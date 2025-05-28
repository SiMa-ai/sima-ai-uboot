//SPDX-License-Identifier: (GPL-2.0+ OR MIT)
/*
 * Copyright (c) 2022 Sima ai
 */


#include <dm.h>
#include <dt-structs.h>
#include <linux/libfdt.h>
#include <mapmem.h>
#include <sdhci.h>

#define EMMC_MIN_FREQ	400000

struct simaai_sdhc_plat {
	struct mmc_config cfg;
	struct mmc mmc;
};

struct simaai_sdhc {
	struct sdhci_host host;
};

static int simaai_sdhci_probe(struct udevice *dev)
{
	struct mmc_uclass_priv *upriv = dev_get_uclass_priv(dev);
	struct simaai_sdhc_plat *plat = dev_get_plat(dev);
	struct simaai_sdhc *prv = dev_get_priv(dev);
	struct sdhci_host *host = &prv->host;
	int max_frequency, ret;

#if CONFIG_IS_ENABLED(OF_PLATDATA)
	struct dtd_simaai_sdhci_4_20 *dtplat = &plat->dtplat;

	host->name = dev->name;
	host->ioaddr = map_sysmem(dtplat->reg[0], dtplat->reg[1]);
	host->bus_width = dtplat->bus_width;
	host->max_clk = dtplat->max_frequency;
	host->quirks = dtplat->no_1_8_v ? SDHCI_QUIRK_NO_1_8_V : 0;
#endif

	host->quirks |= SDHCI_QUIRK_WAIT_SEND_CMD;

	if (host->bus_width == 8)
		host->host_caps |= MMC_MODE_8BIT;

	host->mmc = &plat->mmc;
	host->mmc->priv = &prv->host;
	host->mmc->dev = dev;
	upriv->mmc = host->mmc;

	ret = sdhci_setup_cfg(&plat->cfg, host, 0, EMMC_MIN_FREQ);
	if (ret)
		return ret;

	return sdhci_probe(dev);
}

static int simaai_sdhci_of_to_plat(struct udevice *dev)
{
#if !CONFIG_IS_ENABLED(OF_PLATDATA)
	struct sdhci_host *host = dev_get_priv(dev);

	host->name = dev->name;
	host->ioaddr = dev_read_addr_ptr(dev);
	host->bus_width = dev_read_u32_default(dev, "bus-width", 4);
	host->max_clk = dev_read_u32_default(dev, "max-frequency", EMMC_MIN_FREQ);
	host->quirks |= dev_read_bool(dev, "no-1-8-v") ? SDHCI_QUIRK_NO_1_8_V : 0;
#endif

	return 0;
}

static int simaai_sdhci_bind(struct udevice *dev)
{
	struct simaai_sdhc_plat *plat = dev_get_plat(dev);

	return sdhci_bind(dev, &plat->mmc, &plat->cfg);
}

static const struct udevice_id simaai_sdhci_ids[] = {
	{ .compatible = "simaai,sdhci-4.20a" },
	{ }
};

U_BOOT_DRIVER(simaai_sdhci_drv) = {
	.name		= "simaai_sdhci_4_20",
	.id		= UCLASS_MMC,
	.of_match	= simaai_sdhci_ids,
	.of_to_plat = simaai_sdhci_of_to_plat,
	.ops		= &sdhci_ops,
	.bind		= simaai_sdhci_bind,
	.probe		= simaai_sdhci_probe,
	.priv_auto	= sizeof(struct simaai_sdhc),
	.plat_auto	= sizeof(struct simaai_sdhc_plat),
};
