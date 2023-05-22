//SPDX-License-Identifier: (GPL-2.0+ OR MIT)
/*
 * Copyright (c) 2022 Sima ai
 */

//#define PRINT_PHY_TRAINING_MESSAGES 1

#include <stdio.h>
#include <linux/delay.h>
#include <asm/arch/phy_init.h>
#ifdef PRINT_PHY_TRAINING_MESSAGES
#include <asm/arch/ddr_phy_debug.h>
#endif

static char ops[PHY_INIT_TYPE_NUM][32] = {
		[PHY_INIT_TYPE_WRITE] = "Write to DDRC",
		[PHY_INIT_TYPE_READ] = "Read from DDRC",
		[PHY_INIT_TYPE_POLL] = "Poll from DDRC",
		[PHY_INIT_TYPE_PHY] = "Write to DDR PHY",
		[PHY_INIT_TYPE_FIRMWARE] = "Load firmware binary",
		[PHY_INIT_TYPE_RUN] = "Run firmware",
		[PHY_INIT_TYPE_DEBUG] = "Debug read from PHY",
		[PHY_INIT_TYPE_DUMPEYE] = "Dump PHY EYE",
		[PHY_INIT_TYPE_PHYPOLL] = "Poll from PHY",
		[PHY_INIT_TYPE_DDRCSETTINGS] = "Set DDRC settings",
		[PHY_INIT_TYPE_PHYSETTINGS] = "Set PHY settings",
};
#ifdef PRINT_PHY_TRAINING_MESSAGES
static char major_messages[0x100][64] = {
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
#endif

static inline void do_apb_write(uint32_t base, uint32_t regoff, uint32_t data)
{
	*((volatile uint32_t*)(base + regoff)) = data;
}

static inline void do_apb_read(uint32_t base, uint32_t regoff, uint32_t expdata)
{
	uint32_t data = *((volatile uint32_t*)(base + regoff));

	if(data != expdata)
		printf("PHY INIT: Warning! Read [%#x] failed! expected: %#x, actual: %#x\n", regoff, expdata, data);
}

static inline void do_apb_poll(uint32_t base, uint32_t regoff, uint32_t expdata)
{
	uint32_t data;
	int pollcnt = 1000000;

	do {
		data = *((volatile uint32_t*)(base + regoff));
		if(data != expdata)
			udelay(1);
	} while((pollcnt-- > 0) && (data != expdata));
	if(data != expdata)
		printf("PHY INIT: Warning! Poll [%#x] failed! expected: %#x, actual: %#x\n", regoff, expdata, data);
}

static inline void do_phy_write(uint32_t base, uint32_t regoff, uint16_t data)
{
	*((volatile uint16_t*)(base + (regoff << 1))) = data;
}

static inline void do_phy_writes(uint32_t base, uint32_t regoff, uint16_t data, uint32_t *offsets, uint32_t count)
{
	int i;
	for(i = 0; i < count; i++)
		do_phy_write(base, regoff + offsets[i], data);
}

static inline uint16_t do_phy_read(uint32_t base, uint32_t regoff)
{
	return *((volatile uint16_t*)(base + (regoff << 1)));
}

static inline void do_phy_poll(uint32_t base, uint32_t regoff, uint16_t expdata)
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

static inline void load_firmware(uint32_t base, firmware_t f, chip_settings_t *s) {
	uint32_t i;

	debug("DDR_PHY: Writing firmware at (%#x)\n", f.addr);
	for(i = 0; i < f.size; i++)
		do_phy_write(base, f.addr + i, f.values[i]);

	if(f.addr == 0x54000) {
		do_phy_write(base, f.addr + 0x0, 0x0000);
#ifdef PRINT_PHY_TRAINING_MESSAGES
		do_phy_write(base, f.addr + 0x9, 0x0004);
#endif
		/* Set board specific settings in MRs */
		do_phy_write(base, f.addr + 0x6, s->phyvref);
		do_phy_write(base, f.addr + 0x19, (PHY_DDR_MR2(s) << 8 | PHY_DDR_MR1(s)));
		do_phy_write(base, f.addr + 0x1f, (PHY_DDR_MR2(s) << 8 | PHY_DDR_MR1(s)));
		do_phy_write(base, f.addr + 0x32, (PHY_DDR_MR1(s) << 8 | PHY_DDR_MR24(s)));
		do_phy_write(base, f.addr + 0x38, (PHY_DDR_MR1(s) << 8 | PHY_DDR_MR24(s)));
		do_phy_write(base, f.addr + 0x1a, (PHY_DDR_MR4(s) << 8 | PHY_DDR_MR3(s)));
		do_phy_write(base, f.addr + 0x20, (PHY_DDR_MR4(s) << 8 | PHY_DDR_MR3(s)));
		do_phy_write(base, f.addr + 0x33, (PHY_DDR_MR3(s) << 8 | PHY_DDR_MR2(s)));
		do_phy_write(base, f.addr + 0x39, (PHY_DDR_MR3(s) << 8 | PHY_DDR_MR2(s)));
		do_phy_write(base, f.addr + 0x1b, (PHY_DDR_MR12(s) << 8 | PHY_DDR_MR11(s)));
		do_phy_write(base, f.addr + 0x21, (PHY_DDR_MR12(s) << 8 | PHY_DDR_MR11(s)));
		do_phy_write(base, f.addr + 0x34, (PHY_DDR_MR11(s) << 8 | PHY_DDR_MR4(s)));
		do_phy_write(base, f.addr + 0x3a, (PHY_DDR_MR11(s) << 8 | PHY_DDR_MR4(s)));
		do_phy_write(base, f.addr + 0x35, (PHY_DDR_MR13(s) << 8 | PHY_DDR_MR12(s)));
		do_phy_write(base, f.addr + 0x3b, (PHY_DDR_MR13(s) << 8 | PHY_DDR_MR12(s)));
		do_phy_write(base, f.addr + 0x1c, (PHY_DDR_MR14(s) << 8 | PHY_DDR_MR13(s)));
		do_phy_write(base, f.addr + 0x22, (PHY_DDR_MR14(s) << 8 | PHY_DDR_MR13(s)));
		do_phy_write(base, f.addr + 0x36, (PHY_DDR_MR16(s) << 8 | PHY_DDR_MR14(s)));
		do_phy_write(base, f.addr + 0x3c, (PHY_DDR_MR16(s) << 8 | PHY_DDR_MR14(s)));
	}
}

static uint32_t get_mail(uint32_t base, uint32_t full)
{
	uint32_t mail = 0;

	while(do_phy_read(base, 0xd0004) & 1)
		udelay(1000);

	mail = (uint32_t) do_phy_read(base, 0xd0032);
	if(full)
		mail |= ((uint32_t) do_phy_read(base, 0xd0034)) << 16;

	do_phy_write(base, 0xd0031, 0);
	while(!(do_phy_read(base, 0xd0004) & 1))
		udelay(1000);

	do_phy_write(base, 0xd0031, 1);

	return mail;
}

#ifdef PRINT_PHY_TRAINING_MESSAGES
void varprintf0(char * str, uint32_t *args) {printf(str);};
void varprintf1(char * str, uint32_t *args) {printf(str, args[0]);};
void varprintf2(char * str, uint32_t *args) {printf(str, args[0], args[1]);};
void varprintf3(char * str, uint32_t *args) {printf(str, args[0], args[1], args[2]);};
void varprintf4(char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3]);};
void varprintf5(char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4]);};
void varprintf6(char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4], args[5]);};
void varprintf7(char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4], args[5], args[6]);};
void varprintf8(char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7]);};
void varprintf9(char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8]);};
void varprintf10(char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9]);};
void varprintf11(char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10]);};
void varprintf12(char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11]);};
void varprintf13(char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12]);};
void varprintf14(char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13]);};
void varprintf15(char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13], args[14]);};
void varprintf31(char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13], args[14],
		args[15], args[16], args[17], args[18], args[19], args[20], args[21], args[22], args[23], args[24], args[25], args[26], args[27], args[28], args[29], args[30]);};
