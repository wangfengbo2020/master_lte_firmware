#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cpu.h"
#include "qspi.h"
#include "reg.h"
#include "system.h"
#include "ptable.h"
#include "loadtable.h"
#include "lzop.h"
#include "sdio.h"
#include "pmic.h"
#include "ff.h"
#include "version_logo.h"
#include "asr_property.h"
#include "guilin.h"
#include "logo_table.h"
#include "asr_lzma.h"
#include "utilities.h"
#include "bsp.h"

#include "quec_cust_startup_feature.h"
#include "quec_lcd_application.h"
#include "ql_boot_power.h"
#include "ql_gpio.h"


//unsigned int init_cpsr;

/*
*****************************************************************************************
*			some debug macros
*
*Note:  the following MACRO default state: "CLOSED".
*2. TEST_OTA_DISPLAY_INFO              	If define this MACRO, add debug code for OTA_DISPLAY
*
*****************************************************************************************
*/
//#define TEST_OTA_DISPLAY_INFO

/*
*****************************************************************************************
*			some function MACRO
*
*Note:  the following MACROs default state: "OPEN".
*1. ADD_VIBRATOR_IN_CODE				If define this MACRO, add vibrator feedback after onkeycheck during boot up.
*2. SUPPORT_MALLOC						If define this MACRO, support malloc mechanism
*****************************************************************************************
*/
#define ADD_VIBRATOR_IN_CODE
//#define SUPPORT_MALLOC

#define LZOP_COMPRESSED_MAGIC (0x4f5a4c89)
#define LZMA_COMPRESSED_MAGIC (0x8000005D)
#define LZMA_COMPRESSED_MAGIC1 (0x0800005D)
#define LZMA_COMPRESSED_MAGIC2 (0x0400005D)
#define LZMA_COMPRESSED_MAGIC3 (0x0200005D)


#define MODE32_svc          0x13
#define SPSR_T_ARM          0
#define SPSR_E_LITTLE       0
#define SPSR_FIQ_BIT        (1 << 0)
#define SPSR_IRQ_BIT        (1 << 1)
#define SPSR_ABT_BIT        (1 << 2)
#define DISABLE_ALL_EXCEPTIONS  (SPSR_FIQ_BIT | SPSR_IRQ_BIT | SPSR_ABT_BIT)

#define MODE_RW_SHIFT       0x4
#define MODE_RW_32      0x1
#define MODE32_SHIFT        0
#define MODE32_MASK     0x1f
#define SPSR_T_SHIFT        5
#define SPSR_T_MASK     0x1
#define SPSR_E_SHIFT        9
#define SPSR_E_MASK     0x1
#define SPSR_AIF_SHIFT      6
#define SPSR_AIF_MASK       0x7

#define SPSR_MODE32(mode, isa, endian, aif)     \
    (MODE_RW_32 << MODE_RW_SHIFT |          \
     ((mode) & MODE32_MASK) << MODE32_SHIFT |    \
     ((isa) & SPSR_T_MASK) << SPSR_T_SHIFT |     \
     ((endian) & SPSR_E_MASK) << SPSR_E_SHIFT |  \
     ((aif) & SPSR_AIF_MASK) << SPSR_AIF_SHIFT)

/******************************
MACRO NAME: ADD_VIBRATOR_IN_CODE
Despriction:   Add vibrator feedback after onkeycheck during boot up. 
		       Default: no vibrator feedback
		       
Owner:         Hengshan Yang
Time:          2019-10-16
******************************/


typedef struct {
#if 1 //yqian
    uint32_t  pc;
#else
    uintptr_t pc;
#endif
    uint32_t  spsr;
} transfer_parameter;

/* enum for battery operation */
typedef enum{
	BatteryLevelIsHigh = 0,
	BatteryLevelIsMedium,
	LowBatteryLevel_And_ChargerNoDetect,
	GetBatteryLevelFail,
	Calbration_flag_Not_Set,
	Dsp_adc_NotExist
}LogoBattery_t;



/* global variable for malloc mechanism  */
#ifdef SUPPORT_MALLOC
#define MALLOC_BUFFER_SIZE (0x00050000)
UINT8 g_MallocBuffer[MALLOC_BUFFER_SIZE];
#endif

/* MACRO for config cache */
// NOTE : cache start addr must br multiple of cache size and cache size must 2,4,8..
#define PSRAM_CONFIG_CACHE_START_ADDR 0x7E000000
#define PSRAM_CONFIG_CACHE_SIZE 	  0x01000000	


static int cpy_dsp_by_cp=0;
volatile unsigned long DspBackupAddress;
volatile unsigned long DspFlashAddress;
volatile unsigned long CpExecAddress;
volatile unsigned long CpCopySize;
volatile unsigned long DspExecAddress;
volatile unsigned long DspLoadSize;
volatile unsigned long CpFlashAddress;
volatile unsigned long Cp_2_FlashAddress;
volatile unsigned long rfCopySize;
volatile unsigned long rfFlashAddress;
volatile unsigned long rfLoadAddress;
volatile unsigned long DspImageSize;
volatile unsigned long DspBackupSize;
volatile unsigned long DspRamSize=0;

#define FLASH_CP_START  CpFlashAddress
#define FLASH_DSP_START DspFlashAddress
#define PSRAM_DSP_START DspExecAddress
#define DSP_LOAD_SIZE   DspLoadSize
#define DSPBACKUP_SIZE 	DspBackupSize

//#ifdef ONKEY_CHECK
/* Timer0_0 is configured to free run @1MHz from BootROM. */
#define APBTIMER0_CNT_REG   0xD4014090
#define APBTIMER0_EN_REG    0xD4014000
#define APBTIMER0_CLK_REG   (0xD4015000+0x34)

#ifdef LTEONLY_SINGLE_SIM
#define LOGO_HEAP_SIZE (0x00012000)
#else
//增大heap大小到320KB,LCD刷屏需要这么大的heap
#define LOGO_HEAP_SIZE (0x00050000)
#endif

#define CRANEL_4MRAM_RF_ADDRESS 0x7E065000
#define CRANEL_MULTI_RF_ADDRESS 0x7E045000
#define CRANEL_SINGLE_RF_SIZE   0x00005000//20K


//void transfer_control(transfer_parameter *param) __attribute__ ((noreturn));
extern void transfer_control(transfer_parameter *param);
//extern int lzop_decompress_safe(lzo_bytep src,  lzo_bytep dest, lzo_uint32p dest_len, lzo_uint32p cpz_src_len);
extern void cp_uart_init(void );

/* global variable for record "enable cache and improve core freq" for LZMA */
volatile BOOL g_LzmaOptimizeFlag = FALSE;
extern unsigned int Image$$IMG_END$$Base;

#define LOGO_IMG_END_ADDR ((unsigned int)&(Image$$IMG_END$$Base))

extern BOOL ifPsramLimit200M(void);

