/****************************************************************
*  Copyright (C) of Marvell Internation Ltd     *
*****************************************************************/

/******************************************************************************
 *
 *	loadoffsets.h
 *
 *	This file contains all of the processor specific memory load addresses
 *	 used by the boot ROM or OBM code
 *
 ******************************************************************************/

#ifndef _LOADOFFSETS_H_
#define _LOADOFFSETS_H_

/* BootROM ISRAM Memory Map
0xD1000000 : ISRAM Start
0xD1000040 : Run Time Error Collection
0xD1000100 : Data + BSS, Transfer Struct (grows up)
0xD100A000 : Stack (grows down)
0xD100A000 : Initial TIM Load/Download Area	(Image Load Base)
*/

// ISRAM
#define ISRAM_PHY_ADDR						0xD1000000
#define ISRAM_IMAGE_LOAD_BASE				0xD100A000
#define PLATFORMISRAMLIMIT					0x16000     //88KB (0xD100_0000 - 0xD100_A000)

//  Download address for images and data
#define CS0Base								0x80000000
#define CS1Base								0x90000000
#define CS2Base								0xA0000000
#define CS3Base								0xB0000000

#define DDR_CS0_TBR							0x00000000
#define DDR_CS1_TBR							0x10000000
#define DDR_PHY_ADDR						0x00000000

#define OBM_RESTRICTED_DDR_SPACE			0x00040000 //should be named RESTRICED_SIZE, space is a misnomer
#define DDR_SPARE_AREA_ADDR					0x00040000
#define DDR_BLK_ZERO_BUF_ADDR				0x00060000	// 512 KB buffer to store blk 0
#define DDR_DOWNLOAD_AREA_ADDR				0x000E0000
#define DDR_VERIFY_BUFFER_OFFSET			0x01000000  // 16 MB offset

/**************************************************************************/
/* mDOC device physical address window location                           */
/**************************************************************************/
#define MDOC_START_ADDRESS	CS0Base   /* Used for P2Sample platform */

#endif
