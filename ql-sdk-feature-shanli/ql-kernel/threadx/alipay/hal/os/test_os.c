#include "alipay_common.h"
#include "vendor_os.h"
#include <stdio.h>

#include "UART.h"
#define ALIPAY_TEST_LOG(fmt,args...)  do {CPUartLogPrintf("[ali_os]"fmt, ##args);}while(0)
extern void alipay_task_sleep(uint32_t ms);
extern unsigned int alipay_get_timestamp(void);

#define MEMP_NUM_NETCONN 32
#define FD_SETSIZE    MEMP_NUM_NETCONN

typedef struct fd_set {
  unsigned char fd_bits [(FD_SETSIZE * 2 + 7)/8];
} fd_set;

struct timeval {
    long    tv_sec;     /* seconds */
    long    tv_usec;    /* and microseconds */
};

int lwip_select(int maxfdp1, fd_set *readset, fd_set *writeset, fd_set *exceptset, struct timeval *timeout);

#define select(a,b,c,d,e)     lwip_select(a,b,c,d,e)

//#define ALIPAY_TEST_LOG(format, ...) \
//    printf("[ALIPAY_TEST]"#format"\n", ##__VA_ARGS__)

#define TEST_CASE(func_name) \
    bool TEST_##func_name()

#define TEST_TAG ALIPAY_TEST_LOG("[ALIPAY_TEST]===================TEST:[%s]\n", __func__)

#define TEST_IT(func)                                         \
do {                                                            \
    ALIPAY_TEST_LOG("==============BEGIN %s", #func);           \
    ret = TEST_##func(); \
    if (ret == true) ALIPAY_TEST_LOG("SUCCESS: %s", #func); \
    else ALIPAY_TEST_LOG("FAILURE: %s",#func); \
    ALIPAY_TEST_LOG("==============END %s", #func); \
} while(0)


TEST_CASE(timestamp){
    TEST_TAG;
	alipay_iot_local_time local_time;
    alipay_iot_get_local_time(&local_time);
	 ALIPAY_TEST_LOG("1local_time:%d-%d-%d -- %d:%d:%d",local_time.year,local_time.month,local_time.day,local_time.hour,local_time.minute,local_time.second);
    uint32_t time_s = alipay_get_timestamp();
    ALIPAY_TEST_LOG("alipay_get_timestamp-[%d]",time_s);
    if(time_s < 1694598755){
        ALIPAY_TEST_LOG("alipay_get_timestamp time is invalid");
        return false;
    }

    alipay_set_system_time(time_s+60*60);
	alipay_iot_get_local_time(&local_time);
	 ALIPAY_TEST_LOG("2local_time:%d-%d-%d -- %d:%d:%d",local_time.year,local_time.month,local_time.day,local_time.hour,local_time.minute,local_time.second);
    uint32_t time_adjust = alipay_get_timestamp();
    ALIPAY_TEST_LOG("alipay_get_timestamp-adjust[%d-%d]",time_s,time_adjust);
    if(time_adjust < (time_s+60*60)){
        ALIPAY_TEST_LOG("alipay_set_system_time is invalid");
        return false;
    }

#if 0
    uint32_t compile_timestamp = alipay_get_compile_timestamp();
    ALIPAY_TEST_LOG("alipay_get_compile_timestamp-[%d]",compile_timestamp);
    if(compile_timestamp < 1694598755){
        ALIPAY_TEST_LOG("alipay_get_compile_timestamp time is invalid");
        return false;
    }
	
    //sleep 5s，需要厂商根据自己平台实现
    struct timeval tval;
    tval.tv_sec = 5;
    tval.tv_usec = 0;
    select(0, NULL, NULL, NULL, &tval);

    uint32_t compile_timestamp1 = alipay_get_compile_timestamp();
    ALIPAY_TEST_LOG("alipay_get_compile_timestamp-s[%d]",compile_timestamp1);
    if((compile_timestamp1 != compile_timestamp)){
        ALIPAY_TEST_LOG("alipay_get_compile_timestamp time is invalid");
        return false;
    }
#endif
	
	//sleep 5s，需要厂商根据自己平台实现
	alipay_task_sleep(5000);

    //alipay_iot_local_time local_time;
    alipay_iot_get_local_time(&local_time);
	 ALIPAY_TEST_LOG("3local_time:%d-%d-%d -- %d:%d:%d",local_time.year,local_time.month,local_time.day,local_time.hour,local_time.minute,local_time.second);

    if(local_time.year<2023){
        ALIPAY_TEST_LOG("alipay_iot_get_local_time year is invalid");
        return false;
    }
    if(local_time.month<1||local_time.month>12){
        ALIPAY_TEST_LOG("alipay_iot_get_local_time month is invalid");
        return false;
    }
    if(local_time.day<1||local_time.day>31){
        ALIPAY_TEST_LOG("alipay_iot_get_local_time day is invalid");
        return false;
    }
    if(local_time.hour>23){
        ALIPAY_TEST_LOG("alipay_iot_get_local_time hour is invalid");
        return false;
    }
    if(local_time.minute>59){
        ALIPAY_TEST_LOG("alipay_iot_get_local_time minute is invalid");
        return false;
    }
    if(local_time.second>59){
        ALIPAY_TEST_LOG("alipay_iot_get_local_time second is invalid");
        return false;
    }
    
    return true;
}

TEST_CASE(rand){
    TEST_TAG;
    int num = alipay_rand();
    ALIPAY_TEST_LOG("alipay_rand num is %d", num);
    if(num == 0){
        ALIPAY_TEST_LOG("alipay_rand num is invalid");
        return false;
    }
    return true;
}

int test_os(void){
    bool ret;
	
    TEST_IT(timestamp);
    if(ret == false){
        return -1;
    }
	
    TEST_IT(rand);
    if(ret == false){
        return -2;
    }
    return 0;
}
