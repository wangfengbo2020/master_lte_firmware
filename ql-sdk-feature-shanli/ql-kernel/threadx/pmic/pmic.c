/*--------------------------------------------------------------------------------------------------------------------
(C) Copyright 2006, 2007 Marvell DSPC Ltd. All Rights Reserved.
-------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
INTEL CONFIDENTIAL
Copyright 2006 Intel Corporation All Rights Reserved.
The source code contained or described herein and all documents related to the source code (揗aterial? are owned
by Intel Corporation or its suppliers or licensors. Title to the Material remains with Intel Corporation or
its suppliers and licensors. The Material contains trade secrets and proprietary and confidential information of
Intel or its suppliers and licensors. The Material is protected by worldwide copyright and trade secret laws and
treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted,
transmitted, distributed, or disclosed in any way without Intel抯 prior express written permission.

No license under any patent, copyright, trade secret or other intellectual property right is granted to or
conferred upon you by disclosure or delivery of the Materials, either expressly, by implication, inducement,
estoppel or otherwise. Any license under such intellectual property rights must be express and approved by
Intel in writing.
-------------------------------------------------------------------------------------------------------------------*/

/*********************************************************************
*                      M O D U L E     B O D Y                       *
**********************************************************************
* Title: I2C package                                                 *
*                                                                    *
* Filename: I2C.c                                                    *
*                                                                    *
* Target, platform: Common Platform, HW platform                     *
*                                                                    *
* Authors: Adi Dayan                                                 *
*                                                                    *
* Description:                                                       *
*                                                                    *
* Notes:                                                             *
**********************************************************************/

/************* External include definitions ***************************/

/************************** MACROS ***************************************/
#include "osa.h"
#include "diag.h"
#include "ripc.h"

#include "PMChip.h"
#include "PMChip_nvm_harbell.h"  // for PMC_Nvm_File_t definition
#include "bsp.h"

#include "pmic.h"
#include "ningbo.h"
#include "guilin.h"
#include "guilin_lite.h"
#include "guilin_lite2.h"
#include "pmic_onkey.h"
#include "pmic_rtc.h"
#include "intc.h"
#include "rtc.h"
#include "intc_list.h"
#include "quec_cust_patch.h" //quectel add
#include "utilities.h"
#include "lfs_cache.h"
#include "UART.h"
#include "MRD.h"
#include "bsp_hisr.h"

//fix build warnning
#include "FreqChange.h"
#include "usb2_device.h"
#include "mvUsbDevApi.h"
#include "EE_silentReset.h"
#include "rtc_hw.h"

#include "dev_api.h" // quectel add
#include "quec_board_common.h"
#include "quec_debug.h"
#include "mfpr_api.h"
#include "gpio.h"


unsigned char pmic_id=PMIC_UNAVAILABLE;
/* I2C Semaphore reference. */
OSSemaRef I2CApp_SemaRef;

/************* External include definitions ***************************/
volatile unsigned long I2C_REGISTER_BASE_ADDR = 0xD4037000;
#define PMU_XCGR_READ	 			(( volatile UINT32 *)(0xD4051024))
#define I2C_FUN_CLK_ADD       		(( volatile UINT32 *)(0xD4051024))
#define I2C_APB_CLK_ADD				(( volatile UINT32 *)(0xD401502c))
#define PMU_XCGR_EN_I2C_FUN_CLK		((0x1 << 22) |(0x1 << 6))
#define I2C_APB_CLK_ENABLE			0x3
#define I2C_APB_RESET   			0x4

#define I2C_DEVICE_ERROR                        0xDEADBEEF
#define I2C_STATUS_ARRAY_SIZE                   4
#define I2C_RECORD_FLAG                         0x494E4954
#ifdef QUECTEL_PROJECT_CUST
#define PMIC_HISR_STACK_SIZE                    2048
#endif

/*********************** Sub-Package Parameters *************************/
/* I2C device status*/
typedef struct I2CDeviceStatus
{
    UINT32 RecordFlag;
    UINT32 BaseAddress;
    UINT32 SlaveAddress;
    UINT32 DeviceStatus;
} I2CDeviceStatus;

I2CDeviceStatus I2CStatusArray[I2C_STATUS_ARRAY_SIZE];

typedef void (*I2CMasterNotifyDataReceived)( UINT8 * , UINT16 , UINT16 );

typedef struct
{
    UINT8 							activeSlaveAddress;
    UINT8 							*RxBufferPtr;
    UINT16 							dataSize;
    UINT16 							ID;
	I2CMasterNotifyDataReceived 	callBack;
} I2C_ReceiveRequestParams;


static BOOL    _repeat_start = TRUE;

extern PMIC_RTC_OFFSET_STORAGE m_pmic_rtc_offset_storage_type;
static I2C_ReceiveRequestParams    _receiveReqParams;
extern UINT32    VbatTempEventSetFlag;
extern UINT8      TempReadResult[2];
extern UINT8      VbatReadResult[2];
extern UINT16	   TempmesurementAlignedValue;
extern UINT16	   VoltmesurementAlignedValue;
extern UINT32    TempMesurementvoltage;
extern UINT32    VbatMesurementvoltage;
extern UINT32    ThermisterValue;
extern UINT32    VbatMesurementvoltage_back;
extern UINT32	   RFtemprature_back;
extern UINT8	  Vbat_Temp_test_InitFlag;
extern Pmic_Int_Handler mNingboIntHandler[];
extern Pmic_Int_Handler mGuilinIntHandler[];
extern Pmic_Int_Handler mGuilinLiteIntHandler[];
extern Pmic_Int_Handler mGuilinLite2IntHandler[];
extern UINT8 check_if_DCS_mode(void);
extern BOOL m_rtc_update_alarm_expire_flag_app;//only for PM803L rtc expired which need be delay for 1S

extern PMC_Nvm_File_t   *nvmConfig;

extern BOOL Termistor_VCC_18V(void);
extern BOOL Is_LGE_LYRA_Board(void);

#ifdef LTEONLY_THIN
#define PMIC_DEBUG 0
#else
#define PMIC_DEBUG 1
#endif

#if PMIC_DEBUG
#define PMIC_UART_DEBUG(fmt,...) uart_printf(fmt, ##__VA_ARGS__)
#else
#define PMIC_UART_DEBUG(fmt,...)
#endif


static Pmic_Int_Handler mPmicIntHandler [PM812_INTC_MAX+1];
static UINT32 last_pmic_int_status;
UINT8 power_up_reason;
UINT8 power_down_reason;
UINT8 power_down_reason2;
#ifdef QUECTEL_PROJECT_CUST
UINT8 hot_power_flag;
#endif

extern PMIC_RTC_Setting m_pmic_rtc_setting;

#ifdef QUEC_3601_PMIC_PWRKEY_9374
extern int GetCfunValue(void);
extern void SetCfunValue(int value);
extern void wait_cfun_done(void);
#endif
#ifdef QUEC_1601_PM802_FPWM_ENABLE
extern void Guilin_VBUCK1_Set_FPWM( void );
#endif

/**********************************************************************************/
/******  These structures are use to send/received data by valye only    *********/

extern void ACIPCDAPLPMRequest(UINT32 request);
extern INT16 GetPm803VbatAdc(ADC_TEMP_t tempType);

#ifdef QUECTEL_PROJECT_CUST
#include "quec_board_common.h"
void QUEC_SET_MAINUART_TX_GPIO(void)
{
	unsigned long pin_mfprReg_data;
	GPIO_PinConfiguration gpio_pin_config;
	pin_mfprReg_data = *((volatile unsigned long *)(GPIO_MFPR_ADDR(UART1_TX_PIN_NUM)));
	pin_mfprReg_data = (pin_mfprReg_data & ~(0x07));  //fun0 is GPIO mode
	pin_mfprReg_data = (pin_mfprReg_data | (GPIO_BIT_PULL_SEL) | (GPIO_BIT_PULLUP)) & ~(GPIO_BIT_PULLDN); //set pull up
	*((volatile unsigned long *)(GPIO_MFPR_ADDR(UART1_TX_PIN_NUM))) = pin_mfprReg_data;

	GpioSetDirection(UART1_TX_PIN_NUM,GPIO_IN_PIN);
}
#endif
void ustica_I2CInit(void)
{
	*((volatile UINT32 *)0xd401E140) = 0xd0c2|1<<3|1<<9; //PMR_SCL ->CP_TWSI_SCL
	*((volatile UINT32 *)0xd401E144) = 0xd0c2|1<<3|1<<9; //PWR_SDA ->CP_TWSI_SDA
}

void ustica_I2CEnableclockandPin(void)
{
//    *(volatile unsigned long*)0xD4090104 |= 0x2; //enable PLL1_614 for PWIC I2C
	return;
}

static void ustica_I2CResetUnitDi ( void )
{
    UINT32  	 ICRRegValue;

	// Read the control register
	I2C_REG_READ(I2C_ICR_REG,ICRRegValue);

	ICRRegValue &= ~I2C_ICR_MASTER_ABORT;        // Clear the abort bit
  	ICRRegValue &= ~I2C_ICR_START;               // Clear the start bit
  	ICRRegValue &= ~I2C_ICR_STOP;                // Clear the stop bit
	ICRRegValue &= ~I2C_ICR_ACK_NACK_CONTROL;    // Clear the ACK bit
  	ICRRegValue &= ~I2C_ICR_TRANSFER_BYTE;       // Clear the transfer_byte bit


    // clear the ICR register
    I2C_REG_WRITE(I2C_ICR_REG, I2C_REG_CLEAR_VALUE);

    // Set the RESET bit in the ICR rewgister
    I2C_REG_BIT_WRITE(I2C_ICR_REG, I2C_ICR_UNIT_RESET_BIT, SET);

    // clear the ISR register after reset
    I2C_REG_WRITE(I2C_ISR_REG, I2C_ISR_CLEAR_ALL_INTERRUPTS);

    // Clear the RESET bit in the ICR rewgister
    I2C_REG_BIT_WRITE(I2C_ICR_REG, I2C_ICR_UNIT_RESET_BIT, CLEAR);

    // Restore the ICR register
    I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue);

}


void ustica_I2CConfigureDi( void )
{
    	UINT32 			controlRegValue = I2C_ICR_REG_INIT_VALUE;



		// reset the I2C unit
    	ustica_I2CResetUnitDi();

    	I2C_REG_WRITE(I2C_ILCR_REG, 0x082C469F); //~400K
    	I2C_REG_WRITE(I2C_IWCR_REG, 0x142A);
    	controlRegValue |= FAST_MODE_ENABLE;

    	I2C_REG_WRITE(I2C_ICR_REG, controlRegValue);

        I2C_REG_WRITE(I2C_ISAR_REG, I2C_OWN_SLAVE_ADDRESS);


}


/************************************************************************
* Function: i2cWaitStatusDirect
*************************************************************************
* Description:  - waits for specific status register value
*               - time is limited
*               - breaks when _error_was_detected indicates error detected by interrupt
*               - breaks when _arbitration_loss_was_detected indicates error detected by interrupt
*
* Parameters:   bitsSet     contains '1' where 1 is expected
*               bitsCleared contains '1' where 0 is expected
* Return value: I2C_RC_OK if got it or error code otherwise
*
* Notes:
************************************************************************/
static I2C_ReturnCode ustica_i2cWaitStatusDirect ( UINT32    bitsSet , UINT32    bitsCleared )
{


	UINT32 		statusRegValue;
    UINT32 		countLimit = LOOP_COUNTER_LIMIT;
	UINT32 		mask = bitsSet|bitsCleared;    // all bits we care of
	UINT32 		value = bitsSet;

	do
    {
        I2C_REG_READ(I2C_ISR_REG,statusRegValue);
        countLimit--;
    }
    while ( (( statusRegValue & mask ) != value ) &&
	        (!( I2C_REG_BIT_READ(statusRegValue, I2C_ISR_BUS_ERROR_DETECTED_BIT) ) &&
			(countLimit > 0) &&
			(!( I2C_REG_BIT_READ(statusRegValue, I2C_ISR_ARBITRATION_LOSS_DETECTED_BIT) )) ));

    if ( I2C_REG_BIT_READ(statusRegValue, I2C_ISR_ARBITRATION_LOSS_DETECTED_BIT) )
		return I2C_ISR_ARBITRATION_LOSS;

    // check for timeout, reset the I2C device for next operations and return error if needed
    if ( countLimit == 0 )
    {
		UINT32  ICRRegValue = 0;

		I2C_REG_READ(I2C_ICR_REG,ICRRegValue);
		ICRRegValue |= I2C_ICR_MASTER_ABORT;
		ICRRegValue &= ~I2C_ICR_TRANSFER_BYTE;
    	I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue );
    	return I2C_RC_TIMEOUT_ERROR;
	}
    else
	   if ( ( I2C_REG_BIT_READ(statusRegValue, I2C_ISR_BUS_ERROR_DETECTED_BIT) ))
	        return I2C_ISR_BUS_ERROR;

	return I2C_RC_OK;
}

/************************************************************************
* Function: masterSendDirect
*************************************************************************
* Description: This function is used to write data to I2C slaves in the
* 			   boot stage only while the OS system and INTC are not up.
*
* Parameters:
*
* Return value:
*
* Notes:
************************************************************************/
static I2C_ReturnCode ustica_masterSendDirect(UINT8 *data, UINT16 dataSize, UINT8 slaveAddress, BOOL repeatedStart , BOOL   MasterReceiveCalled )
{
    UINT32  		ICRRegValue = 0;
    int 			i;
	I2C_ReturnCode 	I2CReturnCode = I2C_RC_OK;



	/* Check the bus for free - If there is an arbitration loss, stay until it become free */
    do
	{
        // check if 'Arbitration Loss' was detected
       	if ( I2CReturnCode == I2C_ISR_ARBITRATION_LOSS )
		{
             I2C_STATUS_REG_CLEAR_BIT(I2C_ISR_ARBITRATION_LOSS_DETECTED_BIT);


			 // Read the control register
			 I2C_REG_READ(I2C_ICR_REG,ICRRegValue);

		  	 ICRRegValue &= ~I2C_ICR_START;               // Clear the start bit
		  	 ICRRegValue &= ~I2C_ICR_TRANSFER_BYTE;       // Clear the transfer_byte bit

    		 // Write to the ICR register
    		 I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue);

			 for ( i = 0; i < 50000; i++ );           	/* A little delay to enable others master to finish without interruption */
														/* the bus arbiter, and reduce the arbitration sequences */
		}

    	// write IDBR register: target slave address and R/W# bit=0 for write transaction.
    	I2C_REG_WRITE(I2C_IDBR_REG, I2C_SLAVE_WRITE(slaveAddress) );

    	// write ICR register: set START bit, clear STOP bit, set Transfer Byte bit to initiate the access
        I2C_REG_READ(I2C_ICR_REG,ICRRegValue);
		ICRRegValue &= ~I2C_ICR_STOP;
		ICRRegValue |= (I2C_ICR_START | I2C_ICR_TRANSFER_BYTE);
    	I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue );

	    I2CReturnCode = ustica_i2cWaitStatusDirect ( (I2C_REG_BIT(I2C_ISR_IDBR_TRANSMIT_EMPTY_BIT) | I2C_REG_BIT(I2C_ISR_UNIT_BUSY_BIT)),
			    	                     I2C_REG_BIT(I2C_ISR_READ_WRITE_MODE_BIT)  );

    	// clear 'IDBR Transmit Empty' bit (write '1')
    	I2C_STATUS_REG_CLEAR_BIT(I2C_ISR_IDBR_TRANSMIT_EMPTY_BIT);

		if ( ( I2CReturnCode != I2C_ISR_ARBITRATION_LOSS ) && ( I2CReturnCode != I2C_RC_OK ))
		{
        	I2C_REG_READ(I2C_ICR_REG,ICRRegValue);
			ICRRegValue &= 0xfff0;
   			I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue );

			return I2CReturnCode;
		}
    }
    // check if 'Arbitration Loss' was detected
	while ( I2CReturnCode == I2C_ISR_ARBITRATION_LOSS );

    // write ICR register: clear START bit, clear STOP bit
    I2C_REG_READ(I2C_ICR_REG,ICRRegValue);
  	ICRRegValue &= ~I2C_ICR_STOP;
  	ICRRegValue &= ~I2C_ICR_START;
   	I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue );

    /*** Send data bytes - all, except the last byte  ***/
    for ( i = 0; i < ( dataSize - 1 ); i++ )
    {
        // write data byte to the IDBR register
        I2C_REG_WRITE(I2C_IDBR_REG, *data);
        data++;

        // Set 'Tranfer Byte' bit to intiate the access
        I2C_REG_BIT_WRITE(I2C_ICR_REG, I2C_ICR_TRANSFER_BYTE_BIT, SET);

	    if((I2CReturnCode = ustica_i2cWaitStatusDirect(I2C_REG_BIT(I2C_ISR_IDBR_TRANSMIT_EMPTY_BIT)|I2C_REG_BIT(I2C_ISR_UNIT_BUSY_BIT),
				                          I2C_REG_BIT(I2C_ISR_READ_WRITE_MODE_BIT))) != I2C_RC_OK)
						return I2CReturnCode;

        // clear 'IDBR Transmit Empty' bit (write '1')
        I2C_STATUS_REG_CLEAR_BIT(I2C_ISR_IDBR_TRANSMIT_EMPTY_BIT);
    }


    /*** Send the last byte with STOP bit ***/

    // write the last data byte to the IDBR register
    I2C_REG_WRITE(I2C_IDBR_REG, *data);

    // write ICR: clear START bit
    I2C_REG_BIT_WRITE(I2C_ICR_REG, I2C_ICR_START_BIT, CLEAR);

    if (( repeatedStart == FALSE ) || ( MasterReceiveCalled == FALSE ))
        I2C_REG_BIT_WRITE(I2C_ICR_REG, I2C_ICR_STOP_BIT, SET);

    I2C_REG_BIT_WRITE(I2C_ICR_REG, I2C_ICR_TRANSFER_BYTE_BIT, SET);

//	if (repeatedStart)
//	{
//	  if ((I2CReturnCode = i2cWaitStatusDirect (I2C_REG_BIT(I2C_ISR_IDBR_TRANSMIT_EMPTY_BIT)|I2C_REG_BIT(I2C_ISR_UNIT_BUSY_BIT),
//	  	    	                          I2C_REG_BIT(I2C_ISR_READ_WRITE_MODE_BIT)))!=I2C_RC_OK)
//				return I2CReturnCode;
//	}
//    else
	  if ((I2CReturnCode = ustica_i2cWaitStatusDirect (I2C_REG_BIT(I2C_ISR_IDBR_TRANSMIT_EMPTY_BIT),
	                                      I2C_REG_BIT(I2C_ISR_READ_WRITE_MODE_BIT)))!=I2C_RC_OK)
				return I2CReturnCode;

	// clear 'IDBR Transmit Empty' bit (write '1')
    I2C_STATUS_REG_CLEAR_BIT(I2C_ISR_IDBR_TRANSMIT_EMPTY_BIT);
    I2C_REG_BIT_WRITE(I2C_ICR_REG, I2C_ICR_STOP_BIT, CLEAR);

    return I2C_RC_OK;
}


/************************************************************************
* Function: I2CBusStateGetDirect
*************************************************************************
* Description: This function is used to read the I2C Bus Monitor
* 			   Register - IBMR.
*
* Parameters:
*
* Return value:
*
* Notes:
************************************************************************/

/************************************************************************
* Function: I2CMasterSendDataDirect
*************************************************************************
* Description: This function is used to write data to I2C slaves in the
* 			   boot stage only while the OS system and INTC are not up.
*
* Parameters:
*
* Return value:
*
* Notes:
************************************************************************/
I2C_ReturnCode ustica_I2CMasterSendDataDirect( UINT8 *data , UINT16 dataSize , UINT8 slaveAddress , BOOL protected , UINT16 userId )
{
    UINT32 			XCGR_val;
    I2C_ReturnCode 	I2CReturnCode;
    BOOL 			chipBusy;

#if 0
    return I2C_RC_OK; //qianying, for FPGA ONLY

#ifndef EDEN_1928
	XCGR_val = *PMU_XCGR_READ;
	*I2C_FUN_CLK_ADD = XCGR_val | PMU_XCGR_EN_I2C_FUN_CLK;              //
	 if(AC_IS_CPONLY)
	 {
	 	*I2C_APB_CLK_ADD = I2C_APB_CLK_ENABLE;       //1920                       // I2c APB Clock ;I2c Functional Clock
	 }
#endif
#endif
    CHECK_IF_CHIP_BUSY(chipBusy);
    if ( chipBusy == TRUE )
        return I2C_RC_CHIP_BUSY;

    I2CReturnCode = ustica_masterSendDirect(data, dataSize, slaveAddress, _repeat_start , FALSE);
#if 0
#ifndef EDEN_1928
	if(!AC_IS_SHM)
    {
	    //clock off
		XCGR_val = *PMU_XCGR_READ;
		*I2C_FUN_CLK_ADD = XCGR_val &(~PMU_XCGR_EN_I2C_FUN_CLK);              //
		if(AC_IS_CPONLY)
		{
			XCGR_val = *I2C_APB_CLK_ADD;//1920
			*I2C_APB_CLK_ADD = XCGR_val & (~I2C_APB_CLK_ENABLE);                              // I2c APB Clock ;I2c Functional Clock
		}
	}
#endif
#endif
    return I2CReturnCode;
}
/************************************************************************/
/************************************************************************/
static UINT16 ustica_I2CIntLISRDirect ( void )
{
    UINT32 			statusRegValue , ICRRegValue = 0;



    //check interrupt source
    I2C_REG_READ(I2C_ISR_REG,statusRegValue);

    if ( I2C_REG_BIT_READ(statusRegValue, I2C_ISR_IDBR_RECEIVE_FULL_BIT) )
    {
        // clear 'IDBR Receive Full' bit (write '1')
        I2C_STATUS_REG_CLEAR_BIT(I2C_ISR_IDBR_RECEIVE_FULL_BIT);
        {

            // read the received byte
            I2C_REG_READ(I2C_IDBR_REG,*_receiveReqParams.RxBufferPtr);
            _receiveReqParams.RxBufferPtr++;
            _receiveReqParams.dataSize--;

            // write ICR: clear STOP bit(1), clear ACK/NACK bit(2)
    		I2C_REG_READ(I2C_ICR_REG,ICRRegValue);
			ICRRegValue &= ~I2C_ICR_STOP;
			ICRRegValue &= ~I2C_ICR_ACK_NACK_CONTROL;
    		I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue );


            if ( _receiveReqParams.dataSize > 1 )
            {
            	// write ICR: clear START bit, clear STOP bit, send ACK bit (0 for ACK),
				//             set Transfer Byte bit to initiate the access
    			I2C_REG_READ(I2C_ICR_REG,ICRRegValue);
				ICRRegValue &= ~I2C_ICR_START;
				ICRRegValue &= ~I2C_ICR_STOP;
				ICRRegValue &= ~I2C_ICR_ACK_NACK_CONTROL;
				ICRRegValue |= I2C_ICR_TRANSFER_BYTE;
    			I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue );
            }
            else if ( _receiveReqParams.dataSize == 1 ) //last byte remaing to read (with STOP signal)
            {
            	// write ICR: clear START bit, set STOP bit, send NACK bit (1 for NACK),
				//            set Transfer Byte bit to initiate the access
    			I2C_REG_READ(I2C_ICR_REG,ICRRegValue);
				ICRRegValue &= ~I2C_ICR_START;
				ICRRegValue |= (I2C_ICR_STOP | I2C_ICR_ACK_NACK_CONTROL | I2C_ICR_TRANSFER_BYTE);
    			I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue );
            }
            else
            {
        		// disable 'IDBR Buffer Full' interrupt
        		I2C_REG_BIT_WRITE(I2C_ICR_REG, I2C_ICR_IDBR_RECEIVE_FULL_INT_ENABLE_BIT, CLEAR);

            }
        }
    }

    if ( I2C_REG_BIT_READ(statusRegValue, I2C_ISR_BUS_ERROR_DETECTED_BIT) )
    {
        // clear 'Bus Error Detected' bit (write '1')
        I2C_STATUS_REG_CLEAR_BIT(I2C_ISR_BUS_ERROR_DETECTED_BIT);

    }

    if ( statusRegValue & I2C_ISR_UNEXPECTED_INTERRUPTS )
    {
        // clear 'I2C_ISR_UNEXPECTED_INTERRUPTS ' bits (write '1')
        I2C_REG_WRITE(I2C_ISR_REG,I2C_ISR_UNEXPECTED_INTERRUPTS);

    }

	return _receiveReqParams.dataSize;

}
/************************************************************************
* Function: I2CMasterReceiveDataDirect
*************************************************************************
* Description: This function is used to read data from I2C slaves in the
* 			   boot stage only while the OS system and INTC are not up.
*
* Parameters:
*
* Return value:
*
* Notes:
************************************************************************/
I2C_ReturnCode ustica_I2CMasterReceiveDataDirect ( UINT8 						   *cmd,
											UINT16 	 						cmdLength,
											UINT8 							writeSlaveAddress,
											BOOL 		 					protected,
		                                    UINT8 						   *designatedRxBufferPtr,
											UINT16 	 						dataSize,
											UINT8 							readSlaveAddress )
{
    UINT32 			XCGR_val;
    I2C_ReturnCode 	I2CReturnCode;
    UINT32 			ICRRegValue = 0;
    BOOL 			chipBusy;
	int             result;
    UINT32         countLimit = LOOP_COUNTER_LIMIT;
    // store the request parameters (to be used from the ISR and by the I2C task when error)
    _receiveReqParams.RxBufferPtr = designatedRxBufferPtr;
    _receiveReqParams.dataSize = dataSize;

#if 0
    return I2C_RC_OK; //qianying, for FPGA ONLY

    if ( dataSize == 0 )
        return I2C_RC_INVALID_DATA_SIZE;
#ifndef EDEN_1928

	XCGR_val = *PMU_XCGR_READ;
	*I2C_FUN_CLK_ADD = XCGR_val | PMU_XCGR_EN_I2C_FUN_CLK;              // I2c Functional Clock
	 if(AC_IS_CPONLY)
	{
		*I2C_APB_CLK_ADD = I2C_APB_CLK_ENABLE;                       //1920       // I2c APB Clock
	}
#endif
#endif
    CHECK_IF_CHIP_BUSY(chipBusy);
    if(chipBusy)
        return I2C_RC_CHIP_BUSY;

    if ( (cmdLength != 0) && (cmd != NULL) )  /* if command is associated with the received request */
    {
        I2CReturnCode = ustica_masterSendDirect(cmd, cmdLength, writeSlaveAddress, _repeat_start, TRUE);

        if( I2CReturnCode != I2C_RC_OK )
            return I2CReturnCode;
    }

    /*** send Read Request ***/
    // write IDBR: target slave address and R/W# bit (1 for read)
    I2C_REG_WRITE(I2C_IDBR_REG, I2C_SLAVE_READ(readSlaveAddress) );

    // write ICR: set START bit, clear STOP bit, set Transfer Byte bit to initiate the access
    I2C_REG_READ(I2C_ICR_REG,ICRRegValue);
	ICRRegValue &= ~I2C_ICR_STOP;
	ICRRegValue |= (I2C_ICR_START | I2C_ICR_TRANSFER_BYTE);
    I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue );

	I2CReturnCode = ustica_i2cWaitStatusDirect(I2C_REG_BIT(I2C_ISR_IDBR_TRANSMIT_EMPTY_BIT)|I2C_REG_BIT(I2C_ISR_UNIT_BUSY_BIT)|I2C_REG_BIT(I2C_ISR_READ_WRITE_MODE_BIT), 0 );

    // clear 'IDBR Transmit Empty' bit (write '1')
    I2C_STATUS_REG_CLEAR_BIT(I2C_ISR_IDBR_TRANSMIT_EMPTY_BIT);

	if ( I2CReturnCode != I2C_RC_OK )
        return I2CReturnCode;


    // Initiate the read process:

    if ( dataSize == 1 )   // only one byte to read
    {
        // write ICR: set STOP bit, set ACK/NACK bit (1 for NACK)
        I2C_REG_READ(I2C_ICR_REG,ICRRegValue);
  		ICRRegValue &= ~I2C_ICR_START;
  	    ICRRegValue |= (I2C_ICR_STOP | I2C_ICR_ACK_NACK_CONTROL);
   	    I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue );
    }
    else   // more than one byte to read
    {
        // write ICR: clear STOP bit, clear ACK/NACK bit (0 for ACK)
    	I2C_REG_READ(I2C_ICR_REG,ICRRegValue);
		ICRRegValue &= ~I2C_ICR_STOP;
		ICRRegValue &= ~I2C_ICR_ACK_NACK_CONTROL;
    	I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue );
    }

    I2C_REG_READ(I2C_ICR_REG,ICRRegValue);
  	ICRRegValue &= ~I2C_ICR_START;
  	ICRRegValue |= I2C_ICR_TRANSFER_BYTE;
   	I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue );

    while ( ustica_I2CIntLISRDirect() )
    {
       countLimit--;
    }

    if(countLimit ==0)
    {
       UINT32  ICRRegValue = 0;
       PMIC_UART_DEBUG("I2Ctimeout,reg=0x%x,slaveAddr=0x%x.\r\n",*cmd,writeSlaveAddress);

       I2C_REG_READ(I2C_ICR_REG,ICRRegValue);
       ICRRegValue |= I2C_ICR_MASTER_ABORT;
       ICRRegValue &= ~I2C_ICR_TRANSFER_BYTE;
       I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue );
       return I2C_RC_TIMEOUT_ERROR;
    }

    return I2C_RC_OK;
}

