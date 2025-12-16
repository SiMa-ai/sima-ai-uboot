//SPDX-License-Identifier: (GPL-2.0+ OR MIT)
/*
 * Copyright (c) 2022 Sima ai
 */

#ifndef __PHY_INIT_H__
#define __PHY_INIT_H__

#include <linux/types.h>

#define DIAGNOSTIC_TEST 0
#ifdef CONFIG_CMD_DDR
#define PRINT_PHY_TRAINING_MESSAGES 1
#endif

typedef enum ddr_rank_t_ {
	DDR_SINGLE_RANK,
	DDR_DUAL_RANK,
	DDR_MAX_RANK
} ddr_rank_t;

typedef enum ddr_freq_t_ {
	PHY_DDR_FREQ_533MHz,
	PHY_DDR_FREQ_800MHz,
	PHY_DDR_FREQ_933MHz,
	PHY_DDR_FREQ_3200_8,
	PHY_DDR_FREQ_3200_16,
	PHY_DDR_FREQ_6400_8,
	PHY_DDR_FREQ_6400_16,
	PHY_DDR_FREQ_6400_16_2GB,
	PHY_DDR_FREQ_NUM,
} ddr_freq_t;

typedef enum init_type_t_ {
	PHY_INIT_TYPE_WRITE,
	PHY_INIT_TYPE_WRITE_FREQ,
	PHY_INIT_TYPE_READ,
	PHY_INIT_TYPE_POLL,
	PHY_INIT_TYPE_PHY,
	PHY_INIT_TYPE_PHY_FREQ,
	PHY_INIT_TYPE_FIRMWARE,
	PHY_INIT_TYPE_RUN,
	PHY_INIT_TYPE_DEBUG,
	PHY_INIT_TYPE_DUMPEYE,
	PHY_INIT_TYPE_PHYPOLL,
	PHY_INIT_TYPE_DDRCSETTINGS,
	PHY_INIT_TYPE_PHYSETTINGS,
	PHY_INIT_TYPE_DEBUG_RANGE,
	PHY_INIT_TYPE_NUM
} init_type_t;

typedef struct init_element_t_ {
	init_type_t type;
	uint32_t addr;
	uint32_t value;
} init_element_t;

typedef uint16_t firmware_value_t;

typedef struct unique_sequence_t_ {
	init_element_t * elements;
	uint32_t size;
} unique_sequence_t;

typedef struct init_sequence_t_ {
	init_element_t * elements;
	uint32_t size;
	unique_sequence_t unique_vals[PHY_DDR_FREQ_NUM];
} init_sequence_t;

typedef struct firmware_t_ {
	firmware_value_t * values;
	uint32_t addr;
	uint32_t size;
} firmware_t;

typedef enum phy_init_sequnence_t_ {
	PHY_INIT_DDR_PRERESET,
	PHY_INIT_DDR_POSTRESET,
	PHY_INIT_DDR_1D_TRAINING,
	PHY_INIT_DDR_2D_TRAINING,
	PHY_INIT_DDR_NO_TRAINING,
	PHY_INIT_DDR_DIAGNOSTIC,
	PHY_INIT_DDR_STORE,
	PHY_INIT_DDR_FINAL,
	PHY_INIT_DDR_PREPARE_MAILBOX,
	PHY_INIT_ETH_PREVRRESET,
	PHY_INIT_ETH_POSTVRRESET,
	PHY_INIT_ETH_SGMII,
	PHY_INIT_ETH_USXGMII,
	PHY_INIT_ETH_10GBASER,
	PHY_INIT_NUM,
} phy_init_sequnence_t;

