/*============================================================================================
	Copyright(c) 2018 Quectel Wierless Solution,Co.,Ltd. All Rights Reserved.
	Quectel Wireless Solution Proprietary and Confidential.
============================================================================*/

#ifndef __GPS_CHANNEL_H__
#define __GPS_CHANNEL_H__

#ifdef __cplusplus
extern "C" {
#endif

#define YS_GNSS_LDO_PIN_NUM GPIO_PIN_5
#define NTP_SERVER_DOMAIN "ntp.aliyun.com\0"

typedef enum {
    CHANNEL_TYPE_UART = 0,
    CHANNEL_TYPE_SPI,
    CHANNEL_TYPE_I2C
} GPS_CHANNEL_TYPE;
    
typedef  void (*gnss_event_callback) (void *p);

typedef struct {
   char     (*m_com_init)                  (void);
   unsigned int (*m_com_get_byte_status)       (void);
   unsigned int (*m_com_get_byte_buffer)       (char *buf, unsigned int length);
   unsigned int (*m_com_put_byte_buffer)       (char *buf, unsigned int length);
   void     (*m_com_put_byte_complete)     (char data);
   void     (*m_com_purge_fifo)            (void);
   void     (*m_com_set_baudrate)          (int baud_rate);
   char     (*m_com_deinit)                (void);
   void     (*m_gpio_set_level)            (unsigned int pin_num ,unsigned int level);
   void     (*m_com_event_register_cb)     (gnss_event_callback cb);
   unsigned int (*m_get_rtc_time)          (void); 
   int          (*m_nw_act)                      (void);
   int          (*m_nw_deact)                      (void);
   int          (*m_get_rtc_status)              (void);
   int          (*m_get_netif_status)            (void);
   gnss_event_callback  m_event_callback;
} g_gps_channel_t;

extern g_gps_channel_t g_gps_channel;
typedef struct quec_gnss_gpio_struct
{
   int pwr_en;
   int rst;
   int blk;
   int clock;
   int tx;
   int rx;
}quec_gps_gpio_struct_t;
extern quec_gps_gpio_struct_t gps_gpio_pin;

#define GPS_COM_Init                          g_gps_channel.m_com_init
#define GPS_COM_GetByteStatus                 g_gps_channel.m_com_get_byte_status
#define GPS_COM_GetByte_Buffer(buf,length)    g_gps_channel.m_com_get_byte_buffer(buf, length)
#define GPS_COM_PutByte_Buffer(buf,length)    g_gps_channel.m_com_put_byte_buffer(buf, length)
#define GPS_COM_PutByte_Complete(data)        g_gps_channel.m_com_put_byte_complete(data)
#define GPS_COM_PurgeFIFO                     g_gps_channel.m_com_purge_fifo
#define GPS_COM_SetBaudRate(baud_rate)        g_gps_channel.m_com_set_baudrate(baud_rate)
#define GPS_COM_Deinit                        g_gps_channel.m_com_deinit
#define GPS_GPIO_Set_Level(pin_num,level)     g_gps_channel.m_gpio_set_level(pin_num,level)
#define GPS_COM_register_cb(cb)               g_gps_channel.m_com_event_register_cb(cb)
#define GPS_GET_RTC_TIME                      g_gps_channel.m_get_rtc_time
#define GPS_NW_ACT                            g_gps_channel.m_nw_act
#define GPS_GET_RTC_STATUS                    g_gps_channel.m_get_rtc_status
#define GPS_GET_NETIF_STATUS                  g_gps_channel.m_get_netif_status
#define GPS_NW_DEACT                          g_gps_channel.m_nw_deact 

char    gps_channel_init(void);
char gps_get_channel_type(void);
void gps_delay_ms(unsigned int ms);


typedef struct quec_gnss_monitor_struct
{
	volatile unsigned int monitor_write_flash_cnt;
	volatile unsigned int monitor_agps_req_cnt;
	unsigned int agps_req_time[24];
	volatile unsigned int monitor_apflash_req_cnt;
	unsigned int apflash_req_time[24];
	
}quec_gnss_monitor_struct_t;
extern quec_gnss_monitor_struct_t quec_gnss_monitor;


#ifdef __cplusplus
}
#endif

#endif //__GPS_CHANNEL_H__

