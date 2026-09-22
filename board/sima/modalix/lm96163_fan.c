// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (c) 2026 SiMa.ai
 *
 * Early autonomous fan control for the on-board LM96163 on Modalix SoM.
 *
 * The LM96163 drives the board PWM fan from an internal lookup table (LUT)
 * that maps the remote-diode temperature to a PWM duty, fully autonomously
 * (no OS involvement). Programming the LUT here in U-Boot means the fan is
 * controlled correctly from the earliest boot, and the configuration is
 * preserved across the handoff to Linux: the kernel lm63 driver only reads
 * these registers, it never reprograms them.
 *
 * The Linux thermal zone (board_sensor in modalix-som-common.dtsi) remains
 * as monitoring plus the critical-temperature shutdown backstop.
 */

#include <dm.h>
#include <i2c.h>
#include <log.h>
#include <linux/delay.h>
#include <linux/kernel.h>

/*
 * The LM96163 sits on i2c23 (SoM I2C bus) at address 0x4c. The bus is
 * exposed to U-Boot's DM via the "i2c0 = &i2c23" alias in the SoM dts, so
 * its sequence number is 0. Update this if the alias changes.
 */
#define LM96163_I2C_BUS			0
#define LM96163_I2C_ADDR		0x4c

/* LM96163 / LM63 register map (subset) */
#define LM63_REG_CONFIG1		0x03
#define LM63_REG_CONFIG_FAN		0x4a
#define LM63_REG_PWM_VALUE		0x4c
#define LM63_REG_PWM_FREQ		0x4d
#define LM63_REG_LUT_TEMP_HYST		0x4f
#define LM63_REG_LUT_TEMP(n)		(0x50 + 2 * (n))
#define LM63_REG_LUT_PWM(n)		(0x51 + 2 * (n))
#define LM96163_REG_CONFIG_ENHANCED	0x45

/* CONFIG1 (0x03) */
#define CONFIG1_STANDBY			0x40	/* 1 = standby (no conversions) */
#define CONFIG1_TACH_ENABLE		0x04	/* 1 = Alert/Tach pin is tach in */

/* Fan configuration (0x4a) */
#define FAN_CONFIG_MANUAL		0x20	/* 0 = LUT/auto, 1 = manual PWM */
#define FAN_CONFIG_PWM_CLK_LOW		0x08	/* 0 = 360kHz base (needed hi-res) */
#define FAN_CONFIG_PWM_INVERT		0x10	/* 0 = active-high PWM output */

/* Enhanced config (0x45) */
#define ENH_PWM_HIGHRES			0x10	/* 1 = 8-bit (0..255) PWM duty */
#define ENH_LUT_TEMP_HIGHRES		0x20	/* 1 = 0.5C LUT temp step */

/*
 * High-resolution PWM on the LM96163 requires PWM_FREQ == 8 (matches the
 * kernel lm63 driver's detection). With the 360 kHz base that gives a
 * ~22.5 kHz PWM output (good for 4-wire fans) and full 0..255 duty
 * resolution, so a duty register value is simply round(percent * 255/100).
 */
#define LM96163_PWM_FREQ		8
#define PCT_TO_PWM255(pct)		(((pct) * 255 + 50) / 100)

/* LUT temperature hysteresis before the fan steps back down (deg C) */
#define LM96163_LUT_HYST_C		5

/*
 * The DesignWare i2c controller's first probe can fail this early in boot
 * (its enable-status lags right after the SIO2 block comes out of reset);
 * a re-probe brings it up. Retry a bounded number of times.
 */
#define LM96163_PROBE_RETRIES		25

/*
 * Requested SoM fan curve:
 *   low temp / boot : 50%
 *   50 C            : 75%
 *   70 C and above  : 100%
 * Intermediate points are linearly interpolated (1.25 %/C on each segment).
 * Entry 0 is the floor applied at low temperatures (the "on boot" duty);
 * the trailing entries hold 100%. Temperatures are remote-diode degrees C.
 * The LM96163 has a 12-entry LUT, so all 12 slots are programmed.
 */
struct lm96163_lut_point {
	u8 temp_c;
	u8 pwm_pct;
};

