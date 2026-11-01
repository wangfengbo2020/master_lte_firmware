#include "hal_asr.h"

typedef unsigned char	BOOL;
typedef unsigned char   UINT8;
typedef unsigned short  UINT16;
typedef unsigned long   UINT32;
typedef signed long     INT32;
#include "pmic_rtc.h"

extern char *getSerialNumber(void);
extern char *get_imei(int sim_id);
extern char gWifiMACAddr[6];
UINT8 *mvUsbNetGetMacAddress(void);

char *Hal_get_imei(void)
{
	return get_imei(0);
}

char *Hal_get_sn(void)
{
	return getSerialNumber();
}

unsigned char *Hal_get_mac(void)
{
	return mvUsbNetGetMacAddress();
}

unsigned int Hal_Rtc_Get_Utc_Sec(void)
{
	return time(0);
}

void Hal_seconds_to_time(int tim, h_rtc *tm)
{
	pmic_rtc_to_tm(tim, (t_rtc *)tm);
}

void Hal_Rtc_Settime(h_rtc *time)
{
	int tim = pmic_rtc_mktime((t_rtc *)time);
	tim += PMIC_RTC_GetTimezone()*60*60;
	pmic_rtc_to_tm(tim, (t_rtc *)time);
	PMIC_RTC_SetTime((t_rtc *)time, SYS_OFFSET);
	return;
}

void Hal_Rtc_Gettime(h_rtc *time)
{
	PMIC_RTC_GetUTCTime((t_rtc *)time, SYS_OFFSET);
	return;
}