/*============================================================
    ningbo_dm.c
    overwrite function which is define in ningbo.c for replacing
    those function, so they look a little like; function ONLY is
    related to charge in this file, other function of pmic isn't
    overwritten, so you can use function that is in this file,
    OR in ningbo.c file for charging code, you ONLY use function
    that in ningbo.c for non-charging code.
==============================================================*/
#include "dm_charge.h"
#include "dm_i2c.h"
#include "dm_ningbo.h"

#define ningBoPrintf(fmt, args...) do { uart_printf("[ningBoCharge]"fmt"\r\n", ##args); } while(0)

static UINT16 currentMap[] = {100, 200, 300, 400, 450, 500, 550, 600, 650,
                              700, 750, 800, 850, 900, 950, 1000, 150, 250, 350};

static UINT8 i2cRead(ningBoRegTypeE ningBoRegType, UINT8 reg, UINT8 *regVal)
{
    UINT8 res = 0;
    switch(ningBoRegType) {
        case NINGBO_BASE_Reg:
            res = i2cReceive(NINGBO_READ_BASE_SLAVE_ADDRESS, reg);
            break;
        case NINGBO_POWER_Reg:
            res = i2cReceive(NINGBO_READ_POWER_SLAVE_ADDRESS, reg);
            break;
        case NINGBO_GPADC_Reg:
            res = i2cReceive(NINGBO_READ_GPADC_SLAVE_ADDRESS, reg);
            break;
        case NINGBO_TEST_Reg:
            res = i2cReceive(NINGBO_READ_TEST_SLAVE_ADDRESS, reg);
            break;
        default:
            break;
    }

    *regVal = res;
    return 0;
}

static I2C_ReturnCode i2cWrite(ningBoRegTypeE ningBoRegType, UINT8 reg, UINT8 regVal )
{
    I2C_ReturnCode status = I2C_RC_OK;
    switch(ningBoRegType) {
        case NINGBO_BASE_Reg:
            status = i2cSend(NINGBO_WRITE_BASE_SLAVE_ADDRESS, reg, regVal);
            break;
        case NINGBO_POWER_Reg:
            status = i2cSend(NINGBO_WRITE_POWER_SLAVE_ADDRESS, reg, regVal);
            break;
        case NINGBO_GPADC_Reg:
            status = i2cSend(NINGBO_WRITE_GPADC_SLAVE_ADDRESS, reg, regVal);
            break;
        case NINGBO_TEST_Reg:
            status = i2cSend(NINGBO_WRITE_TEST_SLAVE_ADDRESS, reg, regVal);
            break;
        default:
            break;
    }
    return status;
}

static void ningBoFaultWuBitEnable(void)
{
    UINT8 tmp;
    //set fault_wu_en
    i2cRead(NINGBO_BASE_Reg, NINGBO_FAULT_WU_REG, &tmp);
    i2cWrite(NINGBO_BASE_Reg, NINGBO_FAULT_WU_REG, tmp | NINGBO_FAULT_WU_ENABLE_BIT);
}

static void ningBoFaultWuEnable(void)
{
    UINT8 tmp;
    //then set fault_wu
    i2cRead(NINGBO_BASE_Reg, NINGBO_FAULT_WU_REG, &tmp);
    i2cWrite(NINGBO_BASE_Reg, NINGBO_FAULT_WU_REG, tmp | NINGBO_FAULT_WU_BIT);
}

static void ningBoWDTEnable(void)
{
    UINT8 var = 0;
    ningBoFaultWuBitEnable();
    ningBoFaultWuEnable();

    i2cRead(NINGBO_BASE_Reg, NINGBO_WD_REG, &var);
    var &= ~NINGBO_WD_DIS_BIT;
    i2cWrite(NINGBO_BASE_Reg, NINGBO_WD_REG, var);
}

static void ningBoWDTDisable(void)
{
    UINT8 var = 0;
    ningBoFaultWuBitEnable();
    ningBoFaultWuEnable();

    i2cRead(NINGBO_BASE_Reg, NINGBO_WD_REG, &var);
    var |= NINGBO_WD_DIS_BIT;
    i2cWrite(NINGBO_BASE_Reg, NINGBO_WD_REG, var);
}

static void ningBoActWDTimeoutSet(UINT8 timeout)
{
    UINT8 tmp;
    i2cRead(NINGBO_BASE_Reg, NINGBO_WD_TIMER_REG, &tmp);
    tmp &= ~NINGBO_WD_TIMER_ACT_BITS;
    i2cWrite(NINGBO_BASE_Reg, NINGBO_WD_TIMER_REG, tmp | timeout);
}

//enable/disable the  INT report to master processer
static void ningBoIntToHostEnable(ningBoIntcE intc)
{
    UINT8 tmp;
    UINT8 reg_addr = NINGBO_INTC_TO_ENABLE_REG(intc);
    i2cRead(NINGBO_BASE_Reg, reg_addr, &tmp);
    tmp |= NINGBO_INTC_TO_ENABLE_BIT(intc);
    i2cWrite(NINGBO_BASE_Reg, reg_addr, tmp);
}

static void ningBoIntToHostDisable(ningBoIntcE intc)
{
    UINT8 tmp;
    UINT8 reg_addr = NINGBO_INTC_TO_ENABLE_REG(intc);
    i2cRead(NINGBO_BASE_Reg, reg_addr, &tmp);
    tmp &= (~(NINGBO_INTC_TO_ENABLE_BIT(intc)));
    i2cWrite(NINGBO_BASE_Reg, reg_addr, tmp);
}

static void ningBoIntDisable(ningBoIntcE intc)
{
//    mNingboIntHandler[intc].pmic_intc_enabled = FALSE;
    ningBoIntToHostDisable(intc);
}

static void ningBoIntEnable(ningBoIntcE intc)
{
//    mNingboIntHandler[intc].pmic_intc_enabled = TRUE;
    ningBoIntToHostEnable(intc);
}

static void prechargeCurrentSet(UINT8 regVal)
{
    UINT8 var = 0;

    if (regVal > PRE_CHG_CUR_MAX) {
        regVal = PRE_CHG_CUR_MAX;
    }

    i2cRead(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_CURRENT1_REG, &var);
    var &= ~NINGBO_CHG_PRE_CUR_MASK;
    var |= regVal << NINGBO_CHG_PRE_CUR_SHIFT;
    i2cWrite(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_CURRENT1_REG, var);
}

static void chargerInternalDrvSegmentSet(BOOL Enable)
{
    unsigned char var;
    i2cRead(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_TIMER2_REG, &var);
    if (Enable)
        var |= (0x1 << NINGBO_CHG_CTRL_DRV_SEGMENT_EN);
    else
        var &= ~(0x1 << NINGBO_CHG_CTRL_DRV_SEGMENT_EN);
    i2cWrite(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_TIMER2_REG, var);
}

