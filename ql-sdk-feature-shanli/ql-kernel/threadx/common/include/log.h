#ifndef __LOG_H__
#define __LOG_H__

#define	LOG_EMERG	"<0>"	/* system is unusable				*/
#define	LOG_ALERT	"<1>"	/* action must be taken immediately	*/
#define	LOG_CRIT	"<2>"	/* critical conditions				*/
#define	LOG_ERR		"<3>"	/* error conditions					*/
#define	LOG_WARNING	"<4>"	/* warning conditions				*/
#define	LOG_NOTICE	"<5>"	/* normal but significant condition	*/
#define	LOG_INFO	"<6>"	/* informational					*/
#define	LOG_DEBUG	"<7>"	/* debug-level messages				*/

#define LOG_EMERG_VALUE 	0
#define LOG_ALERT_VALUE		1
#define LOG_CRIT_VALUE		2
#define LOG_ERR_VALUE		3
#define LOG_WARNING_VALUE	4
#define LOG_NOTICE_VALUE	5
#define LOG_INFO_VALUE		6
#define LOG_DEBUG_VALUE		7

#define LOG_OUTPUT_MEMLOG	0
#define LOG_OUTPUT_NONE		1
#define LOG_OUTPUT_UART		2
#define LOG_OUTPUT_ACAT		3
#define LOG_OUTPUT_NVM		4

void log_dump(const unsigned char* ptr, unsigned int length);
void log_printf(const char* fmt, ...);
void log_flush(void);
void log_init(void);

void log_set_trace_level(int level);
void log_set_module_level(const char* module, int level);

#endif

