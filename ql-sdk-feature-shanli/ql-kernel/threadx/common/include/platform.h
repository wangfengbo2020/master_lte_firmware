#ifndef PLATFORM_H
#define PLATFORM_H
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

                Platform.h


GENERAL DESCRIPTION

    This file is for platform configuration.

EXTERNALIZED FUNCTIONS

INITIALIZATION AND SEQUENCING REQUIREMENTS

   Copyright (c) 2011 by Marvell, Incorporated.  All Rights Reserved.
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

*===========================================================================

                        EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.


when         who        what, where, why
--------   ------     ----------------------------------------------------------
12/23/07   zhoujin    Created module
===========================================================================*/


/*===========================================================================

                     INCLUDE FILES FOR MODULE

===========================================================================*/

#include "UART.h"

/*===========================================================================

                                LOCAL MACRO
===========================================================================*/

#ifndef NULL
#define NULL    0x0L
#endif

#ifndef TRUE
#define TRUE    0x01
#endif

#ifndef FALSE
#define FALSE   0x00
#endif

/* Project type ID */
#define PROJECT_TYPE_ID                     0x4e5d30

/*
*
* DDR address to transfer Flag from (OBM to CP) or From (CP to next reset)
*
*/

/* Start address to save Flag */
#define DDR_FLAG_START_ADDR                 0x07D7F000

/* 4 byte for Daseul/PROD flag */
#define DDR_PROD_FLAG_ADDR                  0x07D7F000

/* 4 byte for usbmode flag */
#define DDR_USBMODE_FLAG_ADDR               0x07D7F004

/* 4 byte for ATCMD reset flag */
#define DDR_ATCMD_RST_FLAG_ADDR             0x07D7F008

/* 4 byte for Bootloader version flag */
#define DDR_BOOT_VERSION_FLAG_ADDR          0x07D7F00C

/* 4 byte for LTG/LWG version flag */
#define DDR_IMAGE_VERSION_FLAG_ADDR         0x07D7F010

/* 4 byte for MRD flash address */
#define DDR_MRD_FLASH_ADDR                  0x07D7F014

/* 4 byte for RSTSET flag */
#define DDR_RSTSET_FLAG_ADDR                0x07D7F018

/* 4 byte for reserve flag */
#define DDR_RESERVE_FLAG_ADDR               0x07D7F01C

/* 4 byte for upgrade reset flag */
#define DDR_UPGRADE_RST_FLAG_ADDR           0x07D7F020

/* 4 byte for RBLI flash address */
#define DDR_RBLI_FLASH_ADDR                 0x07D7F024

/* 4 byte for RBLR flash address */
#define DDR_RBLR_FLASH_ADDR                 0x07D7F028

/* 4 byte for SilentReset1 flag */
#define DDR_SRST1_ADDR                      0x07D7F02C

/* 4 byte for SilentReset2 flag */
#define DDR_SRST2_ADDR                      0x07D7F030

/* 4 byte for Watchdog reset flag */
#define DDR_WATCHDOG_RST_ADDR               0x07D7F034

/* 4 byte for Watchdog reset caller address */
#define DDR_WATCHDOG_RST_CALLER_ADDR        0x07D7F038

/* 4 byte for TR069 Upgrade flag */
#define DDR_TR069_UPGRADE_FLAG_ADDR         0x07D7F03C

/* 4 byte for min/max system flag */
#define DDR_MIN_MAX_SYSTEM_FLAG_ADDR        0x07D7F040

/* 4 byte for UART Self adaption flag */
#define DDR_UART_SELF_ADAPT_FLAG_ADDR       0x07D7F044

/* 4 byte for usb download flag */
#define DDR_USB_DL_FLAG_ADDR                0x07D7F048

/* 4 byte for PMIC type address */
#define DDR_PMIC_TYPE_ADDR                  0x07D7F04C

/* 4 byte for Flash type address */
#define DDR_FLASH_TYPE_ADDR                 0x07D7F050

/* 4 byte for PROJECT type address */
#define DDR_PROJECT_TYPE_ADDR               0x07D7F054

/* End address to save Flag*/
#define DDR_FLAG_END_ADDR                   0x07D7FFFC


/*
*
* Read/Write/RDMDFYWR/RDCLEAR register operation
*
*/

/*Read byte from register*/
#define BU_REG_BYTE_READ(x) (*(volatile unsigned char *)(x))

/*Write byte to register*/
#define BU_REG_BYTE_WRITE(x,y) ((*(volatile unsigned char *)(x)) = y )