static void chargeTermCurrentSet(UINT8 regVal)
{
    UINT8 var = 0;

    if (regVal > TERM_CHG_CUR_MAX) {
        regVal = TERM_CHG_CUR_MAX;
    }

    i2cRead(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_CURRENT1_REG, &var);
    var &= ~NINGBO_CHG_TERM_CUR_MASK;
    var |= regVal << NINGBO_CHG_TERM_CUR_SHIFT;
    i2cWrite(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_CURRENT1_REG, var);
}

static void chargerMosfetDrvSegmentSet(UINT8 drvSeg)
{
    UINT8 var = 0;

    if (drvSeg > 12) {
        ningBoPrintf("%s:%d", __FILE__, __LINE__);
    }

    i2cRead(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_MISC2_REG, &var);
    var &= ~0xF;
    var |= drvSeg; /* divided by 12 */
    i2cWrite(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_MISC2_REG, var);
}

static void ccMaxCurrentSet(ningBoCcChgCurrentE regVal)
{
    UINT8 var = 0;
//    ningBoPrintf("mapIndex : %d, curretn value : %dmA", regVal, currentMap[regVal]);
    if (regVal > CC_CHG_CUR_MAX) {
        regVal = CC_CHG_CUR_MAX;
    }

    switch (regVal) {
        case CC_CHG_CUR_150MA:
            regVal = CC_CHG_CUR_100MA;
            break;
        case CC_CHG_CUR_250MA:
            regVal = CC_CHG_CUR_200MA;
            break;
        case CC_CHG_CUR_350MA:
            regVal = CC_CHG_CUR_300MA;
            break;
        default:
            chargerMosfetDrvSegmentSet(0);
            break;
    }

    i2cRead(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_CURRENT2_REG, &var);
    var &= ~NINGBO_CHG_MAX_CURRENT_MASK;
    var |= regVal << NINGBO_CHG_MAX_CURRENT_SHIFT;
    i2cWrite(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_CURRENT2_REG, var);
}

static void ccCurrentSet(UINT8 regVal)
{
    UINT8 var = 0;

    if (regVal > 15) {
        regVal = 15;
    }

    i2cRead(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_CURRENT2_REG, &var);
    var &= ~NINGBO_CHG_CURRENT_MASK;
    var |= regVal << NINGBO_CHG_CURRENT_SHIFT;
    i2cWrite(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_CURRENT2_REG, var);
}

static void ningBoChargerVbat4p4Set(BOOL OnOff)
{
    UINT8 var = 0;

    //Vbat reference, select 1.05V (FALSE), or 1.1V (TRUE).
    i2cRead(NINGBO_BASE_Reg, NINGBO_RTC_CONTROL_REG, &var);
    if (OnOff) {
        var |= NINGBO_VBAT_4P4_EN_BIT;
    } else {
        var &= ~NINGBO_VBAT_4P4_EN_BIT;
    }
    i2cWrite(NINGBO_BASE_Reg, NINGBO_RTC_CONTROL_REG, var);
}

static void ningBoVbatSet(ningBoVbatVoltageE regVal)
{
    UINT8 var = 0;

    if (regVal > VBAT_VOL_MAX) {
        regVal=VBAT_VOL_MAX;
    }

    switch (regVal) {
        case VBAT_VOL_4V30:
            regVal = VBAT_VOL_4V10;
            ningBoChargerVbat4p4Set(TRUE);
            break;
        case VBAT_VOL_4V40:
            regVal = VBAT_VOL_4V20;
            ningBoChargerVbat4p4Set(TRUE);
            break;
        default:
            ningBoChargerVbat4p4Set(FALSE);
            break;
    }

    i2cRead(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_TIMER2_REG, &var);
    var &= ~NINGBO_CHG_CTRL_BAT_VOLT_MASK;
    var |= regVal << NINGBO_CHG_CTRL_BAT_VOLT_SHIFT;
    i2cWrite(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_TIMER2_REG, var);
}

static void ningBoPrechargeTimerSet(UINT8 regVal)
{
    UINT8 var = 0;

    if (regVal > PRE_CHG_MINUTE_MAX) {
        regVal = PRE_CHG_MINUTE_MAX;
    }

    i2cRead(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_TIMER1_REG, &var);
    var &= ~NINGBO_CHG_CTRL_TIMER_PRE_CHG_MASK;
    var |= regVal<<NINGBO_CHG_CTRL_TIMER_PRE_CHG_SHIFT;
    i2cWrite(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_TIMER1_REG, var);
}

static void ningBoTrickleTimerSet(UINT8 regVal)
{
    UINT8 var = 0;

    if (regVal>TRICKLE_CHG_MINUTE_MAX) {
        regVal=TRICKLE_CHG_MINUTE_MAX;
    }

    i2cRead(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_TIMER1_REG, &var);
    var &= ~NINGBO_CHG_CTRL_TIMER_TRI_CHG_MASK;
    var |= regVal<<NINGBO_CHG_CTRL_TIMER_TRI_CHG_SHIFT;
    i2cWrite(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_TIMER1_REG, var);
}

static void ningBoCurrentCheckTimerSet(UINT8 regVal)
{
    UINT8 var = 0;

    if (regVal>CUR_CHK_SECOND_MAX) {
        regVal=CUR_CHK_SECOND_MAX;
    }

    i2cRead(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_TIMER1_REG, &var);
    var &= ~NINGBO_CHG_CTRL_TIMER_CHK_CUR_MASK;
    var |= regVal<<NINGBO_CHG_CTRL_TIMER_CHK_CUR_SHIFT;
    i2cWrite(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_TIMER1_REG, var);
}

static void ningBoVoltageCheckTimerSet(UINT8 regVal)
{
    UINT8 var = 0;

    if (regVal > VOL_CHK_MSECOND_MAX) {
        regVal = VOL_CHK_MSECOND_MAX;
    }

    i2cRead(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_TIMER1_REG, &var);
    var &= ~NINGBO_CHG_CTRL_TIMER_CHK_VOL_MASK;
    var |= regVal << NINGBO_CHG_CTRL_TIMER_CHK_VOL_SHIFT;
    i2cWrite(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_TIMER1_REG, var);
}

static void ningBoCcCvTimerSet(UINT8 regVal)
{
    UINT8 var = 0;

    if (regVal > CCCV_MINUTE_MAX) {
        regVal = CCCV_MINUTE_MAX;
    }

    i2cRead(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_TIMER2_REG, &var);
    var &= ~NINGBO_CHG_CTRL_TIMER_CCCV_MASK;
    var |= regVal << NINGBO_CHG_CTRL_TIMER_CCCV_SHIFT;
    i2cWrite(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_TIMER2_REG, var);
}

static void ningBoChargerTimerSwitch(BOOL OnOff)
{
    UINT8 var;

    i2cRead(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_TIMER2_REG, &var);
    if(OnOff) {
        var &= ~NINGBO_CHG_CTRL_TIMERKEEP_MASK; // 0 keep timer
    }
    else {
        var |= NINGBO_CHG_CTRL_TIMERKEEP_MASK; // 1 disable timer
    }
    i2cWrite(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_TIMER2_REG, var);
}

