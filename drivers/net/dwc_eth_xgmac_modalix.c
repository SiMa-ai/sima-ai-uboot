// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) 2025, SiMa.ai
 *
 * Author: Nikunj Kela <nikunj.kela@sima.ai>
 */
#include <linux/iopoll.h>
#include <linux/bitops.h>
#include <linux/bitfield.h>
#include <asm/io.h>
#include <dm/read.h>
#include <net.h>
#include <phy.h>

#include "dwc_eth_xgmac.h"

#define SIMAAI_VR_XS_PMA_MP_32G_LN_LINK_CTRL	0x2025c
#define SIMAAI_SR_XS_PCS_CTRL1			0x80000
#define SIMAAI_SR_XS_PCS_CTRL2			0x8001c
#define LPM					BIT(11)
#define SIMAAI_VR_XS_PMA_MP_32G_RX_CNTX_CTRL0	0x20248
#define RX_CNTX_SEL_0_10GBASER			0x05
#define RX_CNTX_SEL_0_SGMII			0x06
#define RX_CNTX_SEL_0_USXGMII_10G		0x0a
#define SIMAAI_VR_XS_PMA_MP_32G_TX_CNTX_CTRL0	0x200f8
#define TX_CNTX_SEL_0_10GBASER			0x05
#define TX_CNTX_SEL_0_SGMII			0x06
#define TX_CNTX_SEL_0_USXGMII_10G		0x0a
#define SIMAAI_VR_XS_PMA_MP_32G_TX_CM_CNTX_SEL0	0x200f0
#define CMN_CNTX_0_10GBASER			0x05
#define CMN_CNTX_0_SGMII			0x06
#define CMN_CNTX_0_USXGMII_10G			0x0a
#define SIMAAI_VR_XS_PMA_MP_25G_RX_WIDTH_CTRL	0x202c0
#define WIDTH_10BIT				0x1
#define WIDTH_32BIT				0x4
#define SIMAAI_VR_XS_PMA_MP_25G_TX_WIDTH_CTRL	0x20118
#define WAIT_US					1000
#define DW_VR_XS_PCS_DIG_STS			0xa0040
#define DW_PSEQ_ST				GENMASK(4, 2)
#define DW_PSEQ_ST_GOOD				FIELD_PREP(GENMASK(4, 2), 0x4)
#define DW_PSEQ_ST_DOWN				FIELD_PREP(GENMASK(4, 2), 0x6)
#define DW_VR_XS_PCS_DBG_CTRL			0xa0014
#define DW_SUPRESS_LOS_DET			BIT(4)
#define DW_RX_DT_EN_CTL				BIT(6)
#define DW_VR_XS_PCS_KR_CTRL			0xa001c
#define DW_USXG_MODE				GENMASK(12, 10)
#define DW_USXG_MODE_10G			FIELD_PREP(GENMASK(12, 10), 0x0)
#define DW_VR_XS_PCS_DIG_CTRL1			0xa0000
#define DW_USXGMII_EN				BIT(9)
#define DW_VR_MII_AN_CTRL			0x7a0004
#define DW_VR_MII_TX_CONFIG_MASK		BIT(3)
#define DW_VR_MII_TX_CONFIG_PHY_SIDE_SGMII	0x1
#define DW_VR_MII_TX_CONFIG_MAC_SIDE_SGMII	0x0
#define DW_VR_MII_PCS_MODE_MASK			GENMASK(2, 1)
#define DW_VR_MII_AN_CTRL_MII_CTRL_SHIFT	8
#define DW_VR_MII_MII_CTRL_MASK			BIT(8)
#define DW_VR_MII_LINK_STS_MASK			BIT(4)
#define DW_VR_MII_LINK_STS_UP			0x1
#define DW_VR_MII_LINK_STS_DOWN			0x0
#define DW_VR_MII_AN_CTRL_LINK_STS_SHIFT	4
#define DW_VR_MII_INTR_EN_MASK			BIT(0)
#define DW_VR_MII_INTR_EN_ENABLED		0x1
#define DW_VR_MII_INTR_EN_DISABLED		0x0
#define DW_VR_MII_AN_CTRL_TX_CONFIG_SHIFT	3
#define DW_VR_MII_MII_CTRL_8BIT			0x1
#define DW_VR_MII_MMD_CTRL			0x780000
#define SGMII_SPEED_SS13			BIT(13)	/* SGMII speed along with SS6 and SS5 */
#define SGMII_SPEED_SS6				BIT(6)	/* SGMII speed along with SS13 and SS5 */
#define SGMII_SPEED_SS5				BIT(5)	/* SGMII speed along with SS13 and SS6 */
#define AN_CL37_EN				BIT(12)	/* Enable Clause 37 auto-nego */
#define DW_SR_AN_CTRL				0x180000
#define DW_VR_MII_AN_ADV			0x780010
#define DW_VR_MII_AN_ADV_FD			BIT(5)
#define DW_VR_MII_DIG_CTRL1			0x7A0000
#define DW_VR_MII_DIG_CTRL1_MAC_AUTO_SW		BIT(9)
#define DW_VR_MII_AN_CTRL_PCS_MODE_SHIFT	1
#define DW_VR_MII_PCS_MODE_C37_SGMII		0x2
#define DW_EN_2_5G_MODE				BIT(2)
#define DW_VR_PCS_DIG_CTRL1_CL37_BP		BIT(12)
#define DW_VR_MII_AN_CTRL_INTR_EN_SHIFT		0
#define DW_VR_MII_AN_INTR_STS			0x7A0008
#define DW_VR_MII_C37_ANSGM_SP_LNKSTS		BIT(4)
#define DW_VR_MII_CL37_ANCMPLT_INTR		BIT(0)
#define DW_VR_MII_AN_STS_C37_ANSGM_SP_SHIFT	2
#define DW_VR_MII_AN_STS_C37_ANSGM_SP		GENMASK(3, 2)
#define DW_VR_MII_C37_ANSGM_SP_10		0x0
#define DW_VR_MII_C37_ANSGM_SP_100		0x1
#define DW_VR_MII_C37_ANSGM_SP_1000		0x2
#define DW_VR_MII_AN_STS_C37_ANSGM_FD		BIT(1)
#define DW_VR_MII_AN_USXGMII_SP_SHIFT		10
#define DW_VR_MII_AN_USXGMII_SP			GENMASK(12, 10)
#define DW_VR_MII_AN_USXGMII_SP_10		0x0
#define DW_VR_MII_AN_USXGMII_SP_100		0x1
#define DW_VR_MII_AN_USXGMII_SP_1000		0x2
#define DW_VR_MII_AN_USXGMII_SP_10000		0x3
#define DW_VR_MII_AN_USXGMII_SP_2500		0x4
#define DW_VR_MII_AN_USXGMII_SP_5000		0x5
#define DW_VR_MII_AN_USXGMII_FD			BIT(13)
#define DW_VR_MII_AN_USXGMII_LNKSTS		BIT(14)
#define DW_VR_PCS_DIG_CTRL1_USRA_RST		BIT(10)  /* USXGMII Rate Adapter Reset (Port 0) */
#define DW_SR_XS_PCS_STS1			0x80004
#define DW_SR_XS_PCS_STS1_FLT			BIT(7)
#define DW_USXGMII_FULL				BIT(8)