/*************************************************************************
* Function: I2CRecordDeviceStatus
*
* Descrioption
*   The function record I2C device status.
*
* Parameters:
*   Inputs  :
*       error: The I2C device status.
*       slaveAddress: The slave address of device.
*   Outputs:
*       N/A.
*
* Returns:
*       N/A.
*
* Notes:
*   N/A.
**************************************************************************/
BOOL I2CRecordDeviceStatus(UINT32 SlaveAddress, BOOL error)
{
    UINT8 i = 0;
    UINT32 cpsr = 0;
    BOOL status = FALSE;

    /*---------------------------------------------------------------------*/
    for ( i = 0; i < I2C_STATUS_ARRAY_SIZE; i++ )
    {
        cpsr = disableInterrupts();

        if ( I2C_RECORD_FLAG != I2CStatusArray[i].RecordFlag )
        {
            I2CStatusArray[i].RecordFlag = I2C_RECORD_FLAG;
            I2CStatusArray[i].BaseAddress = I2C_REGISTER_BASE_ADDR;
            I2CStatusArray[i].SlaveAddress = SlaveAddress;

            if(error)
            {
                I2CStatusArray[i].DeviceStatus = I2C_DEVICE_ERROR;
            }
            else
            {
                I2CStatusArray[i].DeviceStatus = 0;
            }

            status = TRUE;
        }

        restoreInterrupts(cpsr);
    }

    return status;
}

/*************************************************************************
* Function: I2CDeviceCheckStatus
*
* Descrioption
*   The function check the I2C device status.
*
* Parameters:
*   Inputs  :
*       slaveAddress: The slave address of decice.
*   Outputs:
*       N/A.
*
* Returns:
*       N/A.
*
* Notes:
*   N/A.
**************************************************************************/
BOOL I2CDeviceCheckStatus(UINT32 SlaveAddress)
{
    UINT8 i = 0;
    UINT32 cpsr = 0;
    BOOL status = TRUE;

    /*---------------------------------------------------------------------*/

    for ( i = 0; i < I2C_STATUS_ARRAY_SIZE; i++ )
    {
        cpsr = disableInterrupts();

        if (( I2CStatusArray[i].BaseAddress == I2C_REGISTER_BASE_ADDR )&&
            ( I2CStatusArray[i].SlaveAddress == SlaveAddress )&&
            ( I2CStatusArray[i].RecordFlag == I2C_RECORD_FLAG )&&
            ( I2CStatusArray[i].DeviceStatus == I2C_DEVICE_ERROR))
        {
            status = FALSE;
        }

        restoreInterrupts(cpsr);
    }

    return status;
} /* End at_client_get_callback_function() */

/*************************************************************************
* Function: MastI2CSend
*
* Descrioption
*   The i2c reading with not re-entery.
*
* Parameters:
*   Inputs  :
*       I2CAddr          : The address of device register.
*       slaveAddress     : The slave address of decice.
*   Outputs:
*       N/A.
*
* Returns:
*       RegData          : The data of reading from device register.
*
* Notes:
*   N/A.
**************************************************************************/
static I2C_ReturnCode MastI2CSend(UINT8 Slave_addr, UINT8 RegAddr, UINT8 RegData )
{
	UINT16      read_times = 0;
	UINT32      i = 0;
	volatile UINT32 ICRRegValue = 0;
	UINT8	    param_data[3] = {0};
	I2C_ReturnCode	status = I2C_RC_NOT_OK;

	param_data[0] = RegAddr;
	param_data[1] = RegData;
	param_data[2] = 0;

	status = ustica_I2CMasterSendDataDirect(param_data , 2 , Slave_addr , FALSE, 0 );

	read_times = 0;
	while ( status != I2C_RC_OK )
	{
		read_times ++;
    	if (read_times >= 3)
    	{
    	    PMIC_UART_DEBUG("Send: reset I2Cbus\r\n");

            I2C_REG_READ(I2C_ICR_REG,ICRRegValue);
            ICRRegValue |= I2C_ICR_BUS_RESET;
            I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue );

            do
            {
                I2C_REG_READ(I2C_ICR_REG,ICRRegValue);
            }while (ICRRegValue & I2C_ICR_BUS_RESET);

            PMIC_UART_DEBUG("Send: reset I2Cbus ends\r\n");
		}
		usticaInit();

		for( i = 0; i < 0x10000; i++ );                                 /* Short delay.             */

        status = ustica_I2CMasterSendDataDirect(param_data , 2 , Slave_addr , FALSE, 0 );

		if( read_times >= 6 )
		{
            PMIC_UART_DEBUG("\r\nMastI2CSend: 0x%x, Slave_addr = 0x%x, I2CRegAddr = 0x%x, RegData = 0x%x.\r\n",status, Slave_addr, RegAddr, RegData);
            #if PMIC_DEBUG
            DIAG_FILTER(HAL, PI2C, MastI2CSend1, DIAG_INFORMATION)
            diagPrintf("MastI2CSend: 0x%x, Slave_addr = 0x%x, I2CRegAddr = 0x%x, RegData = 0x%x.", status, Slave_addr, RegAddr, RegData);
            #endif
            break;
		}
	}

        return status;
}

/*************************************************************************
* Function: I2CMastReceive
*
* Descrioption
*   The i2c reading with not re-entery.
*
* Parameters:
*   Inputs  :
*       I2CAddr          : The address of device register.
*       slaveAddress     : The slave address of decice.
*   Outputs:
*       N/A.
*
* Returns:
*       RegData          : The data of reading from device register.
*
* Notes:
*   N/A.
**************************************************************************/
static UINT8 MastI2CReceive(UINT8 Slave_addr, UINT8 I2CRegAddr)
{
	UINT32      i = 0;
	volatile UINT32 ICRRegValue = 0;
	UINT16      read_times = 0;
	UINT8       I2CRegData = 0;
	I2C_ReturnCode	status = I2C_RC_NOT_OK;

	Slave_addr &=0xFE;
    status = ustica_I2CMasterReceiveDataDirect(  &I2CRegAddr,
                                    1 /*cmd lenght*/,
                                    Slave_addr,
                                    FALSE /*not protected*/,
                                    &I2CRegData,
                                    0x1,
                                    (Slave_addr|0x1));

	read_times = 0;
	while ( status != I2C_RC_OK )
	{
		read_times ++;
    	if (read_times >= 3)
    	{
    	    PMIC_UART_DEBUG("Rcv: reset I2Cbus\r\n");

            I2C_REG_READ(I2C_ICR_REG,ICRRegValue);
            ICRRegValue |= I2C_ICR_BUS_RESET;
            I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue );

            do
            {
                I2C_REG_READ(I2C_ICR_REG,ICRRegValue);
            }while (ICRRegValue & I2C_ICR_BUS_RESET);

            PMIC_UART_DEBUG("Rcv: reset I2Cbus ends\r\n");
    	}
		usticaInit();

		for(i=0;i<0x10000;i++);
        status = ustica_I2CMasterReceiveDataDirect(  &I2CRegAddr,
                                        1 /*cmd lenght*/,
                                        Slave_addr,
                                        FALSE /*not protected*/,
                                        &I2CRegData,
                                        0x1,
                                        (Slave_addr|0x1));
		if( read_times >= 6 )
		{
            PMIC_UART_DEBUG("\r\nMastI2CReceive: 0x%x, Slave_addr = 0x%x, I2CRegAddr = 0x%x.\r\n",status, Slave_addr, I2CRegAddr);
            #if PMIC_DEBUG
            DIAG_FILTER(HAL, PI2C, MastI2CReceive1, DIAG_INFORMATION)
            diagPrintf("MastI2CReceive: 0x%x, Slave_addr = 0x%x, I2CRegAddr = 0x%x.", status, Slave_addr, I2CRegAddr);
            #endif
            break;
		}
	}

	return I2CRegData;
}

/*************************************************************************
* Function: I2CSend
*
* Descrioption
*   The i2c writting with re-entery.
*
* Parameters:
*   Inputs  :
*       RegAddr          : The address of device register.
*       RegData          : The data of writing into device register.
*       slaveAddress     : The slave address of decice.
*   Outputs:
*       N/A.
*
* Returns:
*       N/A.
*
* Notes:
*   N/A.
**************************************************************************/
I2C_ReturnCode I2CSend( UINT8 Slave_addr, UINT8 RegAddr, UINT8 RegData )
{
    I2C_ReturnCode       res = I2C_RC_OK;
    OSA_STATUS  osaStatus  = OS_SUCCESS;

	if((OS_Current_Interrupt_Count() != 0)||
		CurrentThreadIsHISR())
	{
	    /* Lisr Or hisr */
		res = MastI2CSend(Slave_addr, RegAddr,RegData);
	}
	else
	{
	    /* task */
		osaStatus = OSASemaphoreAcquire(I2CApp_SemaRef, OS_SUSPEND);
	    ASSERT(osaStatus == OS_SUCCESS);

		res = MastI2CSend(Slave_addr, RegAddr,RegData);

		osaStatus = OSASemaphoreRelease(I2CApp_SemaRef);
	    ASSERT(osaStatus == OS_SUCCESS);
	}

	return res;
}


/*************************************************************************
* Function: I2CReceive
*
* Descrioption
*   The i2c reading with re-entery.
*
* Parameters:
*   Inputs  :
*       I2CAddr          : The address of device register.
*       slaveAddress     : The slave address of decice.
*   Outputs:
*       N/A.
*
* Returns:
*       RegData          : The data of reading from device register.
*
* Notes:
*   N/A.
**************************************************************************/
UINT8 I2CReceive(  UINT8 Slave_addr, UINT8 I2CRegAddr )
{
	UINT8       res = 0;
    OSA_STATUS  osaStatus = OS_SUCCESS;

	if((OS_Current_Interrupt_Count() != 0)||
		CurrentThreadIsHISR())
	{
	    /* LISR or Hisr */
		res = MastI2CReceive( Slave_addr, I2CRegAddr);
	}
	else
	{
	    /* Task */
		osaStatus = OSASemaphoreAcquire(I2CApp_SemaRef, OS_SUSPEND);
	    ASSERT(osaStatus == OS_SUCCESS);

		res = MastI2CReceive( Slave_addr, I2CRegAddr );

		osaStatus = OSASemaphoreRelease(I2CApp_SemaRef);
	    ASSERT(osaStatus == OS_SUCCESS);
	}

	return res;
}

void USTICAI2CWriteDi_base(unsigned char I2CRegAddr, unsigned char I2CRegData)
{
    I2CSend(PMC_I2C_WRITE_BASE_SLAVE_ADDRESS, I2CRegAddr, I2CRegData);
}
unsigned char USTICAI2CReadDi_base(unsigned char I2CRegAddr)
{
    return I2CReceive(PMC_I2C_WRITE_BASE_SLAVE_ADDRESS, I2CRegAddr);
}

void USTICAI2CWriteDi_power(unsigned char I2CRegAddr, unsigned char I2CRegData)
{
    I2CSend(PMC_I2C_WRITE_POWER_SLAVE_ADDRESS, I2CRegAddr, I2CRegData);
}
unsigned char USTICAI2CReadDi_power(unsigned char I2CRegAddr)
{
    return I2CReceive(PMC_I2C_WRITE_POWER_SLAVE_ADDRESS, I2CRegAddr);
}

void USTICAI2CWriteDi_GPADC(unsigned char I2CRegAddr, unsigned char I2CRegData)
{
    I2CSend(PMC_I2C_WRITE_GPADC_SLAVE_ADDRESS, I2CRegAddr, I2CRegData);
}
unsigned char USTICAI2CReadDi_GPADC(unsigned char I2CRegAddr)
{
    return I2CReceive(PMC_I2C_WRITE_GPADC_SLAVE_ADDRESS, I2CRegAddr);
}

void USTICAI2CWriteDi_TEST(unsigned char I2CRegAddr, unsigned char I2CRegData)
{
    I2CSend(PMC_I2C_WRITE_TEST_SLAVE_ADDRESS, I2CRegAddr, I2CRegData);
}

unsigned char USTICAI2CReadDi_TEST(unsigned char I2CRegAddr)
{
    return I2CReceive(PMC_I2C_READ_TEST_SLAVE_ADDRESS, I2CRegAddr);
}

void USTICAI2CWriteDi_AUDIO(unsigned char I2CRegAddr, unsigned char I2CRegData)
{
    I2CSend(PMC_I2C_WRITE_AUDIO_SLAVE_ADDRESS, I2CRegAddr, I2CRegData);
}
unsigned char USTICAI2CReadDi_AUDIO(unsigned char I2CRegAddr)
{
    return I2CReceive(PMC_I2C_WRITE_AUDIO_SLAVE_ADDRESS, I2CRegAddr);
}

void set_hp1n2(unsigned char enable)
{
	volatile unsigned char regval;

	regval = USTICAI2CReadDi_power(0xE2);
	regval &= ~(0x3<<4);
	regval |= (0x1<<4);
	USTICAI2CWriteDi_power(0xE2, regval);

	regval = USTICAI2CReadDi_AUDIO(0x01);
	if(enable)
		regval |= 0x1;
	else
		regval &= ~0x1;
	USTICAI2CWriteDi_AUDIO(0x01, regval);

	regval = USTICAI2CReadDi_AUDIO(0x26);
	if(enable)
		regval |= ((0x1 << 3) | (0x1 << 0));
	else
		regval &= ~((0x1 << 3) | (0x1 << 0));
	USTICAI2CWriteDi_AUDIO(0x26, regval);

}

void ustica_vbuck1_0_set(unsigned long value)
{
	PMIC_UART_DEBUG("ustica_vbuck1_0_set\r\n");
    USTICAI2CWriteDi_power(USTICA_VBUCK_1_SET_0_REG,value);
}
#ifdef LWIP_IPNETBUF_SUPPORT
extern void _usb_dci_vusb20_stop_transter(void);
#endif

volatile UINT32 USBphyRegOn = 0;
void ustica_USB_shutdown(void)
{
	volatile unsigned long regval;

	//uart_printf("ustica_USB_shutdown\r\n");
	USBphyRegOn = *(volatile unsigned long *)0xD428285C;
	regval =  *(volatile unsigned long *)0xD428285C;
	//regval &= ~((0x1<<5)|(0x1<<0));
	//regval |= ((0x1<<4)|(0x1<<1));
	regval &= ~(0x1<<3);
	*(volatile unsigned long *)0xD428285C = regval;


}
extern volatile UINT32              usb_shutdown;

void ustica_USB_turnOn(void)
{

	//uart_printf("ustica_USB_turnOn\r\n");
	if(USBphyRegOn != 0)
		*(volatile unsigned long *)0xD428285C = USBphyRegOn;
	usb_shutdown = 0;
}

#if !defined(NOT_SUPPORT_PM813)

extern void craneCommPMPowerupUsbPhy(void);
// ningBoUsbConnectCheck() that defined in ningbo_dm.c can implement the same/alike function
void PM813_VBUS_IS_DETECTED(void)
{
	if(GetUsbPmLock()==0)
	{
		SetUsbPmLock(1);
	}
    if (PMIC_READ_REG_BASE(NINGBO_STATUS_REG1) & NINGBO_VBUS_STATUS_BIT)
    {
    	ustica_USB_turnOn();
		craneCommPMPowerupUsbPhy();
    }
	else
	{
		SetUsbPmLock(0);
#ifdef LWIP_IPNETBUF_SUPPORT
        SetUsbEnumFlag(FALSE);
#endif
	}
}
void PM813_VBUS_int_test_callback()
{
	PM813_VBUS_IS_DETECTED();
}

void PM813_VBUS_INTC_ENABLE(BOOL onoff)
{
    onoff ? Ningbo_INT_ENABLE(NINGBO_VBUS_DET_INT): Ningbo_INT_DISABLE(NINGBO_VBUS_DET_INT);
}

//ICAT EXPORTED FUNCTION - SW_PLAT,PM812,VBUS_INTC_test
void PM813_VBUS_int()
{
	if (PMIC_IS_PM813())
	{
		Ningbo_INT_CALLBACK_REGISTER(NINGBO_VBUS_DET_INT, PM813_VBUS_int_test_callback);
		//PM812_VBUS_BIND_INTC(PM812_VBUS_int_test_callback);
		PM813_VBUS_INTC_ENABLE(TRUE);
	}
}
#endif

//ICAT EXPORTED FUNCTION - ADEMO,START_PS,usticaInit
void usticaInit(void)
{
	ustica_I2CEnableclockandPin();
	ustica_I2CConfigureDi();
}

void PM812_bk4clkfll_set_2m(void)
{
}


void PM812_PowerSave_Config(void)
{
}

void PM812_vbuck1_set_fpwm(void)
{
}

void PM812_vbuck4_set_fpwm(void)
{
}

void PM812_vbuck3_set_1_25(void)
{
}

void PM812_vbuck4_set_1_85(void)
{
}

void PM812_vbuck4_set_2_00(void)
{
}

void PM812_APT_enable(void)
{
}

void PM812_BUCK5_Enable(void)
{
}

static void PM812_LDO_Enable(int ldo_num,BOOL OnOff)
{
}

//(sleep vol & activate vol ) should set together to reduce PI2C operation times
static void PM812_LDO_VOUT_CFG(int addr,int act_vol,int slp_vol)
{
}

void PM812_Ldo_3_set_2_8(void)
{
}

void PM812_Ldo_3_set(BOOL OnOff)
{
}

void PM812_Ldo_4_set_1_8(void)
{
}

void PM812_Ldo_4_set_3_0(void)
{
}

void PM812_Ldo_4_set(BOOL OnOff)
{
}

void PM812_Ldo_10_set_1_8(void)
{
}
void PM812_Ldo_10_set_3_0(void)
{
}

void PM812_Ldo_10_set(BOOL OnOff)
{
}

void PM812_Ldo_12_set_1_8(void)
{
}

void PM812_Ldo_12_set_2_8(void)
{
}

void PM812_Ldo_12_set_3_0(void)
{
}

void PM812_Ldo_12_set(BOOL OnOff)
{
}

//add for mmi team 's request
unsigned int PM812_REG_DUMP(unsigned char page, unsigned char addr)
{

	unsigned char regval;
	int			result;

	UINT32  	 ICRRegValue;
	UINT32       ISARRegValue;

	result = Get_RIPC_ustica(3,200);
	if (result == RIPC_FAILURE)
		ASSERT(0);
	I2C_REG_READ(I2C_ICR_REG,ICRRegValue);
	I2C_REG_READ(I2C_ISAR_REG,ISARRegValue);

	ustica_I2CEnableclockandPin();
	ustica_I2CConfigureDi();

	switch(page){
	case PM812_BASE_PAGE_READ_SLAVE_ADDR:
		if(addr >= PM812_INT_STATUS_1_REG && addr <= PM812_INT_STATUS_4_REG){
			//PM812 INT STATUS was not allowed to read by this API
			ASSERT(0);
		}
		regval = USTICAI2CReadDi_base(addr);
		break;
	case PM812_POWER_PAGE_READ_SLAVE_ADDR:
		regval = USTICAI2CReadDi_power(addr);
		break;
	case PM812_GPADC_PAGE_READ_SLAVE_ADDR:
		regval = USTICAI2CReadDi_GPADC(addr);
		break;
	default:
		regval = 0;
	}

#if PMIC_DEBUG
	DIAG_FILTER(HAL, PM812, PM812_REG_DUMP, DIAG_INFORMATION)
	diagPrintf("[PM812_REG_DUMP] PAGE=%d , ADDR=0xx , val=0x%x",page,addr,regval);
#endif

	I2C_REG_WRITE(I2C_ISAR_REG,ISARRegValue);
	I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue);

	Release_RIPC_ustica(3);

	return regval;
}

void PM812_Ldo_5_set_3_1(void)
{
}

void PM812_Ldo_5_set(BOOL OnOff)
{
}

void PM812_Ldo_6_set_1_8(void)
{
}

void PM812_Ldo_6_set_2_8(void)
{
}

void PM812_Ldo_6_set(BOOL OnOff)
{
}

void PM812_Ldo_8_set_2_8(void)
{
}

void PM812_Ldo_8_set(BOOL OnOff)
{
}

void PM812_Ldo_9_set_1_8(void)
{
}

void PM812_Ldo_9_set(BOOL OnOff)
{
}

void PM812_Ldo_11_set_2_8(void)
{
}

void PM812_Ldo_11_set(BOOL OnOff)
{
}

void PM812_Ldo_13_set_2_8(void)
{
}

void PM812_Ldo_13_set(BOOL OnOff)
{
}

void PM812_Ldo_15_set_2_8(void)
{
}

void PM812_Ldo_15_set(BOOL OnOff)
{
}

void PM812_Ldo_16_set_2_8(void)
{
}

void PM812_Ldo_16_set(BOOL OnOff)
{
}

void PM812_Ldo_17_set_2_8(void)
{
}

void PM812_Ldo_17_set(BOOL OnOff)
{
}

void PM812_Ldo_18_set_1_8(void)
{
}

void PM812_Ldo_18_set(BOOL OnOff)
{
}

void PM812_Ldo_19_Config(void) //for RF power supply
{
}

void PM812SetLDO3OffOnSleep(void)
{
}

void PM812_32K_OUT2_Enable(void)
{
}

unsigned char GetPMICID(void)
{
	unsigned char regval;
    int result;
    UINT32  ICRRegValue;
    UINT32  ISARRegValue;

	result = Get_RIPC_ustica(3,200);
    if (result == RIPC_FAILURE)
	    ASSERT(0);

    I2C_REG_READ(I2C_ICR_REG,ICRRegValue);
    I2C_REG_READ(I2C_ISAR_REG,ISARRegValue);

    ustica_I2CEnableclockandPin();
    ustica_I2CConfigureDi();

    regval = USTICAI2CReadDi_base(0x00);

    I2C_REG_WRITE(I2C_ISAR_REG,ISARRegValue);
    I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue);
    Release_RIPC_ustica(3);

    PMIC_UART_DEBUG("PMIC_ID = 0x%x\r\n", regval);
	return regval;
}

//switch external 32k crystal oscillator
void PM812_RTC_USE_XO(void)
{
}

static void PI2C_WRITE_REG(UINT8 page,UINT8 addr, UINT8 value)
{
	switch(page)
	{
    	case PMC_I2C_WRITE_BASE_SLAVE_ADDRESS:
    		USTICAI2CWriteDi_base(addr,value);
    		break;
    	case PMC_I2C_WRITE_POWER_SLAVE_ADDRESS:
    		USTICAI2CWriteDi_power(addr,value);
    		break;
    	case PMC_I2C_WRITE_GPADC_SLAVE_ADDRESS:
    		USTICAI2CWriteDi_GPADC(addr,value);
    		break;
    	case PMC_I2C_WRITE_TEST_SLAVE_ADDRESS:
    		USTICAI2CWriteDi_TEST(addr,value);
    		break;
    	case PMC_I2C_WRITE_AUDIO_SLAVE_ADDRESS:
    		USTICAI2CWriteDi_AUDIO(addr,value);
    		break;
    	default:
    		ASSERT(0);
	}
	return;
}

