/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
                winbond.c

GENERAL DESCRIPTION

    This file is for winbond SPI NAND.

EXTERNALIZED FUNCTIONS

INITIALIZATION AND SEQUENCING REQUIREMENTS

   Copyright (c) 2019 by ASR micro.  All Rights Reserved.
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

*===========================================================================

                        EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.


when         who        what, where, why
--------   ------     ----------------------------------------------------------
07/30/2020   zhoujin    Created module
===========================================================================*/

/*===========================================================================

                     INCLUDE FILES FOR MODULE

===========================================================================*/
#include "spinand.h"
#include "quec_common.h"

/*===========================================================================

            LOCAL DEFINITIONS AND DECLARATIONS FOR MODULE

This section contains local definitions for constants, macros, types,
variables and other items needed by this module.

===========================================================================*/

#define SPINAND_MFR_WINBOND     0xEF

extern int spinand_die_select(struct spinand_device * spinand, unsigned int target);
extern int spinand_disable_ecc(struct spinand_device * spinand);
extern int spinand_select_target(struct spinand_device *spinand, unsigned int target);

static int w25m02gv_select_target(struct spinand_device *spinand, unsigned int target)
{
	return spinand_die_select(spinand, target);
}


static const struct spinand_info winbond_spinand_table[] =
{
	SPINAND_INFO("W25M02GV",
			SPINAND_ID(SPINAND_READID_METHOD_OPCODE_DUMMY, 0xAB),
			NAND_MEMORG(1, 2048, 64, 64, 1024, 20, 1, 1, 2),
			NAND_ECCREQ(1, 512, 0),
			SPINAND_SELECT_TARGET(w25m02gv_select_target)),
	SPINAND_INFO("W25N01GW",
			SPINAND_ID(SPINAND_READID_METHOD_OPCODE_DUMMY, 0xBA),
			NAND_MEMORG(1, 2048, 64, 64, 1024, 20, 1, 1, 1),
			NAND_ECCREQ(1, 512, 0)),
	SPINAND_INFO("W25N01GV",
			SPINAND_ID(SPINAND_READID_METHOD_OPCODE_DUMMY, 0xAA),
			NAND_MEMORG(1, 2048, 64, 64, 1024, 20, 1, 1, 1),
			NAND_ECCREQ(1, 512, 0)),
};

static int winbond_spinand_init(struct spinand_device *spinand)
{
	struct nand_device *nand = spinand_to_nand(spinand);
	unsigned int  i = 0;

	for (i = 0; i < nand->memorg.ntargets; i++)
	{
		spinand_select_target(spinand, i);
		/* Special initilization of Vendor.	*/

		/* Enable ECC.	*/
		spinand_disable_ecc(spinand);
	}

	return 0;
}

static const struct spinand_manufacturer_ops winbond_spinand_ops = 
{
	.init = winbond_spinand_init,
};

const struct spinand_manufacturer winbond_spinand_manufacturer = {
	.id = SPINAND_MFR_WINBOND,
	.name = "WINBOND",
	.chips = winbond_spinand_table,
	.nchips = ARRAY_SIZE(winbond_spinand_table),
	.ops = &winbond_spinand_ops,
};



