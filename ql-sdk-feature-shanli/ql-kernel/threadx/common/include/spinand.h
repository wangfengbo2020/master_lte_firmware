/******************************************************************************
 *
 *  (C)Copyright 2005 - 2008 Marvell. All Rights Reserved.
 *
 *  THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF MARVELL.
 *  The copyright notice above does not evidence any actual or intended
 *  publication of such source code.
 *  This Module contains Proprietary Information of Marvell and should be
 *  treated as Confidential.
 *  The information in this file is provided for the exclusive use of the
 *  licensees of Marvell.
 *  Such users have the right to use, modify, and incorporate this code into
 *  products for purposes authorized by the license agreement provided they
 *  include this notice and the associated copyright notice with any such
 *  product.
 *  The information in this file is provided "AS IS" without warranty.
 *
 ******************************************************************************/

/***********************************************************
*    SPIFlash.h
*       This is the header file for the SPIFlash driver.
*
*    Revision History:
*       5/2/07 - initial draft
************************************************************/
#ifndef __SPI_NAND_H__
#define __SPI_NAND_H__

#include "flash_wk.h"

#define DMA_DEFAULT_TIMEOUT   			3000U
#define DEFAULT_WAIT_TIME 		1000U
#define MANU_RESERVE_BLOCK	         4U

#define WRITE_SIZE          (256)
#define SIZE_4KB	        (0x1000)

/*
* SPI Command Set
*/
#define SPINAND_WRITE_ENABLE		0x06
#define SPINAND_WRITE_DISABLE		0x04
#define SPINAND_GET_FEATURES		0x0F
#define SPINAND_SET_FEATURES		0x1F
#define SPINAND_CACHE_LOAD			0x13
#define SPINAND_CACHE_READ			0x03
#define SPINAND_READ_ID			0x9F
#define SPINAND_PROGRAM_LOAD		0x02
#define SPINAND_PROGRAM_EXECUTE	0x10
#define SPINAND_BLOCK_ERASE		0xD8
#define SPINAND_RESET				0xFF


/*
 * SPI NAND Feature Types
 */

typedef enum
{
	SPINAND_PROTECTION		= 0xA0,
	SPINAND_FEATURE			= 0xB0,
	SPINAND_STATUS			= 0xC0
} SPINAND_Feature_E;

//
// GigaDevice GD5F1GQ4RAYIG: protection register 0xa0
//
// 7      6      5      4      3      2      1		0
// +------+------+------+------+------+------+------+------+
// | BRWD | Rerd |  BP2 | BP1  | BP0  |  INV | CMP  |Rerd  |
// +------+------+------+------+------+------+------+------+

#define GIGA_SPINAND_PROTECTION_Rerd1		BIT_0	// Rserved
#define GIGA_SPINAND_PROTECTION_CMP		BIT_1	// level of protected blcok
#define GIGA_SPINAND_PROTECTION_INV		BIT_2	// level of protected blcok
#define GIGA_SPINAND_PROTECTION_BP0		BIT_3	// level of protected blcok
#define GIGA_SPINAND_PROTECTION_BP1		BIT_4	// level of protected blcok
#define GIGA_SPINAND_PROTECTION_BP2		BIT_5	// level of protected blcok
#define GIGA_SPINAND_PROTECTION_BP3	    	BIT_6	// level of protected blcok
#define GIGA_SPINAND_PROTECTION_BRWD		BIT_7	// block protection lock

//
// GigaDevice GD5F1GQ4RAYIG: feature register 0xb0
//
// 7      6      5      4      3      2      1		0
// +-------+------+------+------+------+------+------+------+
// |OTP_PRT|OTP_EN| Rerd |ECC_EN| Rerd | Rerd | Rerd |  QE  |
// +-------+------+------+------+------+------+------+------+