static UINT8 PI2C_READ_REG(UINT8 page,UINT8 addr)
{
	UINT8   ret=0;

	switch(page)
	{
    	case PMC_I2C_READ_BASE_SLAVE_ADDRESS:
    		ret = USTICAI2CReadDi_base(addr);
    		break;
    	case PMC_I2C_READ_POWER_SLAVE_ADDRESS:
    		ret = USTICAI2CReadDi_power(addr);
    		break;
    	case PMC_I2C_READ_GPADC_SLAVE_ADDRESS:
    		ret = USTICAI2CReadDi_GPADC(addr);
    		break;
    	case PMC_I2C_READ_TEST_SLAVE_ADDRESS:
    		ret = USTICAI2CReadDi_TEST(addr);
    		break;
    	case PMC_I2C_READ_AUDIO_SLAVE_ADDRESS:
    		ret = USTICAI2CReadDi_AUDIO(addr);
    		break;
    	default:
    		ASSERT(0);
	}

	return ret;
}

void PMIC_WRITE_REG_GPADC(UINT8 addr, UINT8 value) {PI2C_WRITE_REG(PMC_I2C_WRITE_GPADC_SLAVE_ADDRESS,addr,value);}
UINT8 PMIC_READ_REG_GPADC(UINT8 addr) {return PI2C_READ_REG(PMC_I2C_READ_GPADC_SLAVE_ADDRESS,addr);}

void PMIC_WRITE_REG_POWER(UINT8 addr, UINT8 value) {PI2C_WRITE_REG(PMC_I2C_WRITE_POWER_SLAVE_ADDRESS,addr, value);}
UINT8 PMIC_READ_REG_POWER(UINT8 addr) {return PI2C_READ_REG(PMC_I2C_READ_POWER_SLAVE_ADDRESS,addr);}

void PMIC_WRITE_REG_BASE(UINT8 addr, UINT8 value) {PI2C_WRITE_REG(PMC_I2C_WRITE_BASE_SLAVE_ADDRESS,addr,value);}
UINT8 PMIC_READ_REG_BASE(UINT8 addr) {return PI2C_READ_REG(PMC_I2C_READ_BASE_SLAVE_ADDRESS,addr);}

void PMIC_WRITE_REG_TEST(UINT8 addr, UINT8 value) {PI2C_WRITE_REG(PMC_I2C_WRITE_TEST_SLAVE_ADDRESS,addr,value);}
UINT8 PMIC_READ_REG_TEST(UINT8 addr) {return PI2C_READ_REG(PMC_I2C_READ_TEST_SLAVE_ADDRESS,addr);}

void PMIC_WRITE_REG_AUDIO(UINT8 addr, UINT8 value) {PI2C_WRITE_REG(PMC_I2C_WRITE_AUDIO_SLAVE_ADDRESS,addr,value);}
UINT8 PMIC_READ_REG_AUDIO(UINT8 addr) {return PI2C_READ_REG(PMC_I2C_READ_AUDIO_SLAVE_ADDRESS,addr);}

static UINT32 PMIC_GET_RTC_REG_32(UINT8 start)
{
    COUNTER_32 cnt;

    cnt.cnt_8[0] = PMIC_READ_REG_BASE(start+0);
    cnt.cnt_8[1] = PMIC_READ_REG_BASE(start+1);
    cnt.cnt_8[2] = PMIC_READ_REG_BASE(start+2);
    cnt.cnt_8[3] = PMIC_READ_REG_BASE(start+3);

    return cnt.cnt_32;
}

static void PMIC_SET_RTC_REG_32(UINT8 start,UINT32 data)
{
    COUNTER_32 cnt;
    cnt.cnt_32 = data;

    PMIC_WRITE_REG_BASE(start+0 ,cnt.cnt_8[0]);
    PMIC_WRITE_REG_BASE(start+1 ,cnt.cnt_8[1]);
    PMIC_WRITE_REG_BASE(start+2 ,cnt.cnt_8[2]);
    PMIC_WRITE_REG_BASE(start+3 ,cnt.cnt_8[3]);
}

//power up / down log
static UINT8 PM812_GET_POWER_UP_LOG()
{
    switch (PMIC_ID_GET())
    {
        #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
            return PMIC_READ_REG_BASE(NINGBO_PWRUP_LOG_REG);
        #endif
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        case PMIC_802S:
            return PMIC_READ_REG_BASE(GUILIN_PWRUP_LOG_REG);
        #endif
        case PMIC_803:
            return PMIC_READ_REG_BASE(GUILIN_LITE_PWRUP_LOG_REG);
        case PMIC_803L:
            return PMIC_READ_REG_BASE(GUILIN_LITE2_PWRUP_LOG_REG);
        default:
            ASSERT(0);
            return 0;
    }
}
static void PM812_CLR_POWER_UP_LOG(UINT8 tmp)
{
    switch (PMIC_ID_GET())
    {
        #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
            PMIC_WRITE_REG_BASE(NINGBO_PWRUP_LOG_REG,tmp);
            break;
        #endif
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        case PMIC_802S:
            PMIC_WRITE_REG_BASE(GUILIN_PWRUP_LOG_REG,tmp);
            break;
        #endif
        case PMIC_803:
            PMIC_WRITE_REG_BASE(GUILIN_LITE_PWRUP_LOG_REG,tmp);
            break;
        case PMIC_803L:
            PMIC_WRITE_REG_BASE(GUILIN_LITE2_PWRUP_LOG_REG,tmp);
            break;
        default:
            ASSERT(0);
            break;
    }
}
static UINT8 PM812_GET_POWER_DOWN_LOG()
{
    switch (PMIC_ID_GET())
    {
        #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
            return PMIC_READ_REG_BASE(NINGBO_POWERDOWN_LOG_REG);
        #endif
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        case PMIC_802S:
            return PMIC_READ_REG_BASE(GUILIN_POWERDOWN_LOG_REG);
        #endif
        case PMIC_803:
            return PMIC_READ_REG_BASE(GUILIN_LITE_POWERDOWN_LOG_REG);
        case PMIC_803L:
            return PMIC_READ_REG_BASE(GUILIN_LITE2_POWERDOWN_LOG_REG);
        default:
            ASSERT(0);
            return 0;
    }
}

static void PM812_CLR_POWER_DOWN_LOG(UINT8 tmp)
{
    switch (PMIC_ID_GET())
    {
        #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
            PMIC_WRITE_REG_BASE(NINGBO_POWERDOWN_LOG_REG,tmp);
            break;
        #endif
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        case PMIC_802S:
            PMIC_WRITE_REG_BASE(GUILIN_POWERDOWN_LOG_REG,tmp);
            break;
        #endif
        case PMIC_803:
            PMIC_WRITE_REG_BASE(GUILIN_LITE_POWERDOWN_LOG_REG,tmp);
            break;
        case PMIC_803L:
            PMIC_WRITE_REG_BASE(GUILIN_LITE2_POWERDOWN_LOG_REG,tmp);
            break;
        default:
            ASSERT(0);
            break;
    }
}

static UINT8 PM812_GET_POWER_DOWN_LOG2()
{
    switch (PMIC_ID_GET())
    {
        #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
            return PMIC_READ_REG_BASE(NINGBO_POWERDOWN_LOG_REG2);
        #endif
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        case PMIC_802S:
            return PMIC_READ_REG_BASE(GUILIN_POWERDOWN_LOG_REG2);
        #endif
        case PMIC_803:
            return PMIC_READ_REG_BASE(GUILIN_LITE_POWERDOWN_LOG_REG2);
        case PMIC_803L:
            return PMIC_READ_REG_BASE(GUILIN_LITE2_POWERDOWN_LOG_REG2);
        default:
            ASSERT(0);
            return 0;
    }
}

static void PM812_CLR_POWER_DOWN_LOG2(UINT8 tmp)
{
    switch (PMIC_ID_GET())
    {
        #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
            PMIC_WRITE_REG_BASE(NINGBO_POWERDOWN_LOG_REG2,tmp);
            break;
        #endif
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        case PMIC_802S:
            PMIC_WRITE_REG_BASE(GUILIN_POWERDOWN_LOG_REG2,tmp);
            break;
        #endif
        case PMIC_803:
            PMIC_WRITE_REG_BASE(GUILIN_LITE_POWERDOWN_LOG_REG2,tmp);
            break;
        case PMIC_803L:
            PMIC_WRITE_REG_BASE(GUILIN_LITE2_POWERDOWN_LOG_REG2,tmp);
            break;
        default:
            ASSERT(0);
            break;
    }
}

//ICAT EXPORTED FUNCTION - SW_PLAT,PM812,DELAY_SW_PDOWN
void PM812_DELAY_SW_PDOWN()
{
    UINT8 tmp;
	//delay 4s for debug manul operation
	//e.g plug-out the USB to avoid EXTON_WU
	PMIC_UART_DEBUG("[%s] \r\n",__func__);

	OSATaskSleep(400);
    switch (PMIC_ID_GET())
    {
        #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
            tmp = PMIC_READ_REG_BASE(NINGBO_MISC_CFG_REG1);
            tmp |= NINGBO_SW_PDOWN_BIT;
            PMIC_WRITE_REG_BASE(NINGBO_MISC_CFG_REG1,tmp);
            break;
        #endif
        case PMIC_803:
            tmp = PMIC_READ_REG_BASE(GUILIN_LITE_WAKEUP_REG1);
            tmp |= GUILIN_LITE_SW_PDOWN_BIT;
            PMIC_WRITE_REG_BASE(GUILIN_LITE_WAKEUP_REG1,tmp);
            break;
        case PMIC_803L:
            tmp = PMIC_READ_REG_BASE(GUILIN_LITE2_WAKEUP_REG1);
            tmp |= GUILIN_LITE2_SW_PDOWN_BIT;
            PMIC_WRITE_REG_BASE(GUILIN_LITE2_WAKEUP_REG1,tmp);
            break;
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        case PMIC_802S:
            tmp = PMIC_READ_REG_BASE(GUILIN_WAKEUP_REG1);
            tmp |= GUILIN_SW_PDOWN_BIT;
            PMIC_WRITE_REG_BASE(GUILIN_WAKEUP_REG1,tmp);
            break;
        #endif
        default:
            ASSERT(0);
            break;
    }

}

void PM812_FAULT_WU_EN_ENABLE()
{
    UINT8 tmp;

    switch (PMIC_ID_GET())
    {
        #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
            tmp = PMIC_READ_REG_BASE(NINGBO_FAULT_WU_REG);
            tmp |= (NINGBO_FAULT_WU_ENABLE_BIT);
            PMIC_WRITE_REG_BASE(NINGBO_FAULT_WU_REG,tmp);
            break;
        #endif
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        case PMIC_802S:
            tmp = PMIC_READ_REG_BASE(GUILIN_FAULT_WU_REG);
            tmp |= (GUILIN_FAULT_WU_ENABLE_BIT);
            PMIC_WRITE_REG_BASE(GUILIN_FAULT_WU_REG,tmp);
            break;
        #endif
        case PMIC_803:
            tmp = PMIC_READ_REG_BASE(GUILIN_LITE_FAULT_WU_REG);
            tmp |= (GUILIN_LITE_FAULT_WU_ENABLE_BIT);
            PMIC_WRITE_REG_BASE(GUILIN_LITE_FAULT_WU_REG,tmp);
            break;
        case PMIC_803L:
            tmp = PMIC_READ_REG_BASE(GUILIN_LITE2_FAULT_WU_REG);
            tmp |= (GUILIN_LITE2_FAULT_WU_ENABLE_BIT);
            PMIC_WRITE_REG_BASE(GUILIN_LITE2_FAULT_WU_REG,tmp);
            break;
        default:
            ASSERT(0);
            break;
    }

}

void PM812_FAULT_WU_ENABLE()
{
    UINT8 tmp;

    switch (PMIC_ID_GET())
    {
        #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
        case PMIC_813A3:
            tmp = PMIC_READ_REG_BASE(NINGBO_FAULT_WU_REG);
            tmp |= (NINGBO_FAULT_WU_BIT);
            PMIC_WRITE_REG_BASE(NINGBO_FAULT_WU_REG,tmp);
            break;
        #endif
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        case PMIC_802S:
            tmp = PMIC_READ_REG_BASE(GUILIN_FAULT_WU_REG);
            tmp |= (GUILIN_FAULT_WU_BIT);
            PMIC_WRITE_REG_BASE(GUILIN_FAULT_WU_REG,tmp);
            break;
        #endif
        case PMIC_803:
            tmp = PMIC_READ_REG_BASE(GUILIN_LITE_FAULT_WU_REG);
            tmp |= (GUILIN_LITE_FAULT_WU_BIT);
            PMIC_WRITE_REG_BASE(GUILIN_LITE_FAULT_WU_REG,tmp);
            break;
        case PMIC_803L:
            tmp = PMIC_READ_REG_BASE(GUILIN_LITE2_FAULT_WU_REG);
            tmp |= (GUILIN_LITE2_FAULT_WU_BIT);
            PMIC_WRITE_REG_BASE(GUILIN_LITE2_FAULT_WU_REG,tmp);
            break;
        #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813S:
            tmp = PMIC_READ_REG_BASE(NINGBO_FAULT_WU_REG);
            tmp |= (NINGBO2_FAULT_WU_BIT);
            PMIC_WRITE_REG_BASE(NINGBO_FAULT_WU_REG,tmp);
            break;
        #endif
        default:
            ASSERT(0);
            break;
    }

}

void PM812_FAULT_WU_EN_DISABLE()
{
    UINT8 tmp;

    switch (PMIC_ID_GET())
    {
        #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
            tmp = PMIC_READ_REG_BASE(NINGBO_FAULT_WU_REG);
            tmp &= ~(NINGBO_FAULT_WU_ENABLE_BIT);
            PMIC_WRITE_REG_BASE(NINGBO_FAULT_WU_REG,tmp);
            break;
        #endif
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        case PMIC_802S:
            tmp = PMIC_READ_REG_BASE(GUILIN_FAULT_WU_REG);
            tmp &= ~(GUILIN_FAULT_WU_ENABLE_BIT);
            PMIC_WRITE_REG_BASE(GUILIN_FAULT_WU_REG,tmp);
            break;
        #endif
        case PMIC_803:
            tmp = PMIC_READ_REG_BASE(GUILIN_LITE_FAULT_WU_REG);
            tmp &= ~(GUILIN_LITE_FAULT_WU_ENABLE_BIT);
            PMIC_WRITE_REG_BASE(GUILIN_LITE_FAULT_WU_REG,tmp);
            break;
        case PMIC_803L:
            tmp = PMIC_READ_REG_BASE(GUILIN_LITE2_FAULT_WU_REG);
            tmp &= ~(GUILIN_LITE2_FAULT_WU_ENABLE_BIT);
            PMIC_WRITE_REG_BASE(GUILIN_LITE2_FAULT_WU_REG,tmp);
            break;
        default:
            ASSERT(0);
            break;
    }

}

void PMIC_PowerDown(void)
{
    UINT8 tmp;

	PMIC_UART_DEBUG("PDOWN!\r\n");

#ifdef LFS_USE_CACHE
    LfsMutexLock(TRUE);
    lfs_write_back_to_flash(FALSE, TRUE);
#endif

    PM812_FAULT_WU_EN_DISABLE();

    #if !defined(NOT_SUPPORT_PM813)
	if (PMIC_IS_PM813()||PMIC_IS_PM813S())
	{
    	PMIC_WRITE_REG_BASE(0x4C,0x0); //disable PWM
    	tmp = PMIC_READ_REG_BASE(NINGBO_MISC_CFG_REG1);
    	tmp |= NINGBO_SW_PDOWN_BIT;
    	PMIC_WRITE_REG_BASE(NINGBO_MISC_CFG_REG1,tmp);
	}
	#endif
}

//extern 	void set_diag_cache_flag(unsigned int val);

//ICAT EXPORTED FUNCTION - SW_PLAT,PM812,SW_PDOWN
void PM812_SW_PDOWN(void)
{
    UINT8 tmp;
	UINT32 callerAddress ;

#if defined(__ARMCC_VERSION)
	callerAddress= (__ARMCC_VERSION >= 200000) ? __return_address() : 0 ;  //  Keep first.
#else
	callerAddress = 0;
#endif

	RTI_LOG("SW_PDOWN @0x%x",callerAddress);

#ifdef AT_OVER_UART //workaround to remove extra 0x00 on cp uart tx when system power down
	if (IsChipCraneL()||IsChipCraneLS()||IsChipCraneLR()) 
	{
	  extern void PMIC_Set_CP_UART_PowerOff_and_AIB_3_3V(void);
	  PMIC_Set_CP_UART_PowerOff_and_AIB_3_3V();
	}
#endif

#ifdef LFS_USE_CACHE
    LfsMutexLock(TRUE);
    lfs_write_back_to_flash(FALSE, TRUE);
#endif

    if (PM812_CHARGER_IS_DETECTED())
    { //if charger attached, prepare to enter "powering-off charging"
        SysRestartReasonSet((SW_RESTART_REASON)'C');
    	PM812_FAULT_WU_EN_ENABLE();
    	PM812_FAULT_WU_ENABLE();
    }
    else
        PM812_FAULT_WU_EN_DISABLE();

    switch (PMIC_ID_GET())
    {
        #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
            PMIC_WRITE_REG_BASE(0x4C,0x0); //disable PWM
            tmp = PMIC_READ_REG_BASE(NINGBO_MISC_CFG_REG1);
            tmp |= NINGBO_SW_PDOWN_BIT;
            PMIC_WRITE_REG_BASE(NINGBO_MISC_CFG_REG1,tmp);
            break;
        #endif
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        case PMIC_802S:
            tmp = PMIC_READ_REG_BASE(GUILIN_WAKEUP_REG1);
            tmp |= GUILIN_SW_PDOWN_BIT;
            PMIC_WRITE_REG_BASE(GUILIN_WAKEUP_REG1,tmp);
            break;
        #endif
        case PMIC_803:
            tmp = PMIC_READ_REG_BASE(GUILIN_LITE_WAKEUP_REG1);
            tmp |= GUILIN_LITE_SW_PDOWN_BIT;
            PMIC_WRITE_REG_BASE(GUILIN_LITE_WAKEUP_REG1,tmp);
            break;
        case PMIC_803L:
            tmp = PMIC_READ_REG_BASE(GUILIN_LITE2_WAKEUP_REG1);
            tmp |= GUILIN_LITE2_SW_PDOWN_BIT;
            PMIC_WRITE_REG_BASE(GUILIN_LITE2_WAKEUP_REG1,tmp);
            break;
        default:
            ASSERT(0);
            break;
    }

}

//ICAT EXPORTED FUNCTION - SW_PLAT,PM812,SW_PDOWN_SLT
void PM812_SW_PDOWN_SLT()
{
    UINT8 tmp;
	UINT32 callerAddress ;

#if defined(__ARMCC_VERSION)
	callerAddress= (__ARMCC_VERSION >= 200000) ? __return_address() : 0 ;  //  Keep first.
#else
	callerAddress = 0;
#endif

	RTI_LOG("SW_PDOWN_SLT @0x%x",callerAddress);

#ifdef LFS_USE_CACHE
    LfsMutexLock(TRUE);
    lfs_write_back_to_flash(FALSE, TRUE);
#endif

    PM812_FAULT_WU_EN_DISABLE();

    switch (PMIC_ID_GET())
    {
        #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
            PMIC_WRITE_REG_BASE(0x4C,0x0); //disable PWM
            tmp = PMIC_READ_REG_BASE(NINGBO_MISC_CFG_REG1);
            tmp |= NINGBO_SW_PDOWN_BIT;
            PMIC_WRITE_REG_BASE(NINGBO_MISC_CFG_REG1,tmp);
            break;
        #endif
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        case PMIC_802S:
            tmp = PMIC_READ_REG_BASE(GUILIN_WAKEUP_REG1);
            tmp |= GUILIN_SW_PDOWN_BIT;
            PMIC_WRITE_REG_BASE(GUILIN_WAKEUP_REG1,tmp);
            break;
        #endif
        case PMIC_803:
            tmp = PMIC_READ_REG_BASE(GUILIN_LITE_WAKEUP_REG1);
            tmp |= GUILIN_LITE_SW_PDOWN_BIT;
            PMIC_WRITE_REG_BASE(GUILIN_LITE_WAKEUP_REG1,tmp);
            break;
        case PMIC_803L:
            tmp = PMIC_READ_REG_BASE(GUILIN_LITE2_WAKEUP_REG1);
            tmp |= GUILIN_LITE2_SW_PDOWN_BIT;
            PMIC_WRITE_REG_BASE(GUILIN_LITE2_WAKEUP_REG1,tmp);
            break;
        default:
            ASSERT(0);
            break;
    }

}

//ICAT EXPORTED FUNCTION - SW_PLAT,PM812,SW_RESET

#ifdef QUECTEL_PROJECT_CUST
extern void USB2MgrDeviceUnplug(void);
#endif

void PM812_SW_RESET(void)
{
    UINT8 tmp;
    UINT32 callerAddress ;

#if defined(__ARMCC_VERSION)
    callerAddress= (__ARMCC_VERSION >= 200000) ? __return_address() : 0 ;  //  Keep first.
#else
    callerAddress = 0;
#endif

    RTI_LOG("SW_RESET @0x%x",callerAddress);

#ifdef AT_OVER_UART //workaround to remove extra 0x00 on cp uart tx when system power down
    if (IsChipCraneL()||IsChipCraneLS()||IsChipCraneLR()) 
	{
	  extern void PMIC_Set_CP_UART_PowerOff_and_AIB_3_3V(void);
	  PMIC_Set_CP_UART_PowerOff_and_AIB_3_3V();
	}
#endif

#ifdef QUECTEL_PROJECT_CUST
	QUEC_SET_MAINUART_TX_GPIO();
    USB2MgrDeviceUnplug();
#endif

#ifdef LFS_USE_CACHE
    LfsMutexLock(TRUE);
    lfs_write_back_to_flash(FALSE, TRUE);
#endif
	//set FAULT_WU & FAULT_WU_EN
	//NOTICE : have to set these flag one by one
	PM812_FAULT_WU_EN_ENABLE();
	PM812_FAULT_WU_ENABLE();

	//SW_PDOWN
    switch (PMIC_ID_GET())
    {
        #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
            PMIC_WRITE_REG_BASE(0x4C,0x0); //disable PWM
            tmp = PMIC_READ_REG_BASE(NINGBO_MISC_CFG_REG1);
            tmp |= NINGBO_SW_PDOWN_BIT;
            PMIC_WRITE_REG_BASE(NINGBO_MISC_CFG_REG1,tmp);
            break;
        #endif
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        case PMIC_802S:
            tmp = PMIC_READ_REG_BASE(GUILIN_WAKEUP_REG1);
            tmp |= GUILIN_SW_PDOWN_BIT;
            PMIC_WRITE_REG_BASE(GUILIN_WAKEUP_REG1,tmp);
            break;
        #endif
        case PMIC_803:
            tmp = PMIC_READ_REG_BASE(GUILIN_LITE_WAKEUP_REG1);
            tmp |= GUILIN_LITE_SW_PDOWN_BIT;
            PMIC_WRITE_REG_BASE(GUILIN_LITE_WAKEUP_REG1,tmp);
            break;
        case PMIC_803L:
            tmp = PMIC_READ_REG_BASE(GUILIN_LITE2_WAKEUP_REG1);
            tmp |= GUILIN_LITE2_SW_PDOWN_BIT;
            PMIC_WRITE_REG_BASE(GUILIN_LITE2_WAKEUP_REG1,tmp);
            break;
        default:
            ASSERT(0);
            break;
    }
}

//ICAT EXPORTED FUNCTION - SW_PLAT,PM812,RESET_ALL
void PM812_RESET_ALL(void)
{
    UINT8 tmp;
	PMIC_UART_DEBUG("[%s] \r\n",__func__);

    switch (PMIC_ID_GET())
    {
        #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
            tmp = PMIC_READ_REG_BASE(NINGBO_MISC_CFG_REG1);
            tmp |= NINGBO_RESET_PMIC_BIT;
            PMIC_WRITE_REG_BASE(NINGBO_MISC_CFG_REG1,tmp);
            break;
        #endif
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        case PMIC_802S:
            tmp = PMIC_READ_REG_BASE(GUILIN_WAKEUP_REG1);
            tmp |= GUILIN_RESET_PMIC_BIT;
            PMIC_WRITE_REG_BASE(GUILIN_WAKEUP_REG1,tmp);
            break;
        #endif
        case PMIC_803:
            tmp = PMIC_READ_REG_BASE(GUILIN_LITE_WAKEUP_REG1);
            tmp |= GUILIN_LITE_RESET_PMIC_BIT;
            PMIC_WRITE_REG_BASE(GUILIN_LITE_WAKEUP_REG1,tmp);
            break;
        case PMIC_803L:
            tmp = PMIC_READ_REG_BASE(GUILIN_LITE2_WAKEUP_REG1);
            tmp |= GUILIN_LITE2_RESET_PMIC_BIT;
            PMIC_WRITE_REG_BASE(GUILIN_LITE2_WAKEUP_REG1,tmp);
            break;
        default:
            ASSERT(0);
            break;
    }
}

