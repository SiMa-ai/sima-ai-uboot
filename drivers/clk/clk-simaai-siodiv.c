// SPDX-License-Identifier: GPL-2.0-only
/*
 * Driver for the SiMa.ai SIO's clock divider
 * Copyright (c) 2024 Sima ai
 * Author: Yurii Konovalenko <yurii.konovalenko@sima.ai>
 *	   Nikunj Kela <nikunj.kela@sima.ai>
 */

#include <dm.h>
#include <div64.h>
#include <clk.h>
#include <clk-uclass.h>
#include <log.h>
#include <asm/io.h>
#include <linux/bitfield.h>
#include <linux/kernel.h>
#include <linux/clk-provider.h>

#define SIMAAI_SIODIV_DRV		"simaai-sio-clkdiv"
#define SIMAAI_SIODIV_NUM		(10)
#define SIMAAI_SIODIV_EN		BIT(31)
#define SIMAAI_SIODIV_INT_SHIFT		(0)
#define SIMAAI_SIODIV_INT_WIDTH		(20)
#define SIMAAI_SIODIV_INT_MASK		((1 << SIMAAI_SIODIV_INT_WIDTH) - 1)
#define SIMAAI_SIODIV_FRAC_SHIFT	(20)
#define SIMAAI_SIODIV_FRAC_WIDTH	(8)
#define SIMAAI_SIODIV_FRAC_MASK		((1 << SIMAAI_SIODIV_FRAC_WIDTH) - 1)

struct simaai_siodiv_priv {
	struct clk parent;
	void __iomem *base;
	u32 ignore_unused;
	struct clk clks[SIMAAI_SIODIV_NUM];
};

static void simaai_siodiv_write_div(void __iomem *reg, u64 div)
{
	u32 regval;

	regval = readl(reg);
	regval &= ~(SIMAAI_SIODIV_INT_MASK << SIMAAI_SIODIV_INT_SHIFT);
	regval &= ~(SIMAAI_SIODIV_FRAC_MASK << SIMAAI_SIODIV_FRAC_SHIFT);
	regval |= (div & SIMAAI_SIODIV_FRAC_MASK) << SIMAAI_SIODIV_FRAC_SHIFT;
	div >>= SIMAAI_SIODIV_FRAC_WIDTH;
	regval |= (div & SIMAAI_SIODIV_INT_MASK) << SIMAAI_SIODIV_INT_SHIFT;
	writel(regval, reg);
}

static int simaai_siodiv_is_enabled(struct clk *clk)
{
	struct simaai_siodiv_priv *priv = dev_get_priv(clk->dev);
	void __iomem *reg = (priv->base + (clk->id * 4));

	return !!(readl(reg) & SIMAAI_SIODIV_EN);
}

u64 simaai_siodiv_best_div(u64 rate, u64 prate)
{
	u64 div;

	div = DIV_ROUND_DOWN_ULL((prate << SIMAAI_SIODIV_FRAC_WIDTH), rate);
	div = clamp(div, (u64)(1 << SIMAAI_SIODIV_FRAC_WIDTH),
		(u64)((1 << (SIMAAI_SIODIV_FRAC_WIDTH + SIMAAI_SIODIV_INT_WIDTH)) - 1));

	return div;
}

static int simaai_siodiv_enable(struct clk *clk)
{
	struct simaai_siodiv_priv *priv = dev_get_priv(clk->dev);
	void __iomem *reg = (priv->base + (clk->id * 4));
	u32 regval;

	if (simaai_siodiv_is_enabled(clk))
		return 0;

	regval = readl(reg);
	regval |= SIMAAI_SIODIV_EN;
	writel(regval, reg);

	return 0;
}

static int simaai_siodiv_disable(struct clk *clk)
{
	struct simaai_siodiv_priv *priv = dev_get_priv(clk->dev);
	void __iomem *reg = (priv->base + (clk->id * 4));
	u32 regval;

	if ((1 << clk->id) & priv->ignore_unused)
		return 0;

	if (!simaai_siodiv_is_enabled(clk))
		return 0;

	regval = readl(reg);
	regval &= ~SIMAAI_SIODIV_EN;
	writel(regval, reg);

	return 0;
}

static ulong simaai_siodiv_set_rate(struct clk *clk, unsigned long rate)
{
	struct simaai_siodiv_priv *priv = dev_get_priv(clk->dev);
	void __iomem *reg = (priv->base + (clk->id * 4));
	ulong prate = clk_get_rate(&priv->parent);
	u64 div;

	if (IS_ERR_VALUE(prate)) {
		log_err("%s: Invalid parent clock rate\n", __func__);
		return prate;
	}

	div = simaai_siodiv_best_div((u64)rate, (u64)prate);
	simaai_siodiv_write_div(reg, div);

	return 0;
}

