#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cpu.h"
#include "qspi.h"
#include "reg.h"
#include "system.h"
//#include "uart.h"
#include "ptable.h"
#include "loadtable.h"
#include "lzop.h"
#include "sdio.h"
#include "pmic.h"
#include "ff.h"
#include "version_block.h"
#include "bspatch.h"
#include "fip.h"
#include "LzmaDec.h"
#include "FreqChange.h"
#include "fbf_parse.h"
#include "ota.h"
#include "tinyalloc.h"
#include "asr_property.h"
#include "secboot.h"
#include "updater_table.h"

#ifdef BOOT33_FOTA_SUPPORT

extern void   TransferControl(unsigned int);
extern int crane_qspi_read(unsigned int addr, unsigned int buf_addr, unsigned int size);
extern int crane_qspi_write(unsigned int addr, unsigned int buf_addr,unsigned int size);
extern int crane_qspi_erase(unsigned int addr, unsigned int size);
extern int malloc_init(unsigned int ta_base, unsigned int length);
extern unsigned int get_fota_param_end_addr(void);
extern unsigned int get_fota_param_start_addr(void);
extern unsigned int get_ddr_ro_exec_length(void);
extern unsigned int get_ddr_ro_exec_addr(void);


extern unsigned long mini_system_enable;

unsigned int get_ps_ncah_address(void)
{
	char region_compress_mark[8];
	unsigned schedule_count = 0;
	rw_region_item region_info;
	char * rw_cpz_struct_addr=(char*)get_rw_cpz_struct_addr();

	//load region compressed struct
	memcpy(region_compress_mark,
			rw_cpz_struct_addr,
			sizeof(region_compress_mark));

	if(!strncmp(region_compress_mark, RW_REGION_MARK_PRE_STRING ,strlen(RW_REGION_MARK_PRE_STRING)-1)){
		while(1){
			//read NEXT region cpz info struct
			memcpy(&region_info
					,(void*)(rw_cpz_struct_addr + (sizeof(rw_region_item)*schedule_count++))
					,sizeof(rw_region_item));


			//dump region info
			//uart_printf("[CP ] decompress [%8s] from [%.08x] to [%.08x]\r\n",
			//		region_info.RW_REGION_NAME,
			//		region_info.RW_REGION_COMPRESSED_ADDR,
			//		region_info.RW_REGION_EXEC_ADDR
			//		);
			
			if(!strncmp(region_info.RW_REGION_NAME,"PS_NCAH",7)){
				return region_info.RW_REGION_EXEC_ADDR;
			}

		}
	}
	else
	{
		uart_printf("[CP ] Region CPZ struct not detected from loadtable\r\n");
	}
	return 0;

}

static void fota_uudelay(int us)
{
	volatile uint32_t i;
	for(i=0; i<us*100;i++)
		i = i+1;
}

static void fota_mdelay(int ms){
	volatile uint32_t i;
	for(i=0; i<ms;i++)
		fota_uudelay(100);
}

static UINT32 CalcImageChecksum( UINT32* DownloadArea, UINT32 ImageLength,UINT32 checksum)
{
    UINT32 ImageChecksum = checksum;
    UINT32* ptr32 = DownloadArea;
    UINT32* pEnd = ptr32 + (ImageLength / sizeof(UINT32));
    UINT32 BytesSummed = 0;

    while ( ptr32 < pEnd )
    {
        // checksum format version 2 algorithm as defined by flasher
        ImageChecksum ^= (*ptr32);
        ptr32++;
        BytesSummed += sizeof(UINT32);
    }
    return ImageChecksum;
}
#if (!defined(BOOT33_FOTA_NO_UPDATER) || !defined(LTEONLY_SINGLE_SIM))

UINT32 OTA_Check_FotaImage(UINT32 buf, UINT32 size, UINT32 flash_Addr)
{
   UINT32 old_checksum = 0,new_checksum = 0;
   char *temp=NULL;
   

   temp =(char *) tiny_malloc(size);
   memset(temp,0,size);
   memcpy(temp,flash_Addr+QSPI_FLASH_BASE,size);
   old_checksum = CalcImageChecksum((UINT32*)buf,size,0);
   new_checksum = CalcImageChecksum((UINT32*)temp,size,0);
   
   if(old_checksum != new_checksum){
       uart_printf("OTA_Check_FotaImage,failed!!![0x%08X]:[0x%08X]\n\r",old_checksum,new_checksum);  
   }else{
       tiny_free(temp);
       return NoError;
   }
   tiny_free(temp);

   return DFota_WriteFlashCheckFailed;
    
}