static u32 xpcs_read(fdt_addr_t xpcs, u32 reg)
{
	return readl(xpcs + reg);
}

static void xpcs_write(fdt_addr_t xpcs, u32 reg, u32 val)
{
	writel(val, xpcs + reg);
}

static int xpcs_poll_power_up(fdt_addr_t xpcs)
{
	int val, ret;

	/* Wait xpcs power-up good */
	ret = read_poll_timeout(xpcs_read, val,
			(val & DW_PSEQ_ST) == DW_PSEQ_ST_GOOD,
			10000, 1000000,
			xpcs, DW_VR_XS_PCS_DIG_STS);
	if (ret < 0)
		pr_warn("%s xpcs power-up timeout\n", __func__);

	return ret;
}

static int xpcs_poll_power_down(fdt_addr_t xpcs)
{
	int val, ret;

	ret = read_poll_timeout(xpcs_read, val,
				(val & DW_PSEQ_ST) == DW_PSEQ_ST_DOWN,
				10000, 1000000,
				xpcs, DW_VR_XS_PCS_DIG_STS);

	if (ret < 0)
		pr_warn("%s xpcs power-down timeout\n", __func__);

	return ret;
}

static void xpcs_supress_sig_loss_detect(fdt_addr_t xpcs, bool on)
{
	u32 ret = xpcs_read(xpcs, DW_VR_XS_PCS_DBG_CTRL);

	if (on)
		ret |= (DW_SUPRESS_LOS_DET | DW_RX_DT_EN_CTL);
	else
		ret &= ~(DW_SUPRESS_LOS_DET | DW_RX_DT_EN_CTL);

	xpcs_write(xpcs, DW_VR_XS_PCS_DBG_CTRL, ret);
}

