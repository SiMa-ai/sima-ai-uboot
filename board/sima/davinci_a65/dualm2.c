// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (c) 2023 SiMa ai
 */

#include <common.h>
#include <asm/arch/simaai_ddr_utils.h>

static ddrc_settings_t ddrc_settings_simaai_dual_m2_8l = {
	.ddrc_mask = 0xf,
	.freq = PHY_DDR_FREQ_933MHz,
	.chip_settings = {
		[0] = {
			.tximp = PHY_DDR_TXIMP_28_OHM,
			.atximp = PHY_DDR_ATXIMP_40_OHM,
			.txodt = PHY_DDR_TXODT_80_OHM,
			.mempdds = PHY_DDR_MEMIMP_40_OHM,
			.memcaodt = PHY_DDR_MEMIMP_240_OHM,
			.memdqodt = PHY_DDR_MEMIMP_40_OHM,
			.memcavref = 0x42,
			.memdqvref = 0x4a,
			.phyvref = 0x18,
		},
		[1] = {
			.tximp = PHY_DDR_TXIMP_28_OHM,
			.atximp = PHY_DDR_ATXIMP_24_OHM,
			.txodt = PHY_DDR_TXODT_53_OHM,
			.mempdds = PHY_DDR_MEMIMP_40_OHM,
			.memcaodt = PHY_DDR_MEMIMP_240_OHM,
			.memdqodt = PHY_DDR_MEMIMP_40_OHM,
			.memcavref = 0x10,
			.memdqvref = 0x51,
			.phyvref = 0x10,
		},
		[2] = {
			.tximp = PHY_DDR_TXIMP_28_OHM,
			.atximp = PHY_DDR_ATXIMP_30_OHM,
			.txodt = PHY_DDR_TXODT_53_OHM,
			.mempdds = PHY_DDR_MEMIMP_80_OHM,
			.memcaodt = PHY_DDR_MEMIMP_240_OHM,
			.memdqodt = PHY_DDR_MEMIMP_40_OHM,
			.memcavref = 0x40,
			.memdqvref = 0x51,
			.phyvref = 0x12,
		},
		[3] = {
			.tximp = PHY_DDR_TXIMP_28_OHM,
			.atximp = PHY_DDR_ATXIMP_40_OHM,
			.txodt = PHY_DDR_TXODT_53_OHM,
			.mempdds = PHY_DDR_MEMIMP_48_OHM,
			.memcaodt = PHY_DDR_MEMIMP_240_OHM,
			.memdqodt = PHY_DDR_MEMIMP_40_OHM,
			.memcavref = 0x44,
			.memdqvref = 0x4e,
			.phyvref = 0x12,
		},
	},
};
static ddrc_settings_t ddrc_settings_simaai_dual_m2_10l = {
	.ddrc_mask = 0xf,
	.freq = PHY_DDR_FREQ_933MHz,
	.chip_settings = {
		[0] = {
			.tximp = PHY_DDR_TXIMP_28_OHM,
			.atximp = PHY_DDR_ATXIMP_40_OHM,
			.txodt = PHY_DDR_TXODT_69_OHM,
			.mempdds = PHY_DDR_MEMIMP_40_OHM,
			.memcaodt = PHY_DDR_MEMIMP_240_OHM,
			.memdqodt = PHY_DDR_MEMIMP_40_OHM,
			.memcavref = 0x42,
			.memdqvref = 0x40,
			.phyvref = 0x19,
		},
		[1] = {
			.tximp = PHY_DDR_TXIMP_28_OHM,
			.atximp = PHY_DDR_ATXIMP_40_OHM,
			.txodt = PHY_DDR_TXODT_69_OHM,
			.mempdds = PHY_DDR_MEMIMP_40_OHM,
			.memcaodt = PHY_DDR_MEMIMP_240_OHM,
			.memdqodt = PHY_DDR_MEMIMP_40_OHM,
			.memcavref = 0x17,
			.memdqvref = 0x1c,
			.phyvref = 0x19,
		},
		[2] = {
			.tximp = PHY_DDR_TXIMP_28_OHM,
			.atximp = PHY_DDR_ATXIMP_40_OHM,
			.txodt = PHY_DDR_TXODT_60_OHM,
			.mempdds = PHY_DDR_MEMIMP_120_OHM,
			.memcaodt = PHY_DDR_MEMIMP_240_OHM,
			.memdqodt = PHY_DDR_MEMIMP_40_OHM,
			.memcavref = 0x44,
			.memdqvref = 0x40,
			.phyvref = 0x16,
		},
		[3] = {
			.tximp = PHY_DDR_TXIMP_28_OHM,
			.atximp = PHY_DDR_ATXIMP_40_OHM,
			.txodt = PHY_DDR_TXODT_40_OHM,
			.mempdds = PHY_DDR_MEMIMP_40_OHM,
			.memcaodt = PHY_DDR_MEMIMP_240_OHM,
			.memdqodt = PHY_DDR_MEMIMP_40_OHM,
			.memcavref = 0x1d,
			.memdqvref = 0x1d,
			.phyvref = 0x10,
		},
	},
};

const boardinfo_t boardinfo_simaai_dual_m2_8l = {
	.name = "SiMa.ai DualM.2 board (8 layers)",
	.id = DAVINCI_8L_DUAL_M2_BOARD,
	.ddr = &ddrc_settings_simaai_dual_m2_8l,
	.ubootdtb = "simaai-davinci-dual-m2",
	.linuxdtb = "davinci-dual-m2.dtb",
};

const boardinfo_t boardinfo_simaai_dual_m2_10l = {
	.name = "SiMa.ai DualM.2 board (10 layers)",
	.id = DAVINCI_10L_DUAL_M2_BOARD,
	.ddr = &ddrc_settings_simaai_dual_m2_10l,
	.ubootdtb = "simaai-davinci-dual-m2",
	.linuxdtb = "davinci-dual-m2.dtb",
};
