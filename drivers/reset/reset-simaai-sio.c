// SPDX-License-Identifier: GPL-2.0-only
/*
 * SiMa.ai SIO Reset Controller Driver
 * Copyright (c) 2024 Sima ai
 * Author: Nikunj Kela <nikunj.kela@sima.ai>
 */


#include <dm.h>
#include <reset.h>
#include <reset-uclass.h>
#include <linux/bitops.h>
#include <linux/err.h>
#include <linux/delay.h>
#include <asm/io.h>

#define SIMAAI_SIO_RESET_TIME_US	10
#define SIMAAI_SIO_RESET_RSTCLR		0x0
#define SIMAAI_SIO_RESET_RSTSET		0x4
#define SIMAAI_SIO_RESET_NUM		10

struct simaai_sio_reset_priv {
	void __iomem *base;
};

static int simaai_sio_reset_request(struct reset_ctl *rst)
{
	if (rst->id < SIMAAI_SIO_RESET_NUM)
		return 0;
	else
		return -EINVAL;
}

static int simaai_sio_reset_assert(struct reset_ctl *rst)
{
	struct simaai_sio_reset_priv *priv = dev_get_priv(rst->dev);

	writel(BIT(rst->id), priv->base + SIMAAI_SIO_RESET_RSTSET);

	/* wait for assert to settle */
	udelay(SIMAAI_SIO_RESET_TIME_US);

	return 0;
}

static int simaai_sio_reset_deassert(struct reset_ctl *rst)
{
	struct simaai_sio_reset_priv *priv = dev_get_priv(rst->dev);

	writel(BIT(rst->id), priv->base + SIMAAI_SIO_RESET_RSTCLR);

	return 0;
}

static const struct reset_ops simaai_sio_reset_ops = {
	.request = simaai_sio_reset_request,
	.rst_assert = simaai_sio_reset_assert,
	.rst_deassert = simaai_sio_reset_deassert,
};

int simaai_sio_reset_probe(struct udevice *dev)
{
	struct simaai_sio_reset_priv *priv = dev_get_priv(dev);

	priv->base = dev_read_addr_ptr(dev);
	if (IS_ERR(priv->base))
		return -ENODEV;

	return 0;
}

static const struct udevice_id simaai_sio_reset_ids[] = {
	{ .compatible = "simaai,reset-sio" },
	{ },
};

U_BOOT_DRIVER(simaai_sio_reset) = {
	.name = "simaai_sio_reset",
	.id = UCLASS_RESET,
	.of_match = simaai_sio_reset_ids,
	.probe = simaai_sio_reset_probe,
	.priv_auto	= sizeof(struct simaai_sio_reset_priv),
	.ops = &simaai_sio_reset_ops,
};
