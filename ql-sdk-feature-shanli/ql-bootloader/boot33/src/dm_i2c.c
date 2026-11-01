/*--------------------------------------------------------------------------------------------------------------------
(C) Copyright 2006, 2007 Marvell DSPC Ltd. All Rights Reserved.
-------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
INTEL CONFIDENTIAL
Copyright 2006 Intel Corporation All Rights Reserved.
The source code contained or described herein and all documents related to the source code (“Material? are owned
by Intel Corporation or its suppliers or licensors. Title to the Material remains with Intel Corporation or
its suppliers and licensors. The Material contains trade secrets and proprietary and confidential information of
Intel or its suppliers and licensors. The Material is protected by worldwide copyright and trade secret laws and
treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted,
transmitted, distributed, or disclosed in any way without Intel’s prior express written permission.

No license under any patent, copyright, trade secret or other intellectual property right is granted to or
conferred upon you by disclosure or delivery of the Materials, either expressly, by implication, inducement,
estoppel or otherwise. Any license under such intellectual property rights must be express and approved by
Intel in writing.
-------------------------------------------------------------------------------------------------------------------*/
#include "dm_i2c.h"

#define SET     1
#define CLEAR   0

#define I2C_RECORD_FLAG                               0x494E4954
#define I2C_DEVICE_ERROR                              0xDEADBEEF

// I2C registers offset
#define I2C_ISAR_REG                                  0x0020  // Slave Address Register
#define I2C_ISR_REG                                   0x0018  // Status Register
#define I2C_ICR_REG                                   0x0010  // Control Register
#define I2C_IDBR_REG                                  0x0008  // Data Byte Register
//#define I2C_IBMR_REG                                0x0000  // Bus Monitor Register

#define I2C_OWN_SLAVE_ADDRESS                         0xFF    /* response */

/** bit map of the ICR register **/
#define I2C_ICR_UNIT_RESET_BIT                        14
#define I2C_ICR_IDBR_RECEIVE_FULL_INT_ENABLE_BIT      9
#define I2C_ICR_MASTER_ABORT_BIT                      4
#define I2C_ICR_TRANSFER_BYTE_BIT                     3
#define I2C_ICR_ACK_NACK_CONTROL_BIT                  2
#define I2C_ICR_STOP_BIT                              1
#define I2C_ICR_START_BIT                             0


#define I2C_ICR_MASTER_ABORT                          (1 << I2C_ICR_MASTER_ABORT_BIT)
#define I2C_ICR_TRANSFER_BYTE                         (1 << I2C_ICR_TRANSFER_BYTE_BIT)
#define I2C_ICR_ACK_NACK_CONTROL                      (1 << I2C_ICR_ACK_NACK_CONTROL_BIT)
#define I2C_ICR_STOP                                  (1 << I2C_ICR_STOP_BIT)
#define I2C_ICR_START                                 (1 << I2C_ICR_START_BIT)

/** bit map of the ISR register **/
#define I2C_ISR_UNEXPECTED_INTERRUPTS                 0x00000310
#define I2C_ISR_CLEAR_ALL_INTERRUPTS                  0x000007f0

#define I2C_ISR_BUS_ERROR_DETECTED_BIT                10
#define I2C_ISR_IDBR_RECEIVE_FULL_BIT                 7
#define I2C_ISR_IDBR_TRANSMIT_EMPTY_BIT               6
#define I2C_ISR_ARBITRATION_LOSS_DETECTED_BIT         5
#define I2C_ISR_UNIT_BUSY_BIT                         2
#define I2C_ISR_READ_WRITE_MODE_BIT                   0

#define I2C_ICR_REG_INIT_VALUE                        0x014E0   //all interrupts are disabled, except of the Bus Error and arbitration lost
#define LOOP_COUNTER_LIMIT                            4000L

#define SLOW_MODE_ENABLE                              0x7fff
#define FAST_MODE_ENABLE                              0x8000
#define HIGH_MODE_ENABLE                              0x18000

