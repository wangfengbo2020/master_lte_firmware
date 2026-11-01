#ifndef _DM_PIMC_H_
#define _DM_PIMC_H_
#include "common.h"

#define Battery_Low_Voltage         3450
#define Battery_Full_Voltage        4350
#define Hours_6                     (6 * 60 * 60)
#define Hours_2                     (2 * 60 * 60)

/** power manage ic family define **/
#define GUILIN                      0
#define PM812                       1
#define NINGBO                      2

typedef union counter32 {
    UINT8   cnt_8[4];
    UINT32  cnt_32;
} counter32U;

typedef enum powerUpTypeE {
    PowerUP_Battery         =       0,
    PowerUP_ONKEY           =       1,
    PowerUP_USB             =       2,
    PowerUP_External        =       3,
    PowerUP_Reset           =       4,
    PowerUP_Unkown          =       0xff
} powerUpTypeEE;

typedef struct pmicInitManagerT {
    UINT8 family;
    UINT8 id;
    UINT8 subId;
    UINT8 (*pmicIDGet)(void);
    void (*init)(void);
    BOOL (*batteryConnectCheck)(void);
    BOOL (*usbConnectCheck)(void);
    enum powerUpTypeE (*wakeUpCheck)(BOOL batConnectState);
    BOOL (*powerOnKeyCheck)(UINT8 timeOutValue);
    void (*chargerEnable)(void);
    UINT16 (*batInstantVoltGet)(BOOL usbStatus);
    UINT16 (*batStableVoltGet)(UINT8 *pPercent);
    void (*systemPowerOff)(void);
    BOOL (*chargerFull)(void);
    BOOL (*chargerCC)(void);
    UINT8 (*getFSM)(void);
    BOOL (*chargerFault)(void);
    void (*forceFSM)(UINT8 state);
    BOOL (*setMPP)(UINT16 limit);
} pmicInitMagnagerTT;

extern struct pmicInitManagerT pmicInitManager[8];

void uudelay(int us);
void mdelay(int ms);
void PMIC_Init(void);
#endif /* _DM_PIMC_H_ */