static int select_pcs_type(fdt_addr_t xpcs, phy_interface_t type)
{
	u32 val;

	switch (type) {
	case PHY_INTERFACE_MODE_10GBASER:
	case PHY_INTERFACE_MODE_10GKR:
	case PHY_INTERFACE_MODE_USXGMII:
		val = 0;
		break;
	case PHY_INTERFACE_MODE_SGMII:
		val = 1;
		break;
	case PHY_INTERFACE_MODE_5GBASER:
		val = 15;
		break;
	default:
		pr_warn("%s unsupported interface type(%d)\n", __func__, type);
		return -EINVAL;
	}

	xpcs_write(xpcs, SIMAAI_SR_XS_PCS_CTRL2, val);

	return 0;
}

static uint32_t alloc_index(void)
{
	static int device_indexes = 1;

	return device_indexes++;
}

static int xpcs_config_32g_phy(fdt_addr_t xpcs,
			      phy_interface_t type)
{
	u32 val1, val2, val3, val4, val5;

	switch (type) {
	case PHY_INTERFACE_MODE_10GBASER:
	case PHY_INTERFACE_MODE_10GKR:
		val1 = RX_CNTX_SEL_0_10GBASER;
		val2 = TX_CNTX_SEL_0_10GBASER;
		val3 = CMN_CNTX_0_10GBASER;
		val4 = WIDTH_32BIT;
		val5 = WIDTH_32BIT;
		break;

	case PHY_INTERFACE_MODE_SGMII:
		val1 = RX_CNTX_SEL_0_SGMII;
		val2 = TX_CNTX_SEL_0_SGMII;
		val3 = CMN_CNTX_0_SGMII;
		val4 = WIDTH_10BIT;
		val5 = WIDTH_10BIT;
		break;

	case PHY_INTERFACE_MODE_USXGMII:
		val1 = RX_CNTX_SEL_0_USXGMII_10G;
		val2 = TX_CNTX_SEL_0_USXGMII_10G;
		val3 = CMN_CNTX_0_USXGMII_10G;
		val4 = WIDTH_32BIT;
		val5 = WIDTH_32BIT;
		break;

	default:
		pr_warn("%s unsupported interface type\n", __func__);
		return -EINVAL;
	}

	xpcs_write(xpcs, SIMAAI_VR_XS_PMA_MP_32G_RX_CNTX_CTRL0, val1);
	xpcs_write(xpcs, SIMAAI_VR_XS_PMA_MP_32G_TX_CNTX_CTRL0, val2);
	xpcs_write(xpcs, SIMAAI_VR_XS_PMA_MP_32G_TX_CM_CNTX_SEL0, val3);
	xpcs_write(xpcs, SIMAAI_VR_XS_PMA_MP_25G_RX_WIDTH_CTRL, val4);
	xpcs_write(xpcs, SIMAAI_VR_XS_PMA_MP_25G_TX_WIDTH_CTRL, val5);
	xpcs_write(xpcs, SIMAAI_VR_XS_PMA_MP_32G_LN_LINK_CTRL, alloc_index());

	return 0;
}