volatile unsigned long i2cRegisterBaseAddr = 0xD4037000;

#define I2C_REG_WRITE(reg, wval) \
        ((*((volatile UINT32*)(i2cRegisterBaseAddr + (reg)))) = wval);

#define I2C_REG_READ(reg, rval) \
        rval = (*((volatile UINT32*)(i2cRegisterBaseAddr + (reg))));

#define I2C_REG_BIT_WRITE(reg, btNm, sc)   \
            {   UINT32 regVl; \
                I2C_REG_READ(reg, regVl);  \
                sc ? (regVl = (1 << btNm) | regVl) : (regVl = ((regVl) & (~(1 << btNm)))); \
                I2C_REG_WRITE(reg, regVl); \
            }


#define I2C_STATUS_REG_CLEAR_BIT(bitNum)             \
            {   UINT32 regVal;                       \
                regVal = (1 << bitNum);              \
                I2C_REG_WRITE(I2C_ISR_REG, regVal);  \
            }

#define CHECK_IF_CHIP_BUSY(st) \
    {   UINT32  rv; \
        I2C_REG_READ(I2C_ISR_REG, rv); \
        st = I2C_REG_BIT_READ(rv, I2C_ISR_UNIT_BUSY_BIT) ? TRUE : FALSE; \
    }

#define I2C_REG_BIT_READ(regVl, btNm)    ((regVl >> btNm) & 0x00000001)
#define I2C_REG_BIT(btNm)                (((UINT32)1) << (btNm))
#define I2C_SLAVE_WRITE(slv)             ((slv) | 0x00000000)          /* Master is writing to the slave */
#define I2C_SLAVE_READ(slv)              ((slv) | 0x00000001)          /* Master is reading from the slave */

/* I2C device status*/
typedef struct I2CDeviceStatusT {
    UINT32 recordFlag;
    UINT32 baseAddress;
    UINT32 slaveAddress;
    UINT32 deviceStatus;
} I2CDeviceStatusTT;

typedef struct I2CReceiveRequestParamsT {
    UINT8 activeSlaveAddress;
    UINT8 *RxBufferPtr;
    UINT16 dataSize;
} I2CReceiveRequestParamsTT;

static BOOL repeatStart = TRUE;
static struct I2CDeviceStatusT i2cStatusArray[4];
static struct I2CReceiveRequestParamsT receiveReqParams;

static void i2cClockAndPinEnable(void)
{
    *(volatile unsigned long*)0xD4090104 |= 0x2; // enable PLL1_614 for PWIC I2C
}

static void i2cUnitDiReset(void)
{
    UINT32 ICRRegValue;

    // Read the control register
    I2C_REG_READ(I2C_ICR_REG, ICRRegValue);

    ICRRegValue &= ~I2C_ICR_MASTER_ABORT;        // Clear the abort bit
    ICRRegValue &= ~I2C_ICR_START;               // Clear the start bit
    ICRRegValue &= ~I2C_ICR_STOP;                // Clear the stop bit
    ICRRegValue &= ~I2C_ICR_ACK_NACK_CONTROL;    // Clear the ACK bit
    ICRRegValue &= ~I2C_ICR_TRANSFER_BYTE;       // Clear the transfer_byte bit

    // clear the ICR register
    I2C_REG_WRITE(I2C_ICR_REG, 0x0000);

    // Set the RESET bit in the ICR rewgister
    I2C_REG_BIT_WRITE(I2C_ICR_REG, I2C_ICR_UNIT_RESET_BIT, SET);

    // clear the ISR register after reset
    I2C_REG_WRITE(I2C_ISR_REG, I2C_ISR_CLEAR_ALL_INTERRUPTS);

    // Clear the RESET bit in the ICR rewgister
    I2C_REG_BIT_WRITE(I2C_ICR_REG, I2C_ICR_UNIT_RESET_BIT, CLEAR);

    // Restore the ICR register
    I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue);
}

