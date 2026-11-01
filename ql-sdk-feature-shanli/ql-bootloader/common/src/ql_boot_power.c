/*================================================================
  Copyright (c) 2022, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/
#include "quec_cust_startup_feature.h"

#ifdef QUECTEL_OPEN_CPU

#include "ql_boot_power.h"
#include "ningbo.h"
#include "guilin.h"
#include "pmic.h"
#include "dm_charge.h"
//#include "dm_ningbo.h"

#ifndef true
#define false	0
#define true	1
#endif

#ifdef QUEC_POWER_LOG_ENABLE
	#define power_dbg_log(fmt, args...)
#else
	#define power_dbg_log(fmt, args...)	uart_printf("[%s][%d]"fmt, __FUNCTION__, __LINE__, ##args)
#endif

//somer.zhang-2020/05/12-add pwrkey check
#ifdef QUEC_BOOT_PWRKEY_CHECK
void Quec_pwrkey_check(void)
{
    unsigned int i, j=0;
	char reg = 0;
	unsigned char power_up_flag = 0xff;
    //uart_printf("[Quec][PWK]OnkeyPowerOnCheck\r\n");
    /* Set 15s for power-down-by-long-ONKEY-pressing period, this register is 
    restricted to change only one bit each time. */
    PMIC_WRITE_REG_BASE(0xE3, 0xC0);
    PMIC_WRITE_REG_BASE(0xE3, 0xE0);
    PMIC_WRITE_REG_BASE(0xE3, 0xF0);
    *(volatile unsigned long*)APBTIMER0_EN_REG = 0x1; //enable Timer0_0 (in free run)

	reg = PMIC_READ_REG_BASE(0xEB);
	if( 0 == (reg & 0x80)) 
	{
		power_up_flag = 0x00; // cold power on
		uart_printf("Cold power on\n"); 
	}
	else 
	{
		power_up_flag = 0x01; // hot  power on
		uart_printf("Hot power on\n"); 
	}


	if(power_up_flag == 0x00){	//cold power on
	    for(i=0;i<2;i++) // 500ms for powerkey  check
	    {
	        if (!Quec_PMIC_GET_PWEKY_STATUS())
	        {
	            uart_printf("short press, do poweroff!!\r\n");
		     	DelayInMilliSecond(100);
	            PMIC_PowerDown(); //Power down if ONKEY is not pressed long enough.
	        }
	        DelayInMilliSecond(100);
	    }
		reg |= 0x80;
		PMIC_WRITE_REG_BASE(0xEB, reg);
	    *(volatile unsigned long*)APBTIMER0_EN_REG = 0x0; //stop Timer0_0 
	}
}
#endif

//for CHARER bind on USB_VBUS
BOOL PM812_VBUS_IS_AVAILABLE(void)
{
	if (PMIC_IS_PM812())
	{
    	//check whether VBUS is availabe (VCHG_LOW_TH < vbus.vol < VCHG_UPP_TH)
    	return ((PMIC_READ_REG_BASE(PM812_STATUS_1_REG) & PM812_VBUS_STATUS_BIT) ? TRUE : FALSE);
	}
#ifdef CRANE_MCU_DONGLE
	else if (PMIC_IS_PM802()||PMIC_IS_PM803())
	{
		#if(0)
			uart_printf("ERR . PM802 means no charge function!\r\n");
			return FALSE;
		#else
			/*PMIC802/PMIC803 do not support charger(so VBUS detectio is impossible),
			we check PMUap offset0x7C ,bit15 to detect VBUS state
			*/
			uart_printf("DBG====PMIC is PM802/PM803\n");
			return (((*(volatile unsigned long*)0xd428287c >>15)&0x1) ? TRUE : FALSE);
		#endif
	}
#endif
	else
	{
	    if (PMIC_IS_PM813_A3())
            return ((PMIC_READ_REG_BASE(NINGBO_READONLY_DATA_2_REG) & (NINGBO_RONLY_DATA_CHG_OK)) ? TRUE : FALSE);
        else
            return ((PMIC_READ_REG_BASE(NINGBO_STATUS_REG1) & (NINGBO_VBUS_STATUS_BIT | NINGBO_VBUS_OVP_BIT | NINGBO_VBUS_UVLO_BIT)) ? TRUE : FALSE);
	}
}

