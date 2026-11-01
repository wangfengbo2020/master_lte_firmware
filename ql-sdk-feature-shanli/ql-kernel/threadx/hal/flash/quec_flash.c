/*==========================================================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
===========================================================================================================*/

/*==========================================================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN              WHO         WHAT, WHERE, WHY
------------     -------     -------------------------------------------------------------------------------
09/04/2022        Sharon.li  此文件是操作内部Nor Flash的(QSPI)的接口INTERNAL_NORFLASH
                 Amos/Egan   1、实现分区保护，防止有些分区数据被误擦除 宏,QUEC_LIMIT_FLASH_ERASE
                             2、正在进行4K擦除的时候掉电，可能会影响相邻block的bit翻转，需要记录当前4K是否擦除
                                完成,如果没有完成，开机的时候在boot侧，进行补擦，完成这个4K的擦除，
                                宏QUEC_NORFLASH_ERASE_OPTIMIZE
===========================================================================================================*/



#ifndef _QUEC_FLASH_H
#define _QUEC_FLASH_H

#include "quec_common.h"
#include "lfs_cache.h"
#include "FDI_FILE.h"
#include "quec_debug.h"
#include "loadTable.h"
#include "FlashPartition.h"
#include "qspi_nor.h"
#include "Flash_wk.h"
#include "quec_cust_feature.h"
#include "loadTable.h"
#include "quec_flash.h"



