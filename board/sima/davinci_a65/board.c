#include <common.h>
#include <cpu.h>
#include <init.h>
#include <net.h>
#include <cpu_func.h>
#include <dm.h>
#include <debug_uart.h>
#include <asm/global_data.h>
#include <asm/armv8/mmu.h>
#include <asm/arch/simaai_ddr_utils.h>


extern const boardinfo_t boardinfo_simaai_800mhz;
extern const boardinfo_t boardinfo_simaai_933mhz;
extern const boardinfo_t boardinfo_simaai_charboard;
extern const boardinfo_t boardinfo_simaai_dual_m2_8l;
extern const boardinfo_t boardinfo_simaai_dual_m2_10l;
extern const boardinfo_t boardinfo_simaai_hhhl;

static const boardinfo_t* boards[] = {
	&boardinfo_simaai_800mhz,
	&boardinfo_simaai_933mhz,
	&boardinfo_simaai_charboard,
	&boardinfo_simaai_dual_m2_8l,
	&boardinfo_simaai_dual_m2_10l,
	&boardinfo_simaai_hhhl,
};

static struct mm_region simaai_mem_map[] = {
	{
		/* OCM */
		.virt = 0x0UL,
		.phys = 0x0UL,
		.size = 0x400000UL,
		.attrs = PTE_BLOCK_MEMTYPE(MT_NORMAL) |
			 PTE_BLOCK_INNER_SHARE
	}, {
		/* Memory mapped registers */
		.virt = 0x400000UL,
		.phys = 0x400000UL,
		.size = 0x80000000UL - 0x400000UL,
		.attrs = PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
			 PTE_BLOCK_NON_SHARE |
			 PTE_BLOCK_PXN | PTE_BLOCK_UXN
	}, {
		/* DRAM */
		.virt = 0x80000000UL,
		.phys = 0x80000000UL,
		.size = 0x80000000UL,
		.attrs = PTE_BLOCK_MEMTYPE(MT_NORMAL) |
			 PTE_BLOCK_INNER_SHARE
	}, {
		/* List terminator */
		0,
	}
};

struct mm_region *mem_map = simaai_mem_map;

static boardinfo_t * get_board_info(void)
{
	int i;
	board_id_t id = get_board_id();

	for (i = 0; i < ARRAY_SIZE(boards); i++)
		if(id == boards[i]->id)
			return boards[i];

	return boards[0];
}

int arch_cpu_init(void)
{
#ifdef CONFIG_DEBUG_UART
	debug_uart_init();
#endif

	return 0;
}

int board_init(void)
{
	return 0;
}

#ifdef CONFIG_BOARD_LATE_INIT
int board_late_init(void)
{
    uint32_t altboot;
    unsigned long bootlimit;
	int32_t res = 0, i;
	unsigned char mac[6];
	boardinfo_t *info = get_board_info();

	sima_eth_init();

	res = populate_mac(mac);
	for(i = 0; i < 4; i++) {
		if(res == 0)
			eth_env_set_enetaddr_by_index("eth", i, mac);
		eth_env_get_enetaddr_by_index("eth", i, mac);
		mac[5]++;
	}
	env_set("fdt_name", info->linuxdtb);
    shmem_ocm_set_uboot_run_mode(1);
    altboot = get_boot_partitions_mode();
    if (altboot == 0x1) {
        printf("altbootmode is set in ocm shm, altboot:0x%x \n",altboot);
        if ( env_get_ulong("upgrade_available", 10, 0)) {
            bootlimit = env_get_ulong("bootlimit", 10, 0);
            /* set bootcount > bootlimit so that u-boot triggers altbootcmd to boot from secondary partitions */
            env_set_ulong("bootcount", bootlimit + 1);
            printf("set to boot from altboot \n");
        }
    }
	return 0;
}
#endif

int dram_init(void)
{
	int ret;

	ret = fdtdec_setup_mem_size_base();
	if (ret)
		return ret;

	sima_ddr_init();

#ifdef CONFIG_CMD_DDR
	cli_init();
	cli_loop();
#endif

#ifdef CPU_RELEASE_ADDR
	*(unsigned long *)CPU_RELEASE_ADDR = 0;
#endif

	return 0;
}

ddrc_settings_t * get_ddrc_settings(void)
{
	boardinfo_t *info = get_board_info();

	return info->ddr;
}

#ifdef CONFIG_MULTI_DTB_FIT
int board_fit_config_name_match(const char *name)
{
	boardinfo_t *info = get_board_info();

	if (!strcmp(name, info->ubootdtb))
		return 0;

	return -1;
}
#endif

#ifdef CONFIG_DISPLAY_BOARDINFO
int checkboard (void)
{
	boardinfo_t *info = get_board_info();

	printf("Board: %s\n", info->name);
	printf("U-boot device tree name: %s.dtb\n", info->ubootdtb);
	printf("Linux device tree name: %s\n", info->linuxdtb);

	return 0;
}
#endif
