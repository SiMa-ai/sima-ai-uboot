// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (c) 2026 SiMa.ai
 *
 * QuickBoot capture/restore for Synopsys DDR PHY.
 *
 * Capture (cold boot) reads two regions per controller:
 *   - Message Block 0x58000..0x581FF (512 u16)  — DRAM-config MRs (host-
 *                                                 written) + Trained*
 *                                                 fields (PMU-written).
 *   - SAVE area    0x58200..0x5962F (5168 u16) — PMU-trained CSRs.
 *
 * Restore (Quick boot) is done BEFORE the firmware load — sima_ddr_init
 * calls sima_ddr_qb_patch_firmware_array(hdr, j) per controller, which
 * mutates qb_firmware_ddr_modalix_2D_1_values[] in place with this
 * controller's captured data, forces Quickboot=1 + SequenceCtrl=1, and
 * lets the normal PHY_INIT_TYPE_FIRMWARE load write the result to PHY
 * DMEM. No post-load PHY writes are needed.
 */

#include <cpu_func.h>
#include <errno.h>
#include <fs.h>
#include <linux/kernel.h>
#include <linux/string.h>
#include <linux/types.h>
#include <stdio.h>
#include <u-boot/crc.h>
#include <asm/cache.h>
#include <asm/arch/ddr_tuning.h>
#include <asm/arch/phy_init.h>
#include <asm/arch/shmem.h>
#include <asm/arch/simaai_ddr_utils.h>

/* -------------------------------------------------------------------------
 * QuickBoot mode flag (.data: deterministic 0 pre-relocation; survives
 * clear_bss into board_init_r).
 * ------------------------------------------------------------------------- */
static int ddr_quickboot_mode __attribute__((section(".data"))) = 0;

int sima_ddr_quickboot_active(void)
{
	return ddr_quickboot_mode;
}

void sima_ddr_quickboot_set(int on)
{
	ddr_quickboot_mode = on ? 1 : 0;
}


/*
 * Capture flow uses OCM at DDR_TUNING_OCM_ADDR (0x700000) directly as
 * the staging buffer — no BSS, no .data array. OCM 0x700000..0x70B0A8
 * (45,480 bytes for 4 controllers + header + CRC) is reserved for the
 * captured blob anyway; capturing in place avoids the BSS/data growth
 * that empirically breaks DVT post-relocation.
 *
 * Only the counter needs to be a real C variable — placed in .data to
 * survive pre-relocation BSS garbage (the counter is read by the
 * bounds check in sima_ddr_qb_post_training_capture).
 */
static uint32_t staged_capture_count
	__attribute__((section(".data"))) = 0;

static uint32_t popcount32(uint32_t x)
{
	uint32_t n = 0;
	while (x) { n += x & 1; x >>= 1; }
	return n;
}

/*
 * Open the PHY for APB reads (AN §2.3.2 step 2): MicroContMuxSel=0 +
 * UcclkHclkEnables=3. Without UcclkHclkEnables=3, DMEM reads silently
 * return 0.
 */
static inline void qb_open_apb_reads(uint32_t phy_base)
{
	/*
	 * Halt PMU before reading CSRs Without this step, the PMU may still be
	 * cleaning up after mail=0x07 — CSR reads return transient/
	 * inconsistent values that corrupt the SAVE area.
	 *
	 *   d0099 = 1 : MicroReset = 1 (halt PMU microcontroller)
	 *   d0000 = 0 : MicroContMuxSel = 0 (route APB to PHY CSRs)
	 *   c0080 = 3 : UcclkHclkEnables = 3 (per AN §2.3.2 — enables clocks
	 *               needed for APB reads of PHY internals)
	 */
	do_phy_write(phy_base, 0xd0099, 0x1);
	do_phy_write(phy_base, 0xd0000, 0x0);
	do_phy_write(phy_base, 0xc0080, 0x3);
}

static inline void qb_close_apb_reads(uint32_t phy_base)
{
	do_phy_write(phy_base, 0xc0080, 0x0);
	do_phy_write(phy_base, 0xd0000, 0x1);
}