#ifdef CRANE_MCU_DONGLE
#define 	GUILIN_PWRUP_LOG_REG			0x10
#endif
#define     GUILIN_POWERDOWN_LOG_REG		0xE5
#define     GUILIN_POWERDOWN_LOG_REG2		0xE6
#define 	PM812_POWERDOWN_LOG_REG2 		0xe6
#define 	PM812_POWERUP_LOG_REG			0x10

static UINT8 PM812_GET_POWER_DOWN_LOG()
{
    if (PMIC_IS_PM812())
     return PMIC_READ_REG_BASE(PM812_POWERDOWN_LOG_REG);
#ifdef CRANE_MCU_DONGLE
 else if (PMIC_IS_PM802())
     return PMIC_READ_REG_BASE(GUILIN_POWERDOWN_LOG_REG);
#endif
    else
        return PMIC_READ_REG_BASE(NINGBO_POWERDOWN_LOG_REG);
}

static UINT8 PM812_GET_POWER_DOWN_LOG2()
{
    if (PMIC_IS_PM812())
     return PMIC_READ_REG_BASE(PM812_POWERDOWN_LOG_REG2);
#ifdef CRANE_MCU_DONGLE
 else if (PMIC_IS_PM802())
  return PMIC_READ_REG_BASE(GUILIN_POWERDOWN_LOG_REG2);
#endif
    else
        return PMIC_READ_REG_BASE(NINGBO_POWERDOWN_LOG_REG2);
}

static void PM812_CLR_POWER_UP_LOG(UINT8 tmp)
{
    if (PMIC_IS_PM812())
	    PMIC_WRITE_REG_BASE(PM812_POWERUP_LOG_REG,tmp);
#ifdef CRANE_MCU_DONGLE
	else if (PMIC_IS_PM802())
    	PMIC_WRITE_REG_BASE(GUILIN_PWRUP_LOG_REG,tmp);
#endif
	else
        PMIC_WRITE_REG_BASE(NINGBO_PWRUP_LOG_REG,tmp);
}


static void PM812_CLR_POWER_DOWN_LOG(UINT8 tmp)
{
    if (PMIC_IS_PM812())
    	PMIC_WRITE_REG_BASE(PM812_POWERDOWN_LOG_REG,tmp);
#ifdef CRANE_MCU_DONGLE
	else if (PMIC_IS_PM802())
    	PMIC_WRITE_REG_BASE(GUILIN_POWERDOWN_LOG_REG,tmp);
#endif
    else
        PMIC_WRITE_REG_BASE(NINGBO_POWERDOWN_LOG_REG,tmp);
}

static void PM812_CLR_POWER_DOWN_LOG2(UINT8 tmp)
{
    if (PMIC_IS_PM812())
    	PMIC_WRITE_REG_BASE(PM812_POWERDOWN_LOG_REG2,tmp);
#ifdef CRANE_MCU_DONGLE
	else if (PMIC_IS_PM802())
		PMIC_WRITE_REG_BASE(GUILIN_POWERDOWN_LOG_REG2,tmp);
#endif
    else
        PMIC_WRITE_REG_BASE(NINGBO_POWERDOWN_LOG_REG2,tmp);
}

