//SPDX-License-Identifier: (GPL-2.0+ OR MIT)
/*
 * Copyright (c) 2022 Sima ai
 */

#include <stdio.h>
#include <net.h>
#include <asm/arch/shmem.h>

#define SHMEM_OCM_ADDR 0x3FEFFF
typedef struct __attribute__ ((packed)) {
    uint8_t factory_mac[6]; //6 bytes - 0x68, 0xE1, 0x54, 0xXX, 0xXX, 0xXX
    uint32_t hwid;
    uint32_t altboot;
    uint32_t uboot_run_status;
} shmem_ocm_s;
volatile shmem_ocm_s *shmem_ocm_addr = (volatile shmem_ocm_s *)(SHMEM_OCM_ADDR);


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

uint32_t get_boot_partitions_mode( void )
{
    return (shmem_ocm_addr->altboot);
}

void shmem_ocm_set_uboot_run_mode(uint32_t state)
{
    shmem_ocm_addr->uboot_run_status =  state;
    flush_cache(SHMEM_OCM_ADDR, 1024);
    return;
}

