//SPDX-License-Identifier: (GPL-2.0+ OR MIT)
/*
 * Copyright (c) 2025 Sima ai
 */

#include <asm/arch/init_eth_phy.h>
#include <linux/kernel.h>

static init_element_t seq0_init_eth_phy_modalix_zebu[] = {
};


static init_element_t seq1_init_eth_phy_modalix_zebu[] = {
	// Common part
	{ .type=PHY_INIT_TYPE_POLL,   .addr=0x2026c,  .value=0x00000001   }, /* 5.1#4 Poll bit [0] (INIT_DN) of VR_XS_PMA_MP_12G_16G_25G_SRAM register till it becomes 1. */
	{ .type=PHY_INIT_TYPE_WRITE,  .addr=0x2026c,  .value=0x00000007   }, /* 5.1#6 (For silicon should be 3)SPDXfter SRAM loading is complete, program bit [1] (EXT_LD_DN) of VR_XS_PMA_MP_25G_16G_SRAM to 1 */
	{ .type=PHY_INIT_TYPE_WRITE,  .addr=0xa0000,  .value=0x00000002   }, /* VR_AN_DIG_CTRL1 (Zebu only hack)*/
	{ .type=PHY_INIT_TYPE_WRITE,  .addr=0x80000,  .value=0x00000440   }, /* 5.1#7 Read the SR_XS_PCS_CTRL1 register and wait till the 15th bit of this register is read as 0 */
	{ .type=PHY_INIT_TYPE_WRITE,  .addr=0x180000, .value=0x00002000   }, /* 5.1#8 ProgramN_ENABLE bit of SR_AN_CTRL register to 0 (to turn-off Clause 73 auto-negotiation) */
	{ .type=PHY_INIT_TYPE_WRITE,  .addr=0xa0014,  .value=0x00000050   }, /* 5.1#9 Program bit [4] (SUPRESS_LOS_DET) and bit [6] (RX_DT_EN_CTL) of VR_XS_PCS_DEBUG_CTRL register to 1. */

};

static init_sequence_t sequences_init_eth_phy_modalix_zebu[] = {
	[PHY_INIT_ETH_PREVRRESET] = { .elements=&seq0_init_eth_phy_modalix_zebu[0], .size=ARRAY_SIZE(seq0_init_eth_phy_modalix_zebu),  },
	[PHY_INIT_ETH_SGMII] = { .elements=&seq1_init_eth_phy_modalix_zebu[0], .size=ARRAY_SIZE(seq1_init_eth_phy_modalix_zebu),  },
	[PHY_INIT_ETH_USXGMII] = { .elements=&seq1_init_eth_phy_modalix_zebu[0], .size=ARRAY_SIZE(seq1_init_eth_phy_modalix_zebu),  },
	[PHY_INIT_ETH_10GBASER] = { .elements=&seq1_init_eth_phy_modalix_zebu[0], .size=ARRAY_SIZE(seq1_init_eth_phy_modalix_zebu),  },

};

int32_t get_sequence_init_eth_phy_modalix_zebu(init_sequence_t **sequences) {
	if(sequences == NULL)
		return -1;
	*sequences = &sequences_init_eth_phy_modalix_zebu[0];
	return ARRAY_SIZE(sequences_init_eth_phy_modalix_zebu);
}
