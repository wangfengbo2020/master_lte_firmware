#ifndef TIMEM_H
#define TIMEM_H

#ifndef time_t
typedef unsigned int time_t;     /* date/time in unix secs past 1-Jan-70 */
#endif

#if 0

struct tm
{
    int tm_sec;   /* seconds after the minute, 0 to 60
                   (0 - 60 allows for the occasional leap second) */
    int tm_min;   /* minutes after the hour, 0 to 59 */
    int tm_hour;  /* hours since midnight, 0 to 23 */
    int tm_mday;  /* day of the month, 1 to 31 */
    int tm_mon;   /* months since January, 0 to 11 */
    int tm_year;  /* years since 1900 */
    int tm_wday;  /* days since Sunday, 0 to 6 */
    int tm_yday;  /* days since January 1, 0 to 365 */
    int tm_isdst; /* Daylight Savings Time flag */
};
#endif
/* struct tm holds the components of a calendar time, called the broken-down
 * time. The value of tm_isdst is positive if Daylight Savings Time is in
 * effect, zero if Daylight Savings Time is not in effect, and negative if
 * the information is not available.
 */
extern time_t Fatsys_time(time_t * /*timer*/);


#endif
