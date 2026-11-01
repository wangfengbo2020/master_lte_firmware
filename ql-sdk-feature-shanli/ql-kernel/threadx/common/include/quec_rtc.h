/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/

/*=================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN              WHO         WHAT, WHERE, WHY
------------     -------     -------------------------------------------------------------------------------
12/04/2022        Fias        Init version:This file contains the rtc functions's definitions
=================================================================*/


#ifndef _QUEC_RTC_H
#define _QUEC_RTC_H



// #include "rtc.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	QUEC_SYS_OFFSET,
	QUEC_APP_OFFSET
}QUEC_RTC_OFFSET_TYPE;

typedef struct quec_rtc_time_struct {
	int quec_tm_sec;				//seconds [0,59]
	int quec_tm_min;				//minutes [0,59]
	int quec_tm_hour;			//hour [0,23]
	int quec_tm_mday;			//day of month [1,31]
	int quec_tm_mon;				//month of year [1,12]
	int quec_tm_year;			// since 1970
	int quec_tm_wday;			// sunday = 0
}quec_rtc_time_t;

typedef enum{
    COME_FORM_NITZ,
    COME_FORM_NTP,
    COME_FORM_APP,
    COME_FORM_UNKNOWN
}time_source_t;

typedef void (*quec_rtc_cb)(void);

void QUEC_RTC_GetTime(quec_rtc_time_t *tm);
void QUEC_RTC_SetTime(quec_rtc_time_t *tm);
void QUEC_RTC_Print_Time(quec_rtc_time_t *tm);

	
void QUEC_RTC_Set_Alarm(quec_rtc_time_t *tm);


void QUEC_RTC_Get_Alarm(quec_rtc_time_t *tm);

void QUEC_RTC_Enable_Alarm(unsigned char on_off);


void QUEC_RTC_Register_cb(quec_rtc_cb cb);

unsigned int QUEC_RTC_Get_Ticks(void);


unsigned long long QUEC_RTC_Get_Ticks_uint64(void);

    void quec_set_rtc_source(time_source_t source);

    time_source_t quec_get_rtc_source(void);

#ifdef __cplusplus
} /*"C" */
#endif

#endif

