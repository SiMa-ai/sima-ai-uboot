/**********************************************************************
 *
 /* SPDX-License-Identifier: GPL-2.0+ */
/*
 * (C) Copyright 2021 SiMa.ai
 *  Filename        : simaai_ddrphy_init.c
 *  Author Name 	: Yurii Konovalenko
 *
 * Description: SiMa.ai DDR PHY Initialization
 *
 *
 *************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <asm/arch/phy_init.h>
#include <asm/arch/simaai_ddr_utils.h>
#include <asm/arch/ddr_tuning.h>
#include <asm/arch/shmem.h>

#define RUN_DDR_SEQUENCE(d, dc) res = run_sequence(dc->addrs[j].ddrc_base, dc->addrs[j].phy_base, \
		dc->sequences[d], dc->firmwares, PHY_DDR_FIRMWARE_NUM, &dc->settings->chip_settings[j], \
		get_unique_vals(dc, d)); if(res) continue
#define RUN_DDR_SEQUENCE_BREAK(d, dc) res = run_sequence(dc->addrs[j].ddrc_base, dc->addrs[j].phy_base, \
		dc->sequences[d], dc->firmwares, PHY_DDR_FIRMWARE_NUM, &dc->settings->chip_settings[j], \
		get_unique_vals(dc, d)); if(res) break
/*
 * Variant that does NOT continue on error — caller is responsible for any
 * post-call diagnostics + `continue`. Used for 2D_TRAINING so the
 * "ctrl N took ..." printf runs even when run_sequence returns -5
 * (get_mail() timeout). On this board the serial buffer flush is gated
 * on that printf appearing, so skipping it makes the QB hang invisible.
 */
#define RUN_DDR_SEQUENCE_NOCONT(d, dc) res = run_sequence(dc->addrs[j].ddrc_base, dc->addrs[j].phy_base, \
		dc->sequences[d], dc->firmwares, PHY_DDR_FIRMWARE_NUM, &dc->settings->chip_settings[j], \
		get_unique_vals(dc, d))

static init_element_t seq_prepare_mailbox[] = {
    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0031, .value=0x1  },
    { .type=PHY_INIT_TYPE_PHY, .addr=0xc0033, .value=0x1  },
};

static inline void prc_write(uint32_t addr, uint32_t data)
{
	*((volatile uint32_t*)((uint64_t)(addr))) = data;
}

static inline uint32_t prc_read(uint32_t addr)
{
	return *((volatile uint32_t*)((uint64_t)((addr))));
}

static void run_dms_reset(ddrc_rst_t *rst) {
	uint32_t val = prc_read(rst->addr);
	if(rst->set_bits || rst->clr_bits) {
		val |= rst->set_bits;
		val &= ~rst->clr_bits;
		prc_write(rst->addr, val);
	}
	if(rst->delay_us)
		udelay(rst->delay_us);
}