static void i2cConfigureDi(void)
{
    UINT32 controlRegValue = I2C_ICR_REG_INIT_VALUE;

    // reset the I2C unit
    i2cUnitDiReset();

    controlRegValue |= FAST_MODE_ENABLE;

    I2C_REG_WRITE(I2C_ICR_REG, controlRegValue);

    I2C_REG_WRITE(I2C_ISAR_REG, I2C_OWN_SLAVE_ADDRESS);
}

void i2cInit(void)
{
    i2cClockAndPinEnable();
    i2cConfigureDi();
}

static I2C_ReturnCode i2cWaitStatusDirect (UINT32 bitsSet, UINT32 bitsCleared)
{
    UINT32 statusRegValue;
    UINT32 countLimit = LOOP_COUNTER_LIMIT;
    UINT32 mask = bitsSet | bitsCleared;    // all bits we care of
    UINT32 value = bitsSet;

    do {
        I2C_REG_READ(I2C_ISR_REG, statusRegValue);
        countLimit--;
    } while (((statusRegValue & mask) != value)
                && (!(I2C_REG_BIT_READ(statusRegValue, I2C_ISR_BUS_ERROR_DETECTED_BIT))
                && (countLimit > 0)
                && (!(I2C_REG_BIT_READ(statusRegValue, I2C_ISR_ARBITRATION_LOSS_DETECTED_BIT)))));

    if (I2C_REG_BIT_READ(statusRegValue, I2C_ISR_ARBITRATION_LOSS_DETECTED_BIT)) {
        return I2C_ISR_ARBITRATION_LOSS;
    }

    // check for timeout, reset the I2C device for next operations and return error if needed
    if (countLimit == 0) {
        UINT32  ICRRegValue = 0;
        I2C_REG_READ(I2C_ICR_REG, ICRRegValue);
        ICRRegValue |= I2C_ICR_MASTER_ABORT;
        ICRRegValue &= ~I2C_ICR_TRANSFER_BYTE;
        I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue );
        return I2C_RC_TIMEOUT_ERROR;
    } else if ((I2C_REG_BIT_READ(statusRegValue, I2C_ISR_BUS_ERROR_DETECTED_BIT))) {
        return I2C_ISR_BUS_ERROR;
    }

    return I2C_RC_OK;
}

