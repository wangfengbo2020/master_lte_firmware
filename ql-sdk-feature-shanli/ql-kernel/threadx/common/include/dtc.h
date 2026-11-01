/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

#ifndef _DTC_H_
#define _DTC_H_

// CQ00092184 begin
#if defined DTC_TEST_MODE
#define DTC_ENABLE_PRINTS
#endif
// CQ00092184 end
#include "dtc_config.h"
#ifdef UPGRADE_DTC_DRIVER

#include "global_types.h"

typedef unsigned char Int8;
typedef unsigned short Int16;
typedef unsigned long Int32;
typedef unsigned long long Int64; // CQ00092184 add

/////// MACROS for descriptor handling ///////
#define DTC_EXTRACT_HEADER_SIZE(reg) (((reg) >> 28) & 0xF)
#define DTC_EXTRACT_HEADER_DATA(reg,size) (  ((reg) << (32-(size))) >>  (32-(size)))
#define DTC_EXTRACT_CONT(reg) (((reg) >> 4) & 1)
#define DTC_EXTRACT_CB(reg) (((reg) >> 5) & 1)
#define DTC_EXTRACT_RCS(reg) (((reg) >> 6) & 1)
#define DTC_EXTRACT_CIPHER_OFFSET(reg) ((reg) & 7)
// CQ00092184 begin
#if defined (DTC_TEST_MODE)
#define DIR_BIT_OFFSET 11
#define DTC_TEST_MAX_CHAIN_LIST_SIZE  (255)
#define MAX_BYTE_SIZE_FOR_OUTPUT_IN_CONT_MODE (2000)
/**************************** Functions prototypes *****************************/
//CQ00096634 begin
#if defined (DTC_ENABLE_PRINTS)
void dtcTestPrintChainListArray(void);
#endif /* DTC_ENABLE_PRINTS */
#endif /* DTC_TEST_MODE */

#define DTC_EEA_BIT_IN_16BITS (0x8000)
#define DTC_DIR_BIT_OFFSET_IN_16BITS (11)
#define DTC_ALG_BIT_OFFSET_IN_16BITS (6)
#define DTC_TATA_BIT_LENGTH_MASK_IN_32BITS (0x0000ffff)
#define DTC_EXTRACT_SRC_BIT_OFFSET_FROM_DESCRIPTOR(A) ((A&0xffff0000)>>16)
#define DTC_EXTRACT_DST_BIT_OFFSET_FROM_DESCRIPTOR(A) (A&0x0000ffff)
#define DTC_EXTRACT_CB_BIT_FROM_DESCRIPTOR(A) ((A&0x2000) != 0)

#define DTC_CTRL_START_BIT_OFFSET (5)
#define DTC_CTRL_MODE_BIT_OFFSET (6)
#define DTC_SW_BYPASS_SET_COMMON_MODE(A) (A=A&0x07ffffff)
#define DTC_UNSET_ALG_16_BITS(A) (A=A&0xff3f)
#define DTC_CLEAR_CB_BIT_FROM_DESCRIPTOR(A) (A=A&0xdfff)


extern void dtcPrintHwRegisters(void);
// CQ00092184 end
//CQ00096634 end
enum
{
	DTC_HEADER_SIZE_PARAM_0 = 0,
	DTC_HEADER_SIZE_PARAM_1 = 4,
	DTC_HEADER_SIZE_PARAM_2 = 6,
	DTC_HEADER_SIZE_PARAM_3 = 8,
	DTC_HEADER_SIZE_PARAM_4 = 12,
	DTC_HEADER_SIZE_PARAM_5 = 14,
	DTC_HEADER_SIZE_PARAM_6 = 16,
	DTC_HEADER_SIZE_PARAM_7 = 20,
	DTC_HEADER_SIZE_PARAM_8 = 22,
// CQ00092184 begin
#if defined DTC_TEST_MODE	
	DTC_HEADER_SIZE_PARAM_9 = 24,
	DTC_HEADER_SIZE_PARAM_10 = 32,
#else
	DTC_HEADER_SIZE_PARAM_9 = 0,
	DTC_HEADER_SIZE_PARAM_10 = 0,
#endif
// CQ00092184 end	
	DTC_HEADER_SIZE_PARAM_11 = 0,
	DTC_HEADER_SIZE_PARAM_12 = 0,
	DTC_HEADER_SIZE_PARAM_13 = 0,
	DTC_HEADER_SIZE_PARAM_14 = 0,
	DTC_HEADER_SIZE_PARAM_15 = 0
};

