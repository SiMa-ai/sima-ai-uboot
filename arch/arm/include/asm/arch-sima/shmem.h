//SPDX-License-Identifier: (GPL-2.0+ OR MIT)
/*
 * Copyright (c) 2022 Sima ai
 */

#ifndef __SHMEM_H__
#define __SHMEM_H__

#include <stdio.h>

typedef enum board_id_t {
	/* TODO: Remove MODALIX_ZEBU after efuse related
	 * changes are included in all zebu images.
	 */
	MODALIX_ZEBU			= 0x00000000,
	DAVINCI_DVT_COMBO_BOARD 	= 0x00000011,
	DAVINCI_DVT_933MHZ_BOARD 	= 0x00001011,
	DAVINCI_CHAR_BOARD 		= 0x00000021,
	DAVINCI_8L_DUAL_M2_BOARD 	= 0x00000031,
	DAVINCI_10L_DUAL_M2_BOARD 	= 0x00001031,
	DAVINCI_HHHL 			= 0x00000041,
	MODALIX_DVT 		        = 0x00000101,
	MODALIX_HHHL 		        = 0x00000121,
	MODALIX_HHHL_X16 		= 0x00001121,
	MODALIX_HHHL_V2 		= 0x00000123,
	MODALIX_HHHL_V2_1R 		= 0x00002123,
	MODALIX_SOM                     = 0x00000144,
	MODALIX_SOM_V2                  = 0x00002144,
	MODALIX_SOM_MICRONFLASH         = 0x00001144,
	MODALIX_SOM_8G                  = 0x00004144,
	MODALIX_VDK			= 0x00000FF1,
	MODALIX_ZEBU_BASIC		= 0x00000FE5,
	MODALIX_ZEBU_PCIE		= 0x00001FE5,
	MODALIX_ZEBU_ETH		= 0x00002FE5,
	MODALIX_ZEBU_MIPI		= 0x00003FE5,
} board_id_t;

#define IS_ZEBU(id) (((id) == MODALIX_ZEBU) || \
			((id) == MODALIX_ZEBU_BASIC) || \
			((id) == MODALIX_ZEBU_PCIE) || \
			((id) == MODALIX_ZEBU_ETH) || \
			((id) == MODALIX_ZEBU_MIPI))

int populate_mac(char *mac);
board_id_t get_board_id(void);
uint32_t get_boot_partitions_mode( void );
void shmem_ocm_set_uboot_run_mode(uint32_t state);
uint32_t get_pcie_enabled( void );

#endif /* __SHMEM_H__ */