static UINT32 OTA_Update_FotaParam(UINT32 buf, UINT32 size, UINT32 flash_Addr)
{
	UINT32 Retval = 0;
	int i=0;
	//char temp[FLASH_4K_SIZE];
	uart_printf("OTA_Update_FotaParam, flash_Addr[0x%08X],size[0x%08X]\n\r", flash_Addr,size);	
	
	//temp =(char *) malloc(FLASH_4K_SIZE);
	//memcpy(temp,(char *)buf,size);
start:	
	
	Retval=crane_qspi_erase(flash_Addr, FLASH_4K_SIZE);
	if (Retval != 0)
		goto exit;
	
	
	Retval = crane_qspi_write(flash_Addr, buf, FLASH_4K_SIZE);
	if (Retval != 0)
		goto exit;
exit:

	Retval=OTA_Check_FotaImage(buf,size,flash_Addr);
	if(NoError!=Retval ){
		if(i>10){
			uart_printf("OTA_Check_FotaImage filed,Wait...\n\r");
			while(1){
				fota_mdelay(10*1000);
			}
		}
		uart_printf("OTA_Check_FotaImage filed,Wait (%d)sec ...\n\r",(i+1)*10);
		fota_mdelay((i+1)*10*1000);
		uart_printf("OTA_Check_FotaImage filed,Wait (%d)sec end\n\r",(i+1)*10);
		i++;
		goto start;
	}

	
	uart_printf("OTA_Update_FotaParam end\n\r");	
	return Retval;
	
}

static UINT32 OTA_Update_FotaImage(UINT32 buf, UINT32 size, UINT32 flash_Addr)
{
	UINT32 Retval = 1;
	char *temp=NULL;
	UINT32 index=0;
	UINT32 tempsize = size;
	int i=0;
	uart_printf("OTA_Update_FotaImage: flash_Addr[0x%08x], size: 0x%08x\n\r", flash_Addr, size);
start:
	
	temp =(char *) tiny_malloc(FLASH_4K_SIZE);

	while(size > FLASH_4K_SIZE){
		memcpy(temp,(char *)(buf+index),FLASH_4K_SIZE);
		
		Retval=crane_qspi_erase(flash_Addr  + index, FLASH_4K_SIZE);
		if (Retval != 0)
			goto error;

		if(index==0){
#if 0
			uart_printf("+++++++++++++++++++++++++++++OTA_Update_FotaImage,delay for poweroff test++++++++++++++\n\r"); 
			fota_delay();
			uart_printf("-----------------------------OTA_Update_FotaImage,delay end----------------------------\n\r"); 
#endif

		}
		if(index%FLASH_1M_SIZE==0){
			uart_printf("\r\n");
		}

		if(index%CRANE_NOR_BLOCKSIZE==0){
			uart_printf("...");
		}
		
		Retval = crane_qspi_write(flash_Addr  + index, (UINT32)temp, FLASH_4K_SIZE);
		if (Retval != 0)
			goto error;
		
		index += FLASH_4K_SIZE;
		size -= FLASH_4K_SIZE;
		
	}


	if(size>0){
		memset(temp,0,FLASH_4K_SIZE);
		memcpy(temp,(char *)(buf+index),size);
		
		Retval=crane_qspi_erase(flash_Addr + index, FLASH_4K_SIZE);
		if (Retval != 0)
			goto error;

		Retval = crane_qspi_write(flash_Addr + index, (UINT32)temp, FLASH_4K_SIZE);
		if (Retval != 0)
			goto error;
		
		index += size;
		size -= size;
	}

	Retval = 0;
error:
	
	if(temp) tiny_free(temp);
	
	Retval=OTA_Check_FotaImage(buf,tempsize,flash_Addr);
	if(NoError!=Retval ){
		if(i>10){
			uart_printf("OTA_Check_FotaImage filed,Wait...\n\r");
			while(1){
				fota_mdelay(10*1000);
			}
		}
		uart_printf("OTA_Check_FotaImage filed,Wait (%d)sec ...\n\r",(i+1)*10);
		fota_mdelay((i+1)*10*1000);
		uart_printf("OTA_Check_FotaImage filed,Wait (%d)sec end\n\r",(i+1)*10);
		i++;
		goto start;
	}

	
	uart_printf("OTA_Update_FotaImage end\n\r");
	return Retval;
	
}