#define GIGA_SPINAND_FEATURE_QE			BIT_0	// quad enable
#define GIGA_SPINAND_FEATURE_Rerd3		BIT_1	// reserved
#define GIGA_SPINAND_FEATURE_Rerd2		BIT_2	// reserved
#define GIGA_SPINAND_FEATURE_Rerd1		BIT_3	// reserved
#define GIGA_SPINAND_FEATURE_ECC_EN		BIT_4	// ecc enable
#define GIGA_SPINAND_FEATURE_Rerd		BIT_5	// reserved
#define GIGA_SPINAND_FEATURE_OTP_EN		BIT_6	// one-time program
#define GIGA_SPINAND_FEATURE_OTP_PRT	BIT_7	// one-time program

//
// GigaDevice GD5F1GQ4RAYIG: status register 0xc0
//
// 7      6      5      4      3      2      1		0
// +-----+------+------+------+------+------+------+------+
// | Rerd| Rerd |ECCS1 |ECCS0 |P_FAIL|E_FAIL| WEL  | OIP  |
// +-----+------+------+------+------+------+------+------+

#define GIGA_SPINAND_STATUS_OIP			BIT_0	// operation in progress
#define GIGA_SPINAND_STATUS_WEL			BIT_1	// write enable latch
#define GIGA_SPINAND_STATUS_E_FAIL		BIT_2	// erase fail
#define GIGA_SPINAND_STATUS_P_FAIL		BIT_3	// program fail
#define GIGA_SPINAND_STATUS_ECCS0		BIT_4	// ecc status
#define GIGA_SPINAND_STATUS_ECCS1		BIT_5	// ecc status
#define GIGA_SPINAND_STATUS_Rerd		BIT_6	// reserved
#define GIGA_SPINAND_STATUS_Rerd1		BIT_7	// reserved

/*
 * SPI NAND Timeouts (all in MICRO seconds!!)
 *	NOTE: I roughly doubled all the values listed in the specification, as the
 *		core will be running slowly in BootROM and I wanted to avoid any situation
 *		where the operation finished at the edge of the timeout value, but the
 *		slow running core captures the timer value just after timeout
 */

#define SN_READ_TIMEOUT		0x100	//maximum time to load a page into the cache field
#define SN_ERASE_TIMEOUT	0x800	//maximum time for the erase operation
#define SN_PROGRAM_TIMEOUT	0x5000	//maximum time for the program operation

#define SSP_READ_TIME_OUT	0x80000	//timeout for reading data from cache to internal memory
									//this is dependent on CPU and DMA clock speeds, NOT the SPI device!

/*
 *  SPI NAND: other values
 */
typedef enum
{
	SSP_CLOCK_13M = 0x0,
	SSP_CLOCK_26M = 0x1,
	SSP_CLOCK_52M = 0x2,
} SSP_Clock;


#define SPINAND_PAGE_SIZE							0x800	
#define SPINAND_BLOCK_SIZE							0x20000	

#define SPINAND_PAGE_WORDS_SIZE					0x200	
#define SPINAND_PAGE_WITH_SPARE_WORDS_SIZE		0x210	
#define SPINAND_PAGE_WITH_SPARE_BYTES_SIZE			(SPINAND_PAGE_WITH_SPARE_WORDS_SIZE<<2)


#define SPI_NAND_MAX_TEST_SIZE	            (65536+4)

/*
* Nezha: SSP Register locations.
*/
#define SSPORT_BASE_FOR_SPI		    get_ssp_base()

/* SSP Control Register 0: (Offset: 0x00) */
#define SSPORT_CR0	            ((volatile unsigned int *) (SSPORT_BASE_FOR_SPI+SSP_SSCR0))

/* SSP Control Register 1: (Offset: 0x04) */
#define SSPORT_CR1	            ((volatile unsigned int *) (SSPORT_BASE_FOR_SPI+SSP_SSCR1))

/* SSP Status Register: (Offset: 0x08) */
#define SSPORT_SR	            ((volatile unsigned int *) (SSPORT_BASE_FOR_SPI+SSP_SSSR))

