/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (c) 2026 SiMa.ai
 *
 * QuickBoot capture/restore for Synopsys DDR PHY (Modalix).
 *
 * COLD BOOT:
 *   - shmem.ddr_tuning_available = 0.
 *   - Normal cold-boot training runs in U-Boot.
 *   - After all controllers pass FINAL, per controller we capture:
 *       (a) Message Block: 512 u16 at 0x58000..0x581FF (DRAM-config MR
 *           values written by host + Trained* fields written by PMU).
 *       (b) SAVE area: 5168 u16 read at the addresses listed in
 *           qb_reg_list[] (per Synopsys REG_LIST_DBYTE4.txt order).
 *   - ACSM SRAM is NOT captured — the verification team's flow doesn't
 *     save/restore it; the post-RUN inline ACSM writes in qb_seq3_2D
 *     handle ACSM initialization at runtime.
 *   - The blob is published to OCM at DDR_TUNING_OCM_ADDR and persisted
 *     to vfat 0:3 as DDR_TRAI.BIN in board_late_init.
 *
 * WARM BOOT:
 *   - tRoot reads DDR_TRAI.BIN, validates checksum, copies blob into OCM
 *     at shmem.ddr_tuning_address, sets shmem.ddr_tuning_available = 1.
 *   - U-Boot validates the OCM blob and sets sima_ddr_quickboot_set(1),
 *     so get_ddrc() picks QB firmware + QB sequences.
 *   - Per controller, BEFORE the QB-load sequence writes DMEM, we
 *     mutate qb_firmware_ddr_modalix_2D_1_values[] in place with this
 *     controller's slice of the captured blob:
 *       qb_firmware_ddr_modalix_2D_1_values[0..511]   = captured MB
 *       qb_firmware_ddr_modalix_2D_1_values[8]  = 0x0001 (SequenceCtrl=1)
 *       qb_firmware_ddr_modalix_2D_1_values[12] = 0x0100 (Quickboot=1)
 *       qb_firmware_ddr_modalix_2D_1_values[0x200..0x162F] = SAVE area
 *   - The normal load_firmware() path then writes the now-patched array
 *     to PHY DMEM 0x58000..0x5FFFF. PMU runs and the PHY drives
 *     DfiInitComplete; seq4 (FINAL) closes the DDRC DFI handshake.
 *
 * Indexes [0x1630..0x7FFF] of the QB DMEM array hold board-agnostic PMU
 * firmware code/data and are left untouched by the patch.
 */

#ifndef __SIMAAI_DDR_TUNING_H__
#define __SIMAAI_DDR_TUNING_H__

#include <linux/types.h>

/* On-disk / on-FAT location for the captured blob. */
#define DDR_TUNING_FAT_IFNAME	"mmc"
#define DDR_TUNING_FAT_DEVPART	"0:3"
#define DDR_TUNING_FAT_FILENAME	"DDR_TRAI.BIN"

/*
 * OCM location U-Boot publishes the freshly captured blob to. Modalix
 * OCM is 0..0x800000; shmem lives at 0x5F0000. 0x700000 leaves plenty of
 * room for the v5 blob (~45 KB for 4 ctrls). tRoot uses the same address
 * on warm boot.
 */
#define DDR_TUNING_OCM_ADDR	0x700000UL

/* 'SDDR' little-endian: bytes S,D,D,R at offset 0,1,2,3 */
#define DDR_TUNING_MAGIC	0x52444453u

/*
 * Blob format version 5: per-controller payload is Message Block (512 u16)
 * + REG_LIST SAVE area (5168 u16). Matches the verification team's setup
 * (they did NOT save/restore ACSM SRAM — the post-RUN inline ACSM writes
 * in qb_seq3_2D handle ACSM init at runtime). v4 added ACSM which proved
 * unnecessary; v5 strips it back out. Bumping the version forces stale
 * blobs to fail validation and trigger a fresh cold-boot capture.
 */
#define DDR_TUNING_VERSION	5

/* Capture sizes (u16 counts). */
#define QB_MB_U16_COUNT		512u                    /* PHY 0x58000..0x581FF */
#define QB_REG_LIST_COUNT	5168u                   /* PHY 0x58200..0x5962F */
#define QB_PER_CTRL_U16		(QB_MB_U16_COUNT + QB_REG_LIST_COUNT)
#define QB_PER_CTRL_BYTES	(QB_PER_CTRL_U16 * sizeof(uint16_t))

/*
 * Indexes within qb_firmware_ddr_modalix_2D_1_values[] (which has
 * firmware_t.addr = 0x58000). These mirror the offsets above.
 */
#define QB_FW_MB_INDEX		0u
#define QB_FW_SAVE_INDEX	0x200u

/*
 * Message Block byte offsets we force after the captured MB copy:
 *   SequenceCtrl @ byte 0x10 (CSR addr 0x58008, u16 index 8) = 0x0001
 *   Quickboot    @ byte 0x19 (CSR addr 0x5800C, u16 index 12 hi-byte) = 0x0100
 */