static UINT32 System_ota_updater(struct fota_firmwar_flag* pFOTA_T,struct fota_param *param,unsigned long FotaParamStartAddress)
{
	UINT32 Retval = GeneralError;
	UINT32 LoadAddr = 0;
	MasterBlockHeader *pMasterHeader = NULL;
	PDeviceHeader_11 pDevHeader_11=NULL;
	PImageStruct_11 pImage_11 = NULL;
	UINT32 temp_p = NULL;
	UINT32 imageChecksum = 0;
	UINT32 imagenum;
	UINT32 ImageAddr;
	UINT32 updaterSize=0,updateImageSize=0;

    if (pFOTA_T->header != FOTA_HEADER_MAGIC)
    {
        uart_printf("[OTA] FBF Flag mismatch,Header[%.08x]\r\n",pFOTA_T->header);
        return NotFoundError;
    }

    if (pFOTA_T->upgrade_flag != 1)
    {
        uart_printf("[OTA] No need to upgrade[%d]\r\n",pFOTA_T->upgrade_flag);
        return NotFoundError;
    }

	
	if(pFOTA_T->upgrade_method != 1)
	{
        uart_printf("[OTA] Not ota upgrader\r\n");
        return NotOtaUpdaterError;
    }

	
	LoadAddr = (UINT32)tiny_malloc(pFOTA_T->fbf_file_size);
	if(LoadAddr == 0){
		uart_printf("[OTA] tiny_malloc error\n\r");
		return InvalidSizeError;
	}
	//uart_printf("LoadAddr: 0x%08x\n\r", LoadAddr);
	memset((void *)LoadAddr,0,pFOTA_T->fbf_file_size);

	//fota_dump_buffer("MasterBlockHeader",(unsigned char *)pFOTA_T->fbf_flash_address+QSPI_FLASH_BASE,0,sizeof(MasterBlockHeader));
	
	memcpy((void *)LoadAddr,(void*)(pFOTA_T->fbf_flash_address+QSPI_FLASH_BASE),pFOTA_T->fbf_file_size);
 
	pMasterHeader = (MasterBlockHeader *)LoadAddr;

	if (pMasterHeader->Format_Version != 11){
		Retval = FBF_VersionNotMatch;
		goto error;
	}

	if (pMasterHeader->nOfDevices != 1){
		Retval = FBF_DeviceMoreThanOne;
		goto error;
	}

	temp_p = pMasterHeader->deviceHeaderOffset[0] + LoadAddr;
	pDevHeader_11 = (PDeviceHeader_11)temp_p;
	
	
	for ( imagenum = pDevHeader_11->nOfImages; imagenum > 0; imagenum -- )
	{
		temp_p = (UINT32)&pDevHeader_11->imageStruct_11[imagenum - 1];
		pImage_11 = (PImageStruct_11)temp_p;

		updaterSize = get_updater_copy_size();
		updateImageSize = pImage_11->length;
		uart_printf("[OTA] Flash_Start_Address: 0x%08x length: 0x%08x\n\r", pImage_11->Flash_Start_Address,updateImageSize);
		uart_printf("[OTA] get_updater_start_addr: 0x%08x get_updater_copy_size: 0x%08x\n\r", get_updater_start_addr(),updaterSize);

		if(updateImageSize & (FLASH_4K_SIZE-1)){
			updateImageSize += (FLASH_4K_SIZE - updateImageSize & (FLASH_4K_SIZE-1));
		}
		if(get_updater_start_addr()!=(pImage_11->Flash_Start_Address+QSPI_FLASH_BASE) || updaterSize < updateImageSize)
		{
			Retval = NotOtaUpdaterError;
			goto error;
		
		}
		uart_printf("[OTA] boot ota updater, nOfImages: %d\n\r",pDevHeader_11->nOfImages);

 
		ImageAddr = LoadAddr+((pImage_11->First_Sector+7)<<ALIGN_1K_SIZE);
		
		// add checksum for images in FBF file
		imageChecksum = CalcImageChecksum((UINT32*)ImageAddr, pImage_11->length,0);
		if (imageChecksum != pImage_11->ChecksumFormatVersion2){
			Retval = CRCFailedError;
			uart_printf("[OTA]fbf file CORRUPT,checksum failed\n\r");
			goto error;
		}
		
		if(pImage_11->ChecksumFormatVersion2==0){
			continue;
		}

		
		uart_printf("[OTA] Flash_Start_Address: 0x%08X, EraseLen: 0x%08X, length=0x%08X\n\r", 
			pImage_11->Flash_Start_Address,pImage_11->Flash_erase_size,pImage_11->length);
		Retval=OTA_Update_FotaImage( ImageAddr, pImage_11->length, pImage_11->Flash_Start_Address);
		if (Retval != NoError )
			goto error;

		
	}

	tiny_free((void*)LoadAddr);
	LoadAddr=0;
	
	memset(param->fotaFlag,0,ASR_FOTA_FLAG_LEN_MAX);
	param->mini_sys_enable = 0;
	OTA_Update_FotaParam((UINT32)param, sizeof(struct fota_param),get_fota_param_start_addr()-QSPI_FLASH_BASE);
	
	
	uart_printf("[OTA] Clear upgrade flag OK\r\n"); 	
	pFOTA_T->header = 0;
	pFOTA_T->upgrade_flag = 0;
	pFOTA_T->upgrade_method = 0;
	pFOTA_T->checksum = 0;
	Retval = OTA_Update_FotaParam((UINT32)pFOTA_T, sizeof(struct fota_firmwar_flag),FotaParamStartAddress);
	if (Retval != NoError)
		return Retval;
	
	Retval = OTA_Update_FotaParam((UINT32)pFOTA_T, sizeof(struct fota_firmwar_flag),FotaParamStartAddress + FLASH_4K_SIZE);
	if (Retval != NoError)
		return Retval;
	uart_printf("[OTA] Clear fota param OK\r\n");
	


	return NoError;


error:
	//free buffers
	uart_printf("[OTA]ota updater,Retval=%x\n\r", Retval);
	if(LoadAddr) tiny_free((void*)LoadAddr);

	return Retval;

}
#endif

