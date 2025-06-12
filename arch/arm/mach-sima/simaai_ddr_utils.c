// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (c) 2022 SiMa ai
 */

#include <linux/kernel.h>
#include <asm/arch/simaai_ddr_utils.h>
#include <asm/arch/firmware_ddr.h>
#include <asm/arch/shmem.h>
#include <linux/delay.h>
#if defined(CONFIG_TARGET_DAVINCI)
#include <asm/arch/init_ddr_933MHz.h>
#include <asm/arch/init_ddr_800MHz.h>
#include <asm/arch/init_ddr_533MHz.h>
#include <asm/arch/davinci/prc_addr_map.h>
#define DMS0_APB_START_ADDR 0x05800000
#define DMS1_APB_START_ADDR 0x05810000
#define DMS2_APB_START_ADDR 0x05820000
#define DMS3_APB_START_ADDR 0x05830000
#define DMS0_PHY_APB_START_ADDR 0x03800000
#define DMS1_PHY_APB_START_ADDR 0x04000000
#define DMS2_PHY_APB_START_ADDR 0x04800000
#define DMS3_PHY_APB_START_ADDR 0x05000000
#define RST_SET0 0x31f
#define RST_CLR0 0x0
#define RST_SET1 0x20
#define RST_CLR1 0x200
#define RST_SET2 0x0
#define RST_CLR2 0x0
#define RST_SET3 0x0
#define RST_CLR3 0x0
#define RST_SET4 0x0
#define RST_CLR4 0x0
#define RST_SET5 0x0
#define RST_CLR5 0x0
#define RST_SET6 0x4c0
#define RST_CLR6 0x0
#define RST_SET7 0x0
#define RST_CLR7 0x0
typedef volatile uint16_t ddrphy_reg_t;
#elif defined(CONFIG_TARGET_MODALIX)
#include <asm/arch/init_ddr_modalix.h>
#include <asm/arch/modalix/prc_addr_map.h>
#include <asm/arch/modalix/mlsoc_addr_map_defines.h>
#define PRC_BASE PRC_APB_START_ADDR
#define DMS0_PHY_APB_START_ADDR (DMS0_APB_START_ADDR + 0x2000000)
#define DMS1_PHY_APB_START_ADDR (DMS1_APB_START_ADDR + 0x2000000)
#define DMS2_PHY_APB_START_ADDR (DMS2_APB_START_ADDR + 0x2000000)
#define DMS3_PHY_APB_START_ADDR (DMS3_APB_START_ADDR + 0x2000000)
#define RST_SET0 0x40
#define RST_CLR0 0x00
#define RST_SET1 0x01
#define RST_CLR1 0x00
#define RST_SET2 0x08
#define RST_CLR2 0x30
#define RST_SET3 0x30
#define RST_CLR3 0x00
#define RST_SET4 0x00
#define RST_CLR4 0x08
#define RST_SET5 0x08
#define RST_CLR5 0x00
#define RST_SET6 0x06
#define RST_CLR6 0x00
#define RST_SET7 0x00
#define RST_CLR7 0x30
typedef volatile uint32_t ddrphy_reg_t;
#endif

#define RESET_WITH_SLEEP(a, s, c, us) { \
	.addr = a, \
	.set_bits = s, \
	.clr_bits = c, \
	.delay_us = us, \
}

#define RESET_NO_SLEEP(a, s, c) RESET_WITH_SLEEP(a, s, c, 0)
#define DDRPHY_REG_SIZE sizeof(ddrphy_reg_t)

typedef int32_t (*get_sequence_t)(init_sequence_t **sequences);

#ifdef PRINT_PHY_TRAINING_MESSAGES
#if defined(CONFIG_TARGET_DAVINCI)
char major_messages[0x100][90] = {
	[0x00] = "End of initialization",
	[0x01] = "End of fine write leveling",
	[0x02] = "End of read enable training",
	[0x03] = "End of read delay center optimization",
	[0x04] = "End of write delay center optimization",
	[0x05] = "End of 2D read delay/voltage center optimization",
	[0x06] = "End of 2D write delay /voltage center optimization",
	[0x07] = "Training has run successfully (firmware complete)",
	/*[0x08] = "Start streaming message mode",*/
	[0x09] = "End of max read latency training",
	[0x0a] = "End of read dq deskew training",
	[0x0b] = "Reserved",
	[0x0c] = "End of all DB training (MREP/DWL/MRD/MWD complete)",
	[0x0d] = "End of CA training",
	[0x0e ... 0xfc] = "",
	[0xfd] = "End of MPR read delay center optimization",
	[0xfe] = "End of Write leveling coarse delay",
	[0xff] = "Training has failed (firmware complete)",
};
#elif defined(CONFIG_TARGET_MODALIX)
char major_messages[0x100][90] = {
	[0x00] = "End of initialization",
	[0x01] = "End of fine write leveling",
	[0x02] = "End of read enable training",
	[0x03] = "End of read delay center optimization",
	[0x04] = "End of write delay center optimization",
	[0x05] = "End of RxDigStrobe training",
	[0x06] = "End of DRAM DCA training",
	[0x07] = "PMU has completed all of its SequenceCtrl tasks and is in a power gated idle state",
	/*[0x08] = "Start streaming message mode",*/
	[0x09] = "End of MaxRdLat training",
	[0x0a] = "End of PHY RX DCA training",
	[0x0b] = "End of PHY TX DCA training",
	[0x0c] = "End of all DB training (MREP/DWL/MRD/MWD complete)",
	[0x0d] = "End of CA training",
	[0x0e] = "End of TxDFE training",
	[0x0f ... 0xfc] = "",
	[0xfd] = "End of Read Training center optimization ( SI Friendly portion of 1d RdDqs training)",
	[0xfe] = "End of Write leveling coarse delay",
	[0xff] = "Training has failed (firmware complete)",
};
#endif
#endif

#if defined(CONFIG_TARGET_DAVINCI)
static get_sequence_t sequences[PHY_DDR_FREQ_NUM] = {
	[PHY_DDR_FREQ_533MHz] = get_sequence_init_ddr_533MHz,
	[PHY_DDR_FREQ_800MHz] = get_sequence_init_ddr_800MHz,
	[PHY_DDR_FREQ_933MHz] = get_sequence_init_ddr_933MHz,
};

