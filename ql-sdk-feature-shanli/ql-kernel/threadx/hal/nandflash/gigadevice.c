// SPDX-License-Identifier: GPL-2.0
/*
 * Author:
 *	Chuanhong Guo <gch981213@gmail.com>
 */

#include "spinand.h"
#include "quec_common.h"


#define SPINAND_MFR_GIGADEVICE     0xC8

extern int spinand_disable_ecc(struct spinand_device * spinand);
extern int spinand_select_target(struct spinand_device *spinand, unsigned int target);


static int gigadevice_check_ecc_common(unsigned char val)
{
    if((val &(1 << 5) != 0) && (val &(1 << 4) == 0))
        return 1;
    else
        return 0;
}

static const struct spinand_info gigadevice_spinand_table[] = {
	SPINAND_INFO("GD5F1GQ4xA",
		     SPINAND_ID(SPINAND_READID_METHOD_OPCODE_ADDR, 0xF1),
		     NAND_MEMORG(1, 2048, 64, 64, 1024, 20, 1, 1, 1),
		     NAND_ECCREQ(8, 512, 0)),

	SPINAND_INFO("GD5F2GQ4xA",
		     SPINAND_ID(SPINAND_READID_METHOD_OPCODE_ADDR, 0xF2),
		     NAND_MEMORG(1, 2048, 64, 64, 2048, 40, 1, 1, 1),
		     NAND_ECCREQ(8, 512, 0)),

	SPINAND_INFO("GD5F4GQ4xA",
		     SPINAND_ID(SPINAND_READID_METHOD_OPCODE_ADDR, 0xF4),
		     NAND_MEMORG(1, 2048, 64, 64, 4096, 80, 1, 1, 1),
		     NAND_ECCREQ(8, 512, 0)),

	SPINAND_INFO("GD5F1GQ4UExxG",
		     SPINAND_ID(SPINAND_READID_METHOD_OPCODE_ADDR, 0xF1),
		     NAND_MEMORG(1, 2048, 128, 64, 1024, 20, 1, 1, 1),
		     NAND_ECCREQ(8, 512, 0)),

	SPINAND_INFO("GD5F1GQ4UFxxG",
		     SPINAND_ID(SPINAND_READID_METHOD_OPCODE, 0xB1, 0x48),
		     NAND_MEMORG(1, 2048, 128, 64, 1024, 20, 1, 2, 1),
		     NAND_ECCREQ(8, 512, 0)),
		     
	SPINAND_INFO("GD5F4GQ6RExxG",
		     SPINAND_ID(SPINAND_READID_METHOD_OPCODE_DUMMY, 0x45),
		     NAND_MEMORG(1, 2048, 64, 64, 2048, 20, 1, 2, 1),
		     NAND_ECCREQ(8, 512, 0)),
	SPINAND_INFO("GD5F1GQ5RExxG",
		     SPINAND_ID(SPINAND_READID_METHOD_OPCODE_DUMMY, 0x41),
		     NAND_MEMORG(1, 2048, 64, 64, 1024, 20, 1, 1, 1),
		     NAND_ECCREQ(8, 512, 0)),
	SPINAND_INFO("GD5F1GM7RExxG",
		     SPINAND_ID(SPINAND_READID_METHOD_OPCODE_DUMMY, 0x81),
		     NAND_MEMORG(1, 2048, 128, 64, 1024, 20, 1, 1, 1),
		     NAND_ECCREQ(8, 512, 0)),
    SPINAND_INFO("GD5F2GM7RExxG",
     		 SPINAND_ID(SPINAND_READID_METHOD_OPCODE_DUMMY, 0x82),
     		 NAND_MEMORG(1, 2048, 128, 64, 2048, 20, 1, 1, 1),
     		 NAND_ECCREQ(8, 512, 1)),
};

static int gigadevice_spinand_init(struct spinand_device *spinand)
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


static const struct spinand_manufacturer_ops gigadevice_spinand_manuf_ops = {
	.init = gigadevice_spinand_init,
	.check_ecc = gigadevice_check_ecc_common,
};

const struct spinand_manufacturer gigadevice_spinand_manufacturer = {
	.id = SPINAND_MFR_GIGADEVICE,
	.name = "GigaDevice",
	.chips = gigadevice_spinand_table,
	.nchips = ARRAY_SIZE(gigadevice_spinand_table),
	.ops = &gigadevice_spinand_manuf_ops,
};
