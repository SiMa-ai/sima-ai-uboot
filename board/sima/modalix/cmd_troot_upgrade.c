// SPDX-License-Identifier: GPL-2.0+
/*
 * troot_upgrade - reflash tRoot's boot SPI-NOR via the HPI mailbox to tRoot.
 * Copyright (c) 2026 SiMa.ai
 */

#include <command.h>
#include <cpu_func.h>
#include <vsprintf.h>
#include <asm/io.h>
#include <dm/ofnode.h>
#include <linux/delay.h>
#include <linux/string.h>

/* HPI mailbox registers, host (A65) view -- DT hpi-controller@0x0f0f1000 */
#define HPI_BASE		0x0f0f1000UL
#define HPI_CPU_IRQ_STAT	0x14
#define HPI_HOST_MB_P0		0x30	/* host -> tRoot, param0 */
#define HPI_HOST_MB_P1		0x34	/* host -> tRoot, param1 */
#define HPI_HOST_MB_CTRL	0x38	/* write 0x2 = doorbell  */
#define HPI_HOST_MB_OWN		0x3c	/* tRoot clears on pickup */
#define HPI_CPU_MB_P0		0x40	/* tRoot -> host mailbox */
#define HPI_CPU_MB_P1		0x44
#define HPI_CPU_MB_OWN		0x4c

#define SIMA_HPI_MSG_UPGRADE_SPI	0x1000000E

/* tRoot's fixed shmem window (0x57500000, host view): base from the DT
 * hpi_client node "simaai,fixed-shmem"; size u32 at +0, blob at +0x200. */
#define SHMEM_BASE_DEFAULT	0x1207500000UL	/* hpi_api.h MODALIX fallback */
#define SPI_HS_OFF		0x04
#define SPI_BLOB_OFF		0x200
#define SPI_READBACK_OFF	(SPI_BLOB_OFF + 0x1000000) /* dvboot write_spi.h */
#define TROOT_MAX_SIZE		0x400000	/* 4 MiB (hpi_api.h MODALIX) */

#define SPI_HS_RUNNING		0x11223344
#define SPI_HS_DONE		0x66778899

#define ACCEPT_TIMEOUT_MS	10000		/* tRoot picking up the mailbox */
#define DONE_TIMEOUT_MS		300000		/* full SPI erase+write+verify  */

static u64 shm;		/* shmem window base, resolved per run */

static inline u32 hpi_rd(u32 off)	{ return readl((void __iomem *)(HPI_BASE + off)); }
static inline void hpi_wr(u32 off, u32 v) { writel(v, (void __iomem *)(HPI_BASE + off)); }
static inline void __iomem *shm_io(ulong off) { return (void __iomem *)(uintptr_t)(shm + off); }

static u64 get_shmem_base(void)
{
	ofnode node = ofnode_by_compatible(ofnode_null(),
					   "simaai,modalix-hpi-client");
	u64 base;

	if (ofnode_valid(node) &&
	    !ofnode_read_u64_index(node, "simaai,fixed-shmem", 0, &base))
		return base;

	printf("troot_upgrade: no simaai,fixed-shmem in DT, using 0x%lx\n",
	       SHMEM_BASE_DEFAULT);
	return SHMEM_BASE_DEFAULT;
}

static void hpi_dump(const char *when)
{
	printf("  HPI[%s] IRQ_STAT=%08x  HOST_MB p0=%08x p1=%08x own=%08x  CPU_MB p0=%08x p1=%08x own=%08x\n",
	       when, hpi_rd(HPI_CPU_IRQ_STAT),
	       hpi_rd(HPI_HOST_MB_P0), hpi_rd(HPI_HOST_MB_P1), hpi_rd(HPI_HOST_MB_OWN),
	       hpi_rd(HPI_CPU_MB_P0), hpi_rd(HPI_CPU_MB_P1), hpi_rd(HPI_CPU_MB_OWN));
}

/* Bytes verified so far: tRoot streams its flash read-back into the ring
 * (cleared at staging), so the ring prefix matching the blob = verify progress. */
static ulong verify_progress(ulong size)
{
	const u8 *blob = (const u8 *)(uintptr_t)(shm + SPI_BLOB_OFF);
	const u8 *rb = (const u8 *)(uintptr_t)(shm + SPI_READBACK_OFF);
	ulong n = 0, chunk;

	invalidate_dcache_range(shm + SPI_READBACK_OFF,
				(shm + SPI_READBACK_OFF + size + 0x3f) & ~0x3fULL);
	while (n < size) {
		chunk = (size - n > 0x1000) ? 0x1000 : size - n;
		if (memcmp(blob + n, rb + n, chunk))
			break;
		n += chunk;
	}
	return n;
}

