#ifndef     _GUILIN_LITE2_H_
#define     _GUILIN_LITE2_H_

/*************************************************************************
*               Included Files.
**************************************************************************/

#ifdef LTEONLY_THIN
#define GUILIN_LITE2_DEBUG 0
#else
#define GUILIN_LITE2_DEBUG 1
#endif

#if GUILIN_LITE2_DEBUG
#define GUILIN_LITE2_UART_DEBUG(fmt,...) uart_printf(fmt, ##__VA_ARGS__)
#else
#define GUILIN_LITE2_UART_DEBUG(fmt,...)
#endif

/***************************************************************************
*                       Typedefines  & Macros
****************************************************************************/
/* GuilinLite2 Registers defines.                        */
/* (1)GUILIN_LITE2 BASE REGISTER                          */

#define     GUILIN_LITE2_ID_REG                       0x00            /* Identification Register.                         */

#define     GUILIN_LITE2_STATUS_REG1                  0x01
#define     GUILIN_LITE2_BAT_DETECT                   0x10            /* Battery is present.                              */
#define     GUILIN_LITE2_RTC_ALARM_STATUS_BIT         0x08            /* RTC_ALARM = 1.                               */
#define     GUILIN_LITE2_EXTON2_DETECT                0x04            /* EXTON2_DETECT = 1.                               */
#define     GUILIN_LITE2_EXTON1_DETECT                0x02            /* EXTON1_DETECT = 1.                               */
#define     GUILIN_LITE2_ONKEY_PRESSED                0x01            /* ONKEYn is Pressed.                               */

#define     GUILIN_LITE2_INT_STATUS_REG1              0x05            /* Interrupt Status Register1.                      */
#define     GUILIN_LITE2_BAT_INT_OCCURRED             0x10            /* Set,when BAT_DET changes.                        */
#define     GUILIN_LITE2_RTC_INT_OCCURRED             0x08            /* Set,when RTC alarm occurred.                     */
#define     GUILIN_LITE2_EXTON2_INT_OCCURRED          0x04            /* Set,when EXTON2 charged.                         */
#define     GUILIN_LITE2_EXTON1_INT_OCCURRED          0x02            /* Set,when EXTON1 charged.                         */
#define     GUILIN_LITE2_ONKEY_INT_OCCURRED           0x01            /* Set,when ONKEY changed.                          */

#define     GUILIN_LITE2_INT_ENABLE_REG1              0x09            /* Interrupt Enable Register1.                      */
#define     GUILIN_LITE2_BAT_INT_EN                   0x10            /* BAT Interrupt Enable.                            */
#define     GUILIN_LITE2_RTC_INT_EN                   0x08            /* RTC Interrupt Enable.                            */
#define     GUILIN_LITE2_EXTON2_INT_EN                0x04            /* EXTON2 Interrupt Enable.                         */
#define     GUILIN_LITE2_EXTON1_INT_EN                0x02            /* EXTON1 Interrupt Enable.                         */
#define     GUILIN_LITE2_ONKEY_INT_EN                 0x01            /* ONKEY Interrupt Enable.                          */

#define     GUILIN_LITE2_WAKEUP_REG1                  0x0d            /* Wakeup Register1.                                */
#define     GUILIN_LITE2_POWER_HOLD                   0x80            /* LPF & DVC enable, SLEEPn disable.                */
#define     GUILIN_LITE2_RESET_PMIC_REG               0x40            /* Reset Ustica registers.                          */
#define     GUILIN_LITE2_SW_PDOWN                     0x20            /* Entrance to 'power-down' sate.                   */
#define     GUILIN_LITE2_WD_RESET                     0x10            /* Resets the Watchdog timer.                       */
#define     GUILIN_LITE2_WD_MODE                      0x01            /* WD1#->toggle RESET_OUTn,WD2#->PowerDown.         */

#define 	GUILIN_LITE2_PWRUP_LOG_REG				0x10

#define     GUILIN_LITE2_WD_REG                       0x1D            /* Watchdog Register                                */
#define     GUILIN_LITE2_WD_DIS                       0x01            /* Watchdog disable.                                */

#define     GUILIN_LITE2_RTC_CTRL_REG	             0xD0            /* RTC_Control>.                                */
#define     GUILIN_LITE2_RTC_DIS_ALARM_PULLDOWN_BIT   (0x01<<7)
#define     GUILIN_LITE2_RTC_OTP_RELOAD_DISABLE_BIT   (0x01<<6)
#define     GUILIN_LITE2_RTC_ALARM_SET_BIT            (0x01<<0)

#define     GUILIN_LITE2_RTC_COUNT_REG1               0xD1            /* RTC_COUNTER<0:7>.                                */
#define     GUILIN_LITE2_RTC_COUNT_REG2               0xD2            /* RTC_COUNTER<8:15>.                               */
#define     GUILIN_LITE2_RTC_COUNT_REG3               0xD3            /* RTC_COUNTER<16:23>.                              */
#define     GUILIN_LITE2_RTC_COUNT_REG4               0xD4            /* RTC_COUNTER<24:31>.                              */
#define     GUILIN_LITE2_RTC_EXPIRE_REG1              0xD5            /* RTC_EXPIRE1<0:7>.                                */
#define     GUILIN_LITE2_RTC_EXPIRE_REG2              0xD6            /* RTC_EXPIRE1<8:15>.                               */
#define     GUILIN_LITE2_RTC_EXPIRE_REG3              0xD7            /* RTC_EXPIRE1<16:23>.                              */
#define     GUILIN_LITE2_RTC_EXPIRE_REG4              0xD8            /* RTC_EXPIRE1<24:31>.                              */

#define     GUILIN_LITE2_RTC_MISC_3_REG				0xE3

#define     GUILIN_LITE2_RTC_USER_DATA_0_REG          0xC0            /* User defined region */
#define     GUILIN_LITE2_RTC_USER_DATA_1_REG          0xC1
#define     GUILIN_LITE2_RTC_USER_DATA_2_REG          0xC2
#define     GUILIN_LITE2_RTC_USER_DATA_3_REG          0xC3
#define     GUILIN_LITE2_RTC_USERDATA_SETTING_MARK_REG GUILIN_LITE2_RTC_USER_DATA_0_REG  

#define     GUILIN_LITE2_CLK_32K_SEL_REG				0xE4
#define     GUILIN_LITE2_LONGKEY_EN2                  0x02             /* When enabled, the event will cause power-down.   */
#define     GUILIN_LITE2_LONGKEY_EN1                  0x01             /* When enabled, the event will cause power-down.   */

#define 	GUILIN_LITE2_LONGKEY_1					0
#define 	GUILIN_LITE2_LONGKEY_2					1

#define     GUILIN_LITE2_POWERDOWN_LOG_REG				0xE5
#define     GUILIN_LITE2_POWERDOWN_LOG_REG2				0xE6

/* (1)GUILIN_LITE2 POWER REGISTER                          */