static I2C_ReturnCode i2cMasterSendDirect(UINT8 *data, UINT16 dataSize, UINT8 slaveAddress, BOOL repeatedStart , BOOL masterReceiveCalled)
{
    int i;
    UINT32 ICRRegValue = 0;
    I2C_ReturnCode I2CReturnCode = I2C_RC_OK;

    /* Check the bus for free - If there is an arbitration loss, stay until it become free */
    do {
        // check if 'Arbitration Loss' was detected
        if (I2CReturnCode == I2C_ISR_ARBITRATION_LOSS) {
             I2C_STATUS_REG_CLEAR_BIT(I2C_ISR_ARBITRATION_LOSS_DETECTED_BIT);

             // Read the control register
             I2C_REG_READ(I2C_ICR_REG, ICRRegValue);

             ICRRegValue &= ~I2C_ICR_START;               // Clear the start bit
             ICRRegValue &= ~I2C_ICR_TRANSFER_BYTE;       // Clear the transfer_byte bit

             // Write to the ICR register
             I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue);

             for ( i = 0; i < 50000; i++ );             /* A little delay to enable others master to finish without interruption */
                                                        /* the bus arbiter, and reduce the arbitration sequences */
        }

        // write IDBR register: target slave address and R/W# bit=0 for write transaction.
        I2C_REG_WRITE(I2C_IDBR_REG, I2C_SLAVE_WRITE(slaveAddress));

        // write ICR register: set START bit, clear STOP bit, set Transfer Byte bit to initiate the access
        I2C_REG_READ(I2C_ICR_REG, ICRRegValue);
        ICRRegValue &= ~I2C_ICR_STOP;
        ICRRegValue |= (I2C_ICR_START | I2C_ICR_TRANSFER_BYTE);
        I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue);

        I2CReturnCode = i2cWaitStatusDirect((I2C_REG_BIT(I2C_ISR_IDBR_TRANSMIT_EMPTY_BIT) | I2C_REG_BIT(I2C_ISR_UNIT_BUSY_BIT)),
                                            I2C_REG_BIT(I2C_ISR_READ_WRITE_MODE_BIT));

        // clear 'IDBR Transmit Empty' bit (write '1')
        I2C_STATUS_REG_CLEAR_BIT(I2C_ISR_IDBR_TRANSMIT_EMPTY_BIT);
        if ((I2CReturnCode != I2C_ISR_ARBITRATION_LOSS) && (I2CReturnCode != I2C_RC_OK)) {
            I2C_REG_READ(I2C_ICR_REG, ICRRegValue);
            ICRRegValue &= 0xfff0;
            I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue);
            return I2CReturnCode;
        }
        // check if 'Arbitration Loss' was detected
    }while (I2CReturnCode == I2C_ISR_ARBITRATION_LOSS);

    // write ICR register: clear START bit, clear STOP bit
    I2C_REG_READ(I2C_ICR_REG, ICRRegValue);
    ICRRegValue &= ~I2C_ICR_STOP;
    ICRRegValue &= ~I2C_ICR_START;
    I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue );

    /*** Send data bytes - all, except the last byte  ***/
    for (i = 0; i < (dataSize - 1); i++) {
        // write data byte to the IDBR register
        I2C_REG_WRITE(I2C_IDBR_REG, *data);
        data++;

        // Set 'Tranfer Byte' bit to intiate the access
        I2C_REG_BIT_WRITE(I2C_ICR_REG, I2C_ICR_TRANSFER_BYTE_BIT, SET);
        if((I2CReturnCode = i2cWaitStatusDirect(I2C_REG_BIT(I2C_ISR_IDBR_TRANSMIT_EMPTY_BIT) | I2C_REG_BIT(I2C_ISR_UNIT_BUSY_BIT),
                                          I2C_REG_BIT(I2C_ISR_READ_WRITE_MODE_BIT))) != I2C_RC_OK) {
            return I2CReturnCode;
        }

        // clear 'IDBR Transmit Empty' bit (write '1')
        I2C_STATUS_REG_CLEAR_BIT(I2C_ISR_IDBR_TRANSMIT_EMPTY_BIT);
    }

    /*** Send the last byte with STOP bit ***/
    // write the last data byte to the IDBR register
    I2C_REG_WRITE(I2C_IDBR_REG, *data);

    // write ICR: clear START bit
    I2C_REG_BIT_WRITE(I2C_ICR_REG, I2C_ICR_START_BIT, CLEAR);

    if ((repeatedStart == FALSE) || (masterReceiveCalled == FALSE)) {
        I2C_REG_BIT_WRITE(I2C_ICR_REG, I2C_ICR_STOP_BIT, SET);
    }

    I2C_REG_BIT_WRITE(I2C_ICR_REG, I2C_ICR_TRANSFER_BYTE_BIT, SET);

//  if (repeatedStart)
//  {
//    if ((I2CReturnCode = i2cWaitStatusDirect (I2C_REG_BIT(I2C_ISR_IDBR_TRANSMIT_EMPTY_BIT)|I2C_REG_BIT(I2C_ISR_UNIT_BUSY_BIT),
//                                        I2C_REG_BIT(I2C_ISR_READ_WRITE_MODE_BIT)))!=I2C_RC_OK)
//              return I2CReturnCode;
//  }
//    else
    if ((I2CReturnCode = i2cWaitStatusDirect(I2C_REG_BIT(I2C_ISR_IDBR_TRANSMIT_EMPTY_BIT),
                                      I2C_REG_BIT(I2C_ISR_READ_WRITE_MODE_BIT))) != I2C_RC_OK) {
        return I2CReturnCode;
    }
    // clear 'IDBR Transmit Empty' bit (write '1')
    I2C_STATUS_REG_CLEAR_BIT(I2C_ISR_IDBR_TRANSMIT_EMPTY_BIT);
    I2C_REG_BIT_WRITE(I2C_ICR_REG, I2C_ICR_STOP_BIT, CLEAR);

    return I2C_RC_OK;
}