UINT8 power_up_reason;
UINT8 power_down_reason;
UINT8 power_down_reason2;
int ql_get_powerup_reason(void)
{
	unsigned char hot_power_flag = 0x0;
	//power up log & power down log
	power_up_reason = PMIC_GET_POWER_UP_LOG();
	PM812_CLR_POWER_UP_LOG(power_up_reason);

	//forrest.liu@20210304 add for PM803 0xe5/0xe6 registers are clear after read
	if(PMIC_IS_PM803())
	{
		unsigned char *reg;
		
		reg = asr_property_get("power_down_reg");
		
		power_down_reason  = reg[2];
		power_down_reason2 = reg[3];
		hot_power_flag = reg[5];

		#if(1) // ref@preboot pmic.c pmic_setup()
			if(power_down_reason == 0xFF)
			{
				power_down_reason = 0x0;
			}
			if(power_down_reason2 == 0xFF)
			{
				power_down_reason2 = 0x0;
			}
			if(hot_power_flag == 0xFF)
			{
				hot_power_flag = 0x0;
			}

		#endif
	}
	else
	{
		power_down_reason = PM812_GET_POWER_DOWN_LOG();
		PM812_CLR_POWER_DOWN_LOG(power_down_reason);
		power_down_reason2 = PM812_GET_POWER_DOWN_LOG2();
		PM812_CLR_POWER_DOWN_LOG2(power_down_reason2);
	}

/*
	uart_printf("power_up_reason:0x%02X\r\n",power_up_reason);
	uart_printf("power_down_reason:0x%02X\r\n",power_down_reason);
	uart_printf("power_down_reason2:0x%02X\r\n",power_down_reason2);
*/
	if (power_up_reason & (1<<1)) //0x02
	{
		if((0x00==power_down_reason) && (0x00==power_down_reason2)  && (0x80 == (hot_power_flag & 0x80))) 
		{
			return QL_POWERUP_RESET;
		}
		else {
			return QL_POWERUP_PWRKEY;
		}
	}
	if (power_up_reason & (1<<6)) //0x40 
	{
		if((0x04==power_down_reason)&&(0x00==power_down_reason2))//forrest.liu@20201201 modify from R01_b04 newest change 
		{
			if(power_up_reason & (1<<5))
			{
				return QL_POWERUP_RESET;//ql_power_reset
			}
			#if 1
			else
			{
				return QL_POWERUP_VBUS;
			}
			#endif
		}
		#if 1
		else if((0x00==power_down_reason)&&(0x00==power_down_reason2))
		{
			return QL_POWERUP_RESET;//reset by hand
		}
		#endif
		else
		{
			return QL_POWERUP_VBUS;
		}
	}
	//forrest.liu@20210304 add for PM803 0xe5/0xe6 registers are clear after read
	if(PMIC_IS_PM803())
	{
		if (power_up_reason & (1<<4))//forrest.liu@20210128 add for power_up_reason is not correct when run ql_power_reset() 
		{
			if((0x04==power_down_reason) && (0x00==power_down_reason2))
			{
				return QL_POWERUP_RESET;//ql_power_reset
			}
			else if((0x00==power_down_reason) && (0x00==power_down_reason2))
			{
				return QL_POWERUP_RESET;//reset by hand
			}
		}
		if (power_up_reason & (1<<2)) //0x04
		{
			return QL_POWERUP_RTC;
		}
		if (power_up_reason & (1<<3)) //0x8
		{
			return QL_POWERUP_VBAT;
		}
	}
	else
	{
		if (power_up_reason & (1<<5))//forrest.liu@20210128 add for power_up_reason is not correct when run ql_power_reset() 
		{
			if((0x04==power_down_reason) && (0x00==power_down_reason2))
			{
				return QL_POWERUP_RESET;//ql_power_reset
			}
			else if((0x00==power_down_reason) && (0x00==power_down_reason2))
			{
				return QL_POWERUP_RESET;//reset by hand
			}
		}
		if (power_up_reason & (1<<3)) //0x08
		{
			return QL_POWERUP_VBAT;
		}
		if (power_up_reason & (1<<4)) //0x10
		{
			return QL_POWERUP_RTC;
		}
		if (power_up_reason & (1<<5)) //0x20
		{
			return QL_POWERUP_FAULT;
		}
	}

	return QL_POWERUP_NO_REASON;
}

void delay_s(int s)
{
	int i;
	for(i=0;i<s*20;i++)
	{
		mdelay(1000);
	}
}

/**************** USB charge API ********************/
extern struct chargeManagerT chargeManager[8];
unsigned char ql_get_vbus_state(void)
{
	return PM812_VBUS_IS_AVAILABLE();
}