static const struct lm96163_lut_point fan_curve[] = {
	{ 30,  50 },	/* floor / boot */
	{ 35,  56 },
	{ 40,  63 },
	{ 45,  69 },
	{ 50,  75 },	/* anchor: 50 C -> 75% */
	{ 55,  81 },
	{ 60,  88 },
	{ 65,  94 },
	{ 70, 100 },	/* anchor: 70 C -> 100% */
	{ 75, 100 },
	{ 80, 100 },
	{ 85, 100 },
};

static int lm96163_wr(struct udevice *dev, u8 reg, u8 val)
{
	return dm_i2c_write(dev, reg, &val, 1);
}

static int lm96163_rmw(struct udevice *dev, u8 reg, u8 clr, u8 set)
{
	u8 val;
	int ret;

	ret = dm_i2c_read(dev, reg, &val, 1);
	if (ret)
		return ret;
	val = (val & ~clr) | set;
	return lm96163_wr(dev, reg, val);
}

int modalix_lm96163_fan_init(void)
{
	struct udevice *dev;
	int i, ret = -ENODEV;

	/* Re-probe until the i2c controller comes up (see comment above). */
	for (i = 0; i < LM96163_PROBE_RETRIES; i++) {
		ret = i2c_get_chip_for_busnum(LM96163_I2C_BUS,
					      LM96163_I2C_ADDR, 1, &dev);
		if (!ret)
			break;
		mdelay(10);
	}
	if (ret) {
		printf("lm96163: not found on i2c%d@0x%02x (%d)\n",
		       LM96163_I2C_BUS, LM96163_I2C_ADDR, ret);
		return ret;
	}

	/* 1. PWM base frequency 8 -> enables hi-res PWM, ~22.5 kHz output. */
	ret = lm96163_wr(dev, LM63_REG_PWM_FREQ, LM96163_PWM_FREQ);
	if (ret)
		goto err;

	/* 2. Enhanced config: enable hi-res (0..255) PWM, keep 1C LUT steps. */
	ret = lm96163_rmw(dev, LM96163_REG_CONFIG_ENHANCED,
			  ENH_LUT_TEMP_HIGHRES, ENH_PWM_HIGHRES);
	if (ret)
		goto err;

	/*
	 * 3. Fan config: stay in MANUAL mode while the LUT is programmed - the
	 *    LUT registers are read-only in lookup-table (auto) mode. Select
	 *    the 360 kHz PWM clock (required for hi-res) and active-high
	 *    output. Adjust FAN_CONFIG_PWM_INVERT if the board inverts the
	 *    fan PWM line.
	 */
	ret = lm96163_rmw(dev, LM63_REG_CONFIG_FAN,
			  FAN_CONFIG_PWM_CLK_LOW | FAN_CONFIG_PWM_INVERT,
			  FAN_CONFIG_MANUAL);
	if (ret)
		goto err;

	/* 4. Program the 12-entry LUT (temperature, duty). */
	for (i = 0; i < ARRAY_SIZE(fan_curve); i++) {
		ret = lm96163_wr(dev, LM63_REG_LUT_TEMP(i),
				 fan_curve[i].temp_c);
		if (ret)
			goto err;
		ret = lm96163_wr(dev, LM63_REG_LUT_PWM(i),
				 PCT_TO_PWM255(fan_curve[i].pwm_pct));
		if (ret)
			goto err;
	}

	/* 5. LUT hysteresis to avoid fan-speed oscillation. */
	ret = lm96163_wr(dev, LM63_REG_LUT_TEMP_HYST, LM96163_LUT_HYST_C);
	if (ret)
		goto err;

	/* 6. Switch to lookup-table (auto) mode now that the LUT is set. */
	ret = lm96163_rmw(dev, LM63_REG_CONFIG_FAN, FAN_CONFIG_MANUAL, 0);
	if (ret)
		goto err;

	/* 7. Enable the tachometer input and leave standby (start sensing). */
	ret = lm96163_rmw(dev, LM63_REG_CONFIG1,
			  CONFIG1_STANDBY, CONFIG1_TACH_ENABLE);
	if (ret)
		goto err;

	printf("lm96163: fan LUT set (50%%/75%%@50C/100%%@70C), tach enabled\n");
	return 0;

err:
	printf("lm96163: configuration failed (%d)\n", ret);
	return ret;
}
