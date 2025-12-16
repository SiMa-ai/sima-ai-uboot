//SPDX-License-Identifier: (GPL-2.0+ OR MIT)
/*
 * Copyright (c) 2024 Sima ai
 * Generated 09/09/2025 23:26:13 by nileshr
 */

#include <asm/arch/init_ddr_modalix_1r.h>
#include <linux/kernel.h>

static init_element_t seq1_init_ddr_modalix_1r[] = {
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010b84, .value=0x1 }, // OPCTRL1
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00010000, .value=0x3080008 }, // MSTR0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010010, .value=0x101 }, // MSTR4
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010100, .value=0x18 }, // DERATECTL0
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00010104, .value=0x3 }, // DERATECTL1
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00010108, .value=0x3 }, // DERATECTL2
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010114, .value=0x0 }, // DERATECTL5
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010118, .value=0x1 }, // DERATECTL6
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010180, .value=0x211 }, // PWRCTL
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010184, .value=0x0 }, // HWLPCTL
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0001018c, .value=0x0 }, // CLKGATECTL
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010200, .value=0x14a }, // RFSHMOD0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010220, .value=0x1F090E01 }, // RFMMOD0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010224, .value=0x0 }, // RFMMOD1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010c94, .value=0x1 }, // DBICTL
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010280, .value=0x80000000 }, // ZQCTL0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010288, .value=0x00000001 }, // ZQCTL2
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010300, .value=0x400040 }, // DQSOSCRUNTIME
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010308, .value=0x1 }, // DQSOSCCFG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010380, .value=0x80013d15 }, // SCHED0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010384, .value=0xA2223000 }, // SCHED1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0001038C, .value=0x08080208 }, // SCHED3
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010390, .value=0x083c0810 }, // SCHED4
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010394, .value=0x0000041e }, // SCHED5
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010500, .value=0x00000000 }, // DFILPCFG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010508, .value=0xe0008000 }, // DFIUPD0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010510, .value=0x5 }, // DFIMISC
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010518, .value=0x30000001 }, // DFIPHYMSTR
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010600, .value=0x02bf7f04 }, // ECCCFG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010604, .value=0x00001fb2 }, // ECCCFG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010648, .value=0x0 }, // ECCPOISONADDR0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0001064c, .value=0x0 }, // ECCPOISONADDR1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010658, .value=0x0 }, // ECCPOISONPAT0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010660, .value=0x0 }, // ECCPOISONPAT2
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010980, .value=0x0 }, // LNKECCCTL0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010b80, .value=0x0 }, // OPCTRL0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010d00, .value=0x40030003 }, // INITTMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010d04, .value=0x00760000 }, // INITTMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00020000, .value=0x0 }, // PCCFG
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00020004, .value=0x00004000 }, // PCFGR
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00020008, .value=0x00006000 }, // PCFGW
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00020094, .value=0x01110804 }, // PCFGQOS0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00020098, .value=0x0222010e }, // PCFGQOS1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0002009c, .value=0x01010502 }, // PCFGWQOS0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x000200a0, .value=0x0019068c }, // PCFGWQOS1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x000200e0, .value=0x0 }, // SBRCTL
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x000200f0, .value=0x3fbc0623 }, // SBRSTART0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x000200f8, .value=0x4ac75c82 }, // SBRRANGE0
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000000, .value=0x19080e11 }, // DRAMSET1TMG0
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000004, .value=0x8051a }, // DRAMSET1TMG1
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000008, .value=0x50a0e12 }, // DRAMSET1TMG2
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x0000000c, .value=0x9151a }, // DRAMSET1TMG3
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000010, .value=0x8020208 }, // DRAMSET1TMG4
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000014, .value=0x2030605 }, // DRAMSET1TMG5
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000018, .value=0x5 }, // DRAMSET1TMG6
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x0000001c, .value=0x2 }, // DRAMSET1TMG7
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000024, .value=0x4020d }, // DRAMSET1TMG9
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000030, .value=0x00030000 }, // DRAMSET1TMG12
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000034, .value=0x8080002 }, // DRAMSET1TMG13
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000038, .value=0x100073 }, // DRAMSET1TMG14
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x0000005c, .value=0x9d0009 }, // DRAMSET1TMG23
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000060, .value=0x20a0e09 }, // DRAMSET1TMG24
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000064, .value=0x1703 }, // DRAMSET1TMG25
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000078, .value=0xf0d0f }, // DRAMSET1TMG30
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000580, .value=0x723020f }, // DFITMG0
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000584, .value=0x60706 }, // DFITMG1
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000588, .value=0x24230f }, // DFITMG2
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000590, .value=0x0c040003 }, // DFITMG4
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000594, .value=0x4080007 }, // DFITMG5
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x000005a0, .value=0x00020202 }, // DFILPTMG0
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x000005a4, .value=0x00000201 }, // DFILPTMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x000005a8, .value=0x00280002  }, // DFIUPDTMG0
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x000005ac, .value=0x008300e9 }, // DFIUPDTMG1
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000600, .value=0x82120073 }, // RFSHSET1TMG0
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000604, .value=0x730073 }, // RFSHSET1TMG1
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000608, .value=0x3180000 }, // RFSHSET1TMG2
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0000060c, .value=0x10000000 }, // RFSHSET1TMG3
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000650, .value=0x44 }, // RFMSET1TMG0
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000800, .value=0xc04b0 }, // ZQSET1TMG0
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000804, .value=0x140000a }, // ZQSET1TMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000a80, .value=0x3c44 }, // DQSOSCCTL0
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000b00, .value=0xbd3062ae }, // DERATEINT
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000b04, .value=0x8120805 }, // DERATEVAL0
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000b08, .value=0x0000001a }, // DERATEVAL1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000b80, .value=0x0 }, // HWLPTMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000c00, .value=0x6 }, // SCHEDTMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000d00, .value=0x1 }, // TMGCFG
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000d04, .value=0xe12 }, // RANKTMG0
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00000d08, .value=0xe12 }, // RANKTMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000d0c, .value=0x009a0076 }, // PWRTMG
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00030004, .value=0x00000016  }, // ADDRMAP1
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x0003000c, .value=0x003f0404  }, // ADDRMAP3
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00030010, .value=0x00000606  }, // ADDRMAP4
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00030014, .value=0x1f161616  }, // ADDRMAP5
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00030018, .value=0x00000000  }, // ADDRMAP6
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x0003001c, .value=0x1f050505  }, // ADDRMAP7
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00030020, .value=0x05050505  }, // ADDRMAP8
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00030024, .value=0x05050505  }, // ADDRMAP9
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00030028, .value=0x05050505  }, // ADDRMAP10
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x0003002c, .value=0x00000505  }, // ADDRMAP11
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x00030030, .value=0x00000000 }, // ADDRMAP12
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010b84, .value=0x0 }, // OPCTRL1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00020090, .value=0x0 }, // PCTRL
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010208, .value=0x1 }, // RFSHCTL0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010b84, .value=0x1 }, // OPCTRL1
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01010000, .value=0x3080008  }, // MSTR0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010010, .value=0x101 }, // MSTR4
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010100, .value=0x18 }, // DERATECTL0
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01010104, .value=0x3 }, // DERATECTL1
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01010108, .value=0x3 }, // DERATECTL2
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010114, .value=0x0 }, // DERATECTL5
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010118, .value=0x1 }, // DERATECTL6
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010180, .value=0x211 }, // PWRCTL
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010184, .value=0x0 }, // HWLPCTL
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0101018c, .value=0x0 }, // CLKGATECTL
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010200, .value=0x14a }, // RFSHMOD0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010220, .value=0x1F090E01  }, // RFMMOD0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010224, .value=0x0 }, // RFMMOD1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010c94, .value=0x1 }, // DBICTL
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010280, .value=0x80000000 }, // ZQCTL0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010288, .value=0x00000001 }, // ZQCTL2
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010300, .value=0x400040 }, // DQSOSCRUNTIME
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010308, .value=0x1 }, // DQSOSCCFG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010380, .value=0x80013d15 }, // SCHED0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010384, .value=0xa2223000 }, // SCHED1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0101038c, .value=0x08080208 }, // SCHED3
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010390, .value=0x083c0810 }, // SCHED4
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010394, .value=0x0000041e }, // SCHED5
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010500, .value=0x00000000 }, // DFILPCFG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010508, .value=0xe0008000 }, // DFIUPD0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010510, .value=0x5 }, // DFIMISC
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010518, .value=0x30000001 }, // DFIPHYMSTR
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010600, .value=0x02bf7f04 }, // ECCCFG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010604, .value=0x00001fb2 }, // ECCCFG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010648, .value=0x0 }, // ECCPOISONADDR0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0101064c, .value=0x0 }, // ECCPOISONADDR1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010658, .value=0x0 }, // ECCPOISONPAT0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010660, .value=0x0 }, // ECCPOISONPAT2
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010980, .value=0x0 }, // LNKECCCTL0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010b80, .value=0x0 }, // OPCTRL0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010d00, .value=0x40030003 }, // INITTMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010d04, .value=0x00760000 }, // INITTMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01020000, .value=0x0 }, // PCCFG
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01020004, .value=0x00004000 }, // PCFGR
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01020008, .value=0x00006000 }, // PCFGW
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01020094, .value=0x01110804 }, // PCFGQOS0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01020098, .value=0x0222010e }, // PCFGQOS1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0102009c, .value=0x01010502 }, // PCFGWQOS0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x010200a0, .value=0x0019068c }, // PCFGWQOS1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x010200e0, .value=0x0 }, // SBRCTL
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x010200f0, .value=0x3fbc0623 }, // SBRSTART0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x010200f8, .value=0x4ac75c82 }, // SBRRANGE0
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000000, .value=0x19080e11 }, // DRAMSET1TMG0
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000004, .value=0x8051a }, // DRAMSET1TMG1
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000008, .value=0x50a0e12 }, // DRAMSET1TMG2
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x0100000c, .value=0x9151a }, // DRAMSET1TMG3
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000010, .value=0x8020208 }, // DRAMSET1TMG4
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000014, .value=0x2030605 }, // DRAMSET1TMG5
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000018, .value=0x5 }, // DRAMSET1TMG6
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x0100001c, .value=0x2 }, // DRAMSET1TMG7
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000024, .value=0x4020d }, // DRAMSET1TMG9
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000030, .value=0x00030000 }, // DRAMSET1TMG12
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000034, .value=0x8080002 }, // DRAMSET1TMG13
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000038, .value=0x100073 }, // DRAMSET1TMG14
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x0100005c, .value=0x9d0009 }, // DRAMSET1TMG23
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000060, .value=0x20a0e09 }, // DRAMSET1TMG24
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000064, .value=0x1703 }, // DRAMSET1TMG25
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000078, .value=0xf0d0f }, // DRAMSET1TMG30
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000580, .value=0x723020f }, // DFITMG0
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000584, .value=0x60706 }, // DFITMG1
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000588, .value=0x24230f }, // DFITMG2
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000590, .value=0x0c040003 }, // DFITMG4
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000594, .value=0x4080007 }, // DFITMG5
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x010005a0, .value=0x00020202 }, // DFILPTMG0
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x010005a4, .value=0x00000201 }, // DFILPTMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x010005a8, .value=0x00280002  }, // DFIUPDTMG0
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x010005ac, .value=0x008300e9 }, // DFIUPDTMG1
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000600, .value=0x82120073 }, // RFSHSET1TMG0
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000604, .value=0x730073 }, // RFSHSET1TMG1
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000608, .value=0x3180000 }, // RFSHSET1TMG2
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0100060c, .value=0x10000000 }, // RFSHSET1TMG3
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000650, .value=0x44 }, // RFMSET1TMG0
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000800, .value=0xc04b0 }, // ZQSET1TMG0
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000804, .value=0x140000a }, // ZQSET1TMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000a80, .value=0x3c44 }, // DQSOSCCTL0
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000b00, .value=0xbd3062ae }, // DERATEINT
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000b04, .value=0x8120805 }, // DERATEVAL0
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000b08, .value=0x0000001a }, // DERATEVAL1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000b80, .value=0x0 }, // HWLPTMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000c00, .value=0x6 }, // SCHEDTMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000d00, .value=0x1 }, // TMGCFG
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000d04, .value=0xe12 }, // RANKTMG0
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01000d08, .value=0xe12 }, // RANKTMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000d0c, .value=0x009a0076 }, // PWRTMG
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01030004, .value=0x00000016  }, // ADDRMAP1
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x0103000c, .value=0x003f0404  }, // ADDRMAP3
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01030010, .value=0x00000606  }, // ADDRMAP4
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01030014, .value=0x1f161616  }, // ADDRMAP5
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01030018, .value=0x00000000  }, // ADDRMAP6
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x0103001c, .value=0x1f050505  }, // ADDRMAP7
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01030020, .value=0x05050505  }, // ADDRMAP8
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01030024, .value=0x05050505  }, // ADDRMAP9
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01030028, .value=0x05050505  }, // ADDRMAP10
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x0103002c, .value=0x00000505  }, // ADDRMAP11
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x01030030, .value=0x00000000 }, // ADDRMAP12
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010b84, .value=0x0 }, // OPCTRL1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01020090, .value=0x0 }, // PCTRL
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010208, .value=0x1 }, // RFSHCTL0
};

static init_element_t seq1_init_ddr_modalix_1r_PHY_DDR_FREQ_6400_16[] = {
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010000, .value=0x1080008 }, // MSTR0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010104, .value=0x1 }, // DERATECTL1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010108, .value=0x1 }, // DERATECTL2
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000000, .value=0x2A101B22 }, // DRAMSET1TMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000004, .value=0x100630 }, // DRAMSET1TMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000008, .value=0x9111317 }, // DRAMSET1TMG2
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0000000c, .value=0xC212F }, // DRAMSET1TMG3
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000010, .value=0xf04040f }, // DRAMSET1TMG4
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000014, .value=0x02040C09 }, // DRAMSET1TMG5
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000018, .value=0x8 }, // DRAMSET1TMG6
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0000001c, .value=0x3 }, // DRAMSET1TMG7
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000024, .value=0x20410 }, // DRAMSET1TMG9
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000034, .value=0xc100002 }, // DRAMSET1TMG13
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000038, .value=0x2000E6 }, // DRAMSET1TMG14
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0000005c, .value=0x009D0009 }, // DRAMSET1TMG23
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000060, .value=0x10160E }, // DRAMSET1TMG24
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000064, .value=0x2806 }, // DRAMSET1TMG25
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000078, .value=0x191418 }, // DRAMSET1TMG30
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000580, .value=0x53f021f }, // DFITMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000584, .value=0xB0505 }, // DFITMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000588, .value=0x213f1f }, // DFITMG2
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000590, .value=0x180C0411 }, // DFITMG4
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000594, .value=0x0410000D  }, // DFITMG5
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x000005a0, .value=0x00100A0C }, // DFILPTMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x000005a4, .value=0x310 }, // DFILPTMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x000005ac, .value=0x280050 }, // DFIUPDTMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000600, .value=0x0201000c }, // RFSHSET1TMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000604, .value=0x00E00070 }, // RFSHSET1TMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000608, .value=0x06480000 }, // RFSHSET1TMG2
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000650, .value=0x88 }, // RFMSET1TMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000800, .value=0x18096a }, // ZQSET1TMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000804, .value=0x28061a8 }, // ZQSET1TMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000b00, .value=0x00F42400 }, // DERATEINT
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000b04, .value=0x10241004 }, // DERATEVAL0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000b08, .value=0x00000033 }, // DERATEVAL1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000d08, .value=0x1c12 }, // RANKTMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00030004, .value=0x0000003F }, // ADDRMAP1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0003000c, .value=0x003f0606 }, // ADDRMAP3
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00030010, .value=0x00000404  }, // ADDRMAP4
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00030014, .value=0x1F141414 }, // ADDRMAP5
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00030018, .value=0x00000000  }, // ADDRMAP6
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0003001c, .value=0x1F1F0505 }, // ADDRMAP7
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00030020, .value=0x05050505  }, // ADDRMAP8
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00030024, .value=0x05050505  }, // ADDRMAP9
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00030028, .value=0x05050505  }, // ADDRMAP10
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0003002c, .value=0x00000505  }, // ADDRMAP11
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00030030, .value=0x00000000 }, // ADDRMAP12
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010000, .value=0x1080008  }, // MSTR0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010104, .value=0x1 }, // DERATECTL1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010108, .value=0x1 }, // DERATECTL2
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000000, .value=0x2A101B22 }, // DRAMSET1TMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000004, .value=0x100630 }, // DRAMSET1TMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000008, .value=0x9111317 }, // DRAMSET1TMG2
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0100000c, .value=0xC212F }, // DRAMSET1TMG3
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000010, .value=0xf04040f }, // DRAMSET1TMG4
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000014, .value=0x02040C09 }, // DRAMSET1TMG5
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000018, .value=0x8 }, // DRAMSET1TMG6
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0100001c, .value=0x3 }, // DRAMSET1TMG7
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000024, .value=0x20410 }, // DRAMSET1TMG9
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000034, .value=0xc100002 }, // DRAMSET1TMG13
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000038, .value=0x2000E6 }, // DRAMSET1TMG14
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0100005c, .value=0x009D0009 }, // DRAMSET1TMG23
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000060, .value=0x10160E }, // DRAMSET1TMG24
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000064, .value=0x2806 }, // DRAMSET1TMG25
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000078, .value=0x191418 }, // DRAMSET1TMG30
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000580, .value=0x53f021f }, // DFITMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000584, .value=0xB0505 }, // DFITMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000588, .value=0x213f1f }, // DFITMG2
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000590, .value=0x180C0411 }, // DFITMG4
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000594, .value=0x0410000D  }, // DFITMG5
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x010005a0, .value=0x00100A0C }, // DFILPTMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x010005a4, .value=0x310 }, // DFILPTMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x010005ac, .value=0x280050 }, // DFIUPDTMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000600, .value=0x0201000c }, // RFSHSET1TMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000604, .value=0x00E00070 }, // RFSHSET1TMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000608, .value=0x06480000 }, // RFSHSET1TMG2
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000650, .value=0x88 }, // RFMSET1TMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000800, .value=0x18096a }, // ZQSET1TMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000804, .value=0x28061a8 }, // ZQSET1TMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000b00, .value=0x00F42400 }, // DERATEINT
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000b04, .value=0x10241004 }, // DERATEVAL0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000b08, .value=0x00000033 }, // DERATEVAL1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000d08, .value=0x1c12 }, // RANKTMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01030004, .value=0x0000003F }, // ADDRMAP1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0103000c, .value=0x003f0606 }, // ADDRMAP3
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01030010, .value=0x00000404  }, // ADDRMAP4
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01030014, .value=0x1F141414 }, // ADDRMAP5
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01030018, .value=0x00000000  }, // ADDRMAP6
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0103001c, .value=0x1F1F0505 }, // ADDRMAP7
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01030020, .value=0x05050505  }, // ADDRMAP8
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01030024, .value=0x05050505  }, // ADDRMAP9
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01030028, .value=0x05050505  }, // ADDRMAP10
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0103002c, .value=0x00000505  }, // ADDRMAP11
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01030030, .value=0x00000000 }, // ADDRMAP12
};

