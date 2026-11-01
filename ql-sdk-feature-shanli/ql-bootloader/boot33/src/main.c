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
#include "ota.h"
#include "asr_property.h"
#include "bsp.h"
#include "ql_boot_power.h"
#include "ql_boot_pwm.h"
#include "Quec_startup_gpio.h"

#define  QUEC_PORGECT_CUST

#ifdef QUEC_PORGECT_CUST
#include "boot_flasherase_check.h"
//#include "boot_pin_test.h"
#endif

//transfer_parameter param;
extern unsigned int Load$$CODE$$Base;
extern unsigned int Image$$CODE$$Base;
extern unsigned int Image$$CODE$$Length;

extern unsigned int Load$$DATA$$RW$$Base;
extern unsigned int Image$$DATA$$RW$$Base;
extern unsigned int Image$$DATA$$RW$$Length;

extern unsigned int Image$$DATA$$ZI$$Base;
extern unsigned int Image$$DATA$$ZI$$Length;

extern unsigned int Load$$ITCM$$Base;
extern unsigned int Image$$ITCM$$Base;
extern unsigned int Image$$ITCM$$Length;

extern unsigned int Load$$DTCM$$RW$$Base;
extern unsigned int Image$$DTCM$$RW$$Base;
extern unsigned int Image$$DTCM$$RW$$Length;
extern unsigned int Image$$DTCM$$ZI$$Base;
extern unsigned int Image$$DTCM$$ZI$$Length;

extern unsigned int Load$$IMG_END$$Base;
extern unsigned int Image$$SEC_KEY_BUF$$Base;

#define IMG_END_ADDR ((unsigned int)&(Load$$IMG_END$$Base))
#define SEC_KEY_ADDR ((unsigned int)&(Image$$SEC_KEY_BUF$$Base))


extern int malloc_init(unsigned int ta_base, unsigned int length);
extern void PsramPhyFreqChangeTo416(void);
extern void CpCoreFreqChangeTo624(void);
extern int bbu_qspi_init(void);
extern void DM_CHARGE_Manager(void);
extern UINT8 PMIC_GET_POWER_UP_LOG(void);
extern void PMIC_Init(void);
extern void cp_uart_init(void );
extern void mpu_value_check(void);
extern void TransferControl(unsigned int);
extern int qspi_flash_init(void);
#define QSPI_AMBA_BASE  0x80000000U
#define PSRAM_BASE_ADDRESS  0x7E000000


void FIQ_Routine(void)
{
    uart_printf("Kernel Panic");
    uart_printf("Early FIQ call");

    while (1) {
    }
}

void UNDEF_Routine(void)
{
    uart_printf("Kernel Panic");
    uart_printf("UNDEF_Routine call");

    while (1) {
    }
}

void PABT_Routine(void)
{
    uart_printf("Kernel Panic");
    uart_printf("PABT_Routine call");

    while (1) {
    }
}

void DABT_Routine(void)
{
    uart_printf("Kernel Panic");
    uart_printf("DABT_Routine call");

    while (1) {
    }
}

void IRQ_Routine(void *arg)
{
    (void)arg;

    uart_printf("in IRQ_Routine");
}

/* Timer0_0 is configured to free run @1MHz from BootROM. */
#define APBTIMER0_CNT_REG   0xD4014090
#define APBTIMER0_EN_REG    0xD4014000

unsigned long Timer0IntervalInMilli(unsigned long Before, unsigned long After)
{
    unsigned long temp = (After - Before);
    return (temp / (1000));
}

unsigned long GetTimer0CNT(void)
{
    return *(volatile unsigned long*)APBTIMER0_CNT_REG;
}

void DelayInMilliSecond(unsigned int ms)
{
    unsigned long startTime, endTime;

    startTime = GetTimer0CNT(); 
    do
    {
        endTime = GetTimer0CNT();    
    }
    while(Timer0IntervalInMilli(startTime, endTime) < ms);
}

#define PMUTIMER_WDT_STATUS_REG 0xD4080070
BOOL IfWdtResetTriggered(void)
{
	return ((*(volatile unsigned long*)PMUTIMER_WDT_STATUS_REG) & 0x1);
}

void Timer0_enable(BOOL enable){
	if(enable){
        *(volatile unsigned long*)0xD4015034 = 0x43;
		*(volatile unsigned long*)APBTIMER0_EN_REG = 0x1; //enable timer0_0 (in free run)
	}else{
        *(volatile unsigned long*)0xD4015034 = 0x40;
	    *(volatile unsigned long*)APBTIMER0_EN_REG = 0x0; //stop Timer0_0 
	}
}


// This typedef describes the structure at which the CPU register's image is kept.
   typedef struct  {/** Total size - 31*4 == 124 bytes == 0x7C bytes. **/
	   UINT32 usrR1_R14[14];/**size=0x38**/// place to store relevant user\system registers (r1-r14)
	   UINT32 cpsr; 		/**size=0x4 **/// place to store the CPSR
	   UINT32 fiqR8_R14[7]; /**size=0x1C**/// place to store all FIQ registers	(r8-r14)
	   UINT32 abtSP_LR[2];	/**size=0x8 **/// place to store the abort stack pointer and link register
	   UINT32 undSP_LR[2];	/**size=0x8 **/// place to store the undefined stack pointer and link register
	   UINT32 irqSP_LR[2];	/**size=0x8 **/// place to store the interrupt stack pointer and link register
	   UINT32 svcSP_LR[2];	/**size=0x8 **/// place to store the supervisor stack pointer and link register
   }CommPM_CPUImageRegsS;

