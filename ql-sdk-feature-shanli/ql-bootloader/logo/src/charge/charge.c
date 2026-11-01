/*-----------------------------------------------------------------------------------------------------------------
    dm_charge.c
    This file implements the demo that ONLY illustrates the procedure that monitor charging to battery.
    This demo call function that is not defined in ningbo.c/guilin.c.etc, but defined in ningbo_dm.c/guilin_dm.c.etc
    Customer could directly use this demo to monitor charging procedure, OR overwrite this demo and call function
    that is defined in ningbo.c/guilin.c.etc to adapt customer's charging procedure

    Note:
    1.For ningbo, too large capacity(exceed 2000mAh~3000mAh) of battery is NOT recommended to use, due to cccv timer(
      90/144/192/240min) and max current setting(1000mA), which cause that battery cannot be charge full.
      If customer thinks that it's necessary to use large capacity of battery, customer need to reset cccv timer in
      some proper ponit during charging procedure by force to change FSM, to avoid to entry Fault status(FSM) due to
      expire of cccv timer.
-------------------------------------------------------------------------------------------------------------------*/
#include "charge/i2c.h"
#include "charge/charge.h"

#define chargeManagerPrintf(fmt, args...) do { uart_printf("[chargeManager]"fmt"\r\n", ##args); } while(0)

static BOOL charging = FALSE;

/** guilin 802
 ** xxxxxx 812
 ** ningbo 813
 ** guilinlite 803
 **/
static char *pmicName[8] = {"guilin", "pm812", "ningbo", "guilinlite"};

/** support 8 charge ic manager **/
struct chargeManagerT chargeManager[8] = {0};

static BOOL batteryConnectCheck(UINT8 index)
{
    if (chargeManager[index].batteryConnectCheck) {
        return chargeManager[index].batteryConnectCheck();
    } else {
        chargeManagerPrintf("batteryConnectCheck func is NULL, pmicName %s", pmicName[index]);
        return FALSE;
    }
}

static BOOL usbConnectCheck(UINT8 index)
{
    if (chargeManager[index].usbConnectCheck) {
        return chargeManager[index].usbConnectCheck();
    } else {
        chargeManagerPrintf("usbConnectCheck func is NULL, pmicName %s", pmicName[index]);
        return FALSE;
    }
}

static enum powerUpTypeE wakeUpCheck(UINT8 index, BOOL batConnectState)
{
    if (chargeManager[index].wakeUpCheck) {
        return chargeManager[index].wakeUpCheck(batConnectState);
    } else {
        chargeManagerPrintf("wakeUpCheck func is NULL, pmicName %s", pmicName[index]);
        return PowerUP_Unkown;
    }
}

static BOOL powerOnKeyCheck(UINT8 index, UINT8 timeOutValue)
{
    if (chargeManager[index].powerOnKeyCheck) {
        return chargeManager[index].powerOnKeyCheck(timeOutValue);
    } else {
        chargeManagerPrintf("powerOnKeyCheck func is NULL, pmicName %s", pmicName[index]);
        return FALSE;
    }
}

static UINT16 batInstantVoltGet(UINT8 index, BOOL usbStatus)
{
    if (chargeManager[index].batInstantVoltGet) {
        return chargeManager[index].batInstantVoltGet(usbStatus);
    } else {
        chargeManagerPrintf("batInstantVoltGet func is NULL, pmicName %s", pmicName[index]);
        return 0;
    }
}

static UINT16 batStableVoltGet(UINT8 index, UINT8 *pPercent)
{
    if (chargeManager[index].batStableVoltGet) {
        return chargeManager[index].batStableVoltGet(pPercent);
    } else {
        chargeManagerPrintf("batStableVoltGet func is NULL, pmicName %s", pmicName[index]);
        return 0;
    }
}

static void systemPowerOff(UINT8 index)
{
    if (chargeManager[index].systemPowerOff) {
        chargeManager[index].systemPowerOff();
    } else {
        chargeManagerPrintf("systemPowerOff func is NULL, pmicName %s", pmicName[index]);
    }
}

static BOOL chargerFull(UINT8 index)
{
    if (chargeManager[index].chargerFull) {
        return (chargeManager[index].chargerFull());
    } else {
        chargeManagerPrintf("chargerFull func is NULL, pmicName %s", pmicName[index]);
        return FALSE;
    }
}

static BOOL chargerCC(UINT8 index)
{
    if (chargeManager[index].chargerCC) {
        return (chargeManager[index].chargerCC());
    } else {
        chargeManagerPrintf("chargerCC func is NULL, pmicName %s", pmicName[index]);
        return FALSE;
    }
}

static BOOL setMPP(UINT8 index, UINT16 limit)
{
    if (chargeManager[index].setMPP) {
        return (chargeManager[index].setMPP(limit));
    } else {
        chargeManagerPrintf("setMPP func is NULL, pmicName %s", pmicName[index]);
        return FALSE;
    }
}

