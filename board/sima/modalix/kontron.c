// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (c) 2026 SiMa ai
 */

#include <asm/arch/simaai_ddr_utils.h>

#define KONTRON_CHIP_SETTINGS \
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
                .dqa_map = { 2, 1, 3, 6, 7, 0, 4, 5, 12, 11, 14, 15, 8, 13, 9, 10 }, \
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
                .dqa_map = { 12, 11, 8, 14, 9, 13, 10, 15, 5, 2, 1, 0, 3, 6, 4, 7 }, \
                .dqb_map = { 10, 11, 9, 8, 15, 13, 14, 12, 3, 4, 0, 5, 6, 2, 1, 7 }, \
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
                .dqa_map = { 6, 3, 2, 0, 7, 5, 4, 1, 15, 13, 11, 14, 9, 8, 10, 12 }, \
                .dqb_map = { 8, 14, 10, 12, 11, 15, 13, 9, 1, 2, 0, 3, 4, 6, 7, 5 }, \
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
                .dqa_map = { 3, 1, 2, 0, 6, 5, 7, 4, 13, 12, 9, 8, 11, 10, 14, 15 }, \
                .dqb_map = { 11, 14, 12, 8, 10, 13, 9, 15, 4, 3, 0, 1, 6, 2, 7, 5 }, \
                .caa_map = { 0, 2, 1, 5, 4, 6, 3 }, \
                .cab_map = { 4, 3, 0, 1, 6, 2, 5 }, \
        }, \
}

ddrc_settings_t ddrc_settings_simaai_kontron = {
	.ddrc_mask = 0xf,
	.type = PHY_DDR_3200_X16_2R_16Gb,
	.chip_settings = KONTRON_CHIP_SETTINGS,
};

const boardinfo_t boardinfo_modalix_kontron = {
	.name = "SiMa.ai Modalix Kontron board",
	.id = MODALIX_KONTRON,
	.ddr = &ddrc_settings_simaai_kontron,
	.ubootdtb = "simaai-modalix-kontron",
	.linuxdtb = "modalix-kontron.dtb",
};