//LDO
#define     GUILIN_LITE2_LDO1_ACTIVE_VOUT_REG         0x71
#define     GUILIN_LITE2_LDO2_ACTIVE_VOUT_REG         0x74
#define     GUILIN_LITE2_LDO3_ACTIVE_VOUT_REG         0x77
#define     GUILIN_LITE2_LDO4_ACTIVE_VOUT_REG         0x7A
#define     GUILIN_LITE2_LDO5_ACTIVE_VOUT_REG         0x7D
#define     GUILIN_LITE2_LDO6_ACTIVE_VOUT_REG         0x80

#define     GUILIN_LITE2_LDO1_SLEEP_VOUT_REG          0x70
#define     GUILIN_LITE2_LDO2_SLEEP_VOUT_REG          0x73
#define     GUILIN_LITE2_LDO3_SLEEP_VOUT_REG          0x76
#define     GUILIN_LITE2_LDO4_SLEEP_VOUT_REG          0x79
#define     GUILIN_LITE2_LDO5_SLEEP_VOUT_REG          0x7C
#define     GUILIN_LITE2_LDO6_SLEEP_VOUT_REG          0x7F

#define     GUILIN_LITE2_LDO1_ENABLE_REG			GUILIN_LITE2_LDO1_ACTIVE_VOUT_REG
#define     GUILIN_LITE2_LDO2_ENABLE_REG			GUILIN_LITE2_LDO2_ACTIVE_VOUT_REG
#define     GUILIN_LITE2_LDO3_ENABLE_REG			GUILIN_LITE2_LDO3_ACTIVE_VOUT_REG
#define     GUILIN_LITE2_LDO4_ENABLE_REG			GUILIN_LITE2_LDO4_ACTIVE_VOUT_REG
#define     GUILIN_LITE2_LDO5_ENABLE_REG			GUILIN_LITE2_LDO5_ACTIVE_VOUT_REG
#define     GUILIN_LITE2_LDO6_ENABLE_REG			GUILIN_LITE2_LDO6_ACTIVE_VOUT_REG

#define     GUILIN_LITE2_LDO1_SLEEP_MODE_REG		GUILIN_LITE2_LDO1_SLEEP_VOUT_REG
#define     GUILIN_LITE2_LDO2_SLEEP_MODE_REG		GUILIN_LITE2_LDO2_SLEEP_VOUT_REG
#define     GUILIN_LITE2_LDO3_SLEEP_MODE_REG		GUILIN_LITE2_LDO3_SLEEP_VOUT_REG
#define     GUILIN_LITE2_LDO4_SLEEP_MODE_REG		GUILIN_LITE2_LDO4_SLEEP_VOUT_REG
#define     GUILIN_LITE2_LDO5_SLEEP_MODE_REG		GUILIN_LITE2_LDO5_SLEEP_VOUT_REG
#define     GUILIN_LITE2_LDO6_SLEEP_MODE_REG		GUILIN_LITE2_LDO6_SLEEP_VOUT_REG

//VBUCK
#define	    GUILIN_LITE2_CONTAIN_VBUCK_ACTIVE_VOUT_MASK	(0x7f)
#define     GUILIN_LITE2_CONTAIN_VBUCK_SLEEP_VOUT_MASK	(0x7f)