static I2C_ReturnCode i2cMasterDataSendDirect(UINT8 *data , UINT16 dataSize , UINT8 slaveAddress , BOOL protected , UINT16 userId)
{
    BOOL chipBusy;
    I2C_ReturnCode I2CReturnCode;

    CHECK_IF_CHIP_BUSY(chipBusy);
    if (chipBusy == TRUE) {
        return I2C_RC_CHIP_BUSY;
    }

    I2CReturnCode = i2cMasterSendDirect(data, dataSize, slaveAddress, repeatStart, FALSE);
    return I2CReturnCode;
}

static UINT16 i2cIntLISRDirect(void)
{
    UINT32 statusRegValue = 0, ICRRegValue = 0;

    //check interrupt source
    I2C_REG_READ(I2C_ISR_REG, statusRegValue);
    if (I2C_REG_BIT_READ(statusRegValue, I2C_ISR_IDBR_RECEIVE_FULL_BIT)) {
        // clear 'IDBR Receive Full' bit (write '1')
        I2C_STATUS_REG_CLEAR_BIT(I2C_ISR_IDBR_RECEIVE_FULL_BIT);
        {
            // read the received byte
            I2C_REG_READ(I2C_IDBR_REG, *receiveReqParams.RxBufferPtr);
            receiveReqParams.RxBufferPtr++;
            receiveReqParams.dataSize--;

            // write ICR: clear STOP bit(1), clear ACK/NACK bit(2)
            I2C_REG_READ(I2C_ICR_REG, ICRRegValue);
            ICRRegValue &= ~I2C_ICR_STOP;
            ICRRegValue &= ~I2C_ICR_ACK_NACK_CONTROL;
            I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue);


            if (receiveReqParams.dataSize > 1) {
                // write ICR: clear START bit, clear STOP bit, send ACK bit (0 for ACK),
                // set Transfer Byte bit to initiate the access
                I2C_REG_READ(I2C_ICR_REG, ICRRegValue);
                ICRRegValue &= ~I2C_ICR_START;
                ICRRegValue &= ~I2C_ICR_STOP;
                ICRRegValue &= ~I2C_ICR_ACK_NACK_CONTROL;
                ICRRegValue |= I2C_ICR_TRANSFER_BYTE;
                I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue);
            } else if (receiveReqParams.dataSize == 1) {
                // last byte remaing to read (with STOP signal)
                // write ICR: clear START bit, set STOP bit, send NACK bit (1 for NACK),
                // set Transfer Byte bit to initiate the access
                I2C_REG_READ(I2C_ICR_REG, ICRRegValue);
                ICRRegValue &= ~I2C_ICR_START;
                ICRRegValue |= (I2C_ICR_STOP | I2C_ICR_ACK_NACK_CONTROL | I2C_ICR_TRANSFER_BYTE);
                I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue);
            } else {
                // disable 'IDBR Buffer Full' interrupt
                I2C_REG_BIT_WRITE(I2C_ICR_REG, I2C_ICR_IDBR_RECEIVE_FULL_INT_ENABLE_BIT, CLEAR);
            }
        }
    }

    if (I2C_REG_BIT_READ(statusRegValue, I2C_ISR_BUS_ERROR_DETECTED_BIT)) {
        // clear 'Bus Error Detected' bit (write '1')
        I2C_STATUS_REG_CLEAR_BIT(I2C_ISR_BUS_ERROR_DETECTED_BIT);
    }

    if (statusRegValue & I2C_ISR_UNEXPECTED_INTERRUPTS) {
        // clear 'I2C_ISR_UNEXPECTED_INTERRUPTS ' bits (write '1')
        I2C_REG_WRITE(I2C_ISR_REG,I2C_ISR_UNEXPECTED_INTERRUPTS);
    }

    return receiveReqParams.dataSize;
}