static UINT8 ningBoChargerFSMStateGet(void)
{
    UINT8 var;

    mdelay(5);
    i2cRead(NINGBO_BASE_Reg, NINGBO_READONLY_DATA_4_REG, &var);
    var = var >> NINGBO_CHG_FSM_SHIFT;
    return var;
}

static BOOL ningBoChargerErrorGet(void)
{
    return (ningBoChargerFSMStateGet() <=2);
}

//for 12bit vol meas
static void ningBoGpadcVolMeasureWrite(UINT8 meaReg, UINT16 mVolt)
{
  UINT8 reg_regVal[2];

  /* Write two registers, the alignment will be done as follows:
  Register 1 - bits 7:0 => 8 LSB bits <7:0> of regVal for comparison
  Register 2 - bits 3:0 => 4 MSB bits <11:8> of regVal for comparison
  */
  reg_regVal[0] = mVolt & 0xFF;
  reg_regVal[1] = (mVolt >> 8) & 0x0F;

  i2cWrite(NINGBO_GPADC_Reg, meaReg + 0, reg_regVal[0]);
  i2cWrite(NINGBO_GPADC_Reg, meaReg + 1, reg_regVal[1]);
}

static void ningBoBatteryTempReferenceSet(void)
{
    ningBoGpadcVolMeasureWrite(NINGBO_BAT_TEMP_60D_REG1, 0xA);
    ningBoGpadcVolMeasureWrite(NINGBO_BAT_TEMP_47D_REG1, 0xF);
    ningBoGpadcVolMeasureWrite(NINGBO_BAT_TEMP_43D_REG1, 0x11);
    ningBoGpadcVolMeasureWrite(NINGBO_BAT_TEMP_12D_REG1, 0x35);
    ningBoGpadcVolMeasureWrite(NINGBO_BAT_TEMP_8D_REG1, 0x3E);
    ningBoGpadcVolMeasureWrite(NINGBO_BAT_TEMP_5D_REG1, 0x47);
    ningBoGpadcVolMeasureWrite(NINGBO_BAT_TEMP_0D_REG1, 0x58);
}

static void ningBoFaultClear(void)
{
    UINT8 var;

    i2cRead(NINGBO_BASE_Reg, NINGBO_RTC_MISC_5_REG, &var);
    var &= ~NINGBO_RTC_FAULT_WU_EN_BIT;
    i2cWrite(NINGBO_BASE_Reg, NINGBO_RTC_MISC_5_REG, var);
    var |= NINGBO_RTC_FAULT_WU_EN_BIT;
    i2cWrite(NINGBO_BASE_Reg, NINGBO_RTC_MISC_5_REG, var);
}

static void ningBoChargerUvsysSet(UINT8 uv)
{
    UINT8 var;

    if (uv > 0x03) {
        return;
    }

// #define NINGBO_FSM_REF_CTRL        0xEF
    i2cRead(NINGBO_BASE_Reg, 0xEF, &var);
    var |= (uv << 4);
    i2cWrite( NINGBO_BASE_Reg, 0xEF, var);
}

/**
 ** OnOff == FALSE : force termination charge
 **/
static void ningBoChargerSwitch(BOOL OnOff)
{
    UINT8 var;

    i2cRead(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_MISC3_REG, &var);
    var &= ~0x0F;
    if (!OnOff) {
        var |= 0x0E; //force termination
    }
    i2cWrite(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_MISC3_REG, var);
}

static void ningBoChargerRestore(void)
{
    ningBoChargerSwitch(0); //charger off
    mdelay(1000);
    ningBoChargerSwitch(1); //charger on
}

static void ningBoChargerStateSet(ningBoForceChgStateE regVal)
{
    UINT8 var = 0;

    if (regVal > CHG_FORCE_MAX) {
        ningBoPrintf("%s:%d", __FILE__, __LINE__);
    }

    i2cRead(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_MISC3_REG, &var);
    var &= ~0xF;
    var |= regVal;
    i2cWrite(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_MISC3_REG, var);
}

static void ningBoPowerUpLogClear(void)
{
    i2cWrite(NINGBO_BASE_Reg, NINGBO_PWRUP_LOG_REG, 0x00);
}

//RTC controller reg
static UINT8 ningBoRtcControlRegGet()
{
    UINT8 var;
    i2cRead(NINGBO_BASE_Reg, NINGBO_RTC_CTRL_REG, &var);
    return var;
}

static void ningBoRtcControlRegSet(UINT8 ctl)
{
    i2cWrite(NINGBO_BASE_Reg, NINGBO_RTC_CTRL_REG, ctl);
}

static UINT32 ningBoCounterRegGet(UINT8 start)
{
    counter32U cnt;
    i2cRead(NINGBO_BASE_Reg, start + 0, &cnt.cnt_8[0]);
    i2cRead(NINGBO_BASE_Reg, start + 1, &cnt.cnt_8[1]);
    i2cRead(NINGBO_BASE_Reg, start + 2, &cnt.cnt_8[2]);
    i2cRead(NINGBO_BASE_Reg, start + 3, &cnt.cnt_8[3]);
    return cnt.cnt_32;
}

static void ningBoCounterRegSet(UINT8 start, UINT32 data)
{
    counter32U cnt;
    cnt.cnt_32 = data;
    i2cWrite(NINGBO_BASE_Reg, start + 0, cnt.cnt_8[0]);
    i2cWrite(NINGBO_BASE_Reg, start + 1, cnt.cnt_8[1]);
    i2cWrite(NINGBO_BASE_Reg, start + 2, cnt.cnt_8[2]);
    i2cWrite(NINGBO_BASE_Reg, start + 3, cnt.cnt_8[3]);
}

//rtc counter
static UINT32 ningBoRtcCounterGet(void)
{
    return ningBoCounterRegGet(NINGBO_RTC_COUNT_REG1);
}

static void clkInit(void)
{
    // done in NingboClkInit
#if 0
    UINT8 var = 0;

    //switch clk to XO
    i2cRead(NINGBO_BASE_Reg, NINGBO_RTC_CONTROL_REG, &var); //BP_0xF1[2]
    var |= NINGBO_RTC_XO_BIT;
    i2cWrite(NINGBO_BASE_Reg, NINGBO_RTC_CONTROL_REG, var);

    i2cRead(NINGBO_BASE_Reg, NINGBO_RTC_CTRL_REG, &var); //BP_0xD0[7]
    var |= NINGBO_RTC_USE_XO_BIT;
    i2cWrite(NINGBO_BASE_Reg, NINGBO_RTC_CTRL_REG, var);

    //set clock mux
    i2cRead( NINGBO_BASE_Reg, NINGBO_CLK_32K_SEL_REG, &var); //BP,A=0xE4,Val=0x47
    var |= NINGBO_CLK_32K_SEL;
    i2cWrite(NINGBO_BASE_Reg, NINGBO_CLK_32K_SEL_REG, var);

    i2cRead(NINGBO_BASE_Reg, NINGBO_CRYSTAL_CAP_SET_REG, &var);
    var &= ~0xE0;
    var |= NINGBO_CRYSTAL_CAP_20PF_BIT;
    i2cWrite(NINGBO_BASE_Reg, NINGBO_CRYSTAL_CAP_SET_REG, var);
#endif
}

