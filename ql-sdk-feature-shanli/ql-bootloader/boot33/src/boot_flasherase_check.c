/*!
  @file
  boot_pin_test.c

  @brief
  It is used to test each pin  in the factory

*/
/*===========================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.


when         who      what, where, why
----------   ----     ---------------------------------------------------------
2020/02/18   Egan     Create the file, It is used to check nvm erase flash


===========================================================================*/

/*===========================================================================

                           INCLUDE FILES

===========================================================================*/


#include "boot_flasherase_check.h"
#include "ptable.h"


//#define flash_check_log(format, args...)   (uart_printf(format , __FILE__, __FUNCTION__ , __LINE__, ##args))
#define flash_check_log(...)
//#define uart_printf(...)   
typedef unsigned char	BYTE;	/* char must be 8-bit */

extern struct spi_flash_chip *chip;
struct spi_flash_chip *spichip=NULL;
UINT32 FlashIsSPI=0;
UINT8 isChip3601S=FALSE;
#define CHIP_SECTOR_SIZE 		  0x1000    //erase 4k each times


/* Compare memory block */
int quec_mem_cmp (const void* dst, const void* src, UINT32 cnt)	/* ZR:same, NZ:different */
{
	const BYTE *d = (const BYTE *)dst, *s = (const BYTE *)src;
	int r = 0;

	do {
		r = *d++ - *s++;
	} while (--cnt && r == 0);

	return r;
}

BOOL isChip_3601S(void)
{
    static UINT8 tmp = FALSE;
    if (!tmp)
    {
        *((volatile UINT32 *)0xd4282868) = 0x09;
        isChip3601S = (*((volatile UINT32 *)0xd4201404)>>12)&0x1; //bank0[28]
        *((volatile UINT32 *)0xd4282868) = 0x0;
        tmp = TRUE;
        
    }
    return isChip3601S;
}


unsigned int spi_nor_do_erase(unsigned int addr, unsigned int size)
{

	int ret = 0;
#ifdef RUN_XIP_MODE
    watchdogKick();
#endif
	if(isChip3601S)
	{
		if(FlashIsSPI)
		{
			flash_check_log("erase\r\n");
			ret = spichip->ops->erase_sector(spichip, addr); //erase a block
		}
		else
		{
			flash_check_log("erase_1\r\n");
			ret = chip->ops->erase(chip, addr, size);
		}
	}
	else
	{
		flash_check_log("erase_2\r\n");
		ret = chip->ops->erase(chip, addr, size);
	}

	return 0;

}

unsigned int spi_nor_do_read(unsigned int addr, unsigned int buf_addr, unsigned int size)
{

	int ret = 0;
	if(isChip3601S)
	{
		if(FlashIsSPI)
		{
			flash_check_log("read\r\n");
			ret = spichip->ops->read(spichip, addr, size, (uint8_t *)buf_addr);
		}
		else
		{
			flash_check_log("read_1\r\n");
			ret = chip->ops->read(chip, addr, size, (uint8_t *)buf_addr);
		}
	}
	else
	{
		flash_check_log("read_2\r\n");
		ret = chip->ops->read(chip, addr, size, (uint8_t *)buf_addr);
	}
		return ret;
}

unsigned int spi_nor_do_write(unsigned int addr, unsigned int buf_addr,unsigned int size)
{

	int ret = 0;
#ifdef RUN_XIP_MODE
    watchdogKick();
#endif
	if(isChip3601S)
	{
		if(FlashIsSPI)
		{
			flash_check_log("write\r\n");
			ret = spichip->ops->write(spichip, addr, size, (uint8_t *)buf_addr);
		}
		else
		{
			flash_check_log("write_1\r\n");
			ret = chip->ops->write(chip, addr, size, (uint8_t *)buf_addr);
		}
	}
	else
	{
		flash_check_log("write_2\r\n");
		ret = chip->ops->write(chip, addr, size, (uint8_t *)buf_addr);
		flash_check_log("write_2_end\r\n");
	}
	return 0;

}

#ifdef QUEC_UART2_ENABLE