//[5:3] WD_TIMER_ACT
//WD_TIMER_SLP=8*WD_TIMER_ACT by default
void PM812_SET_WD_TIMEOUT_ACT(UINT8 input_timeout){
//TODO: should refactor pmic struct in ther furture
typedef enum {
	PMIC_WDT_8s,
	PMIC_WDT_16s,
	PMIC_WDT_32s,
	PMIC_WDT_64s,
	PMIC_WDT_256s
}PMIC_WD_TIMEOUT;

	UINT8 timeout = 0;
	UINT8 tmp = PMIC_READ_REG_BASE(PM812_WAKEUP_2_REG);
	tmp &= ~PM812_WD_TIMER_ACT_BITS;
	switch (input_timeout)
	{
		case  PMIC_WDT_8s:
			timeout = PM812_WD_TIMER_8s;
			break;
		case  PMIC_WDT_16s:
			timeout = PM812_WD_TIMER_16s;
			break;
		case  PMIC_WDT_32s:
			timeout = PM812_WD_TIMER_32s;
			break;
		case  PMIC_WDT_64s:
			timeout = PM812_WD_TIMER_64s;
			break;
		case  PMIC_WDT_256s:
			timeout = PM812_WD_TIMER_256s;
			break;
		default:
			ASSERT(0);
			break;
	}
	PMIC_WRITE_REG_BASE(PM812_WAKEUP_2_REG,(tmp|timeout));
}

void PM812_WD_RESET(void)
{
}

void PM812_WD_MODE(BOOL enable)
{
}

void PM812_WD_ENABLE(BOOL enable){
}

//RTC controller reg
//20200320@xiaoke implement RTC statemachine for pm802
UINT8 PM812_RTC_GET_CONTROL_REG(void)
{
    switch (PMIC_ID_GET())
    {
        #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
        	return PMIC_READ_REG_BASE(NINGBO_RTC_CTRL_REG);
        #endif
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        case PMIC_802S:
    	//20200320@xiaoke implement RTC statemachine for pm802
        	return PMIC_READ_REG_BASE(GUILIN_RTC_CTRL_REG);
        #endif
        case PMIC_803:
        	return 0;
        case PMIC_803L:
        	return PMIC_READ_REG_BASE(GUILIN_LITE2_RTC_CTRL_REG);
        default:
        	ASSERT(0);
    		return 0;
    }
}

//20200320@xiaoke implement RTC statemachine for pm802
void PM812_RTC_SET_CONTROL_REG(UINT8 ctl)
{
    switch (PMIC_ID_GET())
    {
        #if !defined(NOT_SUPPORT_PM813)
    	case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
        	PMIC_WRITE_REG_BASE(NINGBO_RTC_CTRL_REG,ctl);
    		break;
    	#endif
    	#if !defined(NOT_SUPPORT_PM802)
    	case PMIC_802:
        case PMIC_802S:
    		//20200320@xiaoke implement RTC statemachine for pm802
        	PMIC_WRITE_REG_BASE(GUILIN_RTC_CTRL_REG,ctl);
    		break;
        #endif
    	case PMIC_803:
    		break;
    	case PMIC_803L:
        	PMIC_WRITE_REG_BASE(GUILIN_LITE2_RTC_CTRL_REG,ctl);
    		break;
    	default:
    		ASSERT(0);
    		break;
    }
}

//rtc counter
//20200320@xiaoke implement RTC statemachine for pm802
UINT32 PM812_RTC_GET_32B_COUNTER(void)
{
    if (!check_if_DCS_mode() && !CHIP_IS_CRANELR)
    {
	return SCS_GetRtcCounter();
    }else{
	switch (PMIC_ID_GET())
	{
	    #if !defined(NOT_SUPPORT_PM813)
	    case PMIC_813:
	    case PMIC_813A3:
	    case PMIC_813S:
	    	return PMIC_GET_RTC_REG_32(NINGBO_RTC_COUNT_REG1);
	    #endif
	    #if !defined(NOT_SUPPORT_PM802)
	    case PMIC_802:
        case PMIC_802S:
	    	//20200320@xiaoke implement RTC statemachine for pm802
	    	return PMIC_GET_RTC_REG_32(GUILIN_RTC_COUNT_REG1);
	    #endif
	    case PMIC_803:
		//20200904@xiaoke for SCS mode (Single Crystal Scenario)
		return SCS_GetRtcCounter();
	    case PMIC_803L:
	    	return PMIC_GET_RTC_REG_32(GUILIN_LITE2_RTC_COUNT_REG1);
	    default:
	    	ASSERT(0);
	    	return 0;
	}
    }
}

UINT8 PMIC_RTC_USERDATA_REG(void)
{
    switch (PMIC_ID_GET())
    {
        #if !defined(NOT_SUPPORT_PM813)
    	case PMIC_813:
        case PMIC_813A3:
    		return NINGBO_RTC_USERDATA_SETTING_MARK_REG;
        case PMIC_813S:
            return NINGBO2_RTC_USERDATA_SETTING_MARK_REG;
        #endif
        #if !defined(NOT_SUPPORT_PM802)
    	case PMIC_802:
        case PMIC_802S:
    		return GUILIN_RTC_USERDATA_SETTING_MARK_REG;
        #endif
    	case PMIC_803:
		//20200904@xiaoke for PM803 userdata reg
    		return GUILIN_LITE_RTC_USERDATA_SETTING_MARK_REG;
	    case PMIC_803L:
	        return GUILIN_LITE2_RTC_USERDATA_SETTING_MARK_REG;
    	default:
    		ASSERT(0);
    		return 0;
    }
}

void PMIC_RTC_USERDATA_CFG_SET(UINT8 bit_mask,BOOL marked)
{
	UINT8 addr= PMIC_RTC_USERDATA_REG();
	UINT8 tmp = PMIC_READ_REG_BASE(addr);

	PMIC_UART_DEBUG("[%s]bit_mask=[%x],marked=[%x]\r\n",__func__,bit_mask,marked);

	if(marked){
		tmp |= bit_mask;
	}else{
		tmp &= (~bit_mask);
	}

	PMIC_WRITE_REG_BASE(addr,tmp);
}

BOOL PMIC_RTC_USERDATA_CFG_GET(UINT8 bit_mask)
{
	PMIC_UART_DEBUG("[%s] bit_mask=[%x] \r\n",__func__,bit_mask);
	return (PMIC_READ_REG_BASE(PMIC_RTC_USERDATA_REG()) & (bit_mask))?TRUE:FALSE;
}

//20190513@xiaokeweng : RTC_APP_OFFSET implement ++
//dof offset offset , the first 32bit of user data
//20200320@xiaoke implement RTC statemachine for pm802
UINT32 PM812_RTC_GET_32B_SYS_OFFSET(void)
{
    UINT32 tmp = 0;

    if(m_pmic_rtc_offset_storage_type == PMIC_RTC_OFFSET_IN_NVM)
    {
	    tmp = m_pmic_rtc_setting.pmic_rtc_setting_sys_offset;
    }else{
    switch (PMIC_ID_GET())
    {
        #if !defined(NOT_SUPPORT_PM813)
    	case PMIC_813:
        case PMIC_813A3:
        	tmp = PMIC_GET_RTC_REG_32(NINGBO_RTC_SYS_OFFSET_REG);
    		break;
        case PMIC_813S:
            tmp = PMIC_GET_RTC_REG_32(NINGBO2_RTC_SYS_OFFSET_REG);
            break;
        #endif
        #if !defined(NOT_SUPPORT_PM802)
    	case PMIC_802:
        case PMIC_802S:
        #endif
		//20200904@xiaoke for PM803 storage RTC_OFFSET into NVM follow PM802
        case PMIC_803:
        case PMIC_803L:
    		//20200706@xiaokeweng : for PM802 switch the storage of RTC_OFFSET from PMIC-regs into NVM
    		//store sys_offset/app_offset/timezone pmic_rtc config into NVM but the pmic-userdata-regs
        	tmp = m_pmic_rtc_setting.pmic_rtc_setting_sys_offset;
    		break;
    	default:
    		ASSERT(0);
    		break;
    }
    }
    return tmp;

}
void PM812_RTC_SET_32B_SYS_OFFSET(UINT32 offset)
{
    if(m_pmic_rtc_offset_storage_type == PMIC_RTC_OFFSET_IN_NVM)
    {
    	m_pmic_rtc_setting.pmic_rtc_setting_sys_offset=offset;
    	pmic_rtc_setting_save();
    }else{
    switch (PMIC_ID_GET())
    {
        #if !defined(NOT_SUPPORT_PM813)
    	case PMIC_813:
        case PMIC_813A3:
    		return PMIC_SET_RTC_REG_32(NINGBO_RTC_SYS_OFFSET_REG,offset);
        case PMIC_813S:
            return PMIC_SET_RTC_REG_32(NINGBO2_RTC_SYS_OFFSET_REG,offset);
        #endif
        #if !defined(NOT_SUPPORT_PM802)
    	case PMIC_802:
        case PMIC_802S:
        #endif
        case PMIC_803:
        case PMIC_803L:
    		//20200706@xiaokeweng : for PM802 switch the storage of RTC_OFFSET from PMIC-regs into NVM
    		//store sys_offset/app_offset/timezone pmic_rtc config into NVM but the pmic-userdata-regs
    		m_pmic_rtc_setting.pmic_rtc_setting_sys_offset=offset;
    		pmic_rtc_setting_save();
    		break;
    	default:
    		ASSERT(0);
			break;
    }
    }
}
//mmi application offset , the 2nd 32bit of user data
UINT32 PM812_RTC_GET_32B_APP_OFFSET(void)
{
    UINT32 tmp = 0;

    if(m_pmic_rtc_offset_storage_type == PMIC_RTC_OFFSET_IN_NVM)
    {
	    tmp = m_pmic_rtc_setting.pmic_rtc_setting_app_offset;
    }else{
    switch (PMIC_ID_GET())
    {
        #if !defined(NOT_SUPPORT_PM813)
    	case PMIC_813:
        case PMIC_813A3:
    	    tmp = PMIC_GET_RTC_REG_32(NINGBO_RTC_APP_OFFSET_REG);
    	    break;
        case PMIC_813S:
            tmp = PMIC_GET_RTC_REG_32(NINGBO2_RTC_APP_OFFSET_REG);
            break;
        #endif
        #if !defined(NOT_SUPPORT_PM802)
    	case PMIC_802:
        case PMIC_802S:
        #endif
        case PMIC_803:
        case PMIC_803L:
    	    //20200706@xiaokeweng : for PM802 switch the storage of RTC_OFFSET from PMIC-regs into NVM
    	    //store sys_offset/app_offset/timezone pmic_rtc config into NVM but the pmic-userdata-regs
    	    tmp = m_pmic_rtc_setting.pmic_rtc_setting_app_offset;
            break;
    	default:
    		ASSERT(0);
    		break;
    }
    }
    return tmp;
}

void PM812_RTC_SET_32B_APP_OFFSET(UINT32 offset)
{
    if(m_pmic_rtc_offset_storage_type == PMIC_RTC_OFFSET_IN_NVM)
    {
	    m_pmic_rtc_setting.pmic_rtc_setting_app_offset=offset;
	    pmic_rtc_setting_save();
    }else{
    switch (PMIC_ID_GET())
    {
        #if !defined(NOT_SUPPORT_PM813)
    	case PMIC_813:
        case PMIC_813A3:
        	PMIC_SET_RTC_REG_32(NINGBO_RTC_APP_OFFSET_REG,offset);
    		break;
        case PMIC_813S:
            PMIC_SET_RTC_REG_32(NINGBO2_RTC_APP_OFFSET_REG,offset);
            break;
        #endif
        #if !defined(NOT_SUPPORT_PM802)
    	case PMIC_802:
        case PMIC_802S:
        #endif
		//20200904@xiaoke for PM803 storage RTC_OFFSET into NVM follow PM802
        case PMIC_803:
        case PMIC_803L:
    		//20200706@xiaokeweng : for PM802 switch the storage of RTC_OFFSET from PMIC-regs into NVM
    		//store sys_offset/app_offset/timezone pmic_rtc config into NVM but the pmic-userdata-regs
    		m_pmic_rtc_setting.pmic_rtc_setting_app_offset=offset;
    		pmic_rtc_setting_save();
    		break;
    	default:
    		ASSERT(0);
    		break;
    }
    }
}
//20190513@xiaokeweng : RTC_APP_OFFSET implement --
//RTC EXPIRE
UINT32 PM812_RTC_GET_32B_EXPIR_1(void)
{
    if (!check_if_DCS_mode() && !CHIP_IS_CRANELR)
    {
	return SCS_GetRtcAlarm();
    }else{
	switch (PMIC_ID_GET())
	{
	    #if !defined(NOT_SUPPORT_PM813)
	    case PMIC_813:
	    case PMIC_813A3:
	    case PMIC_813S:
	        return PMIC_GET_RTC_REG_32(NINGBO_RTC_EXPIRE1_REG1);
	    #endif
	    #if !defined(NOT_SUPPORT_PM802)
	    case PMIC_802:
        case PMIC_802S:
	    	return PMIC_GET_RTC_REG_32(GUILIN_RTC_EXPIRE1_REG1);
	    #endif
	    case PMIC_803:
		//20200904@xiaoke for SCS mode (Single Crystal Scenario)
		return SCS_GetRtcAlarm();
	    case PMIC_803L:
	    	return PMIC_GET_RTC_REG_32(GUILIN_LITE2_RTC_EXPIRE_REG1);
	    default:
	    	ASSERT(0);
	    	return 0;
	}
    }
}
//20190513@xiaokeweng : RTC_APP_OFFSET implement ++
#if 0
UINT32 PM812_RTC_GET_32B_EXPIR_2()
{
    if (PMIC_IS_PM812())
    	return PMIC_GET_RTC_REG_32(PM812_RTC_EXPIRE2_1_reg);
    else
        return PMIC_GET_RTC_REG_32(NINGBO_RTC_EXPIRE2_REG1);

}
#endif
//20190513@xiaokeweng : RTC_APP_OFFSET implement --
void PM812_RTC_SET_32B_EXPIR_1(UINT32 expir)
{
    if (!check_if_DCS_mode() && !CHIP_IS_CRANELR)
    {
	    SCS_SetRtcAlarm(expir);
    }else{
	    switch (PMIC_ID_GET())
	    {
	    #if !defined(NOT_SUPPORT_PM813)
		case PMIC_813:
		case PMIC_813A3:
		case PMIC_813S:
		    PMIC_SET_RTC_REG_32(NINGBO_RTC_EXPIRE1_REG1,expir);
			break;
		#endif
		#if !defined(NOT_SUPPORT_PM802)
		case PMIC_802:
        case PMIC_802S:
			PMIC_SET_RTC_REG_32(GUILIN_RTC_EXPIRE1_REG1,expir);
		    break;
		#endif
		case PMIC_803:
		    //20200904@xiaoke for SCS mode (Single Crystal Scenario)
		    SCS_SetRtcAlarm(expir);
			break;
	    case PMIC_803L:
			PMIC_SET_RTC_REG_32(GUILIN_LITE2_RTC_EXPIRE_REG1,expir);
			if(m_rtc_update_alarm_expire_flag_app == TRUE)
			{	
				OSATaskSleep(200); //ensure the EXPIRE regs updated
				m_rtc_update_alarm_expire_flag_app = FALSE;
			}
	        break;
		default:
			ASSERT(0);
			break;
	    }
    }

	#ifdef SCS_BUT_WITHOUT_ALARM_IO_PAD
	internal_rtc_alarm_update();
	#endif//SCS_BUT_WITHOUT_ALARM_IO_PAD

    PM812_DUMP_STATE();
}

//20190513@xiaokeweng : RTC_APP_OFFSET implement ++
#if 0
void PM812_RTC_SET_32B_EXPIR_2(UINT32 expir)
{
    if (PMIC_IS_PM812())
    	return PMIC_SET_RTC_REG_32(PM812_RTC_EXPIRE2_1_reg,expir);
	else if (PMIC_IS_PM802())
		return PMIC_SET_RTC_REG_32(GUILIN_RTC_EXPIRE2_REG1,expir);
    else
        return PMIC_SET_RTC_REG_32(NINGBO_RTC_EXPIRE2_REG1,expir);

}
#endif
//20190513@xiaokeweng : RTC_APP_OFFSET implement --
void PM812_RTC_ENABLE_EXPIR_1(void)
{
    UINT8 tmp;

    if (!check_if_DCS_mode() && !CHIP_IS_CRANELR)
    {
        SCS_EnableAlarm();
    }else{
	switch (PMIC_ID_GET())
	{
	    #if !defined(NOT_SUPPORT_PM813)
	    case PMIC_813:
	    case PMIC_813A3:
	    case PMIC_813S:
	        tmp = PMIC_READ_REG_BASE(NINGBO_RTC_CTRL_REG);
	        tmp |= NINGBO_RTC_ALARM_SET1_BIT;
	        PMIC_WRITE_REG_BASE(NINGBO_RTC_CTRL_REG,tmp);
	    	break;
	    #endif
	    #if !defined(NOT_SUPPORT_PM802)
	    case PMIC_802:
        case PMIC_802S:
	        tmp = PMIC_READ_REG_BASE(GUILIN_RTC_CTRL_REG);
	        tmp |= GUILIN_RTC_ALARM_SET1_BIT;
	        PMIC_WRITE_REG_BASE(GUILIN_RTC_CTRL_REG,tmp);
	        break;
	    #endif
	    case PMIC_803:
		//20200904@xiaoke for SCS mode (Single Crystal Scenario)
		SCS_EnableAlarm();
	    	break;
	    case PMIC_803L:
	        tmp = PMIC_READ_REG_BASE(GUILIN_LITE2_RTC_CTRL_REG);
	        tmp |= GUILIN_LITE2_RTC_ALARM_SET_BIT;
	        PMIC_WRITE_REG_BASE(GUILIN_LITE2_RTC_CTRL_REG,tmp);
	        break;
	    default:
	    	ASSERT(0);
	    	break;
	}
    }
}

//20190618@xiaokeweng : for RTC_alarm adjustment follow RTC_Set update ++
BOOL PMIC_RTC_GET_EXPIR_1_ENABLE_STATE()
{
    if (!check_if_DCS_mode() && !CHIP_IS_CRANELR)
    {
	    return SCS_IsAlarmEnabled();
    }else{
	    switch (PMIC_ID_GET())
	    {
	    #if !defined(NOT_SUPPORT_PM813)
		case PMIC_813:
		case PMIC_813A3:
		case PMIC_813S:
			return (PMIC_READ_REG_BASE(NINGBO_RTC_CTRL_REG)&NINGBO_RTC_ALARM_SET1_BIT);
		#endif
		#if !defined(NOT_SUPPORT_PM802)
		case PMIC_802:
        case PMIC_802S:
			return (PMIC_READ_REG_BASE(GUILIN_RTC_CTRL_REG)&GUILIN_RTC_ALARM_SET1_BIT);
	    #endif
		case PMIC_803:
			return SCS_IsAlarmEnabled();
	    case PMIC_803L:
			return (PMIC_READ_REG_BASE(GUILIN_LITE2_RTC_CTRL_REG)&GUILIN_LITE2_RTC_ALARM_SET_BIT);
		default:
			return 0;
	    }
    }
}
//20190618@xiaokeweng : for RTC_alarm adjustment follow RTC_Set update --



//20190513@xiaokeweng : RTC_APP_OFFSET implement ++
#if 0
void PM812_RTC_ENABLE_EXPIR_2()
{
    UINT8 tmp;
    if (PMIC_IS_PM812())
    {
    	tmp = PMIC_READ_REG_BASE(PM812_RTC_CONTROL_REG);
    	tmp |= PM812_RTC_ALARM_SET2_BIT;
    	PMIC_WRITE_REG_BASE(PM812_RTC_CONTROL_REG,tmp);
	}
	else if (PMIC_IS_PM802())
	{
		tmp = PMIC_READ_REG_BASE(GUILIN_RTC_CTRL_REG);
		tmp |= GUILIN_RTC_ALARM_SET2_BIT;
		PMIC_WRITE_REG_BASE(GUILIN_RTC_CTRL_REG,tmp);
	}
	else
	{
        tmp = PMIC_READ_REG_BASE(NINGBO_RTC_CTRL_REG);
        tmp |= NINGBO_RTC_ALARM_SET2_BIT;
        PMIC_WRITE_REG_BASE(NINGBO_RTC_CTRL_REG,tmp);
	}
}

//20190618@xiaokeweng : for RTC_alarm adjustment follow RTC_Set update ++
BOOL PMIC_RTC_GET_EXPIR_2_ENABLE_STATE()
{
    switch (PMIC_ID_GET())
    {
	case PMIC_812:
		return (PMIC_READ_REG_BASE(PM812_RTC_CONTROL_REG)&PM812_RTC_ALARM_SET2_BIT);
	case PMIC_813:
		return (PMIC_READ_REG_BASE(NINGBO_RTC_CTRL_REG)&NINGBO_RTC_ALARM_SET2_BIT);
	case PMIC_802:
		return (PMIC_READ_REG_BASE(GUILIN_RTC_CTRL_REG)&GUILIN_RTC_ALARM_SET2_BIT);
	default:
		return 0;
    }
}
//20190618@xiaokeweng : for RTC_alarm adjustment follow RTC_Set update --
#endif
//20190513@xiaokeweng : RTC_APP_OFFSET implement --
void PM812_RTC_DISABLE_EXPIR_1(void)
{
    UINT8 tmp;

    if (!check_if_DCS_mode() && !CHIP_IS_CRANELR)
    {
        SCS_DisableAlarm();
    }else{
	switch (PMIC_ID_GET())
	{
	    #if !defined(NOT_SUPPORT_PM813)
	    case PMIC_813:
	    case PMIC_813A3:
	    case PMIC_813S:
		tmp = PMIC_READ_REG_BASE(NINGBO_RTC_CTRL_REG);
		tmp &= (~NINGBO_RTC_ALARM_SET1_BIT);
		PMIC_WRITE_REG_BASE(NINGBO_RTC_CTRL_REG,tmp);
		break;
		#endif
		#if !defined(NOT_SUPPORT_PM802)
	    case PMIC_802:
        case PMIC_802S:
		tmp = PMIC_READ_REG_BASE(GUILIN_RTC_CTRL_REG);
		tmp &= (~GUILIN_RTC_ALARM_SET1_BIT);
		PMIC_WRITE_REG_BASE(GUILIN_RTC_CTRL_REG,tmp);
		break;
		#endif
	    case PMIC_803:
		SCS_DisableAlarm();
		break;
	    case PMIC_803L:
		tmp = PMIC_READ_REG_BASE(GUILIN_LITE2_RTC_CTRL_REG);
		tmp &= (~GUILIN_LITE2_RTC_ALARM_SET_BIT);
		PMIC_WRITE_REG_BASE(GUILIN_LITE2_RTC_CTRL_REG,tmp);
	    break;
	    default:
		ASSERT(0);
		break;
	}
    }
}

//20190513@xiaokeweng : RTC_APP_OFFSET implement ++
#if 0
void PM812_RTC_DISABLE_EXPIR_2()
{
    UINT8 tmp;
    if (PMIC_IS_PM812())
    {
    	tmp = PMIC_READ_REG_BASE(PM812_RTC_CONTROL_REG);
    	tmp &= (~PM812_RTC_ALARM_SET2_BIT);
    	PMIC_WRITE_REG_BASE(PM812_RTC_CONTROL_REG,tmp);
	}
	else if (PMIC_IS_PM802())
	{
		tmp = PMIC_READ_REG_BASE(GUILIN_RTC_CTRL_REG);
		tmp &= (~GUILIN_RTC_ALARM_SET2_BIT);
		PMIC_WRITE_REG_BASE(GUILIN_RTC_CTRL_REG,tmp);
	}
	else
	{
    	tmp = PMIC_READ_REG_BASE(NINGBO_RTC_CTRL_REG);
    	tmp &= (~NINGBO_RTC_ALARM_SET2_BIT);
    	PMIC_WRITE_REG_BASE(NINGBO_RTC_CTRL_REG,tmp);
	}
}
#endif
//20190513@xiaokeweng : RTC_APP_OFFSET implement --

static UINT32 PM812_GET_INT_TO_HOST_ENABLE_REG()
{
	COUNTER_32 tmp;

	switch (PMIC_ID_GET())
	{
	    #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
            tmp.cnt_8[3] = PMIC_READ_REG_BASE(NINGBO_INT_ENABLE_REG1);
            tmp.cnt_8[2] = PMIC_READ_REG_BASE(NINGBO_INT_ENABLE_REG2);
            tmp.cnt_8[1] = 0;
            tmp.cnt_8[0] = 0;
            break;
        #endif
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        case PMIC_802S:
            tmp.cnt_8[3] = PMIC_READ_REG_BASE(GUILIN_INT_ENABLE_REG1);
            tmp.cnt_8[2] = PMIC_READ_REG_BASE(GUILIN_INT_ENABLE_REG2);
            tmp.cnt_8[1] = 0;
            tmp.cnt_8[0] = 0;
            break;
        #endif
        case PMIC_803:
            tmp.cnt_8[3] = PMIC_READ_REG_BASE(GUILIN_LITE_INT_ENABLE_REG1);
            tmp.cnt_8[2] = 0;
            tmp.cnt_8[1] = 0;
            tmp.cnt_8[0] = 0;
            break;
        case PMIC_803L:
            tmp.cnt_8[3] = PMIC_READ_REG_BASE(GUILIN_LITE2_INT_ENABLE_REG1);
            tmp.cnt_8[2] = 0;
            tmp.cnt_8[1] = 0;
            tmp.cnt_8[0] = 0;
            break;
        default:
            ASSERT(0);
    }

	return tmp.cnt_32;
}

static UINT32 PMIC_GET_INT_STATUS_SNAPSHOT()
{
	//NOTICE: once PMIC_INTn status REG readed by master processor
	//	  the PMIC_INTn would auto clear by PMIC , so snapshot the
	//	  val for debug , func should only internal invoke by pmic.c
	COUNTER_32 tmp;

	switch (PMIC_ID_GET())
	{
	    #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
            //reconfigure interrupt mode
            PMIC_WRITE_REG_BASE(NINGBO_MISC_CFG_REG2, 0x0);
            tmp.cnt_8[3] = PMIC_READ_REG_BASE(NINGBO_INT_STATUS_REG1);
            tmp.cnt_8[2] = PMIC_READ_REG_BASE(NINGBO_INT_STATUS_REG2);
            tmp.cnt_8[1] = PMIC_READ_REG_BASE(NINGBO2_INT_STATUS_REG3);
            tmp.cnt_8[0] = PMIC_READ_REG_BASE(NINGBO2_INT_STATUS_REG4);
            break;
        #endif
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        case PMIC_802S:
            tmp.cnt_8[3] = 0;
            tmp.cnt_8[2] = 0;
            tmp.cnt_8[1] = PMIC_READ_REG_BASE(GUILIN_INT_STATUS_REG1);
            tmp.cnt_8[0] = PMIC_READ_REG_BASE(GUILIN_INT_STATUS_REG2);
            break;
        #endif
        case PMIC_803:
            tmp.cnt_8[3] = 0;
            tmp.cnt_8[2] = 0;
            tmp.cnt_8[1] = 0;
            tmp.cnt_8[0] = PMIC_READ_REG_BASE(GUILIN_LITE_INT_STATUS_REG1);
            break;
        case PMIC_803L:
            tmp.cnt_8[3] = 0;
            tmp.cnt_8[2] = 0;
            tmp.cnt_8[1] = 0;
            tmp.cnt_8[0] = PMIC_READ_REG_BASE(GUILIN_LITE2_INT_STATUS_REG1);
            break;
        default:
            ASSERT(0);
	}

	return tmp.cnt_32;
}

