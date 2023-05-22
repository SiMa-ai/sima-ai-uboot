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
#include <common.h>
#include <linux/delay.h>
#include <asm/arch/prc_addr_map.h>
#include <asm/arch/phy_init.h>
#include <asm/arch/simaai_ddr_utils.h>

#define RUN_DDR_SEQUENCE(d, dc) res = run_sequence(dc->addrs[j].ddrc_base, dc->addrs[j].phy_base, \
		ddrc->sequences[d], ddrc->firmwares, PHY_DDR_FIRMWARE_NUM, &dc->settings->chip_settings[j]); if(res) continue
#define RUN_DDR_SEQUENCE_BREAK(d, dc) res = run_sequence(dc->addrs[j].ddrc_base, dc->addrs[j].phy_base, \
		ddrc->sequences[d], ddrc->firmwares, PHY_DDR_FIRMWARE_NUM, &dc->settings->chip_settings[j]); if(res) break

static init_element_t seq_prepare_mailbox[] = {
    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0031, .value=0x1  },
    { .type=PHY_INIT_TYPE_PHY, .addr=0xc0033, .value=0x1  },
};

#if (DIAGNOSTIC_TEST == 4)
static init_element_t seq5_diag_ddr[] = {
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0001  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0  },
	    { .type=PHY_INIT_TYPE_DEBUG, .addr=0xd0000, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_FIRMWARE, .addr=0x50000, .value=0x4  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x1  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0  },
	    { .type=PHY_INIT_TYPE_FIRMWARE, .addr=0x54200, .value=0x5  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0x54200, .value=0x0004  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0x54201, .value=0x0001  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0x54202, .value=0xfe00  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0x54203, .value=0x00fe  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0x54206, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0x54207, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0001  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0x00032, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0009  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0001  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_RUN, .addr=0x5420b, .value=0x2  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0001  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_DEBUG, .addr=0x5420b, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_DEBUG, .addr=0x5420c, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_DEBUG, .addr=0x5420d, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_DEBUG, .addr=0x5420e, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_DEBUG, .addr=0x5420f, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_DEBUG, .addr=0x54210, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_DEBUG, .addr=0x54211, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_DEBUG, .addr=0x54212, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_DEBUG, .addr=0x54213, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_DEBUG, .addr=0x54214, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_DEBUG, .addr=0x54215, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_DEBUG, .addr=0x54216, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x1  },
};
#elif (DIAGNOSTIC_TEST == 5)
static init_element_t seq5_diag_ddr[] = {
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0001  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0  },
	    { .type=PHY_INIT_TYPE_DEBUG, .addr=0xd0000, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_FIRMWARE, .addr=0x50000, .value=0x4  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x1  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0  },
	    { .type=PHY_INIT_TYPE_FIRMWARE, .addr=0x54200, .value=0x5  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0x54200, .value=0x0005  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0x54201, .value=0x0002  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0x54202, .value=0xfe00  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0x54203, .value=0x01fe  },
		{ .type=PHY_INIT_TYPE_PHY, .addr=0x54204, .value=0x0101  },
		{ .type=PHY_INIT_TYPE_PHY, .addr=0x54205, .value=0x0001  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0x54206, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0x54207, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0x54208, .value=0xaaaa  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0x54209, .value=0xaaaa  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0001  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0x00032, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0009  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0001  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_RUN, .addr=0x0, .value=0x0  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0001  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_DUMPEYE, .addr=0x5420b, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x1  },
};
#elif (DIAGNOSTIC_TEST == 6)
static init_element_t seq5_diag_ddr[] = {
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0001  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0  },
	    { .type=PHY_INIT_TYPE_DEBUG, .addr=0xd0000, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_FIRMWARE, .addr=0x50000, .value=0x4  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x1  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0  },
	    { .type=PHY_INIT_TYPE_FIRMWARE, .addr=0x54200, .value=0x6  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0x54200, .value=0x0005  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0x54201, .value=0x0002  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0x54202, .value=0xfe00  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0x54203, .value=0x01fe  },
		{ .type=PHY_INIT_TYPE_PHY, .addr=0x54204, .value=0x0101  },
		{ .type=PHY_INIT_TYPE_PHY, .addr=0x54205, .value=0x0001  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0x54206, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0x54207, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0x54208, .value=0xaaaa  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0x54209, .value=0xaaaa  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0001  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0x00032, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0009  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0001  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_RUN, .addr=0x0, .value=0x0  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0001  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_DUMPEYE, .addr=0x5420b, .value=0x0000  },
	    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x1  },
};
#endif