quec_production_cfg_s quec_production_config={NULL,1};
/*
int quec_production_cfg_get(void)
{
	quec_production_cfg_s cfg_read = {0};
	
	memset(&cfg_read, 0, sizeof(quec_production_cfg_s));
	memset(&quec_production_config, 0, sizeof(quec_production_cfg_s));
	
	if (NoError != ReadFlash(QUEC_PRODUCTION_CFG_ADDR, &cfg_read, sizeof(quec_production_cfg_s), BOOT_FLASH))
	{
		uart_printf("read production_config from flash error!\n");
		return 0;
	}
//	uart_printf("Egan %s ,%d\r\n",cfg_read.quec_chk_bytes,quec_production_config.quec_dualport_support);
	if (0 != memcmp(cfg_read.quec_chk_bytes, QUEC_CFG_BYTE_STR, strlen(QUEC_CFG_BYTE_STR)))
	{
		return 0;
	}

	memcpy(&quec_production_config, &cfg_read, sizeof(quec_production_cfg_s));
	return 0;
}
*/
int quec_production_cfg_get(void)
{
	_ptentry * quec_cfg_Entry= ptable_find_entry("quec_cfg");
	volatile unsigned int *quec_cfs_add=quec_cfg_Entry->vstart;
	quec_production_cfg_s *ptr=(quec_production_cfg_s*)quec_cfs_add;
	if (0 == memcmp(ptr->quec_chk_bytes, QUEC_CFG_BYTE_STR, strlen(QUEC_CFG_BYTE_STR)))
	{
		uart_printf("quec_cfg ok %d\r\n",ptr->quec_dualport_support);
		quec_production_config.quec_dualport_support=ptr->quec_dualport_support;		
	}
	else
	{
		uart_printf("quec_cfg fail %d\r\n",ptr->quec_dualport_support);
	}
}


#endif

UINT32 ReadFlash(UINT32 flash_addr, UINT32 buffer, UINT32 total_size, FlashBootType_T fbt)
{
	int ret = NULL;
	ret=spi_nor_do_read(flash_addr,buffer,total_size);
	if(ret != NULL)
	{
		uart_printf("boot_readflash_fail %d %d\r\n",flash_addr,total_size);
	}
	return ret;
}

UINT32 WriteFlash(UINT32 flash_addr, UINT32 buffer, UINT32 total_size, FlashBootType_T fbt)
{
	int ret = NULL;
	ret=spi_nor_do_write(flash_addr,buffer,total_size);
	if(ret != NULL)
	{
		uart_printf("boot_writeflash_fail %d %d\r\n",flash_addr,total_size);
	}
	return ret;
}

UINT32 EraseFlash(UINT32 flash_addr, UINT32 size, FlashBootType_T fbt)
{
	int ret = NULL;
	ret=spi_nor_do_erase(flash_addr,size);
	if(ret != NULL)
	{
		uart_printf("boot_eraseflash_fail %d %d\r\n",flash_addr,size);
	}
	return ret;
}

#define Quec_UpdaterExecAddress 0x7E300000//bind on updater build sct loader config  1606 0x7E000000~0x7E400000

#ifdef QUEC_NORFLASH_ERASE_OPTIMIZE
#define CHIP_BLOCK_SIZE 		  0x10000
#define CRANE_QSPI_BASE_ADDRESS             0x80000000