static int xpcs_power_cycle(fdt_addr_t xpcs)
{
	int ret;
	uint32_t val;

	val = xpcs_read(xpcs, SIMAAI_SR_XS_PCS_CTRL1);
	val |= LPM;
	xpcs_write(xpcs, SIMAAI_SR_XS_PCS_CTRL1, val);

	udelay(WAIT_US);

	ret = xpcs_poll_power_down(xpcs);
	if (ret < 0)
		goto out;

	udelay(WAIT_US);

	xpcs_write(xpcs, SIMAAI_SR_XS_PCS_CTRL1, 0x440);

	udelay(WAIT_US);

	ret = xpcs_poll_power_up(xpcs);
	if (ret < 0)
		goto out;

	udelay(WAIT_US);

	return 0;

out:
	pr_err("%s failed\n", __func__);
	return ret;
}

static int xpcs_switch_usxgmii(fdt_addr_t xpcs)
{
	int ret;

	ret = select_pcs_type(xpcs, PHY_INTERFACE_MODE_USXGMII);
	if (ret < 0)
		goto out;

	ret = xpcs_read(xpcs, DW_VR_XS_PCS_KR_CTRL);

	/* clear usxgmii mode */
	ret &= ~(DW_USXG_MODE);
	/* set usxgmii mode to 10G */
	ret |= DW_USXG_MODE_10G;

	xpcs_write(xpcs, DW_VR_XS_PCS_KR_CTRL, ret);

	ret = xpcs_read(xpcs, DW_VR_XS_PCS_DIG_CTRL1);

	/* enable usxgmii mode */
	ret |= DW_USXGMII_EN;

	xpcs_write(xpcs, DW_VR_XS_PCS_DIG_CTRL1, ret);

	ret = xpcs_config_32g_phy(xpcs, PHY_INTERFACE_MODE_USXGMII);
	if (ret < 0)
		goto out;

	ret = xpcs_power_cycle(xpcs);
	if (ret < 0)
		goto out;

	xpcs_supress_sig_loss_detect(xpcs, true);

	debug("Interface successfully switched to USXGMII\n");

	return 0;

out:
	pr_err("%s failed\n", __func__);
	return ret;
}

static int xpcs_switch_sgmii(fdt_addr_t xpcs)
{
        int ret;

	ret = select_pcs_type(xpcs, PHY_INTERFACE_MODE_SGMII);
	if (ret < 0)
		goto out;

	ret = xpcs_read(xpcs, DW_VR_XS_PCS_DIG_CTRL1);

	/* clear DW_EN_2_5G_MODE bit */
	ret &= ~DW_EN_2_5G_MODE;

	xpcs_write(xpcs, DW_VR_XS_PCS_DIG_CTRL1, ret);

	ret = xpcs_config_32g_phy(xpcs, PHY_INTERFACE_MODE_SGMII);
	if (ret < 0)
		goto out;

	ret = xpcs_power_cycle(xpcs);
	if (ret < 0)
		goto out;

	xpcs_supress_sig_loss_detect(xpcs, false);

	debug("Interface successfully switched to SGMII\n");

	return 0;

out:
	pr_err("%s failed\n", __func__);
	return ret;
}

