#include <cpu.h>
#include <init.h>
#include <net.h>
#include <cpu_func.h>
#include <dm.h>
#include <debug_uart.h>
#include <asm/global_data.h>
#include <asm/armv8/mmu.h>
#include <asm/arch/simaai_ddr_utils.h>
#include <asm/arch/modalix/prc_addr_map.h>
#include <asm/arch/modalix/sio_addr_map.h>
#include <asm/arch/modalix/gpio_addr_map.h>
#include <asm/arch/modalix/mlsoc_addr_map_defines.h>
#ifdef CONFIG_OF_BOARD_SETUP
#include <linux/sizes.h>
#endif

#define modalix_writel(A, T, V) *(( volatile T *)(A)) = (V)

extern const boardinfo_t boardinfo_modalix_dvt;

static const boardinfo_t* boards[] = {
	&boardinfo_modalix_dvt,
};

static struct mm_region simaai_mem_map[] = {
	{
		/* OCM */
		.virt = 0x0UL,
		.phys = 0x0UL,
		.size = 0x800000UL,
		.attrs = PTE_BLOCK_MEMTYPE(MT_NORMAL) |
			 PTE_BLOCK_INNER_SHARE
	}, {
		/* Memory mapped registers */
		.virt = 0x800000UL,
		.phys = 0x800000UL,
		.size = 0x1000000000UL - 0x800000UL,
		.attrs = PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
			 PTE_BLOCK_NON_SHARE |
			 PTE_BLOCK_PXN | PTE_BLOCK_UXN
	}, {
		/* DRAM */
		.virt = 0x1000000000UL,
		.phys = 0x1000000000UL,
		.size = 0x1000000000UL,
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

static int init_sio(void){
	/* SIO[1] UART2 - APU console 115200 */
	/* SIO[1] UART3 - CVU console 115200 */
	modalix_writel( (SIO1_AHB_START_ADDR + SIO_REG__SIO_OE_ADDR) , uint32_t, 0xa0);
	modalix_writel( (SIO1_AHB_START_ADDR + SIO_REG__SIO_RT_ADDR) , uint32_t, 0xf0);
	modalix_writel( (SIO1_AHB_START_ADDR + SIO_REG__SIO_IE_ADDR) , uint32_t, 0x50);
	modalix_writel( (SIO1_AHB_START_ADDR + SIO_REG__SIO_PDN_ADDR) , uint32_t, 0xa0);
	modalix_writel( (SIO1_AHB_START_ADDR + SIO_REG__SIO_PUP_ADDR) , uint32_t, 0x00);
	modalix_writel( (SIO1_AHB_START_ADDR + SIO_REG__SIO_STR_ADDR) , uint32_t, 0x1010000);
	modalix_writel( (SIO1_AHB_START_ADDR + SIO_REG__SIO_RSTSET_ADDR) , uint32_t, (1 << 8) | (1 << 9));
	modalix_writel( (SIO1_AHB_START_ADDR + SIO_REG__SIO_DIV__REGISTER_ARRAY_ADDR + (8 << 2)) , uint32_t, 0x1);
	modalix_writel( (SIO1_AHB_START_ADDR + SIO_REG__SIO_DIV__REGISTER_ARRAY_ADDR + (8 << 2)) , uint32_t, 0x80000001);
	modalix_writel( (SIO1_AHB_START_ADDR + SIO_REG__SIO_DIV__REGISTER_ARRAY_ADDR + (9 << 2)) , uint32_t, 0x1);
	modalix_writel( (SIO1_AHB_START_ADDR + SIO_REG__SIO_DIV__REGISTER_ARRAY_ADDR + (9 << 2)) , uint32_t, 0x80000001);
	udelay(1);
	modalix_writel( (SIO1_AHB_START_ADDR + SIO_REG__SIO_RSTCLR_ADDR) , uint32_t, (1 << 8) | (1 << 9));
	modalix_writel( (SIO1_AHB_START_ADDR + SIO_REG__SIO_MX1_ADDR) , uint32_t, 0x0100);
	modalix_writel( (SIO1_AHB_START_ADDR + SIO_REG__SIO_MX2_ADDR) , uint32_t, 0x01010000);
	modalix_writel( (SIO1_AHB_START_ADDR + 0x1000 + GPIO_REG__GPIO_SWPORTA_CTL_ADDR), uint32_t, 0xf0);
	modalix_writel( (SIO1_AHB_START_ADDR + SIO_REG__SIO_SIRQ_ADDR), uint32_t, 0xba00);
	/* SIO[2] UART2 - M4  console 115200 */
	modalix_writel( (SIO2_AHB_START_ADDR + SIO_REG__SIO_OE_ADDR) , uint32_t, 0x20);
	modalix_writel( (SIO2_AHB_START_ADDR + SIO_REG__SIO_RT_ADDR) , uint32_t, 0x30);
	modalix_writel( (SIO2_AHB_START_ADDR + SIO_REG__SIO_IE_ADDR) , uint32_t, 0x10);
	modalix_writel( (SIO2_AHB_START_ADDR + SIO_REG__SIO_PDN_ADDR) , uint32_t, 0x20);
	modalix_writel( (SIO2_AHB_START_ADDR + SIO_REG__SIO_PUP_ADDR) , uint32_t, 0x00);
	modalix_writel( (SIO2_AHB_START_ADDR + SIO_REG__SIO_STR_ADDR) , uint32_t, 0x0010000);
	modalix_writel( (SIO2_AHB_START_ADDR + SIO_REG__SIO_RSTSET_ADDR) , uint32_t, (1 << 8));
	modalix_writel( (SIO2_AHB_START_ADDR + SIO_REG__SIO_DIV__REGISTER_ARRAY_ADDR + (8 << 2)) , uint32_t, 0x87);
	modalix_writel( (SIO2_AHB_START_ADDR + SIO_REG__SIO_DIV__REGISTER_ARRAY_ADDR + (8 << 2)) , uint32_t, 0x80000087);
	udelay(1);
	modalix_writel( (SIO2_AHB_START_ADDR + SIO_REG__SIO_RSTCLR_ADDR) , uint32_t, (1 << 8));
	modalix_writel( (SIO2_AHB_START_ADDR + SIO_REG__SIO_MX1_ADDR) , uint32_t, 0x0100);
	modalix_writel( (SIO2_AHB_START_ADDR + SIO_REG__SIO_MX2_ADDR) , uint32_t, 0x00010000);
	modalix_writel( (SIO2_AHB_START_ADDR + 0x1000 + GPIO_REG__GPIO_SWPORTA_CTL_ADDR), uint32_t, 0x30);
	modalix_writel( (SIO2_AHB_START_ADDR + SIO_REG__SIO_SIRQ_ADDR), uint32_t, 0x0a00);

	return 0;
}

#ifdef CONFIG_DEBUG_UART_BOARD_INIT
void board_debug_uart_init(void)
{
	init_sio();
}
#endif

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
int board_late_init(void)
{
	uint32_t altboot;
	unsigned long bootlimit;
	int32_t res = 0, i;
	unsigned char mac[6];
	boardinfo_t *info = get_board_info();
	unsigned char fw_dev_part[4] = { 0 };
	const char *s = NULL;

	sima_eth_init();

	res = populate_mac(mac);
	for(i = 0; i < 4; i++) {
		if(res == 0)
			eth_env_set_enetaddr_by_index("eth", i, mac);
		eth_env_get_enetaddr_by_index("eth", i, mac);
		mac[5]++;
	}
	/*
	 * Interface eth1 phy(88x3310) requires the firmware
	 * loading done. These environment variables help find
	 * the firmware image. By default, mmc0:4 is used however
	 * users can override these to pick different device/partition.
	 */
	if (!env_get("storage_interface"))
		env_set("storage_interface", "mmc");

	if (!env_get("fw_dev_part")) {
		sprintf(fw_dev_part,"0:");
		s = env_get("rootfs_partid");
		strcat(fw_dev_part, s ? s : "4");
		env_set("fw_dev_part", fw_dev_part);
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
	const char pcieocm_path[] = "/reserved-memory/ocm@600000";
	const char pcieep_path[] = "/pcie0@0x6000000";
	const char dmscma_path[] = "/reserved-memory/dms@0x1400000000";

	const fdt64_t new_ocm[] = { cpu_to_fdt64(0x0), cpu_to_fdt64(0x800000) };
	const fdt64_t new_pcie[] = { cpu_to_fdt64(0x800000), cpu_to_fdt64(0x0) };
	fdt64_t *new_dmscma;
	char *ep = NULL;
	uint64_t dmscma_size = SZ_1G;

	if(get_pcie_enabled())
		printf("PCIe enabled, leaving OCM memory node unchanged\n");
	else {

		/* Disable PCIe EP driver */
		nodeoffset = fdt_path_offset(blob, pcieep_path);
		if (nodeoffset < 0) {
			printf("Cannot find path %s in dtb: %s\n", pcieep_path, fdt_strerror(nodeoffset));
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
		dmscma_size = (uint64_t)simple_strtoul(ep, NULL, 10);
		if(dmscma_size < SZ_1G) {
			printf("Cannot set DMS CMA size to less than 1 GB, using 1 GB instead\n");
			dmscma_size = SZ_1G;
		}
		if(dmscma_size > (48ULL * SZ_1G)) {
			printf("Cannot set DMS CMA size to more than 48 GB, using 48 GB instead\n");
			dmscma_size = (48ULL * SZ_1G);
		}

		nodeoffset = fdt_path_offset(blob, dmscma_path);
		if (nodeoffset < 0) {
			printf("Cannot find path %s in dtb: %s\n", dmscma_path, fdt_strerror(nodeoffset));
			return 0;
		}
		new_dmscma = fdt_getprop(blob, nodeoffset, "reg", &len);
		if (!new_dmscma || (len != (sizeof(*new_dmscma) * 2))) {
			printf("Cannot get reg of %s in dtb: %s\n", dmscma_path, fdt_strerror(res));
			return 0;
		}

		new_dmscma[1] = cpu_to_fdt64(dmscma_size);
		res = fdt_setprop(blob, nodeoffset, "reg", new_dmscma, sizeof(*new_dmscma) * 2);
		if (res < 0)
			printf("Cannot updates size of %s in dtb: %s\n", dmscma_path, fdt_strerror(res));
		else
			printf ("Updated size of %s to 0x%08lx bytes in dtb\n", dmscma_path, dmscma_size);
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