void Quec_FlashErase_Optimize(void)
{
	int i=0,EraseRecordAreaflag=0;	
	UINT32 tmp_buff;
	quec_flashErase_record_s *P_BlkEraseRecordcell = NULL;
	quec_RecordInfo_s *P_BlkERCellInfo = NULL;
	quec_Eraseflag_s *P_BlkERCellflag = NULL;
	UINT32 Retval = NoError;
	UINT32 BlockSize = CHIP_SECTOR_SIZE; 
	quec_Eraseflag_s BlkEraseflag;
	quec_RecordInfo_s BlkERecordCellInfo;	
	UINT32 QUEC_RECORD_BLOCKERASE_AREA_SIZE=NULL;
	UINT32 QUEC_RECORD_BLOCKERASE_AREA_ADD=NULL;
	_ptentry *ptn=ptable_find_entry("erase_rd");
	if(ptn==NULL)
	{
		uart_printf("not get erase_rd partition \r\n");
		return ;
	}
	QUEC_RECORD_BLOCKERASE_AREA_SIZE=ptn->size;
	QUEC_RECORD_BLOCKERASE_AREA_ADD=ptn->start;
//	uart_printf("start=0x%08x size=0x%08x\r\n",QUEC_RECORD_BLOCKERASE_AREA_ADD,QUEC_RECORD_BLOCKERASE_AREA_SIZE);
//	tmp_buff = DECOMPRESS_TEMP_ADDR;// 0x071B0000, size 0x10000 (64K),tmp buff used here
	BlkEraseflag.flag = 0xAAAA5555;
	BlkEraseflag.reserve = 0xffffffff;
	tmp_buff = Quec_UpdaterExecAddress ;
	Retval = ReadFlash(QUEC_RECORD_BLOCKERASE_AREA_ADD, tmp_buff,QUEC_RECORD_BLOCKERASE_AREA_SIZE, BOOT_FLASH);
//	isChip_3601S();//get the chip is 3601 or not
	if( NoError == Retval)
	{
		P_BlkEraseRecordcell = (quec_flashErase_record_s*)tmp_buff;
		P_BlkERCellInfo = (quec_RecordInfo_s*)tmp_buff;
		if((QUEC_RECORD_MAGIC2 == P_BlkERCellInfo->RecordMagic) && (0x00 == P_BlkERCellInfo->BlockId))// first record cell is a flag which mark the record area erase
		{
		    for(i=1; i*sizeof(quec_flashErase_record_s)<QUEC_RECORD_BLOCKERASE_AREA_SIZE; i++)
		    {
			P_BlkEraseRecordcell = (quec_flashErase_record_s*)tmp_buff+i;
			P_BlkERCellInfo = (quec_RecordInfo_s *)P_BlkEraseRecordcell;
			P_BlkERCellflag = (quec_Eraseflag_s *)((char *)P_BlkEraseRecordcell + sizeof(quec_RecordInfo_s));
			if(0xffffffff != P_BlkERCellInfo->BlockId && 0xAAAA5555 != P_BlkERCellflag->flag)
			{
				uart_printf("[Quec][Flash]:Blk=0x%x maybe need erase! i=%d type=%d \r\n",P_BlkERCellInfo->BlockId,i,P_BlkERCellInfo->Record_type);
				if( 0xffffffff == P_BlkERCellflag->flag && QUEC_RECORD_MAGIC1 == P_BlkERCellInfo->RecordMagic)
				{
					//Record cell is eflag not marked(0xaaaa55) nand magic number is right. erase this block now!!
					BlockSize=P_BlkERCellInfo->Record_type?CHIP_SECTOR_SIZE:CHIP_BLOCK_SIZE;
	
					if((P_BlkERCellInfo->BlockId*BlockSize >= (get_nvm_start_address() - CRANE_QSPI_BASE_ADDRESS)) && (P_BlkERCellInfo->BlockId*BlockSize < (get_nvm_end_address() - CRANE_QSPI_BASE_ADDRESS)))
					{
						if( NoError == EraseFlash(P_BlkERCellInfo->BlockId*BlockSize, BlockSize, BOOT_FLASH))
						{
							Retval = WriteFlash(QUEC_RECORD_BLOCKERASE_AREA_ADD+i*sizeof(quec_flashErase_record_s)+sizeof(quec_RecordInfo_s), \
							           &BlkEraseflag,sizeof(BlkEraseflag), BOOT_FLASH);
							uart_printf("erase addr=%x size=%x block=0x%x erased again!!!! i=%d type=%d\r\n",P_BlkERCellInfo->BlockId*BlockSize,BlockSize,P_BlkERCellInfo->BlockId,i,P_BlkERCellInfo->Record_type);
						}
					} else {
						Retval = WriteFlash(QUEC_RECORD_BLOCKERASE_AREA_ADD+i*sizeof(quec_flashErase_record_s)+sizeof(quec_RecordInfo_s), \
						           &BlkEraseflag,sizeof(BlkEraseflag), BOOT_FLASH);
						uart_printf("addr is error not erase!!addr=%x size=%x block=0x%x i=%d type=%d\r\n",P_BlkERCellInfo->BlockId*BlockSize,BlockSize,P_BlkERCellInfo->BlockId,i,P_BlkERCellInfo->Record_type);
					}
				}
				else
				{
					uart_printf("[Quec][Flash]:RecordCell(i=%d) is dirty data,Blk=%d not need erase!! flag=0x%x\r\n",\
							i,P_BlkERCellInfo->BlockId,P_BlkERCellflag->flag);	
				}
			}

			if(0xffffffff == P_BlkERCellInfo->BlockId && 0xffffffff == P_BlkERCellflag->flag)
			{
				uart_printf("[Quec][Flash]:Abnormal Erasedblock not found(i=%d)\r\n",i);
				break;			
			}

		    }
		    uart_printf("[Quec][Flash]:Abnormal Erasedblock not found(i=%d)\r\n",i);	
		}
		else
		{
			EraseRecordAreaflag=1;
		}
		
		if(1==EraseRecordAreaflag)
        {
			if(NoError == EraseFlash(QUEC_RECORD_BLOCKERASE_AREA_ADD, QUEC_RECORD_BLOCKERASE_AREA_SIZE, BOOT_FLASH))
			{
				BlkERecordCellInfo.RecordMagic = QUEC_RECORD_MAGIC2;
				BlkERecordCellInfo.BlockId  = 0x00;
				Retval = WriteFlash(QUEC_RECORD_BLOCKERASE_AREA_ADD, &BlkERecordCellInfo, sizeof(BlkERecordCellInfo), BOOT_FLASH);
				if(NoError !=Retval)
				{
					uart_printf("[Quec][Flash]:write cell0  EraseRecord area erase flag faild !!!");
					return ;
				}
			}
			else
			{
				uart_printf("[Quec][Flash]:Erase record area fail !!!!!!");
				return ;
			}
		        uart_printf("[Quec][Flash]:cell0 write flag(MAGIC2=0x%x)(BlockId=%d)\r\n",BlkERecordCellInfo.RecordMagic,BlkERecordCellInfo.BlockId);	
			return;
		}
	}
	else
	{
		uart_printf("[Quec][Flash]:flash read EraseRecord Area failed ret=%d\r\n",Retval);
		return;
	}
	return;
}
#endif