static inline void prc_write(uint32_t addr, uint32_t data)
{
	*((volatile uint32_t*)(addr)) = data;
}

static inline uint32_t prc_read(uint32_t addr)
{
	return *((volatile uint32_t*)(addr));
}

static void dms_out_of_reset(int blk, int flag, uint32_t addr)
{
	uint32_t val = prc_read(addr);

	if(flag == 0) { //pre reset
		/* Enable clocks and pull APB interface out of reset */
		val = (val & ~0x3ff) | (0x31f & 0x3ff);
		prc_write(addr, val);

		val = prc_read(addr);
		udelay(10);

		val = (val & ~0x3ff) | (0x13f & 0x3ff);
		prc_write(addr, val);
	} else if(flag == 1) { //post reset
		/* Pull DDRC and Phy outof reset */
		val = (val & ~0x4c0) | (0x4c0 & 0x4c0);
		prc_write(addr, val);
	}
}

void sima_ddr_init(void)
{
	int32_t res = 0, j, k = 0, test_count;
	uint32_t summary[4] = {0};
	uint32_t errors = 0, base;
	ddrc_t *ddrc = get_ddrc();


	if(ddrc == NULL)
		return;

	ddrc->sequences[PHY_INIT_DDR_PREPARE_MAILBOX].elements = &seq_prepare_mailbox;
	ddrc->sequences[PHY_INIT_DDR_PREPARE_MAILBOX].size = ARRAY_SIZE(seq_prepare_mailbox);
#if ((DIAGNOSTIC_TEST == 4) || (DIAGNOSTIC_TEST == 5) || (DIAGNOSTIC_TEST == 6))
	ddrc->sequences[PHY_INIT_DDR_DIAGNOSTIC].elements = &seq5_diag_ddr;
	ddrc->sequences[PHY_INIT_DDR_DIAGNOSTIC].size = ARRAY_SIZE(seq5_diag_ddr);
#endif

	printf("\nDDR INIT: Target DDR controller frequency: %dMHz\n", freq_to_uint(ddrc->settings->freq));
	for(j = 0; j < PHY_DDR_MAX_CONTROLLERS; j++) {
		if(!(ddrc->settings->ddrc_mask & (1 << j)))
			continue;
		res = 0;
		debug("DDR INIT: Bringing controller %d from reset (0)\n", j);
		dms_out_of_reset(j, 0, ddrc->addrs[j].rst_addr);
		debug("DDR INIT: Brought controller %d from reset (0), starting prereset\n", j);
		RUN_DDR_SEQUENCE(PHY_INIT_DDR_PRERESET, ddrc);
		debug("DDR INIT: Prereset completed for controller %d, bringing controller from reset (1)\n", j);
		dms_out_of_reset(j, 1, ddrc->addrs[j].rst_addr);
		debug("DDR INIT: Brought controller %d from reset (1), starting postreset\n", j);
		RUN_DDR_SEQUENCE(PHY_INIT_DDR_POSTRESET, ddrc);
		debug("DDR INIT: Postreset completed for controller %d, preparing mailbox\n", j);
		RUN_DDR_SEQUENCE(PHY_INIT_DDR_PREPARE_MAILBOX, ddrc);
		debug("DDR INIT: Preparing mailboxes completed for controller %d, running 2D training\n", j);
		RUN_DDR_SEQUENCE(PHY_INIT_DDR_2D_TRAINING, ddrc);
#if ((DIAGNOSTIC_TEST == 4) || (DIAGNOSTIC_TEST == 5) || (DIAGNOSTIC_TEST == 6))
			test_count=1;
			while((res == 0) && (test_count > 0)) {
				debug("DDR INIT: Going to run diagnostic of controller %d, runs left: %d\n", j, test_count);
				test_count--;
				RUN_DDR_SEQUENCE_BREAK(PHY_INIT_DDR_DIAGNOSTIC, ddrc);
				k++;
				if(k < 6) {
					seq5_diag_ddr[11].value = 0;
					seq5_diag_ddr[12].value = 0;
				} else if (k < 16) {
					seq5_diag_ddr[11].value = 1 << k;
					seq5_diag_ddr[12].value = 0;
				} else if (k < 32) {
					seq5_diag_ddr[11].value = 0;
					seq5_diag_ddr[12].value = 1 << (k - 16);
				} else
					k = 0;

			}
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
		while (1);
	}

	printf("DDR INITIALIZATION SUMMARY\n");
	for(j = 0; j < 4; j++)
		printf("DDR %d: %s\n", j, summary[j]?"PASSED":"FAILED");
}
