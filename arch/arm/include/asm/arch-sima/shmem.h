//SPDX-License-Identifier: (GPL-2.0+ OR MIT)
/*
 * Copyright (c) 2022 Sima ai
 */

#ifndef __SHMEM_H__
#define __SHMEM_H__

typedef enum board_id_t {
	DAVINCI_DVT_COMBO_BOARD 	= 0x00000011,
	DAVINCI_DVT_933MHZ_BOARD 	= 0x00001011,
	DAVINCI_CHAR_BOARD 		= 0x00000021,
	DAVINCI_8L_DUAL_M2_BOARD 	= 0x00000031,
	DAVINCI_10L_DUAL_M2_BOARD 	= 0x00001031,
	DAVINCI_HHHL 			= 0x00000041,
} board_id_t;

int populate_mac(char *mac);
board_id_t get_board_id(void);

#endif /* __SHMEM_H__ */