//step 0.01v, from 0.48v to 1.28v
#define     GUILIN_LITE2_VBUCK_0V48	                 (0x00)
#define     GUILIN_LITE2_VBUCK_0V49	                 (GUILIN_LITE2_VBUCK_0V48+1)
#define     GUILIN_LITE2_VBUCK_0V50	                 (GUILIN_LITE2_VBUCK_0V48+2)
#define     GUILIN_LITE2_VBUCK_0V51	                 (GUILIN_LITE2_VBUCK_0V48+3)
#define     GUILIN_LITE2_VBUCK_0V52	                 (GUILIN_LITE2_VBUCK_0V48+4)
#define     GUILIN_LITE2_VBUCK_0V53	                 (GUILIN_LITE2_VBUCK_0V48+5)
#define     GUILIN_LITE2_VBUCK_0V54	                 (GUILIN_LITE2_VBUCK_0V48+6)
#define     GUILIN_LITE2_VBUCK_0V55	                 (GUILIN_LITE2_VBUCK_0V48+7)
#define     GUILIN_LITE2_VBUCK_0V56                  (GUILIN_LITE2_VBUCK_0V48+8)
#define     GUILIN_LITE2_VBUCK_0V57                  (GUILIN_LITE2_VBUCK_0V48+9)
#define     GUILIN_LITE2_VBUCK_0V58                  (GUILIN_LITE2_VBUCK_0V48+10)
#define     GUILIN_LITE2_VBUCK_0V59                  (GUILIN_LITE2_VBUCK_0V48+11)
#define     GUILIN_LITE2_VBUCK_0V60                  (GUILIN_LITE2_VBUCK_0V48+12)
#define     GUILIN_LITE2_VBUCK_0V61                  (GUILIN_LITE2_VBUCK_0V48+13)
#define     GUILIN_LITE2_VBUCK_0V62                  (GUILIN_LITE2_VBUCK_0V48+14)
#define     GUILIN_LITE2_VBUCK_0V63                  (GUILIN_LITE2_VBUCK_0V48+15)
#define     GUILIN_LITE2_VBUCK_0V64                  (GUILIN_LITE2_VBUCK_0V48+16)
#define     GUILIN_LITE2_VBUCK_0V65                  (GUILIN_LITE2_VBUCK_0V48+17)
#define     GUILIN_LITE2_VBUCK_0V66                  (GUILIN_LITE2_VBUCK_0V48+18)
#define     GUILIN_LITE2_VBUCK_0V67                  (GUILIN_LITE2_VBUCK_0V48+19)
#define     GUILIN_LITE2_VBUCK_0V68                  (GUILIN_LITE2_VBUCK_0V48+20)
#define     GUILIN_LITE2_VBUCK_0V69                  (GUILIN_LITE2_VBUCK_0V48+21)
#define     GUILIN_LITE2_VBUCK_0V70                  (GUILIN_LITE2_VBUCK_0V48+22)
#define     GUILIN_LITE2_VBUCK_0V71                  (GUILIN_LITE2_VBUCK_0V48+23)
#define     GUILIN_LITE2_VBUCK_0V72                  (GUILIN_LITE2_VBUCK_0V48+24)
#define     GUILIN_LITE2_VBUCK_0V73                  (GUILIN_LITE2_VBUCK_0V48+25)
#define     GUILIN_LITE2_VBUCK_0V74                  (GUILIN_LITE2_VBUCK_0V48+26)
#define     GUILIN_LITE2_VBUCK_0V75                  (GUILIN_LITE2_VBUCK_0V48+27)
#define     GUILIN_LITE2_VBUCK_0V76                  (GUILIN_LITE2_VBUCK_0V48+28)
#define     GUILIN_LITE2_VBUCK_0V77                  (GUILIN_LITE2_VBUCK_0V48+29)
#define     GUILIN_LITE2_VBUCK_0V78                  (GUILIN_LITE2_VBUCK_0V48+30)
#define     GUILIN_LITE2_VBUCK_0V79                  (GUILIN_LITE2_VBUCK_0V48+31)
#define     GUILIN_LITE2_VBUCK_0V80                  (GUILIN_LITE2_VBUCK_0V48+32)
#define     GUILIN_LITE2_VBUCK_0V81                  (GUILIN_LITE2_VBUCK_0V48+33)
#define     GUILIN_LITE2_VBUCK_0V82                  (GUILIN_LITE2_VBUCK_0V48+34)
#define     GUILIN_LITE2_VBUCK_0V83                  (GUILIN_LITE2_VBUCK_0V48+35)
#define     GUILIN_LITE2_VBUCK_0V84                  (GUILIN_LITE2_VBUCK_0V48+36)
#define     GUILIN_LITE2_VBUCK_0V85                  (GUILIN_LITE2_VBUCK_0V48+37)
#define     GUILIN_LITE2_VBUCK_0V86                  (GUILIN_LITE2_VBUCK_0V48+38)
#define     GUILIN_LITE2_VBUCK_0V87                  (GUILIN_LITE2_VBUCK_0V48+39)
#define     GUILIN_LITE2_VBUCK_0V88                  (GUILIN_LITE2_VBUCK_0V48+40)
#define     GUILIN_LITE2_VBUCK_0V89                  (GUILIN_LITE2_VBUCK_0V48+41)
#define     GUILIN_LITE2_VBUCK_0V90                  (GUILIN_LITE2_VBUCK_0V48+42)
#define     GUILIN_LITE2_VBUCK_0V91                  (GUILIN_LITE2_VBUCK_0V48+43)
#define     GUILIN_LITE2_VBUCK_0V92                  (GUILIN_LITE2_VBUCK_0V48+44)
#define     GUILIN_LITE2_VBUCK_0V93                  (GUILIN_LITE2_VBUCK_0V48+45)
#define     GUILIN_LITE2_VBUCK_0V94                  (GUILIN_LITE2_VBUCK_0V48+46)
#define     GUILIN_LITE2_VBUCK_0V95                  (GUILIN_LITE2_VBUCK_0V48+47)
#define     GUILIN_LITE2_VBUCK_0V96                  (GUILIN_LITE2_VBUCK_0V48+48)
#define     GUILIN_LITE2_VBUCK_0V97                  (GUILIN_LITE2_VBUCK_0V48+49)
#define     GUILIN_LITE2_VBUCK_0V98                  (GUILIN_LITE2_VBUCK_0V48+50)
#define     GUILIN_LITE2_VBUCK_0V99                  (GUILIN_LITE2_VBUCK_0V48+51)
#define     GUILIN_LITE2_VBUCK_1V00                  (GUILIN_LITE2_VBUCK_0V48+52)
#define     GUILIN_LITE2_VBUCK_1V01                  (GUILIN_LITE2_VBUCK_0V48+53)
#define     GUILIN_LITE2_VBUCK_1V02                  (GUILIN_LITE2_VBUCK_0V48+54)
#define     GUILIN_LITE2_VBUCK_1V03                  (GUILIN_LITE2_VBUCK_0V48+55)
#define     GUILIN_LITE2_VBUCK_1V04                  (GUILIN_LITE2_VBUCK_0V48+56)
#define     GUILIN_LITE2_VBUCK_1V05                  (GUILIN_LITE2_VBUCK_0V48+57)
#define     GUILIN_LITE2_VBUCK_1V06                  (GUILIN_LITE2_VBUCK_0V48+58)
#define     GUILIN_LITE2_VBUCK_1V07                  (GUILIN_LITE2_VBUCK_0V48+59)
#define     GUILIN_LITE2_VBUCK_1V08                  (GUILIN_LITE2_VBUCK_0V48+60)
#define     GUILIN_LITE2_VBUCK_1V09                  (GUILIN_LITE2_VBUCK_0V48+61)
#define     GUILIN_LITE2_VBUCK_1V10                  (GUILIN_LITE2_VBUCK_0V48+62)
#define     GUILIN_LITE2_VBUCK_1V11                  (GUILIN_LITE2_VBUCK_0V48+63)
#define     GUILIN_LITE2_VBUCK_1V12                  (GUILIN_LITE2_VBUCK_0V48+64)
#define     GUILIN_LITE2_VBUCK_1V13                  (GUILIN_LITE2_VBUCK_0V48+65)
#define     GUILIN_LITE2_VBUCK_1V14                  (GUILIN_LITE2_VBUCK_0V48+66)
#define     GUILIN_LITE2_VBUCK_1V15                  (GUILIN_LITE2_VBUCK_0V48+67)
#define     GUILIN_LITE2_VBUCK_1V16                  (GUILIN_LITE2_VBUCK_0V48+68)
#define     GUILIN_LITE2_VBUCK_1V17                  (GUILIN_LITE2_VBUCK_0V48+69)
#define     GUILIN_LITE2_VBUCK_1V18                  (GUILIN_LITE2_VBUCK_0V48+70)
#define     GUILIN_LITE2_VBUCK_1V19                  (GUILIN_LITE2_VBUCK_0V48+71)
#define     GUILIN_LITE2_VBUCK_1V20                  (GUILIN_LITE2_VBUCK_0V48+72)
#define     GUILIN_LITE2_VBUCK_1V21                  (GUILIN_LITE2_VBUCK_0V48+73)
#define     GUILIN_LITE2_VBUCK_1V22                  (GUILIN_LITE2_VBUCK_0V48+74)
#define     GUILIN_LITE2_VBUCK_1V23                  (GUILIN_LITE2_VBUCK_0V48+75)
#define     GUILIN_LITE2_VBUCK_1V24                  (GUILIN_LITE2_VBUCK_0V48+76)
#define     GUILIN_LITE2_VBUCK_1V25                  (GUILIN_LITE2_VBUCK_0V48+77)
#define     GUILIN_LITE2_VBUCK_1V26                  (GUILIN_LITE2_VBUCK_0V48+78)
#define     GUILIN_LITE2_VBUCK_1V27                  (GUILIN_LITE2_VBUCK_0V48+79)
#define     GUILIN_LITE2_VBUCK_1V28                  (GUILIN_LITE2_VBUCK_0V48+80)

//LDO NORMAL mode
#define     GUILIN_LITE2_LDO_ACTIVE_VOUT_MASK             (0xf << 0)//BIT[3:0] for vout of Active mode