#define QB_MB_IDX_SEQ_CTRL	8u
#define QB_MB_IDX_QUICKBOOT	12u
#define QB_MB_VAL_SEQ_CTRL	0x0001u
#define QB_MB_VAL_QUICKBOOT	0x0100u

/*
 * Maximum blob size for validation bounds (no longer a BSS buffer size —
 * capture writes directly into OCM at DDR_TUNING_OCM_ADDR). 64 KB is a
 * generous ceiling vs the actual blob size of ~45 KB.
 */
#define DDR_TUNING_BLOB_MAX	65536u

struct ddr_tuning_hdr {
	uint32_t magic;		/* DDR_TUNING_MAGIC */
	uint16_t version;	/* DDR_TUNING_VERSION */
	uint16_t hdr_size;	/* sizeof(struct ddr_tuning_hdr) */
	uint32_t board_id;	/* get_board_id() at capture time */
	uint32_t ddr_type;	/* ddr_type_t at capture time */
	uint32_t ctrl_mask;	/* enabled controllers bitmask */
	uint32_t ctrl_count;	/* popcount(ctrl_mask) */
	uint32_t per_ctrl_u16;	/* QB_PER_CTRL_U16, for sanity check */
	uint32_t blob_size;	/* total size including this header and CRC */
	uint32_t reserved;
} __attribute__((packed));

/* The REG_LIST table itself (defined in qb_reg_list.c). */
extern const uint32_t qb_reg_list[];
extern const size_t   qb_reg_list_count;

/*
 * QB-owned DMEM payload (independent copy from cold-boot — see
 * qb_firmware_ddr_modalix.c). ddr_tuning.c mutates THIS array per
 * controller on warm boot. Cold-boot uses its own static array in
 * firmware_ddr_modalix.c; no cross-talk.
 */
extern uint16_t qb_firmware_ddr_modalix_2D_1_values[];

/* QuickBoot mode state ----------------------------------------------------- */

int  sima_ddr_quickboot_active(void);
void sima_ddr_quickboot_set(int on);

/* Cold-boot path ----------------------------------------------------------- */

/**
 * sima_ddr_capture_tuning() - Publish staged per-controller capture to
 * OCM at DDR_TUNING_OCM_ADDR. The staging buffer is filled by
 * sima_ddr_qb_post_training_capture() (one slot per controller, fired
 * from inside the training sequence at mail=0x07). Falls back to
 * re-reading PHY here if staging didn't happen (cb not registered).
 */
int sima_ddr_capture_tuning(void);

/*
 * sima_ddr_qb_post_training_capture() - Cold-boot capture callback.
 * Registered via phy_init_set_post_training_cb() at sima_ddr_init entry.
 * Called from run_sequence()'s PHY_INIT_TYPE_RUN handler right after
 * mail=0x07. Currently a no-op (DIAG bisection step 3a).
 */
void sima_ddr_qb_post_training_capture(uint32_t phy_base);

/*
 * sima_ddr_qb_capture_reset() - Reset capture state. Call from
 * sima_ddr_init() entry on cold-boot before installing the callback.
 */
void sima_ddr_qb_capture_reset(void);

/**
 * sima_ddr_save_pending_tuning() - Persist the OCM blob to vfat 0:3 as
 * DDR_TRAI.BIN. Reads directly from OCM (header self-describes size).
 */
int sima_ddr_save_pending_tuning(void);

/**
 * sima_ddr_save_tuning_to_fat() - Low-level FAT writer.
 */
int sima_ddr_save_tuning_to_fat(const void *buf, size_t len);

/* Warm-boot path ----------------------------------------------------------- */

/**
 * sima_ddr_qb_validate_blob() - Validate the OCM blob tRoot placed.
 * Returns pointer to validated header on success, NULL otherwise.
 */
const struct ddr_tuning_hdr *
sima_ddr_qb_validate_blob(uint32_t expect_board_id,
			  uint32_t expect_ddr_type,
			  uint32_t expect_ctrl_mask);

/**
 * sima_ddr_qb_patch_firmware_array() - Pre-load patch. Mutates
 * qb_firmware_ddr_modalix_2D_1_values[] with this controller's
 * captured Message Block + SAVE area from the OCM blob, then forces
 * Quickboot=1 and SequenceCtrl=1. The subsequent
 * PHY_INIT_TYPE_FIRMWARE load in the QB sequence writes this patched
 * array to PHY DMEM. Call ONCE per controller, BEFORE
 * RUN_DDR_SEQUENCE(PHY_INIT_DDR_2D_TRAINING).
 */
void sima_ddr_qb_patch_firmware_array(const struct ddr_tuning_hdr *hdr,
				      uint32_t ctrl_idx);

#endif /* __SIMAAI_DDR_TUNING_H__ */