static void (*varprintf[])(char * str, uint32_t *args) = {
		&varprintf0, &varprintf1, &varprintf2, &varprintf3,
		&varprintf4, &varprintf5, &varprintf6, &varprintf7,
		&varprintf8, &varprintf9, &varprintf10, &varprintf11,
		&varprintf12, &varprintf13, &varprintf14, &varprintf15,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, &varprintf31,
};

static void get_streaming_message(uint32_t base, uint32_t id)
{
	uint32_t index = get_mail(base, 1);
	uint32_t i, args[32];
	int32_t res;
	char *str;

	for (i = 0; i < (index & 0xffff); i++)
		args[i] = get_mail(base, 1);

	if((get_ddr_phy_debug_string(id, index, &str) == 0) &&
			((index & 0xffff) < ARRAY_SIZE(varprintf)) &&
			(varprintf[i] != NULL))
		(*(varprintf[i]))(str, args);
}
#endif

static int32_t do_training_run(uint32_t base, uint32_t id) {
	uint32_t mail;

	while(1) {
		mail = get_mail(base, 0);
#ifdef PRINT_PHY_TRAINING_MESSAGES
		if((mail < 0x100) && (major_messages[mail] != NULL) && (strlen(major_messages[mail]) > 0))
			printf("PHY FIRMWARE[%d]: %s\n", id, major_messages[mail]);
		if(mail == 0x08) {
			get_streaming_message(base, id);
		}
#endif
		if(mail == 0x07)
			return 0;
		if(mail == 0x0ff)
			return -4;
	}
}

