# SPDX-License-Identifier: GPL-2.0+

obj-y	+= simaai_ddrphy_init.o phy_init.o shmem.o simaai_ddr_utils.o simaai_ethphy_init.o

obj-$(CONFIG_TARGET_DAVINCI) += firmware_ddr.o init_ddr_800MHz.o init_ddr_933MHz.o \
			init_ddr_533MHz.o init_eth_phy.o ddr_phy_debug_davinci.o

obj-$(CONFIG_TARGET_MODALIX) += firmware_ddr_modalix.o init_ddr_modalix.o \
			init_eth_phy_modalix.o ddr_phy_debug_modalix.o