UINT32 PMIC_GET_INT_TO_HOST_STATUS_REG()
{
	last_pmic_int_status = PMIC_GET_INT_STATUS_SNAPSHOT();
	return last_pmic_int_status;
}

void PMIC_CLEAR_INT_TO_HOST_STATUS_REG()
{
	UINT32 tmp=0;
	UINT32 try_times=0;

	tmp = PMIC_GET_INT_STATUS_SNAPSHOT();
	PMIC_UART_DEBUG("[%s] ++ to read clean int_reg=[%x]\r\n",__func__,tmp);
	while(tmp){
		tmp = PMIC_GET_INT_STATUS_SNAPSHOT();
		PMIC_UART_DEBUG("[%s] WARNING failed to read clean int_reg=[%x]\r\n",__func__,tmp);
	}

	return;
}

static void PM812_PRE_REG_SNAPSHOT()
{
	UINT8 tmp = PM812_RTC_GET_CONTROL_REG();
}

//TODO:RTC TRIM need or NTP sync ?

//enable/disable the  INT report to master processer
static void PM812_INT_TO_HOST_ENABLE(PM812_INTC intc)
{
	UINT8 reg_addr = PM812_INTC_TO_ENABLE_REG(intc);
	UINT8 tmp = PMIC_READ_REG_BASE(reg_addr);
	tmp |= PM812_INTC_TO_ENABLE_BIT(intc);
	PMIC_WRITE_REG_BASE(reg_addr,tmp);
}
static void PM812_INT_TO_HOST_DISABLE(PM812_INTC intc)
{
	UINT8 reg_addr = PM812_INTC_TO_ENABLE_REG(intc);
	UINT8 tmp = PMIC_READ_REG_BASE(reg_addr);
	tmp &= (~(PM812_INTC_TO_ENABLE_BIT(intc)));
	PMIC_WRITE_REG_BASE(reg_addr,tmp);
}

//ICAT EXPORTED FUNCTION - SW_PLAT,PM812,DUMP_STATE
void PM812_DUMP_STATE(void)
{
	//power up / down log
	PMIC_UART_DEBUG("[PMIC] power_up_reason            =[0x%x]\r\n",power_up_reason);
	PMIC_UART_DEBUG("[PMIC] power_down_reason          =[0x%x]\r\n",power_down_reason);
	PMIC_UART_DEBUG("[PMIC] power_down_reason2         =[0x%x]\r\n",power_down_reason2);
	PMIC_UART_DEBUG("[PMIC] last_pmic_int_status       =[0x%x]\r\n",last_pmic_int_status);

	//RTC count
	PMIC_UART_DEBUG("[PMIC] RTC_GET_32B_COUNTER        =[0x%x]\r\n",PM812_RTC_GET_32B_COUNTER());
	PMIC_UART_DEBUG("[PMIC] RTC_GET_32B_EXPIR_1        =[0x%x]\r\n",PM812_RTC_GET_32B_EXPIR_1());
	PMIC_UART_DEBUG("[PMIC] RTC_GET_CONTROL_REG        =[0x%x]\r\n",PM812_RTC_GET_CONTROL_REG());
	PMIC_UART_DEBUG("[PMIC] GET_INT_TO_HOST_ENABLE_REG =[0x%x]\r\n",PM812_GET_INT_TO_HOST_ENABLE_REG());
	PMIC_UART_DEBUG("[PMIC] RTC_GET_32B_APP_OFFSET     =[0x%x]\r\n",PM812_RTC_GET_32B_APP_OFFSET());
	PMIC_UART_DEBUG("[PMIC] RTC_GET_32B_SYS_OFFSET     =[0x%x]\r\n",PM812_RTC_GET_32B_SYS_OFFSET());
}

static void PM812_POWER_UP_ACTIONS()
{
	//storage alarm power status
	PM812_PRE_REG_SNAPSHOT();

	//read PMIC_INT to reset all PMIC_INT_STATUS reltated reg
	PMIC_CLEAR_INT_TO_HOST_STATUS_REG();

	//power up log & power down log
	power_up_reason = PM812_GET_POWER_UP_LOG();
	PM812_CLR_POWER_UP_LOG(power_up_reason);
	power_down_reason = PM812_GET_POWER_DOWN_LOG();
	PM812_CLR_POWER_DOWN_LOG(power_down_reason);
	power_down_reason2 = PM812_GET_POWER_DOWN_LOG2();
	PM812_CLR_POWER_DOWN_LOG2(power_down_reason2);
}

UINT8 PM812_GET_POWER_UP_REASON(void)
{
	return power_up_reason;
}

UINT8 PM812_GET_POWER_DOWN_REASON(void)
{
	return power_down_reason;
}

UINT8 PM812_GET_POWER_DOWN_REASON2(void)
{
	return power_down_reason2;
}

BOOL PMIC_IS_ALARM_TRIGGERD_POWERUP(void){
	switch (PMIC_ID_GET())
	{
	    #if !defined(NOT_SUPPORT_PM813)
		case PMIC_813:
		case PMIC_813A3:
		case PMIC_813S:
			if(!check_if_DCS_mode()){
				return (PM812_GET_POWER_UP_REASON() & NINGBO_EXTON1_WAKEUP_BIT)?TRUE:FALSE;
			}else{
				return (PM812_GET_POWER_UP_REASON() & NINGBO_RTC_ALARM_WU_BIT)?TRUE:FALSE;
			}
	    #endif
	    #if !defined(NOT_SUPPORT_PM802)
		case PMIC_802:
        case PMIC_802S:
			if(!check_if_DCS_mode()){
				return (PM812_GET_POWER_UP_REASON() & GUILIN_EXTON1_INT_OCCURRED)?TRUE:FALSE;
			}else{
				return (PM812_GET_POWER_UP_REASON() & GUILIN_RTC_INT_OCCURRED)?TRUE:FALSE;
			}
	    #endif
		case PMIC_803:
			return (PM812_GET_POWER_UP_REASON() & GUILIN_LITE_RTC_INT_OCCURRED)?TRUE:FALSE;
		case PMIC_803L:
			return (PM812_GET_POWER_UP_REASON() & GUILIN_LITE2_RTC_INT_OCCURRED)?TRUE:FALSE;
		default:
		    ASSERT(0);
		    return FALSE;
	}
}

BOOL PMIC_ID_GET(void)
{
    if (pmic_id == PMIC_UNAVAILABLE)
	    pmic_id = (GetPMICID()&0xF8)>>3;//initial pmic_id after boot
    return pmic_id;
}

BOOL PMIC_COMP_ID_GET(void)
{
    static UINT8 pmic_complete_id = PMIC_UNAVAILABLE;
    if (pmic_complete_id == PMIC_UNAVAILABLE)
	    pmic_complete_id = GetPMICID();
    return pmic_complete_id;
}

/* Following APIs reflect PMIC series. */
BOOL PMIC_IS_PM812(void)
{
	return FALSE;
}

BOOL PMIC_IS_PM813(void)
{
	return ((PMIC_ID_GET() == PMIC_813)||(PMIC_ID_GET() == PMIC_813A3));
}

BOOL PMIC_IS_PM813_A1(void)
{
	return (PMIC_COMP_ID_GET() == PMIC_813_A1);
}

BOOL PMIC_IS_PM813_A2(void)
{
	return (PMIC_COMP_ID_GET() == PMIC_813_A2);
}

BOOL PMIC_IS_PM813_A3(void)
{
	return (PMIC_COMP_ID_GET() == PMIC_813_A3);
}

BOOL PMIC_IS_PM802(void)
{
	return (PMIC_ID_GET() == PMIC_802);
}

BOOL PMIC_IS_PM803(void)
{
	return (PMIC_ID_GET() == PMIC_803);
}

BOOL PMIC_IS_PM813S(void)
{
	return (PMIC_ID_GET() == PMIC_813S);
}

BOOL PMIC_IS_PM813S_A0(void)
{
	return (PMIC_COMP_ID_GET() == PMIC_813S_A0);
}

BOOL PMIC_IS_PM802S(void)
{
	return (PMIC_ID_GET() == PMIC_802S);
}

BOOL PMIC_IS_PM803L(void)
{
	return (PMIC_ID_GET() == PMIC_803L);
}

OSTaskRef		PmicHisrTask;
#ifdef QUECTEL_PROJECT_CUST
unsigned char 	PmicHisrTask_Stack[PMIC_HISR_STACK_SIZE];
#else
#ifdef LTEONLY_THIN
unsigned char 	PmicHisrTask_Stack[1024];
#else
unsigned char 	PmicHisrTask_Stack[2048];
#endif
#endif
OSFlagRef 	  	PmicHisrTask_FlgRef;

static void PMICHISRTask(void);

#ifdef SCS_BUT_WITHOUT_ALARM_IO_PAD
OSTaskRef		no_alarm_io_PmicHisrTask;
unsigned char 	no_alarm_io_PmicHisrTask_Stack[2048];
OSFlagRef 	  	no_alarm_io_PmicHisrTask_FlgRef;
static void no_alarm_io_PMICHISRTask(void);


void internal_rtc_alarm_update(void){
	UINT32 offset = 0;

	offset = PM812_RTC_GET_32B_EXPIR_1() - PM812_RTC_GET_32B_COUNTER();
	PMIC_UART_DEBUG("[NO_ALARM_IO][%s]offset =[%x]\r\n",__func__,offset);

	RtcHwRegisters.RTAR = RtcHwRegisters.RCNR + (offset);
	PMIC_UART_DEBUG("[NO_ALARM_IO][%s]RtcHwRegisters.RCNR=[%x]\r\n",__func__,RtcHwRegisters.RCNR);
	PMIC_UART_DEBUG("[NO_ALARM_IO][%s]RtcHwRegisters.RTAR=[%x]\r\n",__func__,RtcHwRegisters.RTAR);
}

void no_alarm_rtc_alarm_enable(BOOL onoff){
	//translate from below refer to RTC_stub.c:
	//onoff?RTC_ALARM_ENABLE:RTC_ALARM_DISABLE;
	//
	PMIC_UART_DEBUG("[NO_ALARM_IO][%s][%d]",__func__,onoff);
	if(onoff){
		RtcHwRegisters.RTSR = (RtcHwRegisters.RTSR|0x04)&~0x03;
		INTCEnable(INTC_SRC_RTC_ALARM);
	}else{
		INTCDisable(INTC_SRC_RTC_ALARM);
		RtcHwRegisters.RTSR = (RtcHwRegisters.RTSR & ~0x04)&~0x03;
	}
}

void no_alarm_io_rtc_signal_clear(void){
	//translate from below refer to RTC_stub.c:
	//RTC_AL_BIT_CLEAR;
	//
	PMIC_UART_DEBUG("[NO_ALARM_IO][%s]",__func__);
	RtcHwRegisters.RTSR = ((RtcHwRegisters.RTSR & (0x0c)) | 0x01);
}
#endif//SCS_BUT_WITHOUT_ALARM_IO_PAD


extern void cpu_dvc_init(void);
extern void Get_Svc_Level_Values(void);		//2022.03.29 update baseline for DRO

void PMIC_Phase1Init(void)
{
	OSA_STATUS      osStatus   = OS_SUCCESS;
    unsigned char var = 0;
	PMIC_UART_DEBUG("PMIC_Phase1Init\r\n");

	osStatus = OSASemaphoreCreate (&I2CApp_SemaRef,1,OSA_FIFO);
    ASSERT(osStatus == OS_SUCCESS);
    osStatus = OSAFlagCreate( &PmicHisrTask_FlgRef );
    ASSERT( osStatus == OS_SUCCESS );
#ifdef QUECTEL_PROJECT_CUST
osStatus = OSATaskCreate( &PmicHisrTask, PmicHisrTask_Stack, PMIC_HISR_STACK_SIZE, 45,  "pmic_HISR_T", (void (*)(void *))PMICHISRTask, NULL );
#else
#ifdef LTEONLY_THIN
	osStatus = OSATaskCreate( &PmicHisrTask, PmicHisrTask_Stack, 1024, 45,  "pmic_HISR_T", (void (*)(void *))PMICHISRTask, NULL );
#else
    osStatus = OSATaskCreate( &PmicHisrTask, PmicHisrTask_Stack, 2048, 45,  "pmic_HISR_T", (void (*)(void *))PMICHISRTask, NULL );
#endif
#endif
	ASSERT(osStatus == OS_SUCCESS);

#ifdef SCS_BUT_WITHOUT_ALARM_IO_PAD
	osStatus = OSAFlagCreate( &no_alarm_io_PmicHisrTask_FlgRef );
	ASSERT( osStatus == OS_SUCCESS );
	osStatus = OSATaskCreate( &no_alarm_io_PmicHisrTask
		, no_alarm_io_PmicHisrTask_Stack
		, 2048, 45,  "mrtc_HISR_T"
		, (void (*)(void *))no_alarm_io_PMICHISRTask
		, NULL );
	ASSERT(osStatus == OS_SUCCESS);
#endif//SCS_BUT_WITHOUT_ALARM_IO_PAD

    usticaInit(); //init clock and TWSI ctrl
    Crane_Get_Svc_Level_Values(); //get voltage values for each DVC level

    cpu_dvc_init();

	switch (PMIC_ID_GET())
	{
	    #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        case PMIC_802S:
            memset( mGuilinIntHandler, 0 , sizeof(mGuilinIntHandler[GUILIN_INTC_MAX+1]));
			#if 1  //set to 10pf once if cap is 20pf in default
            if (check_if_DCS_mode())
            {
                GuilinRead( GUILIN_BASE_Reg, GUILIN_CRYSTAL_CAP_SET_REG, &var );
                if( (var&0xE0) != 0x20)
                {
                    var &= ~0xE0;
                    var |= 0x20;
                    GuilinWrite( GUILIN_BASE_Reg, GUILIN_CRYSTAL_CAP_SET_REG, var );
                }
            }
			#endif
            Guilin_Aditional_Workaround();
            break;
        #endif
		
        #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
#if 1  //set to 10pf once if cap is 20pf in default
            if (check_if_DCS_mode())
            {
                NingboRead( NINGBO_BASE_Reg, NINGBO_CRYSTAL_CAP_SET_REG, &var );
                if( (var&0xE0) != 0x20)
                {
                    var &= ~0xE0;
                    var |= 0x20;
                    NingboWrite( NINGBO_BASE_Reg, NINGBO_CRYSTAL_CAP_SET_REG, var );
                }
            }
#endif
            memset( mNingboIntHandler, 0 , sizeof(mNingboIntHandler[NINGBO_INTC_MAX+1]));
            Ningbo_Aditional_Workaround();
            break;
        #endif
        #if !defined(NOT_SUPPORT_PM803)
        case PMIC_803:
            memset( mGuilinLiteIntHandler, 0 , sizeof(mGuilinLiteIntHandler[GUILIN_LITE_INTC_MAX+1]));
            GuilinLite_Aditional_Workaround();
            break;
        #endif
        #if !defined(NOT_SUPPORT_PM803L)
        case PMIC_803L:
            memset( mGuilinLite2IntHandler, 0 , sizeof(mGuilinLite2IntHandler[GUILIN_LITE2_INTC_MAX+1]));
            GuilinLite2_Aditional_Workaround();
            break;
        #endif
        default:
            ASSERT(0);
            break;
    }
    #if !defined(NOT_SUPPORT_PM813)
    if (PMIC_IS_PM813()||PMIC_IS_PM813S())
    {
#if !defined (ENABLE_SLT_FEATURE)
	#if !QUECTEL_PROJECT_CUST //shaohua.li@20210901 保持和006基线同步，关闭开机电压检测的功能<3.4V 不开机
		Ningbo_SoftwareNotProceedUntilReach3400();
	#endif
#endif
    }
    #endif
#ifdef QUECTEL_PROJECT_CUST
	if(PMIC_IS_PM803())
	{
		unsigned char *reg;
		extern const char* asr_property_get(const char *name);
		reg = (unsigned char *)asr_property_get("power_down_reg");

		//power up log & power down log
		power_up_reason = PM812_GET_POWER_UP_LOG();
		power_down_reason  = reg[2];
		power_down_reason2 = reg[3];
		hot_power_flag = reg[5];
		 // ref@preboot pmic.c pmic_setup()
		if(power_down_reason == 0xFF)
		{
			power_down_reason = 0x0;
		}
		if(power_down_reason2 == 0xFF)
		{
			power_down_reason2 = 0x0;
		}
		if(hot_power_flag == 0xFF)
		{
			hot_power_flag = 0x0;
		}
	}
	else
#endif		
	{

    //to storage the power up reason log
    	PM812_POWER_UP_ACTIONS();
	}
	//PM813_VBUS_int(); disable USB connection by pmic INT

    pmic_rtc_offset_storage_type_detect();
}

static OS_HISR    g_pmic_hisr_ref;

static void PMICHISRTask(void)
{
    UINT32  flag_value = 0;
	PmicCallback isr;
	COUNTER_32 tmp;
	UINT8 intc;
	OSA_STATUS  status = OS_SUCCESS;

	while(1)
	{
		status = OSAFlagWait( PmicHisrTask_FlgRef, 0x01, OSA_FLAG_OR_CLEAR,&flag_value, OSA_SUSPEND );
		ASSERT( status == OS_SUCCESS );

		if( flag_value & 0x01 )
        {
        	//0. storage RTC_STATUS firstly it would be auto clear once PMIC_INT_STATUS read
        	PM812_PRE_REG_SNAPSHOT();

        	//1. read PMIC_INT_STATUS_REG_1 + 2
        	UINT32 int_status = PMIC_GET_INT_TO_HOST_STATUS_REG();
#if QUECTEL_PROJECT_CUST //just for debug
            CPUartLogPrintf("%s,int_status:0x%x",__func__,int_status);
#endif

        	//2. check and handle with callback isr func
            switch (PMIC_ID_GET())
            {
                #if !defined(NOT_SUPPORT_PM813)
                case PMIC_813:
                case PMIC_813A3:
                case PMIC_813S: //use 813 ints temply.
                    {
                        for(intc=0;intc<=NINGBO_INTC_MAX;intc++)
                        {
                            if(mNingboIntHandler[intc].pmic_intc_enabled && (int_status & NINGBO_INTC_TO_STATUS_BIT(intc)))
                            {
                                if (PMIC_IS_PM813_A1())
                                    if (intc == NINGBO_VBUS_UVLO_INT)
                                        Ningbo_INT_DISABLE(NINGBO_VBUS_UVLO_INT); //disable uvlo int here.

                                #if PMIC_DEBUG
                                DIAG_FILTER(SW_PLAT, PMIC, PMIC_HISR_FUNC2, DIAG_INFORMATION)
                                diagPrintf ("PM813(S) HISR: intc %d", intc);
                                #endif
                                mNingboIntHandler[intc].pmic_intc_enabled = FALSE;

								if(!check_if_DCS_mode()){
								    if (int_status & NINGBO_INTC_TO_STATUS_BIT(NINGBO_EXTON1_INT)) {
									//force clear SCS WAKEUP SIGNAL
									SCS_ClearWakeupSignal();
									//the SCS WAKEUP SIGNAL clear may trigger another PMIC RTC intterrupt
									//caused (Basepage,0x05)=0x4 marked, which take side effect to the next SCS RTC intterrput.
									//therefore, do another read action to clean as below.
									PMIC_CLEAR_INT_TO_HOST_STATUS_REG();
								    }
								}

                                isr = mNingboIntHandler[intc].pmic_isr;
                                if(isr)
                                    (isr)();//call isr func
                                else
                                    PMIC_UART_DEBUG("No PMIC int callback!\r\n");
                                mNingboIntHandler[intc].pmic_intc_enabled = TRUE;
                            }
                        }
                    }
                    break;
                #endif
                #if !defined(NOT_SUPPORT_PM802)
                case PMIC_802:
                case PMIC_802S:
                    {
                        for(intc=0;intc<=GUILIN_INTC_MAX;intc++)
                        {
                            if(mGuilinIntHandler[intc].pmic_intc_enabled && (int_status & GUILIN_INTC_TO_STATUS_BIT(intc)))
                            {
                                #if PMIC_DEBUG
                                DIAG_FILTER(SW_PLAT, PMIC, PMIC_HISR_FUNC3, DIAG_INFORMATION)
                                diagPrintf ("PM802 HISR: intc %d", intc);
                                #endif
                                mGuilinIntHandler[intc].pmic_intc_enabled = FALSE;

                                if(!check_if_DCS_mode()){
                                    if (int_status & GUILIN_INTC_TO_STATUS_BIT(GUILIN_EXTON1_INT)) {
                                    //force clear SCS WAKEUP SIGNAL
                                    SCS_ClearWakeupSignal();
                                    //the SCS WAKEUP SIGNAL clear may trigger another PMIC RTC intterrupt
                                    //caused (Basepage,0x05)=0x4 marked, which take side effect to the next SCS RTC intterrput.
                                    //therefore, do another read action to clean as below.
                                    PMIC_CLEAR_INT_TO_HOST_STATUS_REG();
                                    }
                                }

                                isr = mGuilinIntHandler[intc].pmic_isr;
                                if(isr) (isr)();//call isr func
                                mGuilinIntHandler[intc].pmic_intc_enabled = TRUE;
                            }
                        }
                    }
                    break;
                #endif
                #if !defined(NOT_SUPPORT_PM803)
                case PMIC_803:
                    {
                        for(intc=0;intc<=GUILIN_LITE_INTC_MAX;intc++)
                        {
                            if(mGuilinLiteIntHandler[intc].pmic_intc_enabled && (int_status & GUILIN_LITE_INTC_TO_STATUS_BIT(intc)))
                            {
                                #if PMIC_DEBUG
                                DIAG_FILTER(SW_PLAT, PMIC, PMIC_HISR_FUNC4, DIAG_INFORMATION)
                                diagPrintf ("PM803 HISR: intc %d", intc);
                                #endif
                                mGuilinLiteIntHandler[intc].pmic_intc_enabled = FALSE;

                                if(!check_if_DCS_mode()){
                                    if (int_status & GUILIN_LITE_INTC_TO_STATUS_BIT(GUILIN_LITE_RTC_ALARM_INT)) {
                                    //force clear SCS WAKEUP SIGNAL
                                    SCS_ClearWakeupSignal();
                                    //the SCS WAKEUP SIGNAL clear may trigger another PMIC RTC intterrupt
                                    //caused (Basepage,0x05)=0x4 marked, which take side effect to the next SCS RTC intterrput.
                                    //therefore, do another read action to clean as below.
                                    PMIC_CLEAR_INT_TO_HOST_STATUS_REG();
                                    }
                                }

                                isr = mGuilinLiteIntHandler[intc].pmic_isr;
                                if(isr) (isr)();//call isr func
                                mGuilinLiteIntHandler[intc].pmic_intc_enabled = TRUE;
                            }
                        }
                    }
                    break;
                #endif
                #if !defined(NOT_SUPPORT_PM803L)
                case PMIC_803L:
                    {
                        for(intc=0;intc<=GUILIN_LITE2_INTC_MAX;intc++)
                        {
                            if(mGuilinLite2IntHandler[intc].pmic_intc_enabled && (int_status & GUILIN_LITE2_INTC_TO_STATUS_BIT(intc)))
                            {
                #if PMIC_DEBUG
                                DIAG_FILTER(SW_PLAT, PMIC, PMIC_HISR_FUNC5, DIAG_INFORMATION)
                                diagPrintf ("PM803L HISR: intc %d", intc);
                #endif
                                mGuilinLite2IntHandler[intc].pmic_intc_enabled = FALSE;
#if 0
                                if(!check_if_DCS_mode()){
                                    if (int_status & GUILIN_LITE2_INTC_TO_STATUS_BIT(GUILIN_LITE2_RTC_ALARM_INT)) {
                                    //force clear SCS WAKEUP SIGNAL
                                    SCS_ClearWakeupSignal();
                                    //the SCS WAKEUP SIGNAL clear may trigger another PMIC RTC intterrupt
                                    //caused (Basepage,0x05)=0x4 marked, which take side effect to the next SCS RTC intterrput.
                                    //therefore, do another read action to clean as below.
                                    PMIC_CLEAR_INT_TO_HOST_STATUS_REG();
                                    }
                                }
#endif
                                isr = mGuilinLite2IntHandler[intc].pmic_isr;
                                if(isr) (isr)();//call isr func
                                mGuilinLite2IntHandler[intc].pmic_intc_enabled = TRUE;
                            }
                        }
                    }
                    break;
                #endif
                default:
                    ASSERT(0);
                    break;
            }

#ifdef CHARGE_DM
            extern OSTaskRef chargeManagerTaskRef_FlgRef;
            extern UINT32 pmic_int_status_charge;
            pmic_int_status_charge = int_status;
            status = OSAFlagSet(chargeManagerTaskRef_FlgRef, 0x01, OSA_FLAG_OR);
            ASSERT(status == OS_SUCCESS);
#endif
        }
    	//enable INTC_SRC_PMIC
    	INTCEnable(INTC_SRC_PMIC);
	}
}