enum
{
	DTC_CIPHER_OFFSET_PARAM_0 = 0,
	DTC_CIPHER_OFFSET_PARAM_1 = 4,
	DTC_CIPHER_OFFSET_PARAM_2 = 8,
	DTC_CIPHER_OFFSET_PARAM_3 = 12,
	DTC_CIPHER_OFFSET_PARAM_4 = 16,
	DTC_CIPHER_OFFSET_PARAM_5 = 20,
	DTC_CIPHER_OFFSET_PARAM_6 = 0,
	DTC_CIPHER_OFFSET_PARAM_7 = 0
};

////////////////////////////////////////////////////////

///////  I/F types ///////
enum dtcTransferEndStatusTag
{
	DTC_TRANSFER_END_SUCCESS, 
	DTC_TRANSFER_END_ERROR
};

typedef UINT8 DtcF8F9Select;
enum DtcF8F9SelectTag
{
    DTC_SELECT_F9 = 0,    
    DTC_SELECT_F8 = 2     
};

typedef UINT8 DtcDirection;
enum DtcDirectionTag
{
    DTC_DIR_UL = 0,    
    DTC_DIR_DL = 1     
};

typedef UINT8 DtcChainEndEvent;
enum 
{
	DTC_CEE_NONE = 0,
	DTC_CEE_TRIG_EDCH_HW = 8
};

typedef UINT8 DtcPriority;
enum 
{
	DTC_PRIORITY_NORMAL = 0,
	DTC_PRIORITY_HIGH = 1
};

typedef UINT8 DtcBlockingMode;
enum 
{
	DTC_MODE_BLOCKING = 0,
	DTC_MODE_NON_BLOCKING = 1
};

typedef enum 
{
	DTC_SUCCESS, 
	DTC_ERROR
} dtcReqStatus;

//CQ00096634 begin
typedef UINT8 DtcModeSelect;
enum 
{
	DTC_MODE_3G = 0,
	DTC_MODE_4G = 1
};
//CQ00096634 end

//#if defined (L1_UPGRADE_R7)
typedef UINT8 cipherType_te;
//CQ00092184 begin
//ICAT EXPORTED ENUM
enum 
{
#if defined (DTC_TEST_MODE)	
    UEA1_UIA1 = 0x0,
    UEA2_UIA2 = 0x20,
    EEA2_EIA2 = 0x40,
    EEA3_EIA3 = 0x80
#else
	UEA1_UIA1 = 0,
	UEA2_UIA2 = 0x40
#endif	
};
// CQ00092184 end
//#endif

//F8 descriptor
//ICAT EXPORTED STRUCT
typedef struct UdtcF8DescriptorTag
{
	struct UdtcF8DescriptorTag *next_p;
	UINT8	*srcData_p;
	UINT8	*dstData_p;
	UINT16	bitLength;
	UINT8 	bearer;
	UINT8	dtcModeReg;
	UINT32 	headerReg;
	UINT16 	dstBitOffset;
	UINT16 	srcBitOffset;
	UINT32 	countC;
	UINT8 	*key_p;
} dtcF8DescriptorInfo;

//F9 descriptor
//ICAT EXPORTED STRUCT
typedef struct UdtcF9DescriptorTag
{
	UINT32 	reserved0;
	UINT8	*srcData_p;
	UINT32	bitLength;
	UINT32 	fresh;
	UINT32 	countI;
	UINT8 	*key_p;
	UINT16 	srcBitOffset;
	UINT16 	reserved1;
	UINT32 	reserved2;
} dtcF9DescriptorInfo;

// CQ00092184 begin
#if defined DTC_TEST_MODE
//List Chain test info - the input type of chainList tests as in dtc_test_data.c. 
// holds up to 8 chains to request
//ICAT EXPORTED STRUCT
typedef struct dtcListChainTestInfoTag
{
	UINT16	listLength;
	UINT32	reserve[2];    
} dtcListChainTestInfo;
#endif
// CQ00092184 end 

//ICAT EXPORTED STRUCT
typedef struct dtcTransferEndTag
{
	UINT32 status;
	UINT32 macIF9Result;  
	UINT32 requestID;
} dtcTransferEnd_ts;



//ICAT EXPORTED STRUCT
typedef struct LteDtcDesTag
{
    struct LteDtcDesTag *next;   //pointer to the next description
    Int8        *dataPtr;           // Pointer to the source data address 
    Int8        *des_addr;          // Pointer to the destination data address 
    Int16       dataBitLen;
    Int16       shareBufPara;      // include Algorithom, Retain Cipher State, Cipher Bypass, RB ID, Bcontinued, Cipher Offset and isSrb(for RLC  mask 0x0800)
    Int32       headerAndFresh;      // include HDR size and Header Data 
    Int32       bitOffset;          // include input bit offset and output bit offset
    Int32       count;
    Int8        *key_addr;    
}LteDtcDes;


