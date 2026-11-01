#ifndef _NTP_H_
#define _NTP_H_

//#define NTP

//#ifdef NTP
#include <time.h>
#define NTP_FLAG_BIT 0x1

void NTP_Init(void);
void SyncNTP(void);
time_t GetNtpResult(void);
int GetNTPStatus(void);


//#endif

#endif