static void xpcs_aneg_usxgmii(fdt_addr_t xpcs)
{
	u32 ret, mdio_ctrl;

	mdio_ctrl = xpcs_read(xpcs, DW_VR_MII_MMD_CTRL);

	if (mdio_ctrl & AN_CL37_EN)
		xpcs_write(xpcs, DW_VR_MII_MMD_CTRL, mdio_ctrl & ~AN_CL37_EN);

	ret = xpcs_read(xpcs, DW_VR_XS_PCS_DIG_CTRL1);
	ret |= DW_VR_PCS_DIG_CTRL1_CL37_BP;
	xpcs_write(xpcs, DW_VR_XS_PCS_DIG_CTRL1, ret);

	ret = xpcs_read(xpcs, DW_VR_MII_AN_CTRL);
	ret &= ~(DW_VR_MII_PCS_MODE_MASK | DW_VR_MII_TX_CONFIG_MASK |
	       DW_VR_MII_MII_CTRL_MASK | DW_VR_MII_LINK_STS_MASK | DW_VR_MII_INTR_EN_MASK);
	ret |= (DW_VR_MII_TX_CONFIG_PHY_SIDE_SGMII <<
		DW_VR_MII_AN_CTRL_TX_CONFIG_SHIFT &
		DW_VR_MII_TX_CONFIG_MASK);
	ret |= (DW_VR_MII_MII_CTRL_8BIT <<
		DW_VR_MII_AN_CTRL_MII_CTRL_SHIFT &
		DW_VR_MII_MII_CTRL_MASK);
	ret |= (DW_VR_MII_LINK_STS_UP <<
		DW_VR_MII_AN_CTRL_LINK_STS_SHIFT &
		DW_VR_MII_LINK_STS_MASK);
	ret |= (DW_VR_MII_INTR_EN_ENABLED <<
		DW_VR_MII_AN_CTRL_INTR_EN_SHIFT &
		DW_VR_MII_INTR_EN_MASK);

	xpcs_write(xpcs, DW_VR_MII_AN_CTRL, ret);

	/* Set 10G in SR_MII_CTRL SS13, SS6 bits and SR_MII_AN_ADV FD bit */
	mdio_ctrl |= SGMII_SPEED_SS6;
	mdio_ctrl |= SGMII_SPEED_SS13;

	xpcs_write(xpcs, DW_VR_MII_MMD_CTRL, mdio_ctrl);

	xpcs_write(xpcs, DW_VR_MII_MMD_CTRL, mdio_ctrl | AN_CL37_EN);
}

static void xpcs_aneg_sgmii(fdt_addr_t xpcs)
{
	u32 ret, mdio_ctrl;

	ret = xpcs_read(xpcs, DW_SR_AN_CTRL);
	ret &= ~AN_CL37_EN;
	xpcs_write(xpcs, DW_SR_AN_CTRL, ret);

	ret = xpcs_read(xpcs, DW_VR_XS_PCS_DIG_CTRL1);
	ret |= DW_VR_PCS_DIG_CTRL1_CL37_BP;
	xpcs_write(xpcs, DW_VR_XS_PCS_DIG_CTRL1, ret);

	mdio_ctrl = xpcs_read(xpcs, DW_VR_MII_MMD_CTRL);
	if (mdio_ctrl & AN_CL37_EN)
		xpcs_write(xpcs, DW_VR_MII_MMD_CTRL, mdio_ctrl & ~AN_CL37_EN);

	ret = xpcs_read(xpcs, DW_VR_MII_AN_CTRL);
	ret &= ~(DW_VR_MII_PCS_MODE_MASK | DW_VR_MII_TX_CONFIG_MASK |
	       DW_VR_MII_MII_CTRL_MASK | DW_VR_MII_LINK_STS_MASK | DW_VR_MII_INTR_EN_MASK);

	ret |= (DW_VR_MII_PCS_MODE_C37_SGMII <<
		DW_VR_MII_AN_CTRL_PCS_MODE_SHIFT &
		DW_VR_MII_PCS_MODE_MASK);
	ret |= (DW_VR_MII_TX_CONFIG_PHY_SIDE_SGMII <<
		DW_VR_MII_AN_CTRL_TX_CONFIG_SHIFT &
		DW_VR_MII_TX_CONFIG_MASK);
	ret |= (DW_VR_MII_MII_CTRL_8BIT <<
		DW_VR_MII_AN_CTRL_MII_CTRL_SHIFT &
		DW_VR_MII_MII_CTRL_MASK);
	ret |= (DW_VR_MII_LINK_STS_UP <<
		DW_VR_MII_AN_CTRL_LINK_STS_SHIFT &
		DW_VR_MII_LINK_STS_MASK);
	ret |= (DW_VR_MII_INTR_EN_ENABLED <<
		DW_VR_MII_AN_CTRL_INTR_EN_SHIFT &
		DW_VR_MII_INTR_EN_MASK);

	xpcs_write(xpcs, DW_VR_MII_AN_CTRL, ret);

	ret = xpcs_read(xpcs, DW_VR_MII_DIG_CTRL1);
	ret |= DW_VR_MII_DIG_CTRL1_MAC_AUTO_SW;
	xpcs_write(xpcs, DW_VR_MII_DIG_CTRL1, ret);

	mdio_ctrl |= SGMII_SPEED_SS6;
	mdio_ctrl &= ~SGMII_SPEED_SS13;
	xpcs_write(xpcs, DW_VR_MII_MMD_CTRL, mdio_ctrl);

	ret = xpcs_read(xpcs, DW_VR_MII_AN_ADV);
	ret |= DW_VR_MII_AN_ADV_FD;
	xpcs_write(xpcs, DW_VR_MII_AN_ADV, ret);

	ret = xpcs_read(xpcs, DW_VR_MII_MMD_CTRL);
	xpcs_write(xpcs, DW_VR_MII_MMD_CTRL, mdio_ctrl | AN_CL37_EN);
}

