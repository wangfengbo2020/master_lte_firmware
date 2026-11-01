#include "plat_types.h"
//#include "pmic.h"

void uiD2CallbackRegister(int id,lpEnterD2Callback enter,lpExitD2Callback exit)
{
    return;
}

void uiD2CallbackunRegister(int id)
{
    return;
}


void uiC1CallbackRegister(int id,lpEnterC1Callback enter,lpExitC1Callback exit)
{
    return;
}

void uiC1CallbackunRegister(int id)
{
    return;
}

void uiSetSuspendFlag(int id,int flag)
{
    return;
}
extern void NingboLcdBackLightCtrl(UINT8 level); //should be 0~5
void PmicLcdBackLightCtrl(uint8_t level)
{
    NingboLcdBackLightCtrl(level);
    return;
}

extern BOOL PMIC_IS_PM812(void);
extern BOOL PMIC_IS_PM813(void);

BOOL Pmic_is_pm812(void)
{
    return PMIC_IS_PM812();
}
BOOL Pmic_is_pm813(void)
{
    return PMIC_IS_PM813();
}


void Performance_Exit(char * str)
{
    return;
}

bool g_delay_backlight_enable=FALSE;


void Performance_Entry(char *str,int mode,int valu1,int value2)
{
    return;
}