/* SSP Data Write/Read Register: (Offset: 0x10) */
#define SSPORT_DR	            ((volatile unsigned int *) (SSPORT_BASE_FOR_SPI+SSP_SSDR))

/* SSP SSP Programmable Serial Protocol Register: (Offset: 0x2C) */
#define SSPORT_SP	            ((volatile unsigned int *) (SSPORT_BASE_FOR_SPI+SSP_SSPSP))

/* SSP Top Control Register: (Offset: 0x00)*/
#define SSPORT_TCR	((volatile int *) (SSPORT_BASE_FOR_SPI+SSP_TOP_CTRL))

/* SSP FIFO Control Register: (Offset: 0x04)*/
#define SSPORT_FCR	((volatile int *) (SSPORT_BASE_FOR_SPI+SSP_FIFO_CTRL))

/* SSP Interrupt Enable Register: (Offset: 0x08)*/
#define SSPORT_IER	((volatile int *) (SSPORT_BASE_FOR_SPI+SSP_INT_EN))

/* SSP Time Out Register: (Offset: 0x0C)*/
#define SSPORT_TOR	((volatile int *) (SSPORT_BASE_FOR_SPI+SSP_TIMEOUT))

/* SSP Status Register: (Offset: 0x14)*/
#define SSPORT_STS	((volatile int *) (SSPORT_BASE_FOR_SPI+SSP_STATUS))

#define     SPINAND_MAX_ID_LEN				4

struct spinand_device;

/**
 * struct nand_ecc_req - NAND ECC reqirement.
 * @strength: ECC strength
 * @step_size: ECC step/block size.
 */
struct nand_ecc_req {
	unsigned int strength;
	unsigned int step_size;
	unsigned int hw_ecc;
};

#define NAND_ECCREQ(str, stp, ecc)  \
	{			\
		.strength=(str), 	\
		.step_size=(stp),	\
               .hw_ecc=(ecc),   \
	}

/**
 * struct nand_memory_organization structures.
 * @bit_per_celi: number of bits per NAND celi.
 * @pagesize: page size
 * @oobsize: OOB area size
 * @pages_per_eraseblock: number of pages per eraseblock.
 * @eraseblocks_per_lun: number of eraseblocks per LUN(Logical Unit Number).
 * @max_bad_eraseblocks_per_lun: maxium number of eraseblocks per LUN.
 * @plans_per_lun:numbers of plans per LUN.
 * @luns_per_target: number of LUN
 * @ntarget: total number of target exposed bu the NAND device.
 */
struct nand_memory_organization {
	unsigned int bit_per_celi;
	unsigned int pagesize;
	unsigned int oobsize;
	unsigned int pages_per_eraseblock;
	unsigned int eraseblocks_per_lun;
	unsigned int max_bad_eraseblocks_per_lun;
	unsigned int planes_per_lun;
	unsigned int luns_per_target;
	unsigned int ntargets;
};

#define NAND_MEMORG(bpc, ps, os, ppe, epl, mbb, ppl, lpt, nt)	\
	{		\
		.bit_per_celi = (bpc),	\
		.pagesize = (ps),	\
		.oobsize = (os),		\
		.pages_per_eraseblock = (ppe),	\
		.eraseblocks_per_lun = (epl),	\
		.max_bad_eraseblocks_per_lun = (mbb),\
		.planes_per_lun = (ppl),		\
		.luns_per_target = (lpt),		\
		.ntargets = (nt),		\
	}		

/**
 * struct nand_device - NAND device.
 * @mtd: MTD instance attached to the NAND device.
 * @memorg: memory layout.
 * @eccreq: ECC Reqirement.
 */
struct nand_device {
	struct nand_memory_organization memorg;
	struct nand_ecc_req eccreq;
};

/**
 * struct spinand_id - SPI NAND id structurs.
 * @data: buffer containing the id bytes. Currently 4 bytes large.
 * @len: ID Length.
 */
struct spinand_id {
	unsigned char data[SPINAND_MAX_ID_LEN];
	unsigned int len;
};