#if (DIAGNOSTIC_TEST == 4)
static init_element_t seq_diag_ddr[] = {
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0  },
	{ .type=PHY_INIT_TYPE_DEBUG, .addr=0xd0000, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_FIRMWARE, .addr=0x50000, .value=0x4  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x1  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0  },
	{ .type=PHY_INIT_TYPE_FIRMWARE, .addr=0x54200, .value=0x5  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54200, .value=0x0004  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54201, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54202, .value=0xfe00  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54203, .value=0x00fe  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54206, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54207, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x00032, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0009  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_RUN, .addr=0x5420b, .value=0x2  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_DEBUG, .addr=0x5420b, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_DEBUG, .addr=0x5420c, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_DEBUG, .addr=0x5420d, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_DEBUG, .addr=0x5420e, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_DEBUG, .addr=0x5420f, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_DEBUG, .addr=0x54210, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_DEBUG, .addr=0x54211, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_DEBUG, .addr=0x54212, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_DEBUG, .addr=0x54213, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_DEBUG, .addr=0x54214, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_DEBUG, .addr=0x54215, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_DEBUG, .addr=0x54216, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x1  },
};
#elif (DIAGNOSTIC_TEST == 5)
static init_element_t seq_diag_ddr[] = {
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0  },
	{ .type=PHY_INIT_TYPE_DEBUG, .addr=0xd0000, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_FIRMWARE, .addr=0x50000, .value=0x4  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x1  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0  },
	{ .type=PHY_INIT_TYPE_FIRMWARE, .addr=0x54200, .value=0x5  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54200, .value=0x0005  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54201, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54202, .value=0xfe00  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54203, .value=0x01fe  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54204, .value=0x0101  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54205, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54206, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54207, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54208, .value=0xaaaa  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54209, .value=0xaaaa  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x00032, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0009  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_RUN, .addr=0x0, .value=0x0  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_DUMPEYE, .addr=0x5420b, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x1  },
};
#elif (DIAGNOSTIC_TEST == 6)
static init_element_t seq_diag_ddr[] = {
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0  },
	{ .type=PHY_INIT_TYPE_DEBUG, .addr=0xd0000, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_FIRMWARE, .addr=0x50000, .value=0x4  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x1  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0  },
	{ .type=PHY_INIT_TYPE_FIRMWARE, .addr=0x54200, .value=0x5  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54200, .value=0x0006  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54201, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54202, .value=0xfe00  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54203, .value=0x01fe  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54204, .value=0x0101  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54205, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54206, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54207, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54208, .value=0xaaaa  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x54209, .value=0xaaaa  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x00032, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0009  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_RUN, .addr=0x0, .value=0x0  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_DUMPEYE, .addr=0x5420b, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x1  },
};
#endif
#endif

#if defined(CONFIG_TARGET_MODALIX)
#if (DIAGNOSTIC_TEST == 4)
static init_element_t seq_diag_ddr[] = {
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xc0080, .value=0x3 },
	{ .type=PHY_INIT_TYPE_DEBUG, .addr=0xd0000, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_FIRMWARE, .addr=0x50000, .value=0x2  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x1  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value    =0x0  },
	{ .type=PHY_INIT_TYPE_FIRMWARE, .addr=0x58200, .value=0x3  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x58200, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x58201, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x58202, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x58203, .value=0x0020  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x58204, .value=0x0100  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x58205, .value=0x2000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x58206, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x58207, .value=0xffff  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x58208, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x58209, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x5820a, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x5820b, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x00032, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0009  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_RUN, .addr=0x0, .value=0x0  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_DEBUG_RANGE, .addr=0x58220, .value=0x0020  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x1  },
};

#elif (DIAGNOSTIC_TEST == 5) || (DIAGNOSTIC_TEST == 6)
static init_element_t seq_diag_ddr[] = {
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xc0080, .value=0x3 },
	{ .type=PHY_INIT_TYPE_DEBUG, .addr=0xd0000, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_FIRMWARE, .addr=0x50000, .value=0x2  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x1  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value    =0x0  },
	{ .type=PHY_INIT_TYPE_FIRMWARE, .addr=0x58200, .value=0x3  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x58200, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x58201, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x58202, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x58203, .value=0x0020  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x58204, .value=0x0100  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x58205, .value=0x2000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x58206, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x58207, .value=0xffff  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x58208, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x58209, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x5820a, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x5820b, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x00032, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0009  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_RUN, .addr=0x0, .value=0x0  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0001  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_DUMPEYE, .addr=0x58220, .value=0x0000  },
	{ .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x1  },
};
#endif
#endif

static uint32_t freqs[PHY_DDR_FREQ_NUM] = {
#if defined(CONFIG_TARGET_DAVINCI)
	[PHY_DDR_FREQ_533MHz] = 533,
	[PHY_DDR_FREQ_800MHz] = 800,
	[PHY_DDR_FREQ_933MHz] = 933,
#endif
#if defined(CONFIG_TARGET_MODALIX)
	[PHY_DDR_FREQ_3200_8] = 3200,
	[PHY_DDR_FREQ_3200_16] = 3200,
	[PHY_DDR_FREQ_6400_8] = 6400,
	[PHY_DDR_FREQ_6400_16] = 6400,
#endif
};

static ddrc_t ddrc = {
	.sequences = NULL,
	.firmwares = NULL,
	.addrs = { {
			.ddrc_base = DMS0_APB_START_ADDR,
			.phy_base = DMS0_PHY_APB_START_ADDR,
			.resets = {
				RESET_NO_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS0_CK_RST_ADDR, RST_SET0, RST_CLR0),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS0_CK_RST_ADDR, RST_SET1, RST_CLR1, 1),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS0_CK_RST_ADDR, RST_SET2, RST_CLR2, 1),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS0_CK_RST_ADDR, RST_SET3, RST_CLR3, 1),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS0_CK_RST_ADDR, RST_SET4, RST_CLR4, 1),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS0_CK_RST_ADDR, RST_SET5, RST_CLR5, 1),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS0_CK_RST_ADDR, RST_SET6, RST_CLR6, 1),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS0_CK_RST_ADDR, RST_SET7, RST_CLR7, 1),