typedef void (*dtcTransferEndCallback)(dtcTransferEnd_ts *);
// CQ00092184 begin
#if defined DTC_TEST_MODE
//holds the test information about a chain in the list
//ICAT EXPORTED STRUCT
typedef struct dtcTestListChainInfoTag
{
    UINT32    testNum;
    dtcTransferEndCallback callback;    
    dtcTransferEnd_ts transferEndData;
} dtcTestListChainInfo;

// holds END info for all the list
//ICAT EXPORTED STRUCT
typedef struct dtcListTransferEndTag
{
    UINT8 chainListChRequestIndex; // holds the index for the next chain request in the list mode array (lteChainBaseAddressCh0) and the dtc list mode end array ChainListCh0EndInfo
    Int8 lastReportDoneIndexCh;  
    dtcTestListChainInfo chainInfo[DTC_TEST_MAX_CHAIN_LIST_SIZE];    
} dtcListTransferEnd_ts;
#endif /* DTC_TEST_MODE */
// CQ00092184 end
#if 0 
//Dtc request structure
typedef struct dtcTransferReqTag
{
	DtcF8F9Select		select;
	DtcChainEndEvent	cee;
	DtcPriority			priority;
	DtcBlockingMode		blockingMode;
	DtcDirection		dir;
	UINT8				reserved[3];
	UINT32				requestID;
	void *firstDescriptor_p;
	dtcTransferEndCallback	callback;
} dtcTransferReq_ts;
#endif

//ICAT EXPORTED STRUCT
typedef struct dtcTransferReqTag
{
	DtcF8F9Select		select;
	DtcChainEndEvent	cee;
	DtcPriority			priority;
	DtcBlockingMode		blockingMode;
	DtcDirection		dir;
//#if defined (L1_UPGRADE_R7)	
	cipherType_te		cipherAlgorithm;
	UINT8				reserved[2];
//#else
	//UINT8				reserved[3];
//#endif
	UINT32				requestID;
	void *firstDescriptor_p;
	dtcTransferEndCallback	callback;
} dtcTransferReq_ts;


//////////////////////////////////////////////////

/////// function prototype ///////

//generator I/F func
extern void             dtc
	(void *Desc_p,
	UINT32 *input_p,
	UINT32 *output_p,
	UINT8 *key_p,
	DtcDirection       dir,
	DtcF8F9Select		select
 );

extern void dtcF9CallbackFunction(dtcTransferEnd_ts *TransferEndData);

extern dtcReqStatus dtcTransferReq (dtcTransferReq_ts *dtcRequest);

extern void dtcPreF8TransferReq(UINT8 savedBuff[], UINT8 chainLen, dtcF8DescriptorInfo *firstF8Desc_p);

extern void dtcPostF8TransferReq(UINT8 savedBuff[], UINT8 chainLen, dtcF8DescriptorInfo *firstF8Desc_p);

extern dtcReqStatus dtcPahse1Init(void);

extern dtcReqStatus dtcPahse2Init(void);

extern dtcReqStatus InitDtc(void); //CQ00096760 modify
#ifndef	UPGRADE_DTC_SIMULATOR
extern void dtcSetDtcResetAfterRequest (UINT8 val);
void dtcD2Register(void);
#endif

#if defined (PHS_SW_DEMO_TTC)
#if 0
UINT32                    f9
    (UINT8                 * key_p,
     UINT32                  countI,
     UINT32                  fresh,
     UINT8             dir,
     UINT8                 * data_p,
     UINT16                  bitLength
    );
void f8(
	 UINT8				  * key_p,
	 UINT32					countC,
	 UINT32					bearer,
	 UINT8		 			dir,
	 UINT8				  * data_p,
	 UINT16					bitLength,
	 UINT16					bitOffset
	);
void f8Enhanced(
	 UINT8				  * key_p,
	 UINT32					countC,
	 UINT32					bearer,
	 UINT8		 			dir,
	 UINT8				  * srcData_p,
	 UINT8				  * dstData_p,
	 UINT16					bitLength,
	 UINT16					srcBitOffset,
	 UINT16					dstBitOffset
	);
#endif
#endif

#endif //UPGRADE_DTC_DRIVER

#endif
