//SPDX-License-Identifier: (GPL-2.0+ OR MIT)
/*
 * Copyright (c) 2022 Sima ai
 */

#include <stdio.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <asm/arch/phy_init.h>
#include <asm/arch/simaai_ddr_utils.h>
#ifdef PRINT_PHY_TRAINING_MESSAGES
#include <asm/arch/ddr_phy_debug.h>
#endif

static char ops[PHY_INIT_TYPE_NUM][40] = {
	[PHY_INIT_TYPE_WRITE] = "Write to DDRC",
	[PHY_INIT_TYPE_WRITE_FREQ] = "Write to DDRC (frequency specific)",
	[PHY_INIT_TYPE_READ] = "Read from DDRC",
	[PHY_INIT_TYPE_POLL] = "Poll from DDRC",
	[PHY_INIT_TYPE_PHY] = "Write to DDR PHY",
	[PHY_INIT_TYPE_PHY_FREQ] = "Write to DDR PHY (frequency specific)",
	[PHY_INIT_TYPE_FIRMWARE] = "Load firmware binary",
	[PHY_INIT_TYPE_RUN] = "Run firmware",
	[PHY_INIT_TYPE_DEBUG] = "Debug read from PHY",
	[PHY_INIT_TYPE_DUMPEYE] = "Dump PHY EYE",
	[PHY_INIT_TYPE_PHYPOLL] = "Poll from PHY",
	[PHY_INIT_TYPE_DDRCSETTINGS] = "Set DDRC settings",
	[PHY_INIT_TYPE_PHYSETTINGS] = "Set PHY settings",
};
#ifdef PRINT_PHY_TRAINING_MESSAGES
extern char major_messages[0x100][90];
#endif

static inline void load_firmware(uint32_t base, firmware_t f, chip_settings_t *s) {
	uint32_t i;

	debug("DDR_PHY: Writing firmware at (%#x)\n", f.addr);
	for(i = 0; i < f.size; i++)
		do_phy_write(base, f.addr + i, f.values[i]);

	if(f.addr != 0x50000) {
		do_phy_write(base, f.addr + 0x0, 0x0000);
#ifdef PRINT_PHY_TRAINING_MESSAGES
		do_phy_write(base, f.addr + 0x9, 0x0004);
#else
		do_phy_write(base, f.addr + 0x9, 0x00ff);
#endif
		/* Set board specific settings in MRs */
		board_specific_mr_settings(base, f.addr, s);
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
// #define COMPRESSED_MESSAGES 1
#ifdef COMPRESSED_MESSAGES
void varprintf0(uint32_t id, char * str, uint32_t *args) {printf("%x:\n", id);};
void varprintf1(uint32_t id, char * str, uint32_t *args) {printf("%x:%x\n", id, args[0]);};
void varprintf2(uint32_t id, char * str, uint32_t *args) {printf("%x:%x,%x\n", id, args[0], args[1]);};
void varprintf3(uint32_t id, char * str, uint32_t *args) {printf("%x:%x,%x,%x\n", id, args[0], args[1], args[2]);};
void varprintf4(uint32_t id, char * str, uint32_t *args) {printf("%x:%x,%x,%x,%x\n", id, args[0], args[1], args[2], args[3]);};
void varprintf5(uint32_t id, char * str, uint32_t *args) {printf("%x:%x,%x,%x,%x,%x\n", id, args[0], args[1], args[2], args[3], args[4]);};
void varprintf6(uint32_t id, char * str, uint32_t *args) {printf("%x:%x,%x,%x,%x,%x,%x\n", id, args[0], args[1], args[2], args[3], args[4], args[5]);};
void varprintf7(uint32_t id, char * str, uint32_t *args) {printf("%x:%x,%x,%x,%x,%x,%x,%x\n", id, args[0], args[1], args[2], args[3], args[4], args[5], args[6]);};
void varprintf8(uint32_t id, char * str, uint32_t *args) {printf("%x:%x,%x,%x,%x,%x,%x,%x,%x\n", id, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7]);};
void varprintf9(uint32_t id, char * str, uint32_t *args) {printf("%x:%x,%x,%x,%x,%x,%x,%x,%x,%x\n", id, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8]);};
void varprintf10(uint32_t id, char * str, uint32_t *args) {printf("%x:%x,%x,%x,%x,%x,%x,%x,%x,%x,%x\n", id, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9]);};
void varprintf11(uint32_t id, char * str, uint32_t *args) {printf("%x:%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x\n", id, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10]);};
void varprintf12(uint32_t id, char * str, uint32_t *args) {printf("%x:%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x\n", id, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11]);};
void varprintf13(uint32_t id, char * str, uint32_t *args) {printf("%x:%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x\n", id, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12]);};
void varprintf14(uint32_t id, char * str, uint32_t *args) {printf("%x:%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x\n", id, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13]);};
void varprintf15(uint32_t id, char * str, uint32_t *args) {printf("%x:%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x\n", id, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13], args[14]);};
void varprintf29(uint32_t id, char * str, uint32_t *args) {printf("%x:%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x\n", id, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13], args[14],
		args[15], args[16], args[17], args[18], args[19], args[20], args[21], args[22], args[23], args[24], args[25], args[26], args[27], args[28]);};
