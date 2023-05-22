// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (c) 2022 SiMa ai
 */

#include <common.h>
#include <asm/arch/simaai_ddr_utils.h>

static ddrc_settings_t ddrc_settings_simaai_dvt_933mhz = {
	.ddrc_mask = 0xf,
	.freq = PHY_DDR_FREQ_933MHz,
	.chip_settings = {
		[0] = {
			.tximp = PHY_DDR_TXIMP_28_OHM,
			.atximp = PHY_DDR_ATXIMP_40_OHM,
			.txodt = PHY_DDR_TXODT_60_OHM,
			.mempdds = PHY_DDR_MEMIMP_48_OHM,
			.memcaodt = PHY_DDR_MEMIMP_240_OHM,
			.memdqodt = PHY_DDR_MEMIMP_40_OHM,
			.memcavref = 0x40,
			.memdqvref = 0x1c,
			.phyvref = 0x14,
		},
		[1] = {
			.tximp = PHY_DDR_TXIMP_28_OHM,
			.atximp = PHY_DDR_ATXIMP_40_OHM,
			.txodt = PHY_DDR_TXODT_37_OHM,
			.mempdds = PHY_DDR_MEMIMP_60_OHM,
			.memcaodt = PHY_DDR_MEMIMP_240_OHM,
			.memdqodt = PHY_DDR_MEMIMP_40_OHM,
			.memcavref = 0x1d,
			.memdqvref = 0x1c,
			.phyvref = 0x10,
		},
		[2] = {
			.tximp = PHY_DDR_TXIMP_28_OHM,
			.atximp = PHY_DDR_ATXIMP_30_OHM,
			.txodt = PHY_DDR_TXODT_53_OHM,
			.mempdds = PHY_DDR_MEMIMP_60_OHM,
			.memcaodt = PHY_DDR_MEMIMP_240_OHM,
			.memdqodt = PHY_DDR_MEMIMP_40_OHM,
			.memcavref = 0x18,
			.memdqvref = 0x41,
			.phyvref = 0x14,
		},
		[3] = {
			.tximp = PHY_DDR_TXIMP_28_OHM,
			.atximp = PHY_DDR_ATXIMP_40_OHM,
			.txodt = PHY_DDR_TXODT_160_OHM,
			.mempdds = PHY_DDR_MEMIMP_48_OHM,
			.memcaodt = PHY_DDR_MEMIMP_240_OHM,
			.memdqodt = PHY_DDR_MEMIMP_40_OHM,
			.memcavref = 0x44,
			.memdqvref = 0x1A,
			.phyvref = 0x18,
		},
	},
};

const boardinfo_t boardinfo_simaai_933mhz = {
	.name = "SiMa.ai DVT board (933Mhz)",
	.id = DAVINCI_DVT_933MHZ_BOARD,
	.ddr = &ddrc_settings_simaai_dvt_933mhz,
	.ubootdtb = "simaai-davinci-combo-board",
	.linuxdtb = "davinci-combo-board.dtb",
};