typedef enum phy_ddr_firmware_t_ {
	PHY_DDR_FIRMWARE_1D_CODE,
	PHY_DDR_FIRMWARE_1D_DATA,
	PHY_DDR_FIRMWARE_2D_CODE,
	PHY_DDR_FIRMWARE_2D_DATA,
#if ((DIAGNOSTIC_TEST == 4) || (DIAGNOSTIC_TEST == 5) || (DIAGNOSTIC_TEST == 6))
	PHY_DDR_FIRMWARE_DIAG_CODE,
	PHY_DDR_FIRMWARE_DIAG_DATA,
#endif
	PHY_DDR_FIRMWARE_NUM,
} phy_ddr_firmware_t;

typedef enum ddr_tximp_t_ {
	PHY_DDR_TXIMP_480_OHM = 0x041,
	PHY_DDR_TXIMP_240_OHM = 0x082,
	PHY_DDR_TXIMP_160_OHM = 0x0C3,
	PHY_DDR_TXIMP_120_OHM = 0x208,
	PHY_DDR_TXIMP_96_OHM = 0x249,
	PHY_DDR_TXIMP_80_OHM = 0x28A,
	PHY_DDR_TXIMP_69_OHM = 0x2CB,
	PHY_DDR_TXIMP_60_OHM = 0x618,
	PHY_DDR_TXIMP_53_OHM = 0x659,
	PHY_DDR_TXIMP_48_OHM = 0x69A,
	PHY_DDR_TXIMP_44_OHM = 0x6DB,
	PHY_DDR_TXIMP_40_OHM = 0xE38,
	PHY_DDR_TXIMP_37_OHM = 0xE79,
	PHY_DDR_TXIMP_34_OHM = 0xEBA,
	PHY_DDR_TXIMP_32_OHM = 0xEFB,
	PHY_DDR_TXIMP_30_OHM = 0xFBE,
	PHY_DDR_TXIMP_28_OHM = 0xFFF,
} ddr_tximp_t;

typedef enum ddr_atximp_t_ {
	PHY_DDR_ATXIMP_120_OHM = 0x000,
	PHY_DDR_ATXIMP_60_OHM = 0x021,
	PHY_DDR_ATXIMP_40_OHM = 0x063,
	PHY_DDR_ATXIMP_30_OHM = 0x0E7,
	PHY_DDR_ATXIMP_24_OHM = 0x1EF,
	PHY_DDR_ATXIMP_20_OHM = 0x3FF,
} ddr_atximp_t;

typedef enum ddr_txodt_t_ {
	PHY_DDR_TXODT_480_OHM = 0x040,
	PHY_DDR_TXODT_240_OHM = 0x080,
	PHY_DDR_TXODT_160_OHM = 0x0C0,
	PHY_DDR_TXODT_120_OHM = 0x200,
	PHY_DDR_TXODT_96_OHM = 0x240,
	PHY_DDR_TXODT_80_OHM = 0x280,
	PHY_DDR_TXODT_69_OHM = 0x2C0,
	PHY_DDR_TXODT_60_OHM = 0x600,
	PHY_DDR_TXODT_53_OHM = 0x640,
	PHY_DDR_TXODT_48_OHM = 0x680,
	PHY_DDR_TXODT_44_OHM = 0x6C0,
	PHY_DDR_TXODT_40_OHM = 0xE00,
	PHY_DDR_TXODT_37_OHM = 0xE40,
	PHY_DDR_TXODT_34_OHM = 0xE80,
	PHY_DDR_TXODT_32_OHM = 0xEC0,
	PHY_DDR_TXODT_30_OHM = 0xF80,
	PHY_DDR_TXODT_28_OHM = 0xFC0,
} ddr_txodt_t;

typedef enum ddr_memimp_t_ {
	PHY_DDR_MEMIMP_DISABLE = 0x0,
	PHY_DDR_MEMIMP_240_OHM = 0x1,
	PHY_DDR_MEMIMP_120_OHM = 0x2,
	PHY_DDR_MEMIMP_80_OHM = 0x3,
	PHY_DDR_MEMIMP_60_OHM = 0x4,
	PHY_DDR_MEMIMP_48_OHM = 0x5,
	PHY_DDR_MEMIMP_40_OHM = 0x6,
	PHY_DDR_MEMIMP_RFU = 0x7,
} ddr_memimp_t;