#ifdef __cplusplus
extern "C" {
#endif

#ifdef  QUECTEL_PROJECT_CUST
#ifdef QUEC_NORFLASH_ERASE_OPTIMIZE
#define quec_flash_printf(msg, ...)  custom_log("Flash_LOG", msg, ##__VA_ARGS__)
#endif

UINT32 get_quec_cfg_start_address(void)
{
	_ptentry * QUEC_CFG_Entry= ptable_find_entry("quec_cfg");
	return QUEC_CFG_Entry->vstart;
}
UINT32 quec_get_machine_start_address(void)
{
	_ptentry * QUEC_CFG_Entry= ptable_find_entry("machine");
	return QUEC_CFG_Entry->vstart;
}

UINT32 get_erase_rd_start_address(void)
{
#if 1
	_ptentry * erase_rd_start_Entry= ptable_find_entry("erase_rd");
	if(erase_rd_start_Entry==NULL)
		return NULL;
	return erase_rd_start_Entry->start;  /* 3601s internal spi nor flash */

#else
	return pLoadTable->lt_area_armlink_symbol.armlink_symbol_info.nvm_start_address.value;
#endif
}

UINT32 get_erase_rd_bin_size(void)
{
	_ptentry * erase_rd_begin_Entry= ptable_find_entry("erase_rd");
	if(erase_rd_begin_Entry==NULL)
		return NULL;
	return erase_rd_begin_Entry->vsize;
}

UINT32 QUEC_EraseSectorFlash(UINT32 flash_addr, UINT32 size, FlashBootType_T fbt)
{
	fatal_printf("EraseFlash_4k 0x%x 0x%x\r\n", flash_addr, size);

	spi_nor_do_erase_4k(flash_addr,size, 0);

    return 0;
}
#endif

#ifdef QUEC_AT_PRODUCTION
UINT32 CHECK_FLASH_AREA(const char *name,UINT32 flash_addr,UINT32 flash_size)
{
	_ptentry *pnt;
	pnt=ptable_find_entry(name);
	if(pnt==NULL)
	{
		return 0;
	}
	if(flash_addr>=pnt->start)
	{
		if((flash_addr+ flash_size)<= (pnt->start + pnt->size))
		{
			return 1;
		}
	}
	return 0;
}
#endif

#if QUEC_LIMIT_FLASH_ERASE //分区擦除保护功能，用于实现当前分区是否可以被擦除
typedef struct
{
	UINT32 start_addr;    //addr not 0x80000000
	UINT32 end_addr;		 
}QUEC_PART_ADDR_S;

typedef struct
{
	char name[16];
	char erase_flag;
	QUEC_PART_ADDR_S AddrInfo;
}QUEC_PART_ADDR_TYPE_S;
/*****************************************************************
此结构体数组用来控制flash上分区使用flash相关接口的擦、写使能；
如需修改对应分区擦写权限，则需要修改QUEC_PART_ADDR_TYPE_S类型中的erase_flag变量：
1.可使用flash接口进行擦写此分区；0：此分区不可使用flash接口进行擦写。

以customer_app为例，原本此分区erase_flag为0，所以是不可擦、写属性，如果需要将app分区修改为可擦写属性，
则将{"customer_app",NULL}修改为{"customer_app",1,NULL}即可。
*******************************************************************/
QUEC_PART_ADDR_TYPE_S QUEC_PART_ADDR_TYPE_AERA[]={
{"nvm",1,NULL},
{"quec_cfg",1,NULL},
{"fota_param",1,NULL},
{"factory_a",1,NULL},
{"factory_b",1,NULL},
{"erase_rd",1,NULL},
{"bootloader",0,NULL},
{"ptable",0,NULL},
{"fwcerts",0,NULL},
{"rd",0,NULL},
{"cp",0,NULL},
{"dsp",0,NULL},
{"rfbin",0,NULL},
{"customer_app",1,NULL},
{"reserved",0,NULL},
{"logo",0,NULL},
};

/*****************************************************************
*	ASR 平台全系列 qfttest 功能导入
*	https://ticket.quectel.com/browse/BZASR-1931?filter=-1
******************************************************************/
#define QFTEST_PARTITION_COUNT_MAX 	(sizeof(QUEC_PART_ADDR_TYPE_AERA)/sizeof(QUEC_PART_ADDR_TYPE_AERA[0]))
UINT32 G_QftestEraseCount[QFTEST_PARTITION_COUNT_MAX] = {0};

UINT32 CHECK_FLASH_AREA_ADDR_CONFIG(void)
{
	int len = QFTEST_PARTITION_COUNT_MAX;
	_ptentry *pnt;
	int i;
	for(i=0;i<len;i++)
	{
		pnt=ptable_find_entry(QUEC_PART_ADDR_TYPE_AERA[i].name);
		if(pnt==NULL)
		{
			uart_printf("Egan_check flash not found name=%s\r\n",QUEC_PART_ADDR_TYPE_AERA[i].name);
			continue;
		}
		QUEC_PART_ADDR_TYPE_AERA[i].AddrInfo.start_addr=pnt->start;
		QUEC_PART_ADDR_TYPE_AERA[i].AddrInfo.end_addr=pnt->start + pnt->size;
//		uart_printf("Egan_flash_name=%s flash_addr=0x%x flash_end=0x%x \r\n",QUEC_PART_ADDR_TYPE_AERA[i].name,QUEC_PART_ADDR_TYPE_AERA[i].AddrInfo.start_addr,QUEC_PART_ADDR_TYPE_AERA[i].AddrInfo.end_addr);
	}
	
    return 0;
}

//检查传入的FLASH地址是否可以被擦除，返回值0不能被擦除；1能被擦除
UINT32 FLASH_LIMIT_ALLOW_AREA(UINT32 flash_addr,UINT32 flash_size,BOOL rw_flag)
{
	int len = QFTEST_PARTITION_COUNT_MAX;
	int i;
	QUEC_PART_ADDR_TYPE_S *ptr=QUEC_PART_ADDR_TYPE_AERA;

	for(i=0;i<len;i++)
	{
		if((flash_addr>=ptr[i].AddrInfo.start_addr)&&((flash_addr + flash_size) <= ptr[i].AddrInfo.end_addr))
		{			
			if((ptr[i].erase_flag==1)&&(flash_size!=NULL))
			{
				if(rw_flag)
					G_QftestEraseCount[i]++;
				break;
			}
			else{
				return 0;
			}	
		}

		if(((flash_addr>ptr[i].AddrInfo.start_addr)&&(flash_addr<ptr[i].AddrInfo.end_addr))
			||(((flash_addr+flash_size) > ptr[i].AddrInfo.start_addr)&&((flash_addr+flash_size)<ptr[i].AddrInfo.end_addr)))
		{//对擦除的起始地址 和 结束地址 分别判断，如果分别存在不能擦除的分区里，则返回0
			if(ptr[i].erase_flag==0)
			{
				return 0;
			}
		}
	}
	return 1;
}
/*****************************************************************
* Function: QUEC_PART_ADDR_TYPE_AERA_GET_CNT
*
* Description:
* 	获取数组QUEC_PART_ADDR_TYPE_AERA的下标值
* Parameters:
* 	name	[in] partition name
*
* Return:
* 	-1		failure
*****************************************************************/

int QUEC_PART_ADDR_TYPE_AERA_GET_CNT(const char *name)
{
	int len = QFTEST_PARTITION_COUNT_MAX;
	int i;
	for(i=0;i<len;i++)
	{
		if(!strcmp(name, QUEC_PART_ADDR_TYPE_AERA[i].name))
			return i;
	}
	
	return -1;
}
#endif



#ifndef MIN_SYS
#ifdef QUEC_AT_PRODUCTION
#ifdef QUEC_AT_FLASH_ERASE_COUNT_CMD
extern UINT16 *g_FlashBlkEraseCnt;// 6M for nvm erea
#define CHIP_SECTOR_SIZE 		  0x1000    //erase 4k each times
#else
UINT16 g_FlashBlkEraseCnt[1536]={0};// 6M for nvm erea
#endif
UINT16 g_FlashBlkEraseTotal = 0;    
#define  CHIP_SECTOR_SIZE 0x1000
#define  CRANE_SPI_BASE_ADD 0x80000000
extern UINT32 nvm_flash_start_addr;

#ifdef QUEC_FS_WEAR_BALANCE_VERIFY //QuecOpen 记录文件系统均衡的次数
UINT32 customer_fs_flash_start_addr = 0;
UINT32 gFsRWBkTotalCnt = 0; 				//存储文件系统擦写的总次数   
UINT32 *gFsPerBkRWCnt = NULL;				//存储每块block的擦写次数
UINT32 gFsTotalBkCnt = 0;					//存储文件系统block的数量
#endif

//记录flash_addr所在分区的第几个block，被擦除的次数
UINT32 Flash_erase_count_Set(UINT32 flash_addr,UINT32 size)
{
	int i=0;
	UINT32 nvm_block_id=(CRANE_SPI_BASE_ADD+flash_addr-nvm_flash_start_addr)/CHIP_SECTOR_SIZE;
//	fatal_printf("flash_id=0x%x\r\n",flash_id);
#ifdef QUEC_AT_FLASH_ERASE_COUNT_CMD
	if(g_FlashBlkEraseCnt == NULL)
		return 0;
#endif

	if(CHECK_FLASH_AREA("nvm",flash_addr,size))
	{
		for(i=0;i*CHIP_SECTOR_SIZE<size;i++)
		{
			g_FlashBlkEraseCnt[nvm_block_id+i]++;
			g_FlashBlkEraseTotal++;
		}
	}
#ifdef QUEC_FS_WEAR_BALANCE_VERIFY //QuecOpen 记录文件系统均衡的次数
	if(CHECK_FLASH_AREA("customer_fs",flash_addr,size))
	{
		UINT32 customer_fs_block_id=(CRANE_SPI_BASE_ADD+flash_addr-customer_fs_flash_start_addr)/CHIP_SECTOR_SIZE;
		//RTI_LOG("flash_addr(0x%x),size(0x%x),customer_fs_block_id(0x%x)\r\n",flash_addr,size,customer_fs_block_id);
		if(NULL != gFsPerBkRWCnt)
		{
			for(i=0;i*CHIP_SECTOR_SIZE<size;i++)
			{
				gFsPerBkRWCnt[customer_fs_block_id+i]++;
				gFsRWBkTotalCnt++;
			}
		}
	}
#endif
    return 0;
}

/*获取fs block擦写次数*/
int quec_fs_get_bk_erase_count(int flash_addr)
{
#ifdef QUEC_FS_WEAR_BALANCE_VERIFY //QuecOpen 记录文件系统均衡的次数
	if(CHECK_FLASH_AREA("customer_fs",flash_addr,0))
	{
		UINT32 customer_fs_block_id=(CRANE_SPI_BASE_ADD+flash_addr-customer_fs_flash_start_addr)/CHIP_SECTOR_SIZE;
		return gFsPerBkRWCnt[customer_fs_block_id];
	}
#endif	
	if(CHECK_FLASH_AREA("nvm",flash_addr,0))
	{
		UINT32 nvm_block_id=(CRANE_SPI_BASE_ADD+flash_addr-nvm_flash_start_addr)/CHIP_SECTOR_SIZE;
		return g_FlashBlkEraseCnt[nvm_block_id];
	}
	
	return -1;
}

#endif 
#endif /*MIN_SYS*/


#ifdef QUEC_NORFLASH_ERASE_OPTIMIZE //补擦的实现

#ifdef QUECTEL_PROJECT_CUST 
char ERASE_RECORD_AREA[][16]={"nvm"};//目前仅仅记录nvm分区的擦除block
#else
const char ERASE_RECORD_AREA[][16]={"nvm"};
#endif
UINT32 FLASH_ERASE_RECORD_ALLOW_AREA(UINT32 flash_addr,UINT32 size)
{
	int len =sizeof(ERASE_RECORD_AREA)/sizeof(ERASE_RECORD_AREA[0]);
	_ptentry *pnt;
	int i;
	for(i=0;i<len;i++)
	{
		pnt=ptable_find_entry(ERASE_RECORD_AREA[i]);
		if(pnt==NULL)
		{
			if(0==i)
			{
				return NULL;
			}
			continue;
		}
		if(flash_addr >= pnt->start)
		{
			if((flash_addr+size) <= (pnt->start + pnt->size))
			{
//				uart_printf("%s\r\n",ERASE_RECORD_AREA[i]);
				return 1;
			}
		}
			
	}
	return NULL;	
}

extern UINT32 Quec_EraseFlashExt(UINT32 flash_addr, UINT32 size);

#define NoError            					0x0

#define QUEC_RECORD_MAGIC1        (0x78E5D4C2)
#define QUEC_RECORD_MAGIC2        (0x54F7D60E)  // only record cell 0 used , for mark record area is erase successed
#define CHIP_SECTOR_SIZE 		  0x1000    //erase 4k each times
#define CHIP_BLOCK_SIZE 		  0x10000    //erase 4k each times


typedef enum
{
	Record_type_Block,
	Record_type_Page
}quec_Record_type_enum;


typedef struct
{
	UINT32 flag;// 0xAAA55AA55 
	UINT32 reserve; 
}quec_Eraseflag_s;

typedef struct
{
	UINT32 RecordMagic;
	UINT32 PageId;		// recored the eraseing  block id ,   
	UINT32 Record_type; // recored the eraseing  block or page
}quec_RecordInfo_s;

typedef struct
{
	quec_RecordInfo_s ReInfo;
	quec_Eraseflag_s Eflag;
}quec_flashErase_record_s;


UINT32 g_RecordCell = 0xffffffff;
UINT8  g_IsfirstTimeReadRecordblock = 1; 


void Quec_FlashEraseRecord_step1(UINT32 flash_addr,quec_Record_type_enum type)
{
	UINT32 Retval = NoError;
	quec_flashErase_record_s *p_BlkEraseRecordCell = NULL;
	quec_RecordInfo_s  *p_BlkERCellInfo = NULL;
	quec_Eraseflag_s *p_BlkERCellflag = NULL;
	quec_RecordInfo_s  BlkERecordCellInfo; 
	char *Record_buff = NULL;
	int i=0, flash_BlkSize = 0;
	UINT32 QUEC_RECORD_BLOCKREASE_AREA_SIZE=get_erase_rd_bin_size();
	UINT32 QUEC_RECORD_BLOCKREASE_AREA_ADD=get_erase_rd_start_address();
	if((!QUEC_RECORD_BLOCKREASE_AREA_SIZE)||(!QUEC_RECORD_BLOCKREASE_AREA_ADD))
	{	
		quec_flash_printf("not found erase_rd !!!");
		return ;
	}
	flash_BlkSize=type?CHIP_SECTOR_SIZE:CHIP_BLOCK_SIZE;	
	if(0 == g_IsfirstTimeReadRecordblock)
	{
		g_RecordCell++;
	}
	else
	{
		Record_buff = malloc(QUEC_RECORD_BLOCKREASE_AREA_SIZE);
		if(NULL == Record_buff)
		{
			quec_flash_printf("malloc failed !!!!!!!!");
			return;
		}
		Retval = spi_nor_do_read(QUEC_RECORD_BLOCKREASE_AREA_ADD,(unsigned int)Record_buff,QUEC_RECORD_BLOCKREASE_AREA_SIZE, 0);
		if( NoError != Retval)
		{

			if( NULL !=Record_buff )
			{
				free(Record_buff);
				Record_buff = NULL;
			}
			quec_flash_printf("Flash read failed !!");
			return;
		}
		// check record block is  erase  successed
		p_BlkEraseRecordCell = (quec_flashErase_record_s*)Record_buff; // check the 0 cell which is mark for  record area not erase
		p_BlkERCellInfo = (quec_RecordInfo_s*)Record_buff;
		if(QUEC_RECORD_MAGIC2  == p_BlkERCellInfo->RecordMagic  && 0x00 == p_BlkERCellInfo->PageId)
		{
			// scan for 1 . because cell 0 is a flag which mark the block is not erase
			for( i=1; i*sizeof(quec_flashErase_record_s)<QUEC_RECORD_BLOCKREASE_AREA_SIZE; i++)
			{
				p_BlkEraseRecordCell = (quec_flashErase_record_s*)Record_buff+i;
				p_BlkERCellInfo = (quec_RecordInfo_s *)p_BlkEraseRecordCell;// 
				p_BlkERCellflag = (quec_Eraseflag_s *)((char *)p_BlkEraseRecordCell + sizeof(p_BlkEraseRecordCell->ReInfo));
				if(( 0xffffffff == p_BlkERCellInfo->PageId ) && ( 0xffffffff == p_BlkERCellflag->flag)) // this record cell is not used 
				{
					break;
				}
			}
			g_RecordCell = i;
			quec_flash_printf("g_RecordCall =%d\r\n",g_RecordCell);
			g_IsfirstTimeReadRecordblock = 0;
			if( NULL !=Record_buff )
			{
				free(Record_buff);
				Record_buff = NULL;
			}
		}
		else
		{
			Retval = NoError;
			if( 0xffffffff  != p_BlkERCellInfo->RecordMagic )
			{
				Retval = Quec_EraseFlashExt(QUEC_RECORD_BLOCKREASE_AREA_ADD, QUEC_RECORD_BLOCKREASE_AREA_SIZE);
			}
			if(NoError ==Retval)
			{
				BlkERecordCellInfo.RecordMagic = QUEC_RECORD_MAGIC2;
				BlkERecordCellInfo.PageId  = 0x00;
				Retval = spi_nor_do_write(QUEC_RECORD_BLOCKREASE_AREA_ADD, (unsigned int)&BlkERecordCellInfo, sizeof(BlkERecordCellInfo),0);
				if(NoError !=Retval)
				{
					quec_flash_printf("[Ramos], write cell0  EraseRecord area erase flag faild !!!!!");
					return ;
				}
			}
			else
			{
				quec_flash_printf("[Ramos], erase record area fail !!!!!!");
				return ;
			}
			g_RecordCell = 1; //  record block erase cell form cell 1. because cell 0 used record RecordArea erase success flag
		}
		if( NULL !=Record_buff )
		{
				free(Record_buff);
				Record_buff = NULL;
		}
	}

	if(g_RecordCell*sizeof(quec_flashErase_record_s) >= QUEC_RECORD_BLOCKREASE_AREA_SIZE )
	{
		
		Retval = Quec_EraseFlashExt(QUEC_RECORD_BLOCKREASE_AREA_ADD, QUEC_RECORD_BLOCKREASE_AREA_SIZE);
		if(NoError ==Retval)
		{
			BlkERecordCellInfo.RecordMagic = QUEC_RECORD_MAGIC2;
			BlkERecordCellInfo.PageId  = 0x00;
			Retval = spi_nor_do_write(QUEC_RECORD_BLOCKREASE_AREA_ADD, (unsigned int)&BlkERecordCellInfo, sizeof(BlkERecordCellInfo),0);
			if(NoError !=Retval)
			{
				quec_flash_printf("[Ramos], write cell0  EraseRecord area erase flag faild !!!!!");
				return ;
			}
		}
		else
		{
			quec_flash_printf("[Ramos], erase record area fail !!!!!!");
			return ;
		}
		g_RecordCell = 1; //  record block erase cell form cell 1. because cell 0 used record RecordArea erase success flag
	}

	BlkERecordCellInfo.RecordMagic = QUEC_RECORD_MAGIC1;
	BlkERecordCellInfo.PageId = flash_addr/flash_BlkSize;
	BlkERecordCellInfo.Record_type=type;
	quec_flash_printf("addr %x type %d",flash_addr,type);
	Retval = spi_nor_do_write((QUEC_RECORD_BLOCKREASE_AREA_ADD+g_RecordCell*(sizeof(quec_flashErase_record_s))), (unsigned int)&(BlkERecordCellInfo), sizeof(BlkERecordCellInfo),0);
	if(NoError != Retval)
	{
		quec_flash_printf("WriteFlash failed, retval=%d, g_RecordCell=%d   need Record EraseblockId=%d !!!!", Retval, g_RecordCell,BlkERecordCellInfo.PageId);
	}
	memset(&BlkERecordCellInfo,0,sizeof(BlkERecordCellInfo));
	Retval = spi_nor_do_read((QUEC_RECORD_BLOCKREASE_AREA_ADD+g_RecordCell*(sizeof(quec_flashErase_record_s))), (unsigned int)&(BlkERecordCellInfo), sizeof(BlkERecordCellInfo),0);
	if(NoError != Retval)
	{
		quec_flash_printf("readFlash failed, retval=%d, g_RecordCell=%d   need Record EraseblockId=%d !!!!", Retval, g_RecordCell,BlkERecordCellInfo.PageId);
	}
	if((BlkERecordCellInfo.RecordMagic != QUEC_RECORD_MAGIC1) || ((BlkERecordCellInfo.PageId * (flash_BlkSize=type?CHIP_SECTOR_SIZE:CHIP_BLOCK_SIZE) < get_nvm_start_address()-0x80000000) || \
		(BlkERecordCellInfo.PageId * (flash_BlkSize=type?CHIP_SECTOR_SIZE:CHIP_BLOCK_SIZE) > get_nvm_end_address()-0x80000000)) || (BlkERecordCellInfo.Record_type != type))
	{
		quec_Eraseflag_s BlkERecordCellflag;
		BlkERecordCellflag.flag=0xAAAA5555;
		BlkERecordCellflag.reserve = 0xffffffff;

		if(0xffffffff != g_RecordCell)
		{
			//quec_debug("[Ramos] write cell(%d) RecordEraseblock(%d) flag 0xAA55!!",g_RecordCell,	flash_addr/flash_BlkSize);
			Retval = spi_nor_do_write((QUEC_RECORD_BLOCKREASE_AREA_ADD+g_RecordCell*sizeof(quec_flashErase_record_s)+sizeof(quec_RecordInfo_s)), (unsigned int)&BlkERecordCellflag, sizeof(BlkERecordCellflag),0);
			if(NoError != Retval)
			{
				quec_flash_printf("WriteFlash failed, retval=%d, g_RecordCell=%d, need Record EraseblockId=%d !!", Retval,g_RecordCell, flash_addr/flash_BlkSize);
			}
			quec_flash_printf("magic %x addr %x type %x %x",BlkERecordCellInfo.RecordMagic,BlkERecordCellInfo.PageId * (flash_BlkSize=type?CHIP_SECTOR_SIZE:CHIP_BLOCK_SIZE),BlkERecordCellInfo.Record_type,type);
		}
		else
		{
			quec_flash_printf("g_RecordCall(0x%x) not found !! need Record EraseblockId=%d!", g_RecordCell, flash_addr/flash_BlkSize);
		}

	}
	return;
}


void Quec_FlashEraseRecord_step2(UINT32 flash_addr,quec_Record_type_enum type)
{
	UINT32 Retval = NoError, flash_BlkSize = 0;
	quec_Eraseflag_s BlkERecordCellflag;
	UINT32 QUEC_RECORD_BLOCKREASE_AREA_SIZE=get_erase_rd_bin_size();
	UINT32 QUEC_RECORD_BLOCKREASE_AREA_ADD=get_erase_rd_start_address();
	if((!QUEC_RECORD_BLOCKREASE_AREA_SIZE)||(!QUEC_RECORD_BLOCKREASE_AREA_ADD))
	{	
		quec_flash_printf("not found erase_rd !!!");
		return ;
	}
	flash_BlkSize=type?CHIP_SECTOR_SIZE:CHIP_BLOCK_SIZE;;
	
	if(0xffffffff != g_RecordCell)
	{
		Retval = spi_nor_do_read((QUEC_RECORD_BLOCKREASE_AREA_ADD+g_RecordCell*sizeof(quec_flashErase_record_s)+sizeof(quec_RecordInfo_s)), (unsigned int)&BlkERecordCellflag, sizeof(BlkERecordCellflag),0);
		if(NoError != Retval)
		{
			quec_flash_printf("readFlash failed, retval=%d, g_RecordCell=%d!!!!", Retval, g_RecordCell);
		}
		if(BlkERecordCellflag.flag == 0xAAAA5555)
		{
			quec_flash_printf("flag is already write,jump it!!!");
		} else {
			BlkERecordCellflag.flag=0xAAAA5555;
			BlkERecordCellflag.reserve = 0xffffffff;
			//quec_debug("[Ramos] write cell(%d) RecordEraseblock(%d) flag 0xAA55!!",g_RecordCell,  flash_addr/flash_BlkSize);
			Retval = spi_nor_do_write((QUEC_RECORD_BLOCKREASE_AREA_ADD+g_RecordCell*sizeof(quec_flashErase_record_s)+sizeof(quec_RecordInfo_s)), (unsigned int)&BlkERecordCellflag, sizeof(BlkERecordCellflag),0);
			if(NoError != Retval)
			{
				quec_flash_printf("WriteFlash failed, retval=%d, g_RecordCell=%d, need Record EraseblockId=%d !!", Retval,g_RecordCell, flash_addr/flash_BlkSize);
			}
		}
	}
	else
	{
		quec_flash_printf("g_RecordCall(0x%x) not found !! need Record EraseblockId=%d!", g_RecordCell, flash_addr/flash_BlkSize);
	}
}

#endif







//erase a block for internal test
int quec_erase_block(int blk_index, unsigned int disable_protect)
{
	int flash_err = 0;
	lfsBlockInfo * p_blk_prop = NULL;

	p_blk_prop = GetLfsBlkInfo(0);

	//fatal_printf("EraseFlash_4k 0x%x 0x%x\r\n", flash_addr, size);

	if(blk_index*p_blk_prop->FlashBlockSize > quec_get_patition_end_address("all"))
	{
		return -1;
	}

	return spi_nor_do_erase_4k(blk_index*p_blk_prop->FlashBlockSize,p_blk_prop->FlashBlockSize, BOOT_FLASH);

}

unsigned int quec_norflash_do_read(unsigned char *patition_name, unsigned int addr, unsigned int buf_addr, unsigned int size)
{
	unsigned int  ret=-1;
	unsigned int  start_address=0;
	unsigned int  end_address=0;
	unsigned int  free_size=0;
	unsigned int  relative_addr = 0;

	relative_addr = addr&0x7FFFFFFF;
	_ptentry * get_patition_start_Entry= ptable_find_entry(patition_name);
	if(get_patition_start_Entry==NULL)
		return -1;
	start_address = get_patition_start_Entry->vstart;
	end_address=start_address+get_patition_start_Entry->size;
	
	if(addr<start_address || addr>end_address)
	{
		uart_printf("error address param \n");
		return -1;
	}
	
	free_size=end_address-addr; 
	if(size<=free_size)
	{		
		ret = spi_nor_do_read(relative_addr, buf_addr, size, 0);
	}
	else
	{
		uart_printf("no enough free space \n");
		ret = -1;		
	}
	return ret;
}


#ifdef __cplusplus
} /*"C" */
#endif

#endif