#if defined(CONFIG_TARGET_DAVINCI)
				RESET_NO_SLEEP(PRC_BASE + PRC_REG__PWR_REG__PWR_REG_1_ADDR, 0x3 << 0, 0x0),
#elif defined(CONFIG_TARGET_MODALIX)
				RESET_NO_SLEEP(PRC_BASE + PRC_REG__PWR_REG__PWR_REG_1_ADDR, 0xf << 0, 0x0),
#endif
			}, }, {
			.ddrc_base = DMS1_APB_START_ADDR,
			.phy_base = DMS1_PHY_APB_START_ADDR,
			.resets = {
				RESET_NO_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS1_CK_RST_ADDR, RST_SET0, RST_CLR0),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS1_CK_RST_ADDR, RST_SET1, RST_CLR1, 1),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS1_CK_RST_ADDR, RST_SET2, RST_CLR2, 1),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS1_CK_RST_ADDR, RST_SET3, RST_CLR3, 1),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS1_CK_RST_ADDR, RST_SET4, RST_CLR4, 1),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS1_CK_RST_ADDR, RST_SET5, RST_CLR5, 1),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS1_CK_RST_ADDR, RST_SET6, RST_CLR6, 1),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS1_CK_RST_ADDR, RST_SET7, RST_CLR7, 1),
#if defined(CONFIG_TARGET_DAVINCI)
				RESET_NO_SLEEP(PRC_BASE + PRC_REG__PWR_REG__PWR_REG_1_ADDR, 0x3 << 6, 0x0),
#elif defined(CONFIG_TARGET_MODALIX)
				RESET_NO_SLEEP(PRC_BASE + PRC_REG__PWR_REG__PWR_REG_2_ADDR, 0xf << 0, 0x0),
#endif
			}, }, {
			.ddrc_base = DMS2_APB_START_ADDR,
			.phy_base = DMS2_PHY_APB_START_ADDR,
			.resets = {
				RESET_NO_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS2_CK_RST_ADDR, RST_SET0, RST_CLR0),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS2_CK_RST_ADDR, RST_SET1, RST_CLR1, 1),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS2_CK_RST_ADDR, RST_SET2, RST_CLR2, 1),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS2_CK_RST_ADDR, RST_SET3, RST_CLR3, 1),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS2_CK_RST_ADDR, RST_SET4, RST_CLR4, 1),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS2_CK_RST_ADDR, RST_SET5, RST_CLR5, 1),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS2_CK_RST_ADDR, RST_SET6, RST_CLR6, 1),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS2_CK_RST_ADDR, RST_SET7, RST_CLR7, 1),
#if defined(CONFIG_TARGET_DAVINCI)
				RESET_NO_SLEEP(PRC_BASE + PRC_REG__PWR_REG__PWR_REG_1_ADDR, 0x3 << 12, 0x0),
#elif defined(CONFIG_TARGET_MODALIX)
				RESET_NO_SLEEP(PRC_BASE + PRC_REG__PWR_REG__PWR_REG_3_ADDR, 0xf << 0, 0x0),
#endif
			}, }, {
			.ddrc_base = DMS3_APB_START_ADDR,
			.phy_base = DMS3_PHY_APB_START_ADDR,
			.resets = {
				RESET_NO_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS3_CK_RST_ADDR, RST_SET0, RST_CLR0),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS3_CK_RST_ADDR, RST_SET1, RST_CLR1, 1),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS3_CK_RST_ADDR, RST_SET2, RST_CLR2, 1),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS3_CK_RST_ADDR, RST_SET3, RST_CLR3, 1),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS3_CK_RST_ADDR, RST_SET4, RST_CLR4, 1),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS3_CK_RST_ADDR, RST_SET5, RST_CLR5, 1),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS3_CK_RST_ADDR, RST_SET6, RST_CLR6, 1),
				RESET_WITH_SLEEP(PRC_BASE + PRC_REG__CKG_RST_REG__DMS3_CK_RST_ADDR, RST_SET7, RST_CLR7, 1),
#if defined(CONFIG_TARGET_DAVINCI)
				RESET_NO_SLEEP(PRC_BASE + PRC_REG__PWR_REG__PWR_REG_1_ADDR, 0x3 << 18, 0x0),
#elif defined(CONFIG_TARGET_MODALIX)
				RESET_NO_SLEEP(PRC_BASE + PRC_REG__PWR_REG__PWR_REG_4_ADDR, 0xf << 0, 0x0),
#endif
			}, },
	},
	.settings = NULL,
};

ddrc_t * get_ddrc(void)
{
	int32_t res = 0;

	res = get_firmware_firmware_ddr(&ddrc.firmwares);
	if(res != PHY_DDR_FIRMWARE_NUM) {
		printf("DDR INIT: Error. Wrong number of firmwares\n");
		return NULL;
	}
	ddrc.settings = get_ddrc_settings();
#if defined(CONFIG_TARGET_DAVINCI)
	res = sequences[ddrc.settings->freq](&ddrc.sequences);
#elif defined(CONFIG_TARGET_MODALIX)
	res = get_sequence_init_ddr_modalix(&ddrc.sequences);
#endif

	if(res < 0) {
		printf("DDR INIT: Error. Wrong number of sequences\n");
		return NULL;
	}

#if (DIAGNOSTIC_TEST == 4) || (DIAGNOSTIC_TEST == 5) || (DIAGNOSTIC_TEST == 6)
	ddrc.sequences[PHY_INIT_DDR_DIAGNOSTIC].elements = &seq_diag_ddr;
	ddrc.sequences[PHY_INIT_DDR_DIAGNOSTIC].size = ARRAY_SIZE(seq_diag_ddr);
#endif
	return &ddrc;
}

