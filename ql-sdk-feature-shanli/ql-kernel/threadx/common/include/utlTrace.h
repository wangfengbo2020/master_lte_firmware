/*****************************************************************************
 * Utility Library
 *
 * Tracing utilities header file
 *
 *****************************************************************************/

#ifndef _UTL_TRACE_INCLUDED
#define _UTL_TRACE_INCLUDED

#include <stdio.h>
#include "diag.h"
#ifdef LWIP_IPNETBUF_SUPPORT
#include "UART.h"
#endif
#include "utils.h"
#include "platform.h"

//typedef unsigned long UINT32;


/*--- Macros ----------------------------------------------------------------*/

/*--- the following C99-compliant varargs macro is meant to be used inside
      "utlTrace()" macros as follows:

         utlTrace(myTraceString,
                  utlPrintTrace("my trace message, value=%d\n", value);
                 );

      This allows one to easily upgrade the trace library to allow trace
      output redirection.
*/

void PRINTNONE(char *args,...);  //modify by Alan
#define utlPrintTrace(...) PRINTNONE(__VA_ARGS__)
#define utlTrace(name, source_code) {source_code}

#define DPRINTF(fmt,...)    do{}while(0)
#define DBGMSG(fmt,...)     do{}while(0)
#define ERRMSG(fmt,...)     do{}while(0)

#define	ENTER()                 do{}while(0)
#define	LEAVE()                 do{}while(0)
#define	F_ENTER()	do{}while(0)
#define	F_LEAVE()	do{}while(0)
#ifdef LWIP_IPNETBUF_SUPPORT
#define ATDBGSP			CPUartLogPrintf
#define ATDBGMSG(fmt,args...)  CPUartLogPrintf(fmt, ##args)

#define LWIPUTL_TRACE(cat1, cat2, cat3, level, fmt) \
          if ((level) & utlTraceFilter()) { DIAG_FILTER(cat1, cat2, cat3, level) \
          diagTextPrintf(fmt);}

#define LWIPUTL_TRACE1(cat1, cat2, cat3, level, fmt, val1) \
          if ((level) & utlTraceFilter()){ DIAG_FILTER(cat1, cat2, cat3, level) \
          diagPrintf(fmt, val1);}

#define LWIPUTL_TRACE2(cat1, cat2, cat3, level, fmt, val1, val2) \
          if ((level) & utlTraceFilter()) {DIAG_FILTER(cat1, cat2, cat3, level) \
          diagPrintf(fmt, val1, val2);}

#define LWIPUTL_TRACE3(cat1, cat2, cat3, level, fmt, val1, val2, val3) \
          if ((level) & utlTraceFilter()) {DIAG_FILTER(cat1, cat2, cat3, level) \
          diagPrintf(fmt, val1, val2, val3);}

#define LWIPUTL_TRACEBUF(cat1, cat2, cat3, level, fmt, buffer, length) \
          if ((level) & utlTraceFilter()) {DIAG_FILTER(cat1, cat2, cat3, level) \
          diagStructPrintf(fmt, buffer, (length > 20) ? 20 : length);}

#else
#define ATDBGMSG(fmt,args...)
#endif

#define	UTL_DEBUG	0x1

#define UTL_TRACE_ERROR(cat1, cat2, cat3, level, fmt, val1) \
		  if ((level) & utlTraceFilter()){ DIAG_FILTER(cat1, cat2, cat3, level) \
		  diagPrintf(fmt, val1);}

 
#define utlError(...)    PRINTNONE(__VA_ARGS__)


#define UTL_TRACE(cat1, cat2, cat3, level, fmt) \
                    if ((level) & utlTraceFilter()) { DIAG_FILTER(cat1, cat2, cat3, level) \
                    diagTextPrintf(fmt);}
                    

#ifdef AT_FOR_EMBED

        #define UTL_TRACE1(cat1, cat2, cat3, level, fmt, val1) \
                  if ((level) & utlTraceFilter()){ DIAG_FILTER(cat1, cat2, cat3, level) \
                  diagPrintf(fmt, val1);}

        #define UTL_TRACE2(cat1, cat2, cat3, level, fmt, val1, val2) \
                  if ((level) & utlTraceFilter()) {DIAG_FILTER(cat1, cat2, cat3, level) \
                  diagPrintf(fmt, val1, val2);}

        #define UTL_TRACE3(cat1, cat2, cat3, level, fmt, val1, val2, val3) \
                  if ((level) & utlTraceFilter()) {DIAG_FILTER(cat1, cat2, cat3, level) \
                  diagPrintf(fmt, val1, val2, val3);}

#if QUECTEL_PROJECT_CUST
#define UTL_TRACE4(cat1, cat2, cat3, level, fmt, val1, val2, val3, val4) \
          if (((level) & utlTraceFilter()) && 0==InProduction_Mode()) {DIAG_FILTER(cat1, cat2, cat3, level) \
          diagPrintf(fmt, val1, val2, val3, val4);}
#endif

        #define UTL_TRACEBUF(cat1, cat2, cat3, level, fmt, buffer, length) \
                  if ((level) & utlTraceFilter()) {DIAG_FILTER(cat1, cat2, cat3, level) \
                  diagStructPrintf(fmt, buffer, (length > 20) ? 20 : length);}

#define utlAssert(test)		ASSERT(test)
#else

        #define UTL_TRACE1(cat1, cat2, cat3, level, fmt, val1)

        #define UTL_TRACE2(cat1, cat2, cat3, level, fmt, val1, val2)

        #define UTL_TRACE3(cat1, cat2, cat3, level, fmt, val1, val2, val3)
        
#if QUECTEL_PROJECT_CUST
        #define UTL_TRACE4(cat1, cat2, cat3, level, fmt, val1, val2, val3, val4)
#endif

        #define UTL_TRACEBUF(cat1, cat2, cat3, level, fmt, buffer, length)

#define utlAssert(test)
#endif



void SetutlTraceLevel(UINT32 *level, UINT32 len);
UINT32 utlTraceFilter (void);


#endif /* _UTL_TRACE_INCLUDED */

