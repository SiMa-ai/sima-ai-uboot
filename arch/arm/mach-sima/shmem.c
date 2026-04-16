//SPDX-License-Identifier: (GPL-2.0+ OR MIT)
/*
 * Copyright (c) 2022 Sima ai
 */

#include <stdio.h>
#include <net.h>
#include <asm/arch/shmem.h>
#include <asm/io.h>
#include <asm/cache.h>

#if defined(CONFIG_TARGET_DAVINCI)
#define SHMEM_OCM_ADDR 0x2F0000
#elif defined(CONFIG_TARGET_MODALIX)
#define SHMEM_OCM_ADDR 0x5F0000
#elif
#error Define addresh of shared structure
#endif

typedef struct __attribute__((packed))
{
        uint8_t factory_mac[6]; // 6 bytes - 0x68, 0xE1, 0x54, 0xXX, 0xXX, 0xXX
        uint32_t hwid;
        uint32_t altboot;
        uint32_t uboot_run_status;
        uint32_t pcie_enabled;
        uint32_t atf_run_status;
        uint32_t atf_load_in_progress;
        uint16_t ddr_init_done;
        uint64_t secondary_cores_address;
        uint64_t secondary_cores_ddr_address;
        uint64_t src_addr;
        uint64_t len;
        uint16_t secure_boot;
        uint32_t mla_freq;
        uint8_t u_boot_src;
} shmem_ocm_s;
volatile shmem_ocm_s *shmem_ocm_addr = (volatile shmem_ocm_s *)(SHMEM_OCM_ADDR);
#define VERIFY_IMAGE (6)
#define ATF_LOAD_DONE (7)

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

uint32_t get_mla_freq( void )
{
        return (shmem_ocm_addr->mla_freq);
}

uint32_t get_pcie_enabled( void )
{
    return (shmem_ocm_addr->pcie_enabled);
}

uint16_t shmem_ddr_init_done(void)
{
    invalidate_dcache_range(SHMEM_OCM_ADDR, SHMEM_OCM_ADDR + 1024);
    return (board_id_t)shmem_ocm_addr->ddr_init_done;
}

uint16_t get_secure_boot_status(void)
{
    invalidate_dcache_range(SHMEM_OCM_ADDR, SHMEM_OCM_ADDR + 1024);
    return shmem_ocm_addr->secure_boot;
}

bool verify_image(uint64_t src_phys, uint64_t len, uint64_t *out_len)
{
    volatile uint32_t load_state = 1;

    // OCM is also a physical address; convert to virtual
    uint8_t *ocm_addr = phys_to_virt(0x200000);
    uint64_t offset = 0;
    uint64_t chunk = 1024 * 1024;

    *out_len = 0;
    printf("Verifying secure kernel image\n");

    while (offset < len)
    {
        uint64_t cur_len = (offset + chunk) > len ? (len - offset) : chunk;

        // Map source DDR physical to virtual
        uint8_t *src_v = phys_to_virt(src_phys + offset);

        // Copy chunk from DDR to OCM
        memcpy(ocm_addr, src_v, cur_len);
        offset += cur_len;

        flush_cache(ocm_addr, cur_len);

        // Notify tRoot to decrypt
        shmem_ocm_addr->src_addr = (uint64_t)ocm_addr;
        shmem_ocm_addr->len = cur_len;
        shmem_ocm_addr->atf_run_status = VERIFY_IMAGE;
        shmem_ocm_addr->atf_load_in_progress = 1;
        flush_cache(SHMEM_OCM_ADDR, 1024);

        // Wait for decryption to complete
        while (1)
        {
            invalidate_dcache_range(SHMEM_OCM_ADDR, SHMEM_OCM_ADDR + 1024);
            load_state = shmem_ocm_addr->atf_load_in_progress;
            if (load_state == 0)
            {
                cur_len = shmem_ocm_addr->len;
                break;
            }
        }
        if (cur_len == 0) {
                printf("*** kernel verification failure ****\n");
                while(1);
        }
        invalidate_dcache_range(ocm_addr, ocm_addr + chunk);

        // Map destination DDR physical to virtual
        uint8_t *dst_v = phys_to_virt(src_phys + *out_len);
        memcpy(dst_v, ocm_addr, cur_len);
        *out_len += cur_len;
    }

    shmem_ocm_addr->atf_run_status = ATF_LOAD_DONE;
    flush_cache(SHMEM_OCM_ADDR, 1024);

    return true;
}

uint8_t shmem_get_uboot_src(void) {
    invalidate_dcache_range(SHMEM_OCM_ADDR, SHMEM_OCM_ADDR + 1024);
    return shmem_ocm_addr->u_boot_src;
}