#define UpdaterExecAddress 0x7E040000//bind on updater build sct loader config
#define UpdaterVersionIndex 0x00800//bind on updater build sct loader config

UpdaterHeaderInfo updater_version_vb={0};
extern _ptentry *updater_Entry;

void get_updater_vb(void)
{
#ifdef BOOT33_SECBOOT_SUPPORT
#ifdef BOOT33_SECBOOT_V2
    if(secboot_is_fuse_enabled()==1){
#endif
        fip_image_t fip_item;
        
        //[sec.0]secboot init from updater partition
        //    which is updater.bin with a secboot ToC struct with only one FIP header
        //    for updater.bin
        //
        //      |----------------|
        //      | FIP Header     |
        //      |----------------|
        //      | Updater.bin    |
        //      |----------------|
        
        secboot_init("updater");
        
        //[sec.1]do updater verify
        //Timer0_enable(TRUE);
        //secboot_item_check(ITEM_UPDATER);
        //Timer0_enable(FALSE);
        
        //[sec.2]get info from fip of updater.bin
        secboot_item_get_img_addr_size(ITEM_UPDATER,(fip_image_handle)&fip_item);
        
        //[sec.3]for debug to dump header of real updater.bin
        //display_binary((void *)(fip_item.start+fip_item.offset),256);
        
        //[sec.4]load updater_a or updater_b to psram
        memcpy(&updater_version_vb,
            (void *)(fip_item.start+fip_item.offset),
            sizeof(UpdaterHeaderInfo));
        //memcpy( (void *)UpdaterExecAddress,
        //  (void *)(fip_item.start+fip_item.offset),
        //  fip_item.size
        //  );


#ifdef BOOT33_SECBOOT_V2
		secboot_deinit();
    }
    else{
        memcpy(&updater_version_vb,get_updater_start_addr(),sizeof(UpdaterHeaderInfo));
    }
#endif



#else
    memcpy(&updater_version_vb,get_updater_start_addr(),sizeof(UpdaterHeaderInfo));
#endif
	asr_property_set("updater.version",updater_version_vb.version_union.version_info_block.string);
    asr_property_set("updater.solution",updater_version_vb.fota_solution_union.fota_solution_block.string);
    CP_LOGD("[OTA] get updater version %s !\r\n",updater_version_vb.version_union.version_info_block.string);
    CP_LOGD("[OTA] get updater solution %s !\r\n",updater_version_vb.fota_solution_union.fota_solution_block.string);

}