unique_sequence_t * get_unique_vals(ddrc_t *ddrc, init_type_t sequence)
{
	if(sequence > PHY_INIT_TYPE_NUM)
		return NULL;

	return &ddrc->sequences[sequence].unique_vals[ddrc->settings->freq];
}

uint32_t freq_to_uint(ddr_freq_t freq)
{
	return freqs[freq];
}

void do_apb_write(uint32_t base, uint32_t regoff, uint32_t data)
{
	*((volatile uint32_t*)((uint64_t)(base + regoff))) = data;
}

void do_apb_read(uint32_t base, uint32_t regoff, uint32_t expdata)
{
	uint32_t data = *((volatile uint32_t*)((uint64_t)(base + regoff)));

	if(data != expdata)
		printf("PHY INIT: Warning! Read [%#x] failed! expected: %#x, actual: %#x\n", regoff, expdata, data);
}

void do_phy_write(uint32_t base, uint32_t regoff, uint16_t data)
{
	uint32_t tmp;
	if((regoff & 0x1) && (regoff >= 0x50000) && (regoff < 0x60000)) {
		tmp = do_phy_read(base, regoff - 1);
		*((ddrphy_reg_t*)((uint64_t)(base + ((regoff - 1) * DDRPHY_REG_SIZE)))) = (ddrphy_reg_t)tmp;
	}
	*((ddrphy_reg_t*)((uint64_t)(base + (regoff * DDRPHY_REG_SIZE)))) = (ddrphy_reg_t)data;
	if((!(regoff & 0x1)) && (regoff >= 0x50000) && (regoff < 0x60000)) {
		tmp = do_phy_read(base, regoff + 1);
		*((ddrphy_reg_t*)((uint64_t)(base + ((regoff + 1) * DDRPHY_REG_SIZE)))) = (ddrphy_reg_t)tmp;
	}
}

void do_phy_writes(uint32_t base, uint32_t regoff, uint16_t data, uint32_t *offsets, uint32_t count)
{
	int i;
	for(i = 0; i < count; i++)
		do_phy_write(base, regoff + offsets[i], data);
}

uint16_t do_phy_read(uint32_t base, uint32_t regoff)
{
	return *((ddrphy_reg_t*)((uint64_t)(base + (regoff * DDRPHY_REG_SIZE))));
}

void do_phy_rmw(uint32_t base, uint32_t regoff, uint16_t val, uint32_t first, uint32_t last)
{
	uint16_t v;
	uint16_t mask = 0;
	uint32_t i;

	for (i = first; i < last; i++)
		mask |= 1 << i;

	v = do_phy_read(base, regoff);
	v &= ~mask;
	v |= (val << first) & mask;
	do_phy_write(base, regoff, v);
}

void do_apb_poll(uint32_t base, uint32_t regoff, uint32_t expdata)
{
	uint32_t data;
	int pollcnt = 2000000;

	do {
		data = *((volatile uint32_t*)((uint64_t)(base + regoff)));
		if(data != expdata)
			udelay(1);
	} while((pollcnt-- > 0) && (data != expdata));
	if(data != expdata)
		printf("PHY INIT: Warning! Poll [%#x] failed! expected: %#x, actual: %#x\n", regoff, expdata, data);
}

void do_phy_poll(uint32_t base, uint32_t regoff, uint16_t expdata)
{
	uint16_t data;
	int pollcnt = 1000000;

	do {
		data = do_phy_read(base, regoff);
		if(data != expdata)
			udelay(1);
	} while((pollcnt-- > 0) && (data != expdata));
	if(data != expdata)
		printf("PHY INIT: Warning! Poll [%#x] failed! expected: %#x, actual: %#x\n", regoff, expdata, data);
}

#if defined(CONFIG_TARGET_DAVINCI)
static uint32_t odtimps[] = { 0x10000, 0x10100, 0x11000, 0x11100, 0x12000, 0x12100, 0x13000, 0x13100 };
static uint32_t atximps[] = { 0x0000, 0x1000, 0x2000, 0x3000, 0x4000, 0x5000 };

void board_specific_ddrc_settings(uint32_t cbase, chip_settings_t *sets)
{
	do_apb_write(cbase, 0x000000dc, (PHY_DDR_MR1(sets) << 16 | PHY_DDR_MR2(sets)));
	do_apb_write(cbase, 0x000000e0, (PHY_DDR_MR3(sets) << 16 | PHY_DDR_MR13(sets)));
	do_apb_write(cbase, 0x000000e8, (PHY_DDR_MR11(sets) << 16 | PHY_DDR_MR12(sets)));

}

void board_specific_ddrphy_settings(uint32_t phybase, chip_settings_t *sets)
{
	do_phy_writes(phybase, 0x4d, sets->txodt, odtimps, ARRAY_SIZE(odtimps));
	do_phy_writes(phybase, 0x49, sets->tximp, odtimps, ARRAY_SIZE(odtimps));
	do_phy_writes(phybase, 0x43, sets->atximp, atximps, ARRAY_SIZE(atximps));
	do_phy_write(phybase, 0x200b2, VREFGLOBAL(sets->phyvref));

}

