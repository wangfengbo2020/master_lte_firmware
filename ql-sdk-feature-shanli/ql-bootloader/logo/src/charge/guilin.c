/**========================================================================
 ** Guilin.c
===========================================================================**/
#include "charge/charge.h"
#include "charge/i2c.h"
#include "charge/guilin.h"

static UINT8 guiLinRead(guiLinRegTypeE guiLinRegTypeE, unsigned char reg, UINT8 *regVal)
{
    UINT8 res = 0;

    switch(guiLinRegTypeE)
    {
        case GUILIN_BASE_Reg:
            res = i2cReceive(GUILIN_READ_BASE_SLAVE_ADDRESS, reg);
            break;
        case GUILIN_POWER_Reg:
            res = i2cReceive(GUILIN_READ_POWER_SLAVE_ADDRESS, reg);
            break;
        case GUILIN_GPADC_Reg:
            res = i2cReceive(GUILIN_READ_GPADC_SLAVE_ADDRESS, reg);
            break;
        default:
            break;
    }

    *regVal = res;

    return res;
}

static I2C_ReturnCode guiLinWrite(guiLinRegTypeE guiLinRegTypeE, unsigned char reg, UINT8 value )
{
    I2C_ReturnCode status = I2C_RC_OK;
    switch(guiLinRegTypeE)
    {
        case GUILIN_BASE_Reg:
            status = i2cSend(GUILIN_WRITE_BASE_SLAVE_ADDRESS, reg, value);
            break;
        case GUILIN_POWER_Reg:
            status = i2cSend(GUILIN_WRITE_POWER_SLAVE_ADDRESS, reg, value);
            break;
        case GUILIN_GPADC_Reg:
            status = i2cSend(GUILIN_WRITE_GPADC_SLAVE_ADDRESS, reg, value);
            break;
        default:
            break;
    }

    return status;
}

static UINT8 guiLinChargeIDGet(void)
{
    return 0;
}

static void guiLinInit(void)
{
    return;
}

static BOOL guiLinBatteryConnectCheck(void)
{
    return TRUE;
}

static BOOL guiLinUsbConnectCheck(void)
{
    return TRUE;
}

static enum powerUpTypeE guiLinWakeUpCheck(BOOL batConnectState)
{
    enum powerUpTypeE type = PowerUP_Unkown;
    return type;
}

static BOOL guiLinPowerOnKeyCheck(UINT8 timeOutValue)
{
    return TRUE;
}

static void guiLinChargerEnable(void)
{
    return;
}

static UINT16 guiLinBatInstantVoltGet(BOOL usbStatus)
{
    return 0;
}

static BOOL chargerFull(void)
{
    return TRUE;
}

static void guiLinSystemPowerOff(void)
{
    return;
}

struct chargeManagerT guiLinChargeManager = {
    .family = GUILIN,
    .id = PMIC_802,
    .chargeICIDGet = guiLinChargeIDGet,
    .init = guiLinInit,
    .batteryConnectCheck = guiLinBatteryConnectCheck,
    .usbConnectCheck = guiLinUsbConnectCheck,
    .wakeUpCheck = guiLinWakeUpCheck,
    .powerOnKeyCheck = guiLinPowerOnKeyCheck,
    .batInstantVoltGet = guiLinBatInstantVoltGet,
    .systemPowerOff = guiLinSystemPowerOff,
};

void guiLinICRegister(void)
{
    chargeManager[guiLinChargeManager.family] = guiLinChargeManager;
}
