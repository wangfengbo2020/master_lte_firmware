/**========================================================================
 ** Guilin.c
===========================================================================**/
#include "charge/i2c.h"
#include "charge/charge.h"
#include "charge/charge_compound.h"
#include "charge/guilin_lite.h"

#include "utilities.h" //common dir

#define guiLinLitePrintf(fmt, args...)  do { uart_printf("[guiLinLiteCharge]"fmt"\r\n", ##args); } while(0)

// call I2CSend/I2CReceive to fix issue that print "Send: reset I2Cbus"
// this issue is fix by FAE in ningbo IC, and is verified by customer.
// fix this issue in i2c_dm.c by RD, so also use i2cReceive/i2cSend if you want to use RD's code _-_
// this sulotion don't need to sync to OBM charge code due to only one task running in OBM
extern I2C_ReturnCode I2CSend(UINT8 Slave_addr, UINT8 RegAddr, UINT8 RegData);
extern UINT8 I2CReceive(UINT8 Slave_addr, UINT8 I2CRegAddr);

#if 0
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
#else
static UINT8 i2cRead(guiLinLiteRegTypeE guilin_lite_reg_type, UINT8 reg, UINT8 *regVal)
{
    UINT8 res = 0;
    switch(guilin_lite_reg_type) {
        case GUILIN_LITE_BASE_Reg:
            res = I2CReceive(GUILIN_LITE_READ_BASE_SLAVE_ADDRESS, reg);
            break;
        case GUILIN_LITE_POWER_Reg:
            res = I2CReceive(GUILIN_LITE_READ_POWER_SLAVE_ADDRESS, reg);
            break;
        default:
            break;
    }

    *regVal = res;
    return 0;
}

static I2C_ReturnCode i2cWrite(guiLinLiteRegTypeE guilin_lite_reg_type, UINT8 reg, UINT8 regVal )
{
    I2C_ReturnCode status = I2C_RC_OK;
    switch(guilin_lite_reg_type) {
        case GUILIN_LITE_BASE_Reg:
            status = I2CSend(GUILIN_LITE_WRITE_BASE_SLAVE_ADDRESS, reg, regVal);
            break;
        case GUILIN_LITE_POWER_Reg:
            status = I2CSend(GUILIN_LITE_WRITE_POWER_SLAVE_ADDRESS, reg, regVal);
            break;
        default:
            break;
    }
    return status;
}
#endif

static UINT8 guiLinLiteChargeIDGet(void)
{
    UINT8 regVal = 0;

    i2cRead(GUILIN_LITE_BASE_Reg, GUILIN_LITE_ID_REG, &regVal);
    guiLinLitePrintf("%s charge ID %x", __FUNCTION__, regVal);
    return regVal;
}

static void GuilinLite_INT_TO_HOST_ENABLE(GUILIN_LITE_INTC intc)
{
    UINT8 reg_addr = GUILIN_LITE_INTC_TO_ENABLE_REG(intc);
    UINT8 tmp = 0;
    i2cRead(GUILIN_LITE_BASE_Reg, reg_addr, &tmp);
    tmp |= GUILIN_LITE_INTC_TO_ENABLE_BIT(intc);
    i2cWrite(GUILIN_LITE_BASE_Reg, reg_addr, tmp);
}

static void guiLinLiteInit(void)
{
    //GuilinLiteClkInit();

    pmicCombineWith3rdCharger(GUILINLITE, (void *)(&chargeManager[GUILINLITE])); // combine charge function
                                                // from 3rd charge ic due to no charge function of guilinlite
    return;
}

//extern INT16 GetPm803VbatAdc(void);
#include "guilin.h"

// guilinlite ic cannot detect battery plug or unplug, so check voltage of battery
static BOOL guiLinLiteBatteryConnectCheck(void)
{
    PM803_Battery_Res_t pm803_battery_res;
    pm803_get_battery_voltage(&pm803_battery_res);

    if (pm803_battery_res.pm803_status_res != PM803_GetBatteryOk) {
        return FALSE;
    }

    INT16 value = pm803_battery_res.BatteryValue;
    if (value < 0 || value > 5000) { // consider NO Connect when vbat > 5000mV or vbat < 0
        return FALSE;
    } else {
        return TRUE;
    }
}

// guilinlite ic cannot detect usb plug or unplug, so check usb register
static BOOL guiLinLiteUsbConnectCheck(void)
{
    guiLinLitePrintf("vbus detect register %x", reg_read(PMUA_SD_ROT_WAKE_CLR));
    if ((reg_read(PMUA_SD_ROT_WAKE_CLR) & VBUS_DETECT) == VBUS_DETECT) {
        guiLinLitePrintf("usb plug");
        return TRUE;
    } else {
        guiLinLitePrintf("usb unplug");
        return FALSE;
    }
}

static enum powerUpTypeE guiLinLiteWakeUpCheck(BOOL batConnectState)
{
    UINT8 regVal;
    enum powerUpTypeE type = PowerUP_Unkown;