static I2C_ReturnCode i2cMasterDataReceiveDirect (UINT8 *cmd, UINT16 cmdLength,
                        UINT8 writeSlaveAddress, BOOL protected, UINT8 *designatedRxBufferPtr,
                        UINT16 dataSize, UINT8 readSlaveAddress)
{
    I2C_ReturnCode  I2CReturnCode;
    UINT32          ICRRegValue = 0;
    BOOL            chipBusy;

    // store the request parameters (to be used from the ISR and by the I2C task when error)
    receiveReqParams.RxBufferPtr = designatedRxBufferPtr;
    receiveReqParams.dataSize = dataSize;

    CHECK_IF_CHIP_BUSY(chipBusy);
    if(chipBusy) {
        return I2C_RC_CHIP_BUSY;
    }

    if ((cmdLength != 0) && (cmd != NULL)) {
        /* if command is associated with the received request */ 
        I2CReturnCode = i2cMasterSendDirect(cmd, cmdLength, writeSlaveAddress, repeatStart, TRUE);
        if(I2CReturnCode != I2C_RC_OK) {
            return I2CReturnCode;
        }
    }

    /*** send Read Request ***/
    // write IDBR: target slave address and R/W# bit (1 for read)
    I2C_REG_WRITE(I2C_IDBR_REG, I2C_SLAVE_READ(readSlaveAddress));

    // write ICR: set START bit, clear STOP bit, set Transfer Byte bit to initiate the access
    I2C_REG_READ(I2C_ICR_REG, ICRRegValue);
    ICRRegValue &= ~I2C_ICR_STOP;
    ICRRegValue |= (I2C_ICR_START | I2C_ICR_TRANSFER_BYTE);
    I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue);

    I2CReturnCode = i2cWaitStatusDirect(I2C_REG_BIT(I2C_ISR_IDBR_TRANSMIT_EMPTY_BIT)|I2C_REG_BIT(I2C_ISR_UNIT_BUSY_BIT)|I2C_REG_BIT(I2C_ISR_READ_WRITE_MODE_BIT), 0 );

    // clear 'IDBR Transmit Empty' bit (write '1')
    I2C_STATUS_REG_CLEAR_BIT(I2C_ISR_IDBR_TRANSMIT_EMPTY_BIT);

    if (I2CReturnCode != I2C_RC_OK) {
        return I2CReturnCode;
    }

    // Initiate the read process:
    if (dataSize == 1) {
        // only one byte to read
        // write ICR: set STOP bit, set ACK/NACK bit (1 for NACK)
        I2C_REG_READ(I2C_ICR_REG,ICRRegValue);
        ICRRegValue &= ~I2C_ICR_START;
        ICRRegValue |= (I2C_ICR_STOP | I2C_ICR_ACK_NACK_CONTROL);
        I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue);
    } else {
        // more than one byte to read
        // write ICR: clear STOP bit, clear ACK/NACK bit (0 for ACK)
        I2C_REG_READ(I2C_ICR_REG,ICRRegValue);
        ICRRegValue &= ~I2C_ICR_STOP;
        ICRRegValue &= ~I2C_ICR_ACK_NACK_CONTROL;
        I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue);
    }

    I2C_REG_READ(I2C_ICR_REG,ICRRegValue);
    ICRRegValue &= ~I2C_ICR_START;
    ICRRegValue |= I2C_ICR_TRANSFER_BYTE;
    I2C_REG_WRITE(I2C_ICR_REG, ICRRegValue);

    while(i2cIntLISRDirect());

    return I2C_RC_OK;
}