//LDO1
#define     GUILIN_LITE2_LDO1_ACTIVE_1V20                (0x0)
#define     GUILIN_LITE2_LDO1_ACTIVE_1V25                (0x1)
#define     GUILIN_LITE2_LDO1_ACTIVE_1V60                (0x2)
#define     GUILIN_LITE2_LDO1_ACTIVE_1V65                (0x3)
#define     GUILIN_LITE2_LDO1_ACTIVE_1V70                (0x4)
#define     GUILIN_LITE2_LDO1_ACTIVE_1V75                (0x5)
#define     GUILIN_LITE2_LDO1_ACTIVE_1V80                (0x6)
#define     GUILIN_LITE2_LDO1_ACTIVE_1V85                (0x7)
#define     GUILIN_LITE2_LDO1_ACTIVE_1V90                (0x8)
#define     GUILIN_LITE2_LDO1_ACTIVE_2V75                (0x9)
#define     GUILIN_LITE2_LDO1_ACTIVE_2V80                (0xa)
#define     GUILIN_LITE2_LDO1_ACTIVE_2V85                (0xb)
#define     GUILIN_LITE2_LDO1_ACTIVE_2V90                (0xc)
#define     GUILIN_LITE2_LDO1_ACTIVE_3V00                (0xd)
#define     GUILIN_LITE2_LDO1_ACTIVE_3V10                (0xe)
#define     GUILIN_LITE2_LDO1_ACTIVE_3V30                (0xf)
//LDO2
#define     GUILIN_LITE2_LDO2_ACTIVE_1V20                GUILIN_LITE2_LDO1_ACTIVE_1V20
#define     GUILIN_LITE2_LDO2_ACTIVE_1V25                GUILIN_LITE2_LDO1_ACTIVE_1V25
#define     GUILIN_LITE2_LDO2_ACTIVE_1V60                GUILIN_LITE2_LDO1_ACTIVE_1V60
#define     GUILIN_LITE2_LDO2_ACTIVE_1V65                GUILIN_LITE2_LDO1_ACTIVE_1V65
#define     GUILIN_LITE2_LDO2_ACTIVE_1V70                GUILIN_LITE2_LDO1_ACTIVE_1V70
#define     GUILIN_LITE2_LDO2_ACTIVE_1V75                GUILIN_LITE2_LDO1_ACTIVE_1V75
#define     GUILIN_LITE2_LDO2_ACTIVE_1V80                GUILIN_LITE2_LDO1_ACTIVE_1V80
#define     GUILIN_LITE2_LDO2_ACTIVE_1V85                GUILIN_LITE2_LDO1_ACTIVE_1V85
#define     GUILIN_LITE2_LDO2_ACTIVE_1V90                GUILIN_LITE2_LDO1_ACTIVE_1V90
#define     GUILIN_LITE2_LDO2_ACTIVE_2V75                GUILIN_LITE2_LDO1_ACTIVE_2V75
#define     GUILIN_LITE2_LDO2_ACTIVE_2V80                GUILIN_LITE2_LDO1_ACTIVE_2V80
#define     GUILIN_LITE2_LDO2_ACTIVE_2V85                GUILIN_LITE2_LDO1_ACTIVE_2V85
#define     GUILIN_LITE2_LDO2_ACTIVE_2V90                GUILIN_LITE2_LDO1_ACTIVE_2V90
#define     GUILIN_LITE2_LDO2_ACTIVE_3V00                GUILIN_LITE2_LDO1_ACTIVE_3V00
#define     GUILIN_LITE2_LDO2_ACTIVE_3V10                GUILIN_LITE2_LDO1_ACTIVE_3V10
#define     GUILIN_LITE2_LDO2_ACTIVE_3V30                GUILIN_LITE2_LDO1_ACTIVE_3V30
//LDO3
#define     GUILIN_LITE2_LDO3_ACTIVE_1V20                GUILIN_LITE2_LDO1_ACTIVE_1V20
#define     GUILIN_LITE2_LDO3_ACTIVE_1V25                GUILIN_LITE2_LDO1_ACTIVE_1V25
#define     GUILIN_LITE2_LDO3_ACTIVE_1V60                GUILIN_LITE2_LDO1_ACTIVE_1V60
#define     GUILIN_LITE2_LDO3_ACTIVE_1V65                GUILIN_LITE2_LDO1_ACTIVE_1V65
#define     GUILIN_LITE2_LDO3_ACTIVE_1V70                GUILIN_LITE2_LDO1_ACTIVE_1V70
#define     GUILIN_LITE2_LDO3_ACTIVE_1V75                GUILIN_LITE2_LDO1_ACTIVE_1V75
#define     GUILIN_LITE2_LDO3_ACTIVE_1V80                GUILIN_LITE2_LDO1_ACTIVE_1V80
#define     GUILIN_LITE2_LDO3_ACTIVE_1V85                GUILIN_LITE2_LDO1_ACTIVE_1V85
#define     GUILIN_LITE2_LDO3_ACTIVE_1V90                GUILIN_LITE2_LDO1_ACTIVE_1V90
#define     GUILIN_LITE2_LDO3_ACTIVE_2V75                GUILIN_LITE2_LDO1_ACTIVE_2V75
#define     GUILIN_LITE2_LDO3_ACTIVE_2V80                GUILIN_LITE2_LDO1_ACTIVE_2V80
#define     GUILIN_LITE2_LDO3_ACTIVE_2V85                GUILIN_LITE2_LDO1_ACTIVE_2V85
#define     GUILIN_LITE2_LDO3_ACTIVE_2V90                GUILIN_LITE2_LDO1_ACTIVE_2V90
#define     GUILIN_LITE2_LDO3_ACTIVE_3V00                GUILIN_LITE2_LDO1_ACTIVE_3V00
#define     GUILIN_LITE2_LDO3_ACTIVE_3V10                GUILIN_LITE2_LDO1_ACTIVE_3V10
#define     GUILIN_LITE2_LDO3_ACTIVE_3V30                GUILIN_LITE2_LDO1_ACTIVE_3V30
//LDO4
#define     GUILIN_LITE2_LDO4_ACTIVE_1V20                GUILIN_LITE2_LDO1_ACTIVE_1V20
#define     GUILIN_LITE2_LDO4_ACTIVE_1V25                GUILIN_LITE2_LDO1_ACTIVE_1V25
#define     GUILIN_LITE2_LDO4_ACTIVE_1V60                GUILIN_LITE2_LDO1_ACTIVE_1V60
#define     GUILIN_LITE2_LDO4_ACTIVE_1V65                GUILIN_LITE2_LDO1_ACTIVE_1V65
#define     GUILIN_LITE2_LDO4_ACTIVE_1V70                GUILIN_LITE2_LDO1_ACTIVE_1V70
#define     GUILIN_LITE2_LDO4_ACTIVE_1V75                GUILIN_LITE2_LDO1_ACTIVE_1V75
#define     GUILIN_LITE2_LDO4_ACTIVE_1V80                GUILIN_LITE2_LDO1_ACTIVE_1V80
#define     GUILIN_LITE2_LDO4_ACTIVE_1V85                GUILIN_LITE2_LDO1_ACTIVE_1V85
#define     GUILIN_LITE2_LDO4_ACTIVE_1V90                GUILIN_LITE2_LDO1_ACTIVE_1V90
#define     GUILIN_LITE2_LDO4_ACTIVE_2V75                GUILIN_LITE2_LDO1_ACTIVE_2V75
#define     GUILIN_LITE2_LDO4_ACTIVE_2V80                GUILIN_LITE2_LDO1_ACTIVE_2V80
#define     GUILIN_LITE2_LDO4_ACTIVE_2V85                GUILIN_LITE2_LDO1_ACTIVE_2V85
#define     GUILIN_LITE2_LDO4_ACTIVE_2V90                GUILIN_LITE2_LDO1_ACTIVE_2V90
#define     GUILIN_LITE2_LDO4_ACTIVE_3V00                GUILIN_LITE2_LDO1_ACTIVE_3V00
#define     GUILIN_LITE2_LDO4_ACTIVE_3V10                GUILIN_LITE2_LDO1_ACTIVE_3V10
#define     GUILIN_LITE2_LDO4_ACTIVE_3V30                GUILIN_LITE2_LDO1_ACTIVE_3V30
//LDO5
#define     GUILIN_LITE2_LDO5_ACTIVE_1V20                GUILIN_LITE2_LDO1_ACTIVE_1V20
#define     GUILIN_LITE2_LDO5_ACTIVE_1V25                GUILIN_LITE2_LDO1_ACTIVE_1V25
#define     GUILIN_LITE2_LDO5_ACTIVE_1V60                GUILIN_LITE2_LDO1_ACTIVE_1V60
#define     GUILIN_LITE2_LDO5_ACTIVE_1V65                GUILIN_LITE2_LDO1_ACTIVE_1V65
#define     GUILIN_LITE2_LDO5_ACTIVE_1V70                GUILIN_LITE2_LDO1_ACTIVE_1V70
#define     GUILIN_LITE2_LDO5_ACTIVE_1V75                GUILIN_LITE2_LDO1_ACTIVE_1V75
#define     GUILIN_LITE2_LDO5_ACTIVE_1V80                GUILIN_LITE2_LDO1_ACTIVE_1V80
#define     GUILIN_LITE2_LDO5_ACTIVE_1V85                GUILIN_LITE2_LDO1_ACTIVE_1V85
#define     GUILIN_LITE2_LDO5_ACTIVE_1V90                GUILIN_LITE2_LDO1_ACTIVE_1V90
#define     GUILIN_LITE2_LDO5_ACTIVE_2V75                GUILIN_LITE2_LDO1_ACTIVE_2V75
#define     GUILIN_LITE2_LDO5_ACTIVE_2V80                GUILIN_LITE2_LDO1_ACTIVE_2V80
#define     GUILIN_LITE2_LDO5_ACTIVE_2V85                GUILIN_LITE2_LDO1_ACTIVE_2V85
#define     GUILIN_LITE2_LDO5_ACTIVE_2V90                GUILIN_LITE2_LDO1_ACTIVE_2V90
#define     GUILIN_LITE2_LDO5_ACTIVE_3V00                GUILIN_LITE2_LDO1_ACTIVE_3V00
#define     GUILIN_LITE2_LDO5_ACTIVE_3V10                GUILIN_LITE2_LDO1_ACTIVE_3V10
#define     GUILIN_LITE2_LDO5_ACTIVE_3V30                GUILIN_LITE2_LDO1_ACTIVE_3V30
//LDO6
#define     GUILIN_LITE2_LDO6_ACTIVE_1V20                GUILIN_LITE2_LDO1_ACTIVE_1V20
#define     GUILIN_LITE2_LDO6_ACTIVE_1V25                GUILIN_LITE2_LDO1_ACTIVE_1V25
#define     GUILIN_LITE2_LDO6_ACTIVE_1V60                GUILIN_LITE2_LDO1_ACTIVE_1V60
#define     GUILIN_LITE2_LDO6_ACTIVE_1V65                GUILIN_LITE2_LDO1_ACTIVE_1V65
#define     GUILIN_LITE2_LDO6_ACTIVE_1V70                GUILIN_LITE2_LDO1_ACTIVE_1V70
#define     GUILIN_LITE2_LDO6_ACTIVE_1V75                GUILIN_LITE2_LDO1_ACTIVE_1V75
#define     GUILIN_LITE2_LDO6_ACTIVE_1V80                GUILIN_LITE2_LDO1_ACTIVE_1V80
#define     GUILIN_LITE2_LDO6_ACTIVE_1V85                GUILIN_LITE2_LDO1_ACTIVE_1V85
#define     GUILIN_LITE2_LDO6_ACTIVE_1V90                GUILIN_LITE2_LDO1_ACTIVE_1V90
#define     GUILIN_LITE2_LDO6_ACTIVE_2V75                GUILIN_LITE2_LDO1_ACTIVE_2V75
#define     GUILIN_LITE2_LDO6_ACTIVE_2V80                GUILIN_LITE2_LDO1_ACTIVE_2V80
#define     GUILIN_LITE2_LDO6_ACTIVE_2V85                GUILIN_LITE2_LDO1_ACTIVE_2V85
#define     GUILIN_LITE2_LDO6_ACTIVE_2V90                GUILIN_LITE2_LDO1_ACTIVE_2V90
#define     GUILIN_LITE2_LDO6_ACTIVE_3V00                GUILIN_LITE2_LDO1_ACTIVE_3V00
#define     GUILIN_LITE2_LDO6_ACTIVE_3V10                GUILIN_LITE2_LDO1_ACTIVE_3V10
#define     GUILIN_LITE2_LDO6_ACTIVE_3V30                GUILIN_LITE2_LDO1_ACTIVE_3V30

