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

#define RUN_DDR_SEQUENCE(d, dc) res = run_sequence(dc->addrs[j].ddrc_base, dc->addrs[j].phy_base, \
		dc->sequences[d], dc->firmwares, PHY_DDR_FIRMWARE_NUM, &dc->settings->chip_settings[j], \
		get_unique_vals(dc, d)); if(res) continue
#define RUN_DDR_SEQUENCE_BREAK(d, dc) res = run_sequence(dc->addrs[j].ddrc_base, dc->addrs[j].phy_base, \
		dc->sequences[d], dc->firmwares, PHY_DDR_FIRMWARE_NUM, &dc->settings->chip_settings[j], \
		get_unique_vals(dc, d)); if(res) break

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
	ddrc_t *ddrc = get_ddrc();

	if(ddrc == NULL)
		return;

	printf("\nDDR INIT: Target DDR controller frequency: %dMHz\n", freq_to_uint(ddrc->settings->freq));
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
		if (MODALIX_ZEBU != get_board_id()) {
			debug("DDR INIT: Postreset completed for controller %d, preparing mailbox\n", j);
			ddrc->sequences[PHY_INIT_DDR_PREPARE_MAILBOX].elements = &seq_prepare_mailbox;
			ddrc->sequences[PHY_INIT_DDR_PREPARE_MAILBOX].size = ARRAY_SIZE(seq_prepare_mailbox);
			RUN_DDR_SEQUENCE(PHY_INIT_DDR_PREPARE_MAILBOX, ddrc);

		}
		debug("DDR INIT: Preparing mailboxes completed for controller %d, running 2D training\n", j);
		RUN_DDR_SEQUENCE(PHY_INIT_DDR_2D_TRAINING, ddrc);
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
	for(j = 0; j < 4; j++)
		printf("DDR %d: %s\n", j, summary[j]?"PASSED":"FAILED");
}
