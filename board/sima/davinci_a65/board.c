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
#ifdef CONFIG_OF_BOARD_SETUP
#include <linux/sizes.h>
#endif
#if CONFIG_IS_ENABLED(DM_GPIO)
#include <asm-generic/gpio.h>
#endif

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
		/* DRAM */

		.virt = 0x180000000UL,
		.phys = 0x180000000UL,
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

static inline unsigned int read_clusterctrl(void)
{
	unsigned int val;

	asm volatile("mrs %0, S3_0_C15_C3_4" : "=r" (val) : : "cc");
	return val;
}

static inline void write_clusterctrl(unsigned int val)
{
	asm volatile("msr S3_0_C15_C3_4, %0" : : "r" (val) : "cc");
	isb();
}

int arch_cpu_init(void)
{
	// Disable sending of Cache Clean Evict
	u32 val = read_clusterctrl();
	val |= 1 << 3;
	write_clusterctrl(val);

#ifdef CONFIG_DEBUG_UART
	debug_uart_init();
#endif

	return 0;
}

int board_init(void)
{
	return 0;
}

void sima_set_dtb_name(void)
{
	boardinfo_t *info = get_board_info();

	env_set("fdt_name", info->linuxdtb);
}

#ifdef CONFIG_BOARD_LATE_INIT
#if CONFIG_IS_ENABLED(DM_GPIO)
static void sima_reset_phy(void)
{
	ofnode node;
	struct gpio_desc gpio;
	uint32_t reset_delays[3] = { 0 };
	char node_name[] = "/ethernet@1000000";
	int i;

	for(i = 0; i < 4; i++) {
		node_name[11] = '0' + i * 2;
		node = ofnode_path(node_name);
		if (!ofnode_valid(node))
			continue;

		if (!gpio_request_by_name_nodev(node, "snps,reset-gpio", 0,
				&gpio, GPIOD_IS_OUT | GPIOD_ACTIVE_LOW))
			printf("Resetting Ethernet PHY for %s\n", node_name);
		else
			continue;

		ofnode_read_u32_array(node, "snps,reset-delays-us", reset_delays, 3);
		udelay(reset_delays[1]);
		dm_gpio_set_value(&gpio, 1);
		udelay(reset_delays[1]);
		dm_gpio_set_value(&gpio, 0);
		udelay(reset_delays[2]);
		gpio_free_list_nodev(&gpio, 1);
	}
}
#endif