#ifdef SCS_BUT_WITHOUT_ALARM_IO_PAD
static OS_HISR    no_alarm_io_g_pmic_hisr_ref;
Pmic_Int_Handler m_no_alarm_io_rtc_handler;
static void no_alarm_io_PMICHISRTask(void)
{
    UINT32  flag_value = 0;
	PmicCallback isr;
	COUNTER_32 tmp;
	UINT8 intc;
	OSA_STATUS  status = OS_SUCCESS;

	while(1)
	{
		status = OSAFlagWait( no_alarm_io_PmicHisrTask_FlgRef, 0x01, OSA_FLAG_OR_CLEAR,&flag_value, OSA_SUSPEND );
		ASSERT( status == OS_SUCCESS );

		if( flag_value & 0x01 )
		{
			no_alarm_io_rtc_signal_clear();
			//disable SCS alarm flag
			PM812_RTC_DISABLE_EXPIR_1();

			//exec callback
			isr = m_no_alarm_io_rtc_handler.pmic_isr;
			if(isr) (isr)();//call isr func
		}
	}
}
#endif//SCS_BUT_WITHOUT_ALARM_IO_PAD


#ifdef CHARGE_DM
extern void chargeManagePhase2Init(void);
#endif

void PMIC_Phase2Init(void)
{
    INTC_ReturnCode intcStatus;

	PMIC_UART_DEBUG("PMIC_Phase2Init");

	switch (PMIC_ID_GET())
	{
	    #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
//            NingboClkInit();
    //        Ningbo_VBUCK1_Set_FPWM();
            //Buck2 is required to be 2.1V, which is the input for LDO6/7/11, 2.0V may be bad for RF perf.
            Ningbo_VBUCK_Set_VOUT(NINGBO_VBUCK2_ACTIVE_VOUT_REG,NINGBO_VBUCK_2V10);
			NingboWrite( NINGBO_BASE_Reg, NINGBO_MISC_CFG_REG2, 0x0 );
            break;
        #endif
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        case PMIC_802S:
//            GuilinClkInit();
			#ifdef QUEC_1601_PM802_FPWM_ENABLE  //not shield for low probability dump
            Guilin_VBUCK1_Set_FPWM();
			#endif
			//CPUartLogPrintf("set pwm");
            Guilin_VBUCK4_Set_FPWM();
            break;
        #endif
        #if !defined(NOT_SUPPORT_PM803)
        case PMIC_803:
            GuilinLiteClkInit();
            //evin 20210608 IIC open fpwm
            #ifndef QUEC_FPWM_GPIO_SET
            GuilinLite_VBUCK1_Set_FPWM();
            #endif

            break;
        #endif
        #if !defined(NOT_SUPPORT_PM803L)
        case PMIC_803L:
            GuilinLite2ClkInit();
    //        GuilinLite2_VBUCK1_Set_FPWM();
            break;
        #endif
        default:
            ASSERT(0);
            break;
	}

    if (!check_if_DCS_mode() && !CHIP_IS_CRANELR)
    {
        //20200904@xiaoke for CRANE-G+PM803 SCS mode (Single Crystal Scenario)
        SCS_RtcInit();
        //clear signal on I/O pad ALARM_WAKEUP for SCS mode
        if(PMIC_IS_ALARM_TRIGGERD_POWERUP())
		{
            PMIC_UART_DEBUG("[PMIC] SCS_ClearWakeupSignal()\r\n");
            SCS_ClearWakeupSignal();
		}
    } else if (CHIP_IS_CRANELR) {
        #include "rtc_hw.h"
        RtcHwRegisters.RTTR = 32786;
    }

	PMIC_CLEAR_INT_TO_HOST_STATUS_REG();//make sure to clean all ints
    //dump RTC power up status
    PM812_DUMP_STATE();
    pmic_rtc_setting_init_fetch();

#ifdef QUEC_3601_PMIC_PWRKEY_9374
	PMIC_PWRKey_Init(); //added for pwrkey
#else
#ifdef CRANE_MCU_DONGLE
	SysPowerOffInit();//add lh 2019/11/19
#endif
#endif

    //set pimc hisr
    OS_Create_HISR(&g_pmic_hisr_ref ,"PMICHISR" ,PMIC_HISR_FUNC ,HISR_STACK_LEVEL_1 | HISR_PRIORITY_2);

    //bind & enable INTC_SRC_PMIC
    intcStatus = INTCConfigure (INTC_SRC_PMIC,
                    INTC_IRQ,
                    INTC_RISING_EDGE);
    intcStatus = INTCBind( INTC_SRC_PMIC, PMIC_LISR_FUNC);
//    INTCEnable(INTC_SRC_PMIC); //move to main.c

#ifdef SCS_BUT_WITHOUT_ALARM_IO_PAD
     PMIC_UART_DEBUG("[NO_ALARM_IO][%s]\r\n",__func__);
     OS_Create_HISR(&no_alarm_io_g_pmic_hisr_ref ,"mRTCHISR" ,no_alarm_io_PMIC_HISR_FUNC ,HISR_STACK_LEVEL_1 | HISR_PRIORITY_2);
     INTCConfigure(INTC_SRC_RTC_ALARM, INTC_IRQ, INTC_RISING_EDGE);
     INTCBind(INTC_SRC_RTC_ALARM, no_alarm_io_PMIC_LISR_FUNC);

	if(PMIC_RTC_GET_EXPIR_1_ENABLE_STATE()){
	     PMIC_UART_DEBUG("[NO_ALARM_IO][%s] force disable alarm \r\n",__func__);
	     PM812_RTC_DISABLE_EXPIR_1();
     }
#endif//SCS_BUT_WITHOUT_ALARM_IO_PAD

#ifdef CHARGE_DM
    chargeManagePhase2Init();
#endif

    //millisecond align calculate from 32K tick
    RTC_PERIODIC_INTC_Init();
    RTC_millisecond_align_trigger();
}

void PMIC_Phase3Init(void)
{
	PMIC_UART_DEBUG("PMIC_Phase3Init,Clk Init\r\n");

	switch (PMIC_ID_GET())
	{
	    #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
             NingboClkInit();
             break;
        #endif
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        case PMIC_802S:
             GuilinClkInit();
             break;
        #endif
        default:
            break;
    }
}

#ifdef SCS_BUT_WITHOUT_ALARM_IO_PAD
static void no_alarm_io_PMIC_LISR_FUNC(UINT32 isr)
{
	UINT32 status;

	//disable PMIC_INTn intrrupt to avoid re-trigger
	INTCDisable(INTC_SRC_RTC_ALARM);

	status = OS_Activate_HISR(&no_alarm_io_g_pmic_hisr_ref);

	ASSERT(status == OS_SUCCESS);
}
#endif//SCS_BUT_WITHOUT_ALARM_IO_PAD



//PMIC LISR
static void PMIC_LISR_FUNC(UINT32 isr)
{
	UINT32 status;
	status = OS_Activate_HISR(&g_pmic_hisr_ref);

	ASSERT(status == OS_SUCCESS);
	//disable PMIC_INTn intrrupt to avoid re-trigger
	INTCDisable(INTC_SRC_PMIC);
}

void PM812_INT_DISABLE(PM812_INTC intc)
{
	PMIC_UART_DEBUG("[%s] intc=[%d]\r\n",__func__,intc);
	mPmicIntHandler[intc].pmic_intc_enabled = FALSE;
	PM812_INT_TO_HOST_DISABLE(intc);
}

void PM812_INT_ENABLE(PM812_INTC intc)
{
	PMIC_UART_DEBUG("[%s]  intc=[%d]\r\n",__func__,intc);
	mPmicIntHandler[intc].pmic_intc_enabled = TRUE;
	PM812_INT_TO_HOST_ENABLE(intc);
}

void PM812_INT_CALLBACK_REGISTER(PM812_INTC intc,PmicCallback isr)
{
	PMIC_UART_DEBUG("[%s] intc=[%d] , isr=[%x]\r\n",__func__,intc,isr);
	mPmicIntHandler[intc].pmic_isr = isr;

}
#ifdef SCS_BUT_WITHOUT_ALARM_IO_PAD
void no_alarm_io_PMIC_HISR_FUNC(void)
{
	OSA_STATUS  os_status;

	os_status = OSAFlagSet( no_alarm_io_PmicHisrTask_FlgRef, 0x01, OSA_FLAG_OR );
	ASSERT( os_status == OS_SUCCESS );
}
#endif//SCS_BUT_WITHOUT_ALARM_IO_PAD



//PMIC HISR
void PMIC_HISR_FUNC(void)
{
	OSA_STATUS  os_status;

	os_status = OSAFlagSet( PmicHisrTask_FlgRef, 0x01, OSA_FLAG_OR );
	ASSERT( os_status == OS_SUCCESS );
}

BOOL PM812_ONKEY_IS_DETECTED(void)
{
	switch (PMIC_ID_GET())
	{
	    #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
            return ((PMIC_READ_REG_BASE(NINGBO_STATUS_REG1) & NINGBO_ONKEY_STATUS_BIT) ? TRUE : FALSE);
        #endif
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        case PMIC_802S:
            return ((PMIC_READ_REG_BASE(GUILIN_STATUS_REG1) & GUILIN_ONKEY_PRESSED) ? TRUE : FALSE);
        #endif
        case PMIC_803:
            return ((PMIC_READ_REG_BASE(GUILIN_LITE_STATUS_REG1) & GUILIN_LITE_ONKEY_PRESSED) ? TRUE : FALSE);
        case PMIC_803L:
            return ((PMIC_READ_REG_BASE(GUILIN_LITE2_STATUS_REG1) & GUILIN_LITE2_ONKEY_PRESSED) ? TRUE : FALSE);
        default:
            ASSERT(0);
            return FALSE;
	}
}

BOOL PM812_EXTON_IS_DETECTED(void)
{
	//check whether EXTON pin is connected
	switch (PMIC_ID_GET())
	{
	    #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
            return ((PMIC_READ_REG_BASE(NINGBO_STATUS_REG1) & (NINGBO_VBUS_STATUS_BIT | NINGBO_VBUS_OVP_BIT | NINGBO_VBUS_UVLO_BIT)) ? TRUE : FALSE);
        case PMIC_813A3:
        case PMIC_813S:
            return ((PMIC_READ_REG_BASE(NINGBO_READONLY_DATA_2_REG) & (NINGBO_RONLY_DATA_CHG_OK)) ? TRUE : FALSE);
        #endif
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        case PMIC_802S:
            return ((PMIC_READ_REG_BASE(GUILIN_STATUS_REG1) & GUILIN_EXTON1_DETECT) ? TRUE : FALSE);
        #endif
        case PMIC_803:
            return ((PMIC_READ_REG_BASE(GUILIN_LITE_STATUS_REG1) & GUILIN_LITE_EXTON1_DETECT) ? TRUE : FALSE);
        case PMIC_803L:
            return ((PMIC_READ_REG_BASE(GUILIN_LITE2_STATUS_REG1) & GUILIN_LITE2_EXTON1_DETECT) ? TRUE : FALSE);
        default:
            ASSERT(0);
            return FALSE;
	}
}

BOOL PM812_CHARGER_IS_DETECTED(void)
{
	//for FIH board only check EXTON_STATUS
	return PM812_EXTON_IS_DETECTED();
}

BOOL PM812_BATTERY_IS_DETECTED(void)
{
	switch (PMIC_ID_GET())
	{
	    #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
            return ((PMIC_READ_REG_BASE(NINGBO_STATUS_REG1) & NINGBO_VBAT_STATUS_BIT) ? TRUE : FALSE);
        #endif
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        case PMIC_802S:
            return ((PMIC_READ_REG_BASE(GUILIN_STATUS_REG1) & GUILIN_BAT_DETECT) ? TRUE : FALSE);
        #endif
        case PMIC_803:
            return ((PMIC_READ_REG_BASE(GUILIN_LITE_STATUS_REG1) & GUILIN_LITE_BAT_DETECT) ? TRUE : FALSE);
        case PMIC_803L:
            return ((PMIC_READ_REG_BASE(GUILIN_LITE2_STATUS_REG1) & GUILIN_LITE2_BAT_DETECT) ? TRUE : FALSE);
        default:
            ASSERT(0);
            return FALSE;
	}
}

//for CHARER bind on USB_VBUS
BOOL PM812_VBUS_IS_AVAILABLE(void)
{
	switch (PMIC_ID_GET())
	{
	    #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
            return ((PMIC_READ_REG_BASE(NINGBO_STATUS_REG1) & (NINGBO_VBUS_STATUS_BIT | NINGBO_VBUS_OVP_BIT | NINGBO_VBUS_UVLO_BIT)) ? TRUE : FALSE);
        case PMIC_813A3:
        case PMIC_813S:
            return ((PMIC_READ_REG_BASE(NINGBO_READONLY_DATA_2_REG) & (NINGBO_RONLY_DATA_CHG_OK)) ? TRUE : FALSE);
        #endif
       	case PMIC_803:
		case PMIC_802:
		{
			/*PMIC802/PMIC803 do not support charger(so VBUS detectio is impossible),
			we check PMUap offset0x7C ,bit15 to detect VBUS state
			*/
			//uart_printf("DBG========PM812 is called in kernel!\n");
			return (((*(volatile unsigned long*)0xd428287c >>15)&0x1) ? TRUE : FALSE);
		}
        default:
    		PMIC_UART_DEBUG("No charger function!\r\n");
    		return FALSE;
    }
}

//3.4 default
UINT32 PM812_GET_VCHG_LOW_TH()
{
    return 0;
}

//4.2 default
UINT32 PM812_GET_VCHG_UPP_TH()
{
    //NOT SUPPORTED IN PM813
    return 0;
}

void PM812_SET_VCHG_LOW_TH(UINT8 low)
{
    //NOT SUPPORTED IN PM813
}

void PM812_SET_VCHG_UPP_TH(UINT8 upp)
{
    //NOT SUPPORTED IN PM813
}

//for 12bit vol meas
UINT16 PM812_GPADC_READ_VOL_MEAS(UINT8 meaReg)
{
	UINT16 meas_val;
	UINT8 reg_value[2],tmp;

	/* Read two registers, the alignment will be done as follows:
	Register 1 - bits 7:0 => 8 MSB bits <11:4> of measurement value
	Register 2 - bits 3:0 => 4 LSB bits <3:0> of measurement value
	*/
    if (PMIC_IS_PM813())
    {
        tmp = PMIC_READ_REG_GPADC(NINGBO_GPADC_MODE_CONTROL_REG);
        PMIC_WRITE_REG_GPADC(NINGBO_GPADC_MODE_CONTROL_REG,(tmp&~NINGBO_GPADC_EN));//disable GPADC to get proper value
    }
	reg_value[0] = PMIC_READ_REG_GPADC(meaReg+0);
	reg_value[1] = PMIC_READ_REG_GPADC(meaReg+1);

	meas_val = (reg_value[0] << 4) | (reg_value[1] & 0x0F);

	return meas_val;
}
void PM812_BIAS_ENABLE(PM812_BIAS_EN bias_en)
{
}
void PM812_BIAS_DISABLE(PM812_BIAS_EN bias_en)
{
}

void PM812_BIAS_OUT_ON(PM812_BIAS_OUT bias_out)
{
}

void PM812_BIAS_OUT_OFF(PM812_BIAS_OUT bias_out)
{
}

void PM812_MEAS_ENABLE(PM812_MEAS_EN meas_en)
{
}

void PM812_MEAS_DISABLE(PM812_MEAS_EN meas_en)
{
}

void PM812_GPADC_SW_TRIG()
{
    UINT8 tmp;
	if (PMIC_IS_PM802()||PMIC_IS_PM802S())
	{
    	tmp = PMIC_READ_REG_GPADC(GUILIN_GPADC_MISC_CONFIG_REG2);
    	tmp |= GUILIN_GPADC_SW_TRIG_BIT;
    	PMIC_WRITE_REG_GPADC(GUILIN_GPADC_MISC_CONFIG_REG2,tmp);
	}
	#if !defined(NOT_SUPPORT_PM813)
	else if(PMIC_IS_PM813()||PMIC_IS_PM813S())
	{
    	tmp = PMIC_READ_REG_GPADC(NINGBO_GPADC_MODE_CONTROL_REG);
    	tmp |= NINGBO_GPADC_SW_TRIG_BIT;
    	PMIC_WRITE_REG_GPADC(NINGBO_GPADC_MODE_CONTROL_REG,tmp);
	}
	#endif
}

void PM812_GPADC_NONSTOP_TRIG_ENABLE(void)
{
    UINT8 tmp;
    #if !defined(NOT_SUPPORT_PM802)
	if (PMIC_IS_PM802()||PMIC_IS_PM802S())
	{
    	tmp = PMIC_READ_REG_GPADC(GUILIN_GPADC_MISC_CONFIG_REG2);
    	tmp |= (GUILIN_NON_STOP|GUILIN_GPADC_EN);
    	PMIC_WRITE_REG_GPADC(GUILIN_GPADC_MISC_CONFIG_REG2,tmp);
	}else
	#endif
	#if !defined(NOT_SUPPORT_PM813)
	if(PMIC_IS_PM813()||PMIC_IS_PM813S())
	{
    	tmp = PMIC_READ_REG_GPADC(NINGBO_GPADC_MODE_CONTROL_REG);
    	tmp |= (NINGBO_NON_STOP|NINGBO_GPADC_EN);
    	PMIC_WRITE_REG_GPADC(NINGBO_GPADC_MODE_CONTROL_REG,tmp);
	}else
	#endif
	{
		return;
	}
}

void PM812_GPADC_NONSTOP_TRIG_DISABLE(void)
{
    UINT8 tmp;
    #if !defined(NOT_SUPPORT_PM802)
	if (PMIC_IS_PM802()||PMIC_IS_PM802S())
	{
		tmp = PMIC_READ_REG_GPADC(GUILIN_GPADC_MISC_CONFIG_REG2);
		tmp &= ~(GUILIN_NON_STOP|GUILIN_GPADC_EN);
		PMIC_WRITE_REG_GPADC(GUILIN_GPADC_MISC_CONFIG_REG2,tmp);
	}else 
	#endif
	#if !defined(NOT_SUPPORT_PM813)
	if(PMIC_IS_PM813()||PMIC_IS_PM813S())
	{
    	tmp = PMIC_READ_REG_GPADC(NINGBO_GPADC_MODE_CONTROL_REG);
    	tmp &= ~(NINGBO_NON_STOP|NINGBO_GPADC_EN);
    	PMIC_WRITE_REG_GPADC(NINGBO_GPADC_MODE_CONTROL_REG,tmp);
	}else
	#endif
	{
		return;
	}
}

void PM812_BD_ENABLE(UINT8 bit)
{
}

void PM812_BD_DISABLE(UINT8 bit)
{
}
//sec: 1~16
UINT8 PM812_GET_LONKEY_PRESS_TIME(void)
{
    UINT8 tmp = 0;

    #if !defined(NOT_SUPPORT_PM802)
	if (PMIC_IS_PM802()||PMIC_IS_PM802S())
	{
    	tmp = PMIC_READ_REG_BASE(GUILIN_RTC_MISC_3_REG);
    	return (((tmp >> 4) & 0x0f) + 1);
	}
	else 
    #endif
	if (PMIC_IS_PM803())
	{
    	tmp = PMIC_READ_REG_BASE(GUILIN_LITE_RTC_MISC_3_REG);
    	return (((tmp >> 4) & 0x0f) + 1);
	}
	#if !defined(NOT_SUPPORT_PM813)
	else if(PMIC_IS_PM813()||PMIC_IS_PM813S())
	{
    	tmp = PMIC_READ_REG_BASE(NINGBO_RTC_MISC_3_REG);
    	return (((tmp >> 4) & 0x0f) + 1);
	}
	#endif
	else
	{
		return tmp;
	}
}

//sec: 1~16
void PM812_SET_LONKEY_PRESS_TIME(UINT8 sec)
{
    UINT8 tmp;

    #if !defined(NOT_SUPPORT_PM802)
	if (PMIC_IS_PM802()||PMIC_IS_PM802S())
	{
    	tmp = PMIC_READ_REG_BASE(GUILIN_RTC_MISC_3_REG);
    	tmp &= 0x0f;
    	sec = ((sec-1) <<4);
    	PMIC_WRITE_REG_BASE(GUILIN_RTC_MISC_3_REG,(tmp|sec));
	}
	else 
    #endif
	if (PMIC_IS_PM803())
	{
    	tmp = PMIC_READ_REG_BASE(GUILIN_LITE_RTC_MISC_3_REG);
    	tmp &= 0x0f;
    	sec = ((sec-1) <<4);
    	PMIC_WRITE_REG_BASE(GUILIN_LITE_RTC_MISC_3_REG,(tmp|sec));
	}
	#if !defined(NOT_SUPPORT_PM813)
	else if(PMIC_IS_PM813()||PMIC_IS_PM813S())
	{
    	tmp = PMIC_READ_REG_BASE(NINGBO_RTC_MISC_3_REG);
    	tmp &= 0x0f;
    	sec = ((sec-1) <<4);
    	PMIC_WRITE_REG_BASE(NINGBO_RTC_MISC_3_REG,(tmp|sec));
	}
	#endif
}

void PM812_LONKEY_ENABLE_SET(UINT8 LONGKEY_NUM,BOOL enable)
{
    UINT8 tmp;

    #if !defined(NOT_SUPPORT_PM802)
	if (PMIC_IS_PM802()||PMIC_IS_PM802S())
	{
        tmp = PMIC_READ_REG_BASE(GUILIN_CLK_32K_SEL_REG);
        //LONGKEY_1
        if(LONGKEY_NUM == GUILIN_LONGKEY_1){
            enable?(tmp |= GUILIN_LONGKEY_EN1):(tmp &= (~GUILIN_LONGKEY_EN1));
        	PMIC_UART_DEBUG("PM802_LONKEY_ENABLE_SET LONGKEY_1,tmp=0x%x \r\n",tmp);
            PMIC_WRITE_REG_BASE(GUILIN_CLK_32K_SEL_REG,tmp);
        //LONGKEY_2
        }else if (LONGKEY_NUM == GUILIN_LONGKEY_2){
            enable?(tmp |= GUILIN_LONGKEY_EN2):(tmp &= (~GUILIN_LONGKEY_EN2));
        	PMIC_UART_DEBUG("PM802_LONKEY_ENABLE_SET LONGKEY_2,tmp=0x%x \r\n",tmp);
            PMIC_WRITE_REG_BASE(GUILIN_CLK_32K_SEL_REG,tmp);
        }
	}
	else 
    #endif
	if (PMIC_IS_PM803())
	{
        tmp = PMIC_READ_REG_BASE(GUILIN_LITE_CLK_32K_SEL_REG);
        //LONGKEY_1
        if(LONGKEY_NUM == GUILIN_LITE_LONGKEY_1){
            enable?(tmp |= GUILIN_LITE_LONGKEY_EN1):(tmp &= (~GUILIN_LITE_LONGKEY_EN1));
        	PMIC_UART_DEBUG("PM803_LONKEY_ENABLE_SET LONGKEY_1,tmp=0x%x \r\n",tmp);
            PMIC_WRITE_REG_BASE(GUILIN_LITE_CLK_32K_SEL_REG,tmp);
        //LONGKEY_2
        }else if (LONGKEY_NUM == GUILIN_LITE_LONGKEY_2){
            enable?(tmp |= GUILIN_LITE_LONGKEY_EN2):(tmp &= (~GUILIN_LITE_LONGKEY_EN2));
        	PMIC_UART_DEBUG("PM803_LONKEY_ENABLE_SET LONGKEY_2,tmp=0x%x \r\n",tmp);
            PMIC_WRITE_REG_BASE(GUILIN_LITE_CLK_32K_SEL_REG,tmp);
        }
	}
	#if !defined(NOT_SUPPORT_PM813)
	else if(PMIC_IS_PM813()||PMIC_IS_PM813S())
	{
        tmp = PMIC_READ_REG_BASE(NINGBO_CLK_32K_SEL_REG);
        //LONGKEY_1
        if(LONGKEY_NUM == NINGBO_LONGKEY_1){
            enable?(tmp |= NINGBO_LONGKEY_EN1):(tmp &= (~NINGBO_LONGKEY_EN1));
        PMIC_UART_DEBUG("PM813_LONKEY_ENABLE_SET LONGKEY_1,tmp=0x%x \r\n",tmp);
            PMIC_WRITE_REG_BASE(NINGBO_CLK_32K_SEL_REG,tmp);
        //LONGKEY_2
        }else if (LONGKEY_NUM == NINGBO_LONGKEY_2){
            enable?(tmp |= NINGBO_LONGKEY_EN2):(tmp &= (~NINGBO_LONGKEY_EN2));
        PMIC_UART_DEBUG("PM813_LONKEY_ENABLE_SET LONGKEY_2,tmp=0x%x \r\n",tmp);
            PMIC_WRITE_REG_BASE(NINGBO_CLK_32K_SEL_REG,tmp);
        }
	}
	#endif
}

//LONGKEY_NUM: 1/2
BOOL PM812_LONKEY_ENABLE_GET(UINT8 LONGKEY_NUM)
{
    #if !defined(NOT_SUPPORT_PM802)
	if(PMIC_IS_PM802()||PMIC_IS_PM802S())
	{
    	PMIC_UART_DEBUG("PM802_LONKEY_ENABLE_GET , NUM=%d",LONGKEY_NUM);
    	return (PMIC_READ_REG_BASE(GUILIN_CLK_32K_SEL_REG) &
    		((LONGKEY_NUM==GUILIN_LONGKEY_1)?GUILIN_LONGKEY_EN1:GUILIN_LONGKEY_EN2));
	}
	else 
    #endif
	if(PMIC_IS_PM803())
	{
    	PMIC_UART_DEBUG("PM803_LONKEY_ENABLE_GET , NUM=%d",LONGKEY_NUM);
    	return (PMIC_READ_REG_BASE(GUILIN_LITE_CLK_32K_SEL_REG) &
    		((LONGKEY_NUM==GUILIN_LITE_LONGKEY_1)?GUILIN_LITE_LONGKEY_EN1:GUILIN_LITE_LONGKEY_EN2));
	}
	#if !defined(NOT_SUPPORT_PM813)
	else if(PMIC_IS_PM813()||PMIC_IS_PM813S())
	{
        PMIC_UART_DEBUG("PM813_LONKEY_ENABLE_GET , NUM=%d",LONGKEY_NUM);
        return (PMIC_READ_REG_BASE(NINGBO_CLK_32K_SEL_REG) &
            ((LONGKEY_NUM==NINGBO_LONGKEY_1)?NINGBO_LONGKEY_EN1:NINGBO_LONGKEY_EN2));
	}
	#endif
	else
	{
		PMIC_UART_DEBUG("PM812_LONKEY_ENABLE_GET: it shouldn't reach here, NUM=%d",LONGKEY_NUM);

        return FALSE;
	}
}

