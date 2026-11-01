#ifndef  __Saremo_RTC_h__
#define  __Saremo_RTC_h__





#define REG0_ADDR		0xB0
#define REG1_ADDR		0xB2
#define REG2_ADDR		0xB4
#define REG3_ADDR		0xB6

#define REG0_DATA		0xB1
#define REG1_DATA		0xB3
#define REG2_DATA		0xB5
#define REG3_DATA		0xB7


#define RTC_CTR				0xA0
#define RTC_Counter1		0xA1
#define RTC_Counter2		0xA2
#define RTC_Counter3		0xA3
#define RTC_Counter4		0xA4
#define RTC_Expire1			0xA5
#define RTC_Expire2			0xA6
#define RTC_Expire3			0xA7
#define RTC_Expire4			0xA8
#define RTC_Trim1			0xA9
#define RTC_Trim2			0xAA
#define RTC_Trim3			0xAB
#define RTC_Trim4			0xAC
#define RTC_Mis1			0xAD
#define RTC_Mis2			0xAE
#define RTC_Mis3			0xAF

/////////////////////////////////////////////////////////////
#define  WUKONG_RTC_BASE	0xD4010000
#define	 RTC_CNR			(WUKONG_RTC_BASE)
#define	 RTC_AR				(WUKONG_RTC_BASE+0x04)
#define	 RTC_SR				(WUKONG_RTC_BASE+0x08)
#define	 RTC_TR				(WUKONG_RTC_BASE+0x0c)
#define	 RTC_PR				(WUKONG_RTC_BASE+0x10)
#define	 RTC_BRn0			(WUKONG_RTC_BASE+0x14)
#define	 RTC_BRn1			(WUKONG_RTC_BASE+0x18)
#define	 RTC_BRn2			(WUKONG_RTC_BASE+0x1c)
#define	 RTC_BRn3			(WUKONG_RTC_BASE+0x20)
#define	 RTC_BRn4			(WUKONG_RTC_BASE+0x24)

#define  APB_RTC_CLK_RST	(0xD4282800+0x28)

typedef struct 
{
	unsigned int 	FixData1;
	unsigned int 	sec;
	unsigned int 	min;
	unsigned int 	hour;
	unsigned char 	week;
	unsigned char 	day;
	unsigned char 	month;
	unsigned int 	FixData2;
	unsigned int 	year;
	unsigned int  	RTC_reg;
	unsigned int  	Wifi_data;
	unsigned char 	set_flag;
	unsigned int 	FixData3;
	
}TIME;

#define RTC_FixData1		0x12345678
#define RTC_FixData2		0x87654321
#define RTC_FixData3		0xa5a5a5a5



///////////////////////////////////////////////////////////////
extern unsigned int  Wifi_Data_Base;
extern TIME Dis_Time,Current_Time, Set_time, Save_time;
extern unsigned int  RTC_Reg_Val0, RTC_Reg_Val1;

#include <time.h>
void RTC_Phase2_Init(void);
unsigned int Get_RTC_Val(void);
void WebUI_Set_Time(void);
void SaveNTPParameters(struct tm* NTPParms);
void Save_Time_WifiData(TIME time, char OnkeyEventFlag);
int WeekDay(unsigned int v_year, int v_month, unsigned char v_day);
unsigned char Update_RTC_Time(void);
void update_Date(unsigned int day_incr);

#endif