/* -------------------------------------------------------------------------
 * Cold-boot capture
 * ------------------------------------------------------------------------- */

static void dump_u16_block(const char *label, const uint16_t *p,
			   uint32_t n, uint32_t addr_base, int linear)
{
	uint32_t i;

	printf("    %s (%u u16):\n", label, n);
	for (i = 0; i < n; i++) {
		if ((i & 0xf) == 0)
			printf("      [%04x] ", i);
		printf("%04x ", p[i]);
		if ((i & 0xf) == 0xf)
			printf("\n");
	}
	if (n & 0xf)
		printf("\n");
	(void)addr_base; (void)linear;
}

static void capture_one_controller(uint32_t phy_base, uint16_t *dst)
{
	uint32_t i;
	uint16_t *mb   = dst;                          /* [0..511]    */
	uint16_t *save = dst + QB_MB_U16_COUNT;        /* [512..5679] */

	qb_open_apb_reads(phy_base);

	/* Message Block: linear read of 0x58000..0x581FF */
	for (i = 0; i < QB_MB_U16_COUNT; i++)
		mb[i] = do_phy_read(phy_base, 0x58000 + i);

	/* SAVE area: read at REG_LIST source addresses (NOT linear!) */
	for (i = 0; i < qb_reg_list_count; i++)
		save[i] = do_phy_read(phy_base, qb_reg_list[i]);

	qb_close_apb_reads(phy_base);
}

/*
 * Capture DIRECTLY into the OCM blob region (no intermediate
 * BSS/.data staging). Per-controller slot N lives at
 *   OCM_BASE + sizeof(hdr) + N * QB_PER_CTRL_BYTES
 * sima_ddr_capture_tuning() later fills in the header and CRC at fixed
 * offsets and flushes the cache. No memcpy needed.
 */
void sima_ddr_qb_post_training_capture(uint32_t phy_base)
{
	uint16_t *ocm_slot;

	if (staged_capture_count >= PHY_DDR_MAX_CONTROLLERS) {
		printf("DDR tuning capture: staging overflow (slot=%u) — phy_base=0x%08x dropped\n",
		       staged_capture_count, phy_base);
		return;
	}

	ocm_slot = (uint16_t *)(DDR_TUNING_OCM_ADDR
				+ sizeof(struct ddr_tuning_hdr)
				+ (size_t)staged_capture_count * QB_PER_CTRL_BYTES);
	capture_one_controller(phy_base, ocm_slot);
	staged_capture_count++;
}

void sima_ddr_qb_capture_reset(void)
{
	staged_capture_count = 0;
}

int sima_ddr_capture_tuning(void)
{
	ddrc_t *ddrc = get_ddrc();
	struct ddr_tuning_hdr *hdr;
	uint32_t *crc_p;
	uint32_t  ctrl_mask, ctrl_count;
	size_t    blob_size;

	if (!ddrc) {
		printf("DDR tuning capture: no ddrc context\n");
		return -ENODEV;
	}

	ctrl_mask  = ddrc->settings->ddrc_mask;
	ctrl_count = popcount32(ctrl_mask);
	if (!ctrl_count) {
		printf("DDR tuning capture: no controllers enabled\n");
		return -EINVAL;
	}

	if (staged_capture_count != ctrl_count) {
		printf("DDR tuning capture: staged=%u != ctrl_count=%u (post-training cb missed some controllers)\n",
		       staged_capture_count, ctrl_count);
		return -EIO;
	}

	blob_size = sizeof(*hdr) +
		    (size_t)ctrl_count * QB_PER_CTRL_BYTES +
		    sizeof(uint32_t);

	/*
	 * The per-controller payloads are ALREADY in OCM at the right
	 * offsets — the post-training cb wrote them in place. We only
	 * need to fill the header in front and the CRC at the tail.
	 */
	hdr = (struct ddr_tuning_hdr *)DDR_TUNING_OCM_ADDR;
	hdr->magic        = DDR_TUNING_MAGIC;
	hdr->version      = DDR_TUNING_VERSION;
	hdr->hdr_size     = sizeof(*hdr);
	hdr->board_id     = (uint32_t)get_board_id();
	hdr->ddr_type     = (uint32_t)ddrc->settings->type;
	hdr->ctrl_mask    = ctrl_mask;
	hdr->ctrl_count   = ctrl_count;
	hdr->per_ctrl_u16 = QB_PER_CTRL_U16;
	hdr->blob_size    = blob_size;
	hdr->reserved     = 0;

	crc_p = (uint32_t *)((uint8_t *)DDR_TUNING_OCM_ADDR +
			     blob_size - sizeof(uint32_t));
	*crc_p = crc32(0, (const unsigned char *)DDR_TUNING_OCM_ADDR,
		       blob_size - sizeof(uint32_t));

	flush_cache((unsigned long)DDR_TUNING_OCM_ADDR, blob_size);

	printf("DDR tuning capture: %u ctrl(s) mask 0x%x, %u u16/ctrl, %zu bytes, crc=0x%08x, ocm=0x%lx (captured in place)\n",
	       ctrl_count, ctrl_mask, QB_PER_CTRL_U16, blob_size, *crc_p,
	       (unsigned long)DDR_TUNING_OCM_ADDR);
	return 0;
}

