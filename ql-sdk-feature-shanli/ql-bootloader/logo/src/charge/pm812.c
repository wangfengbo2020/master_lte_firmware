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
#include "charge/charge.h"
#include "charge/i2c.h"
#include "charge/pm812.h"

static int pm812Read(pm812RegTypeE pm812RegType, UINT8 reg, UINT8 *value)
{
    int res = 0;

    switch(pm812RegType)
    {
        case PM812_BASE_Reg:
            res = i2cReceive(PM812_READ_BASE_SLAVE_ADDRESS, reg);
            break;
        case PM812_POWER_Reg:
            res = i2cReceive(PM812_READ_POWER_SLAVE_ADDRESS, reg);
            break;
        case PM812_GPADC_Reg:
            res = i2cReceive(PM812_READ_GPADC_SLAVE_ADDRESS, reg);
            break;
        default:
            break;
    }

    *value = res;
    return 0;
}

static I2C_ReturnCode pm812Write(pm812RegTypeE pm812RegType, UINT8 reg, UINT8 value)
{
    I2C_ReturnCode status = I2C_RC_OK;
    switch(pm812RegType)
    {
        case PM812_BASE_Reg:
            status = i2cSend(PM812_WRITE_BASE_SLAVE_ADDRESS, reg, value);
            break;
        case PM812_POWER_Reg:
            status = i2cSend(PM812_WRITE_POWER_SLAVE_ADDRESS, reg, value);
            break;
        case PM812_GPADC_Reg:
            status = i2cSend(PM812_WRITE_GPADC_SLAVE_ADDRESS, reg, value);
            break;
        default:
            break;
    }

    return status;
}

static UINT8 pm812ChargeIDGet(void)
{
    return 0;
}

static void pm812Init()
{
    return;
}

static BOOL pm812BatteryConnectCheck(void)
{
    return TRUE;
}

static BOOL pm812UsbConnectCheck(void)
{
    return TRUE;
}

static enum powerUpTypeE pm812WakeUpCheck(BOOL batConnectState)
{
    return PowerUP_Unkown;
}

static BOOL pm812PowerOnKeyCheck(UINT8 timeOutValue)
{
    return TRUE;
}

static void pm812ChargerEnable(void)
{
    return;
}

static UINT16 pm812BatInstantVoltGet(BOOL usbStatus)
{
    return 0;
}

static BOOL chargerFull(void)
{
    return TRUE;
}

static void pm812SystemPowerOff(void)
{
    return;
}

struct chargeManagerT pm812ChargeManager = {
    .family = PM812,
    .id = PMIC_812,
    .chargeICIDGet = pm812ChargeIDGet,
    .init = pm812Init,
    .batteryConnectCheck = pm812BatteryConnectCheck,
    .usbConnectCheck = pm812UsbConnectCheck,
    .wakeUpCheck = pm812WakeUpCheck,
    .powerOnKeyCheck = pm812PowerOnKeyCheck,
    .batInstantVoltGet = pm812BatInstantVoltGet,
    .systemPowerOff = pm812SystemPowerOff,
};

void pm812ICRegister(void)
{
    chargeManager[pm812ChargeManager.family] = pm812ChargeManager;
}