static void quec_adc_read_bat(unsigned short * vbat)
{
    unsigned short meas_val;
    unsigned short vol_GPADC, vol_cali;
    unsigned short vbat_base;

    meas_val = guilin_read_volt_meas_val(GUILIN_VINLDO_AVE_REG);   // Read the VSYS(Vbat)
    
    vol_GPADC = (unsigned short) ((meas_val * 6450) / 4096);

    vbat_base = 3700;
    if (vol_GPADC >= vbat_base)
    {
        vol_cali = (unsigned short)(3700 + (vol_GPADC-vbat_base));
    }
    else
    {
        vol_cali = (unsigned short)(3700 - (vbat_base-vol_GPADC));
    }

    *vbat = vol_cali;
}

/**
 * somer.zhang-2020/06/10:get battery voltage without charging(it is really battery voltage when battery pause charging)
 * //1 -- on, 0 -- off
 **/
#if 0
unsigned short ql_get_battery_vol(void)
{
	unsigned char index = -1;
	unsigned char usb_connect_state = 0;
	
	index = quec_charge_init();
	usb_connect_state = ql_get_vbus_state();
	return chargeManager[index].batInstantVoltGet(usb_connect_state);
}
#elif 0
unsigned short ql_get_battery_vol(void)
{
	return chargeManager[index].batInstantVoltGet(usb_connect_state);
}
#else
unsigned short ql_get_battery_vol(void)
{
	if(PMIC_IS_PM813())//EC100Y
	{
		return (unsigned short)pm813_get_battery_voltage_withoutCharger();
	}
	else if(PMIC_IS_PM802())//EC600S
	{
		unsigned short vat_val=0;
		quec_adc_read_bat(&vat_val);
		return vat_val;
	}
	else if(PMIC_IS_PM803())//EC600N,not support use in boot£¬Support Use in logo
	{
		return get_cranel_vbat();
	}
}
#endif
/**
 * somer.zhang-2020/06/10:get battery voltage when battery is charging
 * //1 -- on, 0 -- off
 **/
unsigned short ql_get_charging_battery_vol(void)
{
	return (unsigned short)pm813_get_bat_vol();
}

unsigned char ql_get_battery_level(void)
{
	unsigned char index = 7;
	unsigned short stable = 0;
	unsigned char percent = 0;

	//ndex = quec_charge_init();
	//forrest.liu@20210116 modify for PM802 not support charger result in dump
	if(index < 7)
	{
		stable = chargeManager[index].batStableVoltGet(&percent);
		if (stable > 0) {
			return percent;
		}
	}

	return 0;
}
#if 0

unsigned int ql_get_charge_cur(void)
{
	return pm813_get_Icharge_meas_cur_mA();
}


QL_CHARGER_STATUS_E ql_get_charge_status(void)
{
	unsigned char index = -1;

	index = quec_charge_init();
	return (QL_CHARGER_STATUS_E)(chargeManager[index].getFSM());
}
#else
//somer-2020/05/29
#if 0
QL_CHARGER_STATUS_E ql_get_charge_status(void)
{
	unsigned int state = pm813_force_charger_state_get();
	if(state&0x08)//force
	{
		power_dbg_log("force\r\n");
		return (QL_CHARGER_STATUS_E)(state&0x07);
	}
	else//normal
	{
		power_dbg_log("normal\r\n");
		#if 0
		return (QL_CHARGER_STATUS_E)pm813_get_charger_FSM_state();
		#else
		unsigned char index = 7;
		index = quec_charge_init();
		//forrest.liu@20210116 modify for PM802 not support charger result in dump
		if(index < 7)
		{
			return (QL_CHARGER_STATUS_E)(chargeManager[index].getFSM());
		}
		else
		{
			return 0;
		}
		#endif
	}
}
#endif
#endif
#if 0

unsigned char ql_set_charge_mpp(unsigned short limit_cur, unsigned int uvlo)
{
	unsigned char index = 7;
	
	index = quec_charge_init();
	//forrest.liu@20210116 modify for PM802 not support charger result in dump
	if(index < 7)
	{
		return quec_ningbo_set_mpp(limit_cur, uvlo);
	}
	else
	{
		return 1;
	}
}

/**
 * juson.zhang-2020/05/12:add charger switch api
 * //1 -- on, 0 -- off
 **/