static void aditionalWorkAround(void)
{
    // done in Ningbo_Aditional_Workaround
#if 0
    UINT8 var;
    // No SC and RC1 modify
    i2cRead(NINGBO_POWER_Reg, 0x24, &var);
    var |= 0x10;
    i2cWrite(NINGBO_POWER_Reg, 0x24, var);

    // Set BP_0x0D[7]=0b1, only required for DVC enablement
    i2cRead(NINGBO_BASE_Reg, NINGBO_MISC_CFG_REG1, &var);
    i2cWrite(NINGBO_BASE_Reg, NINGBO_MISC_CFG_REG1, var | NINGBO_PWR_HOLD_BIT);

    // CC current limit DVC ramp time to be the slowest, 8ms.
    i2cRead(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_MISC3_REG, &var);
    i2cWrite(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_MISC3_REG, var | (0x3 << 6));

    //set discharge_time to 1s
    i2cRead(NINGBO_BASE_Reg,  NINGBO_RESET_DISCHARGE_REG , &var);
    var &= ~NINGBO_RESET_DISCHARGE_MASK;
    var |= 0x1;
    i2cWrite(NINGBO_BASE_Reg, NINGBO_RESET_DISCHARGE_REG, var);

    /* init specially for charger function. */
    //ccMaxCurrentSet(CC_CHG_CUR_200MA); //CC-charge current @200mA
    ccMaxCurrentSet(CC_CHG_CUR_200MA); //CC-charge current @200mA
    prechargeCurrentSet(PRE_CHG_CUR_150MA); //precharge current @150mA
#endif
    //pm813_get_gpadc_diff_offset();
}

static UINT8 ningBoChargeIDGet(void)
{
    UINT8 regVal = 0;

    i2cRead(NINGBO_BASE_Reg, NINGBO_ID_REG, &regVal);
    return regVal;
}

static void ningBoSetChargerTimer(struct chargerTimer timer)
{
    if (timer.keep) {
        ningBoVoltageCheckTimerSet(timer.volCheck);
        ningBoCurrentCheckTimerSet(timer.curCheck);
        ningBoTrickleTimerSet(timer.trickle);
        ningBoPrechargeTimerSet(timer.precharge);
        ningBoCcCvTimerSet(timer.cccv);
    }
    //ningBoVoltageCheckTimerSet(timer.keep);
}

struct termCurSettingT {
    UINT16 current;
    UINT8 regTerm;
    BOOL regDrvEn;
} termCurSetting[] = {
    {100, 0x00, TRUE}, {50, 0x00, FALSE}, {150, 0x01, TRUE}, {25, 0x01, FALSE},
    {200, 0x10, TRUE}, {75, 0x10, FALSE}, {250, 0x11, TRUE}, {100, 0x11, FALSE},
};

static void ningBoSetTermCurrent(UINT16 current)
{
    UINT8 i = 0;

    for (i = 0; i < sizeof(termCurSetting)/sizeof(struct termCurSettingT); i++) {
        if (termCurSetting[i].current == current) {
            chargerInternalDrvSegmentSet(termCurSetting[i].regDrvEn);
            chargeTermCurrentSet(termCurSetting[i].regTerm);
            break;
        }
    }
}

static void ningBoSetChargerThreshold(struct chargerThreshold threshold)
{
    ningBoSetTermCurrent(threshold.termCur);
}

static void ningBoInit(void)
{
    clkInit();
    aditionalWorkAround();

    // set timer/threshold which is related with charging of pmic
    struct chargerTimer timer = {0x03, 0x03, 0x03, 0x03, 0x03, TRUE};
    ningBoSetChargerTimer(timer);

    struct chargerThreshold threshold = {100};
    ningBoSetChargerThreshold(threshold);
}

static UINT16 ningBobatTempGet(void);
static BOOL ningBoBatteryConnectCheck(void)
{
#if 0
    UINT8 var;
    i2cRead(NINGBO_BASE_Reg, NINGBO_STATUS_REG1, &var);
    return ((var & NINGBO_VBAT_STATUS_BIT) ? TRUE : FALSE);
#else
    return (ningBobatTempGet() != 0xFFF); //Measured result won't be 0xFFF if bat is there.
#endif
}

static BOOL ningBoUsbConnectCheck(void)
{
    UINT8 var;
    i2cRead(NINGBO_BASE_Reg, NINGBO_STATUS_REG1, &var);
    return ((var & NINGBO_VBUS_STATUS_BIT) ? TRUE : FALSE);
}

static BOOL chargerDetected(void)
{
    return ningBoUsbConnectCheck();
}

static enum powerUpTypeE ningBoWakeUpCheck(BOOL batConnectState)
{
    UINT8 regVal;
    enum powerUpTypeE type = PowerUP_Unkown;

    i2cRead(NINGBO_BASE_Reg, NINGBO_PWRUP_LOG_REG, &regVal);

    if (regVal == 0) {
        type = PowerUP_Reset;
    } else if (regVal & NINGBO_IVBUS_DETECT_BIT) {
        type = PowerUP_USB;
    } else if (regVal & NINGBO_BAT_WAKEUP_BIT) {
        if (batConnectState) {
            type = PowerUP_Battery;
        } else {
            /*
            * The external power wakeup signal is connected to battery wakeup signal,
            * such as external 5V power
            */
            type = PowerUP_External;
        }
    } else if (regVal & NINGBO_ONKEY_WAKEUP_BIT) {
        type = PowerUP_ONKEY;

    } else if (regVal & NINGBO_EXTON1_WAKEUP_BIT) {
        type = PowerUP_USB;
    }
    ningBoPrintf("powerUp Value : %x, Type : %x", regVal, type);

    return type;
}

static BOOL onkeyDetected(void)
{
    UINT8 var;
    i2cRead(NINGBO_BASE_Reg, NINGBO_STATUS_REG1, &var);
    return ((var & NINGBO_ONKEY_STATUS_BIT) ? TRUE : FALSE);
}

static BOOL ningBoPowerOnKeyCheck(UINT8 timeOutValue)
{
    UINT8 elapseTime;
    static UINT32 startTime = 0, endTime = 0;
    static BOOL keyDownCounted = FALSE;

    do {
        if (onkeyDetected()) {
            if (!keyDownCounted) {
                startTime = ningBoRtcCounterGet();
                keyDownCounted = TRUE;
                ningBoPrintf("key press: %ld", startTime);
            }
            return FALSE;
        } else {
            endTime = ningBoRtcCounterGet();
            if (keyDownCounted) {
                keyDownCounted = FALSE;
                elapseTime = endTime - startTime;
                ningBoPrintf("key press endTime : %ld, startTime : %ld, elapseTime: %d", endTime, startTime, elapseTime);
            } else {
                return FALSE;
            }
        }
    } while (elapseTime < timeOutValue);

    return TRUE;
}