typedef struct { // this structure contains a 32 bit field for every R/W
				  // register of CP15 that might be modified after init (in run time).
	UINT32 dCacheLockdown;	/* inst. cache lockdown - register 9 */
	UINT32 iCacheLockdown;	/* data  cache lockdown - register 9 */
	UINT32 traceProcessID;	/* trace process ID 	- register 13*/
	UINT32 testState;		/* Test state			- register 15*/
	UINT32 cacheDebugIndex; /* Cache debug index	- register 15*/
}CommPM_CP15BackupS;


typedef struct {
        CommPM_CPUImageRegsS cpuRegs; // This field must be first (the assembly code relies on it).
        CommPM_CP15BackupS   cp15Backup;
    }CommPM_DTCM_DSS;


CommPM_DTCM_DSS _logoContextRegs;

volatile unsigned long CpExecAddress;
volatile unsigned long CpCopySize;
volatile unsigned long DspExecAddress;
volatile unsigned long DspCopySize;
volatile unsigned long CpFlashAddress;
volatile unsigned long Cp_2_FlashAddress;
volatile unsigned long DspFlashAddress;
volatile unsigned long rfCopySize;
volatile unsigned long rfFlashAddress;
volatile unsigned long rfLoadAddress;
volatile unsigned long DspImageSize;
volatile unsigned long DspBackupAddress;
volatile unsigned long DspRfMoveSize=0;
volatile unsigned long DspLoadSize;

unsigned long mini_system_enable = 0;
#define MALLOC_BUFFER_SIZE (0x00012000)
UINT8 g_MallocBuffer[MALLOC_BUFFER_SIZE];


typedef struct {
	UINT32 logoImageMagic; 
	UINT32 logoImageEntry;
	UINT32 LogoImageLoadAddress;
	UINT32 reserved;
#ifdef SUPPORT_COMPRESSED_LOGO
	UINT32 logo_compressed_magic;
#endif	
	//UINT32 Boot33Context[64];
}LogoImageHeader;

UINT32 reg_oldR0;
extern void saveContext(UINT32 R0, UINT32 R1);
extern void restoreContext(void);

#ifndef SUPPORT_NO_LOGO

extern unsigned int get_logo_start_addr(void);
extern unsigned int get_logo_end_addr(void);

extern void   TransferControlToLogo(unsigned int addr, unsigned int para);
extern BOOL ifPsramLimit200M(void);

typedef struct { 
	UINT32 ImageMagic; 
	UINT32 ImageInitialEntryPoint;
	UINT32 ImageLoadAddress;
	UINT32 ImageHeaderSize;
#ifdef SUPPORT_COMPRESSED_LOGO
	UINT32 logo_compressed_magic;
#endif	
}ImageHeader;

typedef enum{
	LZOP = 0,
	LZMA,
	NO_COMPRESSED
}CompressedType_e;

typedef struct{
	char  *ImageName;
	UINT32 FlashAddress;
	UINT32 LoadAddress;
	UINT32 FlashSize;
	UINT32 ExecSize;
	UINT32 UncompressDstAddr;
	CompressedType_e CompressedType;
	_ptflash ImageInFlashType;
}CopyImageInfo_t;


#define LOGO_MAGIC (0xBABE5F5F)
BOOL IsLogoMagicRight(const UINT32 LogoFlashAddr)
{
	UINT32 LogoMagic;
	
	//asr_norflash_read(LogoFlashAddr,(UINT8 *)&LogoMagic,sizeof(LogoMagic));
	crane_qspi_read(LogoFlashAddr - QSPI_FLASH_BASE,(UINT8 *)&LogoMagic,sizeof(LogoMagic));
	
	return LogoMagic == LOGO_MAGIC;
}