void Timer0_enable(BOOL enable){
	if(enable)
	{
		*(volatile unsigned long*)APBTIMER0_CLK_REG = 0x43; //Timer0_0	//Fias.fan 20220608 这个必须在APBTIMER0_EN_REG之前，使用时也必须调用 Timer0_enable(TRUE); 打开
		*(volatile unsigned long*)APBTIMER0_EN_REG = 0x1; //enable timer0_0 (in free run)
	}
	else
	{
		*(volatile unsigned long*)APBTIMER0_EN_REG = 0x0; //stop Timer0_0 
		*(volatile unsigned long*)APBTIMER0_CLK_REG = 0x4; //Timer0_0	//这个值 0x4 是不打开时读寄存器的默认值，关闭时和打开顺序相反
	}
}



void GetKeyPartitionInfoFetch(void)
{	
	_ptentry *cpEntry, *cp_2_Entry;

	cpEntry = ptable_find_entry("cp");
	CpFlashAddress = cpEntry->vstart;
	if(cpEntry == NULL)
		CpFlashAddress = CP_BASE_ADDR;//default address as backup one
}

extern void mpu_value_check(void);
extern void   TransferControl(unsigned int);

#ifdef LCD_USE_IN_CODE
FIL handle;
unsigned char data_buf[64];

FIL handle_lcd;

#ifdef WATCHLCDST7789_CODE_USE
UINT16 picture_buf_2[115200/2];
#else
UINT16 picture_buf_2[153600/2];
#endif

//LCD function declaration
extern int mci_Logo_LcdInit(UINT32 background);
extern void POWER_ON_LCD_ShowImage(void);
extern VOID mci_LcdSetBrightness(UINT8 level);
extern void mci_Logo_LcdClose(void);
#endif

unsigned long Timer0IntervalInMilli(unsigned long Before, unsigned long After)
{
    unsigned long temp = (After - Before);
    return (temp / (1000));
}

