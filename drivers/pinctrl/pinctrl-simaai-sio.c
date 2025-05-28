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
#include <log.h>
#include <dm/device_compat.h>
#include <linux/err.h>
#include <linux/bitfield.h>
#include <linux/bitops.h>

#define SIMMAAI_SIO_ID_ADDR		0x00000000
#define SIMMAAI_SIO_RT_ADDR		0x00000040
#define SIMMAAI_SIO_PDN_ADDR		0x00000104
#define SIMMAAI_SIO_PUP_ADDR		0x00000108
#define SIMMAAI_SIO_HYS_ADDR		0x0000010c
#define SIMMAAI_SIO_STR_ADDR		0x00000110
#define SIMMAAI_SIO_SLEW_ADDR		0x00000114
#define SIMMAAI_SIO_OE_ADDR		0x00000118
#define SIMMAAI_SIO_IE_ADDR		0x0000011c
#define SIMMAAI_SIO_ODEM_ADDR		0x00000120
#define SIMMAAI_SIO_ODPOL_ADDR		0x00000124
#define SIMMAAI_SIO_MX1_ADDR		0x00000204
#define SIMMAAI_SIO_MX2_ADDR		0x00000208

#define pcsimaai_spioe			0x7
#define pcsimaai_spiie			0xf
#define pcsimaai_i2coe			0x3
#define pcsimaai_i2cie			0x3
#define pcsimaai_uartoe			0x2
#define pcsimaai_uartie			0x3
#define pcsimaai_gpiooe			0x1
#define pcsimaai_gpioie			0x1

struct simaai_sio_pin_desc {
	const char	*name;
	u32 number;
};

struct simaai_sio_pin_group {
	const char		*name;
	const u32		*pins;
	const u32		num_pins;
	const u32		oe_val;
	const u32		ie_val;
	const u32		mux1_offset;
	const u32		mux2_offset;
};

struct simaai_sio_pin_func {
	const char		*name;
	const char * const	*groups;
	const u32		num_groups;
	const u32		mux1_val;
	const u32		mux2_val;
	const u32		gpio_val;
};

#define PINCTRL_PIN(a, b)		{ .number = a, .name = b }
#define SIMAAI_SIO_PIN(n)		PINCTRL_PIN(n, "PIN"#n)

