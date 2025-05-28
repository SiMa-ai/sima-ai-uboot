// SPDX-License-Identifier: GPL-2.0-only
/*
 * SiMa.ai SoCs NVS pinctrl driver
 * Copyright (c) 2024 Sima ai
 * Author: Yurii Konovalenko <yurii.konovalenko@sima.ai>
 * 	   Nikunj Kela <nikunj.kela@sima.ai>
 */

#include <dm.h>
#include <dm/pinctrl.h>
#include <asm/io.h>
#include <dm/device_compat.h>
#include <linux/err.h>
#include <linux/bitfield.h>
#include <linux/bitops.h>

#define PCSIMAAI_PIN(a, b) { .number = a, .name = b }

#define SIMMAAI_NVS_ID_ADDR		0x00000000
#define SIMMAAI_NVS_RT_ADDR		0x00000040
#define SIMMAAI_NVS_IE_ADDR		0x00000100
#define SIMMAAI_NVS_HYS_ADDR		0x00000104
#define SIMMAAI_NVS_PUP_ADDR		0x00000108
#define SIMMAAI_NVS_PDN_ADDR		0x0000010c
#define SIMMAAI_NVS_OE_ADDR		0x00000110
#define SIMMAAI_NVS_SLEW_ADDR		0x00000114
#define SIMMAAI_NVS_STR_ADDR		0x00000120

struct pcsimaai_pin_desc {
	const char	*name;
	u32 number;
};

struct pcsimaai_pin_plat {
	struct pcsimaai_pin_desc *pins;
	u32			num_pins;
};

struct simaai_nvs_pc_priv {
	struct pcsimaai_pin_plat *plat;
	void __iomem		*base;
};

static struct pcsimaai_pin_desc pcsimaai_sdioemmc_pins[] = {
	PCSIMAAI_PIN(0, "EMMC_D0"),
	PCSIMAAI_PIN(1, "EMMC_D1"),
	PCSIMAAI_PIN(2, "EMMC_D2"),
	PCSIMAAI_PIN(3, "EMMC_D3"),
	PCSIMAAI_PIN(4, "EMMC_D4"),
	PCSIMAAI_PIN(5, "EMMC_D5"),
	PCSIMAAI_PIN(6, "EMMC_D6"),
	PCSIMAAI_PIN(7, "EMMC_D7"),
	PCSIMAAI_PIN(8, "EMMC_CMD"),
	PCSIMAAI_PIN(9, "EMMC_CLK"),
	PCSIMAAI_PIN(10, "EMMC_RST"),
	PCSIMAAI_PIN(16, "SDIO_D0"),
	PCSIMAAI_PIN(17, "SDIO_D1"),
	PCSIMAAI_PIN(18, "SDIO_D2"),
	PCSIMAAI_PIN(19, "SDIO_D3"),
	PCSIMAAI_PIN(20, "SDIO_CMD"),
	PCSIMAAI_PIN(21, "SDIO_CLK"),
	PCSIMAAI_PIN(22, "SDIO_WP"),
	PCSIMAAI_PIN(23, "SDIO_DET"),
	PCSIMAAI_PIN(24, "SDIO_VSEL"),
};

static struct pcsimaai_pin_desc pcsimaai_spi_pins[] = {
	PCSIMAAI_PIN(0, "SPI0_D0"),
	PCSIMAAI_PIN(1, "SPI0_D1"),
	PCSIMAAI_PIN(2, "SPI0_D2"),
	PCSIMAAI_PIN(3, "SPI0_D3"),
	PCSIMAAI_PIN(4, "SPI0_D4"),
	PCSIMAAI_PIN(5, "SPI0_D5"),
	PCSIMAAI_PIN(6, "SPI0_D6"),
	PCSIMAAI_PIN(7, "SPI0_D7"),
	PCSIMAAI_PIN(8, "SPI0_DMS"),
	PCSIMAAI_PIN(9, "SPI0_SCLK_N"),
	PCSIMAAI_PIN(10, "SPI0_SCLK_P"),
	PCSIMAAI_PIN(11, "SPI0_SS_IN"),
	PCSIMAAI_PIN(12, "SPI0_SS0"),
	PCSIMAAI_PIN(13, "SPI0_SS1"),
	PCSIMAAI_PIN(14, "SPI0_SS2"),
	PCSIMAAI_PIN(15, "SPI0_SS3"),
	PCSIMAAI_PIN(16, "SPI1_D0"),
	PCSIMAAI_PIN(17, "SPI1_D1"),
	PCSIMAAI_PIN(18, "SPI1_D2"),
	PCSIMAAI_PIN(19, "SPI1_D3"),
	PCSIMAAI_PIN(20, "SPI1_D4"),
	PCSIMAAI_PIN(21, "SPI1_D5"),
	PCSIMAAI_PIN(22, "SPI1_D6"),
	PCSIMAAI_PIN(23, "SPI1_D7"),
	PCSIMAAI_PIN(24, "SPI1_DMS"),
	PCSIMAAI_PIN(25, "SPI1_SCLK_N"),
	PCSIMAAI_PIN(26, "SPI1_SCLK_P"),
	PCSIMAAI_PIN(27, "SPI1_SS_IN"),
	PCSIMAAI_PIN(28, "SPI1_SS0"),
	PCSIMAAI_PIN(29, "SPI1_SS1"),
	PCSIMAAI_PIN(30, "SPI1_SS2"),
	PCSIMAAI_PIN(31, "SPI1_SS3"),
};

