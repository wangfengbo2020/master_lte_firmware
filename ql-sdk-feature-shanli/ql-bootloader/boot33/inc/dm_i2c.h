#ifndef _DM_I2C_H_
#define _DM_I2C_H_
#include "common.h"

typedef enum {
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
} I2C_ReturnCode;

void i2cInit(void);
I2C_ReturnCode i2cSend(UINT8 Slave_addr, UINT8 RegAddr, UINT8 RegData);
UINT8 i2cReceive(  UINT8 Slave_addr, UINT8 I2CRegAddr);
#endif /* _DM_I2C_H_ */