/*Read byte from register*/
#define BU_REG_READ8(x) (*(volatile UINT8 *)(x) & 0xff)

/*Write byte to register*/
#define BU_REG_WRITE8(x,y) ((*(volatile UINT8 *)(x)) = (y & 0xff) )

/*Read 2 bytes from register*/
#define BU_REG_READ16(x) (*(volatile UINT16 *)(x) & 0xffff)

/*Write 2 bytes to register*/
#define BU_REG_WRITE16(x,y) ((*(volatile UINT16 *)(x)) = (y & 0xffff) )

/*Read data from register*/
#define BU_REG_READ(x) (*(volatile UINT32 *)(x))

/*Write data to register*/
#define BU_REG_WRITE(x,y) ((*(volatile UINT32 *)(x)) = y )

/* Write data to register based on original setting*/
#define BU_REG_RDMDFYWR(x,y)  (BU_REG_WRITE(x,((BU_REG_READ(x))|y)))

/* Clear data to register based on original setting*/
#define BU_REG_RDCLEAR(x,y)  (BU_REG_WRITE(x,((BU_REG_READ(x))&~(y))))

/*===========================================================================

                          Type definition.

===========================================================================*/

/* Type definition for Project Type. */
typedef enum
{
    /* Wukong Project*/
    WUKONG_MRV_DGLE                 = 0x00,
	WUKONG_MRV_MIFI                 = 0x01,
	WUKONG_MAX_TYPE                 = 0x64,

	/* Nezha Project*/
	NEZHA_MRV_MIFI                  = 0x65,
	NEZHA_SS_MIFI                   = 0x66,
	NEZHA_LTE_DGLE                  = 0x67,
	NEZHA_PCIE_DGLE                 = 0x68,
	NEZHA_MRV_EVB3                  = 0x69,
	NEZHA_MMIFI_V3                  = 0x70,
	NEZHA_SMIFI_V2                  = 0x71,
	NEZHA_SMNAND_V2                 = 0x72,
    NEZHA_MMIFI_V4                  = 0x73,
    NEZHA_MMIFI_V5                  = 0x74,
	NEZHA_MAX_TYPE                  = 0xFF
}PlatformProjectType;

/* Type definition for PMIC Type. */
typedef enum
{
	PMIC_USTICA                     = 0x30,
	PMIC_8607_8609                  = 0x31,
	PMIC_PROCIDA                    = 0x32,
	PMIC_GUILIN                     = 0x33,
	PMIC_MAX_TYPE                   = 0xFF
}PMICType;

/* Type definition for project transfer Type. */
typedef enum
{
	NEZHAC_DKB                      = 0x30,
	NEZHAC_MIFI                     = 0x31,
	NEZHAC_MAX_TYPE                 = 0xFF
}ProjectTransferType;


/* Type definition for I2C Type. */
typedef enum
{
	I2C_POWER_I2C                   = 0x00,
	I2C_CP_I2C                      = 0x01,
	I2C_MAX_TYPE                    = 0xFF
}I2CType;

/* Type definition for Board Type. */
typedef enum
{
    /* Wukong Board.*/
	WUKONG_MRV_MIFI_BOARD           = 0x00,
	WUKONG_MRV_EVB_BOARD            = 0x01,
	WUKONG_MRV_TD365_BOARD          = 0x02,
    WUKONG_MAX_BOARD_TYPE           = 0x64,

	/* Nezha Board.*/
	NEZHA_MRV_MIFI_BOARD            = 0x65,
	NEZHA_MRV_EVB_BOARD             = 0x66,
	NEZHA_SSG_MIFI_BOARD            = 0x67,
	NEZHA_MRV_EVB3_BOARD            = 0x68,
	NEZHA_MMIFI_V3_BOARD            = 0x69,
	NEZHA_SMIFI_V2_BOARD            = 0x70,
	NEZHA_SMNAND_V2_BOARD           = 0x71,
	NEZHA_MMIFI_V4_BOARD            = 0x72,
	NEZHA_MMIFI_V5_BOARD            = 0x73,

	/* NezhaC Board.*/
	NEZHAC_MIFI_DKB_BOARD           = 0x80,
	NEZHAC_MIFI_V1_BOARD            = 0x81,
	NEZHA_MAX_BOARD_TYPE            = 0xFF
}PlatformBoardType;