int sima_ddr_save_tuning_to_fat(const void *buf, size_t len)
{
	loff_t actwrite = 0;
	int ret;

	if (!buf || !len)
		return -EINVAL;

	ret = fs_set_blk_dev(DDR_TUNING_FAT_IFNAME, DDR_TUNING_FAT_DEVPART,
			     FS_TYPE_FAT);
	if (ret) {
		printf("DDR tuning save: cannot select %s %s (%d)\n",
		       DDR_TUNING_FAT_IFNAME, DDR_TUNING_FAT_DEVPART, ret);
		return ret;
	}

	ret = fs_write(DDR_TUNING_FAT_FILENAME, (ulong)buf, 0, (loff_t)len,
		       &actwrite);
	if (ret < 0 || actwrite != (loff_t)len) {
		printf("DDR tuning save: write %s failed (ret=%d, wrote=%lld/%zu)\n",
		       DDR_TUNING_FAT_FILENAME, ret, (long long)actwrite, len);
		return ret ? ret : -EIO;
	}

	printf("DDR tuning save: saved %zu bytes to %s %s:%s\n", len,
	       DDR_TUNING_FAT_IFNAME, DDR_TUNING_FAT_DEVPART,
	       DDR_TUNING_FAT_FILENAME);
	return 0;
}

int sima_ddr_save_pending_tuning(void)
{
	const struct ddr_tuning_hdr *hdr;
	const void *ocm = (const void *)DDR_TUNING_OCM_ADDR;

	invalidate_dcache_range((unsigned long)ocm,
				(unsigned long)ocm + sizeof(*hdr));
	hdr = (const struct ddr_tuning_hdr *)ocm;
	if (hdr->magic != DDR_TUNING_MAGIC) {
		debug("DDR tuning save: no blob at OCM 0x%lx (magic 0x%08x)\n",
		      (unsigned long)ocm, hdr->magic);
		return 0;
	}
	if (hdr->blob_size < sizeof(*hdr) + sizeof(uint32_t) ||
	    hdr->blob_size > DDR_TUNING_BLOB_MAX) {
		printf("DDR tuning save: OCM blob_size %u out of range\n",
		       hdr->blob_size);
		return -EINVAL;
	}

	invalidate_dcache_range((unsigned long)ocm,
				(unsigned long)ocm + hdr->blob_size);
	return sima_ddr_save_tuning_to_fat(ocm, hdr->blob_size);
}

/* -------------------------------------------------------------------------
 * Quick Boot validation
 * ------------------------------------------------------------------------- */

