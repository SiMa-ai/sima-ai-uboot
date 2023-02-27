//SPDX-License-Identifier: (GPL-2.0+ OR MIT)
/*
 * Copyright (c) 2022 Sima ai
 */

#include <stdio.h>
#include <net.h>
#include <asm/arch/shmem.h>

#define SHMEM_OCM_ADDR 0x3FEFFF

int populate_mac(char *mac)
{
	char *pmac = (char *)SHMEM_OCM_ADDR;

	if (is_valid_ethaddr(pmac))
		memcpy(mac, pmac, 6);
	else
		return -1;

	return 0;
}

board_id_t get_board_id(void)
{
	char *pid = (char *)SHMEM_OCM_ADDR + 6;
	unsigned int id;

	memcpy(&id, pid, sizeof(id));

	return (board_id_t)id;
}
