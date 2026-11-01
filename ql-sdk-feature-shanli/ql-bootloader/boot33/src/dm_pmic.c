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
#include "dm_pmic.h"

static BOOL charging = FALSE;
/** support 8 power manage ic **/
struct pmicInitManagerT pmicInitManager[8] = {0};

#define pmicPrintf(fmt, args...) do { uart_printf("[pmic]"fmt, ##args); } while(0)

void uudelay(int us)
{
  volatile UINT32 i;
  for(i=0; i < us*100; i++)
    i = i+1;
}

void mdelay(int ms)
{
  volatile UINT32 i;

  for(i=0; i<ms; i++) {
    uudelay(10);
  }
}

static BOOL batteryConnectCheck(UINT8 index)
{
    return pmicInitManager[index].batteryConnectCheck();
}

static BOOL usbConnectCheck(UINT8 index)
{
    return pmicInitManager[index].usbConnectCheck();
}

static enum powerUpTypeE wakeUpCheck(UINT8 index, BOOL batConnectState)
{
    return pmicInitManager[index].wakeUpCheck(batConnectState);
}

static BOOL powerOnKeyCheck(UINT8 index, UINT8 timeOutValue)
{
    return pmicInitManager[index].powerOnKeyCheck(timeOutValue);
}

static void chargerEnable(UINT8 index)
{
    pmicInitManager[index].chargerEnable();
}

static UINT16 batInstantVoltGet(UINT8 index, BOOL usbStatus)
{
    return pmicInitManager[index].batInstantVoltGet(usbStatus);
}

static void systemPowerOff(UINT8 index)
{
    pmicInitManager[index].systemPowerOff();
}

static BOOL chargerFull(UINT8 index)
{
    return (pmicInitManager[index].chargerFull());
}

static BOOL chargerCC(UINT8 index)
{
    return (pmicInitManager[index].chargerCC());
}

static BOOL setMPP(UINT8 index, UINT16 limit)
{
    return (pmicInitManager[index].setMPP(limit));
}

static UINT8 pmicIDGet(void)
{
    UINT8 i = 0, regVal;

    for (i = 0; i < sizeof(pmicInitManager)/sizeof(struct pmicInitManagerT); i++) {
        if ((pmicInitManager[i].pmicIDGet != NULL) && ((pmicInitManager[i].pmicIDGet() & 0xF0) >> 4 == pmicInitManager[i].id)) {
            regVal = pmicInitManager[i].id;
            pmicPrintf("pmicId : %x\r\n", regVal);
        }
    }

    return regVal;
}

static BOOL pmicSubIDGet(void)  // sub id for ningbo: A1 A2 A3
{
    UINT8 i = 0, regVal;

    for (i = 0; i < sizeof(pmicInitManager)/sizeof(struct pmicInitManagerT); i++) {
        if ((pmicInitManager[i].subId != 0)
            && (pmicInitManager[i].pmicIDGet != NULL)
            && ((regVal = pmicInitManager[i].pmicIDGet()) == pmicInitManager[i].subId)) {
            break;
        }
    }
    pmicPrintf("pmicSubId : %x\r\n", regVal);
    return regVal;
}

static void batteryTimer(void)
{

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
    pmicPrintf("charging is done!\r\n");

    while (1) {
        /*
        * Normal power supply of USB/charger is controlled by the host with the t32s timer
        * running to ensure that the host is alive. When the timer times out, the power
        * supply is terminated.
        */
        //  resetTimer();

        if (powerOnKeyCheck(index, 3)) {
            pmicPrintf("onkey pressed, boot\r\n");
            return TRUE;
        }

        if (!usbConnectCheck(index)) {
            pmicPrintf("charger is plugged out!\r\n");
            systemPowerOff(index);
        }
    }
}