//SLEEP mode
#define     GUILIN_LITE2_LDO_SLEEP_VOUT_MASK             (0xf)	//BIT[3:0] ldo vout for sleep mode

//LDO1
#define     GUILIN_LITE2_LDO1_SLEEP_1V20                (0x0)
#define     GUILIN_LITE2_LDO1_SLEEP_1V25                (0x1)
#define     GUILIN_LITE2_LDO1_SLEEP_1V60                (0x2)
#define     GUILIN_LITE2_LDO1_SLEEP_1V65                (0x3)
#define     GUILIN_LITE2_LDO1_SLEEP_1V70                (0x4)
#define     GUILIN_LITE2_LDO1_SLEEP_1V75                (0x5)
#define     GUILIN_LITE2_LDO1_SLEEP_1V80                (0x6)
#define     GUILIN_LITE2_LDO1_SLEEP_1V85                (0x7)
#define     GUILIN_LITE2_LDO1_SLEEP_1V90                (0x8)
#define     GUILIN_LITE2_LDO1_SLEEP_2V75                (0x9)
#define     GUILIN_LITE2_LDO1_SLEEP_2V80                (0xa)
#define     GUILIN_LITE2_LDO1_SLEEP_2V85                (0xb)
#define     GUILIN_LITE2_LDO1_SLEEP_2V90                (0xc)
#define     GUILIN_LITE2_LDO1_SLEEP_3V00                (0xd)
#define     GUILIN_LITE2_LDO1_SLEEP_3V10                (0xe)
#define     GUILIN_LITE2_LDO1_SLEEP_3V30                (0xf)
//LDO2
#define     GUILIN_LITE2_LDO2_SLEEP_1V20                GUILIN_LITE2_LDO1_SLEEP_1V20
#define     GUILIN_LITE2_LDO2_SLEEP_1V25                GUILIN_LITE2_LDO1_SLEEP_1V25
#define     GUILIN_LITE2_LDO2_SLEEP_1V60                GUILIN_LITE2_LDO1_SLEEP_1V60
#define     GUILIN_LITE2_LDO2_SLEEP_1V65                GUILIN_LITE2_LDO1_SLEEP_1V65
#define     GUILIN_LITE2_LDO2_SLEEP_1V70                GUILIN_LITE2_LDO1_SLEEP_1V70
#define     GUILIN_LITE2_LDO2_SLEEP_1V75                GUILIN_LITE2_LDO1_SLEEP_1V75
#define     GUILIN_LITE2_LDO2_SLEEP_1V80                GUILIN_LITE2_LDO1_SLEEP_1V80
#define     GUILIN_LITE2_LDO2_SLEEP_1V85                GUILIN_LITE2_LDO1_SLEEP_1V85
#define     GUILIN_LITE2_LDO2_SLEEP_1V90                GUILIN_LITE2_LDO1_SLEEP_1V90
#define     GUILIN_LITE2_LDO2_SLEEP_2V75                GUILIN_LITE2_LDO1_SLEEP_2V75
#define     GUILIN_LITE2_LDO2_SLEEP_2V80                GUILIN_LITE2_LDO1_SLEEP_2V80
#define     GUILIN_LITE2_LDO2_SLEEP_2V85                GUILIN_LITE2_LDO1_SLEEP_2V85
#define     GUILIN_LITE2_LDO2_SLEEP_2V90                GUILIN_LITE2_LDO1_SLEEP_2V90
#define     GUILIN_LITE2_LDO2_SLEEP_3V00                GUILIN_LITE2_LDO1_SLEEP_3V00
#define     GUILIN_LITE2_LDO2_SLEEP_3V10                GUILIN_LITE2_LDO1_SLEEP_3V10
#define     GUILIN_LITE2_LDO2_SLEEP_3V30                GUILIN_LITE2_LDO1_SLEEP_3V30
//LDO3
#define     GUILIN_LITE2_LDO3_SLEEP_1V20                GUILIN_LITE2_LDO1_SLEEP_1V20
#define     GUILIN_LITE2_LDO3_SLEEP_1V25                GUILIN_LITE2_LDO1_SLEEP_1V25
#define     GUILIN_LITE2_LDO3_SLEEP_1V60                GUILIN_LITE2_LDO1_SLEEP_1V60
#define     GUILIN_LITE2_LDO3_SLEEP_1V65                GUILIN_LITE2_LDO1_SLEEP_1V65
#define     GUILIN_LITE2_LDO3_SLEEP_1V70                GUILIN_LITE2_LDO1_SLEEP_1V70
#define     GUILIN_LITE2_LDO3_SLEEP_1V75                GUILIN_LITE2_LDO1_SLEEP_1V75
#define     GUILIN_LITE2_LDO3_SLEEP_1V80                GUILIN_LITE2_LDO1_SLEEP_1V80
#define     GUILIN_LITE2_LDO3_SLEEP_1V85                GUILIN_LITE2_LDO1_SLEEP_1V85
#define     GUILIN_LITE2_LDO3_SLEEP_1V90                GUILIN_LITE2_LDO1_SLEEP_1V90
#define     GUILIN_LITE2_LDO3_SLEEP_2V75                GUILIN_LITE2_LDO1_SLEEP_2V75
#define     GUILIN_LITE2_LDO3_SLEEP_2V80                GUILIN_LITE2_LDO1_SLEEP_2V80
#define     GUILIN_LITE2_LDO3_SLEEP_2V85                GUILIN_LITE2_LDO1_SLEEP_2V85
#define     GUILIN_LITE2_LDO3_SLEEP_2V90                GUILIN_LITE2_LDO1_SLEEP_2V90
#define     GUILIN_LITE2_LDO3_SLEEP_3V00                GUILIN_LITE2_LDO1_SLEEP_3V00
#define     GUILIN_LITE2_LDO3_SLEEP_3V10                GUILIN_LITE2_LDO1_SLEEP_3V10
#define     GUILIN_LITE2_LDO3_SLEEP_3V30                GUILIN_LITE2_LDO1_SLEEP_3V30
//LDO4
#define     GUILIN_LITE2_LDO4_SLEEP_1V20                GUILIN_LITE2_LDO1_SLEEP_1V20
#define     GUILIN_LITE2_LDO4_SLEEP_1V25                GUILIN_LITE2_LDO1_SLEEP_1V25
#define     GUILIN_LITE2_LDO4_SLEEP_1V60                GUILIN_LITE2_LDO1_SLEEP_1V60
#define     GUILIN_LITE2_LDO4_SLEEP_1V65                GUILIN_LITE2_LDO1_SLEEP_1V65
#define     GUILIN_LITE2_LDO4_SLEEP_1V70                GUILIN_LITE2_LDO1_SLEEP_1V70
#define     GUILIN_LITE2_LDO4_SLEEP_1V75                GUILIN_LITE2_LDO1_SLEEP_1V75
#define     GUILIN_LITE2_LDO4_SLEEP_1V80                GUILIN_LITE2_LDO1_SLEEP_1V80
#define     GUILIN_LITE2_LDO4_SLEEP_1V85                GUILIN_LITE2_LDO1_SLEEP_1V85
#define     GUILIN_LITE2_LDO4_SLEEP_1V90                GUILIN_LITE2_LDO1_SLEEP_1V90
#define     GUILIN_LITE2_LDO4_SLEEP_2V75                GUILIN_LITE2_LDO1_SLEEP_2V75
#define     GUILIN_LITE2_LDO4_SLEEP_2V80                GUILIN_LITE2_LDO1_SLEEP_2V80
#define     GUILIN_LITE2_LDO4_SLEEP_2V85                GUILIN_LITE2_LDO1_SLEEP_2V85
#define     GUILIN_LITE2_LDO4_SLEEP_2V90                GUILIN_LITE2_LDO1_SLEEP_2V90
#define     GUILIN_LITE2_LDO4_SLEEP_3V00                GUILIN_LITE2_LDO1_SLEEP_3V00
#define     GUILIN_LITE2_LDO4_SLEEP_3V10                GUILIN_LITE2_LDO1_SLEEP_3V10
#define     GUILIN_LITE2_LDO4_SLEEP_3V30                GUILIN_LITE2_LDO1_SLEEP_3V30
//LDO5
#define     GUILIN_LITE2_LDO5_SLEEP_1V20                GUILIN_LITE2_LDO1_SLEEP_1V20
#define     GUILIN_LITE2_LDO5_SLEEP_1V25                GUILIN_LITE2_LDO1_SLEEP_1V25
#define     GUILIN_LITE2_LDO5_SLEEP_1V60                GUILIN_LITE2_LDO1_SLEEP_1V60
#define     GUILIN_LITE2_LDO5_SLEEP_1V65                GUILIN_LITE2_LDO1_SLEEP_1V65
#define     GUILIN_LITE2_LDO5_SLEEP_1V70                GUILIN_LITE2_LDO1_SLEEP_1V70
#define     GUILIN_LITE2_LDO5_SLEEP_1V75                GUILIN_LITE2_LDO1_SLEEP_1V75
#define     GUILIN_LITE2_LDO5_SLEEP_1V80                GUILIN_LITE2_LDO1_SLEEP_1V80
#define     GUILIN_LITE2_LDO5_SLEEP_1V85                GUILIN_LITE2_LDO1_SLEEP_1V85
#define     GUILIN_LITE2_LDO5_SLEEP_1V90                GUILIN_LITE2_LDO1_SLEEP_1V90
#define     GUILIN_LITE2_LDO5_SLEEP_2V75                GUILIN_LITE2_LDO1_SLEEP_2V75
#define     GUILIN_LITE2_LDO5_SLEEP_2V80                GUILIN_LITE2_LDO1_SLEEP_2V80
#define     GUILIN_LITE2_LDO5_SLEEP_2V85                GUILIN_LITE2_LDO1_SLEEP_2V85
#define     GUILIN_LITE2_LDO5_SLEEP_2V90                GUILIN_LITE2_LDO1_SLEEP_2V90
#define     GUILIN_LITE2_LDO5_SLEEP_3V00                GUILIN_LITE2_LDO1_SLEEP_3V00
#define     GUILIN_LITE2_LDO5_SLEEP_3V10                GUILIN_LITE2_LDO1_SLEEP_3V10
#define     GUILIN_LITE2_LDO5_SLEEP_3V30                GUILIN_LITE2_LDO1_SLEEP_3V30
//LDO6
#define     GUILIN_LITE2_LDO6_SLEEP_1V20                GUILIN_LITE2_LDO1_SLEEP_1V20
#define     GUILIN_LITE2_LDO6_SLEEP_1V25                GUILIN_LITE2_LDO1_SLEEP_1V25
#define     GUILIN_LITE2_LDO6_SLEEP_1V60                GUILIN_LITE2_LDO1_SLEEP_1V60
#define     GUILIN_LITE2_LDO6_SLEEP_1V65                GUILIN_LITE2_LDO1_SLEEP_1V65
#define     GUILIN_LITE2_LDO6_SLEEP_1V70                GUILIN_LITE2_LDO1_SLEEP_1V70
#define     GUILIN_LITE2_LDO6_SLEEP_1V75                GUILIN_LITE2_LDO1_SLEEP_1V75
#define     GUILIN_LITE2_LDO6_SLEEP_1V80                GUILIN_LITE2_LDO1_SLEEP_1V80
#define     GUILIN_LITE2_LDO6_SLEEP_1V85                GUILIN_LITE2_LDO1_SLEEP_1V85
#define     GUILIN_LITE2_LDO6_SLEEP_1V90                GUILIN_LITE2_LDO1_SLEEP_1V90
#define     GUILIN_LITE2_LDO6_SLEEP_2V75                GUILIN_LITE2_LDO1_SLEEP_2V75
#define     GUILIN_LITE2_LDO6_SLEEP_2V80                GUILIN_LITE2_LDO1_SLEEP_2V80
#define     GUILIN_LITE2_LDO6_SLEEP_2V85                GUILIN_LITE2_LDO1_SLEEP_2V85
#define     GUILIN_LITE2_LDO6_SLEEP_2V90                GUILIN_LITE2_LDO1_SLEEP_2V90
#define     GUILIN_LITE2_LDO6_SLEEP_3V00                GUILIN_LITE2_LDO1_SLEEP_3V00
#define     GUILIN_LITE2_LDO6_SLEEP_3V10                GUILIN_LITE2_LDO1_SLEEP_3V10
#define     GUILIN_LITE2_LDO6_SLEEP_3V30                GUILIN_LITE2_LDO1_SLEEP_3V30