void varprintf31(uint32_t id, char * str, uint32_t *args) {printf("%x:%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x\n", id, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13], args[14],
		args[15], args[16], args[17], args[18], args[19], args[20], args[21], args[22], args[23], args[24], args[25], args[26], args[27], args[28], args[29], args[30]);};
void varprintf64(uint32_t id, char * str, uint32_t *args) {printf("%x:%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x\n", id, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13], args[14],
		args[15], args[16], args[17], args[18], args[19], args[20], args[21], args[22], args[23], args[24], args[25], args[26], args[27], args[28], args[29], args[30], args[31], args[32], args[33],
		args[34], args[35], args[36], args[37], args[38], args[39], args[40], args[41], args[42], args[43], args[44], args[45], args[46], args[47], args[48], args[49], args[50], args[51], args[52],
		args[53], args[54], args[55], args[56], args[57], args[58], args[59], args[60], args[61], args[62], args[63]);};
#else
void varprintf0(uint32_t id, char * str, uint32_t *args) {printf(str);};
void varprintf1(uint32_t id, char * str, uint32_t *args) {printf(str, args[0]);};
void varprintf2(uint32_t id, char * str, uint32_t *args) {printf(str, args[0], args[1]);};
void varprintf3(uint32_t id, char * str, uint32_t *args) {printf(str, args[0], args[1], args[2]);};
void varprintf4(uint32_t id, char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3]);};
void varprintf5(uint32_t id, char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4]);};
void varprintf6(uint32_t id, char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4], args[5]);};
void varprintf7(uint32_t id, char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4], args[5], args[6]);};
void varprintf8(uint32_t id, char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7]);};
void varprintf9(uint32_t id, char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8]);};
void varprintf10(uint32_t id, char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9]);};
void varprintf11(uint32_t id, char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10]);};
void varprintf12(uint32_t id, char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11]);};
void varprintf13(uint32_t id, char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12]);};
void varprintf14(uint32_t id, char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13]);};
void varprintf15(uint32_t id, char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13], args[14]);};
void varprintf29(uint32_t id, char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13], args[14],
		args[15], args[16], args[17], args[18], args[19], args[20], args[21], args[22], args[23], args[24], args[25], args[26], args[27], args[28]);};
void varprintf31(uint32_t id, char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13], args[14],
		args[15], args[16], args[17], args[18], args[19], args[20], args[21], args[22], args[23], args[24], args[25], args[26], args[27], args[28], args[29], args[30]);};
void varprintf64(uint32_t id, char * str, uint32_t *args) {printf(str, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13], args[14],
		args[15], args[16], args[17], args[18], args[19], args[20], args[21], args[22], args[23], args[24], args[25], args[26], args[27], args[28], args[29], args[30], args[31], args[32], args[33],
		args[34], args[35], args[36], args[37], args[38], args[39], args[40], args[41], args[42], args[43], args[44], args[45], args[46], args[47], args[48], args[49], args[50], args[51], args[52],
		args[53], args[54], args[55], args[56], args[57], args[58], args[59], args[60], args[61], args[62], args[63]);};
#endif
static void (*varprintf[])(uint32_t id, char * str, uint32_t *args) = {
		&varprintf0, &varprintf1, &varprintf2, &varprintf3,
		&varprintf4, &varprintf5, &varprintf6, &varprintf7,
		&varprintf8, &varprintf9, &varprintf10, &varprintf11,
		&varprintf12, &varprintf13, &varprintf14, &varprintf15,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, &varprintf29, NULL, &varprintf31,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL,  &varprintf64,
};

