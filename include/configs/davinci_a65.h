/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * (C) Copyright 2021 SiMa.ai
 */

#ifndef __CONFIG_DAVINCI_A65_H
#define __CONFIG_DAVINCI_A65_H

#include <linux/sizes.h>

#define CONFIG_DW_WDT_CLOCK_KHZ 25000

#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200, \
					  230400, 460800, 921600, 1500000, 3000000, 3500000, 4000000, 10000000 }

#define GIC_BASE 0x03200000
#define GICD_BASE (GIC_BASE + 0x00000)
#define GICR_BASE (GIC_BASE + 0x40000)

#define CPU_RELEASE_ADDR 0x8000fff8

#define CONFIG_SYS_NS16550_MEM32
#define CONFIG_DW_ALTDESCRIPTOR
#define CONFIG_ETHPRIME "eth0"
#define CONFIG_PHY_ADDR 0

#include <config_distro_bootcmd.h>

#define BOOTENV_DEFAULT_NETCFG \
	"ipaddr=192.168.1.20\0" \
	"serverip=192.168.1.10\0" \
	"autoload=no\0" \
	"forcenetcfg=\0"

#define BOOTENV_BOOTARGS \
	"bootargs_common=console=ttyS0,115200n8\0" \
	"rootfs_partid=4\0"\
	"fix_rootfs_mmc=setenv bootargs ${bootargs_common} netcfg=${netcfg} root=/dev/mmcblk${devnum}p${rootfs_partid} rw rootwait\0" \
	"fix_rootfs_cpio=setenv bootargs ${bootargs_common} netcfg=${netcfg} root=/dev/ram0 rw rootfstype=ramfs\0" \
	"fix_rootfs_nfs=setenv bootargs ${bootargs_common} netcfg=${netcfg} root=/dev/nfs rw nfsroot=${serverip}:${npath},v3 ip=${ipaddr}:::::eth0:none nfsrootdebug\0" \
	"target_rootfs=\0"

#define BOOTENV_DEV_NET(devtypeu, devtypel, instance) \
	"bootfile=netboot.scr.uimg\0" \
	"bootcmd_net=tftp ${scriptaddr} ${serverip}:${bootfile}; source ${scriptaddr}\0"
#define BOOTENV_DEV_NAME_NET(devtypeu, devtypel, instance) \
	"net "
#undef BOOTENV_DEV_DHCP
#define BOOTENV_DEV_DHCP(devtypeu, devtypel, instance) \
	"bootcmd_dhcp=previpaddr=${ipaddr}; dhcp; dns ${tftpserver} serverip; run bootcmd_net; setenv ipaddr ${previpaddr}\0"
#define BOOT_TARGET_DEVICES(func) \
	func(MMC, mmc, 1) \
	func(MMC, mmc, 0) \
	func(DHCP, dhcp, na) \
	func(NET, staticip, na)

#define ENV_MEM_LAYOUT_SETTINGS \
	"fdt_addr=0xAF000000\0" \
	"scriptaddr=0x90000000\0" \
	"kernel_addr=0xAA000000\0" \
	"cpio_addr=0xE0000000\0" \
	"cpio_size=0x18000000\0" \
	"cpio_name=simaai-image-palette-davinci.cpio.gz\0" \
	"booti_initrd=-\0"

#define BOOTENV_DEFAULT_PATH \
	"boot_path=/boot-0/\0"

#define BOOTENV_PREFIXES \
	"boot_prefixes=/boot-0/ /boot-1/\0"

#define BOOTENV_ALTBOOTCMD \
	"altbootcmd=if test -n ${boot_path} && test \"${boot_path}\" = \"/boot-0/\";then; setenv boot_prefixes /boot-1/;setenv boot_path /boot-1/;else;setenv boot_prefixes /boot-0/; setenv boot_path /boot-0/;fi;$bootcmd\0"

#define CONFIG_EXTRA_ENV_SETTINGS \
	BOOTENV_BOOTARGS \
	ENV_MEM_LAYOUT_SETTINGS \
	BOOTENV_DEFAULT_NETCFG \
	BOOTENV_DEFAULT_PATH \
	BOOTENV_ALTBOOTCMD \
	BOOTENV \
	BOOTENV_PREFIXES

#endif /* __CONFIG_DAVINCI_A65_H */