void ql_charger_switch(unsigned char on_off)
{
	extern void pm813_charger_switch(BOOL OnOff);
	pm813_charger_switch(on_off);
}

/**
 * pre mode maximum current setting @ normal temp
 **/
void ql_max_pre_cur_set(QL_PRE_CHG_CURRENT_E value)
{
	pm813_precharge_current_set(value);
}

/**
 * CC mode maximum current setting @ normal temp
 **/
void ql_max_cc_cur_set(QL_CC_CHG_CURRENT_E value)
{

	pm813_cc_current_set((CC_CHG_CURRENT)value);
}

/**
 * Charge maximum current setting when PMIC temp is too high (110C)
 **/
void ql_max_cc_cur_set_toohigh(QL_CC_CHG_CURRENT_E value)
{
	pm813_cc_current_set_toohigh(value);
}

/**
 * Charger termination setting
 *	00: 100mA(dis_drvseg=1) 
 *      50mA  (dis_drvseg=0)
 *	01: 150mA(dis_drvseg=1) 
 *      25mA (dis_drvseg=0)
 *	10: 200mA(dis_drvseg=1) 
 *      75mA (dis_drvseg=0)
 *	11: 250mA(dis_drvseg=1) 
 *      100mA (dis_drvseg=0)
 **/
void ql_terminate_cur_set(QL_TERM_CHG_CURRENT_E value)
{
	pm813_charge_termination_current_set(value);
}

/**
 * Pre-charge timer
 * =00, 24 min
 * =01, 36 min
 * =10, 48 min
 * =11, 60 min
 **/
void ql_precharge_time_set(QL_PRE_CHG_TIME_E value)
{
	pm813_precharge_timer_set(value);
}

/**
 * Trickle charge timer
 * =00: 6 min
 * =01: 9 min
 * =10: 12 min
 * =11: 15 min
 **/
void ql_trickle_charge_time_set(QL_TRICKLE_CHG_TIME_E value)
{
	pm813_trickle_timer_set(value);
}

/**
 * force Charger state by software ,  as shown below:
             000: Force Shutdown
             001: Force Check
             010: Force Trickle Charge
             011: Force Pre Charge
             100: Force CC Charge
             101: Force CV Charge
             110: Force Termination
             111: Force Fault
 **/
void ql_force_charge_state_set(QL_CHARGER_STATUS_E value)
{
	unsigned int state = (1<<3);
	state |= value;
	pm813_force_charger_state_set(state);
}

QL_CHARGER_STATUS_E ql_force_charge_state_get(void)
{
	unsigned int state = pm813_force_charger_state_get();

	return (QL_CHARGER_STATUS_E)(state&0x7);
}

unsigned int ql_get_battemp_vol_mv(void)
{
	return pm813_get_battemp_meas_vol_mv_ex();//forrest.liu@20201201 modify from R01_b04 newest change 
}

void ql_cccv_time_set(QL_CCCV_TIME_SET_E value)
{
	unsigned int state=0;
	state |= value;
	pm813_cccv_timer_set(state);
}

