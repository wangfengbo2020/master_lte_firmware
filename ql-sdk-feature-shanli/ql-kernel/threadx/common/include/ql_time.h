/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/

#ifndef _QL_TIME_H_
#define _QL_TIME_H_

#include <time.h>



struct tm *gmtime_r(const time_t *timep, struct tm *r);
struct tm *gmtime(const time_t *_timer);
struct tm* ql_localtime_r(const time_t* t, struct tm* r);
struct tm* ql_localtime(const time_t* t);
time_t quec_mktime(struct tm * timeptr);
extern time_t quec_mktime(struct tm * timeptr);

#endif