static int configure_xpcs_modalix(fdt_addr_t xpcs, phy_interface_t interface)
{
	int ret;

	switch(interface) {
	case PHY_INTERFACE_MODE_USXGMII:
		ret = xpcs_switch_usxgmii(xpcs);
		if (ret)
			return ret;

		xpcs_aneg_usxgmii(xpcs);
		break;

	case PHY_INTERFACE_MODE_SGMII:
		ret = xpcs_switch_sgmii(xpcs);
		if (ret)
			return ret;

		xpcs_aneg_sgmii(xpcs);
		break;

	default:
		pr_warn("%s: Unsupported interface=%d\n", __func__, interface);
		return -EINVAL;
	}

	return ret;
}

static int xgmac_probe_resources_modalix(struct udevice *dev)
{
	struct xgmac_priv *xgmac = dev_get_priv(dev);
	fdt_addr_t xpcs = dev_read_addr_name(dev, "xpcs");
	int ret = 0;

	if (xpcs == FDT_ADDR_T_NONE) {
		pr_err("%s xpcs base address not found\n", dev->name);
		return -ENODEV;
	}

	xgmac->xpcs_regs = xpcs;

        ret = clk_get_by_name(dev, "stmmaceth", &xgmac->clk_common);
        if (ret)
                pr_warn("clk_get_by_name(stmmaceth) failed: %d", ret);

	return ret;
}

static int xgmac_get_enetaddr_modalix(struct udevice *dev)
{
	struct eth_pdata *pdata = dev_get_plat(dev);
	struct xgmac_priv *xgmac = dev_get_priv(dev);
	u32 hi_addr, lo_addr;

	/* Read the MAC Address from the hardawre */
        hi_addr = readl(&xgmac->mac_regs->address0_high);
        lo_addr = readl(&xgmac->mac_regs->address0_low);

	pdata->enetaddr[0] = lo_addr & 0xff;
        pdata->enetaddr[1] = (lo_addr >> 8) & 0xff;
        pdata->enetaddr[2] = (lo_addr >> 16) & 0xff;
        pdata->enetaddr[3] = (lo_addr >> 24) & 0xff;
        pdata->enetaddr[4] = hi_addr & 0xff;
        pdata->enetaddr[5] = (hi_addr >> 8) & 0xff;

        return !is_valid_ethaddr(pdata->enetaddr);
}

static int xgmac_start_resets_modalix(struct udevice *dev)
{
	struct xgmac_priv *xgmac = dev_get_priv(dev);
	phy_interface_t interface = dev_read_phy_mode(dev);

	/* if phy is already configured, no need to reconfigure xpcs */
	if (xgmac->phy)
		return 0;

	return configure_xpcs_modalix(xgmac->xpcs_regs, interface);
}