static init_element_t seq1_init_ddr_modalix_1r_PHY_DDR_FREQ_6400_16_2GB[] = {
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010000, .value=0x1080008 }, // MSTR0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010104, .value=0x1 }, // DERATECTL1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010108, .value=0x1 }, // DERATECTL2
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000000, .value=0x2A101B22 }, // DRAMSET1TMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000004, .value=0x100630 }, // DRAMSET1TMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000008, .value=0x9111317 }, // DRAMSET1TMG2
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0000000c, .value=0xC212F }, // DRAMSET1TMG3
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000010, .value=0xf04040f }, // DRAMSET1TMG4
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000014, .value=0x02040C09 }, // DRAMSET1TMG5
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000018, .value=0x8 }, // DRAMSET1TMG6
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0000001c, .value=0x3 }, // DRAMSET1TMG7
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000024, .value=0x20410 }, // DRAMSET1TMG9
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000034, .value=0xc100002 }, // DRAMSET1TMG13
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000038, .value=0x2000AE }, // DRAMSET1TMG14
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0000005c, .value=0x009D0009 }, // DRAMSET1TMG23
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000060, .value=0x10160E }, // DRAMSET1TMG24
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000064, .value=0x2806 }, // DRAMSET1TMG25
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000078, .value=0x191418 }, // DRAMSET1TMG30
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000580, .value=0x53f021f }, // DFITMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000584, .value=0xB0505 }, // DFITMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000588, .value=0x213f1f }, // DFITMG2
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000590, .value=0x180C0411 }, // DFITMG4
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000594, .value=0x0410000D  }, // DFITMG5
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x000005a0, .value=0x00100A0C }, // DFILPTMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x000005a4, .value=0x310 }, // DFILPTMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x000005ac, .value=0x280050 }, // DFIUPDTMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000600, .value=0x0201000c }, // RFSHSET1TMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000604, .value=0xA80060 }, // RFSHSET1TMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000608, .value=0x06480000 }, // RFSHSET1TMG2
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000650, .value=0x88 }, // RFMSET1TMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000800, .value=0x18096a }, // ZQSET1TMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000804, .value=0x28061a8 }, // ZQSET1TMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000b00, .value=0x00F42400 }, // DERATEINT
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000b04, .value=0x10241004 }, // DERATEVAL0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000b08, .value=0x00000033 }, // DERATEVAL1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000d08, .value=0x1c12 }, // RANKTMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00030004, .value=0x0000003F }, // ADDRMAP1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0003000c, .value=0x003f0606 }, // ADDRMAP3
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00030010, .value=0x00000404  }, // ADDRMAP4
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00030014, .value=0x1F131313 }, // ADDRMAP5
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00030018, .value=0x00000000  }, // ADDRMAP6
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0003001c, .value=0x1F1F1F05 }, // ADDRMAP7
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00030020, .value=0x05050505  }, // ADDRMAP8
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00030024, .value=0x05050505  }, // ADDRMAP9
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00030028, .value=0x05050505  }, // ADDRMAP10
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0003002c, .value=0x00000505  }, // ADDRMAP11
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00030030, .value=0x00000000 }, // ADDRMAP12
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010000, .value=0x1080008  }, // MSTR0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010104, .value=0x1 }, // DERATECTL1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010108, .value=0x1 }, // DERATECTL2
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000000, .value=0x2A101B22 }, // DRAMSET1TMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000004, .value=0x100630 }, // DRAMSET1TMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000008, .value=0x9111317 }, // DRAMSET1TMG2
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0100000c, .value=0xC212F }, // DRAMSET1TMG3
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000010, .value=0xf04040f }, // DRAMSET1TMG4
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000014, .value=0x02040C09 }, // DRAMSET1TMG5
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000018, .value=0x8 }, // DRAMSET1TMG6
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0100001c, .value=0x3 }, // DRAMSET1TMG7
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000024, .value=0x20410 }, // DRAMSET1TMG9
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000034, .value=0xc100002 }, // DRAMSET1TMG13
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000038, .value=0x2000AE }, // DRAMSET1TMG14
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0100005c, .value=0x009D0009 }, // DRAMSET1TMG23
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000060, .value=0x10160E }, // DRAMSET1TMG24
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000064, .value=0x2806 }, // DRAMSET1TMG25
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000078, .value=0x191418 }, // DRAMSET1TMG30
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000580, .value=0x53f021f }, // DFITMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000584, .value=0xB0505 }, // DFITMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000588, .value=0x213f1f }, // DFITMG2
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000590, .value=0x180C0411 }, // DFITMG4
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000594, .value=0x0410000D  }, // DFITMG5
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x010005a0, .value=0x00100A0C }, // DFILPTMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x010005a4, .value=0x310 }, // DFILPTMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x010005ac, .value=0x280050 }, // DFIUPDTMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000600, .value=0x0201000c }, // RFSHSET1TMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000604, .value=0xA80060 }, // RFSHSET1TMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000608, .value=0x06480000 }, // RFSHSET1TMG2
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000650, .value=0x88 }, // RFMSET1TMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000800, .value=0x18096a }, // ZQSET1TMG0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000804, .value=0x28061a8 }, // ZQSET1TMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000b00, .value=0x00F42400 }, // DERATEINT
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000b04, .value=0x10241004 }, // DERATEVAL0
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000b08, .value=0x00000033 }, // DERATEVAL1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000d08, .value=0x1c12 }, // RANKTMG1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01030004, .value=0x0000003F }, // ADDRMAP1
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0103000c, .value=0x003f0606 }, // ADDRMAP3
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01030010, .value=0x00000404  }, // ADDRMAP4
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01030014, .value=0x1F131313 }, // ADDRMAP5
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01030018, .value=0x00000000  }, // ADDRMAP6
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0103001c, .value=0x1F1F1F05 }, // ADDRMAP7
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01030020, .value=0x05050505  }, // ADDRMAP8
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01030024, .value=0x05050505  }, // ADDRMAP9
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01030028, .value=0x05050505  }, // ADDRMAP10
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x0103002c, .value=0x00000505  }, // ADDRMAP11
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01030030, .value=0x00000000 }, // ADDRMAP12
};

static init_element_t seq2_init_ddr_modalix_1r[] = {
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010180, .value=0x00000211 }, // PWRCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010180, .value=0x00000211 }, // PWRCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010180, .value=0x00000211 }, // PWRCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010180, .value=0x00000211 }, // PWRCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010180, .value=0x00000211 }, // PWRCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010180, .value=0x00000211 }, // PWRCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010100, .value=0x00000018 }, // DERATECTL0;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010100, .value=0x00000018 }, // DERATECTL0;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010c80, .value=0x00000000 }, // SWCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010c80, .value=0x00000000 }, // SWCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010510, .value=0x00000004 }, // DFIMISC;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010510, .value=0x00000004 }, // DFIMISC;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010c80, .value=0x00000001 }, // SWCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010c80, .value=0x00000001 }, // SWCTL;
    { .type=PHY_INIT_TYPE_POLL, .addr=0x00010c84, .value=0x00000001 }, // SWSTAT
    { .type=PHY_INIT_TYPE_POLL, .addr=0x01010c84, .value=0x00000001 }, // SWSTAT
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010208, .value=0x00000000 }, // RFSHCTL0;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010208, .value=0x00000000 }, // RFSHCTL0;
};