static void ningBoMeasureEnable(ningBoMeasureE meas_en)
{
    UINT8 tmp;
    i2cRead(NINGBO_GPADC_Reg, NINGBO_MEAS_TO_ENABLE_REG(meas_en), &tmp);
    tmp |= NINGBO_MEAS_TO_ENABLE_BIT(meas_en);
    i2cWrite(NINGBO_GPADC_Reg, NINGBO_MEAS_TO_ENABLE_REG(meas_en), tmp);
}

static void ningBoMeasureDisable(ningBoMeasureE meas_en)
{
    UINT8 tmp;
    i2cRead(NINGBO_GPADC_Reg, NINGBO_MEAS_TO_ENABLE_REG(meas_en), &tmp);
    tmp &= ~(NINGBO_MEAS_TO_ENABLE_BIT(meas_en));
    i2cWrite(NINGBO_GPADC_Reg, NINGBO_MEAS_TO_ENABLE_REG(meas_en), tmp);
}

static void ningBoBiasOutOn(ningBoBiasOutE bias_out)
{
    UINT8 tmp;
    i2cRead(NINGBO_GPADC_Reg, NINGBO_GPADC_BIAS_ENABLE, &tmp);
    tmp |= (1 << bias_out);
    i2cWrite(NINGBO_GPADC_Reg, NINGBO_GPADC_BIAS_ENABLE, tmp);
}

static void ningBoBiasOutOff(ningBoBiasOutE bias_out)
{
    UINT8 tmp;
    i2cRead(NINGBO_GPADC_Reg, NINGBO_GPADC_BIAS_ENABLE, &tmp);
    tmp &= ~(1 << bias_out);
    i2cWrite(NINGBO_GPADC_Reg, NINGBO_GPADC_BIAS_ENABLE, tmp);
}

static void gpadcTrigerTypeEnable(UINT8 type)
{
    UINT8 tmp;
    i2cRead(NINGBO_GPADC_Reg, NINGBO_GPADC_MODE_CONTROL_REG, &tmp);
    i2cWrite(NINGBO_GPADC_Reg, NINGBO_GPADC_MODE_CONTROL_REG, tmp | (type));
}

static void gpadcTrigerTypeDisable(UINT8 type)
{
    UINT8 tmp;
    i2cRead(NINGBO_GPADC_Reg, NINGBO_GPADC_MODE_CONTROL_REG, &tmp);
    i2cWrite(NINGBO_GPADC_Reg, NINGBO_GPADC_MODE_CONTROL_REG, tmp & (~(type)));
}

static UINT32 ningBoMeasureFactorGet(ningBoMeasureE meas_en)
{
    switch (meas_en) {
        case NINGBO_TINT_MEAS_EN:
        case NINGBO_BATID_MEAS_EN:
        case NINGBO_BATTEMP_MEAS_EN:
        case NINGBO_GPADC0_MEAS_EN:
        case NINGBO_GPADC1_MEAS_EN:
            return 1;
        case NINGBO_BUCK1_MEAS_EN:
        case NINGBO_BUCK2_MEAS_EN:
        case NINGBO_AVDD_MEAS_EN:
        case NINGBO_DVDD_MEAS_EN:
            return 2;
        case NINGBO_VCHG_MEAS_EN:
        case NINGBO_VBAT_MEAS_EN:
        case NINGBO_VPWR_MEAS_EN:
        case NINGBO_VSUP_MEAS_EN:
            return 5;
        default:
            return 3;
    }
}

/* Read two registers, the alignment will be done as follows:
   Register 1 - bits 7:0 => 8 LSB bits <7:0> of measurement regVal
   Register 2 - bits 3:0 => 4 MSB bits <11:8> of measurement regVal
*/
static UINT16 ningBoVoltMeasure(UINT8 meaReg)
{
    UINT8 reg_value[2];

    /* Read two registers, the alignment will be done as follows:
    Register 1 - bits 7:0 => 8 MSB bits <11:4> of measurement value
    Register 2 - bits 3:0 => 4 LSB bits <3:0> of measurement value
    */
    i2cRead(NINGBO_GPADC_Reg, meaReg + 0, &reg_value[0]);
    i2cRead(NINGBO_GPADC_Reg, meaReg + 1, &reg_value[1]);

    return ((reg_value[0] << 4) | (reg_value[1] & 0x0F));
}

static UINT16 _ningBoBatInstantVoltGet(BOOL usbStatus)
{
    UINT16 measVal;

    ningBoMeasureEnable(NINGBO_VBAT_MEAS_EN);

    /*trigger meas, use non-stop instead of single-trigger, 
    since the AVG value can be correct only after the first four times of read of single-trigger. */
    gpadcTrigerTypeEnable(NINGBO_NON_STOP_BIT | NINGBO_GPADC_EN_BIT);

    measVal = ningBoVoltMeasure(NINGBO_VINLDO_AVE_REG);
    //Voltage=hex2dec(CODE)/4096*1.3*128/129 (unit: V)(CODE is the adc output, 12bit)
    measVal = VOLT_CONVERT_12BIT_MV(measVal) * ningBoMeasureFactorGet(NINGBO_VBAT_MEAS_EN); 

    gpadcTrigerTypeDisable(NINGBO_NON_STOP_BIT | NINGBO_GPADC_EN_BIT);
    ningBoMeasureDisable(NINGBO_VBAT_MEAS_EN);

    return measVal;
}

static UINT16 ningBoBatInstantVoltGet(BOOL usbStatus)
{
    UINT16 measVal = _ningBoBatInstantVoltGet(usbStatus);

#if 0
    if(chargerDetected() && ningBoChargerErrorGet()) {
        ningBoChargerRestore();
    }
#endif

    return measVal;
}

static UINT16 ningBobatTempGet(void)
{
    UINT16 measVal;
    UINT8 tmp;

    //enable BATTEMP MEAS
    ningBoBiasOutOn(NINGBO_GPADC3_BIAS_OUT);

    i2cRead(NINGBO_GPADC_Reg, NINGBO_GPADC_BIAS_2_REG, &tmp);
    tmp &= ~(0xF << NINGBO_GPADC_3_BIAS_SHIFT);
    tmp |= 0x1 << NINGBO_GPADC_3_BIAS_SHIFT; //set 6uA
    i2cWrite(NINGBO_GPADC_Reg, NINGBO_GPADC_BIAS_2_REG, tmp);

    ningBoMeasureEnable(NINGBO_BATTEMP_MEAS_EN);

    //trigger meas
    gpadcTrigerTypeEnable(NINGBO_GPADC_SW_TRIG_BIT);

    //get BATTEMP meas
    measVal = ningBoVoltMeasure(NINGBO_GPADC_MEAS_VBATTEMP_1_REG);

    //Voltage=hex2dec(CODE)/4096*1.3*128/129 (unit: V)(CODE is the adc output, 12bit)
    if (measVal != 0xFFF) {
        measVal = VOLT_CONVERT_12BIT_MV(measVal) * ningBoMeasureFactorGet(NINGBO_BATTEMP_MEAS_EN) / 6; //with 6uA 
    }

    //disable BATTEMP MEAS
    ningBoBiasOutOff(NINGBO_GPADC3_BIAS_OUT);
    ningBoMeasureDisable(NINGBO_BATTEMP_MEAS_EN);

    //ningBoPrintf("batTemp : %d", measVal);
    return measVal;
}

