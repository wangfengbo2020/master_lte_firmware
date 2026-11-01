/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
INTEL CONFIDENTIAL
Copyright 2006 Intel Corporation All Rights Reserved.
The source code contained or described herein and all documents related to the source code ("Material") are owned
by Intel Corporation or its suppliers or licensors. Title to the Material remains with Intel Corporation or
its suppliers and licensors. The Material contains trade secrets and proprietary and confidential information of
Intel or its suppliers and licensors. The Material is protected by worldwide copyright and trade secret laws and
treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted,
transmitted, distributed, or disclosed in any way without Intel's prior express written permission.

No license under any patent, copyright, trade secret or other intellectual property right is granted to or
conferred upon you by disclosure or delivery of the Materials, either expressly, by implication, inducement,
estoppel or otherwise. Any license under such intellectual property rights must be express and approved by
Intel in writing.
-------------------------------------------------------------------------------------------------------------------*/

/************************************************************************/
/*                                                                      */
/* Title: I2C pacakge header file                                       */
/*                                                                      */
/* Filename:  I2C.h                                                    */
/*                                                                      */
/* Authors: Adi Dayan                                                   */
/*                                                                      */
/* Target, subsystem: Common Platform, HAL                              */
/************************************************************************/
#ifndef _I2C_H_

  #define _I2C_H_
/*----------------------------------------------------------------------*/

#include "global_types.h"
#include "pmu.h"
#include "I2C_config.h"
#if defined _OSA_NUCLEUS_
#include "Osa.h"
#else
#include "nucleus.h"
#endif

/*----------------------------------------------------------------------*/

//void I2CMasterNotifyDataReceived(UINT8 *dataBuffPtr, UINT16 dataSize, UINT16 userId);
typedef void (*I2CMasterNotifyDataReceived)( UINT8 * , UINT16 , UINT16 );

//void I2CNotifyBusError(void);
typedef void (*I2CNotifyError)(UINT32);

typedef void (*I2CSendNotify)(UINT16);

/*----------------------------------------------------------------------*/


/********************* Sub-Package Definitions ********************/


#define I2C_ICR_REG_INIT_VALUE      0x000014E0   //all interrupts are disabled, except of the Bus Error and arbitration lost


typedef enum
{
    I2C_MODE_FAST    = 0x1,     // To use fast mode and repeat start make or operation with the two enums.
    I2C_REPEAT_START = 0x2
}I2C_SET_UP;

/*********************** Sub-Package Parameters *************************/


typedef enum
{
    SLOW_MODE_ENABLE = 0x00007fff,
    FAST_MODE_ENABLE = 0x00008000,
	FST_SLW_LNG_TYP  = 0x0FFFFFFF
}I2C_FAST_MODE;

typedef enum
{
    I2C_NOT_REPEAT_START_MODE 	= 0x00000001,
    I2C_REPEAT_START_MODE 		= 0x00000002
}I2C_REPEAT_START_CFG;



//ICAT EXPORTED ENUM
typedef enum
{
    I2C_RC_OK,
    I2C_RC_NOT_OK,
    I2C_RC_INVALID_DATA_SIZE,
    I2C_RC_INVALID_DATA_PTR,
    I2C_RC_TOO_MANY_REGISTERS,
    I2C_RC_TIMEOUT_ERROR,                               // 5
    I2C_RC_CHIP_BUSY,                                   // 6
    I2C_RC_INVALID_GENERAL_CALL_SLAVE_ADDRESS,          // 7
	I2C_RC_UNREGISTER_ERR,                              // 8
	I2C_RC_MESSAGE_QUEUE_IS_FULL,                       // 9
    I2C_ISR_UNEXPECTED_INTERRUPT,                       // 0xA
	I2C_ISR_BUS_ERROR,                                  // 0xB
	I2C_ISR_BUS_BUSY,                                   // 0xC
	I2C_ISR_EARLY_BUS_BUSY,                             // 0xD
	I2C_ISR_CALL_BACK_FUNCTION_ERR,                     // 0xE
	I2C_ISR_ARBITRATION_LOSS,                           // 0xF
	I2C_RC_ILLEGAL_USE_OF_API
}I2C_ReturnCode;


typedef struct
{
    I2CNotifyError 				callbackNotifyError;
    UINT16    					userId;
    UINT8 			  			slaveAddress;
}I2C_ErrorNotifyParams;


typedef struct
{
    UINT8 			  			scl;    	// i2c_clk
    UINT8 			  			sda; 		// i2c_data
}  I2C_IBMR;

typedef enum
{
    I2C_SLOW    = 0x0,
    I2C_FAST    = 0x1
}I2C_FAST_SLOW_SETUP;