void SetTimer0CLK(void)
{
	*(volatile unsigned long*)APBTIMER0_CLK_REG = 0x43; //Timer0_0 
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

//#endif

void printlog(void)
{
	CP_LOGI("LOGO END\r\n");
	
	//int delay=0x8888;
	//while(delay--);
}

#ifdef TEST_OTA_DISPLAY_INFO
extern void OTA_LCD_DisplayText(char *text, int text_length,int16_t text_height_offset,OTA_LANGUAGE_T ota_language);
extern MCI_ASR_LCD_INFO lcd_info_test;
void test_lcd_display(void)
{
	INT32 i;

	init_lcd_vars();

	/* add test code to test lcd dispaly api */
	
	mci_LcdSetBrightness(3);	//Turn on the blacklight later to fix "Blurred Screen"
	while(1);	
}
#endif

void test_float_data( void )
{
	float f_1 = 5.0;
	float f_2 = 1.0;

	CP_LOGD("f_1:%d\r\n",(int)f_1);
}

void test_fitting_calculate(       void )
{							
						//  ADC			real vol
	const INT32 array[2][2] = { { 497,		3265 },
						  		{ 521,		3519 }
							  };
	INT32 result = 0;
	float k = 0.0, b = 0.0;
	
	CP_LOGD("func:%s\r\n",__func__);

	k = ( (float)array[1][1] - array[0][1] ) / ( array[1][0] - array[0][0] );
	b = (float)array[0][1] - array[0][0] * k ;

	result = (INT32)(k * 514 + b);

	CP_LOGD("result:%d\r\n",result);
}


extern const LogoHeaderTableStruct logo_vb;

BOOL IsDisplayLogo(const LogoBattery_t BatteryRes)
{
	/* check startup reason is WDT reset or not? */
	if(IfWdtResetTriggered()){
		CP_LOGW("Restart by WDT reset\r\n");
		return FALSE; 
	}

	/*check restart reason is "RdProduction" or not*/
    if(isSysRestartByRdProduction()){
		CP_LOGW("Restart By RdProduction\r\n");
		return FALSE; 
    }
	
	/*check battery level */
	if(BatteryRes == LowBatteryLevel_And_ChargerNoDetect){
		CP_LOGI("battery level is less than low threshold and charger not detect, not display logo\r\n");
		return FALSE;
	}

	if( BatteryRes == GetBatteryLevelFail){
		CP_LOGI("battery level get fail, not display logo\r\n");
		while(1);
//		return FALSE;
	}
	if( BatteryRes == Calbration_flag_Not_Set || BatteryRes == Dsp_adc_NotExist ){
		return FALSE;
	}

	/* display logo is valid */
	CP_LOGI("display logo!\r\n");
	return TRUE;   	
}

//查询Vbatt的电压
void CheckBatteryLevel(LogoBattery_t *pBatteryRes)
{
	BOOL IsChargerDectect;
	UINT32 battery_level;
	static BOOL PrintFlag = TRUE;

	while(1)
	{
		//get battery voltage
		if (PMIC_IS_PM813()||PMIC_IS_PM813S())
		{
			battery_level = pm813_get_bat_vol();
		}
		else if(PMIC_IS_PM802())
		{
			battery_level = pm802_get_battery_voltage();
		}
		else if( PMIC_IS_PM803() )
		{
			#if defined(ASR_PLATFORM_CRANEM)
				PM803_Battery_Res_t pm803_battery_res;
				Timer0_enable( TRUE );
				pm803_get_battery_voltage( &pm803_battery_res );
				battery_level = pm803_battery_res.BatteryValue;
				Timer0_enable( FALSE );
				CP_LOGI("pm803_battery_res:%d\r\n",pm803_battery_res.pm803_status_res);
				
				if( pm803_battery_res.pm803_status_res == PM803_CalbrationFlagNotSet ){
					*pBatteryRes = Calbration_flag_Not_Set;
					return;
				}
				if( pm803_battery_res.pm803_status_res == PM803_BatteryFlagNotReady ||
					pm803_battery_res.pm803_status_res == PM803_FitFail ||
					pm803_battery_res.pm803_status_res == PM803_Load_Dsp_adc_Fail ){
					*pBatteryRes = GetBatteryLevelFail;
					return;
				}
				if( pm803_battery_res.pm803_status_res == PM803_Dsp_adc_Not_Exist ){
					*pBatteryRes = Dsp_adc_NotExist;
					return;
				}
			#elif defined(ASR_PLATFORM_CRANEL)
			
				battery_level = get_cranel_vbat();
				
			#else
				#error "Please configure the project"
			#endif
		}
		else
		{
			CP_LOGI("CheckBatteryLevel: Not PM813(S) or PM802 or PM803.\r\n");
			return; //PM803 TBD, no GPADC func
		}
		
		if(battery_level > BATTERY_LOW_THRESHOLD)
		{
			if(battery_level > BATTERY_HIGH_VALUE)
			{
				//case: battery voltage is more than "BATTERY_HIGH_VALUE"
				*pBatteryRes = BatteryLevelIsHigh;
			}
		    else
			{
				//case: battery voltage is more than "low threshold"
				CP_LOGI("battery level: %d, more than low threshold: %d\r\n",battery_level,BATTERY_LOW_THRESHOLD);			
				*pBatteryRes   = BatteryLevelIsMedium;
			}
			
			break;
		}

		//check usb is detected ?
		IsChargerDectect = PM812_CHARGER_IS_DETECTED();
		if(IsChargerDectect == FALSE)
		{
			CP_LOGI("battery level: %d, not more than low threshold: %d\r\n",battery_level,BATTERY_LOW_THRESHOLD);
			CP_LOGW("Charger disconnect\r\n");
			*pBatteryRes   = LowBatteryLevel_And_ChargerNoDetect;
			break;
		}
		else
		{
			if(PrintFlag == TRUE){
				CP_LOGI("battery level: %d, not more than low threshold: %d\r\n",battery_level,BATTERY_LOW_THRESHOLD);
				CP_LOGI("Charger Connect\r\n");
				CP_LOGI("In Chargering...\r\n");
				PrintFlag = FALSE;
			}
		}
	}

	return;
}


//此函数检测电池电压,并判断是否进行开机LCD的logo 显示
void Vibrator_And_LogoFeedback(void)
{
	BOOL ret_val;
	LogoBattery_t BatteryRes;
	UINT32 BrightnessLevel;
	
	/* check battery level */
	CP_LOGD("check battery level\r\n");
	CheckBatteryLevel(&BatteryRes);
	CP_LOGD("BatteryRes:%d\r\n",BatteryRes);
	switch(BatteryRes)
	{
	   case BatteryLevelIsHigh:
		   BrightnessLevel = Normal_BackLight_Brightness_Level;
		   break;

	   case BatteryLevelIsMedium:
		   BrightnessLevel = LowerBattery_BackLight_Brightness_Level;
		   break;
	   
	   case LowBatteryLevel_And_ChargerNoDetect:
		   /* If battery level is not more than low threshold and charger not dectect, return to boot33 */
		   CP_LOGI("battery level is less than low threshold and charger not detect, return to boot33\r\n");
		   break;

	  case GetBatteryLevelFail:
			CP_LOGW("get battery level fail\r\n");
	  		break;
	  
	  case Calbration_flag_Not_Set:
	   		CP_LOGW("PM803 Calbration flag not set\r\n");
			break;
	  
  	  case Dsp_adc_NotExist:
   			CP_LOGW("dsp_adc.bin not exist in ptable\r\n");
			break;
	   
	   default:
		   CP_LOGE("[Logo] BatteryRes: %d is error\r\n",BatteryRes);
		   while(1);
	}
	
	//检查是否需要显示logo,电池电压低或者是热重启,看门狗重启均不进行logo的显示
	ret_val = IsDisplayLogo(BatteryRes);
	if(ret_val == FALSE)
	{
	   CP_LOGW("Not display logo\r\n");
	   return;
	}

	//enable vibrator feedback.
#ifdef 	ADD_VIBRATOR_IN_CODE
	if( PMIC_IS_PM813() )
	{
		NingboVibratorEnable();
		CP_LOGI("VIBRATOR ENABLE\r\n");
	}
#endif

#ifdef QUEC_LCD_USR_FOR_LOGO
	CP_LOGD("LCD INIT\r\n");
	#ifdef QUEC_LCD_SHOWIMAGE_TEST
	POWER_ON_LCD_ShowImage();		//	LOGO侧演示示例
	#endif
#endif

	//If need,disable vibrator feedback
#ifdef 	ADD_VIBRATOR_IN_CODE
	if( PMIC_IS_PM813() )
	{
		NingboVibratorDisable();
		CP_LOGI("VIBRATOR DISABLE\r\n");
	}
#endif
}


static CompressedType_e GetCompressedType(UINT32 magic)
{
	CompressedType_e type;
	
	switch(magic)
	{
		case LZOP_COMPRESSED_MAGIC:
			CP_LOGD("lzop cpmpressed image\r\n");
			type = LZOP;
			break;		
		case LZMA_COMPRESSED_MAGIC:
		case LZMA_COMPRESSED_MAGIC1:
		case LZMA_COMPRESSED_MAGIC2:
		case LZMA_COMPRESSED_MAGIC3:
			CP_LOGD("lzma cpmpressed image\r\n");
			type = LZMA;
			break;
		default:
			CP_LOGW("not a compressed image\r\n");
			type = NO_COMPRESSED;
			break;		
	}

	return type;
}
#ifdef LTEONLY_SINGLE_SIM
#define RFBIN_MAGIC 0x52467266
#define PSRAM_BASE_ADDRESS  0x7E000000
#define DSP_REDUCE_SULOG_SIZE		0x00052000
#define DSP_REDUCE_SULOG_IRBUF_SIZE	0x00049000

void region_decompress_from_flash_to_psram(void){
    char region_compress_mark[8];
    unsigned schedule_count = 0;
    rw_region_item region_info;
	unsigned decompress_result,outLen,inLen;
	char * rw_cpz_struct_addr=(char*)get_rw_cpz_struct_addr();

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




int copy_dsp_from_flash_to_psram(void)
{
	unsigned long magic;
    int ret = -1;
    int outLen = -1;
	unsigned int inLen=0;
	UINT32 checksum = 0;
	_ptentry *dspEntry;
	CompressedType_e CompressedType;

	dspEntry = ptable_find_entry("dsp");
	DspFlashAddress = dspEntry->vstart;
	DspImageSize = dspEntry->vsize;
	inLen = DspImageSize;
	
	DspExecAddress = get_dsp_backup_addr();
	DspLoadSize = get_dsp_backup_size();

	CP_LOGD("logo LOGO_IMG_END_ADDR[%08x]!\r\n",LOGO_IMG_END_ADDR);
	if((LOGO_IMG_END_ADDR - PSRAM_CONFIG_CACHE_START_ADDR)>DspLoadSize)
	{
		CP_LOGE("LOGO image too larger!!![%08x]:[%08x]\r\n",(LOGO_IMG_END_ADDR-PSRAM_CONFIG_CACHE_START_ADDR),DspLoadSize);
		return ret;
	}


    //uart_printf("[DSP] decompress from [0x%.08x] to [0x%0.8x] DspRfMoveSize[%08x]\r\n", FLASH_DSP_START ,PSRAM_DSP_START,DspRfMoveSize);
    //uart_printf("[DSP] expected released dsp size [0x%.08x], inLen[0x%.08x]\r\n", DSP_COPY_SIZE,*inLen);

	magic = *(volatile unsigned long*)DspFlashAddress;
	CompressedType = GetCompressedType(magic);
	if(CompressedType==LZMA)
	{
	    CP_LOGD("LZMA compressed DSP image.\r\n");

		if(!LzmaUncompress((unsigned char *)DspExecAddress,(size_t *)&outLen, (const unsigned char *)DspFlashAddress, (size_t *)&inLen))
		{
			checksum=CalcImageChecksum((UINT32 *)DspExecAddress,  outLen, 0);
			CP_LOGD("[DSP] released dsp size [0x%.08x] inLen[0x%.08x] checksum[%.08x]\r\n", outLen,inLen,checksum);

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

	CP_LOGD("[RF ] copy from [0x%0.8x] to [0x%0.8x] size[0x%0.8x],backup[0x%0.8x]\r\n",
			rfFlashAddress,
			rfLoadAddress,
			rfCopySize,
			rfbackupAddress);
	magic = *(volatile unsigned long*)rfFlashAddress;
	CompressedType = GetCompressedType(magic);
	if (LZMA == CompressedType)
	{
		//offset =	rfLoadAddress - PSRAM_BASE_ADDRESS;  
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

	enable_psram_cache();
	
		
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
#else
void DecompressRegion(rw_region_item *p_region_info)
{
	UINT32 CompressedMagic;
	CompressedType_e CompressedType;
	unsigned decompress_result,outLen,inLen;
	UINT32 UncompressSrcAddr;
	
#ifdef DEBUG_LZMA	
	UINT32 t_start,t_end;
#endif
	// dump region info ( debug use )
//	Dump_RW_REGION_ITEM( p_region_info );

	UncompressSrcAddr = p_region_info->RW_REGION_COMPRESSED_ADDR;

	
	/* get compressed magic */
	CompressedMagic = *(UINT32 *)UncompressSrcAddr;
	CompressedType = GetCompressedType(CompressedMagic);
	if(LZMA == CompressedType){
		
		//Prepare for lzma
		//if(g_LzmaOptimizeFlag == FALSE)
		//	LzmaOptimizeSwitch(TRUE);
#ifdef DEBUG_LZMA	
		t_start = GetTimer0CNT();
#endif
		decompress_result = LzmaUncompress((unsigned char *)p_region_info->RW_REGION_EXEC_ADDR,(size_t *)&outLen, 
			(const unsigned char *)UncompressSrcAddr, (size_t *)&p_region_info->RW_REGION_LENGTH);
			
	    CP_LOGD("[CP_RW] decompress from [0x%.08x] to [0x%.08x] outlen[%08x]\r\n",UncompressSrcAddr,(unsigned char *)p_region_info->RW_REGION_EXEC_ADDR,outLen);
	    
#ifdef DEBUG_LZMA	
		t_end = GetTimer0CNT();
		CP_LOGD("[CP_RW][Decopress][%8s] t_start:%ld, t_end:%ld, delta:%ld\r\n",p_region_info->RW_REGION_NAME,t_start,t_end,t_end - t_start);
#endif
	}else if(LZOP == CompressedType){
		decompress_result = lzop_decompress_safe((unsigned char*)p_region_info->RW_REGION_COMPRESSED_ADDR,
		(unsigned char*)p_region_info->RW_REGION_EXEC_ADDR,
		&outLen,&inLen);
	}else{
		memcpy((unsigned char*)p_region_info->RW_REGION_EXEC_ADDR,(unsigned char*)p_region_info->RW_REGION_COMPRESSED_ADDR, p_region_info->RW_REGION_LENGTH);
		decompress_result = 0;
	}
	
	if(decompress_result != 0){
		CP_LOGE("\r\n ** ERROR: RW DECOMPRESS ERROR RESULT=[%d]",decompress_result);
		while(1);
	}
}


void region_decompress_from_flash_to_psram(void)
{
    char region_compress_mark[8];
    unsigned schedule_count = 0;
    rw_region_item region_info;
    char * rw_cpz_struct_addr=(char *)get_rw_cpz_struct_addr();

    //load compressed region struct
    memcpy( region_compress_mark,
            rw_cpz_struct_addr,
            sizeof(region_compress_mark));

    if(!strncmp(region_compress_mark, RW_REGION_MARK_PRE_STRING ,strlen(RW_REGION_MARK_PRE_STRING)-1)){
        CP_LOGD("Region CPZ struct detected from LDT\r\n");
        while(1){
            //read NEXT region cpz info struct
            memcpy(&region_info
                    ,(void*)(rw_cpz_struct_addr + (sizeof(rw_region_item)*schedule_count++))
                    ,sizeof(rw_region_item));

            if(strncmp(region_info.RW_REGION_MARK, RW_REGION_MARK_PRE_STRING ,strlen(RW_REGION_MARK_PRE_STRING)-1))
            { 
                //expend endpoint of RW decompress working flow for compressed image
                CP_LOGD("stop decompress as no further %s detected\r\n",RW_REGION_MARK_PRE_STRING);
                break;
            }
			if(region_info.RW_REGION_COMPRESSED_ADDR == RW_REGION_COMPRESSED_ADDR_NONE ){
                //expend endpoint of RW decompress working flow for uncompressed image
                //
                //no RW_REGION_COMPRESSED_ADDR detected,
                //image did not compressed with /x/tavor/Arbel/build/external_region_compress.pl script
                //the decompress would be done by /hop/BSP/src/Cinit1.c
                CP_LOGD("skip region decompress as no RW_REGION_COMPRESSED_ADDR detected\r\n");
                break;
            }
			if(!strncmp(region_info.RW_REGION_NAME,"NON_OTA",7)){
				if(asr_property_get("mini.sys.enable")!=0){
					CP_LOGD("[CP ] mini system [%8s] no need decompress\r\n",region_info.RW_REGION_NAME);
					continue;
				}
			}
			
			DecompressRegion(&region_info);
        }
    }
    else
    {
        CP_LOGE("Region CPZ struct not detected from LDT\r\n");
    }
}

int copy_cp_from_flash_to_psram(void)
{
    //COPY CP.bin
    unsigned int tmp;
    CP_LOGD("[CP ] start copy CP bin from [0x%0.8x] to [0x%0.8x] ,size=[0x%0.8x]\r\n",
            FLASH_CP_START,
            CpExecAddress,
            CpCopySize);

    memcpy( (void *)CpExecAddress,
            (void *)FLASH_CP_START,
            CpCopySize);

    tmp = memcmp((void*)CpExecAddress,
                 (void*)FLASH_CP_START,
                 CpCopySize);

    CP_LOGD("[CP ] after memcopy , do memcmp result= %s\r\n",(tmp==0)?"SUCCEED":"FAILED");
    return tmp;
}



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


typedef struct {
    uint32_t  address;
    uint32_t  len;
	uint32_t  reserved[6];
} dsp_backup_info;



int copy_dsp_from_flash_to_psram(unsigned int * inLen)
{
	unsigned long magic;
    //COPY DSP.bin
    int ret = -1;
	CompressedType_e CompressedType;
    int outLen = -1;
	dsp_backup_info dspbk={0};

	magic = *(volatile unsigned long*)FLASH_DSP_START;

	CompressedType = GetCompressedType(magic);

	if (LZMA == CompressedType) //"a lzop image"
	{
	    CP_LOGD("LZMA compressed DSP image.\r\n");

        if((DspLoadSize < (LOGO_IMG_END_ADDR-PSRAM_CONFIG_CACHE_START_ADDR)) && (CHIP_IS_CRANEL || CHIP_IS_CRANELS || CHIP_IS_CRANELR)){

            CP_LOGD("[LzmaUncompress] src: [0x%.08x], srclen: [0x%.08x],dst: [0x%.08x], dstlen: [0x%.08x]",
                FLASH_DSP_START,*inLen, DspBackupAddress ,outLen);
            if(!LzmaUncompress((unsigned char *)DspBackupAddress,(size_t *)&outLen, (const unsigned char *)FLASH_DSP_START, (size_t *)inLen))
            {
                CP_LOGD("[DSP] released dsp outLen [0x%.08x] inLen[0x%.08x] DSPBACKUP_SIZE[%08x]\r\n", outLen,*inLen,DSPBACKUP_SIZE);
            
                if(outLen != DSP_LOAD_SIZE){
                    CP_LOGD("[DSP] WARNING: decompressed length [0x%.08x] unmatch with expected [0x%.08x].\r\n",outLen,DSP_LOAD_SIZE);
                }
            
                ret = 0;
            }else{
                CP_LOGE("\r\n ** ERROR: DSP image decompress failed .\r\n");
                while(1);
            }

        }else{
        	CP_LOGD("[LzmaUncompress] src: [0x%.08x], srclen: [0x%.08x],dst: [0x%.08x], dstlen: [0x%.08x]",
			    FLASH_DSP_START,*inLen,(unsigned char *)PSRAM_DSP_START+DSP_LOAD_SIZE,outLen);
            if(!LzmaUncompress((unsigned char *)PSRAM_DSP_START+DSP_LOAD_SIZE,(size_t *)&outLen, (const unsigned char *)FLASH_DSP_START, (size_t *)inLen))
            {
                CP_LOGD("[DSP] released dsp outLen [0x%.08x] inLen[0x%.08x]\r\n", outLen,*inLen);
            
                
                if(outLen > DSPBACKUP_SIZE){
                    memcpy((unsigned char *)PSRAM_DSP_START+DSPBACKUP_SIZE,(unsigned char *)PSRAM_DSP_START+DSP_LOAD_SIZE+DSPBACKUP_SIZE,DSP_LOAD_SIZE-DSPBACKUP_SIZE);
                    CP_LOGD("[DSP] copy dsp to address[0x%.08x] len[0x%.08x]\r\n", (unsigned char *)PSRAM_DSP_START+DSPBACKUP_SIZE,DSP_LOAD_SIZE-DSPBACKUP_SIZE);
                }else if(CHIP_IS_CRANEL || CHIP_IS_CRANELS || CHIP_IS_CRANELR){
                    DspRamSize = outLen;//this is 1606S 8M psram and all in dsp image
                }
            
                memcpy((unsigned char *)DspBackupAddress,(unsigned char *)PSRAM_DSP_START+DSP_LOAD_SIZE,DSPBACKUP_SIZE);
                CP_LOGD("[DSP] backup dsp size[%08x] to address[0x%.08x]\r\n",DSPBACKUP_SIZE, (unsigned char *)DspBackupAddress);
            
                if(outLen != DSP_LOAD_SIZE){
                    CP_LOGD("[DSP] WARNING: decompressed length [0x%.08x] unmatch with expected [0x%.08x].\r\n",outLen,DSP_LOAD_SIZE);
                }
            
                //dspbk.address = DspBackupAddress;
                //dspbk.len = DSPBACKUP_SIZE;
                //asr_property_set_param("dsp.backup.info",(const char *)&dspbk,sizeof(dsp_backup_info));
                ret = 0;
            }else{
                CP_LOGE("\r\n ** ERROR: DSP image decompress failed .\r\n");
                while(1);
            }

        }
			

		cpy_dsp_by_cp=0;
	}else{
		cpy_dsp_by_cp=1;
		ret = 0;	
    }
    return ret;
}

#ifdef UNCOMPRESS_DEBUG
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
#endif

#define QUEC_MULTI_PA_SUPPORT
#ifdef QUEC_MULTI_PA_SUPPORT

#define QUEC_RESERVED     1024      //1K
#define QUEC_RF_NUM_MAX     3
#define QUEC_MULTI_PA1  (0x803055AA)
#define QUEC_MULTI_PA2  (0x0830AABB)
#define QUEC_RFBIN_SIZE_NORMAL    4096
#pragma pack (1)

typedef  struct
{
 const unsigned int multi_flag1;
 const unsigned int multi_flag2;
 unsigned char rf_num;
 long rf_size[QUEC_RF_NUM_MAX];
 unsigned char reserved[QUEC_RESERVED];

}rf_head_struct_s;

#pragma pack ()

rf_head_struct_s  rf_head ={0};

typedef enum
{
     RF_INDEX_1 =0,
     RF_INDEX_2,
}QUEC_RF_INDEX_E;


typedef struct
{
    unsigned int gpio_num;
    unsigned int gpio_1;
    unsigned int gpio_2;
      
}QUEC_PA_GPIO_PARAM_S;

#define QUEC_EC800M_PA_GPIO1_PIN  GPIO_PIN_NO_37

unsigned long  PA_gpio1_mfpr=  0x148040 ;

#define QUEC_PA_OC_MAX_LEN 6

QUEC_PA_GPIO_PARAM_S    quec_EC800M_PA ={1,QUEC_EC800M_PA_GPIO1_PIN};

QUEC_RF_INDEX_E quec_pa_identify_gpio_init(rf_head_struct_s *prf_head)
{
     PIN_LEVEL_E gpio1_level=0;
     QUEC_RF_INDEX_E ret = RF_INDEX_1;
     if(NULL == prf_head && strlen((prf_head->reserved+prf_head->reserved[0]+1))==QUEC_PA_OC_MAX_LEN)
     {
          uart_printf("[RF ] rf_head invalid\r\n");   
          return ret;
     }

	 if((prf_head->reserved[0]==quec_EC800M_PA.gpio_num)&&
	      (prf_head->reserved[1]==quec_EC800M_PA.gpio_1)&&
	      (strstr((prf_head->reserved+prf_head->reserved[0]+1),"EC800M")!= NULL))
	 {  
	 	  ql_gpio_init(QUEC_EC800M_PA_GPIO1_PIN, PIN_DIRECTION_IN, PIN_PULL_PD, PIN_LEVEL_LOW);
	      *(volatile unsigned long *)(GPIO_MFPR_ADDR(QUEC_EC800M_PA_GPIO1_PIN)) = PA_gpio1_mfpr;
	      ql_gpio_get_level(QUEC_EC800M_PA_GPIO1_PIN, &gpio1_level);
	      uart_printf("[RF ] 800M pin1=%d\r\n",gpio1_level);
	     if(PIN_LEVEL_HIGH == gpio1_level)
	     {
	          return RF_INDEX_2;
	     }
	 }
	 else 
	 {
	     uart_printf("[RF ] one PA\r\n");
	 }
     return RF_INDEX_1;
}

/*
ret =0 , invalid
ret =1 , find multi pa
*/
unsigned int quec_get_rf_info(unsigned int rfFlashAddress,unsigned int rfCopySize,unsigned int *prfFlashAddress,unsigned int *prfCopySize)
{
    unsigned ret =0;
    rf_head_struct_s rf_head={0};
    
    if((NULL == prfFlashAddress)||(NULL ==prfCopySize))
    {
        uart_printf("[RF] addr is null\r\n");
        return 0;  
    }
    if(rfCopySize <= QUEC_RFBIN_SIZE_NORMAL)  
    {
       uart_printf("[RF] normal,size=%d\r\n",rfCopySize);
       return 0;    
    }
    //find whether multi PA
	memcpy((void *)&rf_head,(void *)(rfFlashAddress+rfCopySize-sizeof(rf_head)),sizeof(rf_head));
    if((QUEC_MULTI_PA1 != rf_head.multi_flag1)||(QUEC_MULTI_PA2 != rf_head.multi_flag2))
    {
        uart_printf("[RF],num=%d,pa1=0x%x,pa2=0x%x invalid\r\n",rf_head.rf_num,rf_head.multi_flag1,rf_head.multi_flag2);
        return 0;       
    }
    

    if(rf_head.rf_num > QUEC_RF_NUM_MAX)
    {
        uart_printf("[RF] nornal,rf_num=%d\r\n",rf_head.rf_num);
        return 0;       
    }
     uart_printf("[RF] rf_head=%d,%d\r\n",rf_head.reserved[0],rf_head.reserved[1]);

    if(RF_INDEX_2 == quec_pa_identify_gpio_init(&rf_head))
	{
		*prfFlashAddress = rfFlashAddress + rf_head.rf_size[0];
		*prfCopySize = rf_head.rf_size[1];
		 uart_printf("[RF] num=%d,copy rf2_addr:0x%08x\r\n", rf_head.rf_num,*prfFlashAddress);
	}
	else
	{
        *prfFlashAddress = rfFlashAddress;
        *prfCopySize = rf_head.rf_size[0];
		uart_printf("[RF],num=%d,copy rf_addr:0x%08x\r\n",rf_head.rf_num,*prfFlashAddress);
	}
        
    return rf_head.rf_num;

}

#endif

int copy_rf_from_flash_to_psram(unsigned int rfFlashAddress,unsigned int rfCopySize,unsigned int rfLoadAddress)
{
	
	//COPY rf.bin
	unsigned long magic;
	CompressedType_e CompressedType;
	unsigned uncompress_size=0;
	char *uncompress_buf=NULL;
	int outLen = -1;
	int dsp_non_bk_addr = -1;

	unsigned int checksum = 0;

	if(rfLoadAddress == INVALID_ADDRESS)
	{
		CP_LOGE("[RF ] rfLoadAddress = INVALID_ADDRESS\r\n");
		while(1);
	}

	
#ifdef QUEC_MULTI_PA_SUPPORT
		unsigned int rfFlashAddress_calc =0,rfCopySize_calc=0;

		if(0 != quec_get_rf_info(rfFlashAddress,rfCopySize,&rfFlashAddress_calc,&rfCopySize_calc))
		{
			rfFlashAddress = rfFlashAddress_calc ;
			rfCopySize = rfCopySize_calc;
		}
	
#endif

	CP_LOGW("[RF ] copy from [0x%0.8x] to [0x%0.8x] size[0x%0.8x]\r\n",
			rfFlashAddress,
			rfLoadAddress,
			rfCopySize);
	
	magic = *(volatile unsigned long*)rfFlashAddress;

	CompressedType = GetCompressedType(magic);
	if (LZMA == CompressedType){
		uncompress_size=get_LzmaUncompress_dst_size((const unsigned char *)rfFlashAddress);
		uncompress_buf = (char *)malloc(uncompress_size);
		if(uncompress_buf==NULL){
			CP_LOGE("\r\n ** ERROR: copy RF image failed ,malloc failed[%08x]\r\n",uncompress_size);
			while(1);

		}
		
		if(!LzmaUncompress((unsigned char *)uncompress_buf,(size_t *)&outLen, (const unsigned char *)rfFlashAddress, (size_t *)&rfCopySize))
		{
			CP_LOGD("[RF] Uncompress rf outLen [0x%.08x] inLen[0x%.08x]\r\n", outLen,rfCopySize);
			if(uncompress_size!=outLen){
				CP_LOGD("[RF] WARNING: decompressed length [0x%.08x] unmatch with expected [0x%.08x].\r\n",outLen,uncompress_size);
			}
            CP_LOGD("[RF] DspBackupAddress [0x%.08x]\r\n", DspBackupAddress);
            if((DspLoadSize < (LOGO_IMG_END_ADDR-PSRAM_CONFIG_CACHE_START_ADDR)) && (CHIP_IS_CRANEL || CHIP_IS_CRANELS || CHIP_IS_CRANELR)){
                if((outLen>CRANEL_SINGLE_RF_SIZE) && CHIP_IS_CRANEL){
                    rfLoadAddress = CRANEL_MULTI_RF_ADDRESS;
                }
                
    			memcpy(DspBackupAddress+(rfLoadAddress-PSRAM_DSP_START),uncompress_buf,outLen);
    			CP_LOGD("[RF] copy rf to [0x%.08x] outLen[0x%.08x]\r\n",DspBackupAddress+(rfLoadAddress-PSRAM_DSP_START), outLen);

            }else if((CHIP_IS_CRANEL || CHIP_IS_CRANELS || CHIP_IS_CRANELR) && DspRamSize!=0){//this is 1606S 8M psram and all in dsp image
                memcpy(DspBackupAddress+(CRANEL_4MRAM_RF_ADDRESS - PSRAM_DSP_START),uncompress_buf,outLen);
                CP_LOGD("[RF] copy rf to [0x%.08x] outLen[0x%.08x]\r\n",DspBackupAddress+(CRANEL_4MRAM_RF_ADDRESS-PSRAM_DSP_START), outLen);

            }
            else{
                dsp_non_bk_addr = (PSRAM_DSP_START + DSPBACKUP_SIZE);
                if(rfLoadAddress>=dsp_non_bk_addr){
                    memcpy(rfLoadAddress,uncompress_buf,outLen);
                }else{
                    if((rfLoadAddress + outLen)>dsp_non_bk_addr){
                        memcpy(dsp_non_bk_addr,uncompress_buf + (dsp_non_bk_addr - rfLoadAddress),(rfLoadAddress + outLen) - dsp_non_bk_addr);
                        memcpy(DspBackupAddress+(rfLoadAddress-PSRAM_DSP_START),uncompress_buf,(dsp_non_bk_addr - rfLoadAddress));
                        
                    }else{
                        memcpy(DspBackupAddress+(rfLoadAddress-PSRAM_DSP_START),uncompress_buf,outLen);
                    }
                }

            }


			free(uncompress_buf);
			#ifdef UNCOMPRESS_DEBUG
			checksum=CalcImageChecksum(DspBackupAddress,DSPBACKUP_SIZE,0);
			checksum=CalcImageChecksum(dsp_non_bk_addr,DSP_LOAD_SIZE-DSPBACKUP_SIZE,checksum);
			CP_LOGD("[RF ]copy rf SUCCEED,checksum[%08x]\r\n",checksum);
			#else
			CP_LOGD("[RF ]copy rf SUCCEED\r\n");
			#endif
			
			
			
			return 0;
		}else{
			CP_LOGE("\r\n ** ERROR: RF image decompress failed .\r\n");
			while(1);
		}

	}
#ifdef	CRANEL_CHIP
	else{
		CP_LOGE("\r\n ** ERROR: RF image decompress failed .\r\n");
		while(1);
	}
#endif
	
	if(cpy_dsp_by_cp){
		CP_LOGD("[RF ] copy rf by CP\r\n");
		return 0;
	}

	{
        if((DspLoadSize < (LOGO_IMG_END_ADDR-PSRAM_CONFIG_CACHE_START_ADDR)) && (CHIP_IS_CRANEL || CHIP_IS_CRANELS || CHIP_IS_CRANELR)){
			memcpy(DspBackupAddress+(rfLoadAddress-PSRAM_DSP_START),rfFlashAddress,rfCopySize);
			CP_LOGD("[RF] copy rf to [0x%.08x] rfCopySize[0x%.08x]\r\n",DspBackupAddress+(rfLoadAddress-PSRAM_DSP_START), rfCopySize);

        }else if((CHIP_IS_CRANEL || CHIP_IS_CRANELS || CHIP_IS_CRANELR) && DspRamSize != 0){//this is 1606S 8M psram and all in dsp image
                memcpy(DspBackupAddress+(CRANEL_4MRAM_RF_ADDRESS - PSRAM_DSP_START),uncompress_buf,outLen);
                CP_LOGD("[RF] copy rf to [0x%.08x] outLen[0x%.08x]\r\n",DspBackupAddress+(CRANEL_4MRAM_RF_ADDRESS-PSRAM_DSP_START), outLen);

        }else{
            dsp_non_bk_addr = (PSRAM_DSP_START + DSPBACKUP_SIZE);
            if(rfLoadAddress>=dsp_non_bk_addr){
                memcpy(rfLoadAddress,rfFlashAddress,rfCopySize);
            }else{
                if((rfLoadAddress + rfCopySize)>dsp_non_bk_addr){
                    memcpy(dsp_non_bk_addr,rfFlashAddress + (dsp_non_bk_addr - rfLoadAddress),(rfLoadAddress + rfCopySize) - dsp_non_bk_addr);
                    memcpy(DspBackupAddress+(rfLoadAddress-PSRAM_DSP_START),rfFlashAddress,(dsp_non_bk_addr - rfLoadAddress));
                    
                }else{
                    memcpy(DspBackupAddress+(rfLoadAddress-PSRAM_DSP_START),rfFlashAddress,rfCopySize);
                }
            }

        }


		#ifdef UNCOMPRESS_DEBUG
		checksum=CalcImageChecksum(DspBackupAddress,DSPBACKUP_SIZE,0);
		checksum=CalcImageChecksum(dsp_non_bk_addr,DSP_LOAD_SIZE-DSPBACKUP_SIZE,checksum);
		CP_LOGD("[RF ]copy rf SUCCEED,checksum[%08x]\r\n",checksum);
		#else
		CP_LOGD("[RF ]copy rf SUCCEED\r\n");
		#endif

		/*
		memcpy( (void *)rfLoadAddress,
				(void *)rfFlashAddress,
				rfCopySize);
		tmp = memcmp((void*)rfLoadAddress,
					 (void*)rfFlashAddress,
					 rfCopySize);

		uart_printf("[RF ]memcmp result %s\r\n",(tmp==0)?"SUCCEED":"FAILED");
		*/
	}

	
	return 0;
}



void PrepareToExecuteCp(void)
{
	CP_LOGD("Decompress dsp and rw data start!\r\n");
	unsigned int val;
	_ptentry *cpEntry, *dspEntry,*rfEntry;

	
#ifdef DEBUG_LZMA	
	Timer0_enable(TRUE);
#endif

	/* [NOTE] move these init code into logo as pm803 use */
	/* printf the Chip ID */
	CP_LOGD("chip id: 0x%.08x\r\n",GetLongChipID());
#ifndef LTEONLY_SINGLE_SIM
	CpCoreFreqChangeTo624();
	if(ifPsramLimit200M()){
        PsramPhyFreqChangeTo350();
	}else{
        PsramPhyFreqChangeTo416();
	}
#endif
	enable_psram_cache();

	dspEntry = ptable_find_entry("dsp");
	rfEntry = ptable_find_entry("rfbin");
	DspFlashAddress = dspEntry->vstart;
	DspImageSize = dspEntry->vsize;
	
	DspExecAddress = get_dsp_load_addr();
	DspLoadSize = get_dsp_copy_size();
	
	
		
	if(copy_dsp_from_flash_to_psram((unsigned int *)&DspImageSize)){
		goto FAIL;
	}

	rfLoadAddress = get_rf_load_addr();
	rfFlashAddress = rfEntry->vstart;
	rfCopySize = rfEntry->vsize;

	if(copy_rf_from_flash_to_psram(rfFlashAddress,rfCopySize,rfLoadAddress)){
		goto FAIL;
	}

    CpExecAddress = get_cp_exec_addr(); //CP Exec Addr
    CpCopySize = get_cp_copy_size();

    //DEALING WITH CP.bin
    if (get_cp_execute_mode() == XIP){
        //execute mode = XIP && RW_COMPRESSED detected
        region_decompress_from_flash_to_psram();
    }
#ifndef LTEONLY_SINGLE_SIM	
	else
    {
        //execute mode = PSRAM
        if(copy_cp_from_flash_to_psram()){
            goto FAIL;
        }
    }
#endif

	disable_psram_cache();
#ifndef LTEONLY_SINGLE_SIM
	CpCoreFreqChangeTo416();
#endif

#ifdef DEBUG_LZMA	
	Timer0_enable(FALSE);
#endif	
	CP_LOGD("Decompress dsp and load rf data END!\r\n");
	return;
FAIL:
	CP_LOGE("PrepareToExecuteCp failed!\r\n");
	while(1);

}

#endif



static char heap_a[LOGO_HEAP_SIZE];

void init_heap(void)
{
	unsigned int val;
    unsigned long DspBackupEndAddress;
#ifndef LTEONLY_SINGLE_SIM
    DspLoadSize = get_dsp_copy_size();

	val=get_ddr_heap_size();
	
	DspBackupSize = get_dsp_backup_size();

	if(val==0 || DspBackupSize==0){
		CP_LOGE("loadtable not latest,heap size[%08x] dsp_bk size[%08x]!\r\n",val,DspBackupSize);
		goto FAIL;

	}


	if(DspBackupSize>val){
		CP_LOGE("dsp bk size too larger[%08x], heap size[%08x]!\r\n",DspBackupSize,val);
		goto FAIL;

	}

	CP_LOGD("logo LOGO_IMG_END_ADDR[%08x]!\r\n",LOGO_IMG_END_ADDR);

	DspBackupAddress = get_dsp_backup_addr();
	if(DspBackupAddress==0){
		CP_LOGE("loadtable not latest, DspBackupAddress error!!!\r\n");
		goto FAIL;

	}


	if((DspLoadSize < (LOGO_IMG_END_ADDR-PSRAM_CONFIG_CACHE_START_ADDR)) && (CHIP_IS_CRANEL || CHIP_IS_CRANELS || CHIP_IS_CRANELR)){
	    DspBackupEndAddress = get_dsp_backup_end_addr();
        if(DspBackupAddress>=DspBackupEndAddress){
            CP_LOGE("error!!!DspBackupAddress[%08x] DspBackupEndAddress[%08x]\r\n",DspBackupAddress,DspBackupEndAddress);
            goto FAIL;
        }
        if((DspBackupEndAddress-DspBackupAddress + 4 )<(DspBackupSize)){
            CP_LOGE("error!!!DspBackupAddress[%08x] DspBackupEndAddress[%08x] DspBackupSize[%08x]\r\n",DspBackupAddress,DspBackupEndAddress,DspBackupSize);
            goto FAIL;
        }
	}else{
        if((LOGO_IMG_END_ADDR-PSRAM_CONFIG_CACHE_START_ADDR)>DspBackupSize){
            CP_LOGE("logo image too larger!\r\n");
            goto FAIL;
        }
	}
	
#endif
	/* support malloc mechanism */
	malloc_init(heap_a, LOGO_HEAP_SIZE);
	CP_LOGD("init_heap done!\r\n");
	return;

FAIL:
	CP_LOGE("init_heap failed!\r\n");
	while(1);

}

extern unsigned int Load$$DATA$$RW$$Base;
extern unsigned int Image$$DATA$$RW$$Base;
extern unsigned int Image$$DATA$$RW$$Length;

void logo(void)
{
    unsigned int val;
    volatile UINT8 var;
	unsigned int i;
	UINT32 battery_level;
	
    //[1] uart init
	cp_uart_init();
    CP_LOGD("LOGO START\r\n");
	usticaInit();
	unsigned int dst_addr=(unsigned int)&Image$$DATA$$RW$$Base;
	unsigned int src_addr=(unsigned int)&Load$$DATA$$RW$$Base;
	unsigned int len=(unsigned int)&Image$$DATA$$RW$$Length;
	if((dst_addr < src_addr) && ((dst_addr+len) > src_addr)){
		CP_LOGE("[LOGO] RW data overlap,Image:0x%08x,Load:0x%08x,len:%d\r\n",dst_addr,src_addr,len);
		while(1);
	}
           

	/*[2] Print LOGO HEADER INFO */
	CP_LOGW("[LOGO] VERSION_DATE   :[%s]\r\n",(logo_vb.vb.logo_version_block.version_date));
	CP_LOGD("LCD_TYPE:[%s]\r\n",logo_vb.vb.logo_version_block.oem_lcd_type);
	CP_LOGD("ver:%s\r\n",logo_vb.vb.logo_version_block.build_info_string);
	CP_LOGD("LOGO_FLAG:%s\r\n",logo_vb.FeedbackBlock.feedback_block.LogoDisplayLogoFlag);

#ifndef LTEONLY_SINGLE_SIM
	asr_property_set("logo.version",logo_vb.vb.logo_version_block.build_info_string);
	asr_property_set("logo.lcd_type",logo_vb.vb.logo_version_block.oem_lcd_type);
	asr_property_set("logo.displayflag",logo_vb.FeedbackBlock.feedback_block.LogoDisplayLogoFlag);
#endif

	asr_property_dump();

	
    //[3] Enable MPU and using the cortex-r default memory map as the background region
    reset_all_mpu_reg();
	
    val = sctlr_get();
    val |= SCTLR_BR | SCTLR_M;
    sctlr_set(val);

	//[4] MPU config
    CP_LOGD("logo MPU config\r\n");
	set_mpu_reg_background(1);//FULL_ACCESS
	set_mpu_reg_itcm();
	set_mpu_reg_dtcm();
	set_mpu_reg_flash(0x01000000);//16M
	set_mpu_reg_asic_reg();
	set_mpu_reg_psram(0);
	set_mpu_reg_background(0);//NO_ACCESS

	mpu_value_check();
//    PMIC_Init();
//	sdcard_init();

#ifdef DEBUG_FLOAT_OPERATOR
	/* Note :can execute float operation but can not printf float type data with %f */
	CP_LOGD("test_float_data!\r\n");
	test_float_data();
	test_fitting_calculate();
#endif

#ifdef SUPPORT_MALLOC
   /* support malloc mechanism */
   malloc_init(g_MallocBuffer, MALLOC_BUFFER_SIZE);
   CP_LOGD("malloc init done!\r\n");
#endif

   /* [5] ptable init and dump */
   if(ptable_init()){
	   CP_LOGE("bad partition table!\r\n");
	   while(1);
   }
//  ptable_dump();

   /* 6] KEY PARTITION INFO FETCH */
   GetKeyPartitionInfoFetch();

   /* [7] flash and loadtable init */
   bbu_qspi_init();
   loadtable_init(CpFlashAddress);
   init_heap();
   logo_header_table_init();
   //dump_loadtable();


#ifdef MRD_DEBUG_CODE
	test_MRD_api();
#endif /* MRD_DEBUG_CODE */

#ifdef PM803_DEBUG_CODE

	if( PMIC_IS_PM803() ){
		LogoBattery_t BatteryRes;
		unsigned short adcvol;

		CP_LOGD("check battery level\r\n");
		CheckBatteryLevel( &BatteryRes );
		CP_LOGD("BatteryRes:%d\r\n",BatteryRes);

		CP_LOGD("check adc0 level\r\n");
		ql_adc_read(0, &adcvol);
		CP_LOGD("adc0Res:%d\r\n",adcvol);

		CP_LOGD("check adc1 level\r\n");
		ql_adc_read(1, &adcvol);
		CP_LOGD("adc1Res:%d\r\n",adcvol);
	}
#endif

#ifdef DMCHAGE
    DM_CHARGE_Manager();
#endif

	

#ifdef QUEC_LCD_USR_FOR_LOGO
	Vibrator_And_LogoFeedback();
	//spi 回环测试
	//quec_spi_test();
#else
#if 0//不再使用ASR的代码
	/* check LOGO FLAG in logo.bin */
	if(0 == strncmp(logo_vb.FeedbackBlock.feedback_block.LogoDisplayLogoFlag,ENABLE_LOGO_DISPLAY_FLAG,sizeof(ENABLE_LOGO_DISPLAY_FLAG))){
		/* [8] Display logo and enable vibrator */
		Vibrator_And_LogoFeedback();
	}else{
		CP_LOGD("Read \"LOGO_FLAG\" from image is %s, not display logo\r\n",logo_vb.FeedbackBlock.feedback_block.LogoDisplayLogoFlag);
	}
#endif
#endif

#ifdef QUEC_LOGO_GET_POWERUP_REASON
	int reason,wake_reason;
	reason = ql_get_powerup_reason();
	uart_printf("=====logo powerup reason:%d====\r\n",reason);

	wake_reason = SysRestartReasonGet();
	uart_printf("==wake reason:%d, %c==\n", wake_reason,wake_reason);
#endif

	/* [9] do some prepare work before executing cp.bin (e.g. decompress dsp, load rf. decompress cp_rw if necessary) */
	PrepareToExecuteCp();

	/* [10] return to boot33 */
	//if(g_LzmaOptimizeFlag == TRUE){
	//	LzmaOptimizeSwitch(FALSE);
	//}

	CP_LOGD("LOGO END\r\n");

	return;							
	//while(1);
}

