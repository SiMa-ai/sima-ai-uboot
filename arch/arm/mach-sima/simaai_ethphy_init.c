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
#include <linux/kernel.h>
#include <linux/types.h>
#include <stdint.h>
#include <stdlib.h>
#include <linux/delay.h>
#if defined(CONFIG_TARGET_DAVINCI)
#include <asm/arch/davinci/prc_addr_map.h>
#elif defined(CONFIG_TARGET_MODALIX)
#include <asm/arch/modalix/prc_addr_map.h>
#include <asm/arch/modalix/mlsoc_addr_map_defines.h>
#define PRC_BASE PRC_APB_START_ADDR
#endif
#include <asm/arch/phy_init.h>
#include <asm/arch/init_eth_phy.h>

#define RUN_SEQUENCE(d, base, phybase, fw) res = run_sequence(base, phybase, sequences[d], fw, PHY_DDR_FIRMWARE_NUM, NULL, NULL); if(res) continue

#if defined(CONFIG_TARGET_DAVINCI)
static uint32_t eth_phy_base_addr[] = {
		0x011c0000,
		0x013c0000,
		0x015c0000,
		0x017c0000,
};

static uint32_t eth_postvr_seq[] = {
		PHY_INIT_ETH_POSTVRRESET,
		PHY_INIT_ETH_POSTVRRESET,
		PHY_INIT_ETH_POSTVRRESET,
		PHY_INIT_ETH_POSTVRRESET,
};
#define CLK_ENABLE_VAL(blk) 1 | (1 << (blk + 1)) | (1 << 5) | (1 << (blk + 6))
#define RST_ENABLE_VAL(blk) (1 << 10) | (1 << 11) | (1 << (blk + 12))
#elif defined(CONFIG_TARGET_MODALIX)
static uint32_t eth_phy_base_addr[] = {
		0xa040000,
		0xb040000,
		0xc040000,
		0xd040000,
};
static uint32_t eth_postvr_seq[] = {
		PHY_INIT_ETH_SGMII,
		PHY_INIT_ETH_USXGMII,
		PHY_INIT_ETH_10GBASER,
		PHY_INIT_ETH_10GBASER,
};
#define CLK_ENABLE_VAL(blk) (1 << (blk + 2))
#define RST_ENABLE_VAL(blk) (1 << (blk + 6)) | (1 << (blk + 10)) | (1 << (blk + 14))
#endif

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
	val |= CLK_ENABLE_VAL(blk);
	prc_write(addr, val);
	udelay(10);

	/* Bring out of reset */
	val |= RST_ENABLE_VAL(blk);
	prc_write(addr, val);
	udelay(10);
}

void sima_eth_init(void)
{
	init_sequence_t *sequences;
	int32_t res = 0, i, j;
	uint32_t summary[4] = {0};

#if defined(CONFIG_TARGET_DAVINCI)
	res = get_sequence_init_eth_phy(&sequences);
#elif defined(CONFIG_TARGET_MODALIX)
	res = get_sequence_init_eth_phy_modalix(&sequences);
#endif
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
		/* Set unique ID for each XPCS entinty */
		for(j = 0; j < sequences[eth_postvr_seq[i]].size; j++)
			if((sequences[eth_postvr_seq[i]].elements[j].type == PHY_INIT_TYPE_WRITE) &&
				(sequences[eth_postvr_seq[i]].elements[j].addr == 0x2025c)) {
				printf("ETHPHY INIT: Updated XPCS ID (%d) to %d\n", j, i);
				sequences[eth_postvr_seq[i]].elements[j].value = i;
				break;
			}
		RUN_SEQUENCE(eth_postvr_seq[i], eth_phy_base_addr[i], 0, NULL);
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