UINT32 UncompressUpdater(struct fota_firmwar_flag *fotaPara,unsigned char * address)
{
	UINT32 res = NoError;
	int outLen = -1;
	unsigned int inLen = fotaPara->ota_header.mini_ota_head.nonDiffInfo.updater_size;
	unsigned int offset = fotaPara->ota_header.mini_ota_head.nonDiffInfo.updater_offset;
	
	unsigned char * inAddr = NULL,*dfota_buf=NULL;
	

	if(inLen==0){
		return NotFoundError;
	}
	CP_LOGD("[OTA] updater_addr [0x%.08x]\r\n", fotaPara->ota_header.mini_ota_head.nonDiffInfo.updater_addr);
	if(fotaPara->ota_header.mini_ota_head.nonDiffInfo.updater_addr){
		inAddr = fotaPara->ota_header.mini_ota_head.nonDiffInfo.updater_addr;
		inAddr += QSPI_FLASH_BASE;
	}else{
		CP_LOGD("[OTA] first_flash_addr[0x%.08x], first_file_size[0x%.08x]\r\n", fotaPara->ota_header.mini_ota_head.first_flash_addr,fotaPara->ota_header.mini_ota_head.first_file_size);
		CP_LOGD("[OTA] second_flash_address[0x%.08x], second_file_size[0x%.08x]\r\n", fotaPara->ota_header.mini_ota_head.second_flash_address,fotaPara->ota_header.mini_ota_head.second_file_size);
		dfota_buf = (unsigned char *)tiny_malloc(fotaPara->ota_header.mini_ota_head.first_file_size + fotaPara->ota_header.mini_ota_head.second_file_size);

		crane_qspi_read(fotaPara->ota_header.mini_ota_head.first_flash_addr - QSPI_FLASH_BASE, dfota_buf, fotaPara->ota_header.mini_ota_head.first_file_size);

		if(fotaPara->ota_header.mini_ota_head.second_flash_address && fotaPara->ota_header.mini_ota_head.second_file_size){
			crane_qspi_read(fotaPara->ota_header.mini_ota_head.second_flash_address - QSPI_FLASH_BASE, dfota_buf + fotaPara->ota_header.mini_ota_head.first_file_size, fotaPara->ota_header.mini_ota_head.second_file_size);
		}
		inAddr = dfota_buf + offset; 
	}
	
	
	if(!LzmaUncompress((unsigned char *)address,(size_t *)&outLen, (const unsigned char *)inAddr, (size_t *)&inLen))
	{
		CP_LOGD("[OTA] released updater size [0x%.08x] inLen[0x%.08x]\r\n", outLen,inLen);
		memcpy(&updater_version_vb,address,sizeof(UpdaterHeaderInfo));
		if(updater_version_vb.loadtable_union.loadtable_block.magic != UPDATER_VALID_MAGIC){
			res = UpdaterMagicError;
		}else{
			res=check_updater_ram(address,outLen);
			if(res){
				res = CheckUpdaterError;
			}

		}

	}else{
		res = UnpressedUpdaterError;
    }
	return res;
}


