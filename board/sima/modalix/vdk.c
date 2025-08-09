// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (c) 2025 SiMa ai
 */

#include <asm/arch/simaai_ddr_utils.h>

ddrc_settings_t ddrc_settings_simaai_vdk = {
	.ddrc_mask = 0x0,
	.freq = PHY_DDR_FREQ_6400_8,
	.chip_settings = { },
};

const boardinfo_t boardinfo_modalix_vdk = {
	.name = "SiMa.ai Modalix VDK virtual board",
	.id = MODALIX_VDK,
	.ddr = &ddrc_settings_simaai_vdk,
	.ubootdtb = "simaai-modalix-vdk",
	.linuxdtb = "modalix-vdk.dtb",
};