void PM812_VBUCK1_CFG(UINT8 value)
{
}

void PM812_VBUCK2_CFG(UINT8 value)
{
}

void PM812_VLDO7_SWITCH(UINT8 onoff)
{
}

void PM812_PwmSetLevel(UINT8 level)
{
}

//ICAT EXPORTED FUNCTION - SW_PLAT, PM812, Buck1Cfg
void PM812_Buck1_Config(volatile void *base)
{
}

//ICAT EXPORTED FUNCTION - SW_PLAT, PM812, Buck2Cfg
void PM812_Buck2_Config(volatile void *base)
{
}

extern unsigned char CRN_SVC_FP[];
unsigned int get_cp_dvc_fix_by_dsp(void);

void PlatformVcoreConfigTop(void)
{   // Set 1.10V by default for top level
    if (get_cp_dvc_fix_by_dsp()){
        PMIC_UART_DEBUG("%s dvc fixed!\r\n", __func__);
        return;
    }
	switch (PMIC_ID_GET())
	{
	    #if !defined(NOT_SUPPORT_PM813)
		case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
			Ningbo_VBUCK1_CFG(NINGBO_VBUCK_1V1000);
			break;
		#endif
		#if !defined(NOT_SUPPORT_PM802)
		case PMIC_802:
        case PMIC_802S:
	        Guilin_VBUCK1_CFG(GUILIN_VBUCK_1V1000);
		    break;
		#endif
		#if !defined(NOT_SUPPORT_PM803)
		case PMIC_803:
            GuilinLite_VBUCK1_CFG(GUILIN_LITE_VBUCK_1V1000);
            break;
        #endif
        #if !defined(NOT_SUPPORT_PM803L)
		case PMIC_803L:
            GuilinLite2_VBUCK1_CFG(CRN_SVC_FP[3]);
            break;
        #endif
		default:
			ASSERT(0);
			break;
	}
}

void PlatformVcoreConfigHigh(void)
{   // Set 1.05V by default for higher level
    if (get_cp_dvc_fix_by_dsp()){
        PMIC_UART_DEBUG("%s dvc fixed!\r\n", __func__);
        return;
    }
	switch (PMIC_ID_GET())
	{
	    #if !defined(NOT_SUPPORT_PM813)
		case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
			Ningbo_VBUCK1_CFG(NINGBO_VBUCK_1V0500);
			break;
		#endif
		#if !defined(NOT_SUPPORT_PM802)
		case PMIC_802:
        case PMIC_802S:
	        Guilin_VBUCK1_CFG(GUILIN_VBUCK_1V0500);
		    break;
        #endif
        #if !defined(NOT_SUPPORT_PM803)
		case PMIC_803:
            GuilinLite_VBUCK1_CFG(GUILIN_LITE_VBUCK_1V0500);
            break;
        #endif
		#if !defined(NOT_SUPPORT_PM803L)
		case PMIC_803L:
            GuilinLite2_VBUCK1_CFG(CRN_SVC_FP[2]);
            break;
        #endif
		default:
			ASSERT(0);
			break;
	}
}

void PlatformVcoreConfigLow(void)
{   // Set 1.00V by default
    if (get_cp_dvc_fix_by_dsp()){
        PMIC_UART_DEBUG("%s dvc fixed!\r\n", __func__);
        return;
    }
	switch (PMIC_ID_GET())
	{
	    #if !defined(NOT_SUPPORT_PM813)
		case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
			Ningbo_VBUCK1_CFG(NINGBO_VBUCK_1V0000);
			break;
		#endif
		#if !defined(NOT_SUPPORT_PM802)
		case PMIC_802:
        case PMIC_802S:
	        Guilin_VBUCK1_CFG(GUILIN_VBUCK_1V0000);
		    break;
		#endif
		#if !defined(NOT_SUPPORT_PM803)
		case PMIC_803:
            GuilinLite_VBUCK1_CFG(GUILIN_LITE_VBUCK_1V0000);
            break;
        #endif
        #if !defined(NOT_SUPPORT_PM803L)
		case PMIC_803L:
            GuilinLite2_VBUCK1_CFG(CRN_SVC_FP[0]);
            break;
        #endif
		default:
			ASSERT(0);
			break;
	}
}


void PlatformBuckAptConfig(void)
{
	switch (PMIC_ID_GET())
	{
	    #if !defined(NOT_SUPPORT_PM813)
		case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
            Ningbo_BUCK3_Enable();
            Ningbo_APT_enable();
			break;
		#endif
		#if !defined(NOT_SUPPORT_PM802)
		case PMIC_802:
        case PMIC_802S:
            Guilin_BUCK5_Enable();
            Guilin_APT_enable();
		    break;
		#endif
		case PMIC_803:
        case PMIC_803L:
		    //Guilin-lite doesn't support RF APT.
		    break;
		default:
			ASSERT(0);
			break;
	}
}

void PlatformVcoreConfigForDro(void)
{   // Set 1.05V for DRO reading
    UINT8 buck1;

    if(CHIP_IS_CRANE)
        buck1 = VOLTAGE_1_05;
    else if(CHIP_IS_CRANEG)
        buck1 = VOLTAGE_0_80;
    else if(CHIP_IS_CRANEM || CHIP_IS_CRANEL || CHIP_IS_CRANELS)
        buck1 = VOLTAGE_0_90;
    else if(CHIP_IS_CRANELR)
        ;//PM803L
    else
        return;

	switch (PMIC_ID_GET())
	{
	    #if !defined(NOT_SUPPORT_PM813)
		case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
			Ningbo_VBUCK1_CFG(buck1);
			break;
		#endif
		#if !defined(NOT_SUPPORT_PM802)
		case PMIC_802:
        case PMIC_802S:
	        Guilin_VBUCK1_CFG(buck1);
		    break;
		#endif
		#if !defined(NOT_SUPPORT_PM803)
		case PMIC_803:
            GuilinLite_VBUCK1_CFG(buck1);
            break;
        #endif
        #if !defined(NOT_SUPPORT_PM803L)
		case PMIC_803L:
            GuilinLite2_VBUCK1_CFG(GUILIN_LITE2_VBUCK_0V90);//1602 or 1608
            break;
        #endif
		default:
			ASSERT(0);
			break;
	}
}

void PlatformRfSwitchPowerConfig(void)
{
	switch (PMIC_ID_GET())
	{
	#if !defined(NOT_SUPPORT_PM813)
		case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
            Ningbo_Ldo_1_set_2_8();
//            Ningbo_LDO_Set_Slpmode(NINGBO_LDO1_SLEEP_MODE_REG,NINGBO_LDO_OFF); //also used for LCD, can't off.
            Ningbo_Ldo_1_set(TRUE);
			break;
	#endif
	#if !defined(NOT_SUPPORT_PM802)
		case PMIC_802:
        case PMIC_802S:
            Guilin_Ldo_1_set_2_8();
#ifdef PROJ_ASR_APP_001
            Guilin_LDO_Set_Slpmode(GUILIN_LDO1_SLEEP_MODE_REG,GUILIN_LDO_ACTIVE);
#else
            Guilin_LDO_Set_Slpmode(GUILIN_LDO1_SLEEP_MODE_REG,GUILIN_LDO_OFF);
#endif
            Guilin_Ldo_1_set(TRUE);
		    break;
    #endif
	#if !defined(NOT_SUPPORT_PM803)
		case PMIC_803:
            GuilinLite_Ldo_6_set_2_8();
#ifdef PROJ_ASR_APP_001
            GuilinLite_LDO_Set_Slpmode(GUILIN_LITE_LDO6_SLEEP_MODE_REG,GUILIN_LITE_LDO_ACTIVE);
#else
	#ifndef MIN_SYS
	if (!IsMiniSystem())
	{
		#if QUECTEL_PROJECT_CUST
			//add 20240711 解决800M LE新PA硬件休眠耗流高问题
			#ifdef __QUECTEL_PROJECT_EC800MCN_LE__
					extern int quec_pa_level_check(void);
					if(1 == quec_pa_level_check()){
						GuilinLite_LDO_Set_Slpmode(GUILIN_LITE_LDO6_SLEEP_MODE_REG,GUILIN_LITE_LDO_ACTIVE);
					}else{
						GuilinLite_LDO_Set_Slpmode(GUILIN_LITE_LDO6_SLEEP_MODE_REG,GUILIN_LITE_LDO_OFF);
					}
			#else 
					GuilinLite_LDO_Set_Slpmode(GUILIN_LITE_LDO6_SLEEP_MODE_REG,GUILIN_LITE_LDO_OFF);
			#endif
		#else 
				GuilinLite_LDO_Set_Slpmode(GUILIN_LITE_LDO6_SLEEP_MODE_REG,GUILIN_LITE_LDO_OFF);
		#endif
	}else{
		GuilinLite_LDO_Set_Slpmode(GUILIN_LITE_LDO6_SLEEP_MODE_REG,GUILIN_LITE_LDO_OFF);
	}
	#endif
#endif
            GuilinLite_Ldo_6_set(TRUE);
            break;
    #endif
    #if !defined(NOT_SUPPORT_PM803L)
        case PMIC_803L:
            GuilinLite2_Ldo_6_set_2_8();
#ifdef PROJ_ASR_APP_001
            GuilinLite2_LDO_Set_Slpmode(GUILIN_LITE2_LDO6_SLEEP_MODE_REG,GUILIN_LITE2_LDO_ACTIVE);
#else
            GuilinLite2_LDO_Set_Slpmode(GUILIN_LITE2_LDO6_SLEEP_MODE_REG,GUILIN_LITE2_LDO_OFF);
#endif
            GuilinLite2_Ldo_6_set(TRUE);
            break;
    #endif
		default:
			ASSERT(0);
			break;
	}
}
#ifndef MIN_SYS
void Camera_Avdd_Power_off()
{
	#ifndef NOT_SUPPORT_PM813
    if(PMIC_IS_PM813() || PMIC_IS_PM813S())
    {
        Ningbo_LDO_Set_Enable(NINGBO_LDO10_ENABLE_REG,0);
    }
    else 
	#endif
	#ifndef NOT_SUPPORT_PM802
	if(PMIC_IS_PM802())	//PM802   
    {
		Guilin_Ldo_6_set(0);//EC600S USE PM802 LDO6 For AVDD
    }
    else 
	#endif
	#ifndef NOT_SUPPORT_PM803
	if(PMIC_IS_PM803()) 
    {
		GuilinLite_Ldo_7_set(0);
    }		
	#endif
}

//关闭CamVdd的电
void Camera_Avdd_Power_set(Camera_Pwr_Val ldoVal)
{
    #if !defined(NOT_SUPPORT_PM813)
    if (ldoVal > CAM_VDD_MAX)
    {
        fatal_printf("Wrong Camera AVDD input!\r\n");
        return;
    }
    
    if (PMIC_IS_PM813()||PMIC_IS_PM813S())
    {
        Ningbo_LDO_Set_VOUT(NINGBO_LDO10_ACTIVE_VOUT_REG, (ldoVal<<2));
        Ningbo_LDO_Set_Enable(NINGBO_LDO10_ENABLE_REG,1);
    }
	#endif
	#if !defined(NOT_SUPPORT_PM802)
	if(PMIC_IS_PM802())//shaohua.li //EC600S PM802 LDO6 For Camera AVDD
	{	
		Guilin_Ldo_6_set_2_8();
		Guilin_Ldo_6_set(1);
	}
    else 
	#endif
#ifndef NOT_SUPPORT_PM803
	if(PMIC_IS_PM803())
    {
		GuilinLite_Ldo_7_set_2_8();
		GuilinLite_Ldo_7_set(1);
    }
#endif
}

void Camera_Dvdd_Power_set(Camera_Pwr_Val ldoVal)
{
    #if !defined(NOT_SUPPORT_PM813)
    if (ldoVal > CAM_VDD_MAX)
    {
        fatal_printf("Wrong Camera DVDD input!\r\n");
        return;
    }
    
    if (PMIC_IS_PM813()||PMIC_IS_PM813S())
    {
        Ningbo_LDO_Set_VOUT(NINGBO_LDO11_ACTIVE_VOUT_REG, (ldoVal<<2));
        Ningbo_LDO_Set_Enable(NINGBO_LDO11_ENABLE_REG,1);
    }
    #endif
}

//关闭CamIOVDD的电
void Camera_IOvdd_Power_off()
{
#ifndef NOT_SUPPORT_PM813
	if(PMIC_IS_PM813() || PMIC_IS_PM813S())
	{
		Ningbo_LDO_Set_Enable(NINGBO_LDO13_ENABLE_REG,0);
	}
	else 
#endif
#ifndef NOT_SUPPORT_PM802
	if(PMIC_IS_PM802()) //PM802  
	{
		if(CHIP_IS_CRANEM)//600ncn_ld
		{
			raw_uart_log("hard_ver is v1.2\r\n");			  
			gpio_direction_output(49);
			gpio_set_value(49,1);
		}
		else //600s
		{
			Guilin_Ldo_4_set(on_off);//EC600S USE PM802 LDO6 For IOVDD
		}
	}
	else 
#endif
#ifndef NOT_SUPPORT_PM803
	if(PMIC_IS_PM803()) 
	{
		//quec_debug_print_uart("User Gpio(%d) Ctrl CAMIOVDD Off\r\n",QUEC_GPIO_CTRL_CAMIOVDD_PIN);			   
		gpio_direction_output(QUEC_GPIO_CTRL_CAMIOVDD_PIN);
		gpio_set_value(QUEC_GPIO_CTRL_CAMIOVDD_PIN,GPIORC_HIGH);
	}
#endif
}

void Camera_IOvdd_Power_set(Camera_Pwr_Val ldoVal)
{
    #if !defined(NOT_SUPPORT_PM813)
    UINT8 tmp;
    if (ldoVal > CAM_VDD_MAX)
    {
        fatal_printf("Wrong Camera IOVDD input!\r\n");
        return;
    }
    
    if (PMIC_IS_PM813()||PMIC_IS_PM813S())
    {
        switch(ldoVal)
        {
            case CAM_VDD_1V70: tmp = NINGBO_LDO13_ACTIVE_1V70; break;
            case CAM_VDD_1V80: tmp = NINGBO_LDO13_ACTIVE_1V80; break;
            case CAM_VDD_1V90: tmp = NINGBO_LDO13_ACTIVE_1V90; break;
            case CAM_VDD_2V50: tmp = NINGBO_LDO13_ACTIVE_2V50; break;
            case CAM_VDD_2V80: tmp = NINGBO_LDO13_ACTIVE_2V80; break;
            case CAM_VDD_2V90: tmp = NINGBO_LDO13_ACTIVE_2V90; break;
            case CAM_VDD_3V10: tmp = NINGBO_LDO13_ACTIVE_3V10; break;
            case CAM_VDD_3V30: tmp = NINGBO_LDO13_ACTIVE_3V30; break;
            default:
            PMIC_UART_DEBUG("Camera IOvdd input value Not supported, use 2.8v!\r\n");
            tmp = NINGBO_LDO13_ACTIVE_2V80; break;
        }
        Ningbo_LDO_Set_VOUT(NINGBO_LDO13_ACTIVE_VOUT_REG, tmp);
        Ningbo_LDO_Set_Enable(NINGBO_LDO13_ENABLE_REG,1);
    }
	else 
	#endif //!defined(NOT_SUPPORT_PM813)
	#if !defined(NOT_SUPPORT_PM802)
    if(PMIC_IS_PM802())//EC600S(asr1601) use PM802 LD04 For iovdd
    {
        switch(ldoVal)
        {
            case CAM_VDD_1V70: tmp = GUILIN_LDO4_ACTIVE_1V70; break;
            case CAM_VDD_1V80: tmp = GUILIN_LDO4_ACTIVE_1V80; break;
            case CAM_VDD_1V85: tmp = GUILIN_LDO4_ACTIVE_1V85; break;
            case CAM_VDD_1V90: tmp = GUILIN_LDO4_ACTIVE_1V90; break;
            case CAM_VDD_2V50: tmp = GUILIN_LDO4_ACTIVE_2V50; break;
            case CAM_VDD_2V80: tmp = GUILIN_LDO4_ACTIVE_2V80; break;
            default: 
            uart_printf("Camera IOvdd input value Not supported, use 1.8v!\r\n");
            tmp = GUILIN_LDO4_ACTIVE_1V80; 
			break;                     
        }
		if(CHIP_IS_CRANEM)//600ncn_ld
        {  
        	#if defined __QUECTEL_PROJECT_EG915NEU_AG__
            	GpioSetDirection(10, GPIO_OUT_PIN);
            	GpioSetLevel(10,GPIORC_LOW);
			#else
				GpioSetDirection(49, GPIO_OUT_PIN);
            	GpioSetLevel(49,GPIORC_LOW);
			#endif
        }
		else{
			Guilin_Ldo_4_set_Vout(tmp);
            Guilin_Ldo_4_set(1);
		}   
    }
    else 
	#endif
	if(PMIC_IS_PM803())
    {
        fatal_printf("hard_ver is v1.2\r\n"); 

		//EC600Mxxx系列通过控制GPIO,开启和关闭IOVDD
		GpioSetDirection(QUEC_GPIO_CTRL_CAMIOVDD_PIN, GPIO_OUT_PIN);
		GpioSetLevel(QUEC_GPIO_CTRL_CAMIOVDD_PIN,GPIORC_LOW);//拉低使能CAMIOVDD
    }
}
#endif


UINT8 SysRestartReasonGlobal=0;
UINT32 SysRestartReasonGetFlag=0;

void SysRestartReasonGetGlobal(void)
{
	if(SysRestartReasonGetFlag==0)
	{
        switch (PMIC_ID_GET())
        {
            #if !defined(NOT_SUPPORT_PM813)
            case PMIC_813:
            case PMIC_813A3:
            case PMIC_813S:
                SysRestartReasonGlobal = PMIC_READ_REG_BASE(PMIC_REG_FOR_SW_RESTART_REASON_STR);
                break;
            #endif
            #if !defined(NOT_SUPPORT_PM802)
            case PMIC_802:
            #endif
            case PMIC_803:
                SysRestartReasonGlobal = PMIC_READ_REG_BASE(PMIC_REG_FOR_USR_DEF_FLAGS_STR);
                break;
            #if !defined(NOT_SUPPORT_PM802)
            case PMIC_802S:
                SysRestartReasonGlobal = PMIC_READ_REG_BASE(PM802S_REG_FOR_USR_DEF_FLAGS_STR);
                break;
            #endif
            case PMIC_803L:
                SysRestartReasonGlobal = PMIC_READ_REG_BASE(PM803L_REG_FOR_USR_DEF_FLAGS_STR);
                break;
            default:
                ASSERT(0);
                break;
        }

		SysRestartReasonGetFlag=1;
	}

}


void SysRestartReasonSet(SW_RESTART_REASON reason)
{
    UINT8 desc[40] = {0};
    UINT8 rsn = (UINT8)reason;


    switch (rsn)
    {
        case 'C':
            strcpy((char *)desc, "Charging in powering off"); //set by UI
            break;
        case 'R':
            strcpy((char *)desc, "Rd production mode"); //set by preboot
            break;
        case 'A':
            strcpy((char *)desc, "rtc Alarm"); //set according to pmic
            break;
        case 'N':
            strcpy((char *)desc, "Normal powering on"); //set otherwise
            break;
        case 'E':
            strcpy((char *)desc, "Error reset (WDT)"); //set by WDT indication
            break;
        case 'D':
            strcpy((char *)desc, "image Download"); //set by AT cmd and checked by preboot
            break;
        default:
            PMIC_UART_DEBUG("[SYSRST_SET]Restart reason not supported!");
            return;
    }

    switch (PMIC_ID_GET())
    {
        #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
            PMIC_WRITE_REG_BASE(PMIC_REG_FOR_SW_RESTART_REASON_STR, rsn);
            break;
        #endif
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        #endif
        case PMIC_803:
            PMIC_WRITE_REG_BASE(PMIC_REG_FOR_USR_DEF_FLAGS_STR, rsn);
            break;
        case PMIC_803L:
            PMIC_WRITE_REG_BASE(PM803L_REG_FOR_USR_DEF_FLAGS_STR, rsn);
            break;
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802S:
            PMIC_WRITE_REG_BASE(PM802S_REG_FOR_USR_DEF_FLAGS_STR, rsn);
            break;
        #endif
        default:
            ASSERT(0);
            break;
    }

    PMIC_UART_DEBUG("[SYSRST]Restart reason set: %s", desc);
}

UINT8 SysRestartReasonGet(void)
{
    UINT8 reason = 0;

	if(SysRestartReasonGetFlag==0)
    {
        switch (PMIC_ID_GET())
        {
            #if !defined(NOT_SUPPORT_PM813)
            case PMIC_813:
            case PMIC_813A3:
            case PMIC_813S:
                reason=PMIC_READ_REG_BASE(PMIC_REG_FOR_SW_RESTART_REASON_STR);
                break;
            #endif
            #if !defined(NOT_SUPPORT_PM802)
            case PMIC_802:
            #endif
            case PMIC_803:
                reason=PMIC_READ_REG_BASE(PMIC_REG_FOR_USR_DEF_FLAGS_STR);
                break;
            #if !defined(NOT_SUPPORT_PM802)
            case PMIC_802S:
                reason=PMIC_READ_REG_BASE(PM802S_REG_FOR_USR_DEF_FLAGS_STR);
                break;
            #endif
            case PMIC_803L:
                reason=PMIC_READ_REG_BASE(PM803L_REG_FOR_USR_DEF_FLAGS_STR);
                break;
            default:
                ASSERT(0);
                break;
        }
    }
	else
	    reason = SysRestartReasonGlobal;

	if(reason==0)
		reason='N';

    switch (reason)
    {
        case 'C':
        case 'R':
        case 'A':
        case 'N':
        case 'E':
            break;
        default:
            return 0;
    }
    return reason;
}

void SysRestartReasonPrint(void)
{
    UINT8 desc[40] = {0};
    UINT8 reason = 0;

	if(SysRestartReasonGetFlag==0)
    {
        switch (PMIC_ID_GET())
        {
            #if !defined(NOT_SUPPORT_PM813)
            case PMIC_813:
            case PMIC_813A3:
            case PMIC_813S:
                reason=PMIC_READ_REG_BASE(PMIC_REG_FOR_SW_RESTART_REASON_STR);
                break;
            #endif
            #if !defined(NOT_SUPPORT_PM802)
            case PMIC_802:
            #endif
            case PMIC_803:
                reason=PMIC_READ_REG_BASE(PMIC_REG_FOR_USR_DEF_FLAGS_STR);
                break;
            #if !defined(NOT_SUPPORT_PM802)
            case PMIC_802S:
                reason=PMIC_READ_REG_BASE(PM802S_REG_FOR_USR_DEF_FLAGS_STR);
                break;
            #endif
            case PMIC_803L:
                reason=PMIC_READ_REG_BASE(PM803L_REG_FOR_USR_DEF_FLAGS_STR);
                break;
            default:
                ASSERT(0);
                break;
        }
    }
	else
	    reason = SysRestartReasonGlobal;

	if(reason==0)
		reason='N';

    switch (reason)
    {
        case 'C':
            strcpy((char *)desc, "Charging in powering off");
            break;
        case 'R':
            strcpy((char *)desc, "Rd production mode");
            break;
        case 'A':
            strcpy((char *)desc, "rtc Alarm");
            break;
        case 'N':
            strcpy((char *)desc, "Normal power on");
            break;
        case 'E':
            strcpy((char *)desc, "Error reset (WDT)");
            break;
        default:
            PMIC_UART_DEBUG("[SYSRST_PRT]SW restart reason unknown!\r\n");
            return;
    }
    RTI_LOG("SW restart reason: %s", desc);
}

UINT8 isSysRestartByCharging(void)
{
    return (SysRestartReasonGet() == 'C');
}

UINT8 isSysRestartByRdProduction(void)
{
    return (SysRestartReasonGet() == 'R');
}

UINT8 isSysRestartByAlarm(void)
{
    return (SysRestartReasonGet() == 'A');
}

UINT8 isSysRestartByNormal(void)
{
    return (SysRestartReasonGet() == 'N');
}

UINT8 isSysRestartByError(void)
{
    return (SysRestartReasonGet() == 'E');
}

void pmic_user_defined_flags_set(UINT8 flag)
{
    UINT8 var = 0;

    #if !defined(NOT_SUPPORT_PM813)
    if(PMIC_IS_PM813()||PMIC_IS_PM813S())
    {
        var=PMIC_READ_REG_BASE(PMIC_REG_FOR_USR_DEF_FLAGS_STR);
        var &= ~0xF;
        var |= (flag & 0xF); //only use low 4 bits
        PMIC_WRITE_REG_BASE(PMIC_REG_FOR_USR_DEF_FLAGS_STR, var);
    }
    else
    #endif
    if(PMIC_IS_PM802()||PMIC_IS_PM803()||PMIC_IS_PM802S())
    {
        var=PMIC_READ_REG_BASE(PM802_REG_FOR_USR_DEF_FLAGS_STR);
        var &= ~0xF0;
        var |= (flag<<4); //only use high 4 bits
        PMIC_WRITE_REG_BASE(PM802_REG_FOR_USR_DEF_FLAGS_STR, var);
    }
}