static BOOL i2cDeviceStatusRecord(UINT32 slaveAddress, BOOL error)
{
    UINT8 i = 0;
    BOOL status = FALSE;

    for (i = 0; i < sizeof(i2cStatusArray)/sizeof(struct I2CDeviceStatusT); i++) {
        if (I2C_RECORD_FLAG != i2cStatusArray[i].recordFlag) {
            i2cStatusArray[i].recordFlag = I2C_RECORD_FLAG;
            i2cStatusArray[i].baseAddress = i2cRegisterBaseAddr;
            i2cStatusArray[i].slaveAddress = slaveAddress;

            if (error) {
                i2cStatusArray[i].deviceStatus = I2C_DEVICE_ERROR;
            } else {
                i2cStatusArray[i].deviceStatus = 0;
            }
            status = TRUE;
        }
    }

    return status;
}

static BOOL i2cDeviceStatusCheck(UINT32 slaveAddress)
{
    UINT8 i = 0;
    BOOL status = TRUE;

    for (i = 0; i < sizeof(i2cStatusArray)/sizeof(struct I2CDeviceStatusT); i++) {
        if ((i2cStatusArray[i].baseAddress == i2cRegisterBaseAddr )
            && (i2cStatusArray[i].slaveAddress == slaveAddress)
            && (i2cStatusArray[i].recordFlag == I2C_RECORD_FLAG)
            && (i2cStatusArray[i].deviceStatus == I2C_DEVICE_ERROR)) {
            status = FALSE;
        }
    }

    return status;
}

static I2C_ReturnCode i2cMastSend(UINT8 slaveAddr, UINT8 regAddr, UINT8 regData)
{
    UINT16 readTimes = 0;
    UINT32 i = 0;
    UINT8 paramData[3] = {0};
    I2C_ReturnCode status = I2C_RC_NOT_OK;

    if (!i2cDeviceStatusCheck(slaveAddr)) {
        return I2C_RC_NOT_OK;
    }

    paramData[0] = regAddr;
    paramData[1] = regData;
    paramData[2] = 0;

    status = i2cMasterDataSendDirect(paramData, 2, slaveAddr, FALSE, 0);

    readTimes = 0;
    while (status != I2C_RC_OK) {
        readTimes++;

        for(i = 0; i < 0x10000; i++);                                 /* Short delay. */

        status = i2cMasterDataSendDirect(paramData, 2, slaveAddr, FALSE, 0);

        if (readTimes >= 3) {
            i2cDeviceStatusRecord(slaveAddr, TRUE);
            break;
        }
    }
    return status;
}

static UINT8 i2cMastReceive(UINT8 slaveAddr, UINT8 regAddr)
{
    UINT32 i = 0;
    UINT16 readTimes = 0;
    UINT8 regData = 0;
    I2C_ReturnCode status = I2C_RC_NOT_OK;
    slaveAddr &=0xFE;

    if (!i2cDeviceStatusCheck(slaveAddr)) {
        return I2C_RC_NOT_OK;
    }

    status = i2cMasterDataReceiveDirect(&regAddr,
                                    1 /*cmd lenght*/,
                                    slaveAddr,
                                    FALSE /*not protected*/,
                                    &regData,
                                    0x1,
                                    slaveAddr | 0x1);

    while (status != I2C_RC_OK) {
        readTimes ++;
        for(i=0;i<0x10000;i++);
        status = i2cMasterDataReceiveDirect(&regAddr,
                                        1 /*cmd lenght*/,
                                        slaveAddr,
                                        FALSE /*not protected*/,
                                        &regData,
                                        0x1,
                                        (slaveAddr|0x1));
        if (readTimes >= 3) {
            i2cDeviceStatusRecord(slaveAddr, TRUE);
            break;
        }
    }

    return regData;
}

I2C_ReturnCode i2cSend( UINT8 slaveAddr, UINT8 regAddr, UINT8 regData)
{
     return (i2cMastSend(slaveAddr, regAddr, regData));
}

UINT8 i2cReceive(  UINT8 slaveAddr, UINT8 regAddr)
{
    UINT8 res = 0;
    res = i2cMastReceive(slaveAddr, regAddr);
    return res;
}