void board_specific_mr_settings(uint32_t phybase, uint32_t addr, chip_settings_t *sets)
{
	do_phy_write(phybase, addr + 0x6, sets->phyvref);
	do_phy_write(phybase, addr + 0x19, (PHY_DDR_MR2(sets) << 8 | PHY_DDR_MR1(sets)));
	do_phy_write(phybase, addr + 0x1f, (PHY_DDR_MR2(sets) << 8 | PHY_DDR_MR1(sets)));
	do_phy_write(phybase, addr + 0x32, (PHY_DDR_MR1(sets) << 8 | PHY_DDR_MR24(sets)));
	do_phy_write(phybase, addr + 0x38, (PHY_DDR_MR1(sets) << 8 | PHY_DDR_MR24(sets)));
	do_phy_write(phybase, addr + 0x1a, (PHY_DDR_MR4(sets) << 8 | PHY_DDR_MR3(sets)));
	do_phy_write(phybase, addr + 0x20, (PHY_DDR_MR4(sets) << 8 | PHY_DDR_MR3(sets)));
	do_phy_write(phybase, addr + 0x33, (PHY_DDR_MR3(sets) << 8 | PHY_DDR_MR2(sets)));
	do_phy_write(phybase, addr + 0x39, (PHY_DDR_MR3(sets) << 8 | PHY_DDR_MR2(sets)));
	do_phy_write(phybase, addr + 0x1b, (PHY_DDR_MR12(sets) << 8 | PHY_DDR_MR11(sets)));
	do_phy_write(phybase, addr + 0x21, (PHY_DDR_MR12(sets) << 8 | PHY_DDR_MR11(sets)));
	do_phy_write(phybase, addr + 0x34, (PHY_DDR_MR11(sets) << 8 | PHY_DDR_MR4(sets)));
	do_phy_write(phybase, addr + 0x3a, (PHY_DDR_MR11(sets) << 8 | PHY_DDR_MR4(sets)));
	do_phy_write(phybase, addr + 0x35, (PHY_DDR_MR13(sets) << 8 | PHY_DDR_MR12(sets)));
	do_phy_write(phybase, addr + 0x3b, (PHY_DDR_MR13(sets) << 8 | PHY_DDR_MR12(sets)));
	do_phy_write(phybase, addr + 0x1c, (PHY_DDR_MR14(sets) << 8 | PHY_DDR_MR13(sets)));
	do_phy_write(phybase, addr + 0x22, (PHY_DDR_MR14(sets) << 8 | PHY_DDR_MR13(sets)));
	do_phy_write(phybase, addr + 0x36, (PHY_DDR_MR16(sets) << 8 | PHY_DDR_MR14(sets)));
	do_phy_write(phybase, addr + 0x3c, (PHY_DDR_MR16(sets) << 8 | PHY_DDR_MR14(sets)));
}
#endif

#if defined(CONFIG_TARGET_MODALIX)
static uint32_t tximps[] = { 0x000000, 0x001000, 0x100000, 0x101000, };

static void set_mr(uint32_t phybase, uint32_t addr, uint32_t offset, uint32_t size, uint16_t val)
{
	do_phy_rmw(phybase, addr, val, offset, offset + size);
	do_phy_rmw(phybase, addr, val, offset + 8, offset + 8 + size);
	do_phy_rmw(phybase, addr + 1, val, offset, offset + size);
	do_phy_rmw(phybase, addr + 1, val, offset + 8, offset + 8 + size);
}

void board_specific_ddrc_settings(uint32_t cbase, chip_settings_t *sets)
{

}

void board_specific_ddrphy_settings(uint32_t phybase, chip_settings_t *sets)
{
	int i = 0;

	for(i = 0; i < 16; i++)
		do_phy_write(phybase, 0x10080 + (i >> 3) * 0x1000 + (i & 7), sets->dqa_map[i] & 0x7);
	for(i = 0; i < 16; i++)
		do_phy_write(phybase, 0x12080 + (i >> 3) * 0x1000 + (i & 7), sets->dqb_map[i] & 0x7);
	for(i = 0; i < 7; i++)
		do_phy_write(phybase, 0x30090 + i, sets->caa_map[i] & 0x7);
	for(i = 0; i < 7; i++)
		do_phy_write(phybase, 0x31090 + i, sets->cab_map[i] & 0x7);

	do_phy_writes(phybase, 0x30330, sets->atximpcmos, tximps, ARRAY_SIZE(tximps));
	do_phy_writes(phybase, 0x10040, sets->tximpse, tximps, ARRAY_SIZE(tximps));
	do_phy_writes(phybase, 0x10042, sets->tximpdiff, tximps, ARRAY_SIZE(tximps));
	do_phy_writes(phybase, 0x10043, sets->tximpdiff, tximps, ARRAY_SIZE(tximps));
	do_phy_writes(phybase, 0x10044, sets->tximpdiff, tximps, ARRAY_SIZE(tximps));
	do_phy_writes(phybase, 0x10045, sets->tximpdiff, tximps, ARRAY_SIZE(tximps));
	do_phy_writes(phybase, 0x30040, sets->atximpse, tximps, ARRAY_SIZE(tximps));
	do_phy_writes(phybase, 0x30041, sets->atximpse, tximps, ARRAY_SIZE(tximps));
	do_phy_writes(phybase, 0x30042, sets->atximpdiff, tximps, ARRAY_SIZE(tximps));
	do_phy_writes(phybase, 0x30043, sets->atximpdiff, tximps, ARRAY_SIZE(tximps));
	do_phy_writes(phybase, 0x10048, sets->odtimpse, tximps, ARRAY_SIZE(tximps));
	do_phy_writes(phybase, 0x1004A, sets->odtimpdiff, tximps, ARRAY_SIZE(tximps));
	do_phy_writes(phybase, 0x1004B, sets->odtimpdiff, tximps, ARRAY_SIZE(tximps));
	do_phy_writes(phybase, 0x1004C, sets->odtimpdiff, tximps, ARRAY_SIZE(tximps));
	do_phy_writes(phybase, 0x1004D, sets->odtimpdiff, tximps, ARRAY_SIZE(tximps));

}

void board_specific_mr_settings(uint32_t phybase, uint32_t addr, chip_settings_t *sets)
{
	set_mr(phybase, addr + 0x31, 0, 3, (uint16_t)sets->mempdds);
	set_mr(phybase, addr + 0x35, 0, 3, (uint16_t)sets->odtdq);
	set_mr(phybase, addr + 0x35, 4, 3, (uint16_t)sets->memcaodt);
	set_mr(phybase, addr + 0x41, 0, 3, (uint16_t)sets->memdqodt);
	set_mr(phybase, addr + 0x43, 0, 3, (uint16_t)sets->odtwck);
	set_mr(phybase, addr + 0x45, 6, 2, (uint16_t)sets->memcsodt);
	set_mr(phybase, addr + 0x65, 5, 3, (uint16_t)sets->memodtnt);
}
#endif

#ifdef CONFIG_CMD_DDR

static inline uint32_t do_apb_read_nocheck(uint32_t base, uint32_t regoff)
{
	return  *((volatile uint32_t*)((uint64_t)(base + regoff)));
}

