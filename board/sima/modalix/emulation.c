// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (c) 2025 SiMa ai
 */

#include <asm/arch/simaai_ddr_utils.h>

ddrc_settings_t ddrc_settings_simaai_emulation = {
	.ddrc_mask = 0xf,
	.freq = PHY_DDR_FREQ_6400_16,
};

const boardinfo_t boardinfo_modalix_zebu = {
	.name = "SiMa.ai emulation test bench",
	.id = MODALIX_ZEBU,
	.ddr = &ddrc_settings_simaai_emulation,
	.ubootdtb = "simaai-modalix-zebu",
	.linuxdtb = "michelangelo-emulation-bench.dtb",
};