/* Type definition for USB Descriptor. */
typedef enum
{
	USB_GENERIC_MIFI_DESCRIPTOR     = 27,
    USB_MARVELL_MIFI_DESCRIPTOR     = 30,
    USB_RNDIS_ONLY_DESCRIPTOR	    = 33,
    USB_ASR_MIFI_DESCRIPTOR         = 34,
    USB_MARVELL_ECM_DESCRIPTOR      = 40,
	USB_MBIM_ONLY_DESCRIPTOR 	    = 55,
	USB_MBIM_MODEM_DIAG_DESCRIPTOR	= 56,
    USB_MODEM_DIAG_DESCRIPTOR       = 57,
    USB_MODEM_ONLY_DESCRIPTOR       = 58,
	USB_CDROM_ONLY_DESCRIPTOR       = 66,
	USB_CDROM_DIAG_DESCRIPTOR       = 67,
	USB_DIAG_ONLY_DESCRIPTOR        = 68,
    USB_GENERIC_MOD_ECM_DESCRIPTOR  = 69,
	USB_GENERIC_MOD_DESCRIPTOR      = 70,
	USB_DIAG_UAC_DESCRIPTOR         = 71,
	#ifdef USB2_VBUS_DETECT 
		USB_GENERIC_MOD_SULOG_DESCRIPTOR,
	#endif
	#ifdef QUEC_USB_CDC_SUPPORT
	    USB_CDC_ACM_ONLY_DESCRIPTOR,
	#endif

	USB_MAX_DESCRIPTOR_TYPE
}PlatformUsbDescType;

/* Type definition for Platform configure. */
typedef struct
{
    char  String[6];
    BOOL  ChargeEnable;
    BOOL  KeypadEnable;
    BOOL  OledEnable;
    BOOL  WebEnable;
    BOOL  WifiEnable;
    BOOL  dialerEnable;
    BOOL  SDCardEnable;
    I2CType  I2C_Type;
    PMICType PMIC_Type;
    PlatformBoardType Board_Type;
    PlatformProjectType Project_Type;
} PlatformConfigType;

/*===========================================================================

            EXTERN DEFINITIONS AND DECLARATIONS FOR MODULE

===========================================================================*/

/* I2C register Base address. */
extern unsigned long I2CRegBaseAddress;

/* the pointer to the current thread. */
extern void **pCurrentThread;

/*===========================================================================

                        EXTERN FUNCTION DECLARATIONS

===========================================================================*/
/*===========================================================================

FUNCTION isNezhaY0Above

DESCRIPTION
  Check whether the Chip is Y0 above or not.

DEPENDENCIES
  log string need to print.

RETURN VALUE
  none

SIDE EFFECTS
  none

===========================================================================*/
extern UINT8 isNezhaY0Above(void);

/*===========================================================================

FUNCTION IsMiniSystem

DESCRIPTION
  Check whether it is mini system or not.

DEPENDENCIES
  log string need to print.

RETURN VALUE
  none

SIDE EFFECTS
  none

===========================================================================*/
extern BOOL IsMiniSystem(void);

/*===========================================================================

FUNCTION sdio_config_nz_mifi20_pin

DESCRIPTION
  Nezha MIFI 2.0 Pin Mux configure.

DEPENDENCIES
  log string need to print.

RETURN VALUE
  none

SIDE EFFECTS
  none

===========================================================================*/
extern void sdio_config_nz_mifi20_pin(void);

/*===========================================================================

FUNCTION sdio_config_nz_mifi10_pin

DESCRIPTION
  Nezha MIFI 1.0 Pin Mux configure.

DEPENDENCIES
  log string need to print.

RETURN VALUE
  none

SIDE EFFECTS
  none

===========================================================================*/
extern void sdio_config_nz_mifi10_pin(void);

/*===========================================================================

FUNCTION CurrentThreadIsHISR

DESCRIPTION
  Check whether the current thread is HISR or not.

DEPENDENCIES
  log string need to print.

RETURN VALUE
  none

SIDE EFFECTS
  none

===========================================================================*/
BOOL CurrentThreadIsHISR(void);