#ifdef QUECTEL_FOTA_UPDATER_PARTITION

#define  UPDATER_PKG_IMAGE_SIZE   0x10000*2   //64K
#define  QUEC_UPDATER_PKG_START_FLAG   "QUEC_UPDATER_STR"  // 16 BYTE  start flag,  not modify
#define  QUEC_UPDATER_PKG_END_FLAG     "QUEC_UPDATER_END" // 16 BYTE   not modify

typedef struct
{
    char flagStr[16] ;
    unsigned int updater_file_size;
    unsigned int checksum;
    unsigned int version;
    unsigned int  reserved;
}quec_updater_head_s;


static unsigned int ASR_fbf_checksum(unsigned char * src, unsigned int len, unsigned int checksum)
{
	unsigned int * start = (unsigned int *)src;
	unsigned int * end = (unsigned int *)(src + len);
	while (start < end) {
		checksum ^= (*start++);
	}
	return checksum;
}

// 这个函数 不能随便返回0， 不然可能会影响正常fota升级。只有在updater分区被擦除了，写flash出错了才能返回0，其他都要返回1
int Quectel_ota_updaterImage_function(void)
{  
	UINT32 Retval = NoError;
	UINT32  *DATA_buf= NULL;
	quec_updater_head_s *p_QupdaterPKG_Head;
	unsigned int  updater_pkg_size=0, Q_updaterImgChecksum=0;
	UINT32 QUEC_UPDATER_SOURCE_AREA_SIZE=NULL;
	UINT32 QUEC_UPDATER_SOURCE_AREA_ADD=NULL;
	_ptentry *updater_ptn=ptable_find_entry("updater");
	_ptentry *Rd_ptn=ptable_find_entry("fota_pkg");
	
	if(NULL == Rd_ptn)
	{
		uart_printf("[Quec][boot33][Flash][%s]:not get erase_rd partition \r\n",__func__);
		return  1;
	}
	if(NULL == updater_ptn)
	{
		uart_printf("[Quec][boot33][Flash][%s]:not get updater partition \r\n",__func__);
		return  1;
	}

	DATA_buf = Quec_UpdaterExecAddress;  //malloc(UPDATER_IMAGE_SIZE);  临时借用updater执行的这段内存，毕竟这是还没有运行updater
	if(NULL == DATA_buf)
	{
		uart_printf("[Quec][boot33][Flash][%s]: malloc (size=0x%08X)\r\n",__func__, UPDATER_PKG_IMAGE_SIZE);
		return 1;
	}

	if((Rd_ptn->size) < UPDATER_PKG_IMAGE_SIZE)
	{
		uart_printf("[Quec][boot33][Flash][%s]: fota_pkg partition size too small !!!! (ptn->sizesize=0x%08X)\r\n",__func__,Rd_ptn->size);
		return 1;
	}
	Retval = ReadFlash(Rd_ptn->start, DATA_buf,UPDATER_PKG_IMAGE_SIZE, BOOT_FLASH);
	if( NoError != Retval)
	{
		uart_printf("[Quec][boot33][Flash][%s]: read fota_pkg partiton data failed Retval=%d!!!\r\n",__func__,Retval);
		return 1;
	}
	if(0 !=  quec_mem_cmp((void *)DATA_buf, QUEC_UPDATER_PKG_START_FLAG, strlen(QUEC_UPDATER_PKG_START_FLAG)))
	{
		uart_printf("[Quec][boot33][Flash][%s]: fota_pkg partiton can't found updater OTA flag !!\r\n",__func__);
		return 1;
	}

	#if 1 // check crc
		p_QupdaterPKG_Head = (quec_updater_head_s *)DATA_buf;
		Q_updaterImgChecksum = ASR_fbf_checksum((char *)DATA_buf+sizeof(quec_updater_head_s), p_QupdaterPKG_Head->updater_file_size,0);
		uart_printf("[Quec][boot33][Flash]:updater img checksum flag checksum=[0x%08x], cal checksum[0x%08x]\r\n", p_QupdaterPKG_Head->checksum,Q_updaterImgChecksum);
		if(Q_updaterImgChecksum != p_QupdaterPKG_Head->checksum)
		{
			uart_printf("[Quec][boot33][Flash]:updater img checksum failed, flag checksum=[0x%08x], cal checksum[0x%08x]\r\n", p_QupdaterPKG_Head->checksum,Q_updaterImgChecksum);
			return 1;
		}
	#endif 

	if( 1 == p_QupdaterPKG_Head->version)//we can.t  control this action ,when make updater  PKG
	{
		CpCoreFreqChangeTo416(); // upgrade  updater partiton set CPU Freq  to  416
	}

	Retval = EraseFlash(updater_ptn->start, updater_ptn->size,BOOT_FLASH);
	if(NoError != Retval)
	{
		uart_printf("[Quec][boot33][Flash][%s]: erase updater partition failed!!!!!\r\n",__func__);
		return 1;
	}
	else // updater 分区擦除成功，后面必须要保证updater 数据更新完成，不然不能跳转到updater里去运行。
	{
		Retval = WriteFlash(updater_ptn->start, (char *)DATA_buf+sizeof(quec_updater_head_s), UPDATER_PKG_IMAGE_SIZE-sizeof(quec_updater_head_s)/*head*/-sizeof(quec_updater_head_s)/*tail*/, BOOT_FLASH);
		if(NoError != Retval)
		{
			uart_printf("[Quec][boot33][Flash][%s]:updater_partiton upgrade write flash failed Retval= %d !!!\r\n",__func__,Retval);
			return 0;   // must  return 0,  updater_partition  upgrade fail,  must reboot  
		}
		else
		{
			uart_printf("[Quec][boot33][Flash][%s]:updater_partiton upgrade sucess !!\r\n",__func__);
			Retval = EraseFlash(Rd_ptn->start, UPDATER_PKG_IMAGE_SIZE,BOOT_FLASH);
			if(NoError != Retval)
			{
				uart_printf("[Quec][boot33][Flash][%s]:EraseFlash upgrade flag fail !!\r\n",__func__);
			}
			return 1;
		}
	}
	return 1;
	
}
#endif

