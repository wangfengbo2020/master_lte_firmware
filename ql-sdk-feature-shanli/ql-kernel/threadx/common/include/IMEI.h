/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

//Copyright 2005, Intel Corporation, All rights reserved.

/******************************************************************************
 *               MODULE IMPLEMENTATION FILE
 *******************************************************************************
 * Title: IMEI
 *
 * Filename: IMEI.h
 *
 * Authors:   ashenkal
 *
 * Description: IMEI API - Set / Read / Lock IMEI number to / from / in INT_FLASH
 *
 * Last Updated: 23/1/2006
 *              26/02/2008, yshemla - new design for IMEI management by Shay Shrot: means that
 *              IMEI is now burn to specific location in Flash, and retrieved by OBM
 *              to predefined location in DDR (predefined but still dynamic)

 *
 * Notes:
 ******************************************************************************/
#ifndef _IMEI_H
#define _IMEI_H

#include "global_types.h"
#include "quec_cust_feature.h"

//#if defined(_HERMON_B0_SILICON_) && !defined(INTEL_2CHIP_PLAT_BVD)
 /* OLD DESIGN */
//#else//(_TAVOR_HARBELL_) && TTC
#define IMEI_NEW_DESIGN    // comment this for SW that doesn't support new IMEI design
			//              new design for IMEI management by Shay Shrot: means that
			//              IMEI is now burn to specific location in Flash, and retrieved by OBM
			//              to predefined location in DDR
//#endif//_HERMON_B0_SILICON_

#if defined IMEI_NEW_DESIGN

/********************************************************************************
\* IMEISV format (16 numbers) - :
*  Manufacturer      Code    Platform           Code    SV              Code
*  digits[0]... digits[7]    digits[8]... digits[13]    digits[14] digits[15]
*
* Generic Format (support only IMEISV) as returned in IMEIRead :
*
* digits[0] : first char (MSB) in Manufacturer Code
* digits[7] : last char (LSB) in Manufacturer Code
* digits[8] : first char (MSB) in Platform Code
* digits[13] : last char (LSB) in Platform Code
* digits[14] : first char (MSB) in SV Code
* digits[15] : last char (MSB) in SV Code
*
******************************************************************************/

#define IMEI_DEFAULT_NUMBER     "0010680000000000"

#define IMEI_TOTAL_LEN         	15
#define IMEI_LEN            	14

#define IMEI_NUMBER_SIZE                 16                                 // 16 bytes
#define USER_DATA_SIZE                   16                                 // 16 bytes
#define IMEI_SUB_KEY_SIZE                26                                 // Longs == 104 bytes
#define IMEI_USER_KEY_SIZE            	 26                                 // Longs == 104 bytes
#ifdef 	QUEC_CAMMERA_DECODE_AUTHORIZATION
#define MAX_QRCODE_LEN      1024
#define MAX_LICENSEINFO_LEN  1024

#endif

#ifdef QUEC_AUDIO_DENOISE
#define MAX_DENOISE_LEN      1024
#define MAX_DENOISE_LICENSEINFO_LEN  1024

#endif 
typedef enum
{
	IMEI_IS_NOT_ENC = 0,
	IMEI_IS_ENC
} IMEI_DEC_ENC;

typedef struct
{
    char   digits[16];
} IMEIData;





typedef struct
{
	unsigned char               DeycrptNumber[IMEI_NUMBER_SIZE];
    unsigned char               UserData[USER_DATA_SIZE];
    unsigned char               EncryptNumber[IMEI_NUMBER_SIZE];
    unsigned long               UserKey[IMEI_USER_KEY_SIZE];              // 104 bytes
    unsigned long               SubKey[IMEI_SUB_KEY_SIZE];             // 104 bytes
	unsigned char               ImeiEncrypt;                     /* this will be set to 'IMEI_IS_ENC' in case the EncryptNumber
																  *  is valid */
} IMEIExtendedData;

typedef struct
{
// CD = Check Digit , SV = Software Version

// IMEI(14 digits)+ CD(1 digit), SV(2 digits)
    char   imei_digits[16];
	char   sv_digits[3];
} IMEIStr;

void IMEIinit(unsigned long *ddrBuffaddr);
void IMEIExtendedInit(unsigned long *ddrBuffaddr);
void IMEIRead( IMEIData *imei);      // PS calls this API with pointer to struct of size 9
void IMEIReadOnly( const IMEIData **imei);
void IMEIExtendedRead( const IMEIExtendedData **ext_imei);
void IMEIReadStr( IMEIStr* imeiStr );
BOOL IMEIIsDefaultNumber ( void );

void IMEI2init(unsigned long *ddrBuffaddr);
void IMEI2ExtendedInit(unsigned long *ddrBuffaddr);
void IMEI2Read( IMEIData *imei);      // PS calls this API with pointer to struct of size 9
void IMEI2ReadOnly( const IMEIData **imei);
void IMEI2ExtendedRead( const IMEIExtendedData **ext_imei);
void IMEI2ReadStr( IMEIStr* imeiStr );
BOOL IMEI2IsDefaultNumber ( void );

#else    /* IMEI_NEW_DESIGN */


//compile flags:
#define IMEI_DEBUG_ENABLED
//#define HEXA_DIGITS_ENABLED
#define IMEI_ICAT_ENABLED

#define MC_INTEL					0x89

#define INT_FLASH_ADDR				0x80000000
#define EXT_FLASH_ADDR				0x04000000

#define TETON_FLASH_ID				0x27
#define TETON_FLASH_FPR_OFFSET		0x80
#define TETON_FLASH_FPR_BITS		64
#define TETON_FLASH_FAC_ID_SIZE		4

#define FPR_LOCK_BIT_MASK			0x0002

typedef struct
{
	unsigned int   *baseFlashAddr; //
  	unsigned int    offset; //of FPR lock register from base address of flash.
	unsigned int    facIdSize; //in words
	unsigned int    fprSize; //in bits
	unsigned char	imeiLength; // in digits
} FPRData;

typedef enum
{
	FPR_INT_FLASH = 0,
	FPR_EXT_FLASH,
	FPR_FDI
} FlashLoc;

typedef enum
{
	IMEI_RC_OK = 0,
	IMEI_RC_LOCKED,
	IMEI_RC_FLASH_BUSY,
	IMEI_RC_RW_NO_SUPPORT,
	IMEI_RC_VALUE_ERR,
	IMEI_RC_PROGRAM_ERR,
	IMEI_RC_VPP_LOW_ERR,
	IMEI_RC_FPR_MODIFIED_WARN
} IMEI_ReturnCode;

unsigned short FPRInit (FlashLoc flashPick);
IMEI_ReturnCode  IMEIInit (FlashLoc flashPick, unsigned char imeiLength);
IMEI_ReturnCode IMEIWrite (char *imei);
void IMEIRead (char* imei);
IMEI_ReturnCode FPRWrite (FlashLoc flashPick, unsigned char*  valPtr, unsigned char highWrBit, unsigned char lowWrBit);
void FPRRead (FlashLoc flashPick, unsigned char* dataBufPtr);
IMEI_ReturnCode FPRLock (FlashLoc flashPick);
void FacIDRead (FlashLoc flashPick, unsigned short* facId);

#endif  /* IMEI_NEW_DESIGN */
#endif  /* _IMEI_H */
