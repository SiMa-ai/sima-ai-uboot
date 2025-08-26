// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (c) 2025 SiMa ai
 */

#include <asm/arch/simaai_ddr_utils.h>

extern ddrc_settings_t ddrc_settings_simaai_dvt8;
extern ddrc_settings_t ddrc_settings_simaai_dvt16;

const boardinfo_t boardinfo_modalix_hhhl = {
	.name = "SiMa.ai Modalix HHHL board",
	.id = MODALIX_HHHL,
	.ddr = &ddrc_settings_simaai_dvt8,
	.ubootdtb = "simaai-modalix-hhhl",
	.linuxdtb = "modalix-hhhl.dtb",
};

const boardinfo_t boardinfo_modalix_hhhl_x16 = {
	.name = "SiMa.ai Modalix HHHL X16 board",
	.id = MODALIX_HHHL_X16,
	.ddr = &ddrc_settings_simaai_dvt16,
	.ubootdtb = "simaai-modalix-hhhl_x16",
	.linuxdtb = "modalix-hhhl_x16.dtb",
};