#define     GUILIN_LITE2_VBUCK1_ACTIVE_VOUT_REG      (0x20)
#define     GUILIN_LITE2_VBUCK1_SLEEP_VOUT_REG		(0x21)

#define     GUILIN_LITE2_VBUCK1_FSM_REG1			    (0x22)
#define     GUILIN_LITE2_VBUCK1_FSM_REG2			    (0x23)
#define     GUILIN_LITE2_VBUCK1_FSM_REG3			    (0x24)
#define     GUILIN_LITE2_VBUCK1_FSM_REG4			    (0x25)
#define     GUILIN_LITE2_VBUCK1_FSM_REG5			    (0x26)
#define     GUILIN_LITE2_VBUCK1_FSM_REG6			    (0x27)
#define     GUILIN_LITE2_VBUCK1_FSM_REG7			    (0x28)
#define     GUILIN_LITE2_VBUCK1_FSM_REG8			    (0x29)
#define     GUILIN_LITE2_VBUCK1_FSM_REG9			    (0x2A)

#define	    GUILIN_LITE2_VBUCK1_ENABLE_REG		    GUILIN_LITE2_VBUCK1_ACTIVE_VOUT_REG
#define     GUILIN_LITE2_VBUCK1_SLEEP_MODE_REG		GUILIN_LITE2_VBUCK1_FSM_REG1


