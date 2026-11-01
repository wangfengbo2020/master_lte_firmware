 /*============================================================================================
     Copyright(c) 2018 Quectel Wierless Solution,Co.,Ltd. All Rights Reserved.
     Quectel Wireless Solution Proprietary and Confidential.
 ============================================================================*/

#ifndef __GPS_DEBUG_H__
#define __GPS_DEBUG_H__

#include "quec_debug.h"

#ifdef __cplusplus
extern "C" {
#endif

extern int gps_get_debug_level(void);

#define GPS_DEBUG   1

enum {
	LOG_LEVEL_ERROR		= 100,
	LOG_LEVEL_DEBUG	    = 200,
	LOG_LEVEL_INFO		= 300,
};
#define LOG_GLOBAL_LEVEL gps_get_debug_level()
#define LOG_PRINT(logLevel, levelName, format, ...) 										\
do {                                                                                        \
    if (logLevel <= LOG_GLOBAL_LEVEL) {                                                  \
        quec_log("[gnss][%d][%s]:" levelName ": " format,__LINE__, __func__, ##__VA_ARGS__);\
    }                                                                                       \
} while(0)

// ToDo Porting: Please use your platform API to implement it.
// Platform Log API
#if GPS_DEBUG
#define GPS_LOGI(fmt,...)   LOG_PRINT(LOG_LEVEL_INFO, "info",fmt, ##__VA_ARGS__)
#define GPS_LOGD(fmt,...)   LOG_PRINT(LOG_LEVEL_DEBUG, "waring",fmt, ##__VA_ARGS__)
#define GPS_LOGE(fmt,...)   LOG_PRINT(LOG_LEVEL_ERROR, "err",fmt, ##__VA_ARGS__)
#else
#define GPS_LOGI(fmt,...)
#define GPS_LOGD(fmt,...)
#define GPS_LOGE(fmt,...)
#endif

#define  D    GPS_LOGI

#define GPS_SUCCESS_LOG(X)     GPS_LOGI("%s %s", X, ((success) ? "success" : "fail"))

/*
#ifndef GPS_Assert
#define GPS_Assert(X)                                           \
    do                                                          \
    {                                                           \
        if(!(X))                                                \
        {                                                       \
            GPS_LOGE("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");       \
            GPS_LOGE("GPS_Assert Fail: %s", #X);                \
            GPS_LOGE("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");       \
            vTaskDelay(1000);                                   \
            while(1) {}                                         \
        }                                                       \
    } while(0)
#endif
*/

#ifndef GPS_Require_Noerr_Action
#define GPS_Require_Noerr_Action(X, GOTO_LABEL, Fun)            \
    do {                                                        \
        if(!(X)) {                                              \
            { GPS_LOGI("%s fail", Fun); }                       \
            goto GOTO_LABEL;                                    \
        } else {                                                \
            { GPS_LOGI("%s success", Fun); }                    \
        }                                                       \
    } while(0)
#endif

#ifndef GPS_Require_Noerr
#define GPS_Require_Noerr(X, GOTO_LABEL)                        \
    do {                                                        \
        if(!(X)) {                                              \
            goto GOTO_LABEL;                                    \
        }                                                       \
    } while(0)
#endif


#ifndef GPS_MAIN_LOG
#define GPS_MAIN_LOG(fmt,arg...)                                \
    do                                                          \
    {                                                           \
        GPS_LOGI("##################################################"); \
        GPS_LOGI(fmt, ##arg);                                   \
        GPS_LOGI("##################################################"); \
    } while(0)
#endif

#ifdef __cplusplus
}
#endif

#endif