enum spinand_readid_method {
	SPINAND_READID_METHOD_OPCODE,
	SPINAND_READID_METHOD_OPCODE_ADDR,
	SPINAND_READID_METHOD_OPCODE_DUMMY,
};

/** * struct spinand_devid - SPI NAND device id structure 
* @id: device id of current chip 
* @len: number of bytes in device id 
* @method: method to read chip id 
*	There are 3 possible variants: 
*	    SPINAND_READID_METHOD_OPCODE: chip id is returned immediately 
*	    after read_id opcode. 
*	    SPINAND_READID_METHOD_OPCODE_ADDR: chip id is returned after 
*	    read_id opcode + 1-byte address. 
*	    SPINAND_READID_METHOD_OPCODE_DUMMY: chip id is returned after 
*	    read_id opcode + 1 dummy byte. 
*/
struct spinand_devid{
	const unsigned char *id;
	const unsigned char len;
	const enum spinand_readid_method method;
};


#define SPINAND_ID(__method, ...)					\
	{								\
		.id = (const unsigned char[]){ __VA_ARGS__ },			\
		.len = sizeof((unsigned char[]){ __VA_ARGS__ }),			\
		.method = __method,					\
	}


/**
 * struct spinand_info - structture used to describe SPI NAND chips.
 * @model: model name
 * @devid: device id
 * @eccreq: ECC Reqirement.
 * @selcet_target: function used to select a target/die, Required only for
 		multi_dies.
 * Each SPI NAND manufaturer driver should have a spinand_info table
 * decribing all the chips supported by the driver.
 */ 
struct spinand_info {
	const char *model;
	struct spinand_devid devid;
	struct nand_memory_organization memorg;
	struct nand_ecc_req eccreq;
	int (*select_target)(struct spinand_device *spinand, unsigned int target);
};

								

#define SPINAND_SELECT_TARGET(__func)	\
	.select_target  = __func,
	
#define SPINAND_INFO(__model, __id, __memorg, __eccreq,   ...) \
	{						\
		.model = __model,		\
		.devid = __id,			\
		.memorg = __memorg,	\
		.eccreq = __eccreq,		\
		__VA_ARGS__			\
	}

/**
 * struct spinand_device - SPI NAND device instance
 * @base: NAND device instance.
 * @lock: lock used to serialize  accessed to the NAND.
 * @id: NAND ID as returned by READ_ID.
 * @select_target:select a specific target/die. Usually called before sending
 		a command addressing a page or an eraseblock embedded in this die.
 * @menufacturer: SPI NAND manufacturer informaition.
 */
struct spinand_device {
	struct nand_device base;
	struct spinand_id id;
	int (*select_target) (struct spinand_device *spinand, unsigned int cur_target);
	unsigned int cur_target;
	const struct spinand_manufacturer *manufacturer;
};

/**
 * struct manufacotuerer_ops - OPS NAND manufacturer specific operations
 * @init: initlization  a SPI NAND device
 * @cleanup: cleanup a SPI NAND devices
 * Each SPI NAND manufactuer driver should implement the interface so that
 * NAND chips coming form this vendor can be initilization properly.
 */
struct spinand_manufacturer_ops {
	int (*init)(struct spinand_device *spinand);
	int (*cleanup) (struct spinand_device *spinand);
	int (*check_ecc) (unsigned char val);
};


/**
 * struct spinand_manufacturer - SPI NAND manfacturer instance.
 * @id: manufacturer ID.
 * @name: manufacturer name.
 * @spinand_info: spinand info.
 * @nchips:
 * manufacturer_ops:
*/
struct spinand_manufacturer {
	unsigned char id;
	unsigned char *name;
	const struct spinand_info *chips;
	const unsigned int nchips;
	const struct spinand_manufacturer_ops *ops;
};

/* SPI NAND manufacturers	*/
extern const struct spinand_manufacturer winbond_spinand_manufacturer;
extern const struct spinand_manufacturer gigadevice_spinand_manufacturer;

