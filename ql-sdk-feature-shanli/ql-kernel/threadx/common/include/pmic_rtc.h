#ifndef _PRTC_H_
#define _PRTC_H_
#include "gbl_types.h"

typedef struct rtc_time {
  int tm_sec;	//seconds [0,59]
  int tm_min;	//minutes [0,59]
  int tm_hour;  //hour [0,23]
  int tm_mday;  //day of month [1,31]
  int tm_mon;   //month of year [1,12]
  int tm_year; // since 1970
  int tm_wday; // sunday = 0
}t_rtc;

//20190513@xiaokeweng : RTC_APP_OFFSET implement ++
typedef enum {
	SYS_OFFSET,
	APP_OFFSET
}PMIC_RTC_OFFSET_TYPE;
//20190513@xiaokeweng : RTC_APP_OFFSET implement --


typedef enum {
	RTC_EXPIRE_1=1,
	RTC_EXPIRE_2=2 //RTC_EXPIRE AREA REUSED AS APP_OFFSET, SO ONLY RTC_EXPIRE_1 AVAILABLED
}RTC_EXPIRE_ID;

#define FEBRUARY		2
#define	STARTOFTIME		1970
#define SECDAY			86400L
#define SECYR			(SECDAY * 365)
#define QUEC_PMIC_RTC_OFFSET_TYPE   APP_OFFSET/*定义类型，便于修改*/
typedef void (*AlCallback)(void);


int pmic_rtc_to_tm(unsigned int tim, t_rtc *tm);
void PMIC_RTC_GetTime(t_rtc *tmp,PMIC_RTC_OFFSET_TYPE type);
void PMIC_RTC_GetUTCTime(t_rtc *tmp,PMIC_RTC_OFFSET_TYPE type);
UINT32 PMIC_RTC_GetTime_Count_Without_Timezone(PMIC_RTC_OFFSET_TYPE type);
void PMIC_RTC_SetTime(t_rtc *tmp,PMIC_RTC_OFFSET_TYPE type);
void PMIC_RTC_SetAlarm(t_rtc *tmp);
void PMIC_RTC_GetAlarm(t_rtc *tmp);
void PMIC_RTC_EnableAlarm(BOOL onoff);
void PMIC_RTC_init(AlCallback callback);
UINT32 PMIC_RTC_GetTime_Count(PMIC_RTC_OFFSET_TYPE type);
BOOL PMIC_RTC_is_alarm_powerup(void);
BOOL PMIC_RTC_IS_SYS_RTC_PEER_SYNCED(void);

void pmic_rtc_print_tm(t_rtc *tmp);

t_rtc * PMIC_gmttime(const unsigned int * m_time);
unsigned int time(unsigned int * retrievedTime);
unsigned int millisecond_get(void);

INT32 PMIC_RTC_GetTimezone(void);
void PMIC_RTC_SetTimezone(INT32 timezone);
unsigned long pmic_rtc_mktime(const t_rtc *tm);

BOOL pmic_userdata_get_app_rtc_ever_configed(void);
void pmic_userdata_set_app_rtc_ever_configed(void);
void pmic_userdata_unset_app_rtc_ever_configed(void);
void pmic_rtc_offset_storage_type_detect(void);
void pmic_rtc_setting_init_fetch(void);
void pmic_rtc_setting_save(void);


BOOL pmic_rtc_INIT_FLAG_GET(void);
void PMIC_RTC_USERDATA_CFG_SET(UINT8 bit_mask,BOOL marked);
BOOL PMIC_RTC_USERDATA_CFG_GET(UINT8 bit_mask);
void pm813_userdata_set_app_rtc_ever_configed(void);
BOOL pm813_userdata_get_app_rtc_ever_configed(void);
BOOL pmic_rtc_valid(int year,int month,int day,int hour,int min,int sec,int timezone);

void PMIC_RTC_SetAlarm_id(RTC_EXPIRE_ID id, t_rtc *tmp,PMIC_RTC_OFFSET_TYPE type);
void PMIC_RTC_GetAlarm_id(RTC_EXPIRE_ID id, t_rtc *tmp,PMIC_RTC_OFFSET_TYPE type);
void PMIC_RTC_EnableAlarm_id(RTC_EXPIRE_ID id,BOOL onoff);
void PMIC_RTC_Alarm_Update_Follow_RTC_SetTime(UINT32 src_offset,UINT32 dst_offset,RTC_EXPIRE_ID id);


#endif//_PRTC_H_