static init_element_t seq3_2D_init_ddr_modalix_1r[] = {
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20060, .value=0x2 }, // DWC_DDRPHYA_MASTER0_p0_MemResetL
    { .type=PHY_INIT_TYPE_PHY, .addr=0x200a5, .value=0x1 }, // DWC_DDRPHYA_MASTER0_p0_LP5Mode
    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0036, .value=0x0 }, // DWC_DDRPHYA_APBONLY0_NeverGateAcCsrClock
    { .type=PHY_INIT_TYPE_PHY, .addr=0x200bd, .value=0xff }, // DWC_DDRPHYA_MASTER0_p0_PhyPerfCtrEnable
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20300, .value=0x808 }, // DWC_DDRPHYA_MASTER0_p0_ZCalRZN
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20303, .value=0x9 }, // DWC_DDRPHYA_MASTER0_p0_ZCalRate
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20302, .value=0x26 }, // DWC_DDRPHYA_MASTER0_p0_ZCalCompVref
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20328, .value=0x0 }, // DWC_DDRPHYA_MASTER0_p0_VrefDacRefCtl
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20301, .value=0x3 }, // DWC_DDRPHYA_MASTER0_p0_ZCalBaseCtrl
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2030b, .value=0x0 }, // DWC_DDRPHYA_MASTER0_p0_ZCalCompCtrl
    { .type=PHY_INIT_TYPE_PHY, .addr=0x300a7, .value=0x0 }, // DWC_DDRPHYA_AC0_p0_DFIPHYUPD
    { .type=PHY_INIT_TYPE_PHY, .addr=0x310a7, .value=0x0 }, // DWC_DDRPHYA_AC1_p0_DFIPHYUPD
    { .type=PHY_INIT_TYPE_PHY, .addr=0x300ae, .value=0x280 }, // DWC_DDRPHYA_AC0_p0_PClkAcLnDis
    { .type=PHY_INIT_TYPE_PHY, .addr=0x300ad, .value=0x280 }, // DWC_DDRPHYA_AC0_p0_DfiClkAcLnDis
    { .type=PHY_INIT_TYPE_PHY, .addr=0x300ac, .value=0x280 }, // DWC_DDRPHYA_AC0_p0_AcLnDisable
    { .type=PHY_INIT_TYPE_PHY, .addr=0x310ae, .value=0x280 }, // DWC_DDRPHYA_AC1_p0_PClkAcLnDis
    { .type=PHY_INIT_TYPE_PHY, .addr=0x310ad, .value=0x280 }, // DWC_DDRPHYA_AC1_p0_DfiClkAcLnDis
    { .type=PHY_INIT_TYPE_PHY, .addr=0x310ac, .value=0x280 }, // DWC_DDRPHYA_AC1_p0_AcLnDisable
    { .type=PHY_INIT_TYPE_PHY, .addr=0xc0086, .value=0x0 }, // DWC_DDRPHYA_DRTUB0_ArcPmuEccCtl
    { .type=PHY_INIT_TYPE_PHY, .addr=0x100a3, .value=0x811 }, // DWC_DDRPHYA_DBYTE0_p0_PptCtlStatic
    { .type=PHY_INIT_TYPE_PHY, .addr=0x110a3, .value=0x81d }, // DWC_DDRPHYA_DBYTE1_p0_PptCtlStatic
    { .type=PHY_INIT_TYPE_PHY, .addr=0x120a3, .value=0x811 }, // DWC_DDRPHYA_DBYTE2_p0_PptCtlStatic
    { .type=PHY_INIT_TYPE_PHY, .addr=0x130a3, .value=0x81d }, // DWC_DDRPHYA_DBYTE3_p0_PptCtlStatic
    { .type=PHY_INIT_TYPE_PHYSETTINGS, .addr=0x0, .value=0x0 },
    { .type=PHY_INIT_TYPE_PHY, .addr=0xc00f1, .value=0x6000 }, // DWC_DDRPHYA_DRTUB0_DfiFreqXlat1
    { .type=PHY_INIT_TYPE_PHY, .addr=0xc00f2, .value=0xa9 }, // DWC_DDRPHYA_DRTUB0_DfiFreqXlat2
    { .type=PHY_INIT_TYPE_PHY, .addr=0xc00f3, .value=0x8000 }, // DWC_DDRPHYA_DRTUB0_DfiFreqXlat3
    { .type=PHY_INIT_TYPE_PHY, .addr=0xc00f4, .value=0x5 }, // DWC_DDRPHYA_DRTUB0_DfiFreqXlat4
    { .type=PHY_INIT_TYPE_PHY, .addr=0xc00f5, .value=0x4000 }, // DWC_DDRPHYA_DRTUB0_DfiFreqXlat5
    { .type=PHY_INIT_TYPE_PHY, .addr=0xc00f6, .value=0x2 }, // DWC_DDRPHYA_DRTUB0_DfiFreqXlat6
    { .type=PHY_INIT_TYPE_PHY, .addr=0xc00f7, .value=0xf000 }, // DWC_DDRPHYA_DRTUB0_DfiFreqXlat7
    { .type=PHY_INIT_TYPE_PHY, .addr=0xc00f9, .value=0x6000 }, // DWC_DDRPHYA_DRTUB0_DfiFreqXlat9
    { .type=PHY_INIT_TYPE_PHY, .addr=0xc00fa, .value=0xa9 }, // DWC_DDRPHYA_DRTUB0_DfiFreqXlat10
    { .type=PHY_INIT_TYPE_PHY, .addr=0xc00fb, .value=0x8000 }, // DWC_DDRPHYA_DRTUB0_DfiFreqXlat11
    { .type=PHY_INIT_TYPE_PHY, .addr=0xc00fd, .value=0x4000 }, // DWC_DDRPHYA_DRTUB0_DfiFreqXlat13
    { .type=PHY_INIT_TYPE_PHY, .addr=0xc00ff, .value=0xf000 }, // DWC_DDRPHYA_DRTUB0_DfiFreqXlat15
    { .type=PHY_INIT_TYPE_PHY, .addr=0x908ff, .value=0xf }, // DWC_DDRPHYA_INITENG0_p0_Seq0BFixedAddrBits
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10093, .value=0x0 }, // DWC_DDRPHYA_DBYTE0_p0_DxRxPowerDown
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11093, .value=0x0 }, // DWC_DDRPHYA_DBYTE1_p0_DxRxPowerDown
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12093, .value=0x0 }, // DWC_DDRPHYA_DBYTE2_p0_DxRxPowerDown
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13093, .value=0x0 }, // DWC_DDRPHYA_DBYTE3_p0_DxRxPowerDown
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20051, .value=0x3 }, // DWC_DDRPHYA_MASTER0_p0_DfiMode
    { .type=PHY_INIT_TYPE_FIRMWARE, .addr=0x50000, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90802, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BGPR2_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2004c, .value=0x2e8f }, // DWC_DDRPHYA_MASTER0_p0_PllCtrl5_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2004d, .value=0x0 }, // DWC_DDRPHYA_MASTER0_p0_PllCtrl6_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20002, .value=0x4 }, // DWC_DDRPHYA_MASTER0_p0_PclkPtrInitVal_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20000, .value=0x2 }, // DWC_DDRPHYA_MASTER0_p0_DfiFreqRatio_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90801, .value=0x4d }, // DWC_DDRPHYA_INITENG0_p0_Seq0BGPR1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90809, .value=0x6800 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BGPR9_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1005e, .value=0x366 }, // DWC_DDRPHYA_DBYTE0_p0_TxWCKDcaCtrlTTg0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10060, .value=0x366 }, // DWC_DDRPHYA_DBYTE0_p0_TxWCKDcaCtrlCTg0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10062, .value=0x366 }, // DWC_DDRPHYA_DBYTE0_p0_RxWCKDcaCtrlTTg0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10064, .value=0x366 }, // DWC_DDRPHYA_DBYTE0_p0_RxWCKDcaCtrlCTg0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1105e, .value=0x366 }, // DWC_DDRPHYA_DBYTE1_p0_TxWCKDcaCtrlTTg0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11060, .value=0x366 }, // DWC_DDRPHYA_DBYTE1_p0_TxWCKDcaCtrlCTg0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11062, .value=0x366 }, // DWC_DDRPHYA_DBYTE1_p0_RxWCKDcaCtrlTTg0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11064, .value=0x366 }, // DWC_DDRPHYA_DBYTE1_p0_RxWCKDcaCtrlCTg0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1205e, .value=0x366 }, // DWC_DDRPHYA_DBYTE2_p0_TxWCKDcaCtrlTTg0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12060, .value=0x366 }, // DWC_DDRPHYA_DBYTE2_p0_TxWCKDcaCtrlCTg0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12062, .value=0x366 }, // DWC_DDRPHYA_DBYTE2_p0_RxWCKDcaCtrlTTg0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12064, .value=0x366 }, // DWC_DDRPHYA_DBYTE2_p0_RxWCKDcaCtrlCTg0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1305e, .value=0x366 }, // DWC_DDRPHYA_DBYTE3_p0_TxWCKDcaCtrlTTg0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13060, .value=0x366 }, // DWC_DDRPHYA_DBYTE3_p0_TxWCKDcaCtrlCTg0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13062, .value=0x366 }, // DWC_DDRPHYA_DBYTE3_p0_RxWCKDcaCtrlTTg0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13064, .value=0x366 }, // DWC_DDRPHYA_DBYTE3_p0_RxWCKDcaCtrlCTg0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10005, .value=0x0 }, // DWC_DDRPHYA_DBYTE0_p0_RxDigStrbEn_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1000b, .value=0x0 }, // DWC_DDRPHYA_DBYTE0_p0_DxDigStrobeMode_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11005, .value=0x0 }, // DWC_DDRPHYA_DBYTE1_p0_RxDigStrbEn_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1100b, .value=0x0 }, // DWC_DDRPHYA_DBYTE1_p0_DxDigStrobeMode_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12005, .value=0x0 }, // DWC_DDRPHYA_DBYTE2_p0_RxDigStrbEn_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1200b, .value=0x0 }, // DWC_DDRPHYA_DBYTE2_p0_DxDigStrobeMode_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13005, .value=0x0 }, // DWC_DDRPHYA_DBYTE3_p0_RxDigStrbEn_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1300b, .value=0x0 }, // DWC_DDRPHYA_DBYTE3_p0_DxDigStrobeMode_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20007, .value=0x0 }, // DWC_DDRPHYA_MASTER0_p0_DqsPreambleControl_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20013, .value=0x2c }, // DWC_DDRPHYA_MASTER0_p0_DbyteRxDqsModeCntrl_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x30038, .value=0x3 }, // DWC_DDRPHYA_AC0_p0_RxModeCtlSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x30039, .value=0x3 }, // DWC_DDRPHYA_AC0_p0_RxModeCtlSE1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x3003a, .value=0x3 }, // DWC_DDRPHYA_AC0_p0_RxModeCtlDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x31038, .value=0x3 }, // DWC_DDRPHYA_AC1_p0_RxModeCtlSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x31039, .value=0x3 }, // DWC_DDRPHYA_AC1_p0_RxModeCtlSE1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x3103a, .value=0x3 }, // DWC_DDRPHYA_AC1_p0_RxModeCtlDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10038, .value=0x3 }, // DWC_DDRPHYA_DBYTE0_p0_RxModeCtlSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1003a, .value=0x3 }, // DWC_DDRPHYA_DBYTE0_p0_RxModeCtlDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11038, .value=0x3 }, // DWC_DDRPHYA_DBYTE1_p0_RxModeCtlSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1103a, .value=0x3 }, // DWC_DDRPHYA_DBYTE1_p0_RxModeCtlDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12038, .value=0x3 }, // DWC_DDRPHYA_DBYTE2_p0_RxModeCtlSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1203a, .value=0x3 }, // DWC_DDRPHYA_DBYTE2_p0_RxModeCtlDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13038, .value=0x3 }, // DWC_DDRPHYA_DBYTE3_p0_RxModeCtlSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1303a, .value=0x3 }, // DWC_DDRPHYA_DBYTE3_p0_RxModeCtlDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1003b, .value=0x3 }, // DWC_DDRPHYA_DBYTE0_p0_RxModeCtlDIFF1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1103b, .value=0x3 }, // DWC_DDRPHYA_DBYTE1_p0_RxModeCtlDIFF1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1203b, .value=0x3 }, // DWC_DDRPHYA_DBYTE2_p0_RxModeCtlDIFF1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1303b, .value=0x3 }, // DWC_DDRPHYA_DBYTE3_p0_RxModeCtlDIFF1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10009, .value=0x4 }, // DWC_DDRPHYA_DBYTE0_p0_RxDfeModeCfg_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10037, .value=0x1 }, // DWC_DDRPHYA_DBYTE0_p0_RxVrefCtl_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11009, .value=0x4 }, // DWC_DDRPHYA_DBYTE1_p0_RxDfeModeCfg_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11037, .value=0x1 }, // DWC_DDRPHYA_DBYTE1_p0_RxVrefCtl_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12009, .value=0x4 }, // DWC_DDRPHYA_DBYTE2_p0_RxDfeModeCfg_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12037, .value=0x1 }, // DWC_DDRPHYA_DBYTE2_p0_RxVrefCtl_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13009, .value=0x4 }, // DWC_DDRPHYA_DBYTE3_p0_RxDfeModeCfg_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13037, .value=0x1 }, // DWC_DDRPHYA_DBYTE3_p0_RxVrefCtl_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10004, .value=0x0 }, // DWC_DDRPHYA_DBYTE0_p0_DxPClkDis_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10003, .value=0x0 }, // DWC_DDRPHYA_DBYTE0_p0_DxDfiClkDis_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11004, .value=0x0 }, // DWC_DDRPHYA_DBYTE1_p0_DxPClkDis_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11003, .value=0x0 }, // DWC_DDRPHYA_DBYTE1_p0_DxDfiClkDis_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12004, .value=0x0 }, // DWC_DDRPHYA_DBYTE2_p0_DxPClkDis_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12003, .value=0x0 }, // DWC_DDRPHYA_DBYTE2_p0_DxDfiClkDis_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13004, .value=0x0 }, // DWC_DDRPHYA_DBYTE3_p0_DxPClkDis_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13003, .value=0x0 }, // DWC_DDRPHYA_DBYTE3_p0_DxDfiClkDis_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20004, .value=0x320 }, // DWC_DDRPHYA_MASTER0_p0_ZCalClkInfo_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x30050, .value=0x3c }, // DWC_DDRPHYA_AC0_p0_AcVrefDAC0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x30051, .value=0x3c }, // DWC_DDRPHYA_AC0_p0_AcVrefDAC1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x30052, .value=0x3c }, // DWC_DDRPHYA_AC0_p0_AcVrefDAC2_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x30053, .value=0x3c }, // DWC_DDRPHYA_AC0_p0_AcVrefDAC3_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x31050, .value=0x3c }, // DWC_DDRPHYA_AC1_p0_AcVrefDAC0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x31051, .value=0x3c }, // DWC_DDRPHYA_AC1_p0_AcVrefDAC1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x31052, .value=0x3c }, // DWC_DDRPHYA_AC1_p0_AcVrefDAC2_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x31053, .value=0x3c }, // DWC_DDRPHYA_AC1_p0_AcVrefDAC3_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1004e, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC0_r0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1004f, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC1_r0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10050, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC2_r0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10051, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC3_r0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1014e, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC0_r1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1014f, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC1_r1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10150, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC2_r1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10151, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC3_r1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1024e, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC0_r2_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1024f, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC1_r2_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10250, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC2_r2_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10251, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC3_r2_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1034e, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC0_r3_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1034f, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC1_r3_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10350, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC2_r3_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10351, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC3_r3_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1044e, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC0_r4_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1044f, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC1_r4_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10450, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC2_r4_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10451, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC3_r4_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1054e, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC0_r5_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1054f, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC1_r5_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10550, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC2_r5_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10551, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC3_r5_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1064e, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC0_r6_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1064f, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC1_r6_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10650, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC2_r6_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10651, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC3_r6_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1074e, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC0_r7_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1074f, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC1_r7_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10750, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC2_r7_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10751, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC3_r7_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1084e, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC0_r8_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1084f, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC1_r8_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10850, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC2_r8_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10851, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_VrefDAC3_r8_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1104e, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC0_r0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1104f, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC1_r0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11050, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC2_r0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11051, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC3_r0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1114e, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC0_r1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1114f, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC1_r1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11150, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC2_r1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11151, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC3_r1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1124e, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC0_r2_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1124f, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC1_r2_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11250, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC2_r2_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11251, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC3_r2_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1134e, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC0_r3_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1134f, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC1_r3_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11350, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC2_r3_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11351, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC3_r3_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1144e, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC0_r4_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1144f, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC1_r4_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11450, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC2_r4_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11451, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC3_r4_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1154e, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC0_r5_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1154f, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC1_r5_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11550, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC2_r5_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11551, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC3_r5_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1164e, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC0_r6_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1164f, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC1_r6_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11650, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC2_r6_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11651, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC3_r6_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1174e, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC0_r7_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1174f, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC1_r7_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11750, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC2_r7_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11751, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC3_r7_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1184e, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC0_r8_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1184f, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC1_r8_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11850, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC2_r8_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11851, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_VrefDAC3_r8_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1204e, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC0_r0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1204f, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC1_r0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12050, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC2_r0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12051, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC3_r0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1214e, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC0_r1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1214f, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC1_r1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12150, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC2_r1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12151, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC3_r1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1224e, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC0_r2_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1224f, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC1_r2_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12250, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC2_r2_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12251, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC3_r2_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1234e, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC0_r3_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1234f, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC1_r3_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12350, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC2_r3_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12351, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC3_r3_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1244e, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC0_r4_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1244f, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC1_r4_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12450, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC2_r4_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12451, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC3_r4_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1254e, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC0_r5_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1254f, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC1_r5_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12550, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC2_r5_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12551, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC3_r5_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1264e, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC0_r6_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1264f, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC1_r6_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12650, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC2_r6_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12651, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC3_r6_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1274e, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC0_r7_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1274f, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC1_r7_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12750, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC2_r7_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12751, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC3_r7_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1284e, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC0_r8_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1284f, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC1_r8_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12850, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC2_r8_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12851, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_VrefDAC3_r8_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1304e, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC0_r0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1304f, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC1_r0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13050, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC2_r0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13051, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC3_r0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1314e, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC0_r1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1314f, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC1_r1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13150, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC2_r1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13151, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC3_r1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1324e, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC0_r2_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1324f, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC1_r2_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13250, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC2_r2_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13251, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC3_r2_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1334e, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC0_r3_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1334f, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC1_r3_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13350, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC2_r3_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13351, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC3_r3_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1344e, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC0_r4_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1344f, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC1_r4_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13450, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC2_r4_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13451, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC3_r4_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1354e, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC0_r5_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1354f, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC1_r5_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13550, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC2_r5_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13551, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC3_r5_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1364e, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC0_r6_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1364f, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC1_r6_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13650, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC2_r6_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13651, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC3_r6_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1374e, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC0_r7_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1374f, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC1_r7_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13750, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC2_r7_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13751, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC3_r7_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1384e, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC0_r8_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1384f, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC1_r8_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13850, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC2_r8_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13851, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_VrefDAC3_r8_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x30030, .value=0x0 }, // DWC_DDRPHYA_AC0_p0_TxModeCtlSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x30031, .value=0x0 }, // DWC_DDRPHYA_AC0_p0_TxModeCtlSE1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x30035, .value=0x0 }, // DWC_DDRPHYA_AC0_p0_TxModeCtlDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x31030, .value=0x0 }, // DWC_DDRPHYA_AC1_p0_TxModeCtlSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x31031, .value=0x0 }, // DWC_DDRPHYA_AC1_p0_TxModeCtlSE1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x31035, .value=0x0 }, // DWC_DDRPHYA_AC1_p0_TxModeCtlDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10030, .value=0x0 }, // DWC_DDRPHYA_DBYTE0_p0_TxModeCtlSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10035, .value=0x0 }, // DWC_DDRPHYA_DBYTE0_p0_TxModeCtlDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10036, .value=0x0 }, // DWC_DDRPHYA_DBYTE0_p0_TxModeCtlDIFF1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11030, .value=0x0 }, // DWC_DDRPHYA_DBYTE1_p0_TxModeCtlSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11035, .value=0x0 }, // DWC_DDRPHYA_DBYTE1_p0_TxModeCtlDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11036, .value=0x0 }, // DWC_DDRPHYA_DBYTE1_p0_TxModeCtlDIFF1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12030, .value=0x0 }, // DWC_DDRPHYA_DBYTE2_p0_TxModeCtlSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12035, .value=0x0 }, // DWC_DDRPHYA_DBYTE2_p0_TxModeCtlDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12036, .value=0x0 }, // DWC_DDRPHYA_DBYTE2_p0_TxModeCtlDIFF1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13030, .value=0x0 }, // DWC_DDRPHYA_DBYTE3_p0_TxModeCtlSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13035, .value=0x0 }, // DWC_DDRPHYA_DBYTE3_p0_TxModeCtlDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13036, .value=0x0 }, // DWC_DDRPHYA_DBYTE3_p0_TxModeCtlDIFF1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x3003c, .value=0x5 }, // DWC_DDRPHYA_AC0_p0_RxGainCurrAdjDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x3103c, .value=0x5 }, // DWC_DDRPHYA_AC1_p0_RxGainCurrAdjDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1003c, .value=0x5 }, // DWC_DDRPHYA_DBYTE0_p0_RxGainCurrAdjDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1003d, .value=0x5 }, // DWC_DDRPHYA_DBYTE0_p0_RxGainCurrAdjDIFF1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1003e, .value=0x5 }, // DWC_DDRPHYA_DBYTE0_p0_RxGainCurrAdjRxReplica_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1103c, .value=0x5 }, // DWC_DDRPHYA_DBYTE1_p0_RxGainCurrAdjDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1103d, .value=0x5 }, // DWC_DDRPHYA_DBYTE1_p0_RxGainCurrAdjDIFF1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1103e, .value=0x5 }, // DWC_DDRPHYA_DBYTE1_p0_RxGainCurrAdjRxReplica_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1203c, .value=0x5 }, // DWC_DDRPHYA_DBYTE2_p0_RxGainCurrAdjDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1203d, .value=0x5 }, // DWC_DDRPHYA_DBYTE2_p0_RxGainCurrAdjDIFF1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1203e, .value=0x5 }, // DWC_DDRPHYA_DBYTE2_p0_RxGainCurrAdjRxReplica_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1303c, .value=0x5 }, // DWC_DDRPHYA_DBYTE3_p0_RxGainCurrAdjDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1303d, .value=0x5 }, // DWC_DDRPHYA_DBYTE3_p0_RxGainCurrAdjDIFF1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1303e, .value=0x5 }, // DWC_DDRPHYA_DBYTE3_p0_RxGainCurrAdjRxReplica_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20003, .value=0x1 }, // DWC_DDRPHYA_MASTER0_p0_CmdFifoWrModeMaster_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20001, .value=0x1122 }, // DWC_DDRPHYA_MASTER0_p0_PclkDivRatio_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20009, .value=0x0 }, // DWC_DDRPHYA_MASTER0_p0_CkDisVal_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20008, .value=0x0 }, // DWC_DDRPHYA_MASTER0_p0_DMIPinPresent_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x200d9, .value=0x0 }, // DWC_DDRPHYA_MASTER0_p0_EnPhyUpdZQCalUpdate
    { .type=PHY_INIT_TYPE_PHY, .addr=0x30eef, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x31eef, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20014, .value=0x1300 }, // DWC_DDRPHYA_MASTER0_p0_TrackingModeCntrl_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9080a, .value=0x1300 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BGPR10_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10040, .value=0xe0e }, // DWC_DDRPHYA_DBYTE0_p0_TxImpedanceSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10042, .value=0xe0e }, // DWC_DDRPHYA_DBYTE0_p0_TxImpedanceDIFF0T_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9080d, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BGPR13_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10043, .value=0x0 }, // DWC_DDRPHYA_DBYTE0_p0_TxImpedanceDIFF0C_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10044, .value=0xe0e }, // DWC_DDRPHYA_DBYTE0_p0_TxImpedanceDIFF1T_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10045, .value=0xe0e }, // DWC_DDRPHYA_DBYTE0_p0_TxImpedanceDIFF1C_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11040, .value=0xe0e }, // DWC_DDRPHYA_DBYTE1_p0_TxImpedanceSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11042, .value=0xe0e }, // DWC_DDRPHYA_DBYTE1_p0_TxImpedanceDIFF0T_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9080d, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BGPR13_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11043, .value=0x0 }, // DWC_DDRPHYA_DBYTE1_p0_TxImpedanceDIFF0C_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11044, .value=0xe0e }, // DWC_DDRPHYA_DBYTE1_p0_TxImpedanceDIFF1T_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11045, .value=0xe0e }, // DWC_DDRPHYA_DBYTE1_p0_TxImpedanceDIFF1C_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12040, .value=0xe0e }, // DWC_DDRPHYA_DBYTE2_p0_TxImpedanceSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12042, .value=0xe0e }, // DWC_DDRPHYA_DBYTE2_p0_TxImpedanceDIFF0T_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9080d, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BGPR13_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12043, .value=0x0 }, // DWC_DDRPHYA_DBYTE2_p0_TxImpedanceDIFF0C_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12044, .value=0xe0e }, // DWC_DDRPHYA_DBYTE2_p0_TxImpedanceDIFF1T_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12045, .value=0xe0e }, // DWC_DDRPHYA_DBYTE2_p0_TxImpedanceDIFF1C_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13040, .value=0xe0e }, // DWC_DDRPHYA_DBYTE3_p0_TxImpedanceSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13042, .value=0xe0e }, // DWC_DDRPHYA_DBYTE3_p0_TxImpedanceDIFF0T_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9080d, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BGPR13_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13043, .value=0x0 }, // DWC_DDRPHYA_DBYTE3_p0_TxImpedanceDIFF0C_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13044, .value=0xe0e }, // DWC_DDRPHYA_DBYTE3_p0_TxImpedanceDIFF1T_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13045, .value=0xe0e }, // DWC_DDRPHYA_DBYTE3_p0_TxImpedanceDIFF1C_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x30040, .value=0xe0e }, // DWC_DDRPHYA_AC0_p0_TxImpedanceSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x30041, .value=0xe0e }, // DWC_DDRPHYA_AC0_p0_TxImpedanceSE1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x30042, .value=0xe0e }, // DWC_DDRPHYA_AC0_p0_TxImpedanceDIFF0T_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x30043, .value=0xe0e }, // DWC_DDRPHYA_AC0_p0_TxImpedanceDIFF0C_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x30330, .value=0x33 }, // DWC_DDRPHYA_AC0_p0_TxImpedanceCMOS0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x31040, .value=0xe0e }, // DWC_DDRPHYA_AC1_p0_TxImpedanceSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x31041, .value=0xe0e }, // DWC_DDRPHYA_AC1_p0_TxImpedanceSE1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x31042, .value=0xe0e }, // DWC_DDRPHYA_AC1_p0_TxImpedanceDIFF0T_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x31043, .value=0xe0e }, // DWC_DDRPHYA_AC1_p0_TxImpedanceDIFF0C_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x31330, .value=0x33 }, // DWC_DDRPHYA_AC1_p0_TxImpedanceCMOS0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20331, .value=0x33 }, // DWC_DDRPHYA_MASTER0_p0_TxImpedanceCMOS1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10048, .value=0xc00 }, // DWC_DDRPHYA_DBYTE0_p0_OdtImpedanceSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1004a, .value=0xc00 }, // DWC_DDRPHYA_DBYTE0_p0_OdtImpedanceDIFF0T_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1004b, .value=0xc00 }, // DWC_DDRPHYA_DBYTE0_p0_OdtImpedanceDIFF0C_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1004c, .value=0xc00 }, // DWC_DDRPHYA_DBYTE0_p0_OdtImpedanceDIFF1T_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1004d, .value=0xc00 }, // DWC_DDRPHYA_DBYTE0_p0_OdtImpedanceDIFF1C_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11048, .value=0xc00 }, // DWC_DDRPHYA_DBYTE1_p0_OdtImpedanceSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1104a, .value=0xc00 }, // DWC_DDRPHYA_DBYTE1_p0_OdtImpedanceDIFF0T_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1104b, .value=0xc00 }, // DWC_DDRPHYA_DBYTE1_p0_OdtImpedanceDIFF0C_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1104c, .value=0xc00 }, // DWC_DDRPHYA_DBYTE1_p0_OdtImpedanceDIFF1T_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1104d, .value=0xc00 }, // DWC_DDRPHYA_DBYTE1_p0_OdtImpedanceDIFF1C_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12048, .value=0xc00 }, // DWC_DDRPHYA_DBYTE2_p0_OdtImpedanceSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1204a, .value=0xc00 }, // DWC_DDRPHYA_DBYTE2_p0_OdtImpedanceDIFF0T_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1204b, .value=0xc00 }, // DWC_DDRPHYA_DBYTE2_p0_OdtImpedanceDIFF0C_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1204c, .value=0xc00 }, // DWC_DDRPHYA_DBYTE2_p0_OdtImpedanceDIFF1T_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1204d, .value=0xc00 }, // DWC_DDRPHYA_DBYTE2_p0_OdtImpedanceDIFF1C_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13048, .value=0xc00 }, // DWC_DDRPHYA_DBYTE3_p0_OdtImpedanceSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1304a, .value=0xc00 }, // DWC_DDRPHYA_DBYTE3_p0_OdtImpedanceDIFF0T_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1304b, .value=0xc00 }, // DWC_DDRPHYA_DBYTE3_p0_OdtImpedanceDIFF0C_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1304c, .value=0xc00 }, // DWC_DDRPHYA_DBYTE3_p0_OdtImpedanceDIFF1T_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1304d, .value=0xc00 }, // DWC_DDRPHYA_DBYTE3_p0_OdtImpedanceDIFF1C_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x30048, .value=0xe00 }, // DWC_DDRPHYA_AC0_p0_OdtImpedanceSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x30049, .value=0xe00 }, // DWC_DDRPHYA_AC0_p0_OdtImpedanceSE1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x3004a, .value=0xe00 }, // DWC_DDRPHYA_AC0_p0_OdtImpedanceDIFF0T_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x3004b, .value=0xe00 }, // DWC_DDRPHYA_AC0_p0_OdtImpedanceDIFF0C_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x31048, .value=0xe00 }, // DWC_DDRPHYA_AC1_p0_OdtImpedanceSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x31049, .value=0xe00 }, // DWC_DDRPHYA_AC1_p0_OdtImpedanceSE1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x3104a, .value=0xe00 }, // DWC_DDRPHYA_AC1_p0_OdtImpedanceDIFF0T_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x3104b, .value=0xe00 }, // DWC_DDRPHYA_AC1_p0_OdtImpedanceDIFF0C_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x30033, .value=0xcc }, // DWC_DDRPHYA_AC0_p0_TxSlewSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x30034, .value=0xcc }, // DWC_DDRPHYA_AC0_p0_TxSlewSE1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x3002e, .value=0xcc }, // DWC_DDRPHYA_AC0_p0_TxSlewDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x31033, .value=0xcc }, // DWC_DDRPHYA_AC1_p0_TxSlewSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x31034, .value=0xcc }, // DWC_DDRPHYA_AC1_p0_TxSlewSE1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x3102e, .value=0xcc }, // DWC_DDRPHYA_AC1_p0_TxSlewDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10033, .value=0xcc }, // DWC_DDRPHYA_DBYTE0_p0_TxSlewSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1002e, .value=0xcc }, // DWC_DDRPHYA_DBYTE0_p0_TxSlewDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1002f, .value=0xcc }, // DWC_DDRPHYA_DBYTE0_p0_TxSlewDIFF1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11033, .value=0xcc }, // DWC_DDRPHYA_DBYTE1_p0_TxSlewSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1102e, .value=0xcc }, // DWC_DDRPHYA_DBYTE1_p0_TxSlewDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1102f, .value=0xcc }, // DWC_DDRPHYA_DBYTE1_p0_TxSlewDIFF1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12033, .value=0xcc }, // DWC_DDRPHYA_DBYTE2_p0_TxSlewSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1202e, .value=0xcc }, // DWC_DDRPHYA_DBYTE2_p0_TxSlewDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1202f, .value=0xcc }, // DWC_DDRPHYA_DBYTE2_p0_TxSlewDIFF1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13033, .value=0xcc }, // DWC_DDRPHYA_DBYTE3_p0_TxSlewSE0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1302e, .value=0xcc }, // DWC_DDRPHYA_DBYTE3_p0_TxSlewDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1302f, .value=0xcc }, // DWC_DDRPHYA_DBYTE3_p0_TxSlewDIFF1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20015, .value=0x0 }, // DWC_DDRPHYA_MASTER0_p0_SingleEndedMode_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90806, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BGPR6_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x100e8, .value=0x0 }, // DWC_DDRPHYA_DBYTE0_p0_RxDiffSeDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x100e9, .value=0x3c }, // DWC_DDRPHYA_DBYTE0_p0_RxDiffSeVrefDACDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x110e8, .value=0x0 }, // DWC_DDRPHYA_DBYTE1_p0_RxDiffSeDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x110e9, .value=0x3c }, // DWC_DDRPHYA_DBYTE1_p0_RxDiffSeVrefDACDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x120e8, .value=0x0 }, // DWC_DDRPHYA_DBYTE2_p0_RxDiffSeDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x120e9, .value=0x3c }, // DWC_DDRPHYA_DBYTE2_p0_RxDiffSeVrefDACDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x130e8, .value=0x0 }, // DWC_DDRPHYA_DBYTE3_p0_RxDiffSeDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x130e9, .value=0x3c }, // DWC_DDRPHYA_DBYTE3_p0_RxDiffSeVrefDACDIFF0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10001, .value=0x0 }, // DWC_DDRPHYA_DBYTE0_p0_EnableWriteLinkEcc_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11001, .value=0x0 }, // DWC_DDRPHYA_DBYTE1_p0_EnableWriteLinkEcc_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12001, .value=0x0 }, // DWC_DDRPHYA_DBYTE2_p0_EnableWriteLinkEcc_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13001, .value=0x0 }, // DWC_DDRPHYA_DBYTE3_p0_EnableWriteLinkEcc_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20012, .value=0xa1a1 }, // DWC_DDRPHYA_MASTER0_p0_DllGainCtl_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20017, .value=0x40 }, // DWC_DDRPHYA_MASTER0_p0_DxDllLockParam_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2000a, .value=0x40 }, // DWC_DDRPHYA_MASTER0_p0_AcDllLockParam_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20186, .value=0xa1 }, // DWC_DDRPHYA_MASTER0_p0_RxReplicaDllGainCtl_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20187, .value=0x40 }, // DWC_DDRPHYA_MASTER0_p0_RxReplicaDllLockParam_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20010, .value=0x5a }, // DWC_DDRPHYA_MASTER0_p0_PPTTrainSetup_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20011, .value=0xf }, // DWC_DDRPHYA_MASTER0_p0_PPTTrainSetup2_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9080b, .value=0xf }, // DWC_DDRPHYA_INITENG0_p0_Seq0BGPR11_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9080c, .value=0xf }, // DWC_DDRPHYA_INITENG0_p0_Seq0BGPR12_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x100a5, .value=0x1 }, // DWC_DDRPHYA_DBYTE0_p0_RxTrainPattern8BitMode_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x110a5, .value=0x1 }, // DWC_DDRPHYA_DBYTE1_p0_RxTrainPattern8BitMode_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x120a5, .value=0x1 }, // DWC_DDRPHYA_DBYTE2_p0_RxTrainPattern8BitMode_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x130a5, .value=0x1 }, // DWC_DDRPHYA_DBYTE3_p0_RxTrainPattern8BitMode_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10014, .value=0x3232 }, // DWC_DDRPHYA_DBYTE0_p0_RxReplicaRangeVal_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11014, .value=0x3232 }, // DWC_DDRPHYA_DBYTE1_p0_RxReplicaRangeVal_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12014, .value=0x3232 }, // DWC_DDRPHYA_DBYTE2_p0_RxReplicaRangeVal_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13014, .value=0x3232 }, // DWC_DDRPHYA_DBYTE3_p0_RxReplicaRangeVal_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1000f, .value=0x1086 }, // DWC_DDRPHYA_DBYTE0_p0_RxReplicaCtl04_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1100f, .value=0x1086 }, // DWC_DDRPHYA_DBYTE1_p0_RxReplicaCtl04_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1200f, .value=0x1086 }, // DWC_DDRPHYA_DBYTE2_p0_RxReplicaCtl04_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1300f, .value=0x1086 }, // DWC_DDRPHYA_DBYTE3_p0_RxReplicaCtl04_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20035, .value=0x100c }, // DWC_DDRPHYA_MASTER0_p0_ACSMWckWriteStaticLoPulse_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20036, .value=0x100c }, // DWC_DDRPHYA_MASTER0_p0_ACSMWckWriteStaticHiPulse_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20037, .value=0x41c }, // DWC_DDRPHYA_MASTER0_p0_ACSMWckWriteTogglePulse_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20037, .value=0x45c }, // DWC_DDRPHYA_MASTER0_p0_ACSMWckWriteTogglePulse_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20038, .value=0x1920 }, // DWC_DDRPHYA_MASTER0_p0_ACSMWckWriteFastTogglePulse_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20039, .value=0x1018 }, // DWC_DDRPHYA_MASTER0_p0_ACSMWckReadStaticLoPulse_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2003a, .value=0x1018 }, // DWC_DDRPHYA_MASTER0_p0_ACSMWckReadStaticHiPulse_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2003b, .value=0x428 }, // DWC_DDRPHYA_MASTER0_p0_ACSMWckReadTogglePulse_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2003c, .value=0x2d2c }, // DWC_DDRPHYA_MASTER0_p0_ACSMWckReadFastTogglePulse_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2003d, .value=0x1004 }, // DWC_DDRPHYA_MASTER0_p0_ACSMWckFreqSwStaticLoPulse_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2003e, .value=0x1004 }, // DWC_DDRPHYA_MASTER0_p0_ACSMWckFreqSwStaticHiPulse_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2003f, .value=0x414 }, // DWC_DDRPHYA_MASTER0_p0_ACSMWckFreqSwTogglePulse_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20040, .value=0x1118 }, // DWC_DDRPHYA_MASTER0_p0_ACSMWckFreqSwFastTogglePulse_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2002c, .value=0x83f }, // DWC_DDRPHYA_MASTER0_p0_ACSMRxEnPulse_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2002d, .value=0x83f }, // DWC_DDRPHYA_MASTER0_p0_ACSMRxValPulse_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20030, .value=0x83f }, // DWC_DDRPHYA_MASTER0_p0_ACSMRdcsPulse_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2002e, .value=0x81f }, // DWC_DDRPHYA_MASTER0_p0_ACSMTxEnPulse_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2002f, .value=0x81f }, // DWC_DDRPHYA_MASTER0_p0_ACSMWrcsPulse_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2000c, .value=0x0 }, // DWC_DDRPHYA_MASTER0_p0_AcPipeEn_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2001b, .value=0x0 }, // DWC_DDRPHYA_MASTER0_p0_InhibitTxRdPtrInit_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10007, .value=0x0 }, // DWC_DDRPHYA_DBYTE0_p0_TxDcaMode_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11007, .value=0x0 }, // DWC_DDRPHYA_DBYTE1_p0_TxDcaMode_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12007, .value=0x0 }, // DWC_DDRPHYA_DBYTE2_p0_TxDcaMode_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13007, .value=0x0 }, // DWC_DDRPHYA_DBYTE3_p0_TxDcaMode_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0xc0080, .value=0x3 }, // DWC_DDRPHYA_DRTUB0_UcclkHclkEnables
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2004a, .value=0x804 }, // DWC_DDRPHYA_MASTER0_p0_PllCtrl1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2004b, .value=0x247c }, // DWC_DDRPHYA_MASTER0_p0_PllCtrl4_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2004c, .value=0x6e8f }, // DWC_DDRPHYA_MASTER0_p0_PllCtrl5_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12004a, .value=0x804 }, // DWC_DDRPHYA_MASTER0_p1_PllCtrl1_p1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12004b, .value=0x247c }, // DWC_DDRPHYA_MASTER0_p1_PllCtrl4_p1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12004c, .value=0x6e8f }, // DWC_DDRPHYA_MASTER0_p1_PllCtrl5_p1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20088, .value=0x2531 }, // DWC_DDRPHYA_MASTER0_p0_PllUPllProg0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20089, .value=0x1800 }, // DWC_DDRPHYA_MASTER0_p0_PllUPllProg1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2008a, .value=0x3 }, // DWC_DDRPHYA_MASTER0_p0_PllUPllProg2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2008c, .value=0x0 }, // DWC_DDRPHYA_MASTER0_p0_PllUPllProg3
    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0 }, // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
    { .type=PHY_INIT_TYPE_FIRMWARE, .addr=0x58000, .value=0x1 }, //
    { .type=PHY_INIT_TYPE_PHY, .addr=0x58003, .value=0x1900 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x58008, .value=0x13df }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x5800e, .value=0x0 }, //
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x58012, .value=0x110 }, //
	{ .type=PHY_INIT_TYPE_PHY, .addr=0x58020, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x5802d, .value=0x00b1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x5802e, .value=0x00b1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x5802f, .value=0x00bb }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x58030, .value=0x00bb }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x58031, .value=0x6 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x58032, .value=0x6 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x58035, .value=0x3035 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x58036, .value=0x3035 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x58039, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x5803a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x5803f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x58040, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x58041, .value=0xF806 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x58042, .value=0xF806 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x58043, .value=0x001d }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x58044, .value=0x001d }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x58065, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x58066, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x58081, .value=0x4300 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x58082, .value=0x3f }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x1 }, // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x1 }, // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x9 }, // DWC_DDRPHYA_APBONLY0_MicroReset
    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x1 }, // DWC_DDRPHYA_APBONLY0_MicroReset
    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x0 }, // DWC_DDRPHYA_APBONLY0_MicroReset
    { .type=PHY_INIT_TYPE_RUN, .addr=0x0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0099, .value=0x1 }, // DWC_DDRPHYA_APBONLY0_MicroReset
    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0 }, // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
    { .type=PHY_INIT_TYPE_PHY, .addr=0x908f0, .value=0x65 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDLY0_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x908f1, .value=0x12c }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDLY1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x908f2, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDLY2_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x908f3, .value=0x58 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDLY3_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x908f4, .value=0x14 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDLY4_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x908f5, .value=0x7 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDLY5_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x908f6, .value=0x141 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDLY6_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x908f7, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDLY7_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41008, .value=0x49d8 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41009, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4100a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4100b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4100c, .value=0x4808 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4100d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4100e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4100f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41010, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41011, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41012, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41013, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41014, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41015, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41016, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41017, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41018, .value=0x4958 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41019, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4101a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4101b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4101c, .value=0x4e88 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4101d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4101e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4101f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41020, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41021, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41022, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41023, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41024, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41025, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41026, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41027, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41028, .value=0x40d8 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41029, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4102a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4102b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4102c, .value=0x58c8 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4102d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4102e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4102f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41030, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41031, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41032, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41033, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41034, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41035, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41036, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41037, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41038, .value=0x4158 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41039, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4103a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4103b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4103c, .value=0x5dc8 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4103d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4103e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4103f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41040, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41041, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41042, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41043, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41044, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41045, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41046, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41047, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41048, .value=0x41d8 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41049, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4104a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4104b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4104c, .value=0x4308 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4104d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4104e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4104f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41050, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41051, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41052, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41053, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41054, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41055, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41056, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41057, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41058, .value=0x4558 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41059, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4105a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4105b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4105c, .value=0x6a08 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4105d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4105e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4105f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41060, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41061, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41062, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41063, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41064, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41065, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41066, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41067, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41068, .value=0x45d8 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41069, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4106a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4106b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4106c, .value=0x5a88 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4106d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4106e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4106f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41070, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41071, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41072, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41073, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41074, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41075, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41076, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41077, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41078, .value=0x48d8 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41079, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4107a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4107b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4107c, .value=0x4308 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4107d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4107e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4107f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41080, .value=0x8d8 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41081, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41082, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41083, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41084, .value=0x3448 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41085, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41086, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41087, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41088, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41089, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4108a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4108b, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4108c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4108d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4108e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4108f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41090, .value=0x4a58 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41091, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41092, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41093, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41094, .value=0x4108 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41095, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41096, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41097, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41098, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41099, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4109a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4109b, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4109c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4109d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4109e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4109f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410a0, .value=0x4b58 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410a1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410a2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410a3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410a4, .value=0x4008 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410a5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410a6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410a7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410a8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410a9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410aa, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410ab, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410ac, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410ad, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410ae, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410af, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410b0, .value=0x54d8 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410b1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410b2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410b3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410b4, .value=0x4008 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410b5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410b6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410b7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20015, .value=0x0 }, // DWC_DDRPHYA_MASTER0_p0_SingleEndedMode_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x3004a, .value=0x0 }, // DWC_DDRPHYA_AC0_p0_OdtImpedanceDIFF0T_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x3004b, .value=0x0 }, // DWC_DDRPHYA_AC0_p0_OdtImpedanceDIFF0C_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x3104a, .value=0x0 }, // DWC_DDRPHYA_AC1_p0_OdtImpedanceDIFF0T_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x3104b, .value=0x0 }, // DWC_DDRPHYA_AC1_p0_OdtImpedanceDIFF0C_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2004c, .value=0x2e8f }, // DWC_DDRPHYA_MASTER0_p0_PllCtrl5_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2004d, .value=0x0 }, // DWC_DDRPHYA_MASTER0_p0_PllCtrl6_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20041, .value=0x1 }, // DWC_DDRPHYA_MASTER0_p0_ACSMWckFreeRunMode_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90802, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BGPR2_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20045, .value=0x2 }, // DWC_DDRPHYA_MASTER0_p0_ACSMRptCntOverride_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x10057, .value=0x0 }, // DWC_DDRPHYA_DBYTE0_p0_RxClkCntl1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x11057, .value=0x0 }, // DWC_DDRPHYA_DBYTE1_p0_RxClkCntl1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x12057, .value=0x0 }, // DWC_DDRPHYA_DBYTE2_p0_RxClkCntl1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x13057, .value=0x0 }, // DWC_DDRPHYA_DBYTE3_p0_RxClkCntl1_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1000f, .value=0x1088 }, // DWC_DDRPHYA_DBYTE0_p0_RxReplicaCtl04_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1100f, .value=0x1088 }, // DWC_DDRPHYA_DBYTE1_p0_RxReplicaCtl04_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1200f, .value=0x1088 }, // DWC_DDRPHYA_DBYTE2_p0_RxReplicaCtl04_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x1300f, .value=0x1088 }, // DWC_DDRPHYA_DBYTE3_p0_RxReplicaCtl04_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90803, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BGPR3_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90804, .value=0x82 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BGPR4_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90805, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BGPR5_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90903, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_RtrnMode_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9090b, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_RtrnSeqStop_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90811, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BGPR17_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90812, .value=0xff00 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BGPR18_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20072, .value=0x1 }, // DWC_DDRPHYA_MASTER0_p0_HwtLpCsEnA
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9080e, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BGPR14_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20073, .value=0x1 }, // DWC_DDRPHYA_MASTER0_p0_HwtLpCsEnB
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9080f, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BGPR15_p0
    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x0 }, // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41000, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41001, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41002, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41003, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41004, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41005, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41006, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41007, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41388, .value=0x4028 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41389, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4138a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4138b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4138c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4138d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4138e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4138f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41390, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41391, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41392, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41393, .value=0x400 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41394, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41395, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41396, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41397, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41398, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41399, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4139a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4139b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4139c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4139d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4139e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4139f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413a0, .value=0x4858 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413a1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413a2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413a3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413a4, .value=0x6088 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413a5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413a6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413a7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413a8, .value=0x6038 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413a9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413aa, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413ab, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413ac, .value=0x4858 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413ad, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413ae, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413af, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413b0, .value=0x4088 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413b1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413b2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413b3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413b4, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413b5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413b6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413b7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413b8, .value=0x4028 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413b9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413ba, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413bb, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413bc, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413bd, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413be, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413bf, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413c0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413c1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413c2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413c3, .value=0x400 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413c4, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413c5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413c6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413c7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413c8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413c9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413ca, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413cb, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413cc, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413cd, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413ce, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413cf, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413d0, .value=0x4858 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413d1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413d2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413d3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413d4, .value=0x6208 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413d5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413d6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413d7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413d8, .value=0x6038 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413d9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413da, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413db, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413dc, .value=0x4858 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413dd, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413de, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413df, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413e0, .value=0x4208 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413e1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413e2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413e3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413e4, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413e5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413e6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413e7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413e8, .value=0x4e58 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413e9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413ea, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413eb, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413ec, .value=0x4208 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413ed, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413ee, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413ef, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413f0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413f1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413f2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413f3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413f4, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413f5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413f6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413f7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413f8, .value=0x4370 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413f9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413fa, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413fb, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413fc, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413fd, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413fe, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x413ff, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41400, .value=0x4040 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41401, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41402, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41403, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41404, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41405, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41406, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41407, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41408, .value=0x52d8 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41409, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4140a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4140b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4140c, .value=0x6008 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4140d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4140e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4140f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41410, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41411, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41412, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41413, .value=0x5b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41414, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41415, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41416, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41417, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41418, .value=0x40f0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41419, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4141a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4141b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4141c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4141d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4141e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4141f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41420, .value=0x4fd8 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41421, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41422, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41423, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41424, .value=0x4008 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41425, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41426, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41427, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41428, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41429, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4142a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4142b, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4142c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4142d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4142e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4142f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41430, .value=0x5058 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41431, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41432, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41433, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41434, .value=0x4008 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41435, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41436, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41437, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41438, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41439, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4143a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4143b, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4143c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4143d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4143e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4143f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41440, .value=0x50d8 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41441, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41442, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41443, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41444, .value=0x4088 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41445, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41446, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41447, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41448, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41449, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4144a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4144b, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4144c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4144d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4144e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4144f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41450, .value=0x5158 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41451, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41452, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41453, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41454, .value=0x4008 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41455, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41456, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41457, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41458, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41459, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4145a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4145b, .value=0x5b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4145c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4145d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4145e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4145f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41460, .value=0x402c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41461, .value=0xd00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41462, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41463, .value=0x400 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41464, .value=0x4050 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41465, .value=0x800 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41466, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41467, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41468, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41469, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4146a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4146b, .value=0x400 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4146c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4146d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4146e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4146f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41470, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41471, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41472, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41473, .value=0x400 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41474, .value=0x4050 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41475, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41476, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41477, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41478, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41479, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4147a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4147b, .value=0x7f00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4147c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4147d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4147e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4147f, .value=0x400 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41480, .value=0x407c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41481, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41482, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41483, .value=0x400 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41484, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41485, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41486, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41487, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41488, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41489, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4148a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4148b, .value=0x400 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4148c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4148d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4148e, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4148f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41490, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41491, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41492, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41493, .value=0x400 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41494, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41495, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41496, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41497, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41498, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41499, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4149a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4149b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4149c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4149d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4149e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4149f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414a0, .value=0x402c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414a1, .value=0xd00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414a2, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414a3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414a4, .value=0x4050 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414a5, .value=0x800 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414a6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414a7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414a8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414a9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414aa, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414ab, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414ac, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414ad, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414ae, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414af, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414b0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414b1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414b2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414b3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414b4, .value=0x4050 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414b5, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414b6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414b7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414b8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414b9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414ba, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414bb, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414bc, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414bd, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414be, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414bf, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414c0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414c1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414c2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414c3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414c4, .value=0x4050 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414c5, .value=0x800 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414c6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414c7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414c8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414c9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414ca, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414cb, .value=0x6b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414cc, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414cd, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414ce, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414cf, .value=0x400 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414d0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414d1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414d2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414d3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414d4, .value=0x407c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414d5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414d6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414d7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414d8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414d9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414da, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414db, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414dc, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414dd, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414de, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414df, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414e0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414e1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414e2, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414e3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414e4, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414e5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414e6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414e7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414e8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414e9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414ea, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414eb, .value=0x6b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414ec, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414ed, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414ee, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414ef, .value=0x2000 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414f0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414f1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414f2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414f3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414f4, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414f5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414f6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414f7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414f8, .value=0x402c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414f9, .value=0xd00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414fa, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414fb, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414fc, .value=0x5198 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414fd, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414fe, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x414ff, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41500, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41501, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41502, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41503, .value=0x3b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41504, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41505, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41506, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41507, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41508, .value=0x5218 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41509, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4150a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4150b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4150c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4150d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4150e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4150f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41510, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41511, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41512, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41513, .value=0x6b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41514, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41515, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41516, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41517, .value=0x400 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41518, .value=0x407c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41519, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4151a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4151b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4151c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4151d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4151e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4151f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41520, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41521, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41522, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41523, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41524, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41525, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41526, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41527, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41528, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41529, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4152a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4152b, .value=0x1b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4152c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4152d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4152e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4152f, .value=0x400 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41530, .value=0x401c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41531, .value=0xd0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41532, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41533, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41534, .value=0x4060 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41535, .value=0x84 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41536, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41537, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41538, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41539, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4153a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4153b, .value=0xb00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4153c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4153d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4153e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4153f, .value=0x800 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41540, .value=0x407c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41541, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41542, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41543, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41544, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41545, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41546, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41547, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41548, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41549, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4154a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4154b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4154c, .value=0x4000 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4154d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4154e, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4154f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41550, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41551, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41552, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41553, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41554, .value=0x402c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41555, .value=0xd00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41556, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41557, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41558, .value=0x4020 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41559, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4155a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4155b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4155c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4155d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4155e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4155f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41560, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41561, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41562, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41563, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41564, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41565, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41566, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41567, .value=0x800 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41568, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41569, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4156a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4156b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4156c, .value=0x407c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4156d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4156e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4156f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41570, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41571, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41572, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41573, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41574, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41575, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41576, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41577, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41578, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41579, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4157a, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4157b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4157c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4157d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4157e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4157f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41580, .value=0x801c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41581, .value=0xd0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41582, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41583, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41584, .value=0x8060 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41585, .value=0x84 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41586, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41587, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41588, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41589, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4158a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4158b, .value=0xb00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4158c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4158d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4158e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4158f, .value=0x800 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41590, .value=0x807c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41591, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41592, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41593, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41594, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41595, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41596, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41597, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41598, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41599, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4159a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4159b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4159c, .value=0x8000 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4159d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4159e, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4159f, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415a0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415a1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415a2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415a3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415a4, .value=0x802c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415a5, .value=0xd00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415a6, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415a7, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415a8, .value=0x8020 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415a9, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415aa, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415ab, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415ac, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415ad, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415ae, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415af, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415b0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415b1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415b2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415b3, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415b4, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415b5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415b6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415b7, .value=0x800 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415b8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415b9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415ba, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415bb, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415bc, .value=0x807c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415bd, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415be, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415bf, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415c0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415c1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415c2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415c3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415c4, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415c5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415c6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415c7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415c8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415c9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415ca, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415cb, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415cc, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415cd, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415ce, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415cf, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415d0, .value=0x402c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415d1, .value=0xd00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415d2, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415d3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415d4, .value=0x4050 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415d5, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415d6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415d7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415d8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415d9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415da, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415db, .value=0x1b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415dc, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415dd, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415de, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415df, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415e0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415e1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415e2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415e3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415e4, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415e5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415e6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415e7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415e8, .value=0x4050 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415e9, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415ea, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415eb, .value=0x5a00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415ec, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415ed, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415ee, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415ef, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415f0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415f1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415f2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415f3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415f4, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415f5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415f6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415f7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415f8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415f9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415fa, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415fb, .value=0x100 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415fc, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415fd, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415fe, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415ff, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41600, .value=0x4050 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41601, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41602, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41603, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41604, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41605, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41606, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41607, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41608, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41609, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4160a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4160b, .value=0x6b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4160c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4160d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4160e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4160f, .value=0x400 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41610, .value=0x407c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41611, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41612, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41613, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41614, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41615, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41616, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41617, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41618, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41619, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4161a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4161b, .value=0x3b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4161c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4161d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4161e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4161f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41620, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41621, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41622, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41623, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41624, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41625, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41626, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41627, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41628, .value=0x5758 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41629, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4162a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4162b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4162c, .value=0x4208 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4162d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4162e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4162f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41630, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41631, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41632, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41633, .value=0x4b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41634, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41635, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41636, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41637, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41638, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41639, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4163a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4163b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4163c, .value=0x401c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4163d, .value=0xd0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4163e, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4163f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41640, .value=0x4060 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41641, .value=0x84 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41642, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41643, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41644, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41645, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41646, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41647, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41648, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41649, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4164a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4164b, .value=0x7b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4164c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4164d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4164e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4164f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41650, .value=0x407c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41651, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41652, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41653, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41654, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41655, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41656, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41657, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41658, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41659, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4165a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4165b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4165c, .value=0x4000 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4165d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4165e, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4165f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41660, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41661, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41662, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41663, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41664, .value=0x402c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41665, .value=0xd00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41666, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41667, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41668, .value=0x4020 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41669, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4166a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4166b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4166c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4166d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4166e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4166f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41670, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41671, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41672, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41673, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41674, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41675, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41676, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41677, .value=0x800 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41678, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41679, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4167a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4167b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4167c, .value=0x407c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4167d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4167e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4167f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41680, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41681, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41682, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41683, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41684, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41685, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41686, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41687, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41688, .value=0x4000 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41689, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4168a, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4168b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4168c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4168d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4168e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4168f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41690, .value=0x5758 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41691, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41692, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41693, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41694, .value=0x4008 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41695, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41696, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41697, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41698, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41699, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4169a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4169b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4169c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4169d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4169e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4169f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416a0, .value=0x802c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416a1, .value=0xd00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416a2, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416a3, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416a4, .value=0x8050 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416a5, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416a6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416a7, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416a8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416a9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416aa, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416ab, .value=0x1b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416ac, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416ad, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416ae, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416af, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416b0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416b1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416b2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416b3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416b4, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416b5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416b6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416b7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416b8, .value=0x8050 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416b9, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416ba, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416bb, .value=0x5a10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416bc, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416bd, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416be, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416bf, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416c0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416c1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416c2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416c3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416c4, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416c5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416c6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416c7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416c8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416c9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416ca, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416cb, .value=0x100 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416cc, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416cd, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416ce, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416cf, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416d0, .value=0x8050 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416d1, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416d2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416d3, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416d4, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416d5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416d6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416d7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416d8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416d9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416da, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416db, .value=0x6b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416dc, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416dd, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416de, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416df, .value=0x400 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416e0, .value=0x807c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416e1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416e2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416e3, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416e4, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416e5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416e6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416e7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416e8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416e9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416ea, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416eb, .value=0x3b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416ec, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416ed, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416ee, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416ef, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416f0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416f1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416f2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416f3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416f4, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416f5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416f6, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416f7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416f8, .value=0x9758 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416f9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416fa, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416fb, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416fc, .value=0x8208 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416fd, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416fe, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x416ff, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41700, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41701, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41702, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41703, .value=0x4b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41704, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41705, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41706, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41707, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41708, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41709, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4170a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4170b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4170c, .value=0x801c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4170d, .value=0xd0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4170e, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4170f, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41710, .value=0x8060 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41711, .value=0x84 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41712, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41713, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41714, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41715, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41716, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41717, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41718, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41719, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4171a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4171b, .value=0x7b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4171c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4171d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4171e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4171f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41720, .value=0x807c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41721, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41722, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41723, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41724, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41725, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41726, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41727, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41728, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41729, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4172a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4172b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4172c, .value=0x8000 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4172d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4172e, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4172f, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41730, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41731, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41732, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41733, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41734, .value=0x802c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41735, .value=0xd00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41736, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41737, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41738, .value=0x8020 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41739, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4173a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4173b, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4173c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4173d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4173e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4173f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41740, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41741, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41742, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41743, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41744, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41745, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41746, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41747, .value=0x800 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41748, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41749, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4174a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4174b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4174c, .value=0x807c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4174d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4174e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4174f, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41750, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41751, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41752, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41753, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41754, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41755, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41756, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41757, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41758, .value=0x8000 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41759, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4175a, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4175b, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4175c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4175d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4175e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4175f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41760, .value=0x9758 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41761, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41762, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41763, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41764, .value=0x8008 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41765, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41766, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41767, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41768, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41769, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4176a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4176b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4176c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4176d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4176e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4176f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41770, .value=0x4068 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41771, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41772, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41773, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41774, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41775, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41776, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41777, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41778, .value=0x52d8 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41779, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4177a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4177b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4177c, .value=0x6008 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4177d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4177e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4177f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41780, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41781, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41782, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41783, .value=0x5b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41784, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41785, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41786, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41787, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41788, .value=0x40f0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41789, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4178a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4178b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4178c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4178d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4178e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4178f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41790, .value=0x4fd8 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41791, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41792, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41793, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41794, .value=0x4008 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41795, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41796, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41797, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41798, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41799, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4179a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4179b, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4179c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4179d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4179e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4179f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417a0, .value=0x5058 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417a1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417a2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417a3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417a4, .value=0x4008 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417a5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417a6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417a7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417a8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417a9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417aa, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417ab, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417ac, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417ad, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417ae, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417af, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417b0, .value=0x50d8 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417b1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417b2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417b3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417b4, .value=0x4088 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417b5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417b6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417b7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417b8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417b9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417ba, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417bb, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417bc, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417bd, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417be, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417bf, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417c0, .value=0x5158 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417c1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417c2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417c3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417c4, .value=0x4008 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417c5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417c6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417c7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417c8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417c9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417ca, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417cb, .value=0x5b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417cc, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417cd, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417ce, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417cf, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417d0, .value=0x402c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417d1, .value=0xd00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417d2, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417d3, .value=0x400 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417d4, .value=0x4050 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417d5, .value=0x800 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417d6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417d7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417d8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417d9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417da, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417db, .value=0x400 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417dc, .value=0x4050 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417dd, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417de, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417df, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417e0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417e1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417e2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417e3, .value=0x6f00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417e4, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417e5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417e6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417e7, .value=0x400 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417e8, .value=0x407c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417e9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417ea, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417eb, .value=0x400 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417ec, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417ed, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417ee, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417ef, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417f0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417f1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417f2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417f3, .value=0x400 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417f4, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417f5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417f6, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417f7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417f8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417f9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417fa, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417fb, .value=0x400 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417fc, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417fd, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417fe, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x417ff, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41800, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41801, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41802, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41803, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41804, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41805, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41806, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41807, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41808, .value=0x402c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41809, .value=0xd00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4180a, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4180b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4180c, .value=0x4050 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4180d, .value=0x800 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4180e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4180f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41810, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41811, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41812, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41813, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41814, .value=0x4050 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41815, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41816, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41817, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41818, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41819, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4181a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4181b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4181c, .value=0x4050 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4181d, .value=0x800 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4181e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4181f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41820, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41821, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41822, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41823, .value=0x4b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41824, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41825, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41826, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41827, .value=0x400 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41828, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41829, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4182a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4182b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4182c, .value=0x407c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4182d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4182e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4182f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41830, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41831, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41832, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41833, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41834, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41835, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41836, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41837, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41838, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41839, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4183a, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4183b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4183c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4183d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4183e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4183f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41840, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41841, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41842, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41843, .value=0x4b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41844, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41845, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41846, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41847, .value=0x2000 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41848, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41849, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4184a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4184b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4184c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4184d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4184e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4184f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41850, .value=0x402c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41851, .value=0xd00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41852, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41853, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41854, .value=0x5198 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41855, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41856, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41857, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41858, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41859, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4185a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4185b, .value=0x1b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4185c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4185d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4185e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4185f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41860, .value=0x5218 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41861, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41862, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41863, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41864, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41865, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41866, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41867, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41868, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41869, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4186a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4186b, .value=0x4b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4186c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4186d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4186e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4186f, .value=0x400 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41870, .value=0x407c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41871, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41872, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41873, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41874, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41875, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41876, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41877, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41878, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41879, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4187a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4187b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4187c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4187d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4187e, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4187f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41880, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41881, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41882, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41883, .value=0x1b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41884, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41885, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41886, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41887, .value=0x400 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41888, .value=0x401c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41889, .value=0xd0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4188a, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4188b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4188c, .value=0x4060 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4188d, .value=0x84 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4188e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4188f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41890, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41891, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41892, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41893, .value=0xb00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41894, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41895, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41896, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41897, .value=0x800 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41898, .value=0x407c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41899, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4189a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4189b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4189c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4189d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4189e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4189f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418a0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418a1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418a2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418a3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418a4, .value=0x4000 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418a5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418a6, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418a7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418a8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418a9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418aa, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418ab, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418ac, .value=0x402c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418ad, .value=0xd00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418ae, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418af, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418b0, .value=0x4020 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418b1, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418b2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418b3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418b4, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418b5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418b6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418b7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418b8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418b9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418ba, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418bb, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418bc, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418bd, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418be, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418bf, .value=0x800 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418c0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418c1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418c2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418c3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418c4, .value=0x407c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418c5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418c6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418c7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418c8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418c9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418ca, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418cb, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418cc, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418cd, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418ce, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418cf, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418d0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418d1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418d2, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418d3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418d4, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418d5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418d6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418d7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418d8, .value=0x801c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418d9, .value=0xd0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418da, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418db, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418dc, .value=0x8060 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418dd, .value=0x84 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418de, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418df, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418e0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418e1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418e2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418e3, .value=0xb00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418e4, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418e5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418e6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418e7, .value=0x800 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418e8, .value=0x807c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418e9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418ea, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418eb, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418ec, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418ed, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418ee, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418ef, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418f0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418f1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418f2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418f3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418f4, .value=0x8000 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418f5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418f6, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418f7, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418f8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418f9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418fa, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418fb, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418fc, .value=0x802c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418fd, .value=0xd00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418fe, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418ff, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41900, .value=0x8020 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41901, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41902, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41903, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41904, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41905, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41906, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41907, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41908, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41909, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4190a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4190b, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4190c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4190d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4190e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4190f, .value=0x800 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41910, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41911, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41912, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41913, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41914, .value=0x807c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41915, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41916, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41917, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41918, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41919, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4191a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4191b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4191c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4191d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4191e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4191f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41920, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41921, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41922, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41923, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41924, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41925, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41926, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41927, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41928, .value=0x402c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41929, .value=0xd00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4192a, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4192b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4192c, .value=0x4050 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4192d, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4192e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4192f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41930, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41931, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41932, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41933, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41934, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41935, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41936, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41937, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41938, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41939, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4193a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4193b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4193c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4193d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4193e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4193f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41940, .value=0x4050 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41941, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41942, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41943, .value=0x5a00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41944, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41945, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41946, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41947, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41948, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41949, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4194a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4194b, .value=0x100 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4194c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4194d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4194e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4194f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41950, .value=0x4050 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41951, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41952, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41953, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41954, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41955, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41956, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41957, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41958, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41959, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4195a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4195b, .value=0x4b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4195c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4195d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4195e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4195f, .value=0x400 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41960, .value=0x407c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41961, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41962, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41963, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41964, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41965, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41966, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41967, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41968, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41969, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4196a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4196b, .value=0x3b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4196c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4196d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4196e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4196f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41970, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41971, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41972, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41973, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41974, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41975, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41976, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41977, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41978, .value=0x5758 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41979, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4197a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4197b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4197c, .value=0x4208 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4197d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4197e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4197f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41980, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41981, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41982, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41983, .value=0x4b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41984, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41985, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41986, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41987, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41988, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41989, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4198a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4198b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4198c, .value=0x401c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4198d, .value=0xd0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4198e, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4198f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41990, .value=0x4060 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41991, .value=0x84 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41992, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41993, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41994, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41995, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41996, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41997, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41998, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41999, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4199a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4199b, .value=0x7b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4199c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4199d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4199e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4199f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419a0, .value=0x407c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419a1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419a2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419a3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419a4, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419a5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419a6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419a7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419a8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419a9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419aa, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419ab, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419ac, .value=0x4000 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419ad, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419ae, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419af, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419b0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419b1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419b2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419b3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419b4, .value=0x402c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419b5, .value=0xd00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419b6, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419b7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419b8, .value=0x4020 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419b9, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419ba, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419bb, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419bc, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419bd, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419be, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419bf, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419c0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419c1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419c2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419c3, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419c4, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419c5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419c6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419c7, .value=0x800 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419c8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419c9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419ca, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419cb, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419cc, .value=0x407c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419cd, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419ce, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419cf, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419d0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419d1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419d2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419d3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419d4, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419d5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419d6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419d7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419d8, .value=0x4000 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419d9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419da, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419db, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419dc, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419dd, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419de, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419df, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419e0, .value=0x5758 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419e1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419e2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419e3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419e4, .value=0x4008 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419e5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419e6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419e7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419e8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419e9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419ea, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419eb, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419ec, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419ed, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419ee, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419ef, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419f0, .value=0x802c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419f1, .value=0xd00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419f2, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419f3, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419f4, .value=0x8050 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419f5, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419f6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419f7, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419f8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419f9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419fa, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419fb, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419fc, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419fd, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419fe, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419ff, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a00, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a01, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a02, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a03, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a04, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a05, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a06, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a07, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a08, .value=0x8050 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a09, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a0a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a0b, .value=0x5a10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a0c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a0d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a0e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a0f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a10, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a11, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a12, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a13, .value=0x100 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a14, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a15, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a16, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a17, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a18, .value=0x8050 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a19, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a1a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a1b, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a1c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a1d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a1e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a1f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a20, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a21, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a22, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a23, .value=0x4b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a24, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a25, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a26, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a27, .value=0x400 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a28, .value=0x807c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a29, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a2a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a2b, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a2c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a2d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a2e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a2f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a30, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a31, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a32, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a33, .value=0x3b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a34, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a35, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a36, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a37, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a38, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a39, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a3a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a3b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a3c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a3d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a3e, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a3f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a40, .value=0x9758 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a41, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a42, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a43, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a44, .value=0x8208 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a45, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a46, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a47, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a48, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a49, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a4a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a4b, .value=0x4b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a4c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a4d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a4e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a4f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a50, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a51, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a52, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a53, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a54, .value=0x801c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a55, .value=0xd0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a56, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a57, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a58, .value=0x8060 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a59, .value=0x84 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a5a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a5b, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a5c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a5d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a5e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a5f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a60, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a61, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a62, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a63, .value=0x7b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a64, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a65, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a66, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a67, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a68, .value=0x807c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a69, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a6a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a6b, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a6c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a6d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a6e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a6f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a70, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a71, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a72, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a73, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a74, .value=0x8000 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a75, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a76, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a77, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a78, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a79, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a7a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a7b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a7c, .value=0x802c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a7d, .value=0xd00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a7e, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a7f, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a80, .value=0x8020 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a81, .value=0x803 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a82, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a83, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a84, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a85, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a86, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a87, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a88, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a89, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a8a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a8b, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a8c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a8d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a8e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a8f, .value=0x800 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a90, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a91, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a92, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a93, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a94, .value=0x807c }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a95, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a96, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a97, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a98, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a99, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a9a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a9b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a9c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a9d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a9e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a9f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41aa0, .value=0x8000 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41aa1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41aa2, .value=0x1 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41aa3, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41aa4, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41aa5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41aa6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41aa7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41aa8, .value=0x9758 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41aa9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41aaa, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41aab, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41aac, .value=0x8008 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41aad, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41aae, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41aaf, .value=0x10 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41ab0, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41ab1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41ab2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41ab3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41ab4, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41ab5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41ab6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41ab7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41ab8, .value=0x4068 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41ab9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41aba, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41abb, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41abc, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41abd, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41abe, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41abf, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9002e, .value=0x10 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b0s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9002f, .value=0x400 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b0s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90030, .value=0x80e }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b0s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90031, .value=0xb }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b1s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90032, .value=0x480 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b1s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90033, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b1s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90034, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b2s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90035, .value=0x308 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b2s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90036, .value=0xc09 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b2s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90037, .value=0x28 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b3s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90038, .value=0x8160 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b3s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90039, .value=0x87c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b3s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9003a, .value=0x98 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b4s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9003b, .value=0x820 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b4s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9003c, .value=0xc7e }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b4s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9003d, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b5s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9003e, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b5s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9003f, .value=0x78 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b5s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90040, .value=0xa }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b6s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90041, .value=0x370 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b6s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90042, .value=0x839 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b6s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90043, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b7s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90044, .value=0x8160 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b7s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90045, .value=0x83c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b7s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90046, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b8s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90047, .value=0x150 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b8s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90048, .value=0x839 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b8s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90049, .value=0x70 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b9s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9004a, .value=0x392 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b9s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9004b, .value=0x39 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b9s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9004c, .value=0x78 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b10s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9004d, .value=0x39a }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b10s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9004e, .value=0x39 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b10s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9004f, .value=0xe09 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b11s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90050, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b11s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90051, .value=0x839 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b11s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90052, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b12s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90053, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b12s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90054, .value=0x38 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b12s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90055, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b13s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90056, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b13s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90057, .value=0x839 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b13s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90058, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b14s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90059, .value=0x398 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b14s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9005a, .value=0x839 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b14s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9005b, .value=0xe19 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b15s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9005c, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b15s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9005d, .value=0x839 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b15s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9005e, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b16s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9005f, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b16s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90060, .value=0x38 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b16s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90061, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b17s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90062, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b17s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90063, .value=0x839 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b17s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90064, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b18s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90065, .value=0x390 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b18s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90066, .value=0x839 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b18s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90067, .value=0x78 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b19s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90068, .value=0x39a }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b19s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90069, .value=0x39 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b19s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9006a, .value=0xe29 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b20s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9006b, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b20s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9006c, .value=0x839 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b20s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9006d, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b21s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9006e, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b21s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9006f, .value=0x38 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b21s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90070, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b22s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90071, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b22s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90072, .value=0x839 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b22s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90073, .value=0x70 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b23s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90074, .value=0x392 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b23s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90075, .value=0x39 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b23s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90076, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b24s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90077, .value=0xf0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b24s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90078, .value=0x909 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b24s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90079, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b25s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9007a, .value=0x8160 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b25s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9007b, .value=0x8bc }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b25s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9007c, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b26s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9007d, .value=0x13a }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b26s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9007e, .value=0xb9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b26s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9007f, .value=0x24b }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b27s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90080, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b27s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90081, .value=0x8b9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b27s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90082, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b28s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90083, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b28s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90084, .value=0xb8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b28s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90085, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b29s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90086, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b29s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90087, .value=0x8b9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b29s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90088, .value=0x20 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b30s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90089, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b30s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9008a, .value=0xb8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b30s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9008b, .value=0x20 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b31s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9008c, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b31s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9008d, .value=0xb8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b31s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9008e, .value=0x5 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b32s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9008f, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b32s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90090, .value=0xb8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b32s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90091, .value=0x479 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b33s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90092, .value=0xc7f8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b33s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90093, .value=0x8bc }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b33s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90094, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b34s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90095, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b34s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90096, .value=0xb8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b34s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90097, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b35s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90098, .value=0xa8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b35s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90099, .value=0x8b9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b35s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9009a, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b36s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9009b, .value=0xc9c0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b36s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9009c, .value=0xcbc }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b36s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9009d, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b37s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9009e, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b37s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9009f, .value=0xb8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b37s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900a0, .value=0x25b }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b38s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900a1, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b38s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900a2, .value=0xcb9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b38s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900a3, .value=0x20 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b39s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900a4, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b39s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900a5, .value=0xb8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b39s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900a6, .value=0x20 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b40s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900a7, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b40s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900a8, .value=0xb8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b40s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900a9, .value=0x20 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b41s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900aa, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b41s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900ab, .value=0xb8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b41s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900ac, .value=0x20 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b42s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900ad, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b42s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900ae, .value=0xb8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b42s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900af, .value=0x10 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b43s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900b0, .value=0x400 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b43s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900b1, .value=0x89e }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b43s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900b2, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b44s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900b3, .value=0x370 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b44s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900b4, .value=0x839 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b44s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900b5, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b45s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900b6, .value=0xf0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b45s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900b7, .value=0x909 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b45s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900b8, .value=0x33b }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b46s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900b9, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b46s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900ba, .value=0x8b9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b46s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900bb, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b47s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900bc, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b47s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900bd, .value=0x8b9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b47s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900be, .value=0x23b }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b48s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900bf, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b48s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900c0, .value=0xc99 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b48s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900c1, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b49s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900c2, .value=0x150 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b49s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900c3, .value=0x839 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b49s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900c4, .value=0x1800 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b50s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900c5, .value=0x8660 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b50s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900c6, .value=0x839 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b50s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900c7, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b51s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900c8, .value=0x2a0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b51s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900c9, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b51s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900ca, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b52s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900cb, .value=0x1880 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b52s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900cc, .value=0x839 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b52s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900cd, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b53s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900ce, .value=0x82b0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b53s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900cf, .value=0x838 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b53s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900d0, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b54s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900d1, .value=0xe0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b54s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900d2, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b54s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900d3, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b55s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900d4, .value=0xe0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b55s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900d5, .value=0x869 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b55s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900d6, .value=0xf }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b56s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900d7, .value=0x7c0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b56s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900d8, .value=0x839 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b56s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900d9, .value=0xa }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b57s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900da, .value=0x510 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b57s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900db, .value=0x839 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b57s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900dc, .value=0xa }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b58s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900dd, .value=0x700 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b58s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900de, .value=0x849 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b58s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900df, .value=0xa }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b59s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900e0, .value=0x700 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b59s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900e1, .value=0x859 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b59s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900e2, .value=0xa }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b60s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900e3, .value=0x708 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b60s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900e4, .value=0x859 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b60s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900e5, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b61s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900e6, .value=0x708 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b61s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900e7, .value=0x849 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b61s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900e8, .value=0xff8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b62s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900e9, .value=0x8410 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b62s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900ea, .value=0x839 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b62s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900eb, .value=0x7ff8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b63s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900ec, .value=0x8498 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b63s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900ed, .value=0x838 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b63s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900ee, .value=0x10 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b64s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900ef, .value=0x8160 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b64s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900f0, .value=0x83c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b64s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900f1, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b65s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900f2, .value=0x7c8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b65s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900f3, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b65s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900f4, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b66s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900f5, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b66s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900f6, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b66s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900f7, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b67s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900f8, .value=0x45a }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b67s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900f9, .value=0x89 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b67s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900fa, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b68s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900fb, .value=0x8018 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b68s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900fc, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b68s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900fd, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b69s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900fe, .value=0x8020 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b69s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x900ff, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b69s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90100, .value=0x479 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b70s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90101, .value=0xc7f8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b70s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90102, .value=0x80c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b70s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90103, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b71s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90104, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b71s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90105, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b71s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90106, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b72s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90107, .value=0x8018 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b72s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90108, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b72s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90109, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b73s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9010a, .value=0x8020 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b73s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9010b, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b73s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9010c, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b74s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9010d, .value=0xc9c0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b74s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9010e, .value=0xc0c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b74s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9010f, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b75s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90110, .value=0xa8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b75s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90111, .value=0x8c9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b75s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90112, .value=0x29 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b76s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90113, .value=0x8160 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b76s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90114, .value=0x87c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b76s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90115, .value=0xb8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b77s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90116, .value=0x820 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b77s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90117, .value=0xc7e }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b77s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90118, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b78s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90119, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b78s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9011a, .value=0x78 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b78s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9011b, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b79s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9011c, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b79s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9011d, .value=0x78 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b79s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9011e, .value=0xd8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b80s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9011f, .value=0x820 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b80s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90120, .value=0xc7e }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b80s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90121, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b81s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90122, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b81s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90123, .value=0x78 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b81s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90124, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b82s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90125, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b82s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90126, .value=0x78 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b82s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90127, .value=0xf8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b83s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90128, .value=0x820 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b83s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90129, .value=0xc7e }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b83s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9012a, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b84s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9012b, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b84s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9012c, .value=0x78 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b84s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9012d, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b85s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9012e, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b85s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9012f, .value=0x78 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b85s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90130, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b86s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90131, .value=0x700 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b86s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90132, .value=0x849 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b86s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90133, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b87s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90134, .value=0x618 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b87s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90135, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b87s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90136, .value=0x3ff8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b88s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90137, .value=0x84b8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b88s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90138, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b88s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90139, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b89s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9013a, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b89s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9013b, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b89s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9013c, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b90s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9013d, .value=0xc870 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b90s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9013e, .value=0xc0c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b90s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9013f, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b91s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90140, .value=0x710 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b91s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90141, .value=0x849 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b91s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90142, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b92s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90143, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b92s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90144, .value=0x48 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b92s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90145, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b93s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90146, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b93s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90147, .value=0x48 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b93s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90148, .value=0x10 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b94s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90149, .value=0x710 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b94s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9014a, .value=0x849 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b94s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9014b, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b95s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9014c, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b95s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9014d, .value=0x48 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b95s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9014e, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b96s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9014f, .value=0x710 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b96s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90150, .value=0x849 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b96s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90151, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b97s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90152, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b97s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90153, .value=0x48 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b97s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90154, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b98s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90155, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b98s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90156, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b98s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90157, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b99s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90158, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b99s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90159, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b99s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9015a, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b100s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9015b, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b100s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9015c, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b100s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9015d, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b101s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9015e, .value=0x8410 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b101s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9015f, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b101s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90160, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b102s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90161, .value=0x8498 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b102s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90162, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b102s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90163, .value=0x5 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b103s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90164, .value=0x510 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b103s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90165, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b103s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90166, .value=0x198 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b104s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90167, .value=0x1000 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b104s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90168, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b104s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90169, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b105s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9016a, .value=0x3c0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b105s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9016b, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b105s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9016c, .value=0x10 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b106s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9016d, .value=0x510 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b106s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9016e, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b106s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9016f, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b107s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90170, .value=0x3c0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b107s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90171, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b107s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90172, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b108s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90173, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b108s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90174, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b108s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90175, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b109s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90176, .value=0x510 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b109s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90177, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b109s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90178, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b110s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90179, .value=0x1000 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b110s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9017a, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b110s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9017b, .value=0x68 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b111s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9017c, .value=0x801a }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b111s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9017d, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b111s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9017e, .value=0x68 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b112s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9017f, .value=0x8022 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b112s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90180, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b112s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90181, .value=0x479 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b113s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90182, .value=0xc7f8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b113s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90183, .value=0x80c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b113s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90184, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b114s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90185, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b114s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90186, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b114s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90187, .value=0x68 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b115s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90188, .value=0x801a }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b115s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90189, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b115s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9018a, .value=0x68 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b116s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9018b, .value=0x8022 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b116s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9018c, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b116s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9018d, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b117s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9018e, .value=0xc9c0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b117s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9018f, .value=0xc0c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b117s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90190, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b118s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90191, .value=0xc870 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b118s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90192, .value=0xc0c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b118s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90193, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b119s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90194, .value=0x2a0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b119s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90195, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b119s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90196, .value=0x10 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b120s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90197, .value=0x8160 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b120s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90198, .value=0x89c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b120s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90199, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b121s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9019a, .value=0x7c8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b121s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9019b, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b121s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9019c, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b122s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9019d, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b122s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9019e, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b122s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9019f, .value=0x40 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b123s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901a0, .value=0x1932 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b123s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901a1, .value=0x129 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b123s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901a2, .value=0xa }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b124s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901a3, .value=0xc140 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b124s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901a4, .value=0x80c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b124s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901a5, .value=0x98 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b125s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901a6, .value=0x193a }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b125s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901a7, .value=0x129 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b125s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901a8, .value=0x90 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b126s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901a9, .value=0x1932 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b126s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901aa, .value=0x329 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b126s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901ab, .value=0x90 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b127s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901ac, .value=0x193a }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b127s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901ad, .value=0x329 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b127s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901ae, .value=0x88 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b128s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901af, .value=0x1882 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b128s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901b0, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b128s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901b1, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b129s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901b2, .value=0xc140 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b129s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901b3, .value=0x80c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b129s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901b4, .value=0x10 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b130s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901b5, .value=0x400 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b130s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901b6, .value=0x80e }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b130s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901b7, .value=0xb }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b131s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901b8, .value=0x370 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b131s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901b9, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b131s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901ba, .value=0x23b }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b132s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901bb, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b132s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901bc, .value=0xcf9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b132s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901bd, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b133s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901be, .value=0x2a0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b133s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901bf, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b133s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901c0, .value=0x7800 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b134s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901c1, .value=0x8660 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b134s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901c2, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b134s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901c3, .value=0xd }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b135s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901c4, .value=0x7c0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b135s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901c5, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b135s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901c6, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b136s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901c7, .value=0x82b0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b136s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901c8, .value=0x818 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b136s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901c9, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b137s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901ca, .value=0x82b0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b137s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901cb, .value=0x868 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b137s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901cc, .value=0x479 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b138s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901cd, .value=0xc7f8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b138s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901ce, .value=0x91c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b138s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901cf, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b139s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901d0, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b139s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901d1, .value=0x118 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b139s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901d2, .value=0x38 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b140s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901d3, .value=0x80a2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b140s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901d4, .value=0x118 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b140s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901d5, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b141s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901d6, .value=0xc9c0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b141s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901d7, .value=0xd1c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b141s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901d8, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b142s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901d9, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b142s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901da, .value=0x118 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b142s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901db, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b143s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901dc, .value=0x508 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b143s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901dd, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b143s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901de, .value=0x5 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b144s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901df, .value=0x7c0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b144s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901e0, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b144s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901e1, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b145s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901e2, .value=0x82b0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b145s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901e3, .value=0x868 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b145s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901e4, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b146s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901e5, .value=0x82b0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b146s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901e6, .value=0x818 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b146s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901e7, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b147s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901e8, .value=0x82b0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b147s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901e9, .value=0x888 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b147s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901ea, .value=0x10 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b148s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901eb, .value=0x510 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b148s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901ec, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b148s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901ed, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b149s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901ee, .value=0xa8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b149s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901ef, .value=0x8c9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b149s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901f0, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b150s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901f1, .value=0x1900 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b150s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901f2, .value=0xc09 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b150s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901f3, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b151s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901f4, .value=0x508 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b151s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901f5, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b151s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901f6, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b152s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901f7, .value=0x7c8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b152s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901f8, .value=0x829 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b152s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901f9, .value=0xa }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b153s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901fa, .value=0x3c8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b153s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901fb, .value=0xc29 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b153s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901fc, .value=0x89 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b154s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901fd, .value=0x3d0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b154s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901fe, .value=0xc19 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b154s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x901ff, .value=0x3 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b155s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90200, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b155s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90201, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b155s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90202, .value=0x38 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b156s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90203, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b156s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90204, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b156s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90205, .value=0x89 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b157s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90206, .value=0x3d0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b157s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90207, .value=0xc09 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b157s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90208, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b158s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90209, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b158s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9020a, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b158s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9020b, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b159s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9020c, .value=0x150 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b159s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9020d, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b159s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9020e, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b160s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9020f, .value=0xc800 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b160s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90210, .value=0xc0c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b160s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90211, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b161s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90212, .value=0x8160 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b161s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90213, .value=0x8cc }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b161s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90214, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b162s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90215, .value=0x13a }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b162s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90216, .value=0xc9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b162s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90217, .value=0x24b }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b163s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90218, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b163s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90219, .value=0x8c9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b163s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9021a, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b164s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9021b, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b164s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9021c, .value=0xc8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b164s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9021d, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b165s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9021e, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b165s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9021f, .value=0x8c9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b165s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90220, .value=0x20 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b166s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90221, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b166s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90222, .value=0xc8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b166s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90223, .value=0x20 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b167s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90224, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b167s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90225, .value=0xc8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b167s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90226, .value=0x5 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b168s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90227, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b168s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90228, .value=0xc8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b168s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90229, .value=0x479 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b169s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9022a, .value=0xc7f8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b169s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9022b, .value=0x8cc }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b169s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9022c, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b170s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9022d, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b170s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9022e, .value=0xc8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b170s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9022f, .value=0x30 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b171s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90230, .value=0xaa }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b171s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90231, .value=0xc9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b171s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90232, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b172s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90233, .value=0xc9c0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b172s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90234, .value=0xccc }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b172s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90235, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b173s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90236, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b173s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90237, .value=0xc8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b173s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90238, .value=0x479 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b174s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90239, .value=0xc7f8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b174s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9023a, .value=0x8bc }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b174s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9023b, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b175s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9023c, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b175s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9023d, .value=0xb8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b175s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9023e, .value=0x30 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b176s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9023f, .value=0xaa }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b176s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90240, .value=0xb9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b176s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90241, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b177s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90242, .value=0xc9c0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b177s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90243, .value=0xcbc }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b177s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90244, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b178s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90245, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b178s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90246, .value=0xb8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b178s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90247, .value=0x25b }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b179s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90248, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b179s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90249, .value=0xcc9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b179s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9024a, .value=0x20 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b180s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9024b, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b180s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9024c, .value=0xc8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b180s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9024d, .value=0x20 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b181s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9024e, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b181s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9024f, .value=0xc8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b181s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90250, .value=0x20 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b182s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90251, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b182s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90252, .value=0xa8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b182s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90253, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b183s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90254, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b183s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90255, .value=0xc8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b183s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90256, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b184s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90257, .value=0xc800 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b184s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90258, .value=0xc6c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b184s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90259, .value=0x26f }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b185s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9025a, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b185s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9025b, .value=0xc19 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b185s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9025c, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b186s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9025d, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b186s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9025e, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b186s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9025f, .value=0x27f }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b187s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90260, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b187s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90261, .value=0xc19 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b187s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90262, .value=0x479 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b188s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90263, .value=0xc7f8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b188s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90264, .value=0x80c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b188s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90265, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b189s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90266, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b189s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90267, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b189s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90268, .value=0x58 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b190s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90269, .value=0x8a }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b190s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9026a, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b190s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9026b, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b191s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9026c, .value=0xc9c0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b191s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9026d, .value=0xc0c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b191s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9026e, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b192s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9026f, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b192s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90270, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b192s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90271, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b193s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90272, .value=0x8160 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b193s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90273, .value=0x86c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b193s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90274, .value=0x1008 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b194s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90275, .value=0x853b }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b194s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90276, .value=0x868 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b194s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90277, .value=0xc00 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b195s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90278, .value=0x8588 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b195s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90279, .value=0x868 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b195s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9027a, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b196s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9027b, .value=0x85a8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b196s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9027c, .value=0x868 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b196s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9027d, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b197s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9027e, .value=0x85c8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b197s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9027f, .value=0x868 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b197s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90280, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b198s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90281, .value=0x8050 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b198s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90282, .value=0x868 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b198s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90283, .value=0x60 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b199s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90284, .value=0x138 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b199s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90285, .value=0x869 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b199s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90286, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b200s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90287, .value=0x8510 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b200s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90288, .value=0x868 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b200s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90289, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b201s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9028a, .value=0x2c8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b201s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9028b, .value=0x869 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b201s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9028c, .value=0x10 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b202s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9028d, .value=0x8520 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b202s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9028e, .value=0x868 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b202s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9028f, .value=0x1ff8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b203s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90290, .value=0x85d8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b203s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90291, .value=0xc68 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b203s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90292, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b204s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90293, .value=0xfdf0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b204s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90294, .value=0x868 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b204s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90295, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b205s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90296, .value=0x85f0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b205s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90297, .value=0x868 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b205s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90298, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b206s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90299, .value=0xa5f0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b206s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9029a, .value=0x868 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b206s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9029b, .value=0x298 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b207s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9029c, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b207s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9029d, .value=0x869 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b207s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9029e, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b208s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9029f, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b208s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902a0, .value=0x68 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b208s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902a1, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b209s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902a2, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b209s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902a3, .value=0x869 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b209s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902a4, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b210s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902a5, .value=0x85f0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b210s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902a6, .value=0x868 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b210s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902a7, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b211s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902a8, .value=0xa5f0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b211s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902a9, .value=0x868 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b211s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902aa, .value=0x33b }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b212s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902ab, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b212s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902ac, .value=0x8c9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b212s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902ad, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b213s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902ae, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b213s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902af, .value=0x8c9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b213s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902b0, .value=0x10 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b214s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902b1, .value=0x2c8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b214s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902b2, .value=0x869 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b214s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902b3, .value=0x28 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b215s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902b4, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b215s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902b5, .value=0x68 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b215s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902b6, .value=0xa }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b216s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902b7, .value=0x500 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b216s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902b8, .value=0xc69 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b216s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902b9, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b217s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902ba, .value=0x8520 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b217s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902bb, .value=0x868 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b217s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902bc, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b218s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902bd, .value=0x8530 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b218s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902be, .value=0x868 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b218s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902bf, .value=0x2ba }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b219s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902c0, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b219s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902c1, .value=0x869 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b219s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902c2, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b220s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902c3, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b220s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902c4, .value=0x68 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b220s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902c5, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b221s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902c6, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b221s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902c7, .value=0x869 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b221s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902c8, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b222s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902c9, .value=0x8530 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b222s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902ca, .value=0x868 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b222s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902cb, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b223s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902cc, .value=0x8510 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b223s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902cd, .value=0x868 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b223s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902ce, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b224s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902cf, .value=0x2c8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b224s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902d0, .value=0x869 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b224s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902d1, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b225s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902d2, .value=0x8050 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b225s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902d3, .value=0x868 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b225s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902d4, .value=0x30 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b226s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902d5, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b226s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902d6, .value=0x68 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b226s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902d7, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b227s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902d8, .value=0x8520 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b227s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902d9, .value=0x868 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b227s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902da, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b228s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902db, .value=0x8328 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b228s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902dc, .value=0x86b }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b228s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902dd, .value=0x2ca }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b229s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902de, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b229s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902df, .value=0x869 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b229s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902e0, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b230s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902e1, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b230s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902e2, .value=0x68 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b230s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902e3, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b231s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902e4, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b231s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902e5, .value=0x869 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b231s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902e6, .value=0xff8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b232s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902e7, .value=0x8328 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b232s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902e8, .value=0x86b }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b232s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902e9, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b233s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902ea, .value=0x500 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b233s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902eb, .value=0xc29 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b233s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902ec, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b234s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902ed, .value=0x8520 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b234s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902ee, .value=0x868 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b234s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902ef, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b235s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902f0, .value=0x3c8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b235s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902f1, .value=0xc29 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b235s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902f2, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b236s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902f3, .value=0x150 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b236s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902f4, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b236s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902f5, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b237s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902f6, .value=0x370 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b237s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902f7, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b237s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902f8, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b238s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902f9, .value=0x400 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b238s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902fa, .value=0x80e }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b238s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902fb, .value=0x10 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b239s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902fc, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b239s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902fd, .value=0x118 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b239s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902fe, .value=0x20 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b240s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x902ff, .value=0x82b0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b240s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90300, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b240s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90301, .value=0x479 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b241s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90302, .value=0xc7f8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b241s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90303, .value=0x80c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b241s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90304, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b242s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90305, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b242s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90306, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b242s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90307, .value=0x60 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b243s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90308, .value=0x8a }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b243s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90309, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b243s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9030a, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b244s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9030b, .value=0xc9c0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b244s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9030c, .value=0xc0c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b244s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9030d, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b245s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9030e, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b245s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9030f, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b245s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90310, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b246s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90311, .value=0x2a0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b246s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90312, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b246s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90313, .value=0x48 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b247s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90314, .value=0xc822 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b247s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90315, .value=0xc }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b247s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90316, .value=0x48 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b248s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90317, .value=0xcc32 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b248s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90318, .value=0xc }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b248s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90319, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b249s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9031a, .value=0xc800 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b249s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9031b, .value=0xc0c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b249s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9031c, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b250s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9031d, .value=0x8168 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b250s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9031e, .value=0x80c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b250s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9031f, .value=0x479 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b251s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90320, .value=0xc7f8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b251s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90321, .value=0x91c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b251s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90322, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b252s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90323, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b252s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90324, .value=0x118 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b252s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90325, .value=0x9190 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b253s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90326, .value=0x80a1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b253s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90327, .value=0x918 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b253s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90328, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b254s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90329, .value=0xc9c0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b254s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9032a, .value=0xd1c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b254s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9032b, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b255s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9032c, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b255s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9032d, .value=0x118 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b255s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9032e, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b256s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9032f, .value=0xf0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b256s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90330, .value=0x909 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b256s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90331, .value=0xa }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b257s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90332, .value=0xc140 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b257s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90333, .value=0x92c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b257s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90334, .value=0x88 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b258s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90335, .value=0x1932 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b258s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90336, .value=0x129 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b258s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90337, .value=0x88 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b259s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90338, .value=0x193a }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b259s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90339, .value=0x129 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b259s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9033a, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b260s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9033b, .value=0xc140 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b260s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9033c, .value=0x92c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b260s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9033d, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b261s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9033e, .value=0x300 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b261s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9033f, .value=0x819 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b261s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90340, .value=0x10 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b262s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90341, .value=0x8160 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b262s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90342, .value=0x80c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b262s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90343, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b263s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90344, .value=0x7c8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b263s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90345, .value=0x801 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b263s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90346, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b264s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90347, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b264s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90348, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b264s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90349, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b265s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9034a, .value=0x1880 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b265s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9034b, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b265s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9034c, .value=0x10 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b266s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9034d, .value=0x8160 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b266s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9034e, .value=0x80c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b266s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9034f, .value=0x1800 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b267s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90350, .value=0x8660 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b267s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90351, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b267s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90352, .value=0x4000 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b268s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90353, .value=0x8668 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b268s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90354, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b268s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90355, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b269s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90356, .value=0xf0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b269s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90357, .value=0x909 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b269s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90358, .value=0xf }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b270s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90359, .value=0x7c0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b270s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9035a, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b270s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9035b, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b271s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9035c, .value=0x2a0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b271s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9035d, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b271s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9035e, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b272s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9035f, .value=0x618 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b272s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90360, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b272s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90361, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b273s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90362, .value=0x84b8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b273s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90363, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b273s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90364, .value=0xff8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b274s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90365, .value=0x8410 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b274s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90366, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b274s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90367, .value=0x7ff8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b275s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90368, .value=0x8498 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b275s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90369, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b275s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9036a, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b276s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9036b, .value=0x7c8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b276s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9036c, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b276s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9036d, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b277s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9036e, .value=0x8168 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b277s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9036f, .value=0x80c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b277s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90370, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b278s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90371, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b278s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90372, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b278s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90373, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b279s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90374, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b279s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90375, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b279s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90376, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b280s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90377, .value=0x4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b280s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90378, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b280s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90379, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b281s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9037a, .value=0x300 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b281s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9037b, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b281s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9037c, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b282s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9037d, .value=0x480 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b282s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9037e, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b282s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9037f, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b283s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90380, .value=0x510 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b283s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90381, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b283s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90382, .value=0x7800 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b284s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90383, .value=0x8660 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b284s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90384, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b284s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90385, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b285s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90386, .value=0xf0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b285s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90387, .value=0x909 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b285s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90388, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b286s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90389, .value=0x7c8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b286s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9038a, .value=0x801 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b286s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9038b, .value=0x10 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b287s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9038c, .value=0x400 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b287s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9038d, .value=0x80e }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b287s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9038e, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b288s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9038f, .value=0x150 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b288s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90390, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b288s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90391, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b289s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90392, .value=0x370 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b289s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90393, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b289s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90394, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b290s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90395, .value=0x8160 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b290s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90396, .value=0x80c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b290s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90397, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b291s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90398, .value=0xc800 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b291s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90399, .value=0xc0c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b291s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9039a, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b292s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9039b, .value=0xc888 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b292s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9039c, .value=0xc04 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b292s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9039d, .value=0x20 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b293s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9039e, .value=0x8302 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b293s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9039f, .value=0xb }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b293s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903a0, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b294s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903a1, .value=0x8582 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b294s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903a2, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b294s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903a3, .value=0x9000 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b295s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903a4, .value=0x8539 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b295s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903a5, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b295s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903a6, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b296s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903a7, .value=0x8588 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b296s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903a8, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b296s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903a9, .value=0x40 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b297s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903aa, .value=0x85c8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b297s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903ab, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b297s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903ac, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b298s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903ad, .value=0xfdf0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b298s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903ae, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b298s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903af, .value=0x800 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b299s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903b0, .value=0xc5f0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b299s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903b1, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b299s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903b2, .value=0x1ff8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b300s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903b3, .value=0xfdd8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b300s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903b4, .value=0xc08 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b300s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903b5, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b301s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903b6, .value=0xfda8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b301s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903b7, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b301s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903b8, .value=0x40 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b302s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903b9, .value=0x8520 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b302s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903ba, .value=0x8d8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b302s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903bb, .value=0x80 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b303s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903bc, .value=0x8520 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b303s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903bd, .value=0x8e8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b303s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903be, .value=0x30a }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b304s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903bf, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b304s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903c0, .value=0x8d9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b304s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903c1, .value=0x32a }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b305s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903c2, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b305s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903c3, .value=0x8e9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b305s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903c4, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b306s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903c5, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b306s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903c6, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b306s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903c7, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b307s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903c8, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b307s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903c9, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b307s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903ca, .value=0x1ff8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b308s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903cb, .value=0xfdd8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b308s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903cc, .value=0xc08 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b308s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903cd, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b309s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903ce, .value=0xfda8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b309s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903cf, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b309s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903d0, .value=0x140 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b310s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903d1, .value=0x8520 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b310s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903d2, .value=0x8d8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b310s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903d3, .value=0x180 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b311s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903d4, .value=0x8520 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b311s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903d5, .value=0x8e8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b311s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903d6, .value=0x30a }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b312s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903d7, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b312s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903d8, .value=0x8d9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b312s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903d9, .value=0x32a }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b313s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903da, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b313s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903db, .value=0x8e9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b313s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903dc, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b314s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903dd, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b314s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903de, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b314s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903df, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b315s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903e0, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b315s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903e1, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b315s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903e2, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b316s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903e3, .value=0x500 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b316s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903e4, .value=0xc09 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b316s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903e5, .value=0x10 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b317s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903e6, .value=0x82b0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b317s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903e7, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b317s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903e8, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b318s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903e9, .value=0x8520 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b318s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903ea, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b318s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903eb, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b319s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903ec, .value=0x3c8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b319s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903ed, .value=0xc09 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b319s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903ee, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b320s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903ef, .value=0x150 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b320s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903f0, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b320s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903f1, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b321s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903f2, .value=0x370 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b321s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903f3, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b321s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903f4, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b322s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903f5, .value=0x400 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b322s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903f6, .value=0x80e }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b322s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903f7, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b323s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903f8, .value=0xc848 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b323s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903f9, .value=0xc0c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b323s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903fa, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b324s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903fb, .value=0xc890 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b324s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903fc, .value=0x804 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b324s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903fd, .value=0x20 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b325s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903fe, .value=0x8302 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b325s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x903ff, .value=0xb }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b325s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90400, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b326s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90401, .value=0x8582 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b326s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90402, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b326s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90403, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b327s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90404, .value=0x82b0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b327s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90405, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b327s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90406, .value=0x1000 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b328s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90407, .value=0x8539 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b328s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90408, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b328s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90409, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b329s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9040a, .value=0x8588 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b329s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9040b, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b329s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9040c, .value=0x40 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b330s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9040d, .value=0x85c8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b330s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9040e, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b330s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9040f, .value=0x7f8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b331s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90410, .value=0xfdf0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b331s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90411, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b331s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90412, .value=0x800 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b332s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90413, .value=0xc5f0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b332s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90414, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b332s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90415, .value=0x80 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b333s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90416, .value=0x8088 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b333s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90417, .value=0x80b }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b333s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90418, .value=0x1ff8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b334s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90419, .value=0xfdd8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b334s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9041a, .value=0xc08 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b334s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9041b, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b335s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9041c, .value=0xfda8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b335s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9041d, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b335s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9041e, .value=0x200 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b336s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9041f, .value=0x8520 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b336s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90420, .value=0x8d8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b336s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90421, .value=0x400 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b337s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90422, .value=0x8520 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b337s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90423, .value=0x8e8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b337s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90424, .value=0x2da }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b338s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90425, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b338s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90426, .value=0x8d9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b338s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90427, .value=0x2ea }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b339s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90428, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b339s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90429, .value=0x8e9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b339s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9042a, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b340s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9042b, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b340s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9042c, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b340s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9042d, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b341s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9042e, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b341s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9042f, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b341s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90430, .value=0x1ff8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b342s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90431, .value=0xfdd8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b342s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90432, .value=0xc08 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b342s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90433, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b343s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90434, .value=0xfda8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b343s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90435, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b343s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90436, .value=0xa00 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b344s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90437, .value=0x8520 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b344s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90438, .value=0x8d8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b344s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90439, .value=0xc00 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b345s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9043a, .value=0x8520 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b345s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9043b, .value=0x8e8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b345s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9043c, .value=0x2da }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b346s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9043d, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b346s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9043e, .value=0x8d9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b346s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9043f, .value=0x2ea }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b347s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90440, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b347s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90441, .value=0x8e9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b347s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90442, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b348s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90443, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b348s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90444, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b348s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90445, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b349s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90446, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b349s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90447, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b349s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90448, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b350s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90449, .value=0x500 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b350s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9044a, .value=0xc09 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b350s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9044b, .value=0x10 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b351s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9044c, .value=0x82b0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b351s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9044d, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b351s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9044e, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b352s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9044f, .value=0x8520 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b352s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90450, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b352s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90451, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b353s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90452, .value=0x3c8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b353s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90453, .value=0xc09 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b353s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90454, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b354s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90455, .value=0x150 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b354s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90456, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b354s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90457, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b355s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90458, .value=0x370 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b355s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90459, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b355s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9045a, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b356s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9045b, .value=0x400 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b356s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9045c, .value=0x80e }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b356s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9045d, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b357s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9045e, .value=0xc848 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b357s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9045f, .value=0xc0c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b357s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90460, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b358s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90461, .value=0xc890 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b358s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90462, .value=0x804 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b358s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90463, .value=0x1008 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b359s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90464, .value=0x853b }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b359s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90465, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b359s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90466, .value=0xc00 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b360s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90467, .value=0x8588 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b360s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90468, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b360s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90469, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b361s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9046a, .value=0x85a8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b361s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9046b, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b361s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9046c, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b362s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9046d, .value=0x85c8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b362s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9046e, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b362s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9046f, .value=0x60 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b363s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90470, .value=0x138 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b363s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90471, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b363s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90472, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b364s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90473, .value=0xc8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b364s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90474, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b364s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90475, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b365s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90476, .value=0xa4 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b365s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90477, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b365s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90478, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b366s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90479, .value=0x8510 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b366s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9047a, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b366s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9047b, .value=0x2fa }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b367s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9047c, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b367s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9047d, .value=0x8d9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b367s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9047e, .value=0x31a }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b368s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9047f, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b368s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90480, .value=0x8e9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b368s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90481, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b369s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90482, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b369s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90483, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b369s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90484, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b370s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90485, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b370s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90486, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b370s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90487, .value=0x202 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b371s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90488, .value=0x8510 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b371s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90489, .value=0xc08 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b371s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9048a, .value=0x50 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b372s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9048b, .value=0xa2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b372s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9048c, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b372s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9048d, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b373s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9048e, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b373s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9048f, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b373s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90490, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b374s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90491, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b374s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90492, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b374s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90493, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b375s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90494, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b375s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90495, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b375s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90496, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b376s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90497, .value=0xc8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b376s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90498, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b376s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90499, .value=0xb }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b377s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9049a, .value=0x508 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b377s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9049b, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b377s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9049c, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b378s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9049d, .value=0x1900 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b378s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9049e, .value=0xc09 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b378s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9049f, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b379s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904a0, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b379s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904a1, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b379s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904a2, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b380s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904a3, .value=0x508 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b380s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904a4, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b380s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904a5, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b381s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904a6, .value=0x500 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b381s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904a7, .value=0xc09 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b381s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904a8, .value=0x10 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b382s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904a9, .value=0x82b0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b382s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904aa, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b382s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904ab, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b383s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904ac, .value=0x8520 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b383s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904ad, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b383s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904ae, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b384s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904af, .value=0x3c8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b384s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904b0, .value=0xc09 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b384s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904b1, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b385s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904b2, .value=0x150 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b385s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904b3, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b385s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904b4, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b386s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904b5, .value=0x370 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b386s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904b6, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b386s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904b7, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b387s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904b8, .value=0x400 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b387s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904b9, .value=0x80e }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b387s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904ba, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b388s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904bb, .value=0xc848 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b388s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904bc, .value=0xc0c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b388s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904bd, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b389s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904be, .value=0xc890 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b389s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904bf, .value=0x804 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b389s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904c0, .value=0x20 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b390s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904c1, .value=0x8302 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b390s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904c2, .value=0xb }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b390s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904c3, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b391s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904c4, .value=0x8582 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b391s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904c5, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b391s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904c6, .value=0x1000 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b392s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904c7, .value=0x8539 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b392s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904c8, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b392s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904c9, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b393s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904ca, .value=0x8588 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b393s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904cb, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b393s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904cc, .value=0x40 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b394s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904cd, .value=0x85c8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b394s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904ce, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b394s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904cf, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b395s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904d0, .value=0xfdf0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b395s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904d1, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b395s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904d2, .value=0x80 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b396s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904d3, .value=0x8088 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b396s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904d4, .value=0x80b }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b396s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904d5, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b397s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904d6, .value=0x3b8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b397s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904d7, .value=0x869 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b397s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904d8, .value=0x1ff8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b398s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904d9, .value=0xfdd8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b398s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904da, .value=0xc08 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b398s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904db, .value=0x18 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b399s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904dc, .value=0xfda8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b399s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904dd, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b399s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904de, .value=0x40 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b400s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904df, .value=0x8520 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b400s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904e0, .value=0x8d8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b400s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904e1, .value=0x80 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b401s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904e2, .value=0x8520 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b401s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904e3, .value=0x8e8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b401s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904e4, .value=0x2da }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b402s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904e5, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b402s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904e6, .value=0x8d9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b402s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904e7, .value=0x2ea }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b403s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904e8, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b403s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904e9, .value=0x8e9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b403s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904ea, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b404s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904eb, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b404s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904ec, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b404s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904ed, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b405s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904ee, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b405s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904ef, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b405s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904f0, .value=0x1ff8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b406s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904f1, .value=0xfdd8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b406s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904f2, .value=0xc08 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b406s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904f3, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b407s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904f4, .value=0xfda8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b407s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904f5, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b407s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904f6, .value=0x140 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b408s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904f7, .value=0x8520 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b408s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904f8, .value=0x8d8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b408s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904f9, .value=0x180 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b409s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904fa, .value=0x8520 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b409s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904fb, .value=0x8e8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b409s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904fc, .value=0x2da }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b410s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904fd, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b410s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904fe, .value=0x8d9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b410s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x904ff, .value=0x2ea }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b411s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90500, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b411s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90501, .value=0x8e9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b411s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90502, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b412s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90503, .value=0x1 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b412s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90504, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b412s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90505, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b413s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90506, .value=0x100 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b413s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90507, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b413s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90508, .value=0x9 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b414s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90509, .value=0x500 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b414s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9050a, .value=0xc09 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b414s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9050b, .value=0x10 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b415s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9050c, .value=0x82b0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b415s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9050d, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b415s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9050e, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b416s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9050f, .value=0x8520 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b416s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90510, .value=0x808 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b416s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90511, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b417s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90512, .value=0x3c8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b417s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90513, .value=0xc09 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b417s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90514, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b418s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90515, .value=0x150 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b418s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90516, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b418s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90517, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b419s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90518, .value=0x370 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b419s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90519, .value=0x809 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b419s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9051a, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b420s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9051b, .value=0x400 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b420s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9051c, .value=0x80e }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b420s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9051d, .value=0x8 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b421s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9051e, .value=0xc848 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b421s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9051f, .value=0xc0c }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b421s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90520, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b422s0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90521, .value=0xc890 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b422s1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90522, .value=0x804 }, // DWC_DDRPHYA_INITENG0_p0_SequenceReg0b422s2
    { .type=PHY_INIT_TYPE_PHY, .addr=0xd00e7, .value=0x600 }, // DWC_DDRPHYA_APBONLY0_SequencerOverride
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9001c, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_StartVector0b0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90020, .value=0x77 }, // DWC_DDRPHYA_INITENG0_p0_StartVector0b4
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90024, .value=0x82 }, // DWC_DDRPHYA_INITENG0_p0_StartVector0b8
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90025, .value=0x2b }, // DWC_DDRPHYA_INITENG0_p0_StartVector0b9
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90026, .value=0x2b }, // DWC_DDRPHYA_INITENG0_p0_StartVector0b10
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9002b, .value=0x108 }, // DWC_DDRPHYA_INITENG0_p0_StartVector0b15
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90708, .value=0x11f }, // DWC_DDRPHYA_INITENG0_p0_PieCtrlStartVec0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90700, .value=0x145 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BRtgStartVec0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90701, .value=0x167 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BRtgStartVec1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90702, .value=0x186 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BRtgStartVec2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90703, .value=0x125 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BRtgStartVec3
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90704, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BRtgStartVec4
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90705, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BRtgStartVec5
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90706, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BRtgStartVec6
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90707, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BRtgStartVec7
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2018a, .value=0x0 }, // DWC_DDRPHYA_MASTER0_p0_ACSMNopAddr
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20124, .value=0x1 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2018b, .value=0x16 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20125, .value=0x39 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2018c, .value=0x4e }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20126, .value=0x1 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2018d, .value=0x16 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20127, .value=0x39 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal3
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2018e, .value=0x4e }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal3
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20128, .value=0x17 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal4
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2018f, .value=0x27 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal4
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20129, .value=0x4f }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal5
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20190, .value=0x5f }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal5
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2012a, .value=0x17 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal6
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20191, .value=0x27 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal6
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2012b, .value=0x4f }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal7
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20192, .value=0x5f }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal7
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2012c, .value=0x28 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal8
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20193, .value=0x38 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal8
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2012d, .value=0x60 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal9
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20194, .value=0x70 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal9
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2012e, .value=0x28 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal10
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20195, .value=0x38 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal10
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2012f, .value=0x60 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal11
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20196, .value=0x70 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal11
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20130, .value=0x80 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal12
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20197, .value=0x80 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal12
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20131, .value=0x80 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal13
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20198, .value=0x80 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal13
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20132, .value=0x80 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal14
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20199, .value=0x80 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal14
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20133, .value=0x80 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal15
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2019a, .value=0x80 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal15
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20134, .value=0x71 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal16
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2019b, .value=0x74 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal16
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20135, .value=0x77 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal17
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2019c, .value=0x7a }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal17
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20136, .value=0x71 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal18
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2019d, .value=0x74 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal18
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20137, .value=0x77 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal19
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2019e, .value=0x7a }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal19
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20138, .value=0x75 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal20
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2019f, .value=0x76 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal20
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20139, .value=0x7b }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal21
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201a0, .value=0x7c }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal21
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2013a, .value=0x75 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal22
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201a1, .value=0x76 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal22
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2013b, .value=0x7b }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal23
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201a2, .value=0x7c }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal23
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2013c, .value=0x7d }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal24
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201a3, .value=0x7e }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal24
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2013d, .value=0x7d }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal25
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201a4, .value=0x7e }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal25
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2013e, .value=0x7d }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal26
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201a5, .value=0x7e }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal26
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2013f, .value=0x7d }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal27
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201a6, .value=0x7e }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal27
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20140, .value=0x7f }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal28
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201a7, .value=0x7f }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal28
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20141, .value=0x7f }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal29
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201a8, .value=0x7f }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal29
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20142, .value=0x7f }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal30
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201a9, .value=0x7f }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal30
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20143, .value=0x7f }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal31
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201aa, .value=0x7f }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal31
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20144, .value=0x80 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal32
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201ab, .value=0x7f }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal32
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20145, .value=0x80 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal33
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201ac, .value=0x7f }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal33
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20146, .value=0x80 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal34
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201ad, .value=0x7f }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal34
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20147, .value=0x80 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal35
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201ae, .value=0x7f }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal35
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20148, .value=0x81 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal36
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201af, .value=0x93 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal36
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20149, .value=0x81 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal37
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201b0, .value=0x93 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal37
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2014a, .value=0xef }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal38
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201b1, .value=0x100 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal38
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2014b, .value=0xef }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal39
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201b2, .value=0x100 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal39
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2014c, .value=0x94 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal40
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201b3, .value=0x93 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal40
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2014d, .value=0x94 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal41
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201b4, .value=0x93 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal41
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2014e, .value=0x101 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal42
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201b5, .value=0x100 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal42
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2014f, .value=0x101 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal43
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201b6, .value=0x100 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal43
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20150, .value=0x94 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal44
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201b7, .value=0x9e }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal44
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20151, .value=0x94 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal45
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201b8, .value=0x9e }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal45
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20152, .value=0x101 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal46
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201b9, .value=0x109 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal46
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20153, .value=0x101 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal47
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201ba, .value=0x109 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal47
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20154, .value=0x9f }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal48
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201bb, .value=0xa5 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal48
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20155, .value=0x9f }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal49
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201bc, .value=0xa5 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal49
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20156, .value=0x10a }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal50
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201bd, .value=0x110 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal50
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20157, .value=0x10a }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal51
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201be, .value=0x110 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal51
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20158, .value=0xa6 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal52
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201bf, .value=0xaf }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal52
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20159, .value=0xa6 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal53
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201c0, .value=0xaf }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal53
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2015a, .value=0x111 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal54
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201c1, .value=0x11a }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal54
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2015b, .value=0x111 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal55
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201c2, .value=0x11a }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal55
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2015c, .value=0xb0 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal56
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201c3, .value=0xb9 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal56
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2015d, .value=0xb0 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal57
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201c4, .value=0xb9 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal57
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2015e, .value=0x11b }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal58
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201c5, .value=0x124 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal58
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2015f, .value=0x11b }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal59
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201c6, .value=0x124 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal59
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20160, .value=0xba }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal60
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201c7, .value=0xc4 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal60
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20161, .value=0xba }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal61
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201c8, .value=0xc4 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal61
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20162, .value=0x125 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal62
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201c9, .value=0x12e }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal62
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20163, .value=0x125 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal63
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201ca, .value=0x12e }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal63
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20164, .value=0xc5 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal64
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201cb, .value=0xd3 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal64
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20165, .value=0xc5 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal65
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201cc, .value=0xd3 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal65
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20166, .value=0x12f }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal66
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201cd, .value=0x13d }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal66
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20167, .value=0x12f }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal67
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201ce, .value=0x13d }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal67
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20168, .value=0xd4 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal68
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201cf, .value=0xde }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal68
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20169, .value=0xd4 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal69
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201d0, .value=0xde }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal69
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2016a, .value=0x13e }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal70
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201d1, .value=0x147 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal70
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2016b, .value=0x13e }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal71
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201d2, .value=0x147 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal71
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2016c, .value=0xdf }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal72
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201d3, .value=0xed }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal72
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2016d, .value=0xdf }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal73
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201d4, .value=0xed }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal73
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2016e, .value=0x148 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal74
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201d5, .value=0x156 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal74
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2016f, .value=0x148 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal75
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201d6, .value=0x156 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal75
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20170, .value=0xee }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal76
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201d7, .value=0xee }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal76
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20171, .value=0xee }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal77
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201d8, .value=0xee }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal77
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20172, .value=0x157 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal78
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201d9, .value=0x157 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal78
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20173, .value=0x157 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStartAddrXlatVal79
    { .type=PHY_INIT_TYPE_PHY, .addr=0x201da, .value=0x157 }, // DWC_DDRPHYA_MASTER0_p0_AcsmStopAddrXlatVal79
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4153b, .value=0xb00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4153f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41563, .value=0xb00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41567, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4158b, .value=0xb00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4158f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415b3, .value=0xb00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x415b7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4164b, .value=0xb00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4164f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41673, .value=0xb00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41677, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4171b, .value=0xb00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4171f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41743, .value=0xb00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41747, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41893, .value=0x6b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41897, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418bb, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418bf, .value=0x800 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418e3, .value=0x6b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x418e7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4190b, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4190f, .value=0x800 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4199b, .value=0x6b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4199f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419c3, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x419c7, .value=0x800 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a63, .value=0x6b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a67, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a8b, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41a8f, .value=0x800 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41008, .value=0x49d8 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41009, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4100a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4100b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4100c, .value=0x4808 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4100d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4100e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4100f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41010, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41011, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41012, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41013, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41014, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41015, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41016, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41017, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41018, .value=0x4958 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41019, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4101a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4101b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4101c, .value=0x4e88 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4101d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4101e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4101f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41020, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41021, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41022, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41023, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41024, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41025, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41026, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41027, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41028, .value=0x40d8 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41029, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4102a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4102b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4102c, .value=0x58c8 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4102d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4102e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4102f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41030, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41031, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41032, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41033, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41034, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41035, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41036, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41037, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41038, .value=0x4158 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41039, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4103a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4103b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4103c, .value=0x5dc8 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4103d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4103e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4103f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41040, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41041, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41042, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41043, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41044, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41045, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41046, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41047, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41048, .value=0x41d8 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41049, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4104a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4104b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4104c, .value=0x4308 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4104d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4104e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4104f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41050, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41051, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41052, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41053, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41054, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41055, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41056, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41057, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41058, .value=0x4558 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41059, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4105a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4105b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4105c, .value=0x6a08 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4105d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4105e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4105f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41060, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41061, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41062, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41063, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41064, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41065, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41066, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41067, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41068, .value=0x45d8 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41069, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4106a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4106b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4106c, .value=0x5a88 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4106d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4106e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4106f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41070, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41071, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41072, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41073, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41074, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41075, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41076, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41077, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41078, .value=0x48d8 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41079, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4107a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4107b, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4107c, .value=0x4308 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4107d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4107e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4107f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41080, .value=0x8d8 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41081, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41082, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41083, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41084, .value=0x3448 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41085, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41086, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41087, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41088, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41089, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4108a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4108b, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4108c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4108d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4108e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4108f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41090, .value=0x4a58 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41091, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41092, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41093, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41094, .value=0x4108 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41095, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41096, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41097, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41098, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x41099, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4109a, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4109b, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4109c, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4109d, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4109e, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x4109f, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410a0, .value=0x4b58 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410a1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410a2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410a3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410a4, .value=0x4008 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410a5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410a6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410a7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410a8, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410a9, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410aa, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410ab, .value=0x2b00 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410ac, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410ad, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410ae, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410af, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410b0, .value=0x54d8 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410b1, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410b2, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410b3, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410b4, .value=0x4008 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410b5, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410b6, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0x410b7, .value=0x0 }, // 
    { .type=PHY_INIT_TYPE_PHY, .addr=0xc0001, .value=0x5061 }, // DWC_DDRPHYA_DRTUB0_PieInitVecSel
    { .type=PHY_INIT_TYPE_PHY, .addr=0xc0002, .value=0x7098 }, // DWC_DDRPHYA_DRTUB0_PieInitVecSelB
    { .type=PHY_INIT_TYPE_PHY, .addr=0xc0003, .value=0x0 }, // DWC_DDRPHYA_DRTUB0_PieInitVecSelC
    { .type=PHY_INIT_TYPE_PHY, .addr=0xc0000, .value=0xbedc }, // DWC_DDRPHYA_DRTUB0_PieVecCfg
    { .type=PHY_INIT_TYPE_PHY, .addr=0xc0006, .value=0xb0db }, // DWC_DDRPHYA_DRTUB0_PieVecCfg1
    { .type=PHY_INIT_TYPE_PHY, .addr=0xc0007, .value=0x0 }, // DWC_DDRPHYA_DRTUB0_PieVecCfg2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9070c, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDisableFlag0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9070d, .value=0x7ff }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDisableFlag1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9070e, .value=0x668 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDisableFlag2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9070f, .value=0x7910 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDisableFlag3
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90710, .value=0x355e }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDisableFlag4
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90711, .value=0xcbb5 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDisableFlag5
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90713, .value=0xffff }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDisableFlag7
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90714, .value=0x710 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDisableFlag8
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90715, .value=0x7800 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDisableFlag9
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90c10, .value=0xffff }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDisableFlag16
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90c12, .value=0xff10 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDisableFlag18
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90712, .value=0xffff }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDisableFlag6
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90716, .value=0xff10 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDisableFlag10
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90717, .value=0xff10 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDisableFlag11
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90718, .value=0xff10 }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDisableFlag12
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90719, .value=0xffff }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDisableFlag13
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9071a, .value=0xffff }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDisableFlag14
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9071b, .value=0xfeef }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDisableFlag15
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90c11, .value=0xffff }, // DWC_DDRPHYA_INITENG0_p0_Seq0BDisableFlag17
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90904, .value=0xe400 }, // DWC_DDRPHYA_INITENG0_p0_RtrnModeMask0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90986, .value=0xe400 }, // DWC_DDRPHYA_INITENG0_p0_RtrnModeMask1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90920, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_RtrnSelMask0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90921, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_RtrnSelMask1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90922, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_RtrnSelMask2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90923, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_RtrnSelMask3
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90924, .value=0xff00 }, // DWC_DDRPHYA_INITENG0_p0_RtrnSelMask4
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90925, .value=0xff00 }, // DWC_DDRPHYA_INITENG0_p0_RtrnSelMask5
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90926, .value=0xff00 }, // DWC_DDRPHYA_INITENG0_p0_RtrnSelMask6
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90927, .value=0xff00 }, // DWC_DDRPHYA_INITENG0_p0_RtrnSelMask7
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90930, .value=0x4000 }, // DWC_DDRPHYA_INITENG0_p0_RelTgMaskTg0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90931, .value=0x2000 }, // DWC_DDRPHYA_INITENG0_p0_RelTgMaskTg1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90932, .value=0xff00 }, // DWC_DDRPHYA_INITENG0_p0_RelTgMaskTg2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90933, .value=0xff00 }, // DWC_DDRPHYA_INITENG0_p0_RelTgMaskTg3
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9090a, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_RtrnSeqStart
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9090c, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_RtrnTgSeqStart
    { .type=PHY_INIT_TYPE_PHY, .addr=0x9090d, .value=0x0 }, // DWC_DDRPHYA_INITENG0_p0_RtrnTgSeqStop
    { .type=PHY_INIT_TYPE_PHY, .addr=0x200f0, .value=0x27f7 }, // DWC_DDRPHYA_MASTER0_p0_FspSkipList
    { .type=PHY_INIT_TYPE_PHY, .addr=0x200f1, .value=0x2108 }, // DWC_DDRPHYA_MASTER0_p0_FspSkipList1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x200f2, .value=0x2108 }, // DWC_DDRPHYA_MASTER0_p0_FspSkipList2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x100b9, .value=0x1 }, // DWC_DDRPHYA_DBYTE0_p0_DtsmGoodBar
    { .type=PHY_INIT_TYPE_PHY, .addr=0x100b1, .value=0x180 }, // DWC_DDRPHYA_DBYTE0_p0_DtsmByteCtrl1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x100ba, .value=0x1 }, // DWC_DDRPHYA_DBYTE0_p0_DtsmErrBar
    { .type=PHY_INIT_TYPE_PHY, .addr=0x100a2, .value=0x0 }, // DWC_DDRPHYA_DBYTE0_p0_PptRxEnEvnt
    { .type=PHY_INIT_TYPE_PHY, .addr=0x100b5, .value=0x1 }, // DWC_DDRPHYA_DBYTE0_p0_DtsmLaneCtrl0_i0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x110b9, .value=0x1 }, // DWC_DDRPHYA_DBYTE1_p0_DtsmGoodBar
    { .type=PHY_INIT_TYPE_PHY, .addr=0x110b1, .value=0x180 }, // DWC_DDRPHYA_DBYTE1_p0_DtsmByteCtrl1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x110ba, .value=0x1 }, // DWC_DDRPHYA_DBYTE1_p0_DtsmErrBar
    { .type=PHY_INIT_TYPE_PHY, .addr=0x110a2, .value=0x0 }, // DWC_DDRPHYA_DBYTE1_p0_PptRxEnEvnt
    { .type=PHY_INIT_TYPE_PHY, .addr=0x110b5, .value=0x1 }, // DWC_DDRPHYA_DBYTE1_p0_DtsmLaneCtrl0_i0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x120b9, .value=0x1 }, // DWC_DDRPHYA_DBYTE2_p0_DtsmGoodBar
    { .type=PHY_INIT_TYPE_PHY, .addr=0x120b1, .value=0x180 }, // DWC_DDRPHYA_DBYTE2_p0_DtsmByteCtrl1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x120ba, .value=0x1 }, // DWC_DDRPHYA_DBYTE2_p0_DtsmErrBar
    { .type=PHY_INIT_TYPE_PHY, .addr=0x120a2, .value=0x0 }, // DWC_DDRPHYA_DBYTE2_p0_PptRxEnEvnt
    { .type=PHY_INIT_TYPE_PHY, .addr=0x120b5, .value=0x1 }, // DWC_DDRPHYA_DBYTE2_p0_DtsmLaneCtrl0_i0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x130b9, .value=0x1 }, // DWC_DDRPHYA_DBYTE3_p0_DtsmGoodBar
    { .type=PHY_INIT_TYPE_PHY, .addr=0x130b1, .value=0x180 }, // DWC_DDRPHYA_DBYTE3_p0_DtsmByteCtrl1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x130ba, .value=0x1 }, // DWC_DDRPHYA_DBYTE3_p0_DtsmErrBar
    { .type=PHY_INIT_TYPE_PHY, .addr=0x130a2, .value=0x0 }, // DWC_DDRPHYA_DBYTE3_p0_PptRxEnEvnt
    { .type=PHY_INIT_TYPE_PHY, .addr=0x130b5, .value=0x1 }, // DWC_DDRPHYA_DBYTE3_p0_DtsmLaneCtrl0_i0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70024, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly0_i0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70025, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly1_i0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70026, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly2_i0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70027, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly3_i0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70028, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly4_i0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70029, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly5_i0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x7002a, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly6_i0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x7002b, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly7_i0
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70124, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly0_i1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70125, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly1_i1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70126, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly2_i1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70127, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly3_i1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70128, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly4_i1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70129, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly5_i1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x7012a, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly6_i1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x7012b, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly7_i1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70224, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly0_i2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70225, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly1_i2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70226, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly2_i2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70227, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly3_i2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70228, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly4_i2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70229, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly5_i2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x7022a, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly6_i2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x7022b, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly7_i2
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70324, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly0_i3
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70325, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly1_i3
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70326, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly2_i3
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70327, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly3_i3
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70328, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly4_i3
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70329, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly5_i3
    { .type=PHY_INIT_TYPE_PHY, .addr=0x7032a, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly6_i3
    { .type=PHY_INIT_TYPE_PHY, .addr=0x7032b, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly7_i3
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70424, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly0_i4
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70425, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly1_i4
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70426, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly2_i4
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70427, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly3_i4
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70428, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly4_i4
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70429, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly5_i4
    { .type=PHY_INIT_TYPE_PHY, .addr=0x7042a, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly6_i4
    { .type=PHY_INIT_TYPE_PHY, .addr=0x7042b, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly7_i4
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70524, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly0_i5
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70525, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly1_i5
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70526, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly2_i5
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70527, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly3_i5
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70528, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly4_i5
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70529, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly5_i5
    { .type=PHY_INIT_TYPE_PHY, .addr=0x7052a, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly6_i5
    { .type=PHY_INIT_TYPE_PHY, .addr=0x7052b, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly7_i5
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70624, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly0_i6
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70625, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly1_i6
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70626, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly2_i6
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70627, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly3_i6
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70628, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly4_i6
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70629, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly5_i6
    { .type=PHY_INIT_TYPE_PHY, .addr=0x7062a, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly6_i6
    { .type=PHY_INIT_TYPE_PHY, .addr=0x7062b, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly7_i6
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70724, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly0_i7
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70725, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly1_i7
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70726, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly2_i7
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70727, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly3_i7
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70728, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly4_i7
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70729, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly5_i7
    { .type=PHY_INIT_TYPE_PHY, .addr=0x7072a, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly6_i7
    { .type=PHY_INIT_TYPE_PHY, .addr=0x7072b, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly7_i7
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70824, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly0_i8
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70825, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly1_i8
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70826, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly2_i8
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70827, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly3_i8
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70828, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly4_i8
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70829, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly5_i8
    { .type=PHY_INIT_TYPE_PHY, .addr=0x7082a, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly6_i8
    { .type=PHY_INIT_TYPE_PHY, .addr=0x7082b, .value=0x5a3c }, // DWC_DDRPHYA_PPGC0_PrbsTapDly7_i8
    { .type=PHY_INIT_TYPE_PHY, .addr=0x70065, .value=0x1ff }, // DWC_DDRPHYA_PPGC0_PrbsGenCtl1
    { .type=PHY_INIT_TYPE_PHY, .addr=0x2007e, .value=0x11 }, // DWC_DDRPHYA_MASTER0_p0_HwtControlVal
    { .type=PHY_INIT_TYPE_PHY, .addr=0x200ef, .value=0xffff }, // DWC_DDRPHYA_MASTER0_p0_FspState
    { .type=PHY_INIT_TYPE_PHY, .addr=0x90910, .value=0x2 }, // DWC_DDRPHYA_INITENG0_p0_PieTrigCntVal
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20310, .value=0x1 }, // DWC_DDRPHYA_MASTER0_p0_ZCalReset
    { .type=PHY_INIT_TYPE_PHY, .addr=0x20311, .value=0x1 }, // DWC_DDRPHYA_MASTER0_p0_ZCalRun
    { .type=PHY_INIT_TYPE_PHY, .addr=0xc0080, .value=0x2 }, // DWC_DDRPHYA_DRTUB0_UcclkHclkEnables
    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0003, .value=0x0 }, // DWC_DDRPHYA_APBONLY0_TDRDisable
    { .type=PHY_INIT_TYPE_PHY, .addr=0xd0000, .value=0x1 }, // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
};

static init_element_t seq4_init_ddr_modalix_1r[] = {
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010c80, .value=0x00000000 }, // SWCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010c80, .value=0x00000000 }, // SWCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010510, .value=0x00000024 }, // DFIMISC;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010510, .value=0x00000024 }, // DFIMISC;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010c80, .value=0x00000001 }, // SWCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010c80, .value=0x00000001 }, // SWCTL;
    { .type=PHY_INIT_TYPE_POLL, .addr=0x00010c84, .value=0x00000001 }, // SWSTAT
    { .type=PHY_INIT_TYPE_POLL, .addr=0x01010c84, .value=0x00000001 }, // SWSTAT
    { .type=PHY_INIT_TYPE_POLL, .addr=0x00010514, .value=0x00000001 }, // DFISTAT
    { .type=PHY_INIT_TYPE_POLL, .addr=0x01010514, .value=0x00000001 }, // DFISTAT
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010c80, .value=0x00000000 }, // SWCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010c80, .value=0x00000000 }, // SWCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010510, .value=0x00000004 }, // DFIMISC;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010510, .value=0x00000004 }, // DFIMISC;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010c80, .value=0x00000001 }, // SWCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010c80, .value=0x00000001 }, // SWCTL;
    { .type=PHY_INIT_TYPE_POLL, .addr=0x00010c84, .value=0x00000001 }, // SWSTAT
    { .type=PHY_INIT_TYPE_POLL, .addr=0x01010c84, .value=0x00000001 }, // SWSTAT
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010c80, .value=0x00000000 }, // SWCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010c80, .value=0x00000000 }, // SWCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010510, .value=0x00000005 }, // DFIMISC;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010510, .value=0x00000005 }, // DFIMISC;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010c80, .value=0x00000001 }, // SWCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010c80, .value=0x00000001 }, // SWCTL;
    { .type=PHY_INIT_TYPE_POLL, .addr=0x00010c84, .value=0x00000001 }, // SWSTAT
    { .type=PHY_INIT_TYPE_POLL, .addr=0x01010c84, .value=0x00000001 }, // SWSTAT
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010180, .value=0x00000000 }, // PWRCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010180, .value=0x00000000 }, // PWRCTL;
    { .type=PHY_INIT_TYPE_POLL, .addr=0x00010014, .value=0x00000001 }, // STAT
    { .type=PHY_INIT_TYPE_POLL, .addr=0x01010014, .value=0x00000001 }, // STAT
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010208, .value=0x00000000 }, // RFSHCTL0;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010208, .value=0x00000000 }, // RFSHCTL0;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010180, .value=0x00000201 }, // PWRCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010180, .value=0x00000201 }, // PWRCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00010100, .value=0x00000019 }, // DERATECTL0;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01010100, .value=0x00000019 }, // DERATECTL0;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00000a80, .value=0x00003c44 }, // DQSOSCCTL0;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01000a80, .value=0x00003c44 }, // DQSOSCCTL0;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x000200e0, .value=0x01000000 }, // SBRCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x010200e0, .value=0x01000000 }, // SBRCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x000200e8, .value=0xaaaaaaaa }, // SBRWDATA0;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x010200e8, .value=0xaaaaaaaa }, // SBRWDATA0;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x000200f0, .value=0x00000000 }, // SBRSTART0;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x010200f0, .value=0x00000000 }, // SBRSTART0;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x000200f4, .value=0x00000000 }, // SBRSTART1;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x010200f4, .value=0x00000000 }, // SBRSTART1;
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x000200f8, .value=0x37ffffff }, // SBRRANGE0;
    { .type=PHY_INIT_TYPE_WRITE_FREQ, .addr=0x010200f8, .value=0x37ffffff }, // SBRRANGE0;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x000200fc, .value=0x00000000 }, // SBRRANGE1;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x010200fc, .value=0x00000000 }, // SBRRANGE1;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x000200e0, .value=0x01000001 }, // SBRCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x010200e0, .value=0x01000001 }, // SBRCTL;
    { .type=PHY_INIT_TYPE_POLL, .addr=0x000200e4, .value=0x00000002 }, // SBRSTAT
    { .type=PHY_INIT_TYPE_POLL, .addr=0x010200e4, .value=0x00000002 }, // SBRSTAT
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x000200e0, .value=0x00000000 }, // SBRCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x010200e0, .value=0x00000000 }, // SBRCTL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x00020090, .value=0x00000001 }, // PCTRL;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x01020090, .value=0x00000001 }, // PCTRL;
};


static init_element_t seq4_init_ddr_modalix_1r_PHY_DDR_FREQ_6400_16[] = {
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x000200f8, .value=0x37ffffff }, // SBRRANGE0;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x010200f8, .value=0x37ffffff }, // SBRRANGE0;
};

