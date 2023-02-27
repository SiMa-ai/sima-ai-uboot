// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (c) 2022 SiMa ai
 */

#include <asm/arch/simaai_ddr_utils.h>
#include <asm/arch/init_ddr_933MHz.h>
#include <asm/arch/init_ddr_800MHz.h>
#include <asm/arch/init_ddr_533MHz.h>
#include <asm/arch/init_ddr_zebu.h>
#include <asm/arch/firmware_ddr.h>
#include <asm/arch/shmem.h>

typedef int32_t (*get_sequence_t)(init_sequence_t **sequences);

static get_sequence_t sequences[PHY_DDR_FREQ_NUM] = {
	[PHY_DDR_FREQ_533MHz] = get_sequence_init_ddr_533MHz,
	[PHY_DDR_FREQ_800MHz] = get_sequence_init_ddr_800MHz,
	[PHY_DDR_FREQ_933MHz] = get_sequence_init_ddr_933MHz,
	[PHY_DDR_FREQ_ZEBU] = get_sequence_init_ddr_zebu,
};

static uint32_t freqs[PHY_DDR_FREQ_NUM] = {
	[PHY_DDR_FREQ_533MHz] = 533,
	[PHY_DDR_FREQ_800MHz] = 800,
	[PHY_DDR_FREQ_933MHz] = 933,
	[PHY_DDR_FREQ_ZEBU] = 933,
};

static ddrc_t ddrc = {
	.sequences = NULL,
	.firmwares = NULL,
	.addrs = { {
			.ddrc_base = 0x05800000,
			.phy_base = 0x03800000,
			.rst_addr = PRC_BASE + PRC_REG__CKG_RST_REG__DMS0_CK_RST_ADDR,
		}, {
			.ddrc_base = 0x05810000,
			.phy_base = 0x04000000,
			.rst_addr = PRC_BASE + PRC_REG__CKG_RST_REG__DMS1_CK_RST_ADDR,
		}, {
			.ddrc_base = 0x05820000,
			.phy_base = 0x04800000,
			.rst_addr = PRC_BASE + PRC_REG__CKG_RST_REG__DMS2_CK_RST_ADDR,
		}, {
			.ddrc_base = 0x05830000,
			.phy_base = 0x05000000,
			.rst_addr = PRC_BASE + PRC_REG__CKG_RST_REG__DMS3_CK_RST_ADDR,
	}, },
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
	res = sequences[ddrc.settings->freq](&ddrc.sequences);
	if(res < 0) {
		printf("DDR INIT: Error. Wrong number of sequences\n");
		return NULL;
	}

	return &ddrc;
}

uint32_t freq_to_uint(ddr_freq_t freq)
{
	return freqs[freq];
}

#ifdef CONFIG_CMD_DDR

static inline void do_apb_write(uint32_t base, uint32_t regoff, uint32_t data)
{
	*((volatile uint32_t*)(base + regoff)) = data;
}

static inline uint32_t do_apb_read(uint32_t base, uint32_t regoff)
{
	return *((volatile uint32_t*)(base + regoff));
}

static inline void do_phy_write(uint32_t base, uint32_t regoff, uint16_t data)
{
	*((volatile uint16_t*)(base + (regoff << 1))) = data;
}

static inline uint16_t do_phy_read(uint32_t base, uint32_t regoff)
{
	return *((volatile uint16_t*)(base + (regoff << 1)));
}

static inline void prc_write(uint32_t addr, uint32_t data)
{
	*((volatile uint32_t*)(addr)) = data;
}