static UINT32 ningBoBatSleepVoltGet(void)
{
    UINT32 mVolt;

    mVolt = ningBoVoltMeasure(NINGBO_VINLDO_SLP_REG);
    //Voltage=hex2dec(CODE)/4096*1.3*128/129 (unit: V)(CODE is the adc output, 12bit)
    mVolt = VOLT_CONVERT_12BIT_MV(mVolt) * ningBoMeasureFactorGet(NINGBO_VBAT_MEAS_EN);

    return mVolt;
}

static UINT32 ningBoUsbVoltGet(void)
{
    UINT32 mVolt;

    //enable Vbus MEAS
    ningBoMeasureEnable(NINGBO_VCHG_MEAS_EN);

    //trigger meas
    gpadcTrigerTypeEnable(NINGBO_GPADC_SW_TRIG_BIT);

    //get Vbus meas
    mVolt = ningBoVoltMeasure(NINGBO_GPADC_MEAS_VCHG_1_REG);

    //Voltage=hex2dec(CODE)/4096*1.3*128/129 (unit: V)(CODE is the adc output, 12bit)
    //got real regVal
    if (mVolt != 0xFFF) {
        mVolt = VOLT_CONVERT_12BIT_MV(mVolt) * ningBoMeasureFactorGet(NINGBO_VCHG_MEAS_EN);
    }

    //disable Vbus MEAS
    ningBoMeasureDisable(NINGBO_VCHG_MEAS_EN);

    return mVolt;
}

static void ningBoSystemPowerOff(void)
{
    UINT8 tmp;
    i2cRead(NINGBO_BASE_Reg, NINGBO_MISC_CFG_REG1, &tmp);
    i2cWrite(NINGBO_BASE_Reg, NINGBO_MISC_CFG_REG1, tmp | NINGBO_SW_PDOWN_BIT);
}

static UINT8 ningBoFSMGet(void)
{
    UINT8 var;

    i2cRead(NINGBO_BASE_Reg, NINGBO_READONLY_DATA_4_REG, &var);
    var = var >> NINGBO_CHG_FSM_SHIFT;
    ningBoPrintf("get fsm value : %x", var);
    return var;
}

static BOOL ningBoChargerFull(void)
{
    UINT8 var = ningBoFSMGet();
    return ((var == NINGBO_CHG_FSM_TERM) || (var == NINGBO_CHG_FSM_FAULT));
}

static BOOL ningBoChargerTerm(void)
{
    UINT8 var = ningBoFSMGet();
    return (var == NINGBO_CHG_FSM_TERM);
}

static BOOL ningBoChargerFault(void)
{
    UINT8 var = ningBoFSMGet();
    return (var == NINGBO_CHG_FSM_FAULT);
}

static BOOL ningBoChargerCC(void)
{
    UINT8 var = ningBoFSMGet();
    return (var == NINGBO_CHG_FSM_CC);
}

static UINT8 ningBoForceFSMGet(void)
{
    UINT8 var = 0;

    i2cRead(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_MISC3_REG, &var);
    return (var & 0xF);
}

static void ningBoForceFSMSet(UINT8 state)
{
    UINT8 var;

    i2cRead(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_MISC3_REG, &var);
    ningBoPrintf("force fsm state : %x", state);
    i2cWrite(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_MISC3_REG, (var & 0xF0) | (state & 0x0F));
}

static void ningBoVbusUVSet(BOOL seting)
{
    UINT8 var;

    i2cRead(NINGBO_BASE_Reg, NINGBO_READWRITE_DMY_4_REG, &var);
    if (seting) {
        var |= NINGBO_DIS_VBUS_UV_BIT;
    } else {
        var &= ~NINGBO_DIS_VBUS_UV_BIT;
    }
    i2cWrite(NINGBO_BASE_Reg, NINGBO_READWRITE_DMY_4_REG, var);
}

static ningBoCcChgCurrentE ningBoCurMapGet(UINT16 cur)
{
    UINT8 i;
    if (cur < 100) {
        ningBoPrintf("%s cc current : 100mV", __FUNCTION__);
        return CC_CHG_CUR_100MA;
    }
    for (i = 0; i < sizeof(currentMap); i++) {
        if (currentMap[i] == cur) {
            break;
        }
    }
//    ningBoPrintf("%s cc current : %dmV, map index : %d", __FUNCTION__, cur, i);
    return (ningBoCcChgCurrentE)i;
}

static void ningBoFinalCC(UINT16 cur)
{
    ccMaxCurrentSet(ningBoCurMapGet(cur-100));
}

static BOOL ningBoSetMPP(UINT16 limit)
{
    UINT16 cur;
    BOOL uvloTrig = FALSE;

    if (CHG_FORCE_TERM == ningBoForceFSMGet()) {
        ningBoPrintf("quit MPPT due to forced termination");
        return FALSE;
    }

    ningBoPrintf("MPPT startTime  %u", ningBoRtcCounterGet());
    i2cWrite(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_MISC3_REG, 0xC9); //force check
    i2cWrite(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_MISC3_REG, 0xCE); //force termination
    ningBoVbusUVSet(TRUE);
    i2cWrite(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_MISC3_REG, 0xCC); //force cc

    if (limit > 1000) {
        limit = 1000;
    }

    //from 100mA on, 50mA a step, ends with 1000mA
    for (cur = 100; cur <= limit; cur += 50) {
        ccMaxCurrentSet(ningBoCurMapGet(cur));
        mdelay(500*10);

        //charger removed
        if (!ningBoUsbConnectCheck()) {
            ningBoPrintf("MPPT aborts due to charger removed!!");
            ccMaxCurrentSet(CC_CHG_CUR_200MA);
            i2cWrite(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_MISC3_REG, 0xCE); //force termination
            ningBoVbusUVSet(0); //need to restore
            i2cWrite(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_MISC3_REG, 0xC0); //back normal
            return FALSE;
        }

        //Find the first CC current that makes Vcharger UVLO happens.
        if (ningBoUsbVoltGet() <= 4600) {
            ningBoFinalCC(cur);
            uvloTrig = TRUE;
            break;
        }
    }

    i2cWrite(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_MISC3_REG, 0xCE); //force termination
    ningBoVbusUVSet(0); //need to restore
    i2cWrite(NINGBO_BASE_Reg, NINGBO_CHG_CTRL_MISC3_REG, 0xC0); //back normal

    ningBoPrintf("max cc current setting is %dmA, ends: %u", cur - ((uvloTrig) ? 100 : 50), ningBoRtcCounterGet());
    return TRUE;
}