struct pcsimaai_pin_plat sdioemmc_plat = {
	.pins			= pcsimaai_sdioemmc_pins,
	.num_pins		= ARRAY_SIZE(pcsimaai_sdioemmc_pins),
};

struct pcsimaai_pin_plat spi_plat = {
	.pins			= pcsimaai_spi_pins,
	.num_pins		= ARRAY_SIZE(pcsimaai_spi_pins),
};

static inline int simaai_pc_idx_to_pin(struct simaai_nvs_pc_priv *priv, int index)
{
	return priv->plat->pins[index].number;
}

static const char *simaai_pc_get_pin_name(struct udevice *dev, unsigned index)
{
	struct simaai_nvs_pc_priv *priv = dev_get_priv(dev);

	return priv->plat->pins[index].name;
}

static int simaai_pc_get_pins_count(struct udevice *dev)
{
	struct simaai_nvs_pc_priv *priv = dev_get_priv(dev);

	return priv->plat->num_pins;
}

static int simaai_pc_pconf_set(struct udevice *dev, unsigned index,
			       unsigned param, unsigned argument)
{
	struct simaai_nvs_pc_priv *priv = dev_get_priv(dev);
	int offset;
	int pin_selector = simaai_pc_idx_to_pin(priv, index);
	u32 val = argument >= 1 ? 1 << pin_selector : 0;
	u32 mask = 1 << pin_selector;
	u32 regval;

	switch(param) {
	case PIN_CONFIG_BIAS_PULL_DOWN:
		offset = SIMMAAI_NVS_PDN_ADDR;
		break;

	case PIN_CONFIG_BIAS_PULL_UP:
		offset = SIMMAAI_NVS_PUP_ADDR;
		break;

	case PIN_CONFIG_DRIVE_STRENGTH:
		val = argument & 0xf;
		mask = 0xf << ((pin_selector & 7) * 4);
		offset = SIMMAAI_NVS_STR_ADDR + ((pin_selector / 8) * 4);
		break;

	case PIN_CONFIG_INPUT_ENABLE:
		offset = SIMMAAI_NVS_IE_ADDR;
		break;

	case PIN_CONFIG_OUTPUT_ENABLE:
		offset = SIMMAAI_NVS_OE_ADDR;
		break;

	case PIN_CONFIG_SLEW_RATE:
		offset = SIMMAAI_NVS_SLEW_ADDR;
		break;

	default:
		log_err("Property %u not supported\n", param);
		return -EINVAL;
	}

	regval = readl(priv->base + offset);
	regval &= ~mask;
	regval |= val;

	writel(regval, priv->base + offset);

	return 0;
}

static const struct pinconf_param simaai_pc_pconf_params[] = {
	{ "bias-pull-down", PIN_CONFIG_BIAS_PULL_DOWN, 1 },
	{ "bias-pull-up", PIN_CONFIG_BIAS_PULL_UP, 1 },
	{ "drive-strength", PIN_CONFIG_DRIVE_STRENGTH, 0 },
	{ "input-enable", PIN_CONFIG_INPUT_ENABLE, 1 },
	{ "output-enable", PIN_CONFIG_OUTPUT_ENABLE, 1 },
	{ "slew-rate", PIN_CONFIG_SLEW_RATE, 1 },
};

static const struct pinctrl_ops simaai_nvs_pc_ops = {
	.get_pins_count = simaai_pc_get_pins_count,
	.get_pin_name = simaai_pc_get_pin_name,
	.pinconf_set = simaai_pc_pconf_set,
	.pinconf_num_params = ARRAY_SIZE(simaai_pc_pconf_params),
	.pinconf_params = simaai_pc_pconf_params,
	.set_state = pinctrl_generic_set_state,
};

static int simaai_nvs_pc_probe(struct udevice *dev)
{
	struct simaai_nvs_pc_priv *priv = dev_get_priv(dev);

	priv->base = dev_read_addr_ptr(dev);
	priv->plat = (struct pcsimaai_pin_plat *)dev_get_driver_data(dev);

	/* Clear pull up register */
	writel(0, priv->base + SIMMAAI_NVS_PUP_ADDR);

	return 0;
}

static const struct udevice_id simaai_nvs_pc_ids[] = {
	{ .compatible = "simaai,pinctrl-nvs-sdemmc", (ulong)&sdioemmc_plat },
	{ .compatible = "simaai,pinctrl-nvs-spi" , (ulong)&spi_plat },
	{ }
};

U_BOOT_DRIVER(pinctrl_simaai_nvs) = {
	.name = "pinctrl_simaai_nvs",
	.id = UCLASS_PINCTRL,
	.of_match = simaai_nvs_pc_ids,
	.probe = simaai_nvs_pc_probe,
	.priv_auto	= sizeof(struct simaai_nvs_pc_priv),
	.ops = &simaai_nvs_pc_ops,
};
