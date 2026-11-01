/******************************************************************************
 *
 *  (C)Copyright ASR micro. All Rights Reserved.
 *
 *  THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF ASR.
 *  The copyright notice above does not evidence any actual or intended
 *  publication of such source code.
 *  This Module contains Proprietary Information of ASR and should be
 *  treated as Confidential.
 *  The information in this file is provided for the exclusive use of the
 *  licensees of ASR.
 *  Such users have the right to use, modify, and incorporate this code into
 *  products for purposes authorized by the license agreement provided they
 *  include this notice and the associated copyright notice with any such
 *  product.
 *  The information in this file is provided "AS IS" without warranty.
 *
 ******************************************************************************/
#ifndef __SPI_H__
#define __SPI_H__

#include "ssp_reg.h"

// Flash Types
typedef enum
{
    CS0_XIP_FLASH	= 1,
    CS2_XIP_FLASH	= 2,
    NAND_FLASH		= 3,
    ONENAND_FLASH	= 4,
    MSYS_DOC_FLASH	= 5,
    SDMMC_FLASH		= 6,
    SPI_NOR_FLASH	= 7,
    SPI_NAND_FLASH	= 8
} FlashType_T;

// Flash Fuses
typedef enum
{
    NO_FLASH_P			= 0,
    MSYS_DOC_FLASH_P	= 1,
    ONENAND_FLASH_P		= 2,
    CS0_XIP_FLASH_P		= 3,
    NAND_FLASH_X16_P	= 4,
    CS2_XIP_SIBLEY_P	= 5,
    NAND_FLASH_X8_P		= 6,
    CS2_XIP_TYAX_P		= 7,
    SDMMC_FLASH_OPT1_P	= 8,
    SDMMC_FLASH_OPT2_P	= 9,
    SPI_FLASH_P			= 10,
    SDMMC_FLASH_OPT3_P	= 11
} FlashProbeList_T;

// Flash Structure Types
typedef enum
{
    BOOT_FLASH			= 0,
    SAVE_STATE_FLASH	= 1
} FlashBootType_T;

// ssp flash
typedef enum
{
    SSP_PORT_0			= 0,
    SSP_PORT_1			= 1,
    SSP_PORT_2			= 2,
} SSP_PORT;


typedef struct
{
    unsigned int Reserved			: 13;
    unsigned int SASize				: 11;	//size of spare area, in bytes, PER PAGE!!
    unsigned int UseSpareArea		: 1;	//tells driver whether to write spare area or not (1 = yes, 0 = no)
    unsigned int UseHwEcc			: 1;	//tells driver whether to use HW ECC during read and writes (1 = yes, 0 = no)
    unsigned int UseBBM				: 1;	//driver sets to determine if the flash should use BBM (1 = yes, 0 = no)
    unsigned int FlashNum			: 4;	//see above enum
    unsigned int FlashInitialized	: 1;	//1 = Flash initialized, 0 = Flash NOT initialized
} FlashAttributes_T;


typedef unsigned int (*InitFlash_F) (unsigned char FlashNum, FlashBootType_T FlashBootType, unsigned char *P_DefaultPartitionNum);
typedef unsigned int (*FinalizeFlash_F) (FlashBootType_T FlashBootType);
typedef unsigned int (*ReadFlash_F) (unsigned int FlashOffset, unsigned int LocalBuffer, unsigned int Size, FlashBootType_T FlashBootType);
typedef unsigned int (*WriteFlash_F) (unsigned int FlashOffset, unsigned int LocalBuffer, unsigned int Size, FlashBootType_T FlashBootType);
typedef unsigned int (*EraseFlash_F) (unsigned int FlashOffset, unsigned int Size, FlashBootType_T FlashBootType);
typedef unsigned int (*ResetFlash_F) (FlashBootType_T FlashBootType);
typedef unsigned int (*WipeFlash_F) (FlashBootType_T FlashBootType);
typedef void   		 (*ChangePartition_F) (unsigned int PartitionNum, FlashBootType_T FlashBootType);
typedef unsigned int (*WriteOTP_F) (unsigned int FlashOffset, unsigned int LocalBuffer, unsigned int Size);
typedef unsigned int (*ReadOTP_F) (unsigned int FlashOffset, unsigned int LocalBuffer, unsigned int Size);
typedef unsigned int (*LockOTP_F) (void);
typedef unsigned int (*ConvertToLogicalAddr_F) (unsigned int FlashLocation, FlashBootType_T FlashBootType);

