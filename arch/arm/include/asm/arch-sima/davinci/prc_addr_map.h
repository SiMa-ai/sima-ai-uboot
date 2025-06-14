#ifndef _PRC_ADDR_MAP__H
#define _PRC_ADDR_MAP__H
#define PRC_BASE 0x30100000
#define PRC_REG__PLL_REG__NOC_PLL_CTRL_STAT_ADDR 0x00000000
#define PRC_REG__PLL_REG__NOC_PLL_TUNE_ADDR 0x00000004
#define PRC_REG__PLL_REG__APU_PLL_CTRL_STAT_ADDR 0x00000008
#define PRC_REG__PLL_REG__APU_PLL_TUNE_ADDR 0x0000000c
#define PRC_REG__PLL_REG__DDR_PLL_CTRL_STAT_ADDR 0x00000010
#define PRC_REG__PLL_REG__DDR_PLL_TUNE_ADDR 0x00000014
#define PRC_REG__PLL_REG__MLA_PLL_CTRL_STAT_ADDR 0x00000018
#define PRC_REG__PLL_REG__MLA_PLL_TUNE_ADDR 0x0000001c
#define PRC_REG__PLL_REG__CVU_PLL_CTRL_STAT_ADDR 0x00000020
#define PRC_REG__PLL_REG__CVU_PLL_TUNE_ADDR 0x00000024
#define PRC_REG__PLL_REG__SYS_PLL_CTRL_STAT_ADDR 0x00000028
#define PRC_REG__PLL_REG__SYS_PLL_TUNE_ADDR 0x0000002c
#define PRC_REG__PLL_REG__DCTL_BOOT_REG_ADDR 0x00000030
#define PRC_REG__APU_RST_VEC_REG__APU_RV_0L_REG_ADDR 0x00000040
#define PRC_REG__APU_RST_VEC_REG__APU_RV_0H_REG_ADDR 0x00000044
#define PRC_REG__APU_RST_VEC_REG__APU_RV_1L_REG_ADDR 0x00000048
#define PRC_REG__APU_RST_VEC_REG__APU_RV_1H_REG_ADDR 0x0000004c
#define PRC_REG__APU_RST_VEC_REG__APU_RV_2L_REG_ADDR 0x00000050
#define PRC_REG__APU_RST_VEC_REG__APU_RV_2H_REG_ADDR 0x00000054
#define PRC_REG__APU_RST_VEC_REG__APU_RV_3L_REG_ADDR 0x00000058
#define PRC_REG__APU_RST_VEC_REG__APU_RV_3H_REG_ADDR 0x0000005c
#define PRC_REG__APU_RST_VEC_REG__APU_RV_4L_REG_ADDR 0x00000060
#define PRC_REG__APU_RST_VEC_REG__APU_RV_4H_REG_ADDR 0x00000064
#define PRC_REG__APU_RST_VEC_REG__APU_RV_5L_REG_ADDR 0x00000068
#define PRC_REG__APU_RST_VEC_REG__APU_RV_5H_REG_ADDR 0x0000006c
#define PRC_REG__APU_RST_VEC_REG__APU_RV_6L_REG_ADDR 0x00000070
#define PRC_REG__APU_RST_VEC_REG__APU_RV_6H_REG_ADDR 0x00000074
#define PRC_REG__APU_RST_VEC_REG__APU_RV_7L_REG_ADDR 0x00000078
#define PRC_REG__APU_RST_VEC_REG__APU_RV_7H_REG_ADDR 0x0000007c
#define PRC_REG__GPIO_PAD_REG__BSU_GPIO_ADDR 0x00000080
#define PRC_REG__GPIO_PAD_REG__DAT_GPIO_ADDR 0x00000084
#define PRC_REG__GPIO_PAD_REG__LSIO_GPIO_ADDR 0x00000088
#define PRC_REG__GPIO_PAD_REG__SPI_GPIO_ADDR 0x0000008c
#define PRC_REG__PWR_REG__SRAM_PWR_REG_0_ADDR 0x00000090
#define PRC_REG__PWR_REG__PWR_REG_1_ADDR 0x000000b4
#define PRC_REG__PWR_REG__PWR_REG_2_ADDR 0x00000098
#define PRC_REG__BSU_REG__BSU_CTRL_REG_ADDR 0x0000009c
#define PRC_REG__BSU_ECC_INTR_REG__BSU_ECC_INTR_CTRL_ADDR 0x000000a0
#define PRC_REG__MISC_REG__MISC_CTRL_REG_ADDR 0x000000a8
#define PRC_REG__MISC_REG__ETH_ADDR_CTRL_REG_ADDR 0x000000ac
#define PRC_REG__POR_STAT_REG__SW_STAT_ADDR 0x000000b0
#define PRC_REG__POR_STAT_REG__TRT_HPI_STAT_ADDR 0x000000b4
#define PRC_REG__POR_STAT_REG__TRT_ECC_STAT_ADDR 0x000000b8
#define PRC_REG__THM_REG__PMON_CTRL_ADDR 0x000000c0
#define PRC_REG__THM_REG__PMON_TRIM_ADDR 0x000000c4
#define PRC_REG__THM_REG__PMON_STATUS_ADDR 0x000000c8
#define PRC_REG__THM_REG__PMON_CLK_CTRL_ADDR 0x000000cc
#define PRC_REG__THM_REG__PMON_DELAY_CTRL_ADDR 0x000000d0
#define PRC_REG__THM_REG__PMON_DATA_A_ADDR 0x000000d4
#define PRC_REG__THM_REG__PMON_DATA_B_ADDR 0x000000d8
#define PRC_REG__THM_REG__PMON_DATA_ADDR 0x000000dc
#define PRC_REG__THM_REG__DAT_INTR_ADDR 0x000000e0
#define PRC_REG__THM_REG__DAT_INTR_EN_ADDR 0x000000e4
#define PRC_REG__THM_REG__DAT_HALT_EN_ADDR 0x000000e8
#define PRC_REG__CKG_RST_REG__APU_CK_RST_ADDR 0x00000100
#define PRC_REG__CKG_RST_REG__BSU_CK_RST_ADDR 0x00000104
#define PRC_REG__CKG_RST_REG__CVU_CK_RST_ADDR 0x00000108
#define PRC_REG__CKG_RST_REG__DAT_CK_RST_ADDR 0x0000010c
#define PRC_REG__CKG_RST_REG__DMS0_CK_RST_ADDR 0x00000110
#define PRC_REG__CKG_RST_REG__DMS1_CK_RST_ADDR 0x00000114
#define PRC_REG__CKG_RST_REG__DMS2_CK_RST_ADDR 0x00000118
#define PRC_REG__CKG_RST_REG__DMS3_CK_RST_ADDR 0x0000011c
#define PRC_REG__CKG_RST_REG__ETH_CK_RST_ADDR 0x00000120
#define PRC_REG__CKG_RST_REG__IDM_CK_RST_ADDR 0x00000124
#define PRC_REG__CKG_RST_REG__LSIO_CK_RST_ADDR 0x00000128
#define PRC_REG__CKG_RST_REG__EMMC_CK_RST_ADDR 0x0000012c
#define PRC_REG__CKG_RST_REG__GPIO_CK_RST_ADDR 0x00000130
#define PRC_REG__CKG_RST_REG__I2C_CK_RST_ADDR 0x00000134
#define PRC_REG__CKG_RST_REG__SDIO_CK_RST_ADDR 0x00000138
#define PRC_REG__CKG_RST_REG__SDMA_CK_RST_ADDR 0x0000013c
#define PRC_REG__CKG_RST_REG__SIRQ_CK_RST_ADDR 0x00000140
#define PRC_REG__CKG_RST_REG__SPI_CK_RST_ADDR 0x00000144
#define PRC_REG__CKG_RST_REG__NOC_CK_ADDR 0x00000148
#define PRC_REG__CKG_RST_REG__NOC_RST_ADDR 0x0000014c
#define PRC_REG__CKG_RST_REG__MLA_CK_RST_ADDR 0x00000150
#define PRC_REG__CKG_RST_REG__OCM_CK_RST_ADDR 0x00000154
#define PRC_REG__CKG_RST_REG__PCIE_CK_RST_ADDR 0x00000158
#define PRC_REG__CKG_RST_REG__TIM_CK_RST_ADDR 0x0000015c
#define PRC_REG__CKG_RST_REG__URT_CK_RST_ADDR 0x00000160
#define PRC_REG__CKG_RST_REG__WDT_CK_RST_ADDR 0x00000164
#define PRC_REG__CKG_RST_REG__VID_CK_RST_ADDR 0x00000168
#define PRC_REG__CKG_RST_REG__BYPASS_CLK_CTRL_ADDR 0x0000016c
#define PRC_REG__CKG_RST_REG__NOC_DIV_CTRL_ADDR 0x00000170
#define PRC_REG__CKG_RST_REG__SYS_DIV_CTRL0_ADDR 0x00000174
#define PRC_REG__CKG_RST_REG__SYS_DIV_CTRL1_ADDR 0x00000178
#define PRC_REG__CKG_RST_REG__SYS_RST_CTRL_ADDR 0x0000017c
#define PRC_REG__CKG_RST_REG__WDT_RST_CTRL_ADDR 0x00000180
#endif // _PRC_ADDR_MAP__H