static inline void prc_write(uint32_t addr, uint32_t data)
{
	*((volatile uint32_t*)(addr)) = data;
}

static inline uint32_t prc_read(uint32_t addr)
{
	return *((volatile uint32_t*)(addr));
}

#define SIMAAI_DDRVAL2STRING(name, val) {(uint32_t)PHY_DDR_##name##_##val##_OHM, val}
#define SIMAAI_DDRTXIMP(val) SIMAAI_DDRVAL2STRING(TXIMP, val)
#define SIMAAI_DDRTXODT(val) SIMAAI_DDRVAL2STRING(TXODT, val)
#define SIMAAI_DDRATXIMP(val) SIMAAI_DDRVAL2STRING(ATXIMP, val)
#define SIMAAI_DDRMEMIMP(val) SIMAAI_DDRVAL2STRING(MEMIMP, val)
#define SIMAAI_DDRSOCIMP(val) SIMAAI_DDRVAL2STRING(SOCIMP, val)
#define SIMAAI_DDRCMOSIMP(val) SIMAAI_DDRVAL2STRING(CMOSIMP, val)
#define SIMAAI_DDRMEMIMPCS(val) SIMAAI_DDRVAL2STRING(MEMIMPCS, val)
#define SIMAAI_DDRSETTING(name, i) ddrc->settings->chip_settings[i].name
#define SIMAAI_TXIMP2VAL(name, i) simaai_ddr_hex2val(name##vals, sizeof(name##vals), (uint32_t)SIMAAI_DDRSETTING(name, i))
#define SIMAAI_MEMIMP2VAL(name, i) simaai_ddr_hex2val(memimpvals, sizeof(memimpvals), (uint32_t)SIMAAI_DDRSETTING(name, i))
#define SIMAAI_SOCIMP2VAL(name, i) simaai_ddr_hex2val(socimpvals, sizeof(socimpvals), (uint32_t)SIMAAI_DDRSETTING(name, i))
#define SIMAAI_SMOSIMP2VAL(name, i) simaai_ddr_hex2val(cmosimpvals, sizeof(cmosimpvals), (uint32_t)SIMAAI_DDRSETTING(name, i))
#define SIMAAI_MEMIMPCS2VAL(name, i) simaai_ddr_hex2val(memimpcsvals, sizeof(memimpcsvals), (uint32_t)SIMAAI_DDRSETTING(name, i))
#define SIMAAI_VAL2HEX(name, val) simaai_ddr_val2hex(name, sizeof(name), val)

#define CHECK_AND_SET_VAL(type, field, vals) \
	new_hex = SIMAAI_VAL2HEX(vals, val); \
	if (new_hex == 0xffffffff) { \
		printf("Wrong value of #field: %u\n", val); \
		return -1; \
	} \
	SIMAAI_DDRSETTING(field, index) = (type)new_hex

static const uint32_t tximpvals[][2] = {
	SIMAAI_DDRTXIMP(480),
	SIMAAI_DDRTXIMP(240),
	SIMAAI_DDRTXIMP(160),
	SIMAAI_DDRTXIMP(120),
	SIMAAI_DDRTXIMP(96),
	SIMAAI_DDRTXIMP(80),
	SIMAAI_DDRTXIMP(69),
	SIMAAI_DDRTXIMP(60),
	SIMAAI_DDRTXIMP(53),
	SIMAAI_DDRTXIMP(48),
	SIMAAI_DDRTXIMP(44),
	SIMAAI_DDRTXIMP(40),
	SIMAAI_DDRTXIMP(37),
	SIMAAI_DDRTXIMP(34),
	SIMAAI_DDRTXIMP(32),
	SIMAAI_DDRTXIMP(30),
	SIMAAI_DDRTXIMP(28),
};

static const uint32_t txodtvals[][2] = {
	SIMAAI_DDRTXODT(480),
	SIMAAI_DDRTXODT(240),
	SIMAAI_DDRTXODT(160),
	SIMAAI_DDRTXODT(120),
	SIMAAI_DDRTXODT(96),
	SIMAAI_DDRTXODT(80),
	SIMAAI_DDRTXODT(69),
	SIMAAI_DDRTXODT(60),
	SIMAAI_DDRTXODT(53),
	SIMAAI_DDRTXODT(48),
	SIMAAI_DDRTXODT(44),
	SIMAAI_DDRTXODT(40),
	SIMAAI_DDRTXODT(37),
	SIMAAI_DDRTXODT(34),
	SIMAAI_DDRTXODT(32),
	SIMAAI_DDRTXODT(30),
	SIMAAI_DDRTXODT(28),
};

static const uint32_t atximpvals[][2] = {
	SIMAAI_DDRATXIMP(120),
	SIMAAI_DDRATXIMP(60),
	SIMAAI_DDRATXIMP(40),
	SIMAAI_DDRATXIMP(30),
	SIMAAI_DDRATXIMP(24),
	SIMAAI_DDRATXIMP(20),
};

static const uint32_t memimpvals[][2] = {
	SIMAAI_DDRMEMIMP(240),
	SIMAAI_DDRMEMIMP(120),
	SIMAAI_DDRMEMIMP(80),
	SIMAAI_DDRMEMIMP(60),
	SIMAAI_DDRMEMIMP(48),
	SIMAAI_DDRMEMIMP(40),
};

static const uint32_t socimpvals[][2] = {
	{(uint32_t)PHY_DDR_SOCIMP_HIGHIMP, 0},
	SIMAAI_DDRSOCIMP(120),
	SIMAAI_DDRSOCIMP(60),
	SIMAAI_DDRSOCIMP(40),
	SIMAAI_DDRSOCIMP(30),
};

static const uint32_t cmosimpvals[][2] = {
	SIMAAI_DDRCMOSIMP(400),
	SIMAAI_DDRCMOSIMP(100),
	SIMAAI_DDRCMOSIMP(66),
	SIMAAI_DDRCMOSIMP(50),
};

static const uint32_t memimpcsvals[][2] = {
	SIMAAI_DDRMEMIMPCS(80),
	SIMAAI_DDRMEMIMPCS(120),
	SIMAAI_DDRMEMIMPCS(240),
};

