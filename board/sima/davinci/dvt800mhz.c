// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (c) 2022 SiMa ai
 */

#include <asm/arch/simaai_ddr_utils.h>

static ddrc_settings_t ddrc_settings_simaai_dvt_800mhz = {
	.ddrc_mask = 0xf,
	.freq = PHY_DDR_FREQ_800MHz,
	.chip_settings = {
		[0] = {
			.tximp = PHY_DDR_TXIMP_40_OHM,
			.atximp = PHY_DDR_ATXIMP_20_OHM,
			.txodt = PHY_DDR_TXODT_80_OHM,
			.mempdds = PHY_DDR_MEMIMP_60_OHM,
			.memcaodt = PHY_DDR_MEMIMP_40_OHM,
			.memdqodt = PHY_DDR_MEMIMP_80_OHM,
			.memcavref = 0x6f,
			.memdqvref = 0x4f,
			.phyvref = 0x0f,
		},
		[1] = {
			.tximp = PHY_DDR_TXIMP_40_OHM,
			.atximp = PHY_DDR_ATXIMP_20_OHM,
			.txodt = PHY_DDR_TXODT_80_OHM,
			.mempdds = PHY_DDR_MEMIMP_60_OHM,
			.memcaodt = PHY_DDR_MEMIMP_40_OHM,
			.memdqodt = PHY_DDR_MEMIMP_80_OHM,
			.memcavref = 0x6f,
			.memdqvref = 0x4f,
			.phyvref = 0x0d,
		},
		[2] = {
			.tximp = PHY_DDR_TXIMP_40_OHM,
			.atximp = PHY_DDR_ATXIMP_20_OHM,
			.txodt = PHY_DDR_TXODT_80_OHM,
			.mempdds = PHY_DDR_MEMIMP_60_OHM,
			.memcaodt = PHY_DDR_MEMIMP_40_OHM,
			.memdqodt = PHY_DDR_MEMIMP_80_OHM,
			.memcavref = 0x6f,
			.memdqvref = 0x4f,
			.phyvref = 0x11,
		},
		[3] = {
			.tximp = PHY_DDR_TXIMP_40_OHM,
			.atximp = PHY_DDR_ATXIMP_20_OHM,
			.txodt = PHY_DDR_TXODT_80_OHM,
			.mempdds = PHY_DDR_MEMIMP_60_OHM,
			.memcaodt = PHY_DDR_MEMIMP_40_OHM,
			.memdqodt = PHY_DDR_MEMIMP_80_OHM,
			.memcavref = 0x6f,
			.memdqvref = 0x4f,
			.phyvref = 0x18,
		},
	},
};

const boardinfo_t boardinfo_simaai_800mhz = {
	.name = "SiMa.ai DVT board (800Mhz)",
	.id = DAVINCI_DVT_COMBO_BOARD,
	.ddr = &ddrc_settings_simaai_dvt_800mhz,
	.ubootdtb = "simaai-davinci-combo-board",
	.linuxdtb = "davinci-combo-board.dtb",
};
