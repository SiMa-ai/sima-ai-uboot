//SPDX-License-Identifier: (GPL-2.0+ OR MIT)
/*
 * Copyright (c) 2022 Sima ai
 */

#include <asm/arch/init_eth_phy.h>

static init_element_t seq0_init_eth_phy[] = {
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000, .value=0x1140  }, /* SR_MII_CTRL - Default */
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x201c4, .value=0x0020  }, /* VR_MII_MP_12G_16G_MPLLA_CTRL0 - Default */
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x201dc, .value=0xa03e  }, /* VR_MII_MP_16G_MPLLA_CTRL3 */
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x20248, .value=0x0540  }, /* VR_MII_MP_12G_16G_25G_VCO_CAL_LD0 - Default */
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x20258, .value=0x002a  }, /* VR_MII_MP_16G_25G_VCO_CAL_REF0 - Default */
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x20170, .value=0x0010  }, /* VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4 - Default */
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x200d0, .value=0x0003  }, /* VR_MII_MP_12G_16G_25G_TX_RATE_CTRL - Default */
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x20150, .value=0x0003  }, /* VR_MII_MP_12G_16G_25G_RX_RATE_CTRL - Default */
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x200c8, .value=0x0100  }, /* VR_MII_MP_12G_16G_TX_GENCTRL2 - Default */
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x20148, .value=0x0100  }, /* VR_MII_MP_12G_16G_RX_GENCTRL2 - Default */
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x201cc, .value=0x0200  }, /* VR_MII_MP_12G_16G_MPLLA_CTRL2 - Default */
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x200c4, .value=0x1500  }, /* VR_MII_MP_12G_16G_25G_TX_GENCTRL1 */
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x20160, .value=0x4406  }, /* VR_MII_MP_16G_25G_RX_EQ_CTRL0 */
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x20190, .value=0x0111  }, /* VR_MII_MP_16G_RX_CDR_CTRL1 - Default */
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x201a4, .value=0x0006  }, /* VR_MII_MP_16G_25G_RX_MISC_CTRL0 */
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x201a0, .value=0x0100  }, /* VR_MII_MP_16G_25G_RX_GENCTRL4 - Default */
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x20190, .value=0x0111  }, /* VR_MII_MP_16G_RX_CDR_CTRL1 - Default */
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x201ac, .value=0x0000  }, /* VR_MII_MP_16G_25G_RX_IQ_CTRL0 - Default */
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x20174, .value=0x0000  }, /* VR_MII_MP_16G_25G_RX_EQ_CTRL5 - Default */
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x200c4, .value=0x0500  }, /* VR_MII_MP_12G_16G_25G_TX_GENCTRL1*/
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x20000, .value=0xa000  }, /* VR_MII_DIG_CTRL1 */
};

static init_element_t seq1_init_eth_phy[] = {
    { .type=PHY_INIT_TYPE_POLL,  .addr=0x2026c, .value=0x0001  }, /* VR_MII_MP_12G_16G_25G_SRAM */
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x2026c, .value=0x0003  }, /* VR_MII_MP_12G_16G_25G_SRAM */
    { .type=PHY_INIT_TYPE_POLL,  .addr=0x20000, .value=0x2000  }, /* VR_MII_DIG_CTRL1 */
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x200c4, .value=0xf500  }, /* VR_MII_MP_12G_16G_25G_TX_GENCTRL1 */
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x200d8, .value=0x2800  }, /* VR_MII_MP_12G_16G_25G_TX_EQ_CTRL0 - Default */
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x200dc, .value=0x0000  }, /* VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL1 - Default */
};

static init_sequence_t sequences_init_eth_phy[] = {
    [PHY_INIT_ETH_PREVRRESET] = { .elements=&seq0_init_eth_phy[0], .size=ARRAY_SIZE(seq0_init_eth_phy) },
    [PHY_INIT_ETH_POSTVRRESET] = { .elements=&seq1_init_eth_phy[0], .size=ARRAY_SIZE(seq1_init_eth_phy) },
};

int32_t get_sequence_init_eth_phy(init_sequence_t **sequences) {
    if(sequences == NULL)
        return -1;
    *sequences = &sequences_init_eth_phy[0];
    return ARRAY_SIZE(sequences_init_eth_phy);
}