static ulong simaai_siodiv_recalc_rate(struct clk *clk)
{
	struct simaai_siodiv_priv *priv = dev_get_priv(clk->dev);
	void __iomem *reg = (priv->base + (clk->id * 4));
	ulong prate = clk_get_rate(&priv->parent);
	u64 div;
	u32 regval;

	if (IS_ERR_VALUE(prate)) {
		log_err("%s: Invalid parent clock rate\n", __func__);
		return prate;
	}

	regval = readl(reg);
	div = ((regval >> SIMAAI_SIODIV_INT_SHIFT) & SIMAAI_SIODIV_INT_MASK)
			<< SIMAAI_SIODIV_FRAC_WIDTH;
	div |= ((regval >> SIMAAI_SIODIV_FRAC_SHIFT) & SIMAAI_SIODIV_FRAC_MASK);

	return DIV_ROUND_DOWN_ULL(((u64)prate << SIMAAI_SIODIV_FRAC_WIDTH), div);
}

static int simaai_siodiv_request(struct clk *clk)
{
	if (clk->id >= SIMAAI_SIODIV_NUM)
		return -EINVAL;

	/* let's enable the divider */
	simaai_siodiv_enable(clk);

	return 0;
}

static ulong simaai_siodiv_round_rate(struct clk *clk, ulong rate)
{
	struct simaai_siodiv_priv *priv = dev_get_priv(clk->dev);
	ulong prate = clk_get_rate(&priv->parent);
	u64 div;

	if (IS_ERR_VALUE(prate)) {
		log_err("%s: Invalid parent clock rate\n", __func__);
		return prate;
	}

	div = simaai_siodiv_best_div((u64)rate, (u64)prate);

	return DIV_ROUND_DOWN_ULL(((u64)prate << SIMAAI_SIODIV_FRAC_WIDTH), div);
}

static struct clk_ops simaai_siodiv_ops = {
	.request = simaai_siodiv_request,
	.set_rate = simaai_siodiv_set_rate,
	.get_rate = simaai_siodiv_recalc_rate,
	.enable = simaai_siodiv_enable,
	.disable = simaai_siodiv_disable,
	.round_rate = simaai_siodiv_round_rate,
};

static int simaai_siodiv_parse_dt(struct udevice *dev)
{
	struct simaai_siodiv_priv *priv = dev_get_priv(dev);

	priv->base = dev_read_addr_ptr(dev);
	if (!priv->base) {
		log_err("failed to get register address\n");
		return -EINVAL;
	}

	priv->ignore_unused = dev_read_u32_default(dev, "simaai,ignore-unused", 0);

	return 0;
}

static int simaai_siodiv_probe(struct udevice *dev)
{

	struct simaai_siodiv_priv *priv = dev_get_priv(dev);
	int err, i;
	u32 regval;

	err = simaai_siodiv_parse_dt(dev);
	if (err)
		return err;

	err = clk_get_by_index(dev, 0, &priv->parent);
	if (err) {
		log_err("failed to get parent clock\n");
		return err;
	}

	for (i = 0; i < SIMAAI_SIODIV_NUM; i++) {
		void __iomem *reg = (priv->base + (i * 4));
		char name[64];

		memset(name, 0, 64);

		sprintf(name, "%s-%d", dev->name, i);

		simaai_siodiv_write_div(reg, 1 << SIMAAI_SIODIV_FRAC_WIDTH);

		if (priv->ignore_unused & (1 << i)) {
			regval = readl(reg);
			regval |= SIMAAI_SIODIV_EN;
			writel(regval, reg);
		}

		err = clk_register(&priv->clks[i], SIMAAI_SIODIV_DRV, name, priv->parent.dev->name);
		if (err)
			return err;
	}

	return 0;
}

static const struct udevice_id simaai_siodiv_ids[] = {
	{ .compatible = "simaai,clkdiv-sio" },
	{ },
};

U_BOOT_DRIVER(simaai_siodiv) = {
	.name = SIMAAI_SIODIV_DRV,
	.id = UCLASS_CLK,
	.of_match = simaai_siodiv_ids,
	.ops = &simaai_siodiv_ops,
	.probe = simaai_siodiv_probe,
	.priv_auto = sizeof(struct simaai_siodiv_priv),
	.flags = DM_FLAG_PRE_RELOC,
};
