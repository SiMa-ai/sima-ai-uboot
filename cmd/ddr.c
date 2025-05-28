// SPDX-License-Identifier: GPL-2.0+
/*  (C) Copyright 2022 SiMa.ai
 *  Filename        : ddr.c
 *  Author Name 	: Yurii  Konovalenko
 *
 *  Description: 'ddr*' command for debugging SiMa.ai DDR PHY controller
	             configuration
 *
 *************************************************************************/

#include <command.h>
#include <asm/global_data.h>
#include <asm/arch/simaai_ddr_utils.h>

DECLARE_GLOBAL_DATA_PTR;


#ifdef CONFIG_NEEDS_MANUAL_RELOC
#define RELOC(a)	((typeof(a))((unsigned long)(a) + gd->reloc_off))
#else
#define RELOC(a)	a
#endif

static const char supported_settings[][16] = {
	"tximp",
	"atximp",
	"txodt",
	"mempdds",
	"memcaodt",
	"memdqodt",
	"memcavref",
	"memdqvref",
	"phyvref",
	"tximpse",
	"tximpdiff",
	"atximpse",
	"atximpdiff",
	"atximpcmos",
	"odtimpse",
	"odtimpdiff",
	"odtdq",
	"odtwck",
	"memcsodt",
	"memodtnt",
};

static int do_ddrreg(struct cmd_tbl *cmdtp, int flag, int argc,
		   char *const argv[])
{
	int rcode = CMD_RET_SUCCESS, mask, res = 0, addr, val;

	switch (argc) {
	case 4:			/* get register */
		mask = simple_strtoul(argv[1], NULL, 16);
		addr = simple_strtoul(argv[3], NULL, 16);
		if(argv[2][0] == 'c')
			res = sima_ddr_get_creg(mask, addr);
		else if(argv[2][0] == 'p')
			res = sima_ddr_get_phyreg(mask, addr);
		else
			rcode = CMD_RET_USAGE;
		if(res < 0)
			rcode = CMD_RET_FAILURE;
		break;
	case 5:			/* set register */
		mask = simple_strtoul(argv[1], NULL, 16);
		addr = simple_strtoul(argv[3], NULL, 16);
		val = simple_strtoul(argv[4], NULL, 16);
		if(argv[2][0] == 'c')
			res = sima_ddr_set_creg(mask, addr, val);
		else if(argv[2][0] == 'p')
			res = sima_ddr_set_phyreg(mask, addr, val);
		else
			rcode = CMD_RET_USAGE;
		if(res < 0)
			rcode = CMD_RET_FAILURE;
		break;
	default:
		rcode = CMD_RET_USAGE;
	}

	return rcode;
}

static int do_ddrcfg(struct cmd_tbl *cmdtp, int flag, int argc,
		   char *const argv[])
{
	int rcode = CMD_RET_SUCCESS, res = 0, i;
	uint32_t index, val;

	switch (argc) {
	case 1:			/* dump DDR controller/PHY settings */
		sima_ddr_dump_settings();
		break;
	case 4:			/* set DDR controller/PHY setting */
		index = simple_strtoul(argv[1], NULL, 10);
		val = simple_strtoul(argv[3], NULL, 10);
		for(i = 0; i < ARRAY_SIZE(supported_settings); i++)
			if(!strcmp(argv[2], supported_settings[i]))
				break;
		if(i < ARRAY_SIZE(supported_settings)) {
			res = sima_ddr_set_settings(index, i, val);
			if(res != 0){
				sima_ddr_dump_supported_values();
				rcode = CMD_RET_USAGE;	
			}
		} else
			rcode = CMD_RET_USAGE;
		break;
	default:
		rcode = CMD_RET_USAGE;
	}

	return rcode;
}

static int do_ddrcmd(struct cmd_tbl *cmdtp, int flag, int argc,
		   char *const argv[])
{
	int rcode = CMD_RET_SUCCESS;

	if(argc < 2)
		return CMD_RET_USAGE;

	if(!strcmp(argv[1], "init")) {	/* re-run init sequence */
		sima_ddr_reset();
		sima_ddr_init();
	} else if(!strcmp(argv[1], "type")) {	/* type of CLI */
		if(&rcode < 0x80000000)
			printf("DDR CLI\n");
		else
			printf("MAIN CLI\n");
	} else /* unknown command */
		rcode = CMD_RET_USAGE;

	return rcode;
}

/***************************************************/
U_BOOT_CMD(
	ddrreg,	5,	1,	do_ddrreg,
	"get/set DDR controller/PHY register",
	"mask target address value\n"
	"  - with 3 arguments: print controller/PHY register\n"
	"  - with 4 arguments: set controller/PHY register\n"
	"  Possible target values: c (DDR Controller), p (PHY)"

);

U_BOOT_CMD(
	ddrcfg,	4,	1,	do_ddrcfg,
	"Get/set DDR controller/PHY settings",
	"index setting value\n"
	"  - with 0 arguments: dump DDR controller/PHY settings\n"
	"  - with 3 arguments: set [setting] in DDR controller [index] to value\n"
	"           supported settings: tximp, atximp, txodt, mempdds, memcaodt, memdqodt, memcavref,\n"
	"                               memdqvref, phyvref, tximpse, tximpdiff, atximpse, atximpdiff,\n"
	"                               atximpcmos, odtimpse, odtimpdiff, odtdq, odtwck, memcsodt, memodtnt\n"
);

U_BOOT_CMD(
	ddrcmd,	4,	1,	do_ddrcmd,
	"Run generic DDR commands",
	"command [arguments]\n"
	"  Supported commands: init (re-run init sequence), type (type of CLI)\n"
	"  Arguments of init: none\n"
);