    i2cRead(GUILIN_LITE_BASE_Reg, GUILIN_LITE_PWRUP_LOG_REG, &regVal);

    if (regVal == 0) {
        type = PowerUP_Reset;
    } else if (regVal & GUILIN_LITE_BAT_WAKEUP_BIT) {
        if (batConnectState) {
            type = PowerUP_Battery;
        } else {
            /*
            * The external power wakeup signal is connected to battery wakeup signal,
            * such as external 5V power
            */
            type = PowerUP_External;
        }
    } else if (regVal & GUILIN_LITE_ONKEY_WAKEUP_BIT) {
        type = PowerUP_ONKEY;

    } else if (regVal & GUILIN_LITE_EXTON1_WAKEUP_BIT) {
        type = PowerUP_USB;
    }
    guiLinLitePrintf("powerUp Value : %x, Type : %x", regVal, type);

    return type;
}

static BOOL onkeyDetected(void)
{
    UINT8 var;
    i2cRead(GUILIN_LITE_BASE_Reg, GUILIN_LITE_STATUS_REG1, &var);
    return ((var & GUILIN_LITE_ONKEY_STATUS_BIT) ? TRUE : FALSE);
}

static UINT32 GetTimer0CNT(void)
{
    return *(volatile unsigned long*)APBTIMER0_CNT_REG;
}

static void Timer0Enable(void)
{
    *(volatile unsigned long*)APBTIMER0_EN_REG = 0x1; //enable timer0_0
}

static void Timer0Disable(void)
{
    *(volatile unsigned long*)APBTIMER0_EN_REG = 0x0; //stop Timer0_0
}

// guilinlite have not rtc counter, so use apb timer0 to get counter
static UINT32 guiLinLiteRtcCounterGet(void)
{
    return GetTimer0CNT();
}

static BOOL guiLinLitePowerOnKeyCheck(UINT8 timeOutValue)
{
    UINT8 elapseTime;
    static UINT32 startTime = 0, endTime = 0;
    static BOOL keyDownCounted = FALSE;

    Timer0Enable();

    do {
        if (onkeyDetected()) {
            if (!keyDownCounted) {
                startTime = guiLinLiteRtcCounterGet();
                keyDownCounted = TRUE;
                guiLinLitePrintf("onkey press Time: %ld", startTime);
            }
            guiLinLitePrintf("onkey press again");
            return FALSE;
        } else {
            endTime = guiLinLiteRtcCounterGet();
            if (keyDownCounted) {
                keyDownCounted = FALSE;
                elapseTime = endTime - startTime;
                guiLinLitePrintf("onkey press endTime : %ld, startTime : %ld, elapseTime: %d", endTime, startTime, elapseTime);
            } else {
                guiLinLitePrintf("onkey release, but Donot detect press");
                return FALSE;
            }
        }
    } while (elapseTime < timeOutValue);

    Timer0Disable(); // indicate that exit charge when run here, so would disable timer0;
                     // donot need disable timer0 even if have enable tiemr0
                     // due to continue to charge that need timer0 to get counter
    return TRUE;
}

static UINT16 guiLinLiteBatVoltGet(BOOL usbStatus)
{
    PM803_Battery_Res_t pm803_battery_res;
    pm803_get_battery_voltage(&pm803_battery_res);
    guiLinLitePrintf("vbat %d", pm803_battery_res.BatteryValue);

    if (pm803_battery_res.pm803_status_res != PM803_GetBatteryOk) {
        return FALSE;
    }

    INT16 value = pm803_battery_res.BatteryValue;

    if (value > 0) {
        return (UINT16)value;
    } else {
        return 0;
    }
}

static void guiLinLiteSystemPowerOff(void)
{
    UINT8 tmp;
    i2cRead(GUILIN_LITE_BASE_Reg, GUILIN_LITE_MISC_CFG_REG1, &tmp);
    i2cWrite(GUILIN_LITE_BASE_Reg, GUILIN_LITE_MISC_CFG_REG1, tmp | GUILIN_LITE_SW_PDOWN_BIT);
}

static struct chargeManagerT guiLinLiteChargeManager = { // Although guilinlite has not function of charge, define some member
                                                         // in struct chargeManagerT for partial charge function, and other charge
                                                         // function are defined by 3rd charger ic in struct charge3rdManagerT
    .family = GUILINLITE,
    .id = PMIC_803,
    .chargeICIDGet = guiLinLiteChargeIDGet,
    .init = guiLinLiteInit,
    .need3rdCharge = TRUE,
    .batteryConnectCheck = guiLinLiteBatteryConnectCheck,
    .usbConnectCheck = guiLinLiteUsbConnectCheck,
    .wakeUpCheck = guiLinLiteWakeUpCheck,
    .powerOnKeyCheck = guiLinLitePowerOnKeyCheck,
    .batInstantVoltGet = guiLinLiteBatVoltGet,
    .systemPowerOff = guiLinLiteSystemPowerOff,
};

void guiLinLiteICRegister(void)
{
    chargeManager[guiLinLiteChargeManager.family] = guiLinLiteChargeManager;
}