static void get_streaming_message(uint32_t base, uint32_t id)
{
	uint32_t index = get_mail(base, 1);
	uint32_t i, args[64];
	int32_t res;
	char *str;

	for (i = 0; i < (index & 0xffff); i++)
		args[i] = get_mail(base, 1);

	if((get_ddr_phy_debug_string(id, index, &str) == 0) &&
			((index & 0xffff) < ARRAY_SIZE(varprintf)) &&
			(varprintf[i] != NULL))
		(*(varprintf[i]))(index, str, args);
	else
		printf("PHY: Unknown message 0x%08x\n", index);
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
		if(mail == 0xff)
			return -4;
	}
}

int32_t run_sequence(uint32_t cbase, uint32_t phybase, init_sequence_t s,
		firmware_t *f, int32_t fs, chip_settings_t *sets, unique_sequence_t *u)
{
	uint32_t i, j, k, offset = 3, cols, rows, last_unique = 0;
	int32_t res = 0;
	uint16_t val;

	debug("PHY INIT: Running sequence base %#x, phy %#x, size %d\n", cbase, phybase, s.size);

	if((s.elements == NULL) && (s.size != 0))
		return -1;

	for(i = 0; i < s.size && res == 0; i++) {
		debug("PHY INIT: Executing element %d: %s [%#x] = %#x\n", i, s.elements[i].type < PHY_INIT_TYPE_NUM ? ops[s.elements[i].type] : "Unknown", s.elements[i].addr, s.elements[i].value);
		switch(s.elements[i].type) {
		case PHY_INIT_TYPE_WRITE:
			do_apb_write(cbase, s.elements[i].addr, s.elements[i].value);
			break;
		case PHY_INIT_TYPE_WRITE_FREQ:
			res = s.elements[i].value;
			for(j = 0; u && (j < u->size); j++)
				if((u->elements[j].addr == s.elements[i].addr) &&
					(u->elements[j].type == PHY_INIT_TYPE_WRITE)) {
						res = u->elements[j].value;
						break;
					}
			debug("PHY INIT: Frequency specific value: %#x\n", res);
			do_apb_write(cbase, s.elements[i].addr, res);
			res = 0;
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
		case PHY_INIT_TYPE_PHY_FREQ:
			res = s.elements[i].value;
			for(j = last_unique; u && (j < u->size); j++)
				if((u->elements[j].addr == s.elements[i].addr) &&
					(u->elements[j].type == PHY_INIT_TYPE_PHY)) {
						res = u->elements[j].value;
						last_unique = j;
						break;
					}
			debug("PHY INIT: Frequency specific value: [%#x] = %#x\n", s.elements[i].addr, res);
			do_phy_write(phybase, s.elements[i].addr, res);
			res = 0;
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
		case PHY_INIT_TYPE_DEBUG_RANGE:
			for(j = 0; j < s.elements[i].value; j++)
				printf("PHY INIT: Debug message addr %#x, value %#x\n", s.elements[i].addr + j, do_phy_read(phybase, s.elements[i].addr + j));
			break;
		case PHY_INIT_TYPE_DUMPEYE:
			printf("PHY INIT: Dumping EYE at address %#x\n", s.elements[i].addr);
			cols = do_phy_read(phybase, s.elements[i].addr) & 0xff;
			rows = (do_phy_read(phybase, s.elements[i].addr) >> 8) & 0xff;
			printf("PHY INIT: Columns: %d, rows: %d\n", cols, rows);
			for(j = 0; j < rows; j++) {
				for(k = 0; k < cols; k += 2) {
					val = do_phy_read(phybase, s.elements[i].addr + offset);
					printf("%02x %02x ", val & 0xff, (val >> 8) & 0xff);
					offset++;
				}
				printf("\n");
			}
			break;
		case PHY_INIT_TYPE_DDRCSETTINGS:
			if(sets == NULL)
				res = -4;
			else
				board_specific_ddrc_settings(cbase, sets);
			break;
		case PHY_INIT_TYPE_PHYSETTINGS:
			if(sets == NULL)
				res = -4;
			else
				board_specific_ddrphy_settings(phybase, sets);
			break;
		default:
			break;
		}
	}

	return res;
}
