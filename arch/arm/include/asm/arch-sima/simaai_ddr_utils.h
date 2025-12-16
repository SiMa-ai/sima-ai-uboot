//SPDX-License-Identifier: (GPL-2.0+ OR MIT)
/*
 * Copyright (c) 2022 Sima ai
 */

#ifndef __SIMAAI_DDR_UTILS_H__
#define __SIMAAI_DDR_UTILS_H__

#include <stdint.h>
#include <asm/arch/phy_init.h>
#include <asm/arch/shmem.h>

#define PHY_DDR_MAX_CONTROLLERS	4
#define PHY_DDR_PRE_SEQ1_RESETS 6
#define PHY_DDR_MAX_RESETS 9

typedef struct ddrc_rst_t_ {
	uint32_t addr;
	uint32_t set_bits;
	uint32_t clr_bits;
	uint32_t delay_us;
} ddrc_rst_t;

typedef struct ddrc_addrs_t_ {
	uint32_t ddrc_base;
	uint32_t phy_base;
	ddrc_rst_t resets[PHY_DDR_MAX_RESETS];
} ddrc_addrs_t;

typedef struct ddrc_settings_t_ {
	chip_settings_t chip_settings[PHY_DDR_MAX_CONTROLLERS];
	uint32_t ddrc_mask;
	ddr_freq_t freq;
	ddr_rank_t rank;
} ddrc_settings_t;

typedef struct ddrc_t_ {
	ddrc_settings_t *settings;
	init_sequence_t *sequences;
	firmware_t *firmwares;
	ddrc_addrs_t addrs[PHY_DDR_MAX_CONTROLLERS];
} ddrc_t;

typedef struct boardinfo_t_ {
	const char name[64];
	board_id_t id;
	ddrc_settings_t* ddr;
	const char ubootdtb[64];
	const char linuxdtb[64];
} boardinfo_t;

void do_apb_write(uint32_t base, uint32_t regoff, uint32_t data);
void do_apb_read(uint32_t base, uint32_t regoff, uint32_t expdata);
void do_phy_write(uint32_t base, uint32_t regoff, uint16_t data);
void do_phy_writes(uint32_t base, uint32_t regoff, uint16_t data, uint32_t *offsets, uint32_t count);
uint16_t do_phy_read(uint32_t base, uint32_t regoff);
void do_apb_poll(uint32_t base, uint32_t regoff, uint32_t expdata);
void do_phy_poll(uint32_t base, uint32_t regoff, uint16_t expdata);

ddrc_t * get_ddrc(void);
unique_sequence_t * get_unique_vals(ddrc_t *ddrc, init_type_t sequence);
uint32_t freq_to_uint(ddr_freq_t freq);
ddrc_settings_t * get_ddrc_settings(void);
void board_specific_ddrc_settings(uint32_t cbase, chip_settings_t *sets);
void board_specific_ddrphy_settings(uint32_t phybase, chip_settings_t *sets);
void board_specific_mr_settings(uint32_t phybase, uint32_t addr, chip_settings_t *sets);

void sima_ddr_init(void);
void sima_eth_init(void);

void sima_set_dtb_name(void);

#ifdef CONFIG_CMD_DDR
void sima_ddr_reset(void);

int32_t sima_ddr_get_creg(uint32_t mask, uint32_t addr);
int32_t sima_ddr_set_creg(uint32_t mask, uint32_t addr, uint32_t value);
int32_t sima_ddr_get_phyreg(uint32_t mask, uint32_t addr);
int32_t sima_ddr_set_phyreg(uint32_t mask, uint32_t addr, uint16_t value);
int32_t sima_ddr_dump_supported_values(void);
int32_t sima_ddr_dump_settings(void);
int32_t sima_ddr_set_settings(uint32_t index, uint32_t setting, uint32_t val);
#endif

#endif /* __SIMAAI_DDR_UTILS_H__ */
