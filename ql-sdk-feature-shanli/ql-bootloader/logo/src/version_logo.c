#include "version_logo.h"
#include "logo_table.h"
#include "utilities.h"


extern UINT32 Load$$INIT$$Base;
extern void Reset_Handler(void);

/**
 * Note: The following MACRO can not MODIFY
 * 1. LOGO_VALID_MAGIC: 				  image magic
 * 2. LOGO_EXEC_ADDR:			  image Exec Addr
 * 3. LOGO_LOAD_EXEC_ADDR:    image Load Addr
 */

#define LOGO_EXEC_ADDR   		(UINT32)&Reset_Handler
#define LOGO_LOAD_EXEC_ADDR 	(UINT32)&Load$$INIT$$Base



//for basic logo build version
#define VB_VERSION_DATE        "20231018"

#define INFO_STRING			   VB_VERSION_DATE##"_db"

//for LCD TYPE INFO
//Note: The following will only choose one, Default is "NO_LCD"
#ifdef LCD_ST7789V_MCU
#define VB_OEM_LCD_TYPE        "LCD_ST7789V_MCU"
#endif

#ifdef LCD_ST7789V_SPI_3WIRE_1LANE_1IF
#define VB_OEM_LCD_TYPE        "LCD_ST7789V_SPI_3WIRE_1LANE_1IF"
#endif

#ifdef LCD_ST7789V_SPI_3WIRE_2LANE_1IF
#define VB_OEM_LCD_TYPE        "LCD_ST7789V_SPI_3WIRE_2LANE_1IF"
#endif

#ifdef LCD_ST7789V_SPI_4WIRE_1LANE_1IF
#define VB_OEM_LCD_TYPE        "LCD_ST7789V_SPI_4WIRE_1LANE_1IF"
#endif

#ifdef LCD_ST7789V_SPI_4WIRE_1LANE_2IF
#define VB_OEM_LCD_TYPE        "LCD_ST7789V_SPI_4WIRE_1LANE_2IF"
#endif

#ifdef LCD_GC9305_MCU
#define VB_OEM_LCD_TYPE        "LCD_GC9305_MCU"
#endif

#ifdef LCD_GC9305_SPI_3WIRE_1LANE_1IF
#define VB_OEM_LCD_TYPE        "LCD_GC9305_SPI_3WIRE_1LANE_1IF"
#endif

#ifdef LCD_GC9305_SPI_3WIRE_2LANE_1IF
#define VB_OEM_LCD_TYPE        "LCD_GC9305_SPI_3WIRE_2LANE_1IF"
#endif

#ifdef LCD_GC9305_SPI_4WIRE_1LANE_1IF
#define VB_OEM_LCD_TYPE        "LCD_GC9305_SPI_4WIRE_1LANE_1IF"
#endif

#ifdef LCD_GC9306_SPI_3WIRE_1LANE_1IF
#define VB_OEM_LCD_TYPE        "LCD_GC9306_SPI_3WIRE_1LANE_1IF"
#endif

#ifdef LCD_GC9306_SPI_3WIRE_2LANE_1IF
#define VB_OEM_LCD_TYPE        "LCD_GC9306_SPI_3WIRE_2LANE_1IF"
#endif

#ifdef LCD_GC9306_SPI_4WIRE_1LANE_1IF
#define VB_OEM_LCD_TYPE        "LCD_GC9306_SPI_4WIRE_1LANE_1IF"
#endif


#ifdef LCD_DUMMY_MCU
#define VB_OEM_LCD_TYPE        "LCD_DUMMY_MCU"
#endif

#ifdef LCD_DUMMY_SPI_3WIRE_2LANE_1IF
#define VB_OEM_LCD_TYPE        "LCD_DUMMY_SPI_3WIRE_2LANE_1IF"
#endif

#ifdef LCD_ST7735S_SPI_3WIRE_1LANE_1IF
#define VB_OEM_LCD_TYPE        "LCD_ST7735_SPI_3WIRE_1LANE_1IF"
#endif

#ifndef LCD_USE_IN_CODE			//default
#define VB_OEM_LCD_TYPE "NO_LCD"
#define LOGO_DISPLAY_FLAG  DISABLE_LOGO_DISPLAY_FLAG
#else
#define LOGO_DISPLAY_FLAG  ENABLE_LOGO_DISPLAY_FLAG
#endif

#define VB_ADD_MORE_FUNCTION_SUPORT "SUPPORT_ADD_MORE_FUNCTION"

#pragma arm section rodata="IMGLOGO"
const LogoHeaderTableStruct logo_vb =
{
	//+++++++++++++++++++++++++++++
	//AREA_1: LOGO_LOAD_BLOCK
	{
		LOGO_VALID_MAGIC,
		LOGO_EXEC_ADDR,
		LOGO_LOAD_EXEC_ADDR,
		LOGO_HEADER_TOTAL_SIZE
	},
	//+++++++++++++++++++++++++++++
	//AREA_2: LOGO_FEEDBACK_BLOCK
	{
		"LOGO_FLAG:",
		LOGO_DISPLAY_FLAG
	},
	//+++++++++++++++++++++++++++++
	//AREA_3: VERSION_INFO
	{
		VB_VERSION_DATE,
		VB_OEM_LCD_TYPE,
		VB_ADD_MORE_FUNCTION_SUPORT,
		INFO_STRING
	},
	//AREA_4: ext*.bin info
	{
		{
			{"LOGO_FUC_MG\0",(UINT32)LOGO_FUNCTION_MAGIC_2},        //place updater function magic
			{"EXT_SIZE\0",   (UINT32)(LOGO_INVALID_VALUE)},	    //write by external_ext_bin_size_update.pl
			{"LOGO_SIZE\0",  (UINT32)(LOGO_INVALID_VALUE)},       //write by external_ext_bin_size_update.pl
			{"ADC_EXEC\0",   (UINT32)(DSP_ADC_EXECUTE_ADDR)},
			{"ADC_SIZE\0",   (UINT32)(LOGO_INVALID_VALUE)},       //write by external_ext_bin_append.pl
		}
	},
};
#pragma arm section code

