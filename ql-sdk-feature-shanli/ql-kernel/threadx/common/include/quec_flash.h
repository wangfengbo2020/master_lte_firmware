/*==========================================================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
===========================================================================================================*/


#ifndef _QUEC_FLASH_H
#define _QUEC_FLASH_H

#include "quec_cust_feature.h"
#include "quec_common.h"

#ifdef __cplusplus
extern "C" {
#endif


#define CHIP_SECTOR_SIZE 		  0x1000    //erase 4k each times
#define CHIP_BLOCK_SIZE 		  0x10000    //erase 4k each times

typedef enum
{
	Record_type_Block,
	Record_type_Page
}quec_Record_type_enum;
	
extern void Quec_FlashEraseRecord_step1(UINT32 flash_addr,quec_Record_type_enum type);
extern void Quec_FlashEraseRecord_step2(UINT32 flash_addr,quec_Record_type_enum type);


#ifdef QUEC_NORFLASH_ERASE_OPTIMIZE

//当前要擦除的flash_addr是否需要被记录
UINT32 FLASH_ERASE_RECORD_ALLOW_AREA(UINT32 flash_addr,UINT32 size);


UINT32 get_erase_rd_start_address(void);

UINT32 get_erase_rd_bin_size(void);


#endif


UINT32 CHECK_FLASH_AREA_ADDR_CONFIG(void);

UINT32 FLASH_LIMIT_ALLOW_AREA(UINT32 flash_addr,UINT32 flash_size,BOOL rw_flag);

UINT32 quec_get_machine_start_address(void);

//erase a block for internal test
int quec_erase_block(int blk_index, unsigned int disable_protect);

//记录flash_addr所在分区的第几个block，被擦除的次数
UINT32 Flash_erase_count_Set(UINT32 flash_addr,UINT32 size);
unsigned int quec_norflash_do_read(unsigned char *patition_name, unsigned int addr, unsigned int buf_addr, unsigned int size);


#ifdef __cplusplus
} /*"C" */
#endif

#endif