//chargerTable and dischargerTable indicate relation of ovc and soc
//ovc is measured without charger
static UINT16 chargerTable[100]={
    /* 0  1    2    3    4    5    6    7    8    9 */
    3206,3684,3734,3752,3757,3761,3765,3770,3775,3779,  /*0*/
    3784,3792,3799,3806,3812,3817,3822,3827,3833,3837,  /*1*/
    3842,3845,3848,3850,3853,3855,3856,3857,3858,3860,  /*2*/
    3862,3864,3865,3867,3870,3873,3877,3881,3884,3887,  /*3*/
    3890,3895,3900,3905,3911,3916,3922,3927,3932,3938,  /*4*/
    3945,3951,3957,3963,3970,3978,3984,3991,3998,4005,  /*5*/
    4012,4019,4026,4031,4037,4045,4051,4057,4063,4070,  /*6*/
    4080,4091,4105,4119,4130,4138,4146,4154,4163,4172,  /*7*/
    4182,4193,4204,4213,4222,4233,4244,4256,4268,4280,  /*8*/
    4291,4302,4315,4328,4342,4352,4352,4352,4352,4352   /*9*/
};

static UINT16 dischargerTable[100]={
    /* 9   8    7    6    5    4    3    2    1    0 */
    3003,3384,3464,3520,3555,3577,3591,3600,3605,3609,   /*9*/
    3615,3623,3630,3638,3645,3650,3657,3664,3669,3674,   /*8*/
    3677,3682,3686,3689,3691,3694,3699,3702,3706,3708,   /*7*/
    3710,3714,3718,3723,3726,3729,3733,3736,3739,3743,   /*6*/
    3747,3751,3754,3758,3763,3768,3771,3775,3781,3787,   /*5*/
    3794,3800,3806,3812,3817,3824,3831,3836,3842,3850,   /*4*/
    3858,3866,3873,3879,3887,3896,3904,3913,3921,3930,   /*3*/
    3939,3950,3963,3974,3984,3992,4000,4010,4021,4032,   /*2*/
    4042,4051,4061,4071,4080,4089,4098,4110,4121,4133,   /*1*/
    4145,4156,4165,4176,4189,4203,4218,4233,4252,4315    /*0*/
};

static struct batStableT batStable = {0};

static UINT8 ningBoBatSocFromOcv(UINT16 ocv, UINT16 *batTable)
{
    INT8 i;
    UINT8 count = 100, soc = 0;

    if (ocv < batTable[0]) {
        soc = 0;
        return soc;
    }

    for (i = count-1; i >= 0; i--) {
        if (ocv >= batTable[i]) {
            soc = i;
            break;
        }
    }
    return soc;
}

static UINT8 ningBoBatLevelToPrecent(UINT16 batteryLevel)
{
    UINT8 percent = ningBoBatSocFromOcv(batteryLevel, (UINT16*)&dischargerTable); 

    if (percent <= 0) {
        return 0;
    } else if (percent >= 100) {
        return 100;
    } else {
        return percent;
    }
}

// measure battery volt without charger
static UINT16 ningBoBatInstantVoltOvcGet(BOOL usbStatus)
{
    ningBoForceFSMSet(FSM_FORCE_CHECK);
    UINT16 measVal = _ningBoBatInstantVoltGet(usbStatus);
    ningBoForceFSMSet(FSM_NORMAL);
    return measVal;
}

static UINT16 ningBoBatLevelGet(UINT8 *pPercent)
{
    // calculate soc according to relation of soc and ovc,
    // so measure battery volt without charger
    UINT16 batteryLevel = ningBoBatInstantVoltOvcGet(TRUE);

    if ((batteryLevel != PMIC_BAD_VALUE) && (pPercent != NULL)) {
        *pPercent = ningBoBatLevelToPrecent(batteryLevel);
    }

    return batteryLevel;
}

static UINT16 ningBoStableBatteryLevelGet(UINT8 *pPercent)
{
    UINT8 bcl = 0, i=0, avgPercent = 0;
    INT16 batLevelTemp1 = 0, batLevelTemp2 = 0;
    UINT16 batLevel = ningBoBatLevelGet(&bcl);

    if (batLevel == PMIC_BAD_VALUE) {
        ningBoPrintf("PMIC_BAD_VALUE");
        return PMIC_BAD_VALUE;
    }

    if (batLevel < 2000) {
        ningBoPrintf("PMIC_BAD_VALUE too small");
        return PMIC_BAD_VALUE;
    }

    if (batStable.nb == PM_AVERAGE_BATTERY_NB) {
        if (batStable.avg > batLevel) {
            if ((batStable.avg - batLevel) > PM_FILTRATE_BATTERY_STEP) {
                ningBoPrintf("too small %dmv",batLevel);
            }
        }
    }

    batStable.sum -= batStable.levels[batStable.idx];
    batStable.sum += batLevel;
    batStable.levels[batStable.idx] = batLevel;
    if (batStable.nb < PM_AVERAGE_BATTERY_NB) {
        batStable.nb++;
    }
    batStable.idx++;
    if (batStable.idx >= PM_AVERAGE_BATTERY_NB) {
        batStable.idx = 0;
    }

    if (batStable.nb > 10) {
        batLevelTemp1 = batStable.levels[0];
        for (i = 0; i < batStable.nb; i++) {
          if (batLevelTemp1 > batStable.levels[i]) {
            batLevelTemp1 = batStable.levels[i];
          }
        }
        batLevelTemp2 = batStable.levels[0];
        for (i = 0; i < batStable.nb; i++) {
          if (batLevelTemp2 < batStable.levels[i]) {
            batLevelTemp2 = batStable.levels[i];
          }
        }
        batLevelTemp1 += batLevelTemp2;
        batStable.avg = (batStable.sum - batLevelTemp1 ) / (batStable.nb - 2);

    } else {
        batStable.avg = batStable.sum / batStable.nb;
    }
    batStable.instant = batLevel;
    if ((((INT32)batStable.stable - (INT32)batStable.avg) >= PM_HYSTERESIS_BATTERY_STEP) ||
        (((INT32)batStable.avg - (INT32)batStable.stable) >= PM_HYSTERESIS_BATTERY_STEP)) {
        batStable.stable = batStable.avg;
    }

    avgPercent = ningBoBatLevelToPrecent(batStable.avg);
    if ((avgPercent <= PM_HYSTERESIS_BATTERY_PERCENT_EDGE + 13) ||
        (avgPercent >= (100-PM_HYSTERESIS_BATTERY_PERCENT_EDGE))) {
        batStable.stable = batStable.avg;
    }

    // calculate %, print and return value...
    batStable.precent = ningBoBatLevelToPrecent(batStable.stable);
    if (pPercent != NULL) {
        *pPercent = batStable.precent;
    }

    ningBoPrintf("instant: %dmV, %d%%; mean: %dmV, %d%%; stable: %dmV, %d%%",
                  batLevel, bcl, batStable.avg, avgPercent, batStable.stable, batStable.precent);

    return batStable.stable;
}

static BOOL ningBoGetChargeStatus(void)
{
    UINT8 var;
    i2cRead(NINGBO_BASE_Reg, NINGBO_READONLY_DATA_2_REG, &var);
    ningBoPrintf("vbus status : %x", var);
    return ((var & (NINGBO_RONLY_DATA_VBUS_UV)) ? TRUE : FALSE);
}