static void xgmac_get_state_sgmii(fdt_addr_t xpcs, struct link_state *state)
{
	int ret = xpcs_read(xpcs, DW_VR_MII_AN_INTR_STS);

	if (ret & DW_VR_MII_C37_ANSGM_SP_LNKSTS) {
		int speed;

		state->link = 1;
		debug("Link Up!\n");

		speed = (ret & DW_VR_MII_AN_STS_C37_ANSGM_SP) >> DW_VR_MII_AN_STS_C37_ANSGM_SP_SHIFT;
		if (speed == DW_VR_MII_C37_ANSGM_SP_1000)
			state->speed = SPEED_1000;
		else if (speed == DW_VR_MII_C37_ANSGM_SP_100)
			state->speed = SPEED_100;
		else
			state->speed = SPEED_10;

		if (ret & DW_VR_MII_AN_STS_C37_ANSGM_FD)
			state->duplex = DUPLEX_FULL;
		else
			state->duplex = DUPLEX_HALF;
	}

	ret &= ~(DW_VR_MII_CL37_ANCMPLT_INTR);
	xpcs_write(xpcs, DW_VR_MII_AN_INTR_STS, ret);
}

static void xgmac_link_recovery(fdt_addr_t xpcs)
{
	int ret = xpcs_read(xpcs, DW_SR_XS_PCS_STS1);

	if (ret & DW_SR_XS_PCS_STS1_FLT) {
		ret = xpcs_power_cycle(xpcs);
		if (ret < 0)
			printf("Failed to recover link\n");
		udelay(10000);
	}
}

static void xgmac_fix_xpcs_speed(fdt_addr_t xpcs, struct link_state *state)
{
	int speed, val;

	switch(state->speed) {
	case SPEED_1000:
		speed = SGMII_SPEED_SS6;
		break;
	case SPEED_10000:
		speed = SGMII_SPEED_SS6 | SGMII_SPEED_SS13;
		break;
	default:
		pr_warn("Unsupported speed\n");
		break;
	}

	val = xpcs_read(xpcs, DW_VR_MII_MMD_CTRL);
	val &= ~(SGMII_SPEED_SS6 | SGMII_SPEED_SS5 | SGMII_SPEED_SS13);
	val = speed | DW_USXGMII_FULL;

	xpcs_write(xpcs, DW_VR_MII_MMD_CTRL, val);
}

static void xgmac_get_state_usxgmii(fdt_addr_t xpcs, struct link_state *state)
{
	int ret = xpcs_read(xpcs, DW_VR_MII_AN_INTR_STS);
	int retry = 100;
	u32 val;

	while (retry--) {
		ret = xpcs_read(xpcs, DW_VR_MII_AN_INTR_STS);
		if (ret & DW_VR_MII_AN_USXGMII_LNKSTS) {
			int speed;

			state->link = 1;
			debug("Link Up!\n");

			speed = (ret & DW_VR_MII_AN_USXGMII_SP) >>
				DW_VR_MII_AN_USXGMII_SP_SHIFT;

			switch(speed) {
			case DW_VR_MII_AN_USXGMII_SP_10000:
				state->speed = SPEED_10000;
				break;
			case DW_VR_MII_AN_USXGMII_SP_1000:
				state->speed = SPEED_1000;
				break;
			case DW_VR_MII_AN_USXGMII_SP_100:
				state->speed = SPEED_100;
				break;
			case DW_VR_MII_AN_USXGMII_SP_10:
				state->speed = SPEED_10;
				break;
			case DW_VR_MII_AN_USXGMII_SP_2500:
				state->speed = SPEED_2500;
				break;
			default:
				state->speed = -1;
				break;
			}

			if (ret & DW_VR_MII_AN_USXGMII_FD)
				state->duplex = DUPLEX_FULL;
			else
				state->duplex = DUPLEX_HALF;

			xgmac_fix_xpcs_speed(xpcs, state);
			break;
		}

		xgmac_link_recovery(xpcs);

		udelay(1000);
	}

	udelay(1000);

	retry = 100;
	while (retry--) {
		ret = xpcs_read(xpcs, DW_VR_MII_AN_INTR_STS);
		if (ret & DW_VR_MII_CL37_ANCMPLT_INTR) {
			ret &= ~(DW_VR_MII_CL37_ANCMPLT_INTR);
			xpcs_write(xpcs, DW_VR_MII_AN_INTR_STS, ret);

			break;
		}
		udelay(1000);
	}

	ret = xpcs_read(xpcs, DW_VR_XS_PCS_DIG_CTRL1);
	ret |= DW_VR_PCS_DIG_CTRL1_USRA_RST;
	xpcs_write(xpcs, DW_VR_XS_PCS_DIG_CTRL1, ret);

	/* Wait for DW_VR_PCS_DIG_CTRL1_USRA_RST to get cleared */
	ret =  read_poll_timeout(xpcs_read, val,
				!(val & DW_VR_PCS_DIG_CTRL1_USRA_RST),
				1000, 1000000,
				xpcs, DW_VR_XS_PCS_DIG_CTRL1);
	if (ret < 0)
		pr_warn("Timed out for USRA_RST to clear\n");

	udelay(1000);
}