void ota_entry(void) {
	volatile unsigned long FotaParamStartAddress;
	volatile unsigned long FotaParamEndAddress;
	struct fota_param param;
	unsigned long entry_mini_system_only=0;
	struct fota_firmwar_flag *fotaPara_1=NULL;
	struct fota_firmwar_flag *fotaPara_2=NULL;
	struct fota_firmwar_flag *fotaPara=NULL;
	UINT32 Retval = NoError;
	UpdaterHeaderInfo updater_version;

	//detect whether fota partition supported
	FotaParamStartAddress = get_fota_param_start_addr();
	FotaParamEndAddress   = get_fota_param_end_addr();
	if(FotaParamStartAddress == FotaParamEndAddress){
		CP_LOGE("[OTA] FotaParamStartAddress == FotaParamEndAddress , FOTA not supported\r\n");
		return;
	}
#if (!defined(BOOT33_FOTA_NO_UPDATER) || !defined(LTEONLY_SINGLE_SIM))
	if(updater_Entry){
		get_updater_vb();
		asr_property_dump();
	}
#endif

	//check OTA flag or
	memcpy(&param,(void *)FotaParamStartAddress,sizeof(struct fota_param));

	//if(!strncmp(fota_flag,"ASROTA",6) || Keypad_OTA_Flag_Check_B()){
	if(!strncmp((char *)param.fotaFlag,"ASROTA",6) ){
#if 1
		if( 0 == Quectel_ota_updaterImage_function())// �������?������㷵��?�� ��Ȼ���ܻ�Ӱ������fota������ֻ����updater�����������ˣ�дflash�����˲��ܷ���0��������Ҫ����1
		{
			uart_printf("[OTA] updater  upgrade  failed!!!\r\n ");
			PMIC_SW_RESET();			
		}
#endif
		UINT32 stack=0x7e200000;
		//The bspatch/lzma lib needs malloc/free APIs
		UINT32 poolLen = 0x00600000;
		malloc_init(stack, poolLen);

#if (!defined(BOOT33_FOTA_NO_UPDATER) || !defined(LTEONLY_SINGLE_SIM))
		if(updater_Entry){
			memcpy(&updater_version,get_updater_start_addr(),sizeof(UpdaterHeaderInfo));
			
			CP_LOGD("[OTA] get updater version %s !\r\n",updater_version.version_union.version_info_block.string); 
		}
#endif

		
		fotaPara_1=(struct fota_firmwar_flag*)tiny_malloc(sizeof(struct fota_firmwar_flag));
		fotaPara_2=(struct fota_firmwar_flag*)tiny_malloc(sizeof(struct fota_firmwar_flag));
		
		memcpy(fotaPara_1,(void *)(FotaParamStartAddress+FLASH_4K_SIZE),sizeof(struct fota_firmwar_flag));
		memcpy(fotaPara_2,(void *)(FotaParamStartAddress+2*FLASH_4K_SIZE),sizeof(struct fota_firmwar_flag));
		
		if(fotaPara_1->checksum!=CalcImageChecksum((UINT32*)fotaPara_1,sizeof(struct fota_firmwar_flag)-sizeof(unsigned int),0)
			|| fotaPara_1->header != FOTA_HEADER_MAGIC){
			if(fotaPara_2->checksum!=CalcImageChecksum((UINT32*)fotaPara_2,sizeof(struct fota_firmwar_flag)-sizeof(unsigned int),0)
				|| fotaPara_2->header != FOTA_HEADER_MAGIC){
				CP_LOGD("[OTA] fotaPara error!!!\r\n");
				goto done;
			}else{
				CP_LOGD("[OTA]using fotaPara_2,not copy temp flash\r\n");
				fotaPara = fotaPara_2;
			}
		
		}else{
			if(fotaPara_2->checksum!=CalcImageChecksum((UINT32*)fotaPara_2,sizeof(struct fota_firmwar_flag)-sizeof(unsigned int),0)
				|| fotaPara_2->header != FOTA_HEADER_MAGIC){
				fotaPara = fotaPara_1;
				CP_LOGD("[OTA]using fotaPara_1,need copy temp flash\r\n");
		
			}else{
				if(fotaPara_1->index > fotaPara_2->index){
					fotaPara = fotaPara_1;
					CP_LOGD("[OTA]using fotaPara_1,need copy temp flash\r\n");
				}else{
					fotaPara = fotaPara_2;
					CP_LOGD("[OTA]using fotaPara_2,not copy temp flash,checksum[%08x]\r\n",fotaPara_2->checksum);
				}
		
			}
		}

		
		if(param.mini_sys_enable==1){
			mini_system_enable=1;

			if(fotaPara->ota_header.mini_ota_head.mini_dfota_status==MINI_SYS_DFOTA_START){
				CP_LOGD("[OTA]MINI_SYS_DFOTA_START\r\n");
				entry_mini_system_only = 1;
			}else if(fotaPara->ota_header.mini_ota_head.mini_dfota_status>=MINI_SYS_DFOTA_DONE){
				entry_mini_system_only = 1;
				CP_LOGD("[OTA]MINI_SYS_DFOTA_DONE\r\n");
			}


			if(entry_mini_system_only==1){
				asr_property_set("mini.sys.enable","1");
				tiny_free(fotaPara_1);
				tiny_free(fotaPara_2);	
				uart_printf("[OTA]ENTRY MINI SYSTEM ONLY\r\n");
				return;
			}
			#if defined(BOOT33_FOTA_NO_UPDATER)
			if(!updater_Entry){
				Retval=UncompressUpdater(fotaPara,UpdaterExecAddress);
				CP_LOGD("[OTA]UncompressUpdater[%d] %s !!!\r\n",Retval,Retval?"error":"success");
				if(Retval != NoError){
					CP_LOGE("[OTA] no updater paritition,parse updater failed[%02x]!!!\r\n",Retval);
					tiny_free(fotaPara_1);
					tiny_free(fotaPara_2);
					return;
				}
				
			}
			#endif
			tiny_free(fotaPara_1);
			tiny_free(fotaPara_2);

		}
		#if (!defined(BOOT33_FOTA_NO_UPDATER) || !defined(LTEONLY_SINGLE_SIM))
		else{
			Retval=System_ota_updater(fotaPara,&param,FotaParamStartAddress+FLASH_4K_SIZE-QSPI_FLASH_BASE);
			if(Retval==0){
				CP_LOGD("[OTA]System_ota_updater success!\r\n");
				memcpy(&updater_version,get_updater_start_addr(),sizeof(UpdaterHeaderInfo));
				CP_LOGD("[OTA] get new updater version %s !\r\n",updater_version.version_union.version_info_block.string);
				
				tiny_free(fotaPara_1);
				tiny_free(fotaPara_2);	
				return;
			}
			tiny_free(fotaPara_1);
			tiny_free(fotaPara_2);
		}
		#endif

done:
#if (!defined(BOOT33_FOTA_NO_UPDATER) || !defined(LTEONLY_SINGLE_SIM))
#ifdef 	ADD_VIBRATOR_IN_CODE
		//[0] Before jump to updater, disable vibrator
		NingboVibratorDisable();
#endif

		//[1] TODO:detect ADUPS flags
		CP_LOGD("[OTA] ASROTA prefix detected or Keypad Flag detect!\r\n");
		if(!updater_Entry){
			if(Retval != NoError){
				CP_LOGE("[OTA] no updater paritition,parse updater failed[%02x]!!!\r\n",Retval);
				return;
			}
			goto jump;
		}
#ifdef BOOT33_SECBOOT_SUPPORT
#ifdef BOOT33_SECBOOT_V2
    if(secboot_is_fuse_enabled()==1){
#endif

    	fip_image_t fip_item;

    	//[sec.0]secboot init from updater partition
    	//    which is updater.bin with a secboot ToC struct with only one FIP header
    	//    for updater.bin
    	//
    	//      |----------------|
    	//      | FIP Header     |
    	//      |----------------|
    	//      | Updater.bin    |
    	//      |----------------|
    	secboot_init("updater");

    	//[sec.1]do updater verify
    	Timer0_enable(TRUE);
    	secboot_item_check(ITEM_UPDATER);
    	Timer0_enable(FALSE);

    	//[sec.2]get info from fip of updater.bin
    	secboot_item_get_img_addr_size(ITEM_UPDATER,(fip_image_handle)&fip_item);

    	//[sec.3]for debug to dump header of real updater.bin
    	//display_binary((void *)(fip_item.start+fip_item.offset),256);

    	//[sec.4]load updater_a or updater_b to psram
    	memcpy( (void *)UpdaterExecAddress,
    		(void *)(fip_item.start+fip_item.offset),
    		fip_item.size
    		);
#ifdef BOOT33_SECBOOT_V2
    }else{
        //[2] TODO:load updater_a or updater_b to psram
    	memcpy( (void *)UpdaterExecAddress,
    		(void *)get_updater_start_addr(),
    		get_updater_copy_size());
    }
#endif

#else
	//[2] TODO:load updater_a or updater_b to psram
	memcpy( (void *)UpdaterExecAddress,
		(void *)get_updater_start_addr(),
		get_updater_copy_size());
#endif
#endif

jump:
		//[3] jump to execute updater
		CP_LOGD("\r\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
		CP_LOGD("\r\n >> BOOTLOADER DONE JUMP TO UPDATER");
		CP_LOGD("\r\n >> PC      : 0x%x",UpdaterExecAddress);
		CP_LOGD("\r\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\r\n");
		TransferControl(UpdaterExecAddress);
	}else{
		CP_LOGD("[OTA] NO FOTA FLAG DETECTED \r\n");
	}
}
#endif