INT32 copy_compressed_logo_from_flash_to_psram(   CopyImageInfo_t *p_CopyLogoInfo,const UINT32 HeaderFileSize)
{
    INT32 ret;
    INT32 outLen = -1;
	BOOL SwitchFlag = FALSE;
	UINT32 UncompressSrcAddr;
	UINT32 UncompressDstAddr;
	UINT32 inLen;


#ifndef LTEONLY_SINGLE_SIM
	CpCoreFreqChangeTo624();
#endif
	if(ifPsramLimit200M()){
        PsramPhyFreqChangeTo350();
	}else{
        PsramPhyFreqChangeTo416();
	}

	enable_psram_cache();

#ifndef LTEONLY_SINGLE_SIM
	if(NO_COMPRESSED == p_CopyLogoInfo->CompressedType){
		//[3.1] logo.bin is not compressed
		CP_LOGD("memcopy: begin, dst:0x%x, src:0x%x, size:0x%x\r\n",
		         p_CopyLogoInfo->LoadAddress,
		         p_CopyLogoInfo->FlashAddress,
		         p_CopyLogoInfo->FlashSize);
		//asr_norflash_read(p_CopyLogoInfo->FlashAddress,(UINT8 *)p_CopyLogoInfo->LoadAddress,p_CopyLogoInfo->FlashSize);
		crane_qspi_read(p_CopyLogoInfo->FlashAddress - QSPI_FLASH_BASE,(UINT8 *)p_CopyLogoInfo->LoadAddress,p_CopyLogoInfo->FlashSize);
		ret = 0;
	}else 
#endif
		if(LZMA == p_CopyLogoInfo->CompressedType){
		CP_LOGD("start lzma decompress logo\r\n");
		
		/* load logo header info from flash into psram */
		CP_LOGD("[LOGO] load header info from flash to psram\r\n");
		//asr_norflash_read(p_CopyLogoInfo->FlashAddress,(UINT8 *)p_CopyLogoInfo->LoadAddress,HeaderFileSize);
		crane_qspi_read(p_CopyLogoInfo->FlashAddress - QSPI_FLASH_BASE,(UINT8 *)p_CopyLogoInfo->LoadAddress,HeaderFileSize);
		
		/* decompress compressed logo data from flash into psram */
		CP_LOGD("decompress logo from flash to psram\r\n");
		inLen = p_CopyLogoInfo->FlashSize - HeaderFileSize;
		UncompressDstAddr = p_CopyLogoInfo->LoadAddress  + HeaderFileSize;

		UncompressSrcAddr = p_CopyLogoInfo->FlashAddress + HeaderFileSize;

		CP_LOGD("src_addr:[0x%.08x],src_len:[0x%.08x],dst_addr:[0x%.08x], %s in flash type:%d\r\n",UncompressSrcAddr,inLen,
			UncompressDstAddr,p_CopyLogoInfo->ImageName,p_CopyLogoInfo->ImageInFlashType);
		
		if(LZMA == p_CopyLogoInfo->CompressedType){
			//LzmaOptimizeSwitch(TRUE);
			ret = LzmaUncompress((unsigned char *)UncompressDstAddr,(size_t *)&outLen, 
				(const unsigned char *)UncompressSrcAddr,(size_t *)&inLen);
			//LzmaOptimizeSwitch(FALSE);
		}
        CP_LOGD("inLen=[0x%.08x], outLen=[0x%.08x]\r\n",inLen,outLen);
	}

	disable_psram_cache();
#ifndef LTEONLY_SINGLE_SIM
	CpCoreFreqChangeTo416();
#endif
    return ret;
}


