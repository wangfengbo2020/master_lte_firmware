/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/
#ifndef _QL_POWER_H_
#define _QL_POWER_H_
#include "pmic.h"	 
#ifdef __cplusplus
	 extern "C" {
#endif
#define QL_SLEEP_FLAGS_GROUP_ID         ((unsigned int)0x514C504F)
#define QL_SLEEP_FLAGS_CLEAR_ID         ((unsigned int)0x0)

#define QL_SLEEP_FLAGS_AND_MASK         ((unsigned int)0x2)
#define QL_SLEEP_FLAGS_OR_MASK          ((unsigned int)0x0)

#define QL_SLEEP_FLAGS_GROUP_EMPTY      ((unsigned int)0x0)

#define QL_SLEEP_FLAGS_SUCCESS          ((unsigned int)0x00)
#define QL_SLEEP_FLAGS_ERROR            ((unsigned int)0x01)
#define QL_SLEEP_FLAGS_INVALID          ((unsigned int)0x02)

typedef void* ql_sleep_flags_ref ;

typedef enum QL_SLEEP_FLAG_ENUM
{
	QL_NOT_ALLOW_SLEEP = 0,
	QL_ALLOW_SLEEP,
}QL_SLEEP_FLAG_E;

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

typedef enum QL_POWERDOWN_REASON_ENUM
{
	QL_POWERDOWN_NO_REASON = 0,
	QL_POWERDOWN_PWRKEY,
	QL_POWERDOWN_VINLDO_HIGH,
	QL_POWERDOWN_VINLDO_LOW,
	QL_POWERDOWN_OVERTEMP,
	QL_POWERDOWN_WDT,
	QL_POWERDOWN_VRTC_LOW,
}QL_POWERDOWN_REASON_E;

typedef enum QL_SW_RESTART_REASON_ENUM
{
	QL_RSTREASON_POWEROFF_CHARGE = 'C', //Charging in "powering off" mode
	QL_RSTREASON_RD_PRODUCTION   = 'R', //Rd production mode
	QL_RSTREASON_RTC_ALARM       = 'A', //rtc Alarm
	QL_RSTREASON_NORMAL_POWERON  = 'N', //Normal powering on
	QL_RSTREASON_ERROR_CONDITION = 'E', //Error reset, eg. watchdog reset triggered by system hang or silent reset
	QL_RSTREASON_ENTER_DOWNLOAD  = 'D', //image Download mode
} QL_SW_RESTART_REASON_E;

typedef struct QL_SLEEP_FLAGS_GROUP_STRUCT
{   
    char            *ql_sleep_flag_group_name;
    
    unsigned int     ql_sleep_flag_group_id;
    
    struct QL_SLEEP_FLAGS_GROUP_STRUCT
                    *ql_sleep_flags_group_next, 
                    *ql_sleep_flags_group_previous;

    unsigned int     ql_sleep_flags_group_current;

    unsigned int     ql_sleep_flags_group_set_cnt;
}QL_SLEEP_FLAGS_GROUP;



void ql_sleep_flags_init(void);
unsigned int ql_sleep_flags_create(ql_sleep_flags_ref *group_ref , char *name_ptr);
unsigned int ql_sleep_flags_set(ql_sleep_flags_ref group_ref,unsigned int flags_to_set,unsigned int set_option);
unsigned int ql_sleep_flags_group_delete(ql_sleep_flags_ref group_ref);
unsigned int ql_get_current_sleep_flags(ql_sleep_flags_ref group_ref,unsigned int *current_flag_ptr);
void ql_autosleep_enable(QL_SLEEP_FLAG_E sleep_flag);
void ql_set_cam_vdd_output(unsigned char on_off);
void ql_power_down(unsigned char normal_flag);
void ql_power_reset(void);
void ql_power_reset_fast(void);
int ql_get_powerup_reason(void);
int ql_get_powerdown_reason(void);
unsigned short ql_get_battery_vol(void);
typedef void (*ql_pwrkey_cb)(void);
unsigned char ql_get_pwrkey_status(void);
void ql_pwrkey_register_irq(ql_pwrkey_cb callback);
void ql_pwrkey_intc_enable(unsigned char onoff);
unsigned char ql_get_vbus_state(void);
void ql_create_a_fake_wake_source(QL_SW_RESTART_REASON_E reason);
QL_SW_RESTART_REASON_E ql_get_the_fake_wake_source(void);
void ql_power_watchdog_reset(void);
int ql_lpm_wakelock_create(char *lock_name, int name_size);
void ql_lpm_wakelock_delete(int wakelock_fd);
int ql_lpm_wakelock_lock(int wakelock_fd);
int ql_lpm_wakelock_unlock(int wakelock_fd);
int ql_lpm_get_wakelock_num(void);

/***********************************************************************
 *
 * Name:   ql_autosleep_enable_ex	
 *
 * Description: 增强型休眠接口，再数传场景下可以更快进入休眠
 *
 * Parameters:	sleep_flag:禁用/启用增强型休眠模式
 *
 *				no_data_time:数传结束后进入休眠所等待时间单位秒，范围：1~50
 * Returns: 	punish_time：若遇到异常情况恢复增强型休眠模式的时间单位分钟，范围：1~600
 *				
 * Notes:
 *
 ***********************************************************************/
void ql_autosleep_enable_ex(QL_SLEEP_FLAG_E sleep_flag,unsigned short no_data_time,unsigned short punish_time);

/***********************************************************************
 *
 * Name:   ql_powerdown_rtc_in_work   
 *
 * Description: 关机后,设置LDO5的工作模式，switch to ldo5：不给RTC供电 switch to ldo5x：给RTC供电
 *
 * Parameters:	flag: 0：switch to ldo5   1：switch to ldo5x
 *			   
 * Returns:    0：设置成功 		非0：返回失败
 *				
 * Notes:	switch to ldo5x 关机耗流高100uA
 *
 ***********************************************************************/
int ql_powerdown_rtc_in_work(int flag);


/***********************************************************************
 *
 * Name:   ql_power_stop_system   
 *
 * Description: 设置系统CFUN0后，不在允许擦写flash，并阻塞所有线程（所以此接口请不要在中断、定时器等回调中使用）
 *
 * Parameters:	flag: 0：switch to ldo5   1：switch to ldo5x
 *			   
 * Returns:  
 *				
 ***********************************************************************/
void ql_power_stop_system(void);


#ifdef __cplusplus
	} /*"C" */
#endif

#endif /* _QL_POWER_H_ */