const struct ddr_tuning_hdr *
sima_ddr_qb_validate_blob(uint32_t expect_board_id,
			  uint32_t expect_ddr_type,
			  uint32_t expect_ctrl_mask)
{
	uintptr_t ocm = (uintptr_t)shmem_ddr_tuning_addr();
	const struct ddr_tuning_hdr *hdr;
	uint32_t computed_crc, stored_crc;
	size_t   expected_size;

	if (!ocm) {
		printf("DDR tuning restore: shmem ddr_tuning_address is 0\n");
		return NULL;
	}
	if (ocm < 0x1000UL || ocm + DDR_TUNING_BLOB_MAX > 0x800000UL) {
		printf("DDR tuning restore: shmem addr 0x%lx out of OCM range\n",
		       (unsigned long)ocm);
		return NULL;
	}

	invalidate_dcache_range(ocm, ocm + DDR_TUNING_BLOB_MAX);
	hdr = (const struct ddr_tuning_hdr *)ocm;

	if (hdr->magic != DDR_TUNING_MAGIC) {
		printf("DDR tuning restore: bad magic 0x%08x at OCM 0x%lx\n",
		       hdr->magic, (unsigned long)ocm);
		return NULL;
	}
	if (hdr->version != DDR_TUNING_VERSION) {
		printf("DDR tuning restore: version mismatch (blob=%u, expect=%u)\n",
		       hdr->version, DDR_TUNING_VERSION);
		return NULL;
	}
	if (hdr->hdr_size != sizeof(*hdr)) {
		printf("DDR tuning restore: hdr_size mismatch (%u vs %zu)\n",
		       hdr->hdr_size, sizeof(*hdr));
		return NULL;
	}
	if (hdr->per_ctrl_u16 != QB_PER_CTRL_U16) {
		printf("DDR tuning restore: per_ctrl_u16 mismatch (blob=%u, now=%u)\n",
		       hdr->per_ctrl_u16, QB_PER_CTRL_U16);
		return NULL;
	}
	if (hdr->board_id != expect_board_id) {
		printf("DDR tuning restore: board_id mismatch (blob=0x%08x, now=0x%08x)\n",
		       hdr->board_id, expect_board_id);
		return NULL;
	}
	if (hdr->ddr_type != expect_ddr_type) {
		printf("DDR tuning restore: ddr_type mismatch (blob=%u, now=%u)\n",
		       hdr->ddr_type, expect_ddr_type);
		return NULL;
	}
	if (hdr->ctrl_mask != expect_ctrl_mask) {
		printf("DDR tuning restore: ctrl_mask mismatch (blob=0x%x, now=0x%x)\n",
		       hdr->ctrl_mask, expect_ctrl_mask);
		return NULL;
	}
	if (hdr->ctrl_count != popcount32(expect_ctrl_mask)) {
		printf("DDR tuning restore: ctrl_count mismatch (blob=%u, now=%u)\n",
		       hdr->ctrl_count, popcount32(expect_ctrl_mask));
		return NULL;
	}
	expected_size = sizeof(*hdr) +
			(size_t)hdr->ctrl_count * QB_PER_CTRL_BYTES +
			sizeof(uint32_t);
	if (hdr->blob_size != expected_size) {
		printf("DDR tuning restore: blob_size %u != computed %zu\n",
		       hdr->blob_size, expected_size);
		return NULL;
	}

	stored_crc = *(const uint32_t *)((const uint8_t *)ocm +
					 hdr->blob_size - sizeof(uint32_t));
	computed_crc = crc32(0, (const unsigned char *)ocm,
			     hdr->blob_size - sizeof(uint32_t));
	if (computed_crc != stored_crc) {
		printf("DDR tuning restore: CRC mismatch (stored=0x%08x, computed=0x%08x)\n",
		       stored_crc, computed_crc);
		return NULL;
	}

	printf("DDR tuning restore: blob validated at OCM 0x%lx (%u ctrl, %u u16/ctrl, %u bytes, crc=0x%08x)\n",
	       (unsigned long)ocm, hdr->ctrl_count, hdr->per_ctrl_u16,
	       hdr->blob_size, stored_crc);
	return hdr;
}

