/******************************************************************************
 *
 *  (C)Copyright 2005 - 2011 Marvell. All Rights Reserved.
 *
 *  THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MARVELL.
 *  The copyright notice above does not evidence any actual or intended
 *  publication of such source code.
 *  This Module contains Proprietary Information of Marvell and should be
 *  treated as Confidential.
 *  The information in this file is provided for the exclusive use of the
 *  licensees of Marvell.
 *  Such users have the right to use, modify, and incorporate this code into
 *  products for purposes authorized by the license agreement provided they
 *  include this notice and the associated copyright notice with any such
 *  product.
 *  The information in this file is provided "AS IS" without warranty.

 ******************************************************************************
**
**  FILENAME:	PlatformConfig.h
**
**  PURPOSE: 	Platform specific header to set parameters
**
**
******************************************************************************/

#ifndef __flashearse_check_h
#define __flashearse_check_h

#include "common.h"
#include "cpu.h"
#include "guilin.h"
#include "qspi.h"
#include "qspi_nor.h"

#define QUECTEL_FOTA_UPDATER_PARTITION
#define QUEC_NORFLASH_ERASE_OPTIMIZE
#define QUEC_UART2_ENABLE   1
#ifdef QUEC_NORFLASH_ERASE_OPTIMIZE
#define DECOMPRESS_TEMP_ADDR	       		 0x071B0000 //quectel modification: 0x07200000->0x071B0000
// flash file system
#define QUEC_NOR_FLASH_FSYS_ADDR                0xDE0000    
#define QUEC_NOR_FLASH_FSYS_ADDR_END          ( 0xFD0000-1)
//This block is record
//#define QUEC_RECORD_BLOCKERASE_AREA_ADD   		0xFD0000  

#define QUEC_RECORD_MAGIC1        (0x78E5D4C2)
#define QUEC_RECORD_MAGIC2        (0x54F7D60E)  // only record cell 0 used , for mark record area is erase successed

//#define QUEC_RECORD_BLOCKERASE_AREA_SIZE  64*1024
#define NoError    0x0


typedef enum
{
    BOOT_FLASH			= 0,
    SAVE_STATE_FLASH	= 1
} FlashBootType_T;


typedef enum
{
	Record_type_Page,
	Record_type_Block
}quec_Record_type_enum;
	

typedef struct
{
	UINT32 flag;// 0xAAA55AA55 
	UINT32 reserve; 
}quec_Eraseflag_s;

typedef struct
{
	UINT32 RecordMagic;
	UINT32 BlockId;// recored the eraseing  block id ,   
	UINT32 Record_type; // recored the eraseing  block or page
}quec_RecordInfo_s;

typedef struct
{
	quec_RecordInfo_s ReInfo;
	quec_Eraseflag_s Eflag;
}quec_flashErase_record_s;


#define QUEC_CFG_BYTE_LEN	16
#define QUEC_CFG_BYTE_STR	"QuecCfg"
#define  QUEC_PRODUCTION_CFG_ADDR     0x00FD7000
/*========================================================================
 *  Type Definition
 *========================================================================*/
//to save all configuration
//need 4 bytes align
#if QUEC_UART2_ENABLE
typedef struct quec_production_cfg
{
	char quec_chk_bytes[QUEC_CFG_BYTE_LEN];//for header check
	int quec_dualport_support;//dual at serial port support or not
	int quec_fota_exec_opt;
	int quec_recovery_exec_opt;
}quec_production_cfg_s;
#endif


void Quec_FlashErase_Optimize(void);
UINT32 ReadFlash(UINT32 flash_addr, UINT32 buffer, UINT32 total_size, FlashBootType_T fbt);

int quec_production_cfg_get(void);
extern quec_production_cfg_s quec_production_config;


#endif

#endif