/*===========================================================================

                          INTERNAL FUNCTION DECLARATIONS

===========================================================================*/
/*===========================================================================

FUNCTION PlatformGetBoardType

DESCRIPTION
  Get board Type.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/
PlatformBoardType PlatformGetBoardType(void);

/*===========================================================================

FUNCTION PlatformGetPMICType

DESCRIPTION
  Get PMIC Type.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/

PMICType PlatformGetPMICType(void);

/*===========================================================================

FUNCTION PlatformSetPMICType

DESCRIPTION
  Get PMIC Type.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/

void PlatformSetPMICType(PMICType type);

/*===========================================================================

FUNCTION PlatformGetI2CType

DESCRIPTION
  Get PMIC Type.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/

I2CType PlatformGetI2CType(void);

/*===========================================================================

FUNCTION PlatformI2CInit

DESCRIPTION
  I2C related variables initialize.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/

void PlatformI2CInit(void);

/*===========================================================================

FUNCTION PlatformGetProjectType

DESCRIPTION
  Get Project Type.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/

PlatformProjectType PlatformGetProjectType(void);

/*===========================================================================

FUNCTION PlatformChargeIsEnable

DESCRIPTION
  Check whether the charge module is enable or not.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/
BOOL PlatformChargeIsEnable(void);

/*===========================================================================

FUNCTION PlatformOledIsEnable

DESCRIPTION
  Check whether the OLED module is enable or not.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/
BOOL PlatformOledIsEnable(void);

/*===========================================================================

FUNCTION PlatformKeypadIsEnable

DESCRIPTION
  Check whether the Keypad module is enable or not.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/
BOOL PlatformKeypadIsEnable(void);

/*===========================================================================

FUNCTION PlatformLwipIsEnable

DESCRIPTION
  Check whether the LWIP module is enable or not.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/
BOOL PlatformLwipIsEnable(void);

/*===========================================================================

FUNCTION PlatformWebIsEnable

DESCRIPTION
  Check whether the Web data module is enable or not.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/
BOOL PlatformWebIsEnable(void);

/*===========================================================================

FUNCTION PlatformWifiIsEnable

DESCRIPTION
  Check whether the WIFI module is enable or not.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/
BOOL PlatformWifiIsEnable(void);

/*===========================================================================

FUNCTION PlatformWapiIsEnable

DESCRIPTION
  Check whether the WAPI module is enable or not.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/
BOOL PlatformWapiIsEnable(void);

/*===========================================================================

FUNCTION PlatformDialerIsEnable

DESCRIPTION
  Check whether the dialer module is enable or not.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/
BOOL PlatformDialerIsEnable(void);

/*===========================================================================

FUNCTION PlatformSpiNorEnable

DESCRIPTION
  Check whether the SPI Nor module is enable or not.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/
BOOL PlatformSpiNorEnable(void);

/*===========================================================================

FUNCTION PlatformSDCardEnable

DESCRIPTION
  Check whether the SD Card module is enable or not.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/
BOOL PlatformSDCardEnable(void);

/*===========================================================================

FUNCTION PlatformIsWukong

DESCRIPTION
  Check whether the platform is Wukong or not.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/
BOOL PlatformIsWukong(void);

/*===========================================================================

FUNCTION PlatformIsNezhaC

DESCRIPTION
  Check whether the platform is NezhaC or not.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/
BOOL PlatformIsNezhaC(void);

/*===========================================================================

FUNCTION PlatformIsLwgVersion

DESCRIPTION
  Check whether the platform is LWG version or not.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/
BOOL PlatformIsLwgVersion(void);

/*===========================================================================

FUNCTION PlatformIsLtgVersion

DESCRIPTION
  Check whether the platform is LTG version or not.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/
BOOL PlatformIsLtgVersion(void);

/*===========================================================================

FUNCTION PlatformIsSDKVersion

DESCRIPTION
  Check whether the platform is SDK version or not.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/
BOOL PlatformIsSDKVersion(void);

/*===========================================================================

FUNCTION PlatformIsMinSystem

DESCRIPTION
  Check whether the platform is min system or not.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/
BOOL PlatformIsMinSystem(void);

/*===========================================================================

FUNCTION PlatformIsZmifi

DESCRIPTION
  Check whether the platform is ZIMI MIFI or not.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/
BOOL PlatformIsZmifi(void);

/*===========================================================================

FUNCTION PlatformSetCustomData

DESCRIPTION
  Set const data acccording to customer type.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/
void PlatformSetCustomData(void);

/*===========================================================================

FUNCTION PlatformIsTPMifi

DESCRIPTION
  Check whether the platform is TP link MIFI or not.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/
BOOL PlatformIsTPMifi(void);

/*===========================================================================

FUNCTION PlatformCSDEnable

DESCRIPTION
  Check whether the CSD is enable or not.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/
BOOL PlatformCSDEnable(void);

/*===========================================================================

FUNCTION Platform_sdio_config_pin

DESCRIPTION
  Check whether the platform is Wukong or not.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/
void Platform_sdio_config_pin(void);
#endif
