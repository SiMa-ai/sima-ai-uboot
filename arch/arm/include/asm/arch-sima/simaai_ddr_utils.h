//SPDX-License-Identifier: (GPL-2.0+ OR MIT)
/*
 * Copyright (c) 2022 Sima ai
 */

#ifndef __SIMAAI_DDR_UTILS_H__
#define __SIMAAI_DDR_UTILS_H__

#include <asm/arch/phy_init.h>
#include <asm/arch/shmem.h>
#include <asm/arch/prc_addr_map.h>

#define PHY_DDR_MAX_CONTROLLERS	4

typedef struct ddrc_addrs_t_ {
	uint32_t ddrc_base;
	uint32_t phy_base;
	uint32_t rst_addr;
} ddrc_addrs_t;

typedef struct ddrc_settings_t_ {
	chip_settings_t chip_settings[PHY_DDR_MAX_CONTROLLERS];
	uint32_t ddrc_mask;
	ddr_freq_t freq;
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

ddrc_t * get_ddrc(void);
uint32_t freq_to_uint(ddr_freq_t freq);
ddrc_settings_t * get_ddrc_settings(void);

void sima_ddr_init(void);
void sima_eth_init(void);

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
