#ifndef _LCD_LOG_H_
#define _LCD_LOG_H_

#include "quec_debug.h"

#define LCD_LOG_RETURN_LINE "\r\n"
#define LCDLOG_GLOBAL_LEVEL 100 

enum {
	LCDLOG_LEVEL_ERROR		= 100,
	LCDLOG_LEVEL_WARNING	= 200,
	LCDLOG_LEVEL_INFO		= 300,
	LCDLOG_LEVEL_DEBUG		= 400,
	LCDLOG_LEVEL_VERBOSE	= 500
};

#ifndef LCD_LOG_PRINT
#define LCD_LOG_PRINT(logLevel, levelName, format, ...) 										\
	do {																						\
		if (logLevel <= LCDLOG_GLOBAL_LEVEL) {													\
			UARTLogPrintf_Extend("[lcd]%s:" levelName ": " format LCD_LOG_RETURN_LINE, __func__, ##__VA_ARGS__);\
		}																						\
	} while(0)
#endif


#define LCDLOGE(fmt, ...) LCD_LOG_PRINT(LCDLOG_LEVEL_ERROR, "err", fmt, ##__VA_ARGS__)
#define LCDLOGW(fmt, ...) LCD_LOG_PRINT(LCDLOG_LEVEL_WARNING, "warning", fmt, ##__VA_ARGS__)
#define LCDLOGI(fmt, ...) LCD_LOG_PRINT(LCDLOG_LEVEL_INFO, "info", fmt, ##__VA_ARGS__)
#define LCDLOGD(fmt, ...) LCD_LOG_PRINT(LCDLOG_LEVEL_DEBUG, "debug", fmt, ##__VA_ARGS__)
#define LCDLOGV(fmt, ...) LCD_LOG_PRINT(LCDLOG_LEVEL_VERBOSE, "debug", fmt, ##__VA_ARGS__)

#endif /*_LCD_LOG_H_*/