static void batteryCharge(UINT8 index)
{
    UINT16 vBat;
    BOOL batConnectState, usbConnectState, chargerSkipped = FALSE;
    BOOL mpptDone = FALSE;

    // enable charger, and charge start...
    chargerEnable(index);

    while (!chargerSkipped) {
        batteryTimer();

        batConnectState = batteryConnectCheck(index);
//        batConnectState = TRUE;
        usbConnectState = usbConnectCheck(index);
        vBat = batInstantVoltGet(index, usbConnectState);
        pmicPrintf("vBat : %d\r\n", vBat);

        // if USB is not connectted when charge is in process, power down system
        if (usbConnectState) {
            if (batConnectState) {
                charging = TRUE;
                if (vBat < Battery_Low_Voltage) {
                    /*
                    * System is forbidden to boot up if battery voltage is lower than power up voltage,
                    * it has to wait for OBM charging battery to enough voltage
                    */
                    pmicPrintf("battery low voltage\r\n");

                    if (!mpptDone && chargerCC(index)) {
                        if (setMPP(index, 1000)) {
                            mpptDone = TRUE;
                        }
                    }
                    uudelay(1000 * 1000);
                    continue;
                } else {
                    if (!(chargerFull(index))) {
                        /*
                        * Battery voltage is enough for system requirement, and system is permitted to boot up
                        * if ONKey press longer than 3s
                        */
                        pmicPrintf("battery not full\r\n");
                        if (!mpptDone && chargerCC(index)) {
                            if (setMPP(index, 1000)) {
                                mpptDone = TRUE;
                            }
                        }
                        chargerSkipped = powerOnKeyCheck(index, 3);
                    } else {
                        // Once the battery is charged full, no charge any more, check if boot and if power off
                        pmicPrintf("battery full\r\n");
                        chargerSkipped = checkPowerOnOrPowerOff(index);
                    }
                } 
            } else {
                chargerSkipped = TRUE;
                pmicPrintf("battery is plugged out!\r\n");
            }
        } else {
            pmicPrintf("charger is plugged out!\r\n");
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

static void pmicProcess(UINT8 index)
{
    UINT16 vBat;
    BOOL batConnectState, usbConnectState;
    enum powerUpTypeE powerUpType = PowerUP_Unkown;

    mdelay(10);
    batConnectState = batteryConnectCheck(index); // no implement in status register 1
//    batConnectState = TRUE;
    usbConnectState = usbConnectCheck(index);
    powerUpType = wakeUpCheck(index, batConnectState);
    vBat = batInstantVoltGet(index, usbConnectState);

    if (batConnectState) {
        if (powerUpType == PowerUP_Battery) {
            if (vBat < Battery_Low_Voltage) {
                systemPowerOff(index);
            }
            pmicPrintf("powerOn that is woken up by battery\r\n");
        } else if (powerUpType == PowerUP_ONKEY) {
            if (vBat < Battery_Low_Voltage) {
                if (!usbConnectState) {
                    systemPowerOff(index);
                }
                pmicPrintf("powerOn that is woken up by onKey on usb\r\n");
            } else {
                if (powerOnKeyCheck(index, 3)) {
                    pmicPrintf("powerOn that is woken up by onKey on battery or usb\r\n");
                    return;
                }
            }
        } else if (powerUpType == PowerUP_USB) {
            if (!usbConnectState) {
                 if (vBat < Battery_Low_Voltage) {
                    systemPowerOff(index);
                 }
                 pmicPrintf("powerOn that is woken up by usb on battery\r\n");
            } else {
                pmicPrintf("powerOn that is woken up by usb\r\n");
            }
        } else {
            pmicPrintf("invalid resource which wakeup pmic\r\n");
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
                    pmicPrintf("powerOn that is woken up by onKey on usb\r\n");
                } else {
                    systemPowerOff(index);
                }
            }
        } else if (powerUpType == PowerUP_USB) {
            if (!usbConnectState) {
                systemPowerOff(index); // can go here (powerup by usb and usb disconnect) ??
            }
            pmicPrintf("powerOn that is woken up by usb\r\n");
        }  else {
            pmicPrintf("invalid resource which wakeup pmic\r\n");
        }
    }
}

extern void guiLinICRegister(void);
extern void pm812ICRegister(void);
extern void ningBoICRegister(void);

static void pmicRegister(void)
{
//    guiLinICRegister();
//    pm812ICRegister();
    ningBoICRegister();
}

void DM_PMIC_Init(void)
{
    UINT8 i = 0;
    UINT8 pmicIndex = 0;
    BOOL initDone = FALSE;

    pmicRegister();

//    i2cInit();

    UINT8 pmicId = pmicIDGet();
    UINT8 pmicSubId = pmicSubIDGet();

    for (i = 0; i < sizeof(pmicInitManager)/sizeof(struct pmicInitManagerT); i++) {
        if (pmicInitManager[i].id == pmicId) {
            if (pmicInitManager[i].subId != 0) {
                if (pmicInitManager[i].subId == pmicSubId) {
                    if (pmicInitManager[i].init != NULL) {
                        pmicInitManager[i].init();
                        initDone = TRUE;
                        pmicIndex = i;
                        break;
                    }
                }
            } else {
               if (pmicInitManager[i].init != NULL) {
                   pmicInitManager[i].init();
                   pmicIndex = i;
                   initDone = TRUE;
                   break;
               }
            }
        }
    }

    if (initDone) {
        pmicProcess(pmicIndex);
    } else {
        pmicPrintf("pmic init failed\r\n");
    }
}