typedef enum ddr_memimpcs_t_ {
	PHY_DDR_MEMIMPCS_80_OHM = 0x0,
	PHY_DDR_MEMIMPCS_120_OHM = 0x1,
	PHY_DDR_MEMIMPCS_240_OHM = 0x2,
	PHY_DDR_MEMIMPCS_RFU = 0x3,
} ddr_memimpcs_t;

typedef enum ddr5_socimp_t_ {
	PHY_DDR_SOCIMP_HIGHIMP = 0x000,
	PHY_DDR_SOCIMP_120_OHM = 0x808,
	PHY_DDR_SOCIMP_60_OHM = 0xC0C,
	PHY_DDR_SOCIMP_40_OHM = 0xE0E,
	PHY_DDR_SOCIMP_30_OHM = 0xF0F,
} ddr5_socimp_t;

typedef enum ddr5_cmosimp_t_ {
	PHY_DDR_CMOSIMP_400_OHM = 0x00,
	PHY_DDR_CMOSIMP_100_OHM = 0x11,
	PHY_DDR_CMOSIMP_66_OHM = 0x22,
	PHY_DDR_CMOSIMP_50_OHM = 0x33,
} ddr5_cmosimp_t;

#define VREFGLOBAL(v) (0x4 & 0xfc07) | ((((v * 100000)/(128 * 500)) + 1) << 3)

#define PHY_DDR_MR1(d)		0x64
#define PHY_DDR_MR2(d)		0x36
#define PHY_DDR_MR3(d)		(0xC3 | (d->mempdds << 3))
#define PHY_DDR_MR4(d)		0x0
#define PHY_DDR_MR13(d)		0x18
#define PHY_DDR_MR16(d)		0x0
#define PHY_DDR_MR24(d)		0x0
#define PHY_DDR_MR11(d)		((d->memcaodt << 4) | (d->memdqodt))
#define PHY_DDR_MR12(d)		(d->memcavref)
#define PHY_DDR_MR14(d)		(d->memdqvref)

typedef struct chip_settings_t_ {
	ddr_tximp_t tximp;
	ddr_atximp_t atximp;
	ddr_txodt_t txodt;
	ddr5_socimp_t tximpse;		// TxImpedanceSE
	ddr5_socimp_t tximpdiff;	// TxImpedanceDIFF
	ddr5_socimp_t atximpse;		// ATxImpedanceSE
	ddr5_socimp_t atximpdiff;	// ATxImpedanceDIFF
	ddr5_cmosimp_t atximpcmos;	// ATxImpedanceCMOS
	ddr5_socimp_t odtimpse;		// OdtImpedanceSE
	ddr5_socimp_t odtimpdiff;	// OdtImpedanceDIFF
	ddr_memimp_t odtdq;		// ODT DQ
	ddr_memimp_t odtwck;		// ODT WCK
	ddr_memimp_t mempdds;		// PDDS
	ddr_memimp_t memcaodt;		// ODT CA/CK
	ddr_memimpcs_t memcsodt;	// ODT CS
	ddr_memimp_t memdqodt;		// SoC ODT
	ddr_memimp_t memodtnt;		// ODT NT
	int8_t memcavref;
	int8_t memdqvref;
	uint32_t phyvref;
	uint8_t dqa_map[16];
	uint8_t dqb_map[16];
	uint8_t caa_map[7];
	uint8_t cab_map[7];
} chip_settings_t;

int32_t run_sequence(uint32_t cbase, uint32_t phybase, init_sequence_t s,
		firmware_t *f, int32_t fs, chip_settings_t *sets, unique_sequence_t *u);
int32_t wait_training_completion(uint32_t ddrcbase, uint32_t ddrcphybase,
		init_sequence_t s, firmware_t *f, int32_t fs);

#endif /* __PHY_INIT_H__ */
