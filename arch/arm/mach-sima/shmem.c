//SPDX-License-Identifier: (GPL-2.0+ OR MIT)
/*
 * Copyright (c) 2022 Sima ai
 */

#include <stdio.h>
#include <net.h>
#include <asm/arch/shmem.h>

#if defined(CONFIG_TARGET_DAVINCI)
#define SHMEM_OCM_ADDR 0x2F0000
#elif defined(CONFIG_TARGET_MODALIX)
#define SHMEM_OCM_ADDR 0x5F0000
#elif
#error Define addresh of shared structure
#endif

typedef struct __attribute__ ((packed)) {
    uint8_t factory_mac[6]; //6 bytes - 0x68, 0xE1, 0x54, 0xXX, 0xXX, 0xXX
    uint32_t hwid;
    uint32_t altboot;
    uint32_t uboot_run_status;
    uint32_t pcie_enabled;
} shmem_ocm_s;
volatile shmem_ocm_s *shmem_ocm_addr = (volatile shmem_ocm_s *)(SHMEM_OCM_ADDR);


int populate_mac(char *mac)
{
        invalidate_dcache_range(SHMEM_OCM_ADDR, SHMEM_OCM_ADDR + 1024);
        if (is_valid_ethaddr(shmem_ocm_addr->factory_mac))
                memcpy(mac, shmem_ocm_addr->factory_mac, 6);
        else
                return -1;

        return 0;
}

board_id_t get_board_id(void)
{
        invalidate_dcache_range(SHMEM_OCM_ADDR, SHMEM_OCM_ADDR + 1024);
        return (board_id_t)shmem_ocm_addr->hwid;
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

uint32_t get_pcie_enabled( void )
{
    return (shmem_ocm_addr->pcie_enabled);
}