#define SIMAAI_SIO_PINGROUP(block, n, m1, m2) { \
	.name = #block#n"_group", \
	.pins = block##n##_pins, \
	.num_pins = ARRAY_SIZE(block##n##_pins), \
	.oe_val = (pcsimaai_##block##oe) << ((ARRAY_SIZE(block##n##_pins)) * n), \
	.ie_val = (pcsimaai_##block##ie) << ((ARRAY_SIZE(block##n##_pins)) * n), \
	.mux1_offset = m1, \
	.mux2_offset = m2, \
}

#define SIMAAI_SIO_PINFUNCTION(block, m1, m2, g) { \
	.name = #block, \
	.groups = block##_groups, \
	.num_groups = ARRAY_SIZE(block##_groups), \
	.mux1_val = m1, \
	.mux2_val = m2, \
	.gpio_val = g, \
}

static struct simaai_sio_pin_desc sio_pins[] = {
	SIMAAI_SIO_PIN(0),
	SIMAAI_SIO_PIN(1),
	SIMAAI_SIO_PIN(2),
	SIMAAI_SIO_PIN(3),
	SIMAAI_SIO_PIN(4),
	SIMAAI_SIO_PIN(5),
	SIMAAI_SIO_PIN(6),
	SIMAAI_SIO_PIN(7),
};

static const u32 spi0_pins[] = { 0, 1, 2, 3 };
static const u32 spi1_pins[] = { 4, 5, 6, 7 };
static const u32 i2c0_pins[] = { 0, 1 };
static const u32 i2c1_pins[] = { 2, 3 };
static const u32 i2c2_pins[] = { 4, 5 };
static const u32 i2c3_pins[] = { 6, 7 };
static const u32 uart0_pins[] = { 0, 1 };
static const u32 uart1_pins[] = { 2, 3 };
static const u32 uart2_pins[] = { 4, 5 };
static const u32 uart3_pins[] = { 6, 7 };
static const u32 gpio0_pins[] = { 0 };
static const u32 gpio1_pins[] = { 1 };
static const u32 gpio2_pins[] = { 2 };
static const u32 gpio3_pins[] = { 3 };
static const u32 gpio4_pins[] = { 4 };
static const u32 gpio5_pins[] = { 5 };
static const u32 gpio6_pins[] = { 6 };
static const u32 gpio7_pins[] = { 7 };

static const char * const spi_groups[]	  = { "spi0_group", "spi1_group", };
static const char * const i2c_groups[]	  = { "i2c0_group", "i2c1_group", "i2c2_group",
					      "i2c3_group", };
static const char * const uart_groups[]	  = { "uart0_group", "uart1_group", "uart2_group",
					      "uart3_group", };
static const char * const gpio_groups[]	  = { "gpio0_group", "gpio1_group", "gpio2_group",
					      "gpio3_group", "gpio4_group", "gpio5_group",
					      "gpio6_group", "gpio7_group", };

static const struct simaai_sio_pin_group sio_pin_groups[] = {
	SIMAAI_SIO_PINGROUP(spi, 0, 0, 0),
	SIMAAI_SIO_PINGROUP(spi, 1, 8, 0),
	SIMAAI_SIO_PINGROUP(i2c, 0, 0, 0),
	SIMAAI_SIO_PINGROUP(i2c, 1, 0, 8),
	SIMAAI_SIO_PINGROUP(i2c, 2, 8, 16),
	SIMAAI_SIO_PINGROUP(i2c, 3, 8, 24),
	SIMAAI_SIO_PINGROUP(uart, 0, 0, 0),
	SIMAAI_SIO_PINGROUP(uart, 1, 0, 8),
	SIMAAI_SIO_PINGROUP(uart, 2, 8, 16),
	SIMAAI_SIO_PINGROUP(uart, 3, 8, 24),
	SIMAAI_SIO_PINGROUP(gpio, 0, 0, 0),
	SIMAAI_SIO_PINGROUP(gpio, 1, 0, 0),
	SIMAAI_SIO_PINGROUP(gpio, 2, 0, 8),
	SIMAAI_SIO_PINGROUP(gpio, 3, 0, 8),
	SIMAAI_SIO_PINGROUP(gpio, 4, 8, 16),
	SIMAAI_SIO_PINGROUP(gpio, 5, 8, 16),
	SIMAAI_SIO_PINGROUP(gpio, 6, 8, 24),
	SIMAAI_SIO_PINGROUP(gpio, 7, 8, 24),
};

static const struct simaai_sio_pin_func sio_pin_functions[] = {
	SIMAAI_SIO_PINFUNCTION(spi, 0, 0, 1),
	SIMAAI_SIO_PINFUNCTION(i2c, 1, 0, 1),
	SIMAAI_SIO_PINFUNCTION(uart, 1, 1, 1),
	SIMAAI_SIO_PINFUNCTION(gpio, 1, 2, 0),
};

struct simaai_sio_pc_priv {
	struct simaai_sio_pin_desc	*pins;
	u32 			num_pins;
	const struct simaai_sio_pin_group *pin_groups;
	u32			num_pin_groups;
	const struct simaai_sio_pin_func *functions;
	u32			num_functions;
	void __iomem		*ctl_base;
	void __iomem		*gpio_base;
};

static int simaai_sio_pc_get_pins_count(struct udevice *dev)
{
	struct simaai_sio_pc_priv *priv = dev_get_priv(dev);

	return priv->num_pins;
}

static const char *simaai_sio_pc_get_pin_name(struct udevice *dev, unsigned index)
{
	struct simaai_sio_pc_priv *priv = dev_get_priv(dev);

	return priv->pins[index].name;
}

static int simaai_sio_pc_get_groups_count(struct udevice *dev)
{
	struct simaai_sio_pc_priv *priv = dev_get_priv(dev);

	return priv->num_pin_groups;
}

static const char *simaai_sio_pc_get_group_name(struct udevice *dev,
						unsigned selector)
{
	struct simaai_sio_pc_priv *priv = dev_get_priv(dev);

	return priv->pin_groups[selector].name;
}

static int simaai_sio_pc_get_functions_count(struct udevice *dev)
{
	struct simaai_sio_pc_priv *priv = dev_get_priv(dev);

	return priv->num_functions;
}

static const char *simaai_sio_pc_get_function_name(struct udevice *dev,
						unsigned selector)
{
	struct simaai_sio_pc_priv *priv = dev_get_priv(dev);

	return priv->functions[selector].name;
}

static int simaai_sio_pc_pinmux_group_set(struct udevice *dev, unsigned group_selector,
					unsigned func_selector)
{
	struct simaai_sio_pc_priv *priv = dev_get_priv(dev);
	const struct simaai_sio_pin_group *pin_group;
	u32 ie, oe, mux;
	int i;

	if (group_selector >= priv->num_pin_groups) {
		log_err("%s: Invalid group %d\n", __func__, group_selector);
		return -EINVAL;
	}

	if (func_selector >= priv->num_functions) {
		log_err("%s: Invalid function %d\n", __func__, func_selector);
		return -EINVAL;
	}

	pin_group = &priv->pin_groups[group_selector];

	/* Configure Input/Output enable */
	oe = readl(priv->ctl_base + SIMMAAI_SIO_OE_ADDR);
	ie = readl(priv->ctl_base + SIMMAAI_SIO_IE_ADDR);
	for (i = 0; i < pin_group->num_pins; i++) {
		oe &= ~(1 << pin_group->pins[i]);
		ie &= ~(1 << pin_group->pins[i]);
	}
	oe |= pin_group->oe_val;
	ie |= pin_group->ie_val;
	writel(oe, priv->ctl_base + SIMMAAI_SIO_OE_ADDR);
	writel(ie, priv->ctl_base + SIMMAAI_SIO_IE_ADDR);

	/* Write MUX1 and MUX2 */
	mux = readl(priv->ctl_base + SIMMAAI_SIO_MX1_ADDR);
	mux &= ~(1 << pin_group->mux1_offset);
	mux |= priv->functions[func_selector].mux1_val << pin_group->mux1_offset;
	writel(mux, priv->ctl_base + SIMMAAI_SIO_MX1_ADDR);
	mux = readl(priv->ctl_base + SIMMAAI_SIO_MX2_ADDR);
	mux &= ~(3 << pin_group->mux2_offset);
	mux |= priv->functions[func_selector].mux2_val << pin_group->mux2_offset;
	writel(mux, priv->ctl_base + SIMMAAI_SIO_MX2_ADDR);

	/* Configure GPIO register */
	mux = readl(priv->gpio_base);
	for (i = 0; i < pin_group->num_pins; i++) {
		mux &= ~(1 << pin_group->pins[i]);
		mux |= (priv->functions[func_selector].gpio_val & 1) << pin_group->pins[i];
	}
	writel(mux, priv->gpio_base);

	return 0;
}

static int simaai_sio_pc_pconf_set(struct udevice *dev, unsigned index,
			       unsigned param, unsigned argument)
{
	struct simaai_sio_pc_priv *priv = dev_get_priv(dev);
	u32 val = argument >= 1 ? 1 << index : 0;
	u32 mask = 1 << index;
	u32 regval;
	u32 offset;

	if (index >= priv->num_pins) {
		log_err("%s: Invalid pin %d\n", __func__, index);
		return -EINVAL;
	}

	switch(param) {
	case PIN_CONFIG_BIAS_PULL_DOWN:
		offset = SIMMAAI_SIO_PDN_ADDR;
		break;

	case PIN_CONFIG_BIAS_PULL_UP:
		offset = SIMMAAI_SIO_PUP_ADDR;
		break;

	case PIN_CONFIG_DRIVE_STRENGTH:
		val = argument & 0xf;
		mask = 0xf << (index * 4);
		offset = SIMMAAI_SIO_STR_ADDR;
		break;

	case PIN_CONFIG_INPUT_ENABLE:
		offset = SIMMAAI_SIO_IE_ADDR;
		break;

	case PIN_CONFIG_OUTPUT_ENABLE:
		offset = SIMMAAI_SIO_OE_ADDR;
		break;

	case PIN_CONFIG_SLEW_RATE:
		offset = SIMMAAI_SIO_SLEW_ADDR;
		break;

	default:
		log_err("%s: Property %u not supported\n", __func__, param);
		return -EINVAL;
	}

	regval = readl(priv->ctl_base + offset);
	regval &= ~mask;
	regval |= val;
	writel(regval, priv->ctl_base + offset);

	return 0;
}

static int simaai_sio_pc_pconf_group_set(struct udevice *dev, unsigned group_selector,
					unsigned param, unsigned argument)
{
	struct simaai_sio_pc_priv *priv = dev_get_priv(dev);
	unsigned int num_pins, current_pin;
	int ret;

	if (group_selector >= priv->num_pin_groups) {
		log_err("%s: Invalid group %d\n", __func__, group_selector);
		return -EINVAL;
	}

	num_pins = priv->pin_groups[group_selector].num_pins;

	for (current_pin = 0; current_pin < num_pins; current_pin++) {
		ret = simaai_sio_pc_pconf_set(dev,
				priv->pin_groups[group_selector].pins[current_pin],
				param, argument);
		if (ret < 0)
			return ret;
	}

	return 0;
}

static const struct pinconf_param simaai_sio_pc_pconf_params[] = {
	{ "bias-pull-down", PIN_CONFIG_BIAS_PULL_DOWN, 1 },
	{ "bias-pull-up", PIN_CONFIG_BIAS_PULL_UP, 1 },
	{ "drive-strength", PIN_CONFIG_DRIVE_STRENGTH, 0 },
	{ "input-enable", PIN_CONFIG_INPUT_ENABLE, 1 },
	{ "output-enable", PIN_CONFIG_OUTPUT_ENABLE, 1 },
	{ "slew-rate", PIN_CONFIG_SLEW_RATE, 1 },
};

static const struct pinctrl_ops simaai_sio_pc_ops = {
	.set_state      = pinctrl_generic_set_state,
	.get_pins_count = simaai_sio_pc_get_pins_count,
	.get_pin_name	= simaai_sio_pc_get_pin_name,
	.get_groups_count = simaai_sio_pc_get_groups_count,
	.get_group_name = simaai_sio_pc_get_group_name,
	.get_functions_count = simaai_sio_pc_get_functions_count,
	.get_function_name = simaai_sio_pc_get_function_name,
	.pinmux_group_set = simaai_sio_pc_pinmux_group_set,
#if CONFIG_IS_ENABLED(PINCONF)
	.pinconf_num_params = ARRAY_SIZE(simaai_sio_pc_pconf_params),
	.pinconf_params = simaai_sio_pc_pconf_params,
	.pinconf_set = simaai_sio_pc_pconf_set,
	.pinconf_group_set = simaai_sio_pc_pconf_group_set,
#endif
};

static int simaai_sio_pc_probe(struct udevice *dev)
{
	struct simaai_sio_pc_priv *priv = dev_get_priv(dev);

	priv->ctl_base = (void __iomem *)devfdt_get_addr_name(dev, "ctl");
	if (!priv->ctl_base) {
		log_err("%s: Failed to read ctl address\n", __func__);
		return -EINVAL;
	}

	priv->gpio_base = (void __iomem *)devfdt_get_addr_name(dev, "gpio");
	if (!priv->gpio_base) {
		log_err("%s: Failed to read gpio address\n", __func__);
		return -EINVAL;
	}

	priv->pins = sio_pins;
	priv->num_pins = ARRAY_SIZE(sio_pins);
	priv->functions = sio_pin_functions;
	priv->num_functions = ARRAY_SIZE(sio_pin_functions);
	priv->pin_groups = sio_pin_groups;
	priv->num_pin_groups = ARRAY_SIZE(sio_pin_groups);

	return 0;
}

static const struct udevice_id simaai_sio_pc_ids[] = {
	{ .compatible = "simaai,pinctrl-sio" },
	{ }
};

U_BOOT_DRIVER(pinctrl_simaai_sio) = {
	.name = "pinctrl_simaai_sio",
	.id = UCLASS_PINCTRL,
	.of_match = simaai_sio_pc_ids,
	.probe = simaai_sio_pc_probe,
	.priv_auto	= sizeof(struct simaai_sio_pc_priv),
	.ops = &simaai_sio_pc_ops,
};