#define SIMAAI_DDRVAL2STRING(name, val) {(uint32_t)PHY_DDR_##name##_##val##_OHM, val}
#define SIMAAI_DDRTXIMP(val) SIMAAI_DDRVAL2STRING(TXIMP, val)
#define SIMAAI_DDRTXODT(val) SIMAAI_DDRVAL2STRING(TXODT, val)
#define SIMAAI_DDRATXIMP(val) SIMAAI_DDRVAL2STRING(ATXIMP, val)
#define SIMAAI_DDRMEMIMP(val) SIMAAI_DDRVAL2STRING(MEMIMP, val)
#define SIMAAI_DDRSETTING(name, i) ddrc->settings->chip_settings[i].name
#define SIMAAI_TXIMP2VAL(name, i) simaai_ddr_hex2val(name##vals, sizeof(name##vals), (uint32_t)SIMAAI_DDRSETTING(name, i))
#define SIMAAI_MEMIMP2VAL(name, i) simaai_ddr_hex2val(memimpvals, sizeof(memimpvals), (uint32_t)SIMAAI_DDRSETTING(name, i))
#define SIMAAI_VAL2HEX(name, val) simaai_ddr_val2hex(name, sizeof(name), val)

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
					do_apb_read(ddrc->addrs[i].ddrc_base, addr));
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
					do_apb_read(ddrc->addrs[i].ddrc_base, addr));
			do_apb_write(ddrc->addrs[i].ddrc_base, addr, value);
			printf("DDRC[%d] New value register[0x%04x] = 0x%08x\n", i, addr,
					do_apb_read(ddrc->addrs[i].ddrc_base, addr));
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
	int32_t i;
	ddrc_t *ddrc = get_ddrc();

	for(i = 0; i < PHY_DDR_MAX_CONTROLLERS; i++) {
		prc_write(ddrc->addrs[i].rst_addr, 0x200);
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
	printf("\t\txodt: ");
	for(i = 0; i < ARRAY_SIZE(txodtvals); i++)
		printf("%u, ", txodtvals[i][1]);
	printf("\n");
	printf("\t\tmempdds, memcaodt, memdqodt: ");
	for(i = 0; i < ARRAY_SIZE(memimpvals); i++)
		printf("%u, ", memimpvals[i][1]);
	printf("\n");
	printf("\t\tmemcavref, memdqvref, phyvref: Any DECIMAL	 value\n");

	return 0;
}

int32_t sima_ddr_dump_settings(void)
{
	int32_t i;
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
	}

	return 0;
}

int32_t sima_ddr_set_settings(uint32_t index, uint32_t setting, uint32_t val)
{
	uint32_t new_hex;
	ddrc_t *ddrc = get_ddrc();

	switch(setting) {
		case 0:
			new_hex = SIMAAI_VAL2HEX(tximpvals, val);
			if (new_hex == 0xffffffff) {
				printf("Wrong value of tximp: %u\n", val);
				return -1;
			}
			SIMAAI_DDRSETTING(tximp, index) = (ddr_memimp_t)new_hex;
			break;
		case 1:
			new_hex = SIMAAI_VAL2HEX(atximpvals, val);
			if (new_hex == 0xffffffff) {
				printf("Wrong value of atximp: %u\n", val);
				return -1;
			}
			SIMAAI_DDRSETTING(atximp, index) = (ddr_memimp_t)new_hex;
			break;
		case 2:
			new_hex = SIMAAI_VAL2HEX(txodtvals, val);
			if (new_hex == 0xffffffff) {
				printf("Wrong value of txodt: %u\n", val);
				return -1;
			}
			SIMAAI_DDRSETTING(txodt, index) = (ddr_memimp_t)new_hex;
			break;
		case 3:
			new_hex = SIMAAI_VAL2HEX(memimpvals, val);
			if (new_hex == 0xffffffff) {
				printf("Wrong value of mempdds: %u\n", val);
				return -1;
			}
			SIMAAI_DDRSETTING(mempdds, index) = (ddr_memimp_t)new_hex;
			break;
		case 4:
			new_hex = SIMAAI_VAL2HEX(memimpvals, val);
			if (new_hex == 0xffffffff) {
				printf("Wrong value of memcaodt: %u\n", val);
				return -1;
			}
			SIMAAI_DDRSETTING(memcaodt, index) = (ddr_memimp_t)new_hex;
			break;
		case 5:
			new_hex = SIMAAI_VAL2HEX(memimpvals, val);
			if (new_hex == 0xffffffff) {
				printf("Wrong value of memdqodt: %u\n", val);
				return -1;
			}
			SIMAAI_DDRSETTING(memdqodt, index) = (ddr_memimp_t)new_hex;
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
		default:
			printf("Unknown setting: %u\n", setting);
			return -1;
	}

	return 0;
}

#endif