typedef struct
{
    unsigned int 			BlockSize;
    unsigned int 			PageSize;
    unsigned int 			NumBlocks;
    unsigned int            SectorSize;
    unsigned int                  TimFlashAddress;
    FlashType_T				FlashType;
    unsigned int					*ReservedPkgIDs;
    FlashAttributes_T		FlashSettings;

    // Function pointers
    FinalizeFlash_F			FinalizeFlash;
    ReadFlash_F				ReadFromFlash;
    WriteFlash_F			WriteToFlash;
    EraseFlash_F			EraseFlash;
    ResetFlash_F			ResetFlash;
    WipeFlash_F				WipeFlash;
    ChangePartition_F		ChangePartition;
    WriteOTP_F				WriteOTP;
    ReadOTP_F				ReadOTP;
    LockOTP_F				LockOTP;
    ConvertToLogicalAddr_F	pConvertToLogicalAddr;
}
FlashProperties_T, *P_FlashProperties_T;

/* Supported SPI Devices */
typedef struct{
	unsigned int SPI_ID;
	unsigned int SPI_CAPACITY;
	unsigned int SPI_SECTOR_SIZE;
	unsigned int SPI_PAGE_SIZE;
} SPI_DEVICE_INFO_T, *P_SPI_DEVICE_INFO_T;

typedef enum
{
	SSP_CLOCK_13M = 0x0,
	SSP_CLOCK_26M = 0x1,
	SSP_CLOCK_52M = 0x2,
} SSP_Clock;

#define TRUE 1
#define FALSE 0
/*
* SPI Command Set
*/
#define SPI_CMD_JEDEC_ID			0x009F
#define SPI_CMD_RELEASE_POWER_DOWN	0x00AB
#define SPI_CMD_READ_STATUS			0x05
#define SPI_CMD_WRITE_ENABLE		0x06
#define SPI_CMD_WRITE_STATUS_REG	0x01
#define SPI_CMD_PROGRAM				0x02
#define SPI_CMD_READ				0x03
#define SPI_CMD_SECTOR_ERASE		0x20
#define SPI_CMD_CHIP_ERASE			0xc7
#define SPI_CMD_BLOCK_ERASE			0xd8
#define SPI_CMD_POWER_DOWN			0xB9
#define SPI_CMD_RELEASE_POWER_DOWN  0xAB
#define SPI_CMD_RESET_ENABLE	    0x66
#define SPI_CMD_RESET	    		0x99

#define DEFAULT_TIMEOUT   			500
#define TIME_OUT_ERROR				0x01
#define SPINOR_WRITE_PAGE_SIZE		(0x100 / 4)
#define SPINOR_READ_PAGE_SIZE		(0x100)
#define WRITE_SIZE 					(256)
#define READ_SIZE					(0x10000)

#ifdef SPINAND_SUPPORT
#define SSP_BASE_FOR_SPI		    get_ssp_base()
#else
#define SSP_BASE_FOR_SPI		    GetSSPBase()
#endif

#define SSP_DMA_READ_SIZE           4096	//bytes per descriptor

#define SPI_READ_STATUS_RDY_BIT		BIT0
#define MAX_TEST_SIZE	            (0x1000)

typedef struct {
  unsigned int SPI_READ_CMD;
  unsigned int SPI_READ_STAUS_CMD;
  unsigned int SPI_WRITE_STATUS_CMD;
  unsigned int SPI_WRITE_ENABLE_CMD;
  unsigned int SPI_WRITE_STAGE1_CMD;
  unsigned int SPI_WRITE_STAGE2_CMD;
  unsigned int SPI_ERASE_CMD;
} SPI_COMMANDS_T, *P_SPI_COMMANDS_T;

/*
* Nezha: SSP Register locations.
*
* Note:  SSP_BASE_FOR_SPI set in platform_config.h
*/

/* SSP Control Register 0: (Offset: 0x00) */
#define SSP_CR0	            ((volatile unsigned int *) (SSP_BASE_FOR_SPI+SSP_SSCR0))

/* SSP Control Register 1: (Offset: 0x04) */
#define SSP_CR1	            ((volatile unsigned int *) (SSP_BASE_FOR_SPI+SSP_SSCR1))

/* SSP Status Register: (Offset: 0x08) */
#define SSP_SR	            ((volatile unsigned int *) (SSP_BASE_FOR_SPI+SSP_SSSR))

/* SSP Data Write/Read Register: (Offset: 0x10) */
#define SSP_DR	            ((volatile unsigned int *) (SSP_BASE_FOR_SPI+SSP_SSDR))

/* SSP SSP Programmable Serial Protocol Register: (Offset: 0x2C) */
#define SSP_SP	            ((volatile unsigned int *) (SSP_BASE_FOR_SPI+SSP_SSPSP))

/* SSP Time Out Register: (Offset: 0x28) */
#define SSP_TO	            ((volatile unsigned int *) (SSP_BASE_FOR_SPI+SSP_SSTO))

//Control Register special values
#define SSP_CR0_INITIAL 	(SSP_SSCR0_TIM | SSP_SSCR0_RIM | 0x7)
#define SSP_CR0_SSE			SSP_SSCR0_SSE
#define SSP_CR0_FPCKE		SSP_SSCR0_FPCKE
#define SSP_CR0_DSS_32		SSP_SSCR0_EDSS | 0xF
#define SSP_CR0_DSS_24		SSP_SSCR0_EDSS | 0x7
#define SSP_CR0_DSS_16		0x0000000F
#define SSP_CR0_DSS_8		0x00000007