static uint32_t simaai_ddr_hex2val(const uint32_t vals[][2], uint32_t size, uint32_t hex)
{
	int i = 0;

	for(i = 0; i < size; i++)
		if(vals[i][0] == hex)
			return vals[i][1];
	return 0;
}

static uint32_t simaai_ddr_val2hex(const uint32_t vals[][2], uint32_t size, uint32_t val)
{
	int i = 0;

	for(i = 0; i < size; i++)
		if(vals[i][1] == val)
			return vals[i][0];
	return 0xffffffff;
}

int32_t sima_ddr_get_creg(uint32_t mask, uint32_t addr)
{
	int32_t i;
	ddrc_t *ddrc = get_ddrc();

	for(i = 0; i < PHY_DDR_MAX_CONTROLLERS; i++) {
		if((1 << i) & mask)
			printf("DDRC[%d] Register[0x%04x] = 0x%08x\n", i, addr,
					do_apb_read_nocheck(ddrc->addrs[i].ddrc_base, addr));
	}

	return 0;
}

int32_t sima_ddr_set_creg(uint32_t mask, uint32_t addr, uint32_t value)
{
	int32_t i;
	ddrc_t *ddrc = get_ddrc();

	for(i = 0; i < PHY_DDR_MAX_CONTROLLERS; i++) {
		if((1 << i) & mask) {
			printf("DDRC[%d] Old value register[0x%04x] = 0x%08x\n", i, addr,
					do_apb_read_nocheck(ddrc->addrs[i].ddrc_base, addr));
			do_apb_write(ddrc->addrs[i].ddrc_base, addr, value);
			printf("DDRC[%d] New value register[0x%04x] = 0x%08x\n", i, addr,
					do_apb_read_nocheck(ddrc->addrs[i].ddrc_base, addr));
		}
	}

	return 0;
}

int32_t sima_ddr_get_phyreg(uint32_t mask, uint32_t addr)
{
	int32_t i;
	uint32_t val;
	ddrc_t *ddrc = get_ddrc();

	for(i = 0; i < PHY_DDR_MAX_CONTROLLERS; i++) {
		if((1 << i) & mask) {
			val = (uint32_t)do_phy_read(ddrc->addrs[i].phy_base, addr);
			printf("DDRPHY[%d] Register[0x%04x] = 0x%04x\n", i, addr, val);
		}
	}

	return 0;
}

int32_t sima_ddr_set_phyreg(uint32_t mask, uint32_t addr, uint16_t value)
{
	int32_t i;
	uint32_t val;
	ddrc_t *ddrc = get_ddrc();

	for(i = 0; i < PHY_DDR_MAX_CONTROLLERS; i++) {
		if((1 << i) & mask) {
			val = (uint32_t)do_phy_read(ddrc->addrs[i].phy_base, addr);
			printf("DDRPHY[%d] Old value register[0x%04x] = 0x%04x\n", i, addr, val);
			do_phy_write(ddrc->addrs[i].phy_base, addr, value);
			val = (uint32_t)do_phy_read(ddrc->addrs[i].phy_base, addr);
			printf("DDRPHY[%d] New value register[0x%04x] = 0x%04x\n", i, addr, val);
		}
	}

	return 0;
}

void sima_ddr_reset(void)
{
	int32_t i, j;
	uint32_t val;
	ddrc_rst_t *rst;
	ddrc_t *ddrc = get_ddrc();

	for(i = 0; i < PHY_DDR_MAX_CONTROLLERS; i++)
		for(j = PHY_DDR_MAX_RESETS - 1; j >= 0; j--) {
			rst = &ddrc->addrs[i].resets[j];
			val = prc_read(rst->addr);
			if(rst->set_bits || rst->clr_bits) {
				val |= rst->clr_bits;
				val &= ~rst->set_bits;
				prc_write(rst->addr, val);
			}
			if(rst->delay_us)
				udelay(rst->delay_us);
		}
}

int32_t sima_ddr_dump_supported_values(void)
{
	int32_t i;
	printf("DDR INIT: Set of supported values:\n");
	printf("\t\ttximp: ");
	for(i = 0; i < ARRAY_SIZE(tximpvals); i++)
		printf("%u, ", tximpvals[i][1]);
	printf("\n");
	printf("\t\tatximp: ");
	for(i = 0; i < ARRAY_SIZE(atximpvals); i++)
		printf("%u, ", atximpvals[i][1]);
	printf("\n");
	printf("\t\ttxodt: ");
	for(i = 0; i < ARRAY_SIZE(txodtvals); i++)
		printf("%u, ", txodtvals[i][1]);
	printf("\n");
	printf("\t\tmempdds, memcaodt, memdqodt, odtdq, odtwck, memodtnt: ");
	for(i = 0; i < ARRAY_SIZE(memimpvals); i++)
		printf("%u, ", memimpvals[i][1]);
	printf("\n");
	printf("\t\ttximpse, tximpdiff, atximpse, atximpdiff, odtimpse, odtimpdiff: ");
	for(i = 0; i < ARRAY_SIZE(socimpvals); i++)
		printf("%u, ", socimpvals[i][1]);
	printf("\n");
	printf("\t\tatximpcmos: ");
	for(i = 0; i < ARRAY_SIZE(cmosimpvals); i++)
		printf("%u, ", cmosimpvals[i][1]);
	printf("\n");
	printf("\t\tmemcsodt: ");
	for(i = 0; i < ARRAY_SIZE(memimpcsvals); i++)
		printf("%u, ", memimpcsvals[i][1]);
	printf("\n");
	printf("\t\tmemcavref, memdqvref, phyvref: Any DECIMAL	 value\n");

	return 0;
}

