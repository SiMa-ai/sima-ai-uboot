// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (c) 2024 SiMa ai
 */

#include <asm/arch/simaai_ddr_utils.h>

#define DVT_CHIP_SETTINGS \
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
		.dqa_map = { 4, 5, 7, 0, 3, 1, 6, 2, 8, 9, 10, 13, 12, 11, 15, 14 }, \
		.dqb_map = { 1, 4, 6, 3, 5, 0, 2, 7, 10, 12, 8, 11, 14, 15, 13, 9 }, \
		.caa_map = { 3, 6, 2, 5, 1, 0, 4 }, \
		.cab_map = { 0, 1, 6, 3, 2, 4, 5 }, \
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
		.dqa_map = { 6, 1, 4, 2, 3, 7, 5, 0, 8, 13, 10, 11, 12, 14, 9, 15 }, \
		.dqb_map = { 6, 7, 2, 4, 1, 5, 0, 3, 11, 15, 9, 8, 12, 13, 10, 14 }, \
		.caa_map = { 1, 5, 2, 3, 4, 0, 6 }, \
		.cab_map = { 4, 3, 5, 2, 1, 6, 0 }, \
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
		.dqa_map = { 1, 3, 7, 0, 4, 5, 6, 2, 11, 13, 9, 14, 12, 15, 8, 10 }, \
		.dqb_map = { 1, 4, 0, 3, 2, 5, 6, 7, 12, 9, 11, 14, 13, 15, 10, 8 }, \
		.caa_map = { 0, 1, 2, 3, 6, 5, 4 }, \
		.cab_map = { 6, 4, 0, 3, 2, 5, 1 }, \
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
		.dqa_map = { 5, 3, 4, 7, 1, 2, 6, 0, 8, 12, 9, 11, 10, 14, 15, 13 }, \
		.dqb_map = { 3, 5, 0, 4, 2, 7, 6, 1, 12, 13, 14, 11, 9, 8, 15, 10 }, \
		.caa_map = { 1, 4, 6, 3, 0, 5, 2 }, \
		.cab_map = { 6, 5, 4, 2, 0, 1, 3 }, \
	}, \
}

ddrc_settings_t ddrc_settings_simaai_dvt8 = {
	.ddrc_mask = 0xf,
	.freq = PHY_DDR_FREQ_6400_8,
	.chip_settings = DVT_CHIP_SETTINGS,
};

ddrc_settings_t ddrc_settings_simaai_dvt16 = {
	.ddrc_mask = 0xf,
	.freq = PHY_DDR_FREQ_6400_16,
	.chip_settings = DVT_CHIP_SETTINGS,
};

const boardinfo_t boardinfo_modalix_dvt = {
	.name = "SiMa.ai Modalix DVT X8 board",
	.id = MODALIX_DVT,
	.ddr = &ddrc_settings_simaai_dvt8,
	.ubootdtb = "simaai-modalix-dvt",
	.linuxdtb = "modalix-dvt.dtb",
};