static int do_troot_upgrade(struct cmd_tbl *cmdtp, int flag, int argc,
			    char *const argv[])
{
	ulong src, size, prog;
	int i, dry = 0, verbose = 0, accepted = 0, last_print = 0;

	/* optional leading flags: -n dry-run (stage only), -v verbose regs */
	while (argc > 1 && argv[1][0] == '-') {
		const char *p = &argv[1][1];

		for (; *p; p++) {
			if (*p == 'n')
				dry = 1;
			else if (*p == 'v')
				verbose = 1;
			else
				return CMD_RET_USAGE;
		}
		argc--;
		argv++;
	}

	if (argc != 3)
		return CMD_RET_USAGE;

	src  = hextoul(argv[1], NULL);
	size = hextoul(argv[2], NULL);
	if (!size || size > TROOT_MAX_SIZE) {
		printf("troot_upgrade: bad size 0x%lx (max 0x%x)\n",
		       size, TROOT_MAX_SIZE);
		return CMD_RET_FAILURE;
	}

	shm = get_shmem_base();

	/* Stage blob + size for tRoot and flush to DRAM (the ARC core is not
	 * cache-coherent with the A65). */
	memmove((void *)(uintptr_t)(shm + SPI_BLOB_OFF), (void *)src, size);
	writel(size, shm_io(0));
	/* progress marker; also clears a stale DONE word from a previous run */
	writel(SPI_HS_RUNNING, shm_io(SPI_HS_OFF));
	/* clear the read-back ring so verify progress/compare see fresh data */
	memset((void *)(uintptr_t)(shm + SPI_READBACK_OFF), 0, size);
	flush_dcache_range(shm, shm + 0x40);
	flush_dcache_range(shm + SPI_BLOB_OFF, shm + SPI_BLOB_OFF + size);
	flush_dcache_range(shm + SPI_READBACK_OFF,
			   (shm + SPI_READBACK_OFF + size + 0x3f) & ~0x3fULL);

	if (verbose) {
		printf("troot_upgrade: staged 0x%lx bytes at 0x%llx (size at 0x%llx)\n",
		       size, shm + SPI_BLOB_OFF, shm);
		hpi_dump("pre ");
	}

	if (dry) {
		printf("troot_upgrade: dry-run - would send HOST_MB_P0=0x%08x, doorbell CTRL=0x2. Not sent.\n",
		       SIMA_HPI_MSG_UPGRADE_SPI);
		return CMD_RET_SUCCESS;
	}

	/* Send the request and ring the doorbell (sequence from swsoc-hpidrv
	 * hpi_drv.c). */
	hpi_wr(HPI_HOST_MB_P0, SIMA_HPI_MSG_UPGRADE_SPI);
	hpi_wr(HPI_HOST_MB_P1, 0);
	hpi_wr(HPI_HOST_MB_CTRL, 0x2);

	if (verbose) {
		hpi_dump("sent");
		printf("troot_upgrade: asking tRoot to reflash SPI...\n");
	}

	/* tRoot never sends an HPI reply (its writer parks in while(1));
	 * acceptance = HOST_MB_OWN clearing when tRoot picks up the mailbox. */
	for (i = 0; i < ACCEPT_TIMEOUT_MS; i++) {
		if (!(hpi_rd(HPI_HOST_MB_OWN) & 0x1)) {
			accepted = 1;
			break;
		}
		mdelay(1);
	}

	if (verbose)
		hpi_dump("post");

	if (!accepted) {
		printf("troot_upgrade: tRoot did NOT accept the request (HOST_MB_OWN still set).\n"
		       "  Is tRoot alive/idle? SPI unchanged -- safe to retry.\n");
		return CMD_RET_FAILURE;
	}

	printf("troot_upgrade: erase/program/verify in progress...\n");

	/* Wait for tRoot's DONE word in the DDR handshake word. */
	for (i = 0; i < DONE_TIMEOUT_MS; i++) {
		invalidate_dcache_range(shm, shm + 0x40);
		if (readl(shm_io(SPI_HS_OFF)) == SPI_HS_DONE)
			break;
		mdelay(1);
		/* sample every 1s: verify is short and prints as soon as it
		 * starts; erase/program keeps the quieter 10s cadence */
		if ((i % 1000) || !i)
			continue;
		prog = verify_progress(size);
		if (prog >= 0x1000) {
			printf("... verifying %lu%%\n", prog * 100 / size);
			last_print = i;
		} else if (i - last_print >= 10000) {
			if (verbose)
				printf("... erasing/programming (hs=0x%08x)\n",
				       readl(shm_io(SPI_HS_OFF)));
			else
				printf("... erasing/programming\n");
			last_print = i;
		}
	}

	if (readl(shm_io(SPI_HS_OFF)) != SPI_HS_DONE) {
		printf("troot_upgrade: TIMEOUT waiting for done word (hs=0x%08x).\n"
		       "  tRoot may still be flashing -- do NOT power-cycle; re-check with:\n"
		       "    md.l 0x%llx 1   (expect 0x%08x)\n",
		       readl(shm_io(SPI_HS_OFF)), shm + SPI_HS_OFF, SPI_HS_DONE);
		return CMD_RET_FAILURE;
	}

	/* Data match: compare tRoot's flash read-back against the input blob. */
	invalidate_dcache_range(shm + SPI_READBACK_OFF,
				(shm + SPI_READBACK_OFF + size + 0x3f) & ~0x3fULL);
	if (memcmp((void *)(uintptr_t)(shm + SPI_BLOB_OFF),
		   (void *)(uintptr_t)(shm + SPI_READBACK_OFF), size)) {
		printf("troot_upgrade: DATA MATCH FAILED - flash read-back differs from blob.\n"
		       "  Do NOT power-cycle. Retry the upgrade (safe), or recover externally.\n");
		return CMD_RET_FAILURE;
	}

	printf("troot_upgrade: SUCCESS - SPI reflashed and read-back verified (0x%lx bytes).\n"
	       "  Power-cycle to boot the new tRoot/U-Boot.\n", size);
	return CMD_RET_SUCCESS;
}

U_BOOT_CMD(troot_upgrade, 5, 0, do_troot_upgrade,
	"reflash tRoot boot SPI-NOR via the HPI mailbox to tRoot",
	"[-n] [-v] <blob_addr> <size>\n"
	"    - hand troot_blob.be (already at <blob_addr>, length <size> hex) to\n"
	"      tRoot over HPI; tRoot erases+writes its boot SPI-NOR and verifies.\n"
	"      -n  dry-run: stage the blob and print the request, do not send it\n"
	"      -v  verbose: dump the HPI mailbox registers around the exchange\n"
	"      e.g.  fatload usb 0:1 ${loadaddr} troot_blob.be\n"
	"            troot_upgrade ${loadaddr} ${filesize}");