#define		GUILIN_LITE2_CONTAIN_VBUCK_EN_BIT(x)		(x==GUILIN_LITE2_VBUCK1_ENABLE_REG)
#define		GUILIN_LITE2_CONTAIN_VBUCK_ACTIVE_VOUT_BIT(x)		GUILIN_LITE2_CONTAIN_VBUCK_EN_BIT(x)
#define		GUILIN_LITE2_CONTAIN_VBUCK_SLEEP_VOUT_BIT(x)	(x==GUILIN_LITE2_VBUCK1_SLEEP_VOUT_REG)

#define		GUILIN_LITE2_CONTAIN_VBUCK_SLEEP_MODE_BIT(x) 	(x==GUILIN_LITE2_VBUCK1_SLEEP_MODE_REG)

#define		GUILIN_LITE2_VBUCK_ENABLE_MASK			(0x1<<7)
#define		GUILIN_LITE2_VBUCK_SLEEP_MODE_MASK		(0x3<<3)

//00	:	BUCK OFF
//01	:	BUCK ACTIVE mode
//10	:	BUCK SLEEP mode
//11	:	BUCK NORMAL mode
#define		GUILIN_LITE2_VBUCK_OFF			(0x0 <<3)
#define		GUILIN_LITE2_VBUCK_ACTIVE_SLEEP	(0x1 <<3)
#define		GUILIN_LITE2_VBUCK_SLEEP			(0x2 <<3)
#define		GUILIN_LITE2_VBUCK_ACTIVE		(0x3 <<3)
#define		GUILIN_LITE2_VBUCK_SKIP_MODE		(0x1 <<5)

