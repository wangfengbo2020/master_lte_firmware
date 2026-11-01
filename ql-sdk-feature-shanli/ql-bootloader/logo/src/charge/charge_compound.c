/*-----------------------------------------------------------------------------------------------------------------
    charge_compound.c
    This file implements the function of combine pmic and third party charge ic when use third party charge ic and
    pmic without charge function in some board.
-------------------------------------------------------------------------------------------------------------------*/
//#include <stdlib.h>

#include "charge/charge_compound.h"
#include "charge/charge.h"

#define chargeCompoundPrintf(fmt, args...)  do { uart_printf("[chargeCompound]"fmt"\r\n", ##args); } while(0)

static char *pmicName[8] = {"guilin", "pm812", "ningbo", "guilinlite"};

/** support 8 3rd charge ic control info **/
static struct charg3rdControlInfoT charg3rdControlInfo[8] = {
    {ETA4256, "eta4256", TRUE},
};
/** support 8 3rd charge ic manager **/
struct charge3rdManagerT charge3rdManager[8] = {0};

extern void eta4256RegisterToCompound(void);
//extern void eta6005RegisterToCompound(void);
static void charge3rdRegister(void)
{
    eta4256RegisterToCompound();
    //eta6005RegisterToCompound();
}

void charge3rdInit(void)
{
    UINT8 i = 0;
    charge3rdRegister();

    for (i = 0; i < sizeof(charg3rdControlInfo)/sizeof(struct charg3rdControlInfoT); i++) {
        if (charg3rdControlInfo[i].enable) { // only one third party charge ic is enable in one board.
            chargeCompoundPrintf("third party charge ic(%s) init doing.", charg3rdControlInfo[i].name);
            charge3rdManager[i].init();
            chargeCompoundPrintf("third party charge ic(%s) init done.", charg3rdControlInfo[i].name);
            break;
        }
    }
}

void pmicCombineWith3rdCharger(UINT8 family, void *chargeManager)
{
    UINT8 i = 0;

    for (i = 0; i < sizeof(charg3rdControlInfo)/sizeof(struct charg3rdControlInfoT); i++) {
        if (charg3rdControlInfo[i].enable) { // only one third party charge ic is enable in one board.
            charge3rdManager[i].charge3rdCombineWithPimc(chargeManager);
            chargeCompoundPrintf("combine %s with third party charge ic(%s)", pmicName[family], charg3rdControlInfo[i].name);
            break;
        }
    }
}