void ql_vbat_vol_set(QL_VBAT_VOL_SET_E value)
{
	VBAT_VOLTAGE state=0;
	state |= value;
	pm813_vbat_set(state);
}
#endif
/*
somer-2020/05/29-add charger terminate current poll
*/
#if 0
QL_TERMINATE_JUDGE_E ql_charger_terminate_poll(unsigned int terminate_curr_mA)
{
	unsigned int charger_curr=0;
	static unsigned char cnt=0;
	charger_curr = ql_get_charge_cur();

	if(terminate_curr_mA<10)terminate_curr_mA=10;
	else if(terminate_curr_mA>500)terminate_curr_mA=500;
	
	if( charger_curr <= terminate_curr_mA )
	{
		if(++cnt>3)
		{
			cnt = 0;
			pm813_charger_switch(0);
			return QL_TERMINATE_ENABLE;
		}
	}else{cnt=0;}

return QL_TERMINATE_DISABLE;
}
#endif
/*
somer-2020/05/29-add recharger poll
*/
QL_RECHARGE_JUDGE_E ql_recharger_poll(unsigned int recharge_vol_mV)
{
	unsigned int bat_vol=0;
	static unsigned char cnt=0;
	bat_vol = ql_get_battery_vol();
	
	if( bat_vol <= recharge_vol_mV )
	{
		if(++cnt>3)
		{
			cnt = 0;
			pm813_charger_switch(1);
			return QL_RECHARGE_ENABLE;
		}
	}else{cnt=0;}

return QL_RECHARGE_DISABLE;
}
//forrest.liu@20201201 add from R01_b04 newest change 
#define BATTERY_LOW_VOL         3050
#define BATTERY_FULL_VOL        4200
#define LIMIT_CURR				1000	//1A
#define USB_UVLO				4200
/*=====================================================================*/
//description:
//ntc demo
//ntc name:NCP15XH103F03RC
//10K ==> 25 degree
#define LN_EN	0
static float ntc_to_Temp_v2(float ntc)
{
	float Y_temp;

	uart_printf("ntc = %.02f K\r\n", ntc);
	
	if(ntc>97)
	{
		#if LN_EN
		Y_temp = -18.59*log(ntc) + 57.967;
		#else
		Y_temp = 0.0006*ntc*ntc - 0.2914*ntc - 3.9682;
		#endif
		
	}
	else if(ntc>53.65)
	{
		#if LN_EN
		Y_temp = -20.27*log(ntc) + 65.648;
		#else
		Y_temp = 0.0021*ntc*ntc - 0.593*ntc + 10.726;
		#endif
	}
	else if(ntc>31) 
	{
		#if LN_EN
		Y_temp = -21.9*log(ntc) + 72.165; 
		#else
		Y_temp = 0.0071*ntc*ntc - 1.128*ntc + 25.157; 
		#endif
	}
	else if(ntc>18.67)
	{	
		#if LN_EN
		Y_temp = -23.64*log(ntc) + 78.124;
		#else
		Y_temp = 0.0225*ntc*ntc - 2.087*ntc + 40.106;
		#endif
	}
	else if(ntc>11.63)
	{
		#if LN_EN
		Y_temp = -25.34*log(ntc) + 83.12;
		#else
		Y_temp = 0.0645*ntc*ntc - 3.6551*ntc + 54.762;
		#endif
	}
	else if(ntc>7.46)
	{	
		#if LN_EN
		Y_temp = -27.04*log(ntc) + 87.292;
		#else
		Y_temp = 0.1713*ntc*ntc - 6.1452*ntc + 69.296;
		#endif
	}
	else if(ntc>4.92)
	{	
		#if LN_EN
		Y_temp = -28.78*log(ntc) + 90.793;
		#else
		Y_temp = 0.4336*ntc*ntc - 10.078*ntc + 84.058;
		#endif
	}
	else if(ntc>3.32)
	{
		#if LN_EN
		Y_temp = -30.44*log(ntc) + 93.447;
		#else
		Y_temp = 1.041*ntc*ntc - 16.054*ntc + 98.768;
		#endif
	}	
	else if(ntc>2.29)
	{	
		#if LN_EN
		Y_temp = -32.61*log(ntc) + 96.028;
		#else
		Y_temp = 2.5397*ntc*ntc - 25.994*ntc + 115.26;
		#endif
	}	
	else if(ntc>1.62)
	{	
		#if LN_EN
		Y_temp = -34.62*log(ntc) + 97.711;
		#else
		Y_temp = 5.309*ntc*ntc - 38.634*ntc + 129.7;
		#endif
	}	
	else if(ntc>1.17)
	{
		#if LN_EN
		Y_temp = -36.72*log(ntc) + 98.73;
		#else
		Y_temp = 10.952*ntc*ntc - 57.094*ntc + 144.8;
		#endif
	}	
	else if(ntc>0.86)
	{	
		#if LN_EN
		Y_temp = -38.68*log(ntc) + 99.026;
		#else
		Y_temp = 22.925*ntc*ntc - 84.916*ntc + 160.97;
		#endif
	}	
	else if(ntc>0.64)
	{
		
		#if LN_EN
		Y_temp = -40.98*log(ntc) + 98.686;
		#else
		Y_temp = 43.412*ntc*ntc - 120.1*ntc + 176.09;
		#endif
	}
	else
	{	
		#if LN_EN
		Y_temp = -42.74*log(ntc) + 97.929;
		#else
		Y_temp = 72.692*ntc*ntc - 158.46*ntc + 188.65;
		#endif
	}
		 	
return Y_temp;
}