/* -------------------------------------------------------------------------
 * Pre-load firmware-array patcher
 *
 * Mutates qb_firmware_ddr_modalix_2D_1_values[] in place per controller
 * before its PHY_INIT_TYPE_FIRMWARE load. After this returns, the QB
 * sequence's firmware-load step writes the freshly patched DMEM image
 * (Message Block with Quickboot=1, SequenceCtrl=1, board-specific MRs;
 * board-specific SAVE area; board-agnostic firmware code/data) into the
 * controller's PHY DMEM at 0x58000..0x5FFFF.
 *
 * On the array layout. The firmware_t descriptor for this array has
 * .addr = 0x58000, so load_firmware() writes values[i] to PHY register
 * address 0x58000 + i. Hence array-index [N] == PHY-address (0x58000 + N).
 *
 *   array [0x0000..0x01FF]  ==  PHY  [0x58000..0x581FF]
 *      Message Block. Cold-boot defaults are the host-written DRAM
 *      config. We OVERWRITE these with the captured per-board MB (which
 *      also carries PMU-written Trained* fields), then force Quickboot=1
 *      + SequenceCtrl=1 at array indexes 12 and 8 (PHY 0x5800C, 0x58008).
 *
 *   array [0x0200..0x162F]  ==  PHY  [0x58200..0x5962F]
 *      PMU SAVE area. Cold-boot defaults here are Synopsys firmware-
 *      internal constants for the training algorithm (499 non-zero of
 *      5168). They are NOT trained CSR values. For QB to skip training,
 *      we MUST NEGLECT these cold-boot values and OVERWRITE the whole
 *      range with the captured per-board CSR values from DDR_TRAI.BIN.
 *      The loop below does exactly that — all 5168 indexes written, none
 *      of the cold-boot defaults preserved.
 *
 *   array [0x1630..end]     ==  PHY  [0x59630..end of DMEM]
 *      Synopsys-supplied generic PMU firmware code/data used by both
 *      cold-boot training and QuickBoot short-circuit paths. KEEP
 *      UNTOUCHED (do NOT neglect).
 *
 * The mutation persists for the rest of this boot session, but the cold
 * boot path does not run on the same boot as the warm path, and the
 * array is reinitialized from the U-Boot .data section on every reboot.
 * ------------------------------------------------------------------------- */

static const uint16_t *per_ctrl_slice(const struct ddr_tuning_hdr *hdr,
				      uint32_t ctrl_idx)
{
	const uint8_t *p;
	uint32_t slot;

	slot = popcount32(hdr->ctrl_mask & ((1u << ctrl_idx) - 1u));
	p = (const uint8_t *)hdr + hdr->hdr_size +
	    (size_t)slot * QB_PER_CTRL_BYTES;
	return (const uint16_t *)p;
}

void sima_ddr_qb_patch_firmware_array(const struct ddr_tuning_hdr *hdr,
				      uint32_t ctrl_idx)
{
	const uint16_t *slice;
	const uint16_t *mb_src;
	const uint16_t *save_src;
	uint32_t i;

	if (!hdr || ctrl_idx >= 32 || !(hdr->ctrl_mask & (1u << ctrl_idx)))
		return;

	slice    = per_ctrl_slice(hdr, ctrl_idx);
	mb_src   = slice;
	save_src = slice + QB_MB_U16_COUNT;

	/* Message Block: indexes 0..511 of QB DMEM array. */
	for (i = 0; i < QB_MB_U16_COUNT; i++)
		qb_firmware_ddr_modalix_2D_1_values[QB_FW_MB_INDEX + i] =
			mb_src[i];

	/*
	 * Force the two QB-specific MB fields per AN Table 3-1. The
	 * captured MB has Quickboot=0 (cold-boot run) and SequenceCtrl
	 * set to "run all training steps", which would make the QB
	 * firmware retrain rather than short-circuit.
	 */
	qb_firmware_ddr_modalix_2D_1_values[QB_MB_IDX_SEQ_CTRL] =
		QB_MB_VAL_SEQ_CTRL;
	qb_firmware_ddr_modalix_2D_1_values[QB_MB_IDX_QUICKBOOT] =
		QB_MB_VAL_QUICKBOOT;

	/* SAVE area: indexes 0x200..0x162F of QB DMEM array. */
	for (i = 0; i < qb_reg_list_count; i++)
		qb_firmware_ddr_modalix_2D_1_values[QB_FW_SAVE_INDEX + i] =
			save_src[i];
}