static BOOL getChargeStatus(UINT8 index)
{
    if (chargeManager[index].getChargeStatus) {
        return (chargeManager[index].getChargeStatus());
    } else {
        chargeManagerPrintf("getChargeStatus func is NULL, pmicName %s", pmicName[index]);
        return FALSE;
    }
}

static UINT32 getChargeCurrent(UINT8 index)
{
    if (chargeManager[index].getChargeCurrent) {
        return (chargeManager[index].getChargeCurrent());
    } else {
        chargeManagerPrintf("getChargeCurrent func is NULL, pmicName %s", pmicName[index]);
        return 0;
    }
}

static void closeCharge(UINT8 index)
{
    if (chargeManager[index].closeCharge) {
        chargeManager[index].closeCharge();
    } else {
        chargeManagerPrintf("closeCharge func is NULL, pmicName %s", pmicName[index]);
    }
}

static void openCharge(UINT8 index)
{
    if (chargeManager[index].openCharge) {
        chargeManager[index].openCharge();
    } else {
        chargeManagerPrintf("openCharge func is NULL, pmicName %s", pmicName[index]);
    }
}

// handle charger abnormal that can defer, eg:abnormal that shutdown charge due to high temperature
// this type of abnormal is periodically handled, because they can defer.
static void handleChargerAbnormal(UINT8 index)
{
    if (chargeManager[index].handleChargerAbnormal) {
        chargeManager[index].handleChargerAbnormal();
    } else {
        chargeManagerPrintf("handleChargerAbnormal func is NULL, pmicName %s", pmicName[index]);
    }
}

static UINT8 chargeICIDGet(void)
{
    UINT8 i = 0, regVal;

    for (i = 0; i < sizeof(chargeManager)/sizeof(struct chargeManagerT); i++) {
        if ((chargeManager[i].chargeICIDGet != NULL) && (chargeManager[i].chargeICIDGet() == chargeManager[i].id)) {
            regVal = chargeManager[i].id;
            break;
        }
    }

    return regVal;
}


static BOOL checkPowerOnOrPowerOff(UINT8 index)
{
    /*
    * 1, the charger/USB might not be plugged out after the battery is full charged,
    * and the charger/USB is wakeup source, if OBM power down the system after
    * full charged, it will wake up the system again...
    *
    * 2, if the charge function is disabled after full charged, the system power will
    * be supplied from battery, it's not acceptable since the battery power will be
    * exhausted...
    *
    * 3, the charger/USB can supply power to system too, and the charge function uses
    * the same HW line connection as power supply function on Nezha LET MIFI 2.0,
    * so, OBM will keep charge function, and let the charger/USB supply the system power.
    */
    chargeManagerPrintf("charging is done!");

    while (1) {
        /*
        * Normal power supply of USB/charger is controlled by the host with the t32s timer
        * running to ensure that the host is alive. When the timer times out, the power
        * supply is terminated.
        */
        //  resetTimer();

        if (powerOnKeyCheck(index, 3)) {
            chargeManagerPrintf("onkey pressed, boot");
            return TRUE;
        }

        if (!usbConnectCheck(index)) {
            chargeManagerPrintf("charger is plugged out!");
            systemPowerOff(index);
        }
    }
}

static void batteryCharge(UINT8 index)
{
    UINT16 vBat;
    UINT32 chargeCurrent;
    BOOL batConnectState, usbConnectState, chargerSkipped = FALSE, mpptDone = FALSE;

    uudelay(1000 * 100);

    while (!chargerSkipped) {
        batConnectState = batteryConnectCheck(index);
//        batConnectState = TRUE;
        usbConnectState = usbConnectCheck(index);
        vBat = batInstantVoltGet(index, usbConnectState);
        chargeManagerPrintf("vBat : %d", vBat);
        chargeCurrent = getChargeCurrent(index);
        chargeManagerPrintf("chargeCurrent : %d", chargeCurrent);

        // periodically handle charger abnormal
        handleChargerAbnormal(index);

        // if USB is not connectted when charge is in process, power down system
        if (usbConnectState) {
            if (batConnectState) {
                charging = TRUE;
                if (vBat < Battery_Low_Voltage) {
                    /*
                    * System is forbidden to boot up if battery voltage is lower than power up voltage,
                    * it has to wait for OBM charging battery to enough voltage
                    */
                    chargeManagerPrintf("battery low voltage");

                    if (!mpptDone && chargerCC(index)) {
                        if (setMPP(index, 1000)) {
                            mpptDone = TRUE;
                        }
                    }

                    if (getChargeStatus(index)) {  // do mmpt when vbus re_plug, ov or uv
                        setMPP(index, 1000);
                    }

                    uudelay(1000 * 1000);
                    continue;
                } else {
                    if (!(chargerFull(index))) {
                        /*
                        * Battery voltage is enough for system requirement, and system is permitted to boot up
                        * if ONKey press longer than 3s
                        */
                        chargeManagerPrintf("battery not full, please long press onKey to wakeup");
                        if (!mpptDone && chargerCC(index)) {
                            if (setMPP(index, 1000)) {
                                mpptDone = TRUE;
                            }
                        }

                        if (getChargeStatus(index)) {  // do mmpt when vbus re_plug, ov or uv
                            setMPP(index, 1000);
                        }

                        chargerSkipped = powerOnKeyCheck(index, 3);
                    } else {
                        // Once the battery is charged full, no charge any more, check if boot and if power off
                        chargeManagerPrintf("battery full, please long press onKey to wakeup");
                        chargerSkipped = checkPowerOnOrPowerOff(index);
                    }
                    uudelay(1000 * 1000);
                }
            } else {
                chargerSkipped = TRUE;
                chargeManagerPrintf("battery is plugged out!");
            }
        } else {
            chargeManagerPrintf("charger is plugged out!");
            if (charging) {
                systemPowerOff(index);
            } else {
                if (vBat >= Battery_Low_Voltage) {
                    return;
                }
            }
        }

        if (chargerSkipped) {
            continue;
        }

        uudelay(1000 * 100);
    }
}