/*************** Prototypes *****************/


/* This function is Using a task and UnBlocking ---  send by value */
I2C_ReturnCode I2CMasterSend( UINT8 			*data,
							  UINT16 			dataSize,
							  UINT8 			slaveAddress,
							  BOOL 				protected,
							  UINT16  			userId,
							  I2CSendNotify   	SendCallBack );

/* This function is Using a task and UnBlocking */
I2C_ReturnCode I2CMasterReceive( UINT8 			*cmd,
								 UINT16 		cmdLength,
								 UINT8 			writeSlaveAddress,
								 BOOL 			protected,
								 UINT8 			*designatedRxBufferPtr,
								 UINT16 		dataSize,
								 UINT8 			readSlaveAddress,
								 UINT16      	userId,
								 I2CMasterNotifyDataReceived   	ReadCallBack );

/* This function is Using a task and UnBlocking ---  send by referance */
I2C_ReturnCode I2CMasterSendByReferance ( UINT8             *data,
                                          UINT16            dataSize,
                                          UINT8             slaveAddress,
                                          BOOL              protected,
                                          UINT16            userId,
                                          I2CSendNotify     SendCallBack );



/* These two function are using a task and blocking */
I2C_ReturnCode I2CBlockingMasterSend ( UINT8        *data,
                                       UINT16       dataSize,
                                       UINT8        slaveAddress,
                                       BOOL         protected,
                                       UINT16       userId );

I2C_ReturnCode I2CBlockingMasterReceive(  UINT8              *cmd,
                                          UINT16             cmdLength,
                                          UINT8              writeSlaveAddress,
                                          BOOL               protected,
                                          UINT8              *designatedRxBufferPtr,
                                          UINT16             dataSize,
                                          UINT8              readSlaveAddress,
                                          UINT16             userId );


I2C_ReturnCode I2CUnRegister ( UINT16  		userId , UINT8 		  slaveAddress );
I2C_ReturnCode I2CRegister ( I2CNotifyError 		userCallbackNotifyError,
							 UINT16					userId,
							 UINT8 			  		slaveAddress );
I2C_ReturnCode I2CConfigure( I2C_FAST_MODE  fastMode , I2C_REPEAT_START_CFG rptStrt, UINT8 my_slave_add );
I2C_ReturnCode I2CControl( I2C_FAST_MODE 	fastMode );
void I2CPhase1Init(void);
void I2CPhase2Init(void);
//void I2CResetUnit(void);
I2C_ReturnCode I2CSlaveSetup( UINT8    slave_addr , UINT32     setup );

void I2CBusStateGetDirect ( I2C_IBMR   *i2c_ibmr );
I2C_ReturnCode I2CMasterSendDataDirect( UINT8 *data , UINT16 dataSize , UINT8 slaveAddress , BOOL protected , UINT16 userId );
I2C_ReturnCode I2CMasterReceiveDataDirect ( UINT8 						   *cmd,
											UINT16 	 						cmdLength,
											UINT8 							writeSlaveAddress,
											BOOL 		 					protected,
		                                    UINT8 						   *designatedRxBufferPtr,
											UINT16 	 						dataSize,
											UINT8 							readSlaveAddress );
I2C_ReturnCode CI2CMasterSendDataDirect( UINT8 *data , UINT16 dataSize , UINT8 slaveAddress , BOOL protected , UINT16 userId );
I2C_ReturnCode CI2CMasterReceiveDataDirect ( UINT8 						   *cmd,
											UINT16 	 						cmdLength,
											UINT8 							writeSlaveAddress,
											BOOL 		 					protected,
		                                    UINT8 						   *designatedRxBufferPtr,
											UINT16 	 						dataSize,
											UINT8 							readSlaveAddress );

typedef enum
{
	PMC_MICCO_C1,
    PMC_LEVANTE_A1,
    PMC_LEVANTE_B0,
    PMC_UNKNOWN,  //add new types before this line
    PMC_MAX = PMC_UNKNOWN
}LEVANTE_TYPE;

extern unsigned char  PMC_GetLevanteType(void);

#define PMC_TYPE_IS_MICCO              FALSE // (PMC_GetLevanteType() <= PMC_MICCO_C1)

#define PMC_TYPE_IS_LEVANTE_B0         TRUE  //   (PMC_GetLevanteType() == PMC_LEVANTE_B0)

#define CUSTOMER_IS_HUAWEI              FALSE // (bspGetBoardType() == CUSTOM_HUAWEI)

extern unsigned char PMC_I2C_WRITE_SLAVE_ADDRESS;
extern unsigned char PMC_I2C_READ_SLAVE_ADDRESS;


/*----------------------------------------------------------------------*/

#endif  /* _I2C_H_ */
