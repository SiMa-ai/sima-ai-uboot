// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (c) 2025 SiMa ai
 */

#include <asm/arch/simaai_ddr_utils.h>

#define SOM_CHIP_SETTINGS \
{ \
        { \
                .tximpse = PHY_DDR_SOCIMP_40_OHM, \
                .tximpdiff = PHY_DDR_SOCIMP_40_OHM, \
                .atximpse = PHY_DDR_SOCIMP_40_OHM, \
                .atximpdiff = PHY_DDR_SOCIMP_40_OHM, \
                .atximpcmos = PHY_DDR_SOCIMP_40_OHM, \
                .odtimpse = PHY_DDR_SOCIMP_60_OHM, \
                .odtimpdiff= PHY_DDR_SOCIMP_60_OHM, \
                .odtdq = PHY_DDR_MEMIMP_60_OHM, \
                .odtwck = PHY_DDR_MEMIMP_48_OHM, \
                .mempdds = PHY_DDR_MEMIMP_40_OHM, \
                .memcaodt = PHY_DDR_MEMIMP_80_OHM, \
                .memcsodt = PHY_DDR_MEMIMPCS_80_OHM, \
                .memdqodt = PHY_DDR_MEMIMP_40_OHM, \
                .memodtnt = PHY_DDR_MEMIMP_240_OHM, \
                .dqa_map = { 5, 7, 0, 4, 3, 1, 6, 2, 12, 11, 14, 15, 8, 13, 9, 10 }, \
                .dqb_map = { 10, 8, 9, 11, 12, 14, 13, 15, 6, 4, 7, 2, 5, 1, 0, 3 }, \
                .caa_map = { 6, 2, 0, 4, 5, 1, 3 }, \
                .cab_map = { 1, 4, 6, 5, 3, 0, 2 }, \
        }, \
        { \
                .tximpse = PHY_DDR_SOCIMP_40_OHM, \
                .tximpdiff = PHY_DDR_SOCIMP_40_OHM, \
                .atximpse = PHY_DDR_SOCIMP_40_OHM, \
                .atximpdiff = PHY_DDR_SOCIMP_40_OHM, \
                .atximpcmos = PHY_DDR_SOCIMP_40_OHM, \
                .odtimpse = PHY_DDR_SOCIMP_60_OHM, \
                .odtimpdiff= PHY_DDR_SOCIMP_60_OHM, \
                .odtdq = PHY_DDR_MEMIMP_60_OHM, \
                .odtwck = PHY_DDR_MEMIMP_48_OHM, \
                .mempdds = PHY_DDR_MEMIMP_40_OHM, \
                .memcaodt = PHY_DDR_MEMIMP_80_OHM, \
                .memcsodt = PHY_DDR_MEMIMPCS_80_OHM, \
                .memdqodt = PHY_DDR_MEMIMP_40_OHM, \
                .memodtnt = PHY_DDR_MEMIMP_240_OHM, \
                .dqa_map = { 2, 5, 3, 1, 6, 7, 4, 0, 15, 9, 8, 11, 14, 12, 10, 13 }, \
                .dqb_map = { 10, 11, 9, 8, 15, 13, 14, 12, 5, 3, 4, 0, 6, 2, 1, 7 }, \
                .caa_map = { 6, 2, 4, 1, 0, 3, 5 }, \
                .cab_map = { 0, 6, 2, 3, 4, 5, 1 }, \
        }, \
        { \
                .tximpse = PHY_DDR_SOCIMP_40_OHM, \
                .tximpdiff = PHY_DDR_SOCIMP_40_OHM, \
                .atximpse = PHY_DDR_SOCIMP_40_OHM, \
                .atximpdiff = PHY_DDR_SOCIMP_40_OHM, \
                .atximpcmos = PHY_DDR_SOCIMP_40_OHM, \
                .odtimpse = PHY_DDR_SOCIMP_60_OHM, \
                .odtimpdiff= PHY_DDR_SOCIMP_60_OHM, \
                .odtdq = PHY_DDR_MEMIMP_60_OHM, \
                .odtwck = PHY_DDR_MEMIMP_48_OHM, \
                .mempdds = PHY_DDR_MEMIMP_40_OHM, \
                .memcaodt = PHY_DDR_MEMIMP_80_OHM, \
                .memcsodt = PHY_DDR_MEMIMPCS_80_OHM, \
                .memdqodt = PHY_DDR_MEMIMP_40_OHM, \
                .memodtnt = PHY_DDR_MEMIMP_240_OHM, \
                .dqa_map = { 7, 2, 3, 1, 0, 6, 5, 4, 15, 13, 14, 12, 8, 11, 10, 9 }, \
                .dqb_map = { 11, 9, 14, 12, 10, 15, 13, 8, 7, 6, 2, 5, 4, 3, 0, 1 }, \
                .caa_map = { 4, 0, 1, 3, 2, 6, 5 }, \
                .cab_map = { 0, 1, 6, 2, 4, 3, 5 }, \
        }, \
        { \
                .tximpse = PHY_DDR_SOCIMP_40_OHM, \
                .tximpdiff = PHY_DDR_SOCIMP_40_OHM, \
                .atximpse = PHY_DDR_SOCIMP_40_OHM, \
                .atximpdiff = PHY_DDR_SOCIMP_40_OHM, \
                .atximpcmos = PHY_DDR_SOCIMP_40_OHM, \
                .odtimpse = PHY_DDR_SOCIMP_60_OHM, \
                .odtimpdiff= PHY_DDR_SOCIMP_60_OHM, \
                .odtdq = PHY_DDR_MEMIMP_60_OHM, \
                .odtwck = PHY_DDR_MEMIMP_48_OHM, \
                .mempdds = PHY_DDR_MEMIMP_40_OHM, \
                .memcaodt = PHY_DDR_MEMIMP_80_OHM, \
                .memcsodt = PHY_DDR_MEMIMPCS_80_OHM, \
                .memdqodt = PHY_DDR_MEMIMP_40_OHM, \
                .memodtnt = PHY_DDR_MEMIMP_240_OHM, \
                .dqa_map = { 2, 7, 3, 5, 0, 1, 4, 6, 12, 13, 8, 15, 9, 10, 11, 14 }, \
                .dqb_map = { 12, 14, 13, 11, 15, 10, 9, 8, 1, 7, 5, 0, 2, 3, 4, 6 }, \
                .caa_map = { 0, 2, 1, 5, 4, 6, 3 }, \
                .cab_map = { 4, 3, 0, 1, 6, 2, 5 }, \
        }, \
}

