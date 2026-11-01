#include "alipay_common.h"
#include "vendor_os.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "hal_asr.h"


/*设置手表时间，设置之后要求及时生效，并且通过 alipay_get_timestamp 接口获取的是修改后的时间
 * 注:UTC时间戳，从1970开始的
 * @param [in] timestamp_s  时间戳，单位为s
 * @return 
 */
EXTERNC void alipay_set_system_time(PARAM_IN int32_t timestamp_s)
{
    h_rtc rtc_time;
    memset(&rtc_time, 0, sizeof(h_rtc));
    Hal_seconds_to_time(timestamp_s, &rtc_time);
    Hal_Rtc_Settime(&rtc_time);
}


/**
* 获取一个非0的随机数
*/
int alipay_rand(void)
{
    int ret_val = 0;
    uint32_t retry_time = 20;

    do {
        ret_val = rand();
        retry_time--;
    } while((ret_val == 0) && (retry_time > 0));

    return ret_val;
}

/**
* 设定随机数种子
*/
void alipay_srand(unsigned int seed)
{
    srand(seed);
}

/*
* 获取系统当前时间
* month 为1表示1月，day 为1表示1号，year为2018表示2018年。
* hour 取值0-23.  min取值0-59. second取值0-59.
*/
void alipay_iot_get_local_time(alipay_iot_local_time *ltime)
{
    h_rtc timeinfo;
    Hal_Rtc_Gettime(&timeinfo);

    ltime->year = timeinfo.tm_year;
    ltime->month = timeinfo.tm_mon;
    ltime->day = timeinfo.tm_mday;
    ltime->hour = timeinfo.tm_hour;
    ltime->minute = timeinfo.tm_min;
    ltime->second = timeinfo.tm_sec;
    ltime->isdst = 0;
}