#define SSP_CR1_INITIAL 	SSP_SSCR1_TTELP | SSP_SSCR1_TTE
#define SSP_CR1_RWOT		SSP_SSCR1_RWOT

#define SSP_SSSR_TFL			0xF00       // BIT 11:8 --Transmit FIFO Level, when it's 0x0, TXFIFO is emptry or full.


/*
* NezhaC: SSP Register locations.
*
* Note:  SSP_BASE_FOR_SPI set in platform_config.h
*/

/* SSP Top Control Register: (Offset: 0x00)*/
#define SSP_TCR	((volatile int *) (SSP_BASE_FOR_SPI+SSP_TOP_CTRL))

/* SSP FIFO Control Register: (Offset: 0x04)*/
#define SSP_FCR	((volatile int *) (SSP_BASE_FOR_SPI+SSP_FIFO_CTRL))

/* SSP Interrupt Enable Register: (Offset: 0x08)*/
#define SSP_IER	((volatile int *) (SSP_BASE_FOR_SPI+SSP_INT_EN))

/* SSP Time Out Register: (Offset: 0x0C)*/
#define SSP_TOR	((volatile int *) (SSP_BASE_FOR_SPI+SSP_TIMEOUT))

/* SSP Data Register: (Offset: 0x10)*/
//#define SSP_DR	((volatile int *) (SSP_BASE_FOR_SPI+SSP_DATAR))

/* SSP Status Register: (Offset: 0x14)*/
#define SSP_STS	((volatile int *) (SSP_BASE_FOR_SPI+SSP_STATUS))

//Control Register special values
#define SSP_TCR_INITIAL		        (SSP_TCR_TTELP | SSP_TCR_TTE | SSP_TCR_DSS8)
#define SSP_IER_INITIAL		        (SSP_IER_TIM | SSP_IER_RIM)
#define SSP_FCR_INITIAL		        0

#define SSP_FCR_DMA_PAGE_PROGRAM    (SSP_FCR_RFT(15) | SSP_FCR_TFT(15) | SSP_FCR_RSRE | SSP_FCR_TSRE)
#define SSP_FCR_DMA_READ	        (SSP_FCR_RFT(15) | SSP_FCR_TFT(15) | SSP_FCR_RSRE | SSP_FCR_TSRE)
#define SSP_FCR_DMA_WRITE	        (SSP_FCR_TFT(2) | SSP_FCR_RSRE | SSP_FCR_TSRE)
#define SSP_FCR_DMA_ERASE	        (SSP_FCR_TFT(2) | SSP_FCR_RSRE | SSP_FCR_TSRE)

#define SSP_FCR_NAND_DMA_READ	    (SSP_FCR_RFT(3) | SSP_FCR_TFT(3) | SSP_FCR_RSRE | SSP_FCR_TSRE)

#define SSP_TOR_TIMEOUT             0x1FFF

/* Transmit FIFO Level: BIT 11:7, when it's 0x0, TXFIFO is emptry or full. */
#define SSP_STS_TFL	            0xF80

/* Transmit FIFO Not Full: 0 = TXFIFO is ful, 1 = TXFIFO is not full */
#define	SSP_STS_TF_NF		    BIT_6

/* SSP Busy: 0 = SSPx port is idle or disabled, 1 = SSPx port is currently transmitting or receiving framed data */
#define	SSP_STS_BSY	            BIT_0


#define BU_REG_READ8(x) (*(volatile unsigned char *)(x) & 0xff)
#define BU_REG_WRITE8(x,y) ((*(volatile unsigned char *)(x)) = y & 0xff )

#define spi_reg_read(reg)		*(volatile unsigned int *)(reg)
#define spi_reg_write(reg, val) *(volatile unsigned int *)(reg) = val; *(volatile unsigned int *)(reg);
#define spi_reg_bit_set(reg, val) *(volatile unsigned int *)(reg) |= val; *(volatile unsigned int *)(reg);
#define spi_reg_bit_clr(reg, val) *(volatile unsigned int *)(reg) &= ~val; *(volatile unsigned int *)(reg);


unsigned int SPINOR_Wipe(int sspport);
unsigned int SPINOR_EraseByBlock(int sspport, unsigned int Address, unsigned int Size);
unsigned int SPINOR_EraseBySector(int sspport, unsigned int Address, unsigned int Size);
unsigned int SPINOR_Read(int sspport, unsigned int FlashOffset, unsigned char * Buffer, unsigned int Size);
unsigned int SPINOR_Write(int sspport, unsigned int Address, unsigned char * Buffer, unsigned int Size);
int InitializeSPIDevice(int sspport, int sspclock);
void SPINOR_SW_Reset(int sspport);
int SPINOR_getSSPPort(void);

#endif