static init_element_t seq4_init_ddr_modalix_1r_PHY_DDR_FREQ_6400_16_2GB[] = {
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x000200f8, .value=0x1BFFFFFF }, // SBRRANGE0;
    { .type=PHY_INIT_TYPE_WRITE, .addr=0x010200f8, .value=0x1BFFFFFF }, // SBRRANGE0;
};

static init_sequence_t sequences_init_ddr_modalix_1r[PHY_INIT_NUM] = {
    [PHY_INIT_DDR_PRERESET] = {
        .elements = &seq1_init_ddr_modalix_1r[0],
        .size = ARRAY_SIZE(seq1_init_ddr_modalix_1r),
        .unique_vals = {
            [PHY_DDR_FREQ_6400_16] = {
                .elements = &seq1_init_ddr_modalix_1r_PHY_DDR_FREQ_6400_16[0],
                .size = ARRAY_SIZE(seq1_init_ddr_modalix_1r_PHY_DDR_FREQ_6400_16)
            },
            [PHY_DDR_FREQ_6400_16_2GB] = {
                .elements = &seq1_init_ddr_modalix_1r_PHY_DDR_FREQ_6400_16_2GB[0],
                .size = ARRAY_SIZE(seq1_init_ddr_modalix_1r_PHY_DDR_FREQ_6400_16_2GB)
            },
            { 0 },
        },
    },
    [PHY_INIT_DDR_POSTRESET] = {
        .elements = &seq2_init_ddr_modalix_1r[0],
        .size = ARRAY_SIZE(seq2_init_ddr_modalix_1r),
        .unique_vals = { 0 },
    },
    [PHY_INIT_DDR_2D_TRAINING] = {
        .elements = &seq3_2D_init_ddr_modalix_1r[0],
        .size = ARRAY_SIZE(seq3_2D_init_ddr_modalix_1r),
        .unique_vals =  { 0 },
    },
    [PHY_INIT_DDR_FINAL] = {
        .elements = &seq4_init_ddr_modalix_1r[0],
        .size = ARRAY_SIZE(seq4_init_ddr_modalix_1r),
        .unique_vals = {
            [PHY_DDR_FREQ_6400_16] = {
                .elements = &seq4_init_ddr_modalix_1r_PHY_DDR_FREQ_6400_16[0],
                .size = ARRAY_SIZE(seq4_init_ddr_modalix_1r_PHY_DDR_FREQ_6400_16)
            },
            [PHY_DDR_FREQ_6400_16_2GB] = {
                .elements = &seq4_init_ddr_modalix_1r_PHY_DDR_FREQ_6400_16_2GB[0],
                .size = ARRAY_SIZE(seq4_init_ddr_modalix_1r_PHY_DDR_FREQ_6400_16_2GB)
            },
			{ 0 },
		},
    },
};

int32_t get_sequence_init_ddr_modalix_1r(init_sequence_t **sequences) {
    if(sequences == NULL)
        return -1;
    *sequences = &sequences_init_ddr_modalix_1r[0];
    return ARRAY_SIZE(sequences_init_ddr_modalix_1r);
}