int32_t sima_ddr_dump_settings(void)
{
	int32_t i, j;
	ddrc_t *ddrc = get_ddrc();

	for(i = 0; i < PHY_DDR_MAX_CONTROLLERS; i++) {
		if(!(ddrc->settings->ddrc_mask & (1 << i)))
			continue;
		printf("DDR INIT: Dumpig settings of controller %d\n", i);
		printf("DDR INIT: tximp: %u Ohms, atximp: %u Ohms, txodt: %u Ohms\n",
			SIMAAI_TXIMP2VAL(tximp, i),SIMAAI_TXIMP2VAL(atximp, i), SIMAAI_TXIMP2VAL(txodt, i));
		printf("DDR INIT: mempdds: %u Ohms, memcaodt: %u Ohms, memdqodt: %u Ohms\n",
			SIMAAI_MEMIMP2VAL(mempdds, i),SIMAAI_MEMIMP2VAL(memcaodt, i), SIMAAI_MEMIMP2VAL(memdqodt, i));
		printf("DDR INIT: memcavref: %d , memdqvref: %d , phyvref: %d \n",
			(int32_t)SIMAAI_DDRSETTING(memcavref, i),(int32_t)SIMAAI_DDRSETTING(memdqvref, i), (int32_t)SIMAAI_DDRSETTING(phyvref, i));
		printf("DDR INIT: tximpse: %u Ohms, tximpdiff: %u Ohms, atximpse: %u Ohms\n",
			SIMAAI_SOCIMP2VAL(tximpse, i),SIMAAI_SOCIMP2VAL(tximpdiff, i), SIMAAI_SOCIMP2VAL(atximpse, i));
		printf("DDR INIT: atximpdiff: %u Ohms, atximpcmos: %u Ohms, odtimpse: %u Ohms\n",
			SIMAAI_SOCIMP2VAL(atximpdiff, i),SIMAAI_SMOSIMP2VAL(atximpcmos, i), SIMAAI_SOCIMP2VAL(odtimpse, i));
		printf("DDR INIT: odtimpdiff: %u Ohms, odtdq: %u Ohms, odtwck: %u Ohms\n",
			SIMAAI_SOCIMP2VAL(odtimpdiff, i),SIMAAI_MEMIMP2VAL(odtdq, i), SIMAAI_MEMIMP2VAL(odtwck, i));
		printf("DDR INIT: memcsodt: %u Ohms, memodtnt: %u Ohms,\n",
			SIMAAI_MEMIMPCS2VAL(memcsodt, i),SIMAAI_MEMIMP2VAL(memodtnt, i));
		printf("DDR INIT: DQA mapping: ");
		for(j = 0; j < ARRAY_SIZE(SIMAAI_DDRSETTING(dqa_map, i)); j++)
			printf("%d, ", SIMAAI_DDRSETTING(dqa_map[j], i));
		printf("\nDDR INIT: DQB mapping: ");
		for(j = 0; j < ARRAY_SIZE(SIMAAI_DDRSETTING(dqb_map, i)); j++)
			printf("%d, ", SIMAAI_DDRSETTING(dqb_map[j], i));
		printf("\nDDR INIT: CAA mapping: ");
		for(j = 0; j < ARRAY_SIZE(SIMAAI_DDRSETTING(caa_map, i)); j++)
			printf("%d, ", SIMAAI_DDRSETTING(caa_map[j], i));
		printf("\nDDR INIT: CAB mapping: ");
		for(j = 0; j < ARRAY_SIZE(SIMAAI_DDRSETTING(cab_map, i)); j++)
			printf("%d, ", SIMAAI_DDRSETTING(cab_map[j], i));
		printf("\n");
	}

	return 0;
}

int32_t sima_ddr_set_settings(uint32_t index, uint32_t setting, uint32_t val)
{
	uint32_t new_hex;
	ddrc_t *ddrc = get_ddrc();

	switch(setting) {
		case 0:
			CHECK_AND_SET_VAL(ddr_tximp_t, tximp, tximpvals);
			break;
		case 1:
			CHECK_AND_SET_VAL(ddr_atximp_t, atximp, atximpvals);
			break;
		case 2:
			CHECK_AND_SET_VAL(ddr_txodt_t, txodt, txodtvals);
			break;
		case 3:
			CHECK_AND_SET_VAL(ddr_memimp_t, mempdds, memimpvals);
			break;
		case 4:
			CHECK_AND_SET_VAL(ddr_memimp_t, memcaodt, memimpvals);
			break;
		case 5:
			CHECK_AND_SET_VAL(ddr_memimp_t, memdqodt, memimpvals);
			break;
		case 6:
			SIMAAI_DDRSETTING(memcavref, index) = (uint8_t)val;
			break;
		case 7:
			SIMAAI_DDRSETTING(memdqvref, index) = (uint8_t)val;
			break;
		case 8:
			SIMAAI_DDRSETTING(phyvref, index) = val;
			break;
		case 9:
			CHECK_AND_SET_VAL(ddr5_socimp_t, tximpse, socimpvals);
			break;
		case 10:
			CHECK_AND_SET_VAL(ddr5_socimp_t, tximpdiff, socimpvals);
			break;
		case 11:
			CHECK_AND_SET_VAL(ddr5_socimp_t, atximpse, socimpvals);
			break;
		case 12:
			CHECK_AND_SET_VAL(ddr5_socimp_t, atximpdiff, socimpvals);
			break;
		case 13:
			CHECK_AND_SET_VAL(ddr5_cmosimp_t, atximpcmos, cmosimpvals);
			break;
		case 14:
			CHECK_AND_SET_VAL(ddr5_socimp_t, odtimpse, socimpvals);
			break;
		case 15:
			CHECK_AND_SET_VAL(ddr5_socimp_t, odtimpdiff, socimpvals);
			break;
		case 16:
			CHECK_AND_SET_VAL(ddr_memimp_t, odtdq, memimpvals);
			break;
		case 17:
			CHECK_AND_SET_VAL(ddr_memimp_t, odtwck, memimpvals);
			break;
		case 18:
			CHECK_AND_SET_VAL(ddr_memimpcs_t, memcsodt, memimpcsvals);
			break;
		case 19:
			CHECK_AND_SET_VAL(ddr_memimp_t, memodtnt, socimpvals);
			break;
		default:
			printf("Unknown setting: %u\n", setting);
			return -1;
	}

	return 0;
}

#endif