static uint32_t odtimps[] = { 0x10000, 0x10100, 0x11000, 0x11100, 0x12000, 0x12100, 0x13000, 0x13100 };
static uint32_t atximps[] = { 0x0000, 0x1000, 0x2000, 0x3000, 0x4000, 0x5000 };


int32_t run_sequence(uint32_t cbase, uint32_t phybase, init_sequence_t s, firmware_t *f, int32_t fs, chip_settings_t *sets) {
	uint32_t i, j, k, offset = 3, cols, rows;
	int32_t res = 0;
	uint16_t val;

	debug("PHY INIT: Running sequence %#x, value %#x\n", cbase, phybase);

	if(s.elements == NULL)
		return -1;

	for(i = 0; i < s.size && res == 0; i++) {
		debug("PHY INIT: Executing element %d: %s [%#x] = %#x\n", i, s.elements[i].type < PHY_INIT_TYPE_NUM ? ops[s.elements[i].type] : "Unknown", s.elements[i].addr, s.elements[i].value);
		switch(s.elements[i].type) {
		case PHY_INIT_TYPE_WRITE:
			do_apb_write(cbase, s.elements[i].addr, s.elements[i].value);
			break;
		case PHY_INIT_TYPE_READ:
			do_apb_read(cbase, s.elements[i].addr, s.elements[i].value);
			break;
		case PHY_INIT_TYPE_POLL:
			do_apb_poll(cbase, s.elements[i].addr, s.elements[i].value);
			break;
		case PHY_INIT_TYPE_PHY:
			do_phy_write(phybase, s.elements[i].addr, s.elements[i].value);
			break;
		case PHY_INIT_TYPE_PHYPOLL:
			do_phy_poll(phybase, s.elements[i].addr, s.elements[i].value);
			break;
		case PHY_INIT_TYPE_FIRMWARE:
			if(f == NULL)
				res = -2;
			else if(s.elements[i].value > fs)
				res = -3;
			else
				load_firmware(phybase, f[s.elements[i].value], sets);
			break;
		case PHY_INIT_TYPE_RUN:
			res = do_training_run(phybase, s.elements[i].value);
			if((res == 0) && (s.elements[i].value)) {
				res = do_phy_read(phybase, s.elements[i].addr) && 0xff;
			}
			break;
		case PHY_INIT_TYPE_DEBUG:
			printf("PHY INIT: Debug message addr %#x, value %#x\n", s.elements[i].addr, do_phy_read(phybase, s.elements[i].addr));
			break;
		case PHY_INIT_TYPE_DUMPEYE:
			printf("PHY INIT: Dumping EYE at address %#x\n", s.elements[i].addr);
			cols = do_phy_read(phybase, s.elements[i].addr) & 0xff;
			rows = (do_phy_read(phybase, s.elements[i].addr) >> 8) & 0xff;
			printf("PHY INIT: Columns: %d, rows: %d\n", cols, rows);
			for(j = 0; j < rows; j++) {
				for(k = 0; k < cols; k += 2) {
					val = do_phy_read(phybase, s.elements[i].addr + offset);
					printf("%03d %03d ", val & 0xff, (val >> 8) & 0xff);
					offset++;
				}
				printf("\n");
			}
			break;
		case PHY_INIT_TYPE_DDRCSETTINGS:
			if(sets == NULL)
				res = -4;
			else {
				do_apb_write(cbase, 0x000000dc, (PHY_DDR_MR1(sets) << 16 | PHY_DDR_MR2(sets)));
				do_apb_write(cbase, 0x000000e0, (PHY_DDR_MR3(sets) << 16 | PHY_DDR_MR13(sets)));
				do_apb_write(cbase, 0x000000e8, (PHY_DDR_MR11(sets) << 16 | PHY_DDR_MR12(sets)));
			}
			break;
		case PHY_INIT_TYPE_PHYSETTINGS:
			if(sets == NULL)
				res = -4;
			else {
				do_phy_writes(phybase, 0x4d, sets->txodt, odtimps, ARRAY_SIZE(odtimps));
				do_phy_writes(phybase, 0x49, sets->tximp, odtimps, ARRAY_SIZE(odtimps));
				do_phy_writes(phybase, 0x43, sets->atximp, atximps, ARRAY_SIZE(atximps));
				do_phy_write(phybase, 0x200b2, VREFGLOBAL(sets->phyvref));
			}
			break;
		default:
			break;
		}
	}

	return res;
}