void sima_ddr_init(void)
{
	int32_t res = 0, j, i;
#if ((DIAGNOSTIC_TEST == 4) || (DIAGNOSTIC_TEST == 5) || (DIAGNOSTIC_TEST == 6))
	int32_t k = 0, test_count;
#if defined(CONFIG_TARGET_MODALIX)
	int32_t test, rank, byte, lane;
#endif
#endif
	uint32_t summary[4] = {0};
	ddrc_t *ddrc;
	const struct ddr_tuning_hdr *qb_hdr = NULL;
	int qb_active = 0;
	ddrc_settings_t *s;
	uint64_t total_t0, total_t1, total_freq;

	asm volatile("mrs %0, cntvct_el0" : "=r"(total_t0));
	asm volatile("mrs %0, cntfrq_el0" : "=r"(total_freq));

#if defined(CONFIG_TARGET_MODALIX)
	if (shmem_ddr_tuning_available() == 1) {
		s = get_ddrc_settings();
		if (s)
			qb_hdr = sima_ddr_qb_validate_blob(
					(uint32_t)get_board_id(),
					(uint32_t)s->type,
					s->ddrc_mask);
		if (qb_hdr) {
			qb_active = 1;
		} else {
			printf("DDR INIT: QuickBoot blob rejected; clearing flag\n");
			shmem_ddr_tuning_clear();
		}
	}
	sima_ddr_quickboot_set(qb_active);
#endif
	ddrc = get_ddrc();
	if(ddrc == NULL)
		return;

	/*
	 * Register a NO-OP cb on cold boot. This makes the
	 * `if (cb)` check in PHY_INIT_TYPE_RUN handler pass and triggers
	 * an indirect call, but the cb itself does nothing. Isolates "cb
	 * being called per RUN" from "cb actually doing capture work".
	 */
#if defined(CONFIG_TARGET_MODALIX)
	if (!qb_active) {
		sima_ddr_qb_capture_reset();
		phy_init_set_post_training_cb(sima_ddr_qb_post_training_capture);
	}
#endif

	printf("\nDDR INIT: Target DDR controller frequency: %dMHz\n", freq_to_uint(ddrc->settings->type));
	for(j = 0; j < PHY_DDR_MAX_CONTROLLERS; j++) {
		if(!(ddrc->settings->ddrc_mask & (1 << j)))
			continue;
		res = 0;
		debug("DDR INIT: Bringing controller %d from reset (0)\n", j);
		for(i = 0; i < PHY_DDR_PRE_SEQ1_RESETS; i++)
			run_dms_reset(&ddrc->addrs[j].resets[i]);
		debug("DDR INIT: Brought controller %d from reset (0), starting prereset\n", j);
		RUN_DDR_SEQUENCE(PHY_INIT_DDR_PRERESET, ddrc);
		debug("DDR INIT: Prereset completed for controller %d, bringing controller from reset (1)\n", j);
		for(i = PHY_DDR_PRE_SEQ1_RESETS; i < PHY_DDR_MAX_RESETS; i++)
			run_dms_reset(&ddrc->addrs[j].resets[i]);
		debug("DDR INIT: Brought controller %d from reset (1), starting postreset\n", j);
		RUN_DDR_SEQUENCE(PHY_INIT_DDR_POSTRESET, ddrc);
		if (!IS_ZEBU(get_board_id())) {
			debug("DDR INIT: Postreset completed for controller %d, preparing mailbox\n", j);
			ddrc->sequences[PHY_INIT_DDR_PREPARE_MAILBOX].elements = (init_element_t *)&seq_prepare_mailbox;
			ddrc->sequences[PHY_INIT_DDR_PREPARE_MAILBOX].size = ARRAY_SIZE(seq_prepare_mailbox);
			RUN_DDR_SEQUENCE(PHY_INIT_DDR_PREPARE_MAILBOX, ddrc);

		}
		debug("DDR INIT: Preparing mailboxes completed for controller %d, running 2D training\n", j);
		{
			uint64_t cnt0, cnt1, freq;
			asm volatile("mrs %0, cntvct_el0" : "=r"(cnt0));
			asm volatile("mrs %0, cntfrq_el0" : "=r"(freq));
			/*
			 * ColdBoot: RUN_DDR_SEQUENCE(2D_TRAINING) trains for ~5 s.
			 * QuickBoot: RUN_DDR_SEQUENCE(2D_TRAINING) is the QB "load"
			 *       sequence (MemReset, PMU clock, ECC disable,
			 *       IMEM+DMEM load). Then we splat per-board state
			 *       into PMU DMEM and trigger the firmware via the
			 *       QB "run" sequence in the STORE slot.
			 */
			/*
			 * QuickBoot: BEFORE seq3_2D writes DMEM, pre-patch
			 * qb_firmware_ddr_modalix_2D_1_values[] with THIS
			 * controller's captured Message Block + SAVE area
			 * from the OCM blob. seq3_2D's PHY_INIT_TYPE_FIRMWARE
			 * load then writes the per-board values to PHY DMEM
			 * (with side-effects gated off in phy_init.c when
			 * sima_ddr_quickboot_active()). The PHY_INIT_TYPE_RUN
			 * at the end of seq3_2D starts the QB PMU firmware
			 * which short-circuits training and drives DFI ready.
			 */
#if defined(CONFIG_TARGET_MODALIX)
			if (qb_active)
				sima_ddr_qb_patch_firmware_array(qb_hdr, j);
#endif
			RUN_DDR_SEQUENCE_NOCONT(PHY_INIT_DDR_2D_TRAINING, ddrc);
			asm volatile("mrs %0, cntvct_el0" : "=r"(cnt1));
			printf("DDR INIT: 2D training ctrl %d took %llu us (res=%d, qb=%d)\n",
			       j,
			       (unsigned long long)((cnt1 - cnt0) * 1000000ULL / (freq ? freq : 1)),
			       res, qb_active);
			if (res)
				continue;
		}
#if defined(CONFIG_TARGET_DAVINCI)
#if ((DIAGNOSTIC_TEST == 4) || (DIAGNOSTIC_TEST == 5) || (DIAGNOSTIC_TEST == 6))
		test_count=1;
		while((res == 0) && (test_count > 0)) {
			debug("DDR INIT: Going to run diagnostic of controller %d, runs left: %d\n", j, test_count);
			test_count--;
			RUN_DDR_SEQUENCE_BREAK(PHY_INIT_DDR_DIAGNOSTIC, ddrc);
			k++;
			if(k < 6) {
				ddrc->sequences[PHY_INIT_DDR_DIAGNOSTIC].elements[11].value = 0;
				ddrc->sequences[PHY_INIT_DDR_DIAGNOSTIC].elements[12].value = 0;
			} else if (k < 16) {
				ddrc->sequences[PHY_INIT_DDR_DIAGNOSTIC].elements[11].value = 1 << k;
				ddrc->sequences[PHY_INIT_DDR_DIAGNOSTIC].elements[12].value = 0;
			} else if (k < 32) {
				ddrc->sequences[PHY_INIT_DDR_DIAGNOSTIC].elements[11].value = 0;
				ddrc->sequences[PHY_INIT_DDR_DIAGNOSTIC].elements[12].value = 1 << (k - 16);
			} else
				k = 0;

		}
#endif
#endif
#if defined(CONFIG_TARGET_MODALIX)
#if (DIAGNOSTIC_TEST == 4)
		for(rank = 0; rank < 2; rank++) {
			printf("DDR INIT: controller %d, rank: %d, test: %d\n", rank, 4);
			ddrc->sequences[PHY_INIT_DDR_DIAGNOSTIC].elements[8 + 0].value = 4;
			ddrc->sequences[PHY_INIT_DDR_DIAGNOSTIC].elements[8 + 1].value = (rank << 8) | 0x01;
			ddrc->sequences[PHY_INIT_DDR_DIAGNOSTIC].elements[8 + 3].value =  0x20;
			ddrc->sequences[PHY_INIT_DDR_DIAGNOSTIC].elements[8 + 4].value = 0;
			RUN_DDR_SEQUENCE_BREAK(PHY_INIT_DDR_DIAGNOSTIC, ddrc);
		}
#elif ((DIAGNOSTIC_TEST == 5) || (DIAGNOSTIC_TEST == 6))
		for(byte = 0; byte < 4; byte++)
			for(lane = 0; lane < 10; lane++)
				for(rank = 0; rank < 2; rank++)
					for(test = 5; test < 7; test++) {
						printf("DDR INIT: controller %d, byte: %d, lane: %d, rank: %d, test: %d\n",
							j, byte, lane, rank, test);
						ddrc->sequences[PHY_INIT_DDR_DIAGNOSTIC].elements[8 + 0].value = (0x00 << 8) | test;
						ddrc->sequences[PHY_INIT_DDR_DIAGNOSTIC].elements[8 + 1].value = (rank << 8) | 0x01;
						ddrc->sequences[PHY_INIT_DDR_DIAGNOSTIC].elements[8 + 3].value = (byte << 8) | 0x20;
						ddrc->sequences[PHY_INIT_DDR_DIAGNOSTIC].elements[8 + 4].value = (0x01 << 8) | lane;
						RUN_DDR_SEQUENCE_BREAK(PHY_INIT_DDR_DIAGNOSTIC, ddrc);
					}
#endif
#endif
		if(res == 0)
			summary[j] = 1;
		debug("DDR INIT: Training completed for controller %d, running final sequence\n", j);
		RUN_DDR_SEQUENCE(PHY_INIT_DDR_FINAL, ddrc);
		debug("DDR INIT: Initialization of controller %d completed!\n", j);
	}

	if(res == 0) {
		printf("DDR INIT: DDR initialization successful for all controllers\n");
	}
	else {
		printf("DDR INIT: Error. Some initialization sequences failed\n");
#ifndef CONFIG_CMD_DDR
		while (1);
#endif
	}

	printf("DDR INITIALIZATION SUMMARY\n");
	for(j = 0; j < 4; j++) {
		if(!(ddrc->settings->ddrc_mask & (1 << j)))
			continue;

		printf("DDR %d: %s\n", j, summary[j]?"PASSED":"FAILED");
	}

#if defined(CONFIG_TARGET_MODALIX)
	/*
	 * Cold-boot capture only. On Quick boot, tRoot already restored the
	 * blob to OCM from DDR_TRAI.BIN; re-capturing would just rewrite
	 * the same data.
	 */
	/*
	 * Cold-boot only: publish the captured blob header + CRC into
	 * OCM. Per-controller data is already in OCM (cb wrote it in
	 * place during training).
	 */
	if (res == 0 && !qb_active)
		sima_ddr_capture_tuning();

	/* Unregister the cb regardless of capture outcome. */
	phy_init_set_post_training_cb(NULL);

	/*
	 * Consolidated banner — total wall-clock for sima_ddr_init and boot
	 * mode on one line, printed AFTER per-controller training-time lines
	 * so it shows up in the visible part of the serial log even on
	 * boards where the very-early prints are swallowed.
	 */
	asm volatile("mrs %0, cntvct_el0" : "=r"(total_t1));
	{
		uint64_t total_us = (total_t1 - total_t0) * 1000000ULL /
				    (total_freq ? total_freq : 1);
		printf("DDR INIT: Boot mode: %s, total DDR init time: %llu us (%llu.%03llu s)\n",
		       qb_active ? "QuickBoot (warm)" : "Cold (full training)",
		       (unsigned long long)total_us,
		       (unsigned long long)(total_us / 1000000ULL),
		       (unsigned long long)((total_us / 1000ULL) % 1000ULL));
	}
#endif
}
