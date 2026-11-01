/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

#ifndef REL_DATA_H
#define REL_DATA_H

#include "xscale_types.h"
#include "global_types.h"

#if defined (NVM_INCLUDE)
//COM side is with FDI5 conventions.
#include <FDI_EXT.h>
#include <FDI_FILE.h>
#include <FDI_TYPE.h>
#endif

/*Relaible data types*/
#define   EMPTY_TYPE 	   	 0x00000000
#define   RD_FORMAT_VER      0x00001019 //update this when updating the RDB image - padding support to be align to UNTI32.
#define   RD_FORAMT_LGCY     0x00001017
#define   VALID_BUF_STMP 	 0xCAFECAFE
#define   IMEI_TYPE 		 0xCAFE0010 //add type ID according to the types in RDB image
#define   MEP_TYPE           0xCAFE0015
#define   NVM_TYPE 	   		 0xCAFE0020
#define   SERIAL_NUM_TYPE    0xCAFE0025 /* used only in OBM , no need to parse it in COM side */
#define   GEN_DATA_TYPE      0xCAFE0030 /* generic type for data transfer from OBM to COM, fileName is data identify */
//#define   RESERVED_TYPE      0xCAFE0035
#define   MRD_BTID_TYPE     0xCAFE0035
#define   MRD_WIFIMAC_TYPE   0xCAFE0040
#define   END_BUF_STMP 	 	 0xDADADADA
#define   VALID_CS_OK        0xFACEFACE

#if defined(NVM_OVER_RAM)
#define RD_FILE_INFO 		RAM_FILE_INFO
#define RD_TCHAR        	RAM_TCHAR
#define RD_FILE_ID      	RAM_FILE_ID
#define RD_FILE_NAME_SIZE   RAM_FILE_NAME_SIZE

#elif defined (NVM_INCLUDE)
#define	RD_FILE_INFO    	FILE_INFO
#define RD_TCHAR        	FDI_TCHAR
#define RD_FILE_ID			FILE_ID
#ifdef LTEONLY_THIN
#define RD_FILE_NAME_SIZE   128
#else
#define RD_FILE_NAME_SIZE   FILE_NAME_SIZE
#endif
#else

#define RD_TCHAR        	unsigned char
#define RD_FILE_NAME_SIZE   128

#endif

#define RD_SUCCESS  	TRUE
#define RD_FAIL     	FALSE
#define RD_PRE_PHASE2 	FALSE
#define RD_PHASE2  		TRUE

#define CRANE_SPI_BASE_ADD    (0x90000000)
#define CRANE_QSPI_A1_BASE_ADD    (0x80000000)
#define CRANE_QSPI_A2_BASE_ADD (0x81000000)

#define QSPI_FLASH_A1 0		//external/internal qspi A1
#define SPI_FLASH_INTERNAL 1	//internal spi
#define QSPI_FLASH_A2 2		//external qspi A2

/* IMS Cfg file name */
#define IMS_CFG_FILE "Settings_preferences.xml"

//struct size should be aligned to UINT32
typedef struct tag_buffer_flash_header
{
   UINT32 validBufferStamp;
   UINT32 bufCheckSum;
   UINT32 version;
   UINT32 reserve1;
   UINT32 reserve2;
} RD_BUFFER_HEADER;

//struct size should be aligned to UINT32
typedef struct tag_buffer_info_flash
{
   UINT32 entryType;
   UINT32 fileAndPadSize;
   RD_TCHAR file_name[RD_FILE_NAME_SIZE];
   UINT32 *pEntryData;
} RD_ENTRY;

void  	ReliableDataPhase1 ( void );
void  	ReliableDataPhase2 ( void );
BOOL    ReliableDataUnPack (BOOL);
BOOL    APReliableDataGenFilter (void);
BOOL    APReliableDataUnPack ( BOOL IsPhase2 );
char *getSerialNumber(void);

/*NEW FOR compilation */
typedef enum
{
	RD_PHASE_0,
	RD_PHASE_1,
	RD_PHASE_2
} RD_PHASE;

#if defined(__QUECTEL_PROJECT_EC600MCN_CC__)||defined(__QUECTEL_PROJECT_EC600MCN_MC__)
#define QUEC_MULT_HARDWARE_SUPPORT 1
#define module_det_pin_mfpr  0xD401E1CC        //EC600MCNCC & EC600MCNMC GPIO37
#define module_det_pin_register  0xD4019004
#endif
#if QUEC_MULT_HARDWARE_SUPPORT
typedef struct{
char module_oc[64];
char module_det_level;
UINT16 GSM_BAND;
UINT16 WCDMA_BAND;
UINT64 LTE_BAND;
}quec_mult_hardware_s;
UINT64 quec_mult_hardware_band(char *band_mode);
#endif

#endif /* REL_DATA_H */