static int xgmac_get_link_state_modalix(struct udevice *dev, struct link_state *state)
{
	struct xgmac_priv *xgmac = dev_get_priv(dev);
	phy_interface_t interface = dev_read_phy_mode(dev);

	switch(interface) {
	case PHY_INTERFACE_MODE_SGMII:
		xgmac_get_state_sgmii(xgmac->xpcs_regs, state);
		break;

	case PHY_INTERFACE_MODE_USXGMII:
		xgmac_get_state_usxgmii(xgmac->xpcs_regs, state);
		break;

	default:
		return 0;
	}

	return 0;
}

static int xgmac_start_clks_modalix(struct udevice *dev)
{
	struct xgmac_priv *xgmac = dev_get_priv(dev);
	int ret;

	ret = clk_enable(&xgmac->clk_common);
	if (ret < 0) {
		pr_err("Failed to enable clock\n");
		return ret;
	}

	return 0;
}

static int xgmac_stop_clks_modalix(struct udevice *dev)
{
	struct xgmac_priv *xgmac = dev_get_priv(dev);

	clk_disable(&xgmac->clk_common);

	return 0;
}

static struct xgmac_ops xgmac_modalix_ops = {
	.xgmac_probe_resources = xgmac_probe_resources_modalix,
	.xgmac_get_enetaddr = xgmac_get_enetaddr_modalix,
	.xgmac_get_link_state = xgmac_get_link_state_modalix,
	.xgmac_inval_desc = xgmac_inval_desc_generic,
        .xgmac_flush_desc = xgmac_flush_desc_generic,
        .xgmac_inval_buffer = xgmac_inval_buffer_generic,
        .xgmac_flush_buffer = xgmac_flush_buffer_generic,
	.xgmac_stop_resets = xgmac_null_ops,
	.xgmac_start_resets = xgmac_start_resets_modalix,
	.xgmac_stop_clks = xgmac_stop_clks_modalix,
	.xgmac_start_clks = xgmac_start_clks_modalix,
	.xgmac_calibrate_pads = xgmac_null_ops,
        .xgmac_disable_calibration = xgmac_null_ops,
};

struct xgmac_config __maybe_unused xgmac_modalix_config = {
        .reg_access_always_ok = false,
        .swr_wait = 50,
        .config_mac = XGMAC_MAC_RXQ_CTRL0_RXQ0EN_ENABLED_DCB,
        .config_mac_mdio = XGMAC_MAC_MDIO_ADDRESS_CR_250_300,
        .axi_bus_width = XGMAC_AXI_WIDTH_64,
        .interface = dev_read_phy_mode,
        .ops = &xgmac_modalix_ops
};
