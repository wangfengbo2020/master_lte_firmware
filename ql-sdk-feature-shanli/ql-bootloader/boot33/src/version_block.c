#include "version_block.h"

//for basic boot33 build version
#define VB_VERSION_DATE        "20231018"

//for LCD TYPE INFO
#ifdef LCD_ST7789
#define VB_OEM_LCD_TYPE        "LCD_ST7789"
#else
#define VB_OEM_LCD_TYPE        "NO_LCD"
#endif

#ifdef BOOT33_SECBOOT_SUPPORT
#ifdef BOOT33_SECBOOT_V1
#define VB_SECBOOT_SUPPORT     "SECBOOT_V1"
#else
#define VB_SECBOOT_SUPPORT     "SECBOOT_V2"
#endif
#else
#define VB_SECBOOT_SUPPORT     "NON-SECBOOT"
#endif


#ifdef SUPPORT_COMPRESSED_LOGO
#define VB_COMPRESSED_LOGO_SUPPORT     "SUPPORT_COMPRESSED_LOGO"
#else
#define VB_COMPRESSED_LOGO_SUPPORT     "NOT_SUPPORT_COMPRESSED_LOGO"
#endif


#pragma arm section rodata="IMGVERBLOCK"
const Boot33VerBlockType boot33_vb =
{
	//+++++++++++++++++++++++++++++
	//AREA_1: VERSION_INFO
	{
		VB_VERSION_DATE,
		VB_OEM_LCD_TYPE,
		VB_SECBOOT_SUPPORT,
		VB_COMPRESSED_LOGO_SUPPORT,
		"boot33.bin 20231018_2_db"
	}
};
#pragma arm section code
