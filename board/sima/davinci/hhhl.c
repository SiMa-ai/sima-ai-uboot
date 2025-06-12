// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (c) 2023 SiMa ai
 */

#include <asm/arch/simaai_ddr_utils.h>

static ddrc_settings_t ddrc_settings_simaai_hhhl = {
	.ddrc_mask = 0xf,
	.freq = PHY_DDR_FREQ_933MHz,
	.chip_settings = {
		[0] = {
			.tximp = PHY_DDR_TXIMP_28_OHM,
			.atximp = PHY_DDR_ATXIMP_40_OHM,
			.txodt = PHY_DDR_TXODT_48_OHM,
			.mempdds = PHY_DDR_MEMIMP_60_OHM,
			.memcaodt = PHY_DDR_MEMIMP_240_OHM,
			.memdqodt = PHY_DDR_MEMIMP_40_OHM,
			.memcavref = 0x40,
			.memdqvref = 0x1d,
			.phyvref = 0x14,
		},
		[1] = {
			.tximp = PHY_DDR_TXIMP_28_OHM,
			.atximp = PHY_DDR_ATXIMP_40_OHM,
			.txodt = PHY_DDR_TXODT_44_OHM,
			.mempdds = PHY_DDR_MEMIMP_40_OHM,
			.memcaodt = PHY_DDR_MEMIMP_240_OHM,
			.memdqodt = PHY_DDR_MEMIMP_40_OHM,
			.memcavref = 0x1c,
			.memdqvref = 0x41,
			.phyvref = 0x13,
		},
		[2] = {
			.tximp = PHY_DDR_TXIMP_28_OHM,
			.atximp = PHY_DDR_ATXIMP_40_OHM,
			.txodt = PHY_DDR_TXODT_60_OHM,
			.mempdds = PHY_DDR_MEMIMP_80_OHM,
			.memcaodt = PHY_DDR_MEMIMP_240_OHM,
			.memdqodt = PHY_DDR_MEMIMP_40_OHM,
			.memcavref = 0x46,
			.memdqvref = 0x1b,
			.phyvref = 0x16,
		},
		[3] = {
			.tximp = PHY_DDR_TXIMP_28_OHM,
			.atximp = PHY_DDR_ATXIMP_40_OHM,
			.txodt = PHY_DDR_TXODT_48_OHM,
			.mempdds = PHY_DDR_MEMIMP_60_OHM,
			.memcaodt = PHY_DDR_MEMIMP_240_OHM,
			.memdqodt = PHY_DDR_MEMIMP_40_OHM,
			.memcavref = 0x41,
			.memdqvref = 0x40,
			.phyvref = 0x15,
		},
	},
};

const boardinfo_t boardinfo_simaai_hhhl = {
	.name = "SiMa.ai HHHL board",
	.id = DAVINCI_HHHL,
	.ddr = &ddrc_settings_simaai_hhhl,
	.ubootdtb = "simaai-davinci-hhhl",
	.linuxdtb = "davinci-hhhl.dtb",
};