static float volt_to_temp_v2(unsigned int volt)
{
	float Y_temp;
	float X_ntc;
	float ss=0.0f;
	ss =  volt*139/39;
	X_ntc  =  10*ss / ((1800-ss)-(volt/39));//10k pull up
	uart_printf("current ntc = %.02f K\r\n", X_ntc);
	Y_temp = ntc_to_Temp_v2(X_ntc);
	
return Y_temp;
}

//description:
//usb plug in ==> enter charging
//usb plug out ==> stop charging and power down
#if 0
void boot_battery_charge(void)
{
	unsigned char usb_connect_state = 0;
	unsigned int charger_skipped = 0, charger_cur = 0;
	unsigned short battery_vol = 0;
	unsigned char battery_percent = 0;
	QL_CHARGER_STATUS_E charger_status = 0;
	unsigned char mpp_done = 0;
	unsigned char termin_done = 0;
	unsigned short charging_bat_vol=0;
	unsigned int cnt=0;
	unsigned int battemp_vol_mv=0;
	float bat_temp=0.0f;

	unsigned char tmp_cnt = 0;
		
	ql_precharge_time_set(QL_PRE_CHG_MINUTE24);
	ql_cccv_time_set(QL_CCCV_TIME_MINUTE96);
	ql_trickle_charge_time_set(QL_TRICKLE_CHG_MINUTE6);//set trickle charge 6 min
	ql_max_pre_cur_set(QL_PRE_CHG_CUR_150MA);//set precharger max charger current
	ql_terminate_cur_set(QL_TERM_CHG_CUR_25MA);	
	ql_vbat_vol_set(QL_VBAT_VOL_4V20);
	//ql_max_cc_cur_set(QL_CC_CHG_CUR_1000MA);
	ql_charger_switch(1);//1-on 0-off

	battery_vol = ql_get_battery_vol();
	while (!charger_skipped) 
	{
		charger_cur = ql_get_charge_cur();
		charging_bat_vol = ql_get_charging_battery_vol();
		battery_percent = ql_get_battery_level();
		usb_connect_state = ql_get_vbus_state();				
		charger_status = ql_get_charge_status();

		if(cnt++>10)
		{	
			cnt = 0;
			battery_vol = ql_get_battery_vol();
		}
		mdelay(1000);

		#ifdef QUEC_BOOT_NTC_TMP
		battemp_vol_mv = ql_get_battemp_vol_mv();
		uart_printf("BootCharging...battemp_vol_mv: %d\r\n",battemp_vol_mv);
		bat_temp =  volt_to_temp_v2(battemp_vol_mv); 
		uart_printf("BootCharging...bat_temp: %.02f\r\n",bat_temp);
		#endif
		
		uart_printf("BootCharging...battery_vol:%d\r\n",battery_vol); 
		uart_printf("BootCharging...battery_percent:%d\r\n",battery_percent);
		uart_printf("BootCharging...charger_cur:%d\r\n", charger_cur);
		uart_printf("BootCharging...charger_status:%d\r\n",charger_status);
		uart_printf("BootCharging...charging_bat_vol:%d\r\n",charging_bat_vol);//This function switches the MOS tube causing level fluctuations, so it should be called last

		//forrest.liu@20210306 add for high temperature charger termination bug
		ningBoHandleChargerAbnormal();
		
		if (usb_connect_state) 
		{
			if (battery_vol < BATTERY_LOW_VOL) 
			{
				uart_printf("BT:Battery low voltage! \r\n");
				if (!mpp_done && (QL_CHARGER_CC==charger_status)) 
				{
					if (ql_set_charge_mpp(LIMIT_CURR, USB_UVLO)) 
					{
						mpp_done = 1;
					}
				}
				mdelay(3000);
				continue;
			}
			else 
			{
				if(charger_status==QL_CHARGER_CC)
				{
					if (!mpp_done) 
					{
						if (ql_set_charge_mpp(LIMIT_CURR, USB_UVLO)) 
						{
							mpp_done = 1;
						}
					}
				}	
				else if(charger_status==QL_CHARGER_CV)
				{
					if(termin_done == 0)
					{
						uart_printf("BT:terminate poll\r\n");
						if(ql_charger_terminate_poll(100)==QL_TERMINATE_ENABLE)//if terminate enable and enter terminate status, do not use "ql_charger_terminate_poll" again!!!
						{
							uart_printf("BT:Battery full...Charge already off\r\n");
							termin_done = 1;
							//charger_skipped = 1;
						}
					}
				}		
				else if(charger_status==QL_CHARGER_TER)
				{
					if(termin_done == 1)
					{
						uart_printf("BT:recharger poll\r\n");
						if(ql_recharger_poll(USB_UVLO-100) == QL_RECHARGE_ENABLE)//if recharger enable and enter charging, do not use "ql_recharger_poll" again!!! 
						{
							termin_done = 0;
							uart_printf("BT:Battery not full...recharge running\r\n");
						}
					}
				}
				
				if(Quec_PMIC_GET_PWEKY_STATUS())
				{
					uart_printf("BT:power key press !\r\n");
					//charger_skipped = 1;
					break;
				}
			}

			#ifdef QUEC_BOOT_NTC_TMP
			if( bat_temp < -5.0f || bat_temp > 55.0f )
			{
				ql_charger_switch(0);//1-on 0-off
				while(1)
				{
					if( bat_temp > -4.5f && bat_temp < 54.5f )
					{
						if(tmp_cnt++>3)
						{
							tmp_cnt = 0;
							ql_charger_switch(1);//1-on 0-off
							break;
						}					
					}
					mdelay(3000);
				}					
			}
			#endif				
		}
		else 
		{
			uart_printf("BT:USB is plugged out!\r\n");
			uart_printf("BT:stop charging!\r\n");
			uart_printf("BT:shut down!!\r\n");
			PMIC_PowerDown();
		}
		mdelay(1000);
	}
}
#endif
#if 0
/* juson.zhang-2020/06/16: add api control cam VDD output */
/**
 * LDO10, 2.8V output
 * on_off: 0---off, 1---on
 **/