/**
 * spinand_to_nand() - Get the SPI NAND device embedded in a SPI NAND object.
 * @spinand: SPI NAND device.
 * Returns: the NAND device.
*/
static inline struct nand_device * spinand_to_nand(struct spinand_device *spinand)
{
	return &spinand->base;
}

/**
 * nanddev_page_size() - Get NAND Page Size.
 * @spinand: SPI NAND device.
 * Returns: the page size.
*/
static inline unsigned int nanddev_page_size(const struct nand_device *nand)
{
	return nand->memorg.pagesize;
}

/**
 * nanddev_oobsize() - Get NAND Page Size.
 * @spinand: SPI NAND device.
 * Returns: the page size.
*/
static inline unsigned int nanddev_per_page_oobsize(const struct nand_device *nand)
{
	return nand->memorg.oobsize;
}

/**
 * nanddev_eraseblock_size() - Get NAND erase block Size.
 * @spinand: SPI NAND device.
 * Returns: the erase block size.
*/
static inline unsigned int nanddev_eraseblock_size(const struct nand_device *nand)
{
	return nand->memorg.pages_per_eraseblock * nand->memorg.pagesize ;
}


/**
 * nanddev_eraseblock_size() - Get NAND erase block Size.
 * @spinand: SPI NAND device.
 * Returns: the number of target/die used by us.
*/
static inline unsigned int nanddev_eraseblocks_per_target(const struct nand_device *nand)
{
	return (nand->memorg.luns_per_target *nand->memorg.eraseblocks_per_lun);
}


/**
 * nanddev_page_size() - Get total size  provided by a single target/die.
 * @spinand: SPI NAND device.
 * Returns: the total size per target/die.
*/
static inline unsigned long long  nanddev_target_size(const struct nand_device *nand)
{
	return (unsigned long long )nand->memorg.luns_per_target *
					nand->memorg.eraseblocks_per_lun *
					nand->memorg.pages_per_eraseblock *
					nand->memorg.pagesize;
}

/**
 * nanddev_size() - Get the total targets.
 * @spinand: SPI NAND device.
 * Returns: the total number.
*/
static inline unsigned int nanddev_ntargets(const struct nand_device *nand)
{
	return nand->memorg.ntargets;
}


/**
 * nanddev_size() - Get NAND Size.
 * @spinand: SPI NAND device.
 * Returns: the page size.
*/
static inline unsigned int nanddev_size(const struct nand_device *nand)
{
	return nanddev_target_size(nand) * nanddev_ntargets(nand);
}

struct SPINAND_ADDRESS_FIELDS
{
	unsigned int CA			:11;	
	unsigned int RA			:16;	
	unsigned int reserved		:5;		
};

typedef union
{
	unsigned int value;
	struct SPINAND_ADDRESS_FIELDS fields;
} SPINAND_ADDRESS_FIELD_T;
typedef enum 
{
    SPI_PIN_16_19,
    SPI_PIN_33_36,
}SPI_PIN;

unsigned int  SPINANDDevice_Init(unsigned char flashnu, FlashBootType_T flashbootType, unsigned char *P_DefaultPartitonNum);
unsigned int SPINAND_Read(unsigned int FlashOffset, unsigned int Buffer, 
					unsigned int Size, FlashBootType_T fbt);
unsigned int SPINAND_Write(unsigned int FlashOffset, unsigned int Buffer, 
						unsigned int Size, FlashBootType_T fbt);
unsigned int SPINAND_Erase(unsigned int FlashOffset, unsigned int Size, 
					FlashBootType_T fbt);
unsigned int SPINAND_Read_Page_SpareData(unsigned int FlashOffset, 
					unsigned int Buffer,  unsigned int size);
unsigned int SPINAND_Write_Page_SpareData(unsigned int FlashOffset, 
					unsigned int Buffer,  unsigned int size);
int quec_nand_spi_init(int spi_port,SPI_PIN spi_pin,SSP_Clock spi_clk);


#endif