int board_late_init(void)
{
    uint32_t altboot;
    unsigned long bootlimit;
	int32_t res = 0, i;
	unsigned char mac[6];
	boardinfo_t *info = get_board_info();

#if CONFIG_IS_ENABLED(DM_GPIO)
	sima_reset_phy();
#endif
	sima_eth_init();

	res = populate_mac(mac);
	for(i = 0; i < 4; i++) {
		if(res == 0)
			eth_env_set_enetaddr_by_index("eth", i, mac);
		eth_env_get_enetaddr_by_index("eth", i, mac);
		mac[5]++;
	}
	sima_set_dtb_name();
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

#ifdef CONFIG_OF_BOARD_SETUP
int ft_board_setup(void *blob, struct bd_info *bd)
{
	int  nodeoffset, res, i, len;
	const char ocm_path[] = "/reserved-memory/ocm@0";
	const char pcieocm_path[] = "/reserved-memory/ocm@300000";
	const char pcieep_path[] = "/pcie_ep@1800000";
	const char dmscma_path[][33] = { "/reserved-memory/dms@0x100000000",
					 "/reserved-memory/dms@0x200000000",
					 "/reserved-memory/dms@0x300000000",
					 "/reserved-memory/dms@0x380000000" };
	const fdt64_t new_ocm[] = { cpu_to_fdt64(0x0), cpu_to_fdt64(0x400000) };
	const fdt64_t new_pcie[] = { cpu_to_fdt64(0x400000), cpu_to_fdt64(0x0) };
	fdt64_t *new_dmscma;
	char *ep;
	long dmscma_size;

	if(get_pcie_enabled())
		printf("PCIe enabled, leaving OCM memory node unchanged\n");
	else {

		/* Disable PCIe EP driver */
		nodeoffset = fdt_path_offset(blob, pcieep_path);
		if (nodeoffset < 0) {
			printf("Cannot find path %s in dtb: %s\n", ocm_path, fdt_strerror(nodeoffset));
			return 0;
		}

		res = fdt_setprop_string(blob, nodeoffset, "status", "disabled");
		if (res < 0)
			printf("Cannot disable node %s in dtb\n", pcieep_path);
		else
			printf ("Disabled node %s in dtb\n", pcieep_path);

		/* Increase size of generic OCM */
		nodeoffset = fdt_path_offset(blob, ocm_path);
		if (nodeoffset < 0) {
			printf("Cannot find path %s in dtb: %s\n", ocm_path, fdt_strerror(nodeoffset));
			return 0;
		}

		res = fdt_setprop(blob, nodeoffset, "reg", new_ocm, sizeof(new_ocm));
		if (res < 0)
			printf("Cannot updates size of %s to 0x%08lx in dtb: %s\n", ocm_path, fdt64_to_cpu(new_ocm[1]), fdt_strerror(res));
		else
			printf ("Updated size of %s to 0x%08lx bytes in dtb\n", ocm_path, fdt64_to_cpu(new_ocm[1]));

		/* Decrease size of PCIe OCM */
		nodeoffset = fdt_path_offset(blob, pcieocm_path);
		if (nodeoffset < 0) {
			printf("Cannot find path %s in dtb: %s\n", pcieocm_path, fdt_strerror(nodeoffset));
			return 0;
		}

		res = fdt_setprop(blob, nodeoffset, "reg", new_pcie, sizeof(new_pcie));
		if (res < 0)
			printf("Cannot updates size of %s to 0x%08lx in dtb: %s\n", pcieocm_path, fdt64_to_cpu(new_pcie[1]), fdt_strerror(res));
		else
			printf ("Updated size of %s to 0x%08lx bytes in dtb\n", pcieocm_path, fdt64_to_cpu(new_pcie[1]));
	}

	ep = env_get("dms_cma_size");
	if(ep != NULL) {
		dmscma_size = simple_strtol(ep, NULL, 10);
		if(dmscma_size < SZ_1G) {
			printf("Cannot set DMS CMA size to less than 1 GB, using 1 GB instead\n");
			dmscma_size = SZ_1G;
		}
		if(dmscma_size > SZ_2G) {
			printf("Cannot set DMS CMA size to more than 2 GB, using 2 GB instead\n");
			dmscma_size = SZ_2G;
		}

		for(i = 0; i < 4; i++) {
			nodeoffset = fdt_path_offset(blob, dmscma_path[i]);
			if (nodeoffset < 0) {
				printf("Cannot find path %s in dtb: %s\n", dmscma_path[i], fdt_strerror(nodeoffset));
				continue;
			}
			new_dmscma = fdt_getprop(blob, nodeoffset, "reg", &len);
			if (!new_dmscma || (len != (sizeof(*new_dmscma) * 2))) {
				printf("Cannot get reg of %s in dtb: %s\n", dmscma_path[i], fdt_strerror(res));
				continue;
			}

			new_dmscma[1] = cpu_to_fdt64(dmscma_size);
			res = fdt_setprop(blob, nodeoffset, "reg", new_dmscma, sizeof(*new_dmscma) * 2);
			if (res < 0)
				printf("Cannot updates size of %s in dtb: %s\n", dmscma_path[i], fdt_strerror(res));
			else
				printf ("Updated size of %s to 0x%08lx bytes in dtb\n", dmscma_path[i], dmscma_size);
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

int dram_init_banksize(void)
{
        return fdtdec_setup_memory_banksize();
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

	printf("SIMAAI: \n");
	printf("Board: %s\n", info->name);
	printf("U-boot device tree name: %s.dtb\n", info->ubootdtb);
	printf("Linux device tree name: %s\n", info->linuxdtb);

	return 0;
}
#endif
