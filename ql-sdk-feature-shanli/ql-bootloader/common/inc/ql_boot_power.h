/**
 ******************************************************************************
 * @file    ql_boot_gpio.h
 * @author  somer.zhang
 * @version V1.0.0
 * @date    2020/05/27
 * @brief   This file contains the power functions's declaration
 ******************************************************************************
 **/
#ifndef __QL_BOOT_POWER_H__
#define __QL_BOOT_POWER_H__
#ifdef __cplusplus
	 extern "C" {
#endif

//forrest.liu@20201201 add from R01_b04 newest change 
//#define QUEC_BOOT_BAT_CHARGE
//#define QUEC_BOOT_PWRKEY_CHECK
//#define QUEC_BOOT_VBUS_VOLT_CHECK
//#define QUEC_BOOT_NTC_TMP
//#define QUEC_BOOT_GET_POWERUP_REASON

#define NINGBO_RONLY_DATA_CHG_OK            (0x01<<3)

#define PMIC_813_A1 						0x31 
#define PMIC_813_A2                         0x32
#define PMIC_813_A3                         0x3B

/* Timer0_0 is configured to free run @1MHz from BootROM. */
#define APBTIMER0_CNT_REG   0xD4014090
#define APBTIMER0_EN_REG    0xD4014000

typedef enum QL_POWERUP_REASON_ENUM
{
	QL_POWERUP_NO_REASON = 0,
	QL_POWERUP_PWRKEY,
	QL_POWERUP_RESET,
	QL_POWERUP_VBAT,
	QL_POWERUP_RTC,
	QL_POWERUP_FAULT,
	QL_POWERUP_VBUS,
}QL_POWERUP_REASON_E;

typedef enum QL_CHARGER_STATUS_ENUM
{
	QL_CHARGER_SHUTDOWN = 0,
	QL_CHARGER_CHECK,
	QL_CHARGER_TRICKLE,
	QL_CHARGER_PRE,
	QL_CHARGER_CC,
	QL_CHARGER_CV,
	QL_CHARGER_TER,
	QL_CHARGER_FAULT,
}QL_CHARGER_STATUS_E;

typedef enum QL_PRE_CHG_CURRENT_ENUM
{
	QL_PRE_CHG_CUR_75MA,
	QL_PRE_CHG_CUR_50MA,
	QL_PRE_CHG_CUR_100MA,
	QL_PRE_CHG_CUR_150MA,
	QL_PRE_CHG_CUR_MAX = QL_PRE_CHG_CUR_150MA
}QL_PRE_CHG_CURRENT_E;

typedef enum QL_CC_CHG_CURRENT_ENUM
{
	QL_CC_CHG_CUR_100MA,
	QL_CC_CHG_CUR_200MA,
	QL_CC_CHG_CUR_300MA,
	QL_CC_CHG_CUR_400MA,
	QL_CC_CHG_CUR_450MA,
	QL_CC_CHG_CUR_500MA,
	QL_CC_CHG_CUR_550MA,
	QL_CC_CHG_CUR_600MA,
	QL_CC_CHG_CUR_650MA,
	QL_CC_CHG_CUR_700MA,
	QL_CC_CHG_CUR_750MA,
	QL_CC_CHG_CUR_800MA,
	QL_CC_CHG_CUR_850MA,
	QL_CC_CHG_CUR_900MA,
	QL_CC_CHG_CUR_950MA,
	QL_CC_CHG_CUR_1000MA,
	QL_CC_CHG_CUR_MAX = QL_CC_CHG_CUR_1000MA
}QL_CC_CHG_CURRENT_E;

typedef enum QL_TERM_CHG_CURRENT_ENUM
{
	QL_TERM_CHG_CUR_50MA,
	QL_TERM_CHG_CUR_25MA,
	QL_TERM_CHG_CUR_75MA,
	QL_TERM_CHG_CUR_100MA,
	QL_TERM_CHG_CUR_MAX = QL_TERM_CHG_CUR_100MA
}QL_TERM_CHG_CURRENT_E;

typedef enum QL_PRE_CHG_TIME_ENUM
{
	QL_PRE_CHG_MINUTE24,
	QL_PRE_CHG_MINUTE36,
	QL_PRE_CHG_MINUTE48,
	QL_PRE_CHG_MINUTE60,
	QL_PRE_CHG_MINUTE_MAX = QL_PRE_CHG_MINUTE60
}QL_PRE_CHG_TIME_E;

typedef enum QL_TRICKLE_CHG_TIME_ENUM
{
	QL_TRICKLE_CHG_MINUTE6,
	QL_TRICKLE_CHG_MINUTE9,
	QL_TRICKLE_CHG_MINUTE12,
	QL_TRICKLE_CHG_MINUTE15,
	QL_TRICKLE_CHG_MINUTE_MAX = QL_TRICKLE_CHG_MINUTE15
}QL_TRICKLE_CHG_TIME_E;

typedef enum QL_CCCV_TIME_SET_ENUM
{
	QL_CCCV_TIME_MINUTE96,
	QL_CCCV_TIME_MINUTE144,
	QL_CCCV_TIME_MINUTE192,
	QL_CCCV_TIME_MINUTE240,
	QL_CCCV_TIME_MINUTE_MAX=QL_CCCV_TIME_MINUTE240
}QL_CCCV_TIME_SET_E;

typedef enum QL_VBAT_VOL_SET_ENUM
{
	QL_VBAT_VOL_4V20,
	QL_VBAT_VOL_4V35,
	QL_VBAT_VOL_4V15,
	QL_VBAT_VOL_4V10,
	QL_VBAT_VOL_MAX=QL_VBAT_VOL_4V35
}QL_VBAT_VOL_SET_E;

typedef enum QL_TERMINATE_JUDGE_ENUM
{
	QL_TERMINATE_DISABLE = 0,
	QL_TERMINATE_ENABLE,	
}QL_TERMINATE_JUDGE_E;


typedef enum QL_RECHARGE_JUDGE_ENUM
{
	QL_RECHARGE_DISABLE = 0,
	QL_RECHARGE_ENABLE,
}QL_RECHARGE_JUDGE_E;

void delay_s(int s);
void ql_power_down(unsigned char normal_flag);
int ql_get_powerup_reason(void);
void Quec_pwrkey_check(void);

/*********************Charger API*******************/
unsigned char ql_get_vbus_state(void);
unsigned short ql_get_battery_vol(void);
unsigned short ql_get_charging_battery_vol(void);
unsigned char ql_get_battery_level(void);
unsigned int ql_get_charge_cur(void);
QL_CHARGER_STATUS_E ql_get_charge_status(void);
unsigned char ql_set_charge_mpp(unsigned short limit_cur, unsigned int uvlo);
void ql_charger_switch(unsigned char on_off); //1 -- on, 0 -- off
/**
 * precharger mode maximum current setting @ normal temp
 **/
void ql_max_pre_cur_set(QL_PRE_CHG_CURRENT_E value);
/**
 * CC mode maximum current setting @ normal temp
 **/
void ql_max_cc_cur_set(QL_CC_CHG_CURRENT_E value);
/**
 * Charge maximum current setting when PMIC temp is too high (110C)
 **/
void ql_max_cc_cur_set_toohigh(QL_CC_CHG_CURRENT_E value);
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
void ql_terminate_cur_set(QL_TERM_CHG_CURRENT_E value);
/**
 * Pre-charge timer
 * =00, 24 min
 * =01, 36 min
 * =10, 48 min
 * =11, 60 min
 **/
void ql_precharge_time_set(QL_PRE_CHG_TIME_E value);
/**
 * Trickle charge timer
 * =00: 6 min
 * =01: 9 min
 * =10: 12 min
 * =11: 15 min
 **/
void ql_trickle_charge_time_set(QL_TRICKLE_CHG_TIME_E value);
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
void ql_force_charge_state_set(QL_CHARGER_STATUS_E value);
QL_CHARGER_STATUS_E ql_force_charge_state_get(void);

/**
 * get battery temp(need NTC)
 **/
unsigned int ql_get_battemp_vol_mv(void);
/**
* cccv timer setting
**/
void ql_cccv_time_set(QL_CCCV_TIME_SET_E value);

/**
* vbat voltage setting
**/
void ql_vbat_vol_set(QL_VBAT_VOL_SET_E value);

/*
somer-2020/05/29-add charger terminate current poll
*/
QL_TERMINATE_JUDGE_E ql_charger_terminate_poll(unsigned int terminate_curr_mA);

/*
somer-2020/05/29-add recharger poll
*/
QL_RECHARGE_JUDGE_E ql_recharger_poll(unsigned int recharger_vol_mV);
//forrest.liu@20201201 add from R01_b04 newest change 
void boot_battery_charge(void);
void boot_battery_charge_v2(void);

/* juson.zhang-2020/06/16: add api control cam VDD output */
/**
 * LDO10, 2.8V output
 * on_off: 0---off, 1---on
 **/
void ql_set_cam_vdd_output(unsigned char on_off);

/**
 * LDO13, 1.8V output
 * on_off: 0---off, 1---on
 **/
void ql_set_cam_iovdd_output(unsigned char on_off);

//test code
void ql_boot_get_battery_vol_test(void);

#ifdef __cplusplus
	} /*"C" */
#endif

#endif