void logo_dispaly_entry(void)
{
	volatile UINT32 LogoFlashStartAddress;
	volatile UINT32 LogoFlashSize;
	ImageHeader logo_header;
	CompressedType_e CompressedType;
	CopyImageInfo_t  CopyLogoInfo;
	INT32 ret = -1;

	//The bspatch/lzma lib needs malloc/free APIs

	malloc_init(g_MallocBuffer, MALLOC_BUFFER_SIZE);
	CP_LOGD("malloc init done!\r\n");

	//[0] logo header table init.( will detect logo exist and valid in funtion internal)
	logo_header_table_init();


	//[1] get logo.bin flash info
	LogoFlashStartAddress = get_logo_flash_start_addr();
	LogoFlashSize = get_logo_flash_size();
	CP_LOGD("logo image in flash start addr: 0x%x ,Size: 0x%x\r\n",
				 LogoFlashStartAddress,
				 LogoFlashSize);


	//[2] read logo header block info from flash into psram
	//asr_norflash_read(LogoFlashStartAddress,(UINT8 *)&logo_header,sizeof(ImageHeader));
	crane_qspi_read(LogoFlashStartAddress - QSPI_FLASH_BASE,(UINT8 *)&logo_header,sizeof(ImageHeader));
#ifdef SUPPORT_COMPRESSED_LOGO
	//asr_norflash_read(LogoFlashStartAddress+logo_header.ImageHeaderSize,(UINT8 *)&logo_header.logo_compressed_magic,sizeof(logo_header.logo_compressed_magic));
	crane_qspi_read(LogoFlashStartAddress+logo_header.ImageHeaderSize - QSPI_FLASH_BASE,(UINT8 *)&logo_header.logo_compressed_magic,sizeof(logo_header.logo_compressed_magic));
	CP_LOGD("logo compressed magic: 0x%x\r\n",logo_header.logo_compressed_magic);
#endif
	CP_LOGD("logo magic:0x%x, entry point: 0x%x,load addr: 0x%x, header file size:0x%x\r\n",
				 logo_header.ImageMagic, 
				 logo_header.ImageInitialEntryPoint, 
				 logo_header.ImageLoadAddress,
				 logo_header.ImageHeaderSize
			);	


	if(logo_header.ImageHeaderSize == 0){
		CP_LOGE("[LOGO] Error, logo header size: 0x%.08x is errror!\r\n",logo_header.ImageHeaderSize);
		while(1);
	}

	//[3] load logo.bin to psram
	CopyLogoInfo.ImageName		  = "logo";
	CopyLogoInfo.CompressedType   = GetCompressedType(logo_header.logo_compressed_magic);
	CopyLogoInfo.FlashAddress	  = LogoFlashStartAddress;
	CopyLogoInfo.LoadAddress	  = logo_header.ImageLoadAddress;
	CopyLogoInfo.FlashSize		  = LogoFlashSize;
	CopyLogoInfo.ImageInFlashType = pt_flash_internal;//ptable_get_flash_type(CopyLogoInfo.ImageName);


	ret = copy_compressed_logo_from_flash_to_psram(&CopyLogoInfo,logo_header.ImageHeaderSize);
	if(0 != ret){
		CP_LOGE("[LOGO] copy logo.bin err!\r\n");
		while(1);
	}
	
	//[4] jump to execute updater
	CP_LOGD(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\r\n ");
	CP_LOGD("B33 JUMP TO LOGO at 0x%x\r\n", logo_header.ImageInitialEntryPoint); 
	CP_LOGD(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\r\n");
	
	TransferControlToLogo(logo_header.ImageInitialEntryPoint, NULL);
}
#else

#include "asr_lzma.h"
#define RFBIN_MAGIC 0x52467266

#define DSP_REDUCE_SULOG_SIZE		0x00052000
#define DSP_REDUCE_SULOG_IRBUF_SIZE	0x00049000

#define CRANEL_MULTI_RF_ADDRESS 0x7E045000
#define CRANEL_SINGLE_RF_SIZE   0x00005000//20K

#ifdef SPINOR_SUPPORT
static unsigned int PS_CODE_DDR_ADDR = 0;
static unsigned int DSP_BACKUP_END_ADDR = 0;


unsigned int get_ps_code_ddr_addr_from_Loadtable(void)
{
	char region_compress_mark[8];
	unsigned schedule_count = 0;
	rw_region_item region_info;
	unsigned int value = 0;
	
	char * rw_cpz_struct_addr=(char*)get_rw_cpz_struct_addr();

	if(PS_CODE_DDR_ADDR != 0)
	{
		return PS_CODE_DDR_ADDR;
	}

	CpExecAddress = get_cp_exec_addr(); //CP Exec Addr

	//load region compressed struct
	memcpy(region_compress_mark,
			rw_cpz_struct_addr,
			sizeof(region_compress_mark));

	if(!strncmp(region_compress_mark, RW_REGION_MARK_PRE_STRING ,strlen(RW_REGION_MARK_PRE_STRING)-1)){
		CP_LOGD("[CP ] Region CPZ struct detected from loadtable\r\n");
		while(1){
			//read NEXT region cpz info struct
			memcpy(&region_info
					,(void*)(rw_cpz_struct_addr + (sizeof(rw_region_item)*schedule_count++))
					,sizeof(rw_region_item));

			if(strncmp(region_info.RW_REGION_MARK, RW_REGION_MARK_PRE_STRING ,strlen(RW_REGION_MARK_PRE_STRING)-1))
			{
				break;
			}else if(region_info.RW_REGION_COMPRESSED_ADDR == RW_REGION_COMPRESSED_ADDR_NONE ){

				break;
			}


			if(!strncmp(region_info.RW_REGION_NAME,"CODE_PS",7)){
							//dump region info
			CP_LOGD("[CP ] GET [%8s] ddr address [%.08x]\r\n",
					region_info.RW_REGION_NAME,
					region_info.RW_REGION_EXEC_ADDR
					);
				value = region_info.RW_REGION_EXEC_ADDR;
				PS_CODE_DDR_ADDR = value;
				break;
			}

		}
	}
	return value;
}
#endif

void region_decompress_from_flash_to_psram(void){
    char region_compress_mark[8];
    unsigned schedule_count = 0;
    rw_region_item region_info;
	unsigned decompress_result,outLen,inLen;
	char * rw_cpz_struct_addr=(char*)get_rw_cpz_struct_addr();
	#ifdef SPINOR_SUPPORT
	_ptentry *cp2Entry = NULL;
	unsigned int offset=0;
	cp2Entry = ptable_find_entry("cp2");
	#endif

    CpExecAddress = get_cp_exec_addr(); //CP Exec Addr

    //load region compressed struct
    memcpy(region_compress_mark,
            rw_cpz_struct_addr,
            sizeof(region_compress_mark));

    if(!strncmp(region_compress_mark, RW_REGION_MARK_PRE_STRING ,strlen(RW_REGION_MARK_PRE_STRING)-1)){
        CP_LOGD("[CP ] Region CPZ struct detected from loadtable\r\n");
        while(1){
            //read NEXT region cpz info struct
            memcpy(&region_info
                    ,(void*)(rw_cpz_struct_addr + (sizeof(rw_region_item)*schedule_count++))
                    ,sizeof(rw_region_item));

            if(strncmp(region_info.RW_REGION_MARK, RW_REGION_MARK_PRE_STRING ,strlen(RW_REGION_MARK_PRE_STRING)-1))
            {
                //expend endpoint of RW decompress working flow for compressed image
                CP_LOGD("[CP ] stop decompress as no further %s detected\r\n",RW_REGION_MARK_PRE_STRING);
                break;
            }else if(region_info.RW_REGION_COMPRESSED_ADDR == RW_REGION_COMPRESSED_ADDR_NONE ){
                //expend endpoint of RW decompress working flow for uncompressed image
                //
                //no RW_REGION_COMPRESSED_ADDR detected,
                //image did not compressed with /x/tavor/Arbel/build/external_region_compress.pl script
                //the decompress would be done by /hop/BSP/src/Cinit1.c
                CP_LOGD("[CP ] skip region decompress as no RW_REGION_COMPRESSED_ADDR detected\r\n");
                break;
            }


#ifdef SPINOR_SUPPORT
			if(cp2Entry && DSP_BACKUP_END_ADDR){
				if(offset==0){
					offset = region_info.RW_REGION_COMPRESSED_ADDR;
				}
				crane_ext_spi_read((cp2Entry->vstart - SPI_FLASH_BASE)+(region_info.RW_REGION_COMPRESSED_ADDR - offset), DSP_BACKUP_END_ADDR, region_info.RW_REGION_LENGTH);
			}
			
			//dump region info
            CP_LOGD("[CP ] decompress [%8s] from [%.08x] to [%.08x] len[%08x]\r\n",
                    region_info.RW_REGION_NAME,
                    cp2Entry ? (cp2Entry->vstart + (region_info.RW_REGION_COMPRESSED_ADDR - offset)) : (region_info.RW_REGION_COMPRESSED_ADDR),
                    region_info.RW_REGION_EXEC_ADDR,
                    region_info.RW_REGION_LENGTH
                    );

			decompress_result=LzmaUncompress((unsigned char *)region_info.RW_REGION_EXEC_ADDR,
				(size_t *)&outLen, 
				cp2Entry ? ((const unsigned char *)DSP_BACKUP_END_ADDR):((const unsigned char *)region_info.RW_REGION_COMPRESSED_ADDR), 
				(size_t *)&region_info.RW_REGION_LENGTH);
#else
			//dump region info
			CP_LOGD("[CP ] decompress [%8s] from [%.08x] to [%.08x] len[%08x]\r\n",
					region_info.RW_REGION_NAME,
					region_info.RW_REGION_COMPRESSED_ADDR,
					region_info.RW_REGION_EXEC_ADDR,
					region_info.RW_REGION_LENGTH
					);

			decompress_result=LzmaUncompress((unsigned char *)region_info.RW_REGION_EXEC_ADDR,
				(size_t *)&outLen, 
				(const unsigned char *)region_info.RW_REGION_COMPRESSED_ADDR, 
				(size_t *)&region_info.RW_REGION_LENGTH);
#endif


            if(decompress_result != 0){
                CP_LOGE("\r\n ** ERROR: RW DECOMPRESS ERROR RESULT=[%d] outLen[%08x] inLen[%08x]",decompress_result,outLen,inLen);
                while(1) {};
            }
        }
    }
    else
    {
        CP_LOGW("[CP ] Region CPZ struct not detected from loadtable\r\n");
    }

}


extern int crane_ext_spi_read(unsigned int addr, unsigned int buf_addr, unsigned int size);


int copy_dsp_from_flash_to_psram(void)
{
	unsigned long magic;
    int ret = -1;
    int outLen = -1;
	unsigned int inLen=0;
	_ptentry *dspEntry;
	CompressedType_e CompressedType;

	dspEntry = ptable_find_entry("dsp");
	DspFlashAddress = dspEntry->vstart;
	DspImageSize = dspEntry->vsize;
	inLen = DspImageSize;
	
	DspExecAddress = get_dsp_backup_addr();
	DspLoadSize = get_dsp_backup_size();
	
	CP_LOGD("copy_dsp_from_flash_to_psram, DspFlashAddress=0x%x, DspImageSize=0x%x, inLen=0x%x, DspExecAddress=0x%x,\r\n",DspFlashAddress,DspImageSize,inLen,DspExecAddress);
	#ifdef SPINOR_SUPPORT
	if((DspFlashAddress & SPI_FLASH_BASE) == SPI_FLASH_BASE)
	{
		unsigned int flash_offset = DspFlashAddress - SPI_FLASH_BASE;
		DspFlashAddress = get_ps_code_ddr_addr_from_Loadtable();//get_dsp_backup_end_addr() + 0x10000; //use the start 128K of PS NOCACHE as dsp buf
		//memset((void*)DspFlashAddress, 0, 0x30000);
		CP_LOGD("temp DspFlashAddress=0x%08x, size 0x%08x,flash_offset=0x%x,\r\n", DspFlashAddress , dspEntry->size, flash_offset);
		crane_ext_spi_read(flash_offset, DspFlashAddress, dspEntry->size);
	}
	#endif


    //uart_printf("[DSP] decompress from [0x%.08x] to [0x%0.8x] DspRfMoveSize[%08x]\r\n", FLASH_DSP_START ,PSRAM_DSP_START,DspRfMoveSize);
    //uart_printf("[DSP] expected released dsp size [0x%.08x], inLen[0x%.08x]\r\n", DSP_COPY_SIZE,*inLen);

	magic = *(volatile unsigned long*)DspFlashAddress;
	CompressedType = GetCompressedType(magic);
	if(CompressedType==LZMA)
	{
	    CP_LOGD("LZMA compressed DSP image.\r\n");

		if(!LzmaUncompress((unsigned char *)DspExecAddress,(size_t *)&outLen, (const unsigned char *)DspFlashAddress, (size_t *)&inLen))
		{
			CP_LOGD("[DSP] released dsp size [0x%.08x] inLen[0x%.08x]\r\n", outLen,inLen);
			#ifdef SPINOR_SUPPORT
			DSP_BACKUP_END_ADDR = DspExecAddress + outLen;
			#endif

			if(outLen != DspLoadSize){
				CP_LOGE("[DSP] WARNING: decompressed length [0x%.08x] unmatch with expected [0x%.08x].\r\n",outLen,DspLoadSize);
				if((DspLoadSize <= DSP_REDUCE_SULOG_SIZE) && (outLen < DspLoadSize)){
					ret = 0;
				}else{
					ret = -1;
				}
			}else{
				ret = 0;
			}
			
		}else{
		        CP_LOGE("\r\n ** ERROR: DSP image decompress failed .\r\n");
	    }
		
    }
	if(ret!=0){
		while(1);
	}
    return ret;
}



UINT32 CalcImageChecksum( UINT32* DownloadArea, UINT32 ImageLength,UINT32 checksum)
{
	//uart_printf("CalcImageChecksum DownloadArea[%08x],ImageLength[%08x]\r\n",DownloadArea,ImageLength);
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

int copy_rf_from_flash_to_psram(void)
{
	
    //COPY rf.bin
    unsigned int tmp;
	_ptentry *rfEntry;
	unsigned long magic;
	unsigned long offset;
	int outLen = -1;
	CompressedType_e CompressedType;
	UINT32 checksum = 0;
	UINT32 rfbackupAddress = 0;

	rfEntry = ptable_find_entry("rfbin");
	rfbackupAddress = get_dsp_backup_end_addr();
	
	
	rfFlashAddress = rfEntry->vstart;
	rfCopySize = rfEntry->vsize;
	CP_LOGD("copy_rf_from_flash_to_psram, rfFlashAddress=0x%x, rfCopySize=0x%x, rfLoadAddress=0x%x,\r\n",rfFlashAddress,rfCopySize,rfLoadAddress);
	
	#ifdef SPINOR_SUPPORT
	if(((unsigned int)rfFlashAddress & SPI_FLASH_BASE) == SPI_FLASH_BASE)
	{
		unsigned int flash_offset = rfFlashAddress - SPI_FLASH_BASE;
		rfFlashAddress = get_ps_code_ddr_addr_from_Loadtable();//get_dsp_backup_end_addr() + 0x10000; //use the end 32K of heap as dsp buf
		//memset(rfFlashAddress, 0, 0x8000);
		crane_ext_spi_read(flash_offset, rfFlashAddress, rfEntry->size);
	}
	#endif

	
    CP_LOGD("[RF ] copy from [0x%0.8x] to [0x%0.8x] size[0x%0.8x],backup[0x%0.8x]\r\n",
            rfFlashAddress,
            rfLoadAddress,
            rfCopySize,
            rfbackupAddress);
	magic = *(volatile unsigned long*)rfFlashAddress;
	CompressedType = GetCompressedType(magic);
	if (LZMA == CompressedType)
	{
		//offset =  rfLoadAddress - PSRAM_BASE_ADDRESS;  
		if(!LzmaUncompress((unsigned char *)rfbackupAddress + 8,(size_t *)&outLen, (const unsigned char *)rfFlashAddress, (size_t *)&rfCopySize))
		{
			if(DspLoadSize<=DSP_REDUCE_SULOG_SIZE){
				*(volatile unsigned long*)rfbackupAddress = RFBIN_MAGIC;
				*(volatile unsigned long*)(rfbackupAddress + 4) = outLen;
				//checksum=CalcImageChecksum((UINT32 *)(rfbackupAddress + 8),  outLen, 0);	
			}else{
				rfLoadAddress = get_rf_load_addr();
				if((outLen>CRANEL_SINGLE_RF_SIZE) && CHIP_IS_CRANEL){
                    rfLoadAddress = CRANEL_MULTI_RF_ADDRESS;
                }
				memcpy(DspExecAddress+(rfLoadAddress-PSRAM_BASE_ADDRESS),(UINT32 *)(rfbackupAddress + 8),outLen);
			}
			CP_LOGD("[RF] released rf size [0x%.08x] inLen[0x%.08x] checksum[0x%.08x]\r\n", outLen,rfCopySize,checksum);

		}else{
		        CP_LOGE("\r\n ** ERROR: RF image decompress failed .\r\n");
	    }

	}else{
		CP_LOGE("\r\n ** ERROR: RF image decompress failed .\r\n");
		while(1);
	}
    return 0;
}




void PrepareToExecuteCp(void)
{

#ifdef DEBUG_LZMA	
	Timer0_enable(TRUE);
#endif

	/* [NOTE] move these init code into logo as pm803 use */
	/* printf the Chip ID */
	CP_LOGD("chip id: 0x%.08x\r\n",GetLongChipID());

	//CpCoreFreqChangeTo624();
	if(ifPsramLimit200M()){
        PsramPhyFreqChangeTo350();
	}else{
        PsramPhyFreqChangeTo416();
	}

	enable_psram_cache();
	
	malloc_init(g_MallocBuffer, MALLOC_BUFFER_SIZE);
		
	if(copy_dsp_from_flash_to_psram()){
		goto FAIL;
	}

	if(copy_rf_from_flash_to_psram()){
		goto FAIL;
	}

    region_decompress_from_flash_to_psram();


	disable_psram_cache();
	//CpCoreFreqChangeTo416();

#ifdef DEBUG_LZMA	
	Timer0_enable(FALSE);
#endif	
	CP_LOGD("Decompress cp, dsp, rf data END!\r\n");
	return;
FAIL:
	CP_LOGE("PrepareToExecuteCp failed!\r\n");
	while(1);

}
#endif



void bootloader(void)
{
    unsigned int val;
    volatile UINT8 var;
    //transfer_parameter param;
    //unsigned long cp_part_load, cp_part_image, cp_part_size;
#ifdef AVOID_PTABLE
#else
    _ptentry *cpEntry, *dspEntry,*rfEntry;
#endif
	unsigned int src_addr;
	unsigned int dst_addr;
	unsigned int len;
	unsigned int i;
	unsigned int *psrc, *pdst;
	unsigned int stack = 0;
	unsigned int poolLen = 0;

#ifdef BOOT33_SECBOOT_SUPPORT
	src_addr=IMG_END_ADDR; //copy secboot key to squ
	dst_addr=SEC_KEY_ADDR;
	len=512;
	len=(len+3)/4;
	psrc=(unsigned int *)src_addr;
	pdst=(unsigned int *)dst_addr;
	for(i=0;i<len;i++)
		*pdst++=*psrc++;
#endif

	src_addr=(unsigned int)&(Load$$ITCM$$Base);
	dst_addr=(unsigned int)&(Image$$ITCM$$Base);
	len=(unsigned int)&(Image$$ITCM$$Length);
	len=(len+3)/4;
	psrc=(unsigned int *)src_addr;
	pdst=(unsigned int *)dst_addr;
	for(i=0;i<len;i++)
		*pdst++=*psrc++;

	src_addr=(unsigned int)&(Load$$DTCM$$RW$$Base);
	dst_addr=(unsigned int)&(Image$$DTCM$$RW$$Base);
	len=(unsigned int)&(Image$$DTCM$$RW$$Length);
	len=(len+3)/4;
	psrc=(unsigned int *)src_addr;
	pdst=(unsigned int *)dst_addr;
	for(i=0;i<len;i++)
		*pdst++=*psrc++;


	src_addr=(unsigned int)&(Load$$CODE$$Base);
	dst_addr=(unsigned int)&(Image$$CODE$$Base);
	len=(unsigned int)&(Image$$CODE$$Length);
	len=(len+3)/4;
	psrc=(unsigned int *)src_addr;
	pdst=(unsigned int *)dst_addr;
	for(i=0;i<len;i++)
		*pdst++=*psrc++;

	src_addr=(unsigned int)&(Load$$DATA$$RW$$Base);
	dst_addr=(unsigned int)&(Image$$DATA$$RW$$Base);
	len=(unsigned int)&(Image$$DATA$$RW$$Length);
	len=(len+3)/4;
	psrc=(unsigned int *)src_addr;
	pdst=(unsigned int *)dst_addr;
	if(len != 0){
		psrc += (len-1);
		pdst += (len-1);
	}
	for(i=0;i<len;i++)
		*pdst--=*psrc--;


	dst_addr=(unsigned int)&(Image$$DATA$$ZI$$Base);
	len=(unsigned int)&(Image$$DATA$$ZI$$Length);
	len=(len+3)/4;
	pdst=(unsigned int *)dst_addr;
	for(i=0;i<len;i++)
		*pdst++=0;



	dst_addr=(unsigned int)&(Image$$DTCM$$ZI$$Base);
	len=(unsigned int)&(Image$$DTCM$$ZI$$Length);
	len=(len+3)/4;
	pdst=(unsigned int *)dst_addr;
	for(i=0;i<len;i++)
		*pdst++=0;

	ql_gpio_init(GPIO_PIN_NO_53,PIN_DIRECTION_OUT, PIN_PULL_PD, PIN_LEVEL_LOW);
	ql_gpio_set_level(GPIO_PIN_NO_53,PIN_LEVEL_LOW);	
	
    //uart init
	cp_uart_init();
    CP_LOGD("Boot33 UART INIT DONE\r\n");

    PMIC_Init();

	//Print VB_VERSION INFO
	extern Boot33VerBlockType boot33_vb;
	CP_LOGW("\r\n[BOOT33]VB_VERSION_DATE   :[%s]\r\n",boot33_vb.vb.version_block.version_date);
	CP_LOGD("[BOOT33]VB_OEM_LCD_TYPE   :[%s]\r\n",boot33_vb.vb.version_block.oem_lcd_type);
	CP_LOGD("[BOOT33]VB_SECBOOT_SUPPORT:[%s]\r\n",boot33_vb.vb.version_block.secboot_support);
	CP_LOGD("[BOOT33]build_info_string :[%s]\r\n",boot33_vb.vb.version_block.build_info_string);

	asr_property_set("b33.version",boot33_vb.vb.version_block.build_info_string);
	asr_property_set("b33.secboot",boot33_vb.vb.version_block.secboot_support);
	asr_property_set("b33.compressed_logo",boot33_vb.vb.version_block.logo_compress_support);
	asr_property_dump();
	
#ifndef CRANEL_CHIP
    if (!IfWdtResetTriggered())
    {
        var = PMIC_GET_POWER_UP_LOG();
        CP_LOGD("PowerOnLog: 0x%x\r\n", var);
#ifdef 	ADD_VIBRATOR_IN_CODE
        NingboVibratorEnable();
#endif
    }
#endif
#ifdef QUEC_BOOT_GET_POWERUP_REASON
	int reason;
	reason = ql_get_powerup_reason();
	uart_printf("powerup reason-----------------------:%d\r\n",reason);
#endif
    CP_LOGD("Built by DS-5.\r\n");

    /* Enable MPU and using the cortex-r default memory map as the background region */
	reset_all_mpu_reg();
    val = sctlr_get();
    val |= SCTLR_BR | SCTLR_M;
    sctlr_set(val);

    CP_LOGD("boot33 MPU config\r\n");


	set_mpu_reg_background(1);//FULL_ACCESS
	set_mpu_reg_itcm();
	set_mpu_reg_dtcm();
	set_mpu_reg_flash(0x01000000);//16M
	set_mpu_reg_asic_reg();
	set_mpu_reg_psram(0);
#ifdef BOOT33_SECBOOT_V2
	set_mpu_reg_squ();
	set_mpu_reg_arom();
#endif
	set_mpu_reg_background(0);//NO_ACCESS
    
	mpu_value_check();


#ifdef BOOT33_SECBOOT_V2
	extern  void syscall_init(void);
    CP_LOGD("syscall_init\r\n");
	syscall_init();
    CP_LOGD("aboot_sys_getversion : %s \n", aboot_sys_getversion());
#endif

#ifdef DMCHAGE
    DM_CHARGE_Manager();
#endif
//    PMIC_Init();
//	sdcard_init();


    //PTABLE INIT AND DUMP
    if (ptable_init())
    {
        CP_LOGE("bad partition table!\r\n");
        goto FAIL;
    }
    ptable_dump();


    //KEY PARTITION INFO FETCH
    cpEntry = ptable_find_entry("cp");
    CpFlashAddress = cpEntry->vstart;

    //QSPI FLASH INIT
    bbu_qspi_init();
	#ifdef SPINOR_SUPPORT
	//SPI NOR FLAHS INIT
	int external_spi_init(void);
	external_spi_init();
	#endif
#ifdef SUPPORT_FBP
	crane_set_fbp(FALSE);
#endif	

    //LOADTABLE INIT AND DUMP
    loadtable_init(CpFlashAddress);

#ifdef BOOT33_FOTA_SUPPORT
    ota_entry();
#endif

#ifndef CRANEL_CHIP
#ifdef 	ADD_VIBRATOR_IN_CODE
	//add boot up feedback:disable vibration
	NingboVibratorDisable();
#endif
#endif

#ifdef QUEC_NORFLASH_ERASE_OPTIMIZE 
	Quec_FlashErase_Optimize();
#endif

	//TODO:After detecting OTA_FLAG, Close keypad interrupt and keypad mode, clear keypad wake event
	//Keypad_disable();
	dump_loadtable();

#ifdef BOOT33_SECBOOT_SUPPORT
	#include "secboot.h"
	#ifdef BOOT33_SECBOOT_V2
	if(secboot_is_fuse_enabled()==1){
	#endif
	if(!mini_system_enable)
	{
    	secboot_init("fwcerts");
    	Timer0_enable(TRUE);
    	/*
    	currenttly do not support image inside internal 8M spi_nor flash
    	below items under secboot check , also open config to customer
    	refer to their owner fip image config inside of ABOOT config.json
    	*/
    	secboot_item_check(ITEM_CP);     //item CP_IMAGE_ID of fip .json
    	secboot_item_check(ITEM_DSP);    //item DSP_IMAGE_ID of fip .json
    	//secboot_item_check(ITEM_APP);    //item APP_IMAGE_ID of fip .json
    	//secboot_item_check(ITEM_USER1);  //item USER1_IMAGE_ID of fip .json
    	//secboot_item_check(ITEM_USER2);  //item USER2_IMAGE_ID of fip .json
    	//secboot_item_check(ITEM_USER3);  //item USER3_IMAGE_ID of fip .json
    	secboot_item_check(ITEM_LOGO);   //item LOGO_IMAGE_ID of fip .json
    	Timer0_enable(FALSE);
	}
	#ifdef BOOT33_SECBOOT_V2
	}
	#endif
#endif

#ifdef SUPPORT_FBP
	crane_set_fbp(TRUE);
#endif	

#ifdef SUPPORT_NO_LOGO
	PrepareToExecuteCp();
#else
	logo_dispaly_entry();
    CpExecAddress = get_cp_exec_addr(); //CP Exec Addr	
#endif
	//CP_LOGE("ql_pwm_test");
	//ql_pwm_test();


    // [3] transfer control
    CP_LOGD("\r\n ********************************************");
    CP_LOGD("\r\n ** BOOTLOADER DONE JUMP TO CP IMAGE");
    CP_LOGD("\r\n ** VERSION : %s",boot33_vb.vb.version_block.version_date);
    CP_LOGW("\r\n ** PC      : 0x%x\r\n",CpExecAddress);
    CP_LOGD("\r\n ********************************************\r\n");

    TransferControl(CpExecAddress);
FAIL:
    CP_LOGE("Bootloader FAILED");
    while(1);
}

