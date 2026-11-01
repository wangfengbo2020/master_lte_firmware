/*============================================================
    eta4256.c
    eta4256 is 3rd IC which only implement feature of charging;
    use this file when eta4256 and pm803 implement in one board;
    need replace pm803 api if eta4256 implement in one board with
    other pmic ic, eg.pm802...
==============================================================*/
#include "utilities.h"
#include "bsp.h"
#include "charge/charge.h"
#include "charge/charge_compound.h"
#include "charge/eta4256.h"

#define eta4256Printf(fmt, args...)  do { uart_printf("[eta4256Charge]"fmt"\r\n", ##args); } while(0)

#define BIT13                       0x00002000
#define BIT14                       0x00004000

//1603
#define CHG_EN_GPIO_MFPR            0xD401E114
#define CHG_STAT_GPIO_MFPR          0xD401E110

#define CHG_EN                      BIT14 //out
#define CHG_STAT                    BIT13 //in

//1606
#define CHG_STAT_GPIO_MFPR_6          0xD401E114
#define CHG_STAT_6                    BIT14 //in

#define GPIO0_BASE                  0xD4019000

#define GPIO_PLR                    (0x0000)    /* 32 bit   GPIO Pin-Level Register */
#define GPIO_PDR                    (0x000C)    /* 32 bit   GPIO Pin Direction Register */
#define GPIO_PSR                    (0x0018)    /* 32 bit   GPIO Pin Output Set Register */
#define GPIO_PCR                    (0x0024)    /* 32 bit   GPIO Pin Output Clear Register */

static void eta4256Init(void)
{
    eta4256Printf("%s", __FUNCTION__);

    UINT32 v_reg = 0;

    if (CHIP_IS_CRANEL || CHIP_IS_CRANELS || CHIP_IS_CRANELR) {
        reg_write(CHG_STAT_GPIO_MFPR_6, 0xC880 | 0x0); // GPIO14  0xC880   0x00c0
        //set GPIO dir IN
        v_reg = reg_read(GPIO0_BASE + GPIO_PDR);    //CHG_STATUS, GPIO14, AF0
        reg_write((GPIO0_BASE + GPIO_PDR), v_reg & (~CHG_STAT_6));
        v_reg = reg_read(GPIO0_BASE + GPIO_PDR); // read it
        eta4256Printf("%s GPIO0 PDR6 %x", __FUNCTION__, v_reg);
    } else {
        reg_write(CHG_EN_GPIO_MFPR, 0xC880 | 0x0);    // GPIO14  0xC880 0x00c0
        //set GPIO dir OUT
        v_reg = reg_read((GPIO0_BASE + GPIO_PDR));      //CHG_DISABLE, GPIO14, AF0
        reg_write((GPIO0_BASE + GPIO_PDR), v_reg | CHG_EN);
        reg_write((GPIO0_BASE + GPIO_PCR), CHG_EN); //GPIO14 charge enable

        reg_write(CHG_STAT_GPIO_MFPR, 0xC880 | 0x0); // GPIO13  0xC880   0x00c0
        //set GPIO dir IN
        v_reg = reg_read(GPIO0_BASE + GPIO_PDR);    //CHG_STATUS, GPIO13, AF0
        reg_write((GPIO0_BASE + GPIO_PDR), v_reg & (~CHG_STAT));
        v_reg = reg_read(GPIO0_BASE + GPIO_PDR); // read it
        eta4256Printf("%s GPIO0 PDR %x", __FUNCTION__, v_reg);
    }
}

static BOOL checkChargerFullBit(UINT32 v_reg)
{
    if (CHIP_IS_CRANEL || CHIP_IS_CRANELS || CHIP_IS_CRANELR) {
        return ((v_reg & CHG_STAT_6) == CHG_STAT_6);
    } else {
        return ((v_reg & CHG_STAT) == CHG_STAT);
    }
}

static BOOL eta4256ChargerFull(void)
{
    eta4256Printf("%s", __FUNCTION__);

    if (checkChargerFullBit(reg_read(GPIO0_BASE + GPIO_PLR))) {
        eta4256Printf("battery full");
        return TRUE;
    } else {
        eta4256Printf("battery Not full");
        return FALSE;
    }
}

static void eta4256CloseCharge(void)
{
    eta4256Printf("%s", __FUNCTION__);

    if (CHIP_IS_CRANEL || CHIP_IS_CRANELS || CHIP_IS_CRANELR) {
        ;
    } else {
        reg_write((GPIO0_BASE + GPIO_PSR), CHG_EN); //GPIO14 charge disable
    }
}

static void eta4256OpenCharge(void)
{
    eta4256Printf("%s", __FUNCTION__);

    if (CHIP_IS_CRANEL || CHIP_IS_CRANELS || CHIP_IS_CRANELR) {
        ;
    } else {
        reg_write((GPIO0_BASE + GPIO_PCR), CHG_EN); //GPIO14 charge enable
    }
}

static void eta4256CombineWithPimc(void *pmicWithoutChargeManager)
{
    struct chargeManagerT *chargeManager = (struct chargeManagerT *)pmicWithoutChargeManager;

    chargeManager->chargerFull = charge3rdManager[ETA4256].chargerFull;
    chargeManager->closeCharge = charge3rdManager[ETA4256].closeCharge;
    chargeManager->openCharge = charge3rdManager[ETA4256].openCharge;
}

static struct charge3rdManagerT eta4256ChargeManager = {
    .family3rd = ETA4256,
    .init = eta4256Init,
    .chargerFull = eta4256ChargerFull,
    .closeCharge = eta4256CloseCharge,
    .openCharge = eta4256OpenCharge,
    .charge3rdCombineWithPimc = eta4256CombineWithPimc,
};

void eta4256RegisterToCompound(void)
{
    charge3rdManager[eta4256ChargeManager.family3rd] = eta4256ChargeManager;
}