static void chargeProcess(UINT8 index)
{
    UINT16 vBat;
    BOOL batConnectState, usbConnectState;
    enum powerUpTypeE powerUpType = PowerUP_Unkown;

    mdelay(10);
    batConnectState = batteryConnectCheck(index); // no implement in status register 1
//    batConnectState = TRUE;
    chargeManagerPrintf("batConnectState %d", batConnectState);
    usbConnectState = usbConnectCheck(index);
    chargeManagerPrintf("usbConnectState %d", usbConnectState);
    powerUpType = wakeUpCheck(index, batConnectState);
    chargeManagerPrintf("powerUpType %d", powerUpType);
    vBat = batInstantVoltGet(index, usbConnectState);

    if (batConnectState) {
        if (powerUpType == PowerUP_Battery) {
            if (vBat < Battery_Low_Voltage) {
                systemPowerOff(index);
            }
            chargeManagerPrintf("powerOn that is woken up by battery");
        } else if (powerUpType == PowerUP_ONKEY) {
            if (vBat < Battery_Low_Voltage) {
                if (!usbConnectState) {
                    systemPowerOff(index);
                }
                chargeManagerPrintf("powerOn that is woken up by onKey on usb");
            } else {
                if (powerOnKeyCheck(index, 3)) {
                    chargeManagerPrintf("powerOn that is woken up by onKey on battery or usb");
                    return;
                }
            }
        } else if (powerUpType == PowerUP_USB) {
            if (!usbConnectState) {
                 if (vBat < Battery_Low_Voltage) {
                    systemPowerOff(index);
                 }
                 chargeManagerPrintf("powerOn that is woken up by usb on battery");
            } else {
                chargeManagerPrintf("powerOn that is woken up by usb");
            }
        } else {
            chargeManagerPrintf("invalid resource which wakeup pmic");
        }

        charging = FALSE;
        batteryCharge(index);
    } else {
        if (powerUpType == PowerUP_Battery) {
            systemPowerOff(index); // can go here (powerup by battery and battery disconnect) ??
        } else if (powerUpType == PowerUP_ONKEY) {
            if (!usbConnectState) {
                systemPowerOff(index);
            } else {
                if (powerOnKeyCheck(index, 3)) {
                    chargeManagerPrintf("powerOn that is woken up by onKey on usb");
                } else {
                    systemPowerOff(index);
                }
            }
        } else if (powerUpType == PowerUP_USB) {
            if (!usbConnectState) {
                systemPowerOff(index); // can go here (powerup by usb and usb disconnect) ??
            }
            chargeManagerPrintf("powerOn that is woken up by usb");
        }  else {
            chargeManagerPrintf("invalid resource which wakeup pmic");
        }
    }
}

extern void guiLinICRegister(void);
extern void pm812ICRegister(void);
extern void ningBoICRegister(void);
extern void guiLinLiteICRegister(void);

static void chargeICRegister(void)
{
//    guiLinICRegister();
//    pm812ICRegister();
    ningBoICRegister();
    guiLinLiteICRegister();
}

void DM_CHARGE_Manager(void)
{
    UINT8 i = 0;
    BOOL initDone = FALSE;

    chargeICRegister();

//    i2cInit();    // init is done in pmic.c, so donot init again

    UINT8 chargeICID = chargeICIDGet();
    chargeManagerPrintf("%s chargeICID %x", __FUNCTION__, chargeICID);

    for (i = 0; i < sizeof(chargeManager)/sizeof(struct chargeManagerT); i++) {
        if (chargeManager[i].id != chargeICID) {
            continue;
        }

        if (chargeManager[i].init != NULL) {
            if (chargeManager[i].need3rdCharge) {
                charge3rdInit();
            }

            chargeManager[i].init();
            initDone = TRUE;
            break;
        }
    }

    if (initDone) {
        chargeProcess(i);
    } else {
        chargeManagerPrintf("charge init failed");
    }
}
