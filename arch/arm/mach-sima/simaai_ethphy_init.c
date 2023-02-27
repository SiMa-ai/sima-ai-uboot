/**********************************************************************
 *
 /* SPDX-License-Identifier: GPL-2.0+ */
/*
 * (C) Copyright 2023 SiMa.ai
 *  Filename        : simaai_ethphy_init.c
 *  Author Name 	: Yurii Konovalenko
 *
 * Description: SiMa.ai Ethernet PHY Initialization
 *
 *
 *************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <common.h>
#include <linux/delay.h>
#include <asm/arch/prc_addr_map.h>
#include <asm/arch/phy_init.h>
#include <asm/arch/init_eth_phy.h>

#define RUN_SEQUENCE(d, base, phybase, fw) res = run_sequence(base, phybase, sequences[d], fw, PHY_DDR_FIRMWARE_NUM, NULL); if(res) continue

static uint32_t eth_phy_base_addr[] = {
		0x011c0000,
		0x013c0000,
		0x015c0000,
		0x017c0000,
};

static inline void prc_write(uint32_t addr, uint32_t data)
{
	*((volatile uint32_t*)(addr)) = data;
}

static inline uint32_t prc_read(uint32_t addr)
{
	return *((volatile uint32_t*)(addr));
}

static void eth_out_of_reset(int blk)
{
	uint32_t addr = PRC_BASE + PRC_REG__CKG_RST_REG__ETH_CK_RST_ADDR;
	uint32_t val = prc_read(addr);

	/* Enable clocks */
	val |= 1 | (1 << (blk + 1)) | (1 << 5) | (1 << (blk + 6));
	prc_write(addr, val);
	udelay(10);

	/* Bring out of reset */
	val |= (1 << 10) | (1 << 11) | (1 << (blk + 12));
	prc_write(addr, val);
	udelay(10);
}

void sima_eth_init(void)
{
	init_sequence_t *sequences;
	int32_t res = 0, i;
	uint32_t summary[4] = {0};

	res = get_sequence_init_eth_phy(&sequences);
	for(i = 0; i < ARRAY_SIZE(eth_phy_base_addr); i++) {
		res = 0;
		debug("ETHPHY INIT: Bringing controller %d out of reset\n", i);
		eth_out_of_reset(i);
		RUN_SEQUENCE(PHY_INIT_ETH_PREVRRESET, eth_phy_base_addr[i], 0, NULL);
		if(res == 0)
			summary[i] = 1;
		debug("ETHPHY INIT: Pre-VR Reset sequence of controller %d completed\n", i);
	}
	for(i = 0; i < ARRAY_SIZE(eth_phy_base_addr); i++) {
		res = 0;
		RUN_SEQUENCE(PHY_INIT_ETH_POSTVRRESET, eth_phy_base_addr[i], 0, NULL);
		if(res == 0)
			summary[i] |= 1;
		debug("ETHPHY INIT: Post-VR Reset sequence of controller %d completed\n", i);
	}

	if(res == 0)
		printf("ETHPHY INIT: Initialization successful for all controllers\n");
	else
		printf("ETHPHY INIT: Error. Some initialization sequences failed\n");

	printf("ETHPHY INITIALIZATION SUMMARY\n");
	for(i = 0; i < 4; i++)
		printf("ETHPHY %d: %s\n", i, summary[i]?"PASSED":"FAILED");
}