void ql_set_cam_vdd_output(unsigned char on_off)
{
	if (PMIC_IS_PM813()){
	    Ningbo_Ldo_10_set_2_8();
	    Ningbo_Ldo_10_set(on_off);
    }
    else if (PMIC_IS_PM803())
    {
        int level1=0,level2=0;
        ql_gpio_set_direction(69);
        ql_gpio_set_direction(70);
        ql_gpio_get_level(69,&level1);
        ql_gpio_get_level(70,&level2);
        uart_printf("********level1:%d level2:%d***********\r\n", level1, level2);
        if(level1&&level2)//v1.1
        {
            uart_printf("********v1.1***********\r\n");
            GuilinLite_Ldo_8_set_2_8();
            GuilinLite_Ldo_8_set(on_off);
        }
        else if((!level1)&&level2)//v1.2
        {
            uart_printf("********v1.2***********\r\n");
            GuilinLite_Ldo_7_set_2_8();
            GuilinLite_Ldo_7_set(on_off);
        }
    }
}
#endif
/**
 * LDO13, 1.8V output
 * on_off: 0---off, 1---on
 **/
void ql_set_cam_iovdd_output(unsigned char on_off)
{
	Ningbo_Ldo_13_set_1_8();
	Ningbo_Ldo_13_set(on_off);
}

//test code
void ql_boot_get_battery_vol_test(void)
{
	unsigned short bat_vol = 0;
	int ii = 0;
	int jj = 0;
	int kk = 0;
	while(1)
	{
		bat_vol = ql_get_battery_vol();
		uart_printf("bat_vol:%d\r\n",bat_vol);
		for(ii=0;ii<2000;ii++)
		{
			for(jj=0;jj<10000;jj++);
		}

		if(kk++>20)
		{
			break;
		}		
	}
}
#endif