#define		GUILIN_LITE2_CONTAIN_LDO_EN_BIT(x) 		(x==GUILIN_LITE2_LDO1_ENABLE_REG|| \
											x==GUILIN_LITE2_LDO2_ENABLE_REG|| \
											x==GUILIN_LITE2_LDO3_ENABLE_REG|| \
											x==GUILIN_LITE2_LDO4_ENABLE_REG|| \
											x==GUILIN_LITE2_LDO5_ENABLE_REG|| \
											x==GUILIN_LITE2_LDO6_ENABLE_REG)

#define		GUILIN_LITE2_CONTAIN_LDO_ACTIVE_VOUT_BIT(x)	GUILIN_LITE2_CONTAIN_LDO_EN_BIT(x)


#define		GUILIN_LITE2_CONTAIN_LDO_SLEEP_MODE_BIT(x) 		(x==GUILIN_LITE2_LDO1_SLEEP_MODE_REG|| \
												x==GUILIN_LITE2_LDO2_SLEEP_MODE_REG|| \
												x==GUILIN_LITE2_LDO3_SLEEP_MODE_REG|| \
												x==GUILIN_LITE2_LDO4_SLEEP_MODE_REG|| \
												x==GUILIN_LITE2_LDO5_SLEEP_MODE_REG|| \
												x==GUILIN_LITE2_LDO6_SLEEP_MODE_REG)
												
#define		GUILIN_LITE2_CONTAIN_LDO_SLEEP_VOUT_BIT(x)	GUILIN_LITE2_CONTAIN_LDO_SLEEP_MODE_BIT(x)

#define		GUILIN_LITE2_LDO_ENABLE_MASK				(0x1<<7)
#define		GUILIN_LITE2_LDO_SLEEP_MODE_MASK			(0x3<<4)

//00	:	LDO OFF
//01	:	Reserve
//10	:	LDO SLEEP mode
//11	:	LDO NORMAL mode
#define     GUILIN_LITE2_LDO_OFF                      (0x0 <<4)
#define     GUILIN_LITE2_LDO_SLEEP                    (0x2 <<4)
#define     GUILIN_LITE2_LDO_ACTIVE                   (0x3 <<4)


//BASE_PAGE_ADDR=0xE2 , BIT[3:0]
#define		GUILIN_LITE2_RESET_DISCHARGE_REG			 (0xe2)
#define		GUILIN_LITE2_RESET_DISCHARGE_MASK		 (0xf)

#define		GUILIN_LITE2_FAULT_WU_REG				  (0xe7)
#define		GUILIN_LITE2_FAULT_WU_BIT				  (0x1<<1)
#define		GUILIN_LITE2_FAULT_WU_ENABLE_BIT			  (0x1<<0)

#define		GUILIN_LITE2_RESET_REG				    (0x0d)
#define		GUILIN_LITE2_SW_PDOWN_BIT				(0x1<<5)
#define		GUILIN_LITE2_RESET_PMIC_BIT			    (0x1<<6)

#define		GUILIN_LITE2_PWR_HOLD_REG				GUILIN_LITE2_RESET_REG
#define		GUILIN_LITE2_PWR_HOLD_BIT				(0x1<<7)

#define 	GUILIN_LITE2_BUCK_ENABLE                   (0x1<<7)
#define 	GUILIN_LITE2_LDO_ENABLE                    (0x1<<7)

#define		GUILIN_LITE2_I2C_CotlAddr		     I2CRegBaseAddress

/* GuilinLite2 I2c address*/
#define GUILIN_LITE2_BASE_SLAVE_WRITE_ADDR		     0x60
#define GUILIN_LITE2_BASE_SLAVE_READ_ADDR	         0x61

#define GUILIN_LITE2_POWER_SLAVE_WRITE_ADDR		     0x62
#define GUILIN_LITE2_POWER_SLAVE_READ_ADDR	         0x63

typedef enum
{
    GUILIN_LITE2_BASE_Reg,
    GUILIN_LITE2_POWER_Reg,
}GuilinLite2_Reg_Type;

typedef enum {
	//INT ENABLE REG 1 addr=0x09
	GUILIN_LITE2_ONKEY_INT=0,
	GUILIN_LITE2_EXTON1_INT,
	GUILIN_LITE2_EXTON2_INT,
	GUILIN_LITE2_RTC_ALARM_INT,
	GUILIN_LITE2_BAT_INT,
} GUILIN_LITE2_INTC ;

#define GUILIN_LITE2_INTC_MAX 7
#define GUILIN_LITE2_INTC_TO_STATUS_BIT(intc) (0x01<<intc)
#define GUILIN_LITE2_INTC_TO_ENABLE_BIT(intc) (1<<intc)
#define GUILIN_LITE2_INTC_TO_ENABLE_REG(intc) GUILIN_LITE2_INT_ENABLE_REG1

/*===========================================================================

                          INTERNAL FUNCTION DECLARATIONS

===========================================================================*/


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      GuilinLite2Read                                                       */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function Read GuilinLite2 by PI2C interface.                      */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
int GuilinLite2Read( GuilinLite2_Reg_Type guilin_lite_reg_type, unsigned char reg, unsigned char *value );


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      GuilinLite2Wite                                                       */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function Write GuilinLite2 by PI2C interface.                     */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
int GuilinLite2Write( GuilinLite2_Reg_Type guilin_lite_reg_type, unsigned char reg, unsigned char value );

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      GuilinLite2ClkInit                                                    */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function initialize the Ustia clock.                         */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      meas_val                            The 12bit ADC value          */
/*                                                                       */
/*************************************************************************/
void GuilinLite2ClkInit( void );
void GuilinLite2_Ldo_6_set(BOOL OnOff);
void GuilinLite2_Ldo_6_set_2_8(void);
void GuilinLite2_Ldo_3_set_1_8(void);
void GuilinLite2_Ldo_3_set_3_0(void);
void GuilinLite2_Ldo_3_set(BOOL OnOff);
void GuilinLite2_VBUCK1_CFG(UINT8 value);
int GuilinLite2_VBUCK_Set_Enable(unsigned char reg, unsigned char enable);
int GuilinLite2_VBUCK_Set_Slpmode(unsigned char reg, unsigned char mode);
int GuilinLite2_VBUCK_Set_VOUT(unsigned char reg, unsigned char value);
int GuilinLite2_LDO_Set_Enable(unsigned char reg, unsigned char enable);
int GuilinLite2_LDO_Set_Slpmode(unsigned char reg, unsigned char mode);
int GuilinLite2_LDO_Set_VOUT(unsigned char reg, unsigned char value);

#endif /* _GUILIN_LITE2_H_        */