static float ningBoGPADC1_0DiffMeas(void)
{
    UINT32 meas_val;
    float diff_val;

	//trigger meas
	//PM812_GPADC_SW_TRIG();
	gpadcTrigerTypeEnable(NINGBO_GPADC_SW_TRIG_BIT);

	//get Vgpadc0 meas
    //meas_val = PM812_GPADC_READ_VOL_MEAS(NINGBO_VGPADC0);
    meas_val = ningBoVoltMeasure(NINGBO_VGPADC0);

//    diff_val = VOLT_CONVERT_DIFF_12BIT_MV(meas_val-0x800)*Ningbo_Get_Meas_Factor(NINGBO_GPADC0_MEAS_EN);
    diff_val = ((float)meas_val-0x800)*0.63f;

    return diff_val;
}

// currentDirect is true when charge; currentDirect is false when discharge
static BOOL currentDirect = TRUE;

static void ningBoSetCurrentDirect(BOOL direct)
{
    currentDirect = direct;
}

static BOOL ningBoGetCurrentDirect(void)
{
    return currentDirect;
}

#define CYCLE_TIMES         10 //get average value of 10 times measurement
#define RESISTOR_ICHARGE    20 //value for the resistor put between GPADC0/1, in "mOhm"
static UINT32 ningBoGetChargeCurrent(void)
{
    UINT32 i, j = CYCLE_TIMES;
    float tmp, Icharge = 0;

	//enable GPADC1 MEAS
    //Ningbo_MEAS_ENABLE(NINGBO_GPADC0_MEAS_EN);
    ningBoMeasureEnable(NINGBO_GPADC0_MEAS_EN);

    for (i = 0; i < CYCLE_TIMES; i++) {
        tmp = ningBoGPADC1_0DiffMeas();
        if (tmp != 0)
            Icharge += tmp;
        else
            j--;
    }

	//disable GPADC1 MEAS
    //Ningbo_MEAS_DISABLE(NINGBO_GPADC0_MEAS_EN);
    ningBoMeasureDisable(NINGBO_GPADC0_MEAS_EN);

    //Icharge = Icharge/j-gpadc_diff_offset;
    Icharge = Icharge / j;

    if (Icharge > 0) {
        ningBoSetCurrentDirect(TRUE);
        return (UINT32)(Icharge*50); /* 1000/20 --> 50, averageVolt (mV), /20mOhm ->1A, *1000 -> mA */
    } else {
        ningBoSetCurrentDirect(FALSE);
        return (UINT32)(-Icharge*50); /* 1000/20 --> 50, averageVolt (mV), /20mOhm ->1A, *1000 -> mA */
    }
}

static void ningBoCloseCharge(void)
{
    ningBoForceFSMSet(FSM_FORCE_TERMINATION);
}

static void ningBoOpenCharge(void)
{
    ningBoForceFSMSet(FSM_NORMAL);
}

static UINT16 _ningBoGPADCGet(ningBoMeasureE meas_en, UINT8 meaReg)
{
    UINT16 measVal;

    ningBoMeasureEnable(meas_en);

    /*trigger meas, use non-stop instead of single-trigger,
    since the AVG value can be correct only after the first four times of read of single-trigger. */
    gpadcTrigerTypeEnable(NINGBO_NON_STOP_BIT | NINGBO_GPADC_EN_BIT);

    measVal = ningBoVoltMeasure(NINGBO_VINLDO_AVE_REG);
    if (meas_en == NINGBO_TINT_MEAS_EN) {
        measVal = TEMP_CONVERT_16BIT_MV(measVal) * ningBoMeasureFactorGet(meas_en);
    } else {
        //Voltage=hex2dec(CODE)/4096*1.3*128/129 (unit: V)(CODE is the adc output, 12bit)
        measVal = VOLT_CONVERT_12BIT_MV(measVal) * ningBoMeasureFactorGet(meas_en);
    }

    gpadcTrigerTypeDisable(NINGBO_NON_STOP_BIT | NINGBO_GPADC_EN_BIT);
    ningBoMeasureDisable(meas_en);

    return measVal;
}

static UINT16 ningBoTintGet(BOOL usbStatus)
{
    return (_ningBoGPADCGet(NINGBO_TINT_MEAS_EN, NINGBO_GPADC_MEAS_TINT_REG));
}

static UINT16 ningBoVpwrGet(BOOL usbStatus)
{
    return (_ningBoGPADCGet(NINGBO_VPWR_MEAS_EN, NINGBO_GPADC_MEAS_VPWR_REG));
}

static BOOL isHighTemperature(void)
{
    UINT16 vbat = ningBoBatInstantVoltGet(TRUE);
    UINT32 curr = ningBoGetChargeCurrent();
    BOOL direct = ningBoGetCurrentDirect();
    UINT16 tint = ningBoTintGet(TRUE);
    UINT16 vpwr = ningBoVpwrGet(TRUE);
    UINT8 fsm = ningBoFSMGet();
    if((tint > 35) &&
       ((fsm == FSM_CC_CHG) || (fsm == FSM_CV_CHG) || (fsm == FSM_PRE_CHG)) &&
       ((vpwr < vbat + 15) && (vpwr > vbat - 15)) &&
       (!direct || (direct && (curr < 50)))) {
        ningBoPrintf("high temperature is detected, tint : %x, fsm : %x, vpwr %x, vbat : %x, curr %x, direct : %x",
            tint, fsm, vpwr, vbat, curr, direct);
        return TRUE;
    } else {
        return FALSE;
    }
}

static void ningBoHandleHighTemperature(void)
{
    ningBoCloseCharge();
    ningBoOpenCharge();
}

static void ningBoHandleChargerAbnormal(void)
{
    if (isHighTemperature()) {
        ningBoHandleHighTemperature();
    }
    // TODO : other type of abnormal
}

static struct chargeManagerT ningBoChargeManager = {
    .family = NINGBO,
    .id = PMIC_813,
    .subId = PMIC_813_A3,
    .chargeICIDGet = ningBoChargeIDGet,
    .init = ningBoInit,
    .batteryConnectCheck = ningBoBatteryConnectCheck,
    .usbConnectCheck = ningBoUsbConnectCheck,
    .wakeUpCheck = ningBoWakeUpCheck,
    .powerOnKeyCheck = ningBoPowerOnKeyCheck,
    .batInstantVoltGet = ningBoBatInstantVoltGet,
    .batStableVoltGet = ningBoStableBatteryLevelGet,
    .systemPowerOff = ningBoSystemPowerOff,
    .chargerFull = ningBoChargerFull,
    .chargerCC = ningBoChargerCC,
    .setMPP = ningBoSetMPP,
    .getChargeStatus = ningBoGetChargeStatus,
    .getChargeCurrent = ningBoGetChargeCurrent,
    .closeCharge = ningBoCloseCharge,
    .openCharge = ningBoOpenCharge,
    .handleChargerAbnormal = ningBoHandleChargerAbnormal,
};

void ningBoICRegister(void)
{
    chargeManager[ningBoChargeManager.family] = ningBoChargeManager;
}