UINT8 pmic_user_defined_flags_get(void)
{
    UINT8 var = 0;

    #if !defined(NOT_SUPPORT_PM813)
    if(PMIC_IS_PM813()||PMIC_IS_PM813S())
    {
        var = PMIC_READ_REG_BASE(PMIC_REG_FOR_USR_DEF_FLAGS_STR);
        return (var & 0xF); //only use low 4 bits
    }
    else
    #endif
    if(PMIC_IS_PM802()||PMIC_IS_PM803()||PMIC_IS_PM802S())
    {
        var=PMIC_READ_REG_BASE(PM802_REG_FOR_USR_DEF_FLAGS_STR);
        return (var>>4); //only use high 4 bits
    }
	else
	{
		return var;
	}
}
//Sharon.li@20230424 移远代码不使用如下函数
#ifndef QUECTEL_PROJECT_CUST
BOOL pmic_lcdbacklight_current_status_get(void)
{
    #if !defined(NOT_SUPPORT_PM813)
    if (PMIC_IS_PM813()||PMIC_IS_PM813S()){
        return PM813_LcdBacklight_Status_Get();
    }else
    #endif
    #if (!defined(NOT_SUPPORT_PM802))
    if(PMIC_IS_PM802()||PMIC_IS_PM802S()){
        return PM802_LcdBacklight_Status_Get();
    }else
    #endif
    #if (!defined(NOT_SUPPORT_PM803))
    if(PMIC_IS_PM803()){
        return PM803_LcdBacklight_Status_Get();
    }else
    #endif
    {
        return FALSE;//not supported for other PMIC in this func
    }
}

UINT8 pmic_lcdbacklight_level_get(void)
{
    #if !defined(NOT_SUPPORT_PM813)
    if (PMIC_IS_PM813()||PMIC_IS_PM813S()){
        return PM813_LcdBacklight_Level_Get();
    }else
    #endif
    #if (!defined(NOT_SUPPORT_PM802))
    if(PMIC_IS_PM802()||PMIC_IS_PM802S()){
        return PM802_LcdBacklight_Level_Get();
    }else
    #endif
    #if (!defined(NOT_SUPPORT_PM803))
    if(PMIC_IS_PM803()){
        return PM803_LcdBacklight_Level_Get();
    }else
    #endif
    {
        return 0xFF;//not supported for other PMIC in this func
    }
}

//Indicate for UI whether LCD is initialized within LOGO.bin
BOOL m_lcd_ever_configed = FALSE;

void pmic_userdata_set_app_lcd_ever_configed(void)
{
    unsigned char var = 0;

    if( m_lcd_ever_configed == FALSE)
    {
        #if !defined(NOT_SUPPORT_PM813)
        if(PMIC_IS_PM813())
        {//use BP_0xF7[4]
    	    NingboRead( NINGBO_BASE_Reg, NINGBO_RTC_USER_DATA_4_REG, &var );
    	    var |= 0x10; //BIT_4
    	    NingboWrite( NINGBO_BASE_Reg, NINGBO_RTC_USER_DATA_4_REG, var );
	    }
	    else if(PMIC_IS_PM813S())
        {//use BP_0xCF[4]
    	    NingboRead( NINGBO_BASE_Reg, NINGBO2_RTC_USER_DATA_15_REG, &var );
    	    var |= 0x10; //BIT_4
    	    NingboWrite( NINGBO_BASE_Reg, NINGBO2_RTC_USER_DATA_15_REG, var );
	    }
        else
        #endif
        #if (!defined(NOT_SUPPORT_PM802))
        if(PMIC_IS_PM802()||PMIC_IS_PM802S())
        {//use BP_0xEB[7]
            GuilinRead( GUILIN_BASE_Reg, 0xEB, &var );
            var |= 0x80; //BIT_7
            GuilinWrite( GUILIN_BASE_Reg, 0xEB, var );
        }else
        #endif
        #if (!defined(NOT_SUPPORT_PM803))
        if(PMIC_IS_PM803()){
            GuilinLiteRead( GUILIN_LITE_BASE_Reg, 0xEB, &var );
            var |= 0x80; //BIT_7
            GuilinLiteWrite( GUILIN_LITE_BASE_Reg, 0xEB, var );   
        }
        #endif
	    PMIC_UART_DEBUG("[%s]\r\n",__func__);
    }
}

//to detect LCD ever being configed during booting
BOOL pmic_userdata_get_app_lcd_ever_configed(void)
{
    unsigned char var = 0;

    if(m_lcd_ever_configed == FALSE)
    {
        #if !defined(NOT_SUPPORT_PM813)
        if(PMIC_IS_PM813())
        {//use BP_0xF7[4]
        	NingboRead( NINGBO_BASE_Reg, NINGBO_RTC_USER_DATA_4_REG, &var );
        	m_lcd_ever_configed = (var & 0x10)?TRUE:FALSE;
            NingboWrite( NINGBO_BASE_Reg, NINGBO_RTC_USER_DATA_4_REG, var&~(0x10));//clear corresponding bits
        }
        else if(PMIC_IS_PM813S())
        {//use BP_0xCF[4]
        	NingboRead( NINGBO_BASE_Reg, NINGBO2_RTC_USER_DATA_15_REG, &var );
        	m_lcd_ever_configed = (var & 0x10)?TRUE:FALSE;
            NingboWrite( NINGBO_BASE_Reg, NINGBO2_RTC_USER_DATA_15_REG, var&~(0x10));//clear corresponding bits
        }
        else
        #endif
        #if (!defined(NOT_SUPPORT_PM802))
        if(PMIC_IS_PM802()||PMIC_IS_PM802S())
        {//use BP_0xEB[7]
            GuilinRead( GUILIN_BASE_Reg, 0xEB, &var );
            m_lcd_ever_configed = (var & 0x80)?TRUE:FALSE;
            GuilinWrite( GUILIN_BASE_Reg, 0xEB, var&~(0x80));//clear corresponding bits
        }else
        #endif
        #if (!defined(NOT_SUPPORT_PM803))
        if(PMIC_IS_PM803())
        {
            GuilinLiteRead( GUILIN_LITE_BASE_Reg, 0xEB, &var );
            m_lcd_ever_configed = (var & 0x80)?TRUE:FALSE;
            GuilinLiteWrite( GUILIN_LITE_BASE_Reg, 0xEB, var&~(0x80));//clear corresponding bits
        }
        else
        #endif
        {
            PMIC_UART_DEBUG("[%s] failed\r\n",__func__);
        }
    }

    PMIC_UART_DEBUG("[%s]=[%d]\r\n",__func__,m_lcd_ever_configed);
    return m_lcd_ever_configed;
}
#endif

void pmic_set_sys_restart_reason(void)
{
    if (isSysRestartByRdProduction())
    {
        set_calib_production_mode(1); //RD production mode detected.
    }
    else if (Is_silentReset())
    {
        SysRestartReasonSet((SW_RESTART_REASON)'E'); //error
    }
    else if (SysRestartReasonGet() == 'C') //already signed by UI
    {
        ;
    }
    else if (PMIC_IS_ALARM_TRIGGERD_POWERUP())
    {
        SysRestartReasonSet((SW_RESTART_REASON)'A'); //alarm
    }
    else if (PM812_GET_POWER_UP_REASON() & ((0x1<<5)|(0x1<<0)))
    {
        SysRestartReasonSet((SW_RESTART_REASON)'N'); //fault_wu & onkey_wu
    }
    else if (PM812_GET_POWER_UP_REASON() & ((0x1<<6)|(0x1<<3)|(0x1<<2)))
    {
        SysRestartReasonSet((SW_RESTART_REASON)'C'); //charge -- vbus & bat_wu & exton2
    }
    else if (PMIC_IS_PM803() && (PM812_GET_POWER_UP_REASON() & (0x1<<1)))
    {
        SysRestartReasonSet((SW_RESTART_REASON)'C'); //charge -- exton1n for pm803
    }

	SysRestartReasonGetGlobal();
	SysRestartReasonSet((SW_RESTART_REASON)'N');
}

UINT32 PMIC_readVbat(void)
{
    switch (PMIC_ID_GET())
    {
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        case PMIC_802S:
            return pm802_get_battery_voltage();
        #endif
        #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
            return pm813_get_battery_voltage_withoutCharger();
        #endif
        #if !defined(NOT_SUPPORT_PM803)
		#ifndef LTEONLY_THIN  
        case PMIC_803:
			#ifdef ASR_PLATFORM_CRANEM
            return (UINT32)GetPm803VbatAdc(TEMP_NORMAL);
			#endif
        #endif
		#endif
        case PMIC_803L:
            return 0;
        default:
            ASSERT(0);
            return 0;
    }
}

//ICAT EXPORTED FUNCTION - SW_PLAT,PMIC,PMIC_Vbat
void PMIC_Vbat(void)
{
    UINT32 tmp = PMIC_readVbat();
    PMIC_UART_DEBUG("\r\nPMIC_Vbat: %d\r\n",tmp);
}
//Sharon.li@20230424 移远代码不使用如下函数
#ifndef QUECTEL_PROJECT_CUST
BOOL isLcdEverInitedUponBooting(void)
{
    return pmic_userdata_get_app_lcd_ever_configed();
}
#endif

//TODO  : may need further porting FUNCs
//
UINT8 PMCWriteRegister(UINT8 regToWrite, UINT8 value,UINT16 image_ena)
{
	return TRUE;
}

BOOL  PMCGetGPADCValue(PMC_adc_reg_t reg,PMCGetGPADCValueNotifyFunc bindFunc)
{
    return TRUE;
}

void   PMCNotifyEventBind (UINT32 mask,PMCNotifyEventFunc pmcBindFunc)
{
}

#ifdef QUEC_3601_PMIC_PWRKEY_9374

void PMIC_FAULT_WU_EN_ENABLE()
{
	UINT8 tmp;
	switch(pmic_id){
		case PMIC_802:
#ifdef QUEC_3601_PMIC_PWRKEY_12651
			   tmp = PMIC_READ_REG_BASE(GUILIN_FAULT_WU_REG);
		       tmp |= (GUILIN_FAULT_WU_ENABLE_BIT);
		       PMIC_WRITE_REG_BASE(GUILIN_FAULT_WU_REG,tmp);
		break;
#endif
#ifdef QUEC_1603_PM803_SUPPORT
		case PMIC_803:
		     tmp = PMIC_READ_REG_BASE(GUILIN_LITE_FAULT_WU_REG);
		     tmp |= (GUILIN_LITE_FAULT_WU_ENABLE_BIT);
		     PMIC_WRITE_REG_BASE(GUILIN_LITE_FAULT_WU_REG,tmp);
			 break;
#endif			 
#if !defined(NOT_SUPPORT_PM803L)
		case PMIC_803L:
			tmp = PMIC_READ_REG_BASE(GUILIN_LITE2_FAULT_WU_REG);
			tmp |= (GUILIN_LITE2_FAULT_WU_ENABLE_BIT);
			PMIC_WRITE_REG_BASE(GUILIN_LITE2_FAULT_WU_REG,tmp);
			break;
#endif
		case PMIC_812:
		       tmp = PMIC_READ_REG_BASE(PM812_RTC_MISC_5_REG);
		       tmp |= (PM812_RTC_FAULT_WU_EN_BIT);
		       PMIC_WRITE_REG_BASE(PM812_RTC_MISC_5_REG,tmp);
		       break;

		case PMIC_813:
        case PMIC_813A3: //forrest.liu@20201130 add for ASR new interface for  PMIC_ID_GET
        case PMIC_813S:			
			tmp = PMIC_READ_REG_BASE(NINGBO_FAULT_WU_REG);
			tmp |= (NINGBO_FAULT_WU_ENABLE_BIT);
			PMIC_WRITE_REG_BASE(NINGBO_FAULT_WU_REG,tmp);
		       break;

		default:
			break;
	}
}

void PMIC_FAULT_WU_ENABLE()
{
	UINT8 tmp;
	switch(pmic_id){
		case PMIC_802:
#ifdef QUEC_3601_PMIC_PWRKEY_12651
				tmp = PMIC_READ_REG_BASE(GUILIN_FAULT_WU_REG);
				tmp |= (GUILIN_FAULT_WU_BIT);
				PMIC_WRITE_REG_BASE(GUILIN_FAULT_WU_REG,tmp);
				break;
#endif
		case PMIC_812:
		       tmp = PMIC_READ_REG_BASE(PM812_RTC_MISC_5_REG);
		       tmp |= (PM812_RTC_FAULT_WU_BIT);
		       PMIC_WRITE_REG_BASE(PM812_RTC_MISC_5_REG,tmp);
		       break;
		case PMIC_813:
        case PMIC_813A3: //forrest.liu@20201130 add for ASR new interface for  PMIC_ID_GET			
			tmp = PMIC_READ_REG_BASE(NINGBO_FAULT_WU_REG);
			tmp |= (NINGBO_FAULT_WU_BIT);
			PMIC_WRITE_REG_BASE(NINGBO_FAULT_WU_REG,tmp);
		       break;
			   
        case PMIC_813S: //forrest.liu@20201130 add for ASR new interface for  PMIC_ID_GET
        	tmp = PMIC_READ_REG_BASE(NINGBO_FAULT_WU_REG);
            tmp |= (NINGBO2_FAULT_WU_BIT);
        	PMIC_WRITE_REG_BASE(NINGBO_FAULT_WU_REG,tmp);
            break;			   
#ifdef QUEC_1603_PM803_SUPPORT
		case PMIC_803:
			  	tmp = PMIC_READ_REG_BASE(GUILIN_LITE_FAULT_WU_REG);
			  	tmp |= (GUILIN_LITE_FAULT_WU_BIT);
			  	PMIC_WRITE_REG_BASE(GUILIN_LITE_FAULT_WU_REG,tmp);   
	    	   break;
#endif			   
#if !defined(NOT_SUPPORT_PM803L)			   
		case PMIC_803L:
				tmp = PMIC_READ_REG_BASE(GUILIN_LITE2_FAULT_WU_REG);
				tmp |= (GUILIN_LITE2_FAULT_WU_BIT);
				PMIC_WRITE_REG_BASE(GUILIN_LITE2_FAULT_WU_REG,tmp);
				break;
#endif
		default:
			break;
	}
}

#ifdef QUEC_3601_PMIC_PWRKEY_12651

void PMIC_FAULT_WU_EN_DISABLE()
{
	UINT8 tmp;
	switch(pmic_id)
	{
		case PMIC_813:
        case PMIC_813A3: //forrest.liu@20201130 add for ASR new interface for  PMIC_ID_GET
        case PMIC_813S:					
				tmp = PMIC_READ_REG_BASE(NINGBO_FAULT_WU_REG);
				tmp &= ~(NINGBO_FAULT_WU_ENABLE_BIT);
				PMIC_WRITE_REG_BASE(NINGBO_FAULT_WU_REG,tmp);
		       break;
		case PMIC_802:
				tmp = PMIC_READ_REG_BASE(GUILIN_FAULT_WU_REG);
				tmp &= ~(GUILIN_FAULT_WU_ENABLE_BIT);
				PMIC_WRITE_REG_BASE(GUILIN_FAULT_WU_REG,tmp);
				break;
#ifdef QUEC_1603_PM803_SUPPORT
		case PMIC_803:
			  	tmp = PMIC_READ_REG_BASE(GUILIN_LITE_FAULT_WU_REG);
			  	tmp &= ~(GUILIN_LITE_FAULT_WU_ENABLE_BIT);
			  	PMIC_WRITE_REG_BASE(GUILIN_LITE_FAULT_WU_REG,tmp);   
	    	   break;
#endif
#if !defined(NOT_SUPPORT_PM803L)			   
		case PMIC_803L:
				tmp = PMIC_READ_REG_BASE(GUILIN_LITE2_FAULT_WU_REG);
				tmp &= ~(GUILIN_LITE2_FAULT_WU_ENABLE_BIT);
				PMIC_WRITE_REG_BASE(GUILIN_LITE2_FAULT_WU_REG,tmp);
				break;
#endif	
		case PMIC_812:
		       tmp = PMIC_READ_REG_BASE(PM812_RTC_MISC_5_REG);
		       tmp &= ~(PM812_RTC_FAULT_WU_BIT);
		       PMIC_WRITE_REG_BASE(PM812_RTC_MISC_5_REG,tmp);
		       break;
		default:
			break;
	}
}
#endif

void PMIC_SW_RESET(void)
{
	UINT8 tmp;
	PMIC_FAULT_WU_EN_ENABLE();
	PMIC_FAULT_WU_ENABLE();
#ifdef AT_OVER_UART //workaround to remove extra 0x00 on cp uart tx when system power down
	if (CHIP_IS_CRANEL) 
	{
	  extern void PMIC_Set_CP_UART_PowerOff_and_AIB_3_3V(void);
	  PMIC_Set_CP_UART_PowerOff_and_AIB_3_3V();
	}
#endif
#ifdef QUECTEL_PROJECT_CUST
    USB2MgrDeviceUnplug();
	QUEC_SET_MAINUART_TX_GPIO();
#endif

	uart_printf("+PMIC_SW_RESET,pmic_id=0x%x\r\n",pmic_id);
	CPUartLogPrintf("+PMIC_SW_RESET,pmic_id=0x%x\r\n",pmic_id);


	//SW_RESET
	switch(pmic_id){
		case PMIC_812:
		       tmp = PMIC_READ_REG_BASE(PM812_WAKEUP_1_REG);
		       tmp |= PM812_SW_PDOWN_BIT;
		       PMIC_WRITE_REG_BASE(PM812_WAKEUP_1_REG,tmp);
		       break;
		case PMIC_813:
        case PMIC_813A3: //forrest.liu@20201130 add for ASR new interface for  PMIC_ID_GET
        case PMIC_813S:					
#ifdef QUEC_3601_PMIC_PWRKEY_12651
		   	   PMIC_WRITE_REG_BASE(0x4C,0x0); //disable PWM
#endif
		       tmp = PMIC_READ_REG_BASE(NINGBO_MISC_CFG_REG1);
		       tmp |= NINGBO_SW_PDOWN_BIT;
		       PMIC_WRITE_REG_BASE(NINGBO_MISC_CFG_REG1,tmp);
		       break;
		case PMIC_802:
	    		/*TODO*/
			   tmp = PMIC_READ_REG_BASE(GUILIN_WAKEUP_REG1);
		       tmp |= GUILIN_SW_PDOWN;
		       PMIC_WRITE_REG_BASE(GUILIN_WAKEUP_REG1,tmp);
	    	   break;
#ifdef QUEC_1603_PM803_SUPPORT
	    case PMIC_803:
			   tmp = PMIC_READ_REG_BASE(GUILIN_LITE_WAKEUP_REG1);
			   tmp |= GUILIN_LITE_SW_PDOWN;
			   PMIC_WRITE_REG_BASE(GUILIN_LITE_WAKEUP_REG1,tmp);   
	    	   break;
#endif			   
#if !defined(NOT_SUPPORT_PM803L)			   
	    case PMIC_803L:
			   tmp = PMIC_READ_REG_BASE(GUILIN_LITE2_WAKEUP_REG1);
	           tmp |= GUILIN_LITE2_SW_PDOWN_BIT;
	           PMIC_WRITE_REG_BASE(GUILIN_LITE2_WAKEUP_REG1,tmp);
	           break;
#endif
		default:
			break;

	}
}

void PMIC_SW_POWERDOWN(void)
{
	UINT8 tmp;
	#ifdef QUEC_1603_PM803_SUPPORT
		RTI_LOG("+PMIC_SW_POWERDOWN,pmic_id=0x%x\r\n",pmic_id);
	#endif
	uart_printf("+PMIC_SW_POWERDOWN,pmic_id=0x%x\r\n",pmic_id);
	CPUartLogPrintf("+PMIC_SW_POWERDOWN,pmic_id=0x%x\r\n",pmic_id);
#ifdef AT_OVER_UART //workaround to remove extra 0x00 on cp uart tx when system power down
	if (CHIP_IS_CRANEL) 
	{
	  extern void PMIC_Set_CP_UART_PowerOff_and_AIB_3_3V(void);
	  PMIC_Set_CP_UART_PowerOff_and_AIB_3_3V();
	}
#endif
#ifdef QUECTEL_PROJECT_CUST
    USB2MgrDeviceUnplug();//evin.zhu before POWER OFF,plug out USB
	QUEC_SET_MAINUART_TX_GPIO();
#endif
#ifdef QUEC_POWER_MANAGER_ENABLE
/*
解决bug STASR1601-235. powerkey 开机后，再使用powerkey关机，下次再使用powerkey开机时拉低10ms就可以开机无debounce效果
该问题根本原因是系统判断冷启动借用的是GUILIN_BASE_Reg 这个寄存器bit5~bit7初始值为0， 如果不为0说明不是冷启动，
则不会去做powerkey防抖检查(reset, cfun=1,1重启的不能做powerkey防抖检测)，而正常模块关机时GUILIN_BASE_Reg 寄存器bit5-7是不为0的
所以导致再次powerkey开机时没有去做防抖检测，导致powerkey只要拉低立即开机，因此再这里关机前将该寄存器比bit5-7设置为0
*/
#if !defined(NOT_SUPPORT_PM802)
if(PMIC_IS_PM802())
{
	//冷热启动判断目前寄存器地址修改为0xeb,关机后，把寄存器清零 
	unsigned char var = 0;
	GuilinRead( GUILIN_BASE_Reg, 0xeb, &var );
	var &= ~0x80;
	GuilinWrite( GUILIN_BASE_Reg, 0xeb, var);
	//向前兼容，0xf0寄存器清零
    GuilinRead( GUILIN_BASE_Reg, GUILIN_CRYSTAL_CAP_SET_REG, &var );
    var &= ~0xE0;
    GuilinWrite( GUILIN_BASE_Reg, GUILIN_CRYSTAL_CAP_SET_REG, var );
}else
#endif
#if !defined(NOT_SUPPORT_PM803)
{
	if(PMIC_IS_PM803())
	{
		unsigned char var = 0;
		GuilinLiteRead(GUILIN_LITE_BASE_Reg, 0xeb, &var);
		var &= ~0x80;
		GuilinLiteWrite(GUILIN_LITE_BASE_Reg, 0xeb, var);
	}
}
#endif
#if !defined(NOT_SUPPORT_PM803L)
{
	if(PMIC_IS_PM803L())
	{
		unsigned char var = 0;
		GuilinLite2Read(GUILIN_LITE_BASE_Reg, 0xeb, &var);
		var &= ~0x80;
		GuilinLite2Write(GUILIN_LITE_BASE_Reg, 0xeb, var);
	}
}
#endif
#endif

		
#ifdef QUEC_3601_PMIC_PWRKEY_12651
	PMIC_FAULT_WU_EN_DISABLE();
#endif
	//SW_PDOWN
	switch(pmic_id)
	{
#if !defined(NOT_SUPPORT_PM813)
		case PMIC_812:
		       tmp = PMIC_READ_REG_BASE(PM812_WAKEUP_1_REG);
		       tmp |= PM812_SW_PDOWN_BIT;
		       PMIC_WRITE_REG_BASE(PM812_WAKEUP_1_REG,tmp);
		       break;
		case PMIC_813:
        case PMIC_813A3: 
        case PMIC_813S:					
			#ifdef QUEC_3601_PMIC_PWRKEY_12651
		       PMIC_WRITE_REG_BASE(0x4C,0x0); //disable PWM
			#endif

		       tmp = PMIC_READ_REG_BASE(NINGBO_MISC_CFG_REG1);
		       tmp |= NINGBO_SW_PDOWN_BIT;
		       PMIC_WRITE_REG_BASE(NINGBO_MISC_CFG_REG1,tmp);
		       break;
#endif
#if !defined(NOT_SUPPORT_PM802)
		case PMIC_802:
			   /*TODO*/
	    	   tmp = PMIC_READ_REG_BASE(GUILIN_WAKEUP_REG1);
		       tmp |= GUILIN_SW_PDOWN;
		       PMIC_WRITE_REG_BASE(GUILIN_WAKEUP_REG1,tmp);
	    	   break;
#endif
#ifdef QUEC_1603_PM803_SUPPORT
		case PMIC_803:
    	   tmp = PMIC_READ_REG_BASE(GUILIN_LITE_WAKEUP_REG1);
	       tmp |= GUILIN_LITE_SW_PDOWN;
	       PMIC_WRITE_REG_BASE(GUILIN_LITE_WAKEUP_REG1,tmp);
    	   break;
#endif
#if !defined(NOT_SUPPORT_PM803L)	   
		case PMIC_803L:
		   tmp = PMIC_READ_REG_BASE(GUILIN_LITE2_RESET_REG);
           tmp |= GUILIN_LITE2_SW_PDOWN_BIT;
           PMIC_WRITE_REG_BASE(GUILIN_LITE2_RESET_REG,tmp);
		   break;
#endif
		default:
			break;

	}
}

//extern BOOL diagCommSdLogEnable(void);

void at_power_control(int flag) //1, power off; 2, reset;
{
	extern int enterCfunValue;
	extern int CurrentCfunValue;
	
	CPUartLogPrintf("%s, flag %d, enterCfunValue 0x%x, CurrentCfunValue 0x%x, ticks=%d",__func__,
		flag, enterCfunValue,CurrentCfunValue,OSAGetTicks());
	RTI_LOG("%s,flag=%d,ticks=%d",__func__,flag,OSAGetTicks());

//Rui.xu@2021/08/23:STASR1601-4314,Prevent calling large system functions during FOTA upgrade
#ifndef MIN_SYS	
if (!IsMiniSystem())
{
	if(GetCfunValue() != 0) {
		CPUartLogPrintf("set CFUN0,tick=%d",OSAGetTicks());
		RTI_LOG("set CFUN0,tick=%d",OSAGetTicks());
		SetCfunValue(0);
		wait_cfun_done();
	}
}
#endif	
	RTI_LOG("CFUN0 done,tick=%d",OSAGetTicks());
	CPUartLogPrintf("CFUN0 done,tick=%d",OSAGetTicks());

	//if(diagCommSdLogEnable()) //leoyang++for sdcard log enable
	{ 
      // flush_sd_log();
	}
	//diag_comm_transmit_finish();
	
	OSATaskSleep(100);
	CPUartLogPrintf("End,tick=%d",OSAGetTicks());
	RTI_LOG("End,ticks:%d",OSAGetTicks());

	if(flag == 1) //poweroff
	{ 
		PMIC_SW_POWERDOWN();
		CPUartLogPrintf("You should not see this!!! otherwise, might PDOWN failure");
	} 
	else if(flag == 2) //reset
	{ 
		PMIC_SW_RESET();	
	}
	return ;

}
#endif

