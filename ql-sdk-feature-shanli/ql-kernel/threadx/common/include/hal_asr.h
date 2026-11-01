#ifndef _ASR_HAL_H_
#define _ASR_HAL_H_

typedef struct h_rtc_time {
  int tm_sec;	//seconds [0,59]
  int tm_min;	//minutes [0,59]
  int tm_hour;  //hour [0,23]
  int tm_mday;  //day of month [1,31]
  int tm_mon;   //month of year [1,12]
  int tm_year; // since 1970
  int tm_wday; // sunday = 0
}h_rtc;

void Hal_seconds_to_time(int tim, h_rtc *tm);
unsigned int Hal_Rtc_Get_Utc_Sec(void);
void Hal_Rtc_Settime(h_rtc *time);
void Hal_Rtc_Gettime(h_rtc *time);

char *Hal_get_imei(void);
char *Hal_get_sn(void);
unsigned char *Hal_get_mac(void);



#endif