ddrc_settings_t ddrc_settings_simaai_som = {
	.ddrc_mask = 0xf,
	.freq = PHY_DDR_FREQ_6400_16,
	.chip_settings = SOM_CHIP_SETTINGS,
	.rank = DDR_DUAL_RANK,
};

ddrc_settings_t ddrc_settings_simaai_som_8g = {
	.ddrc_mask = 0xf,
	.freq = PHY_DDR_FREQ_6400_16_2GB,
	.chip_settings = SOM_CHIP_SETTINGS,
	.rank = DDR_SINGLE_RANK,
};

const boardinfo_t boardinfo_modalix_som = {
	.name = "SiMa.ai Modalix SoM X16 board",
	.id = MODALIX_SOM,
	.ddr = &ddrc_settings_simaai_som,
	.ubootdtb = "simaai-modalix-som",
	.linuxdtb = "modalix-som.dtb",
};

const boardinfo_t boardinfo_modalix_som_micronFlash = {
	.name = "SiMa.ai Modalix SoM X16 board",
	.id = MODALIX_SOM_MICRONFLASH,
	.ddr = &ddrc_settings_simaai_som,
	.ubootdtb = "simaai-modalix-som",
	.linuxdtb = "modalix-som.dtb",
};

const boardinfo_t boardinfo_modalix_som_v2 = {
	.name = "SiMa.ai Modalix SoM X16 board",
	.id = MODALIX_SOM_V2,
	.ddr = &ddrc_settings_simaai_som,
	.ubootdtb = "simaai-modalix-som",
	.linuxdtb = "modalix-som.dtb",
};

const boardinfo_t boardinfo_modalix_som_8g = {
	.name = "SiMa.ai Modalix SoM 8Gig board",
	.id = MODALIX_SOM_8G,
	.ddr = &ddrc_settings_simaai_som_8g,
	.ubootdtb = "simaai-modalix-som_8g",
	.linuxdtb = "modalix-som_8g.dtb",
};
