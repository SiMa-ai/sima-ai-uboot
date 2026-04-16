// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (c) 2025 SiMa ai
 */

#include <asm/arch/simaai_ddr_utils.h>

ddrc_settings_t ddrc_settings_simaai_emulation = {
	.ddrc_mask = 0xf,
	.type = PHY_DDR_3200_X16_2R_16Gb,
};

const boardinfo_t boardinfo_modalix_zebu = {
	.name = "SiMa.ai emulation ethernet test bench",
	.id = MODALIX_ZEBU,
	.ddr = &ddrc_settings_simaai_emulation,
	.ubootdtb = "simaai-modalix-zebu",
	.linuxdtb = "modalix-zebu-eth.dtb",
};

const boardinfo_t boardinfo_modalix_zebu_basic = {
	.name = "SiMa.ai basic zebu test bench",
	.id = MODALIX_ZEBU_BASIC,
	.ddr = &ddrc_settings_simaai_emulation,
	.ubootdtb = "simaai-modalix-zebu",
	.linuxdtb = "modalix-zebu-basic.dtb",
};

const boardinfo_t boardinfo_modalix_zebu_pcie = {
	.name = "SiMa.ai pcie zebu test bench",
	.id = MODALIX_ZEBU_PCIE,
	.ddr = &ddrc_settings_simaai_emulation,
	.ubootdtb = "simaai-modalix-zebu",
	.linuxdtb = "modalix-zebu-pcie.dtb",
};

const boardinfo_t boardinfo_modalix_zebu_eth = {
	.name = "SiMa.ai eth zebu test bench",
	.id = MODALIX_ZEBU_ETH,
	.ddr = &ddrc_settings_simaai_emulation,
	.ubootdtb = "simaai-modalix-zebu",
	.linuxdtb = "modalix-zebu-eth.dtb",
};

const boardinfo_t boardinfo_modalix_zebu_mipi = {
	.name = "SiMa.ai mipi zebu test bench",
	.id = MODALIX_ZEBU_MIPI,
	.ddr = &ddrc_settings_simaai_emulation,
	.ubootdtb = "simaai-modalix-zebu",
	.linuxdtb = "modalix-zebu-eth.dtb",
};
