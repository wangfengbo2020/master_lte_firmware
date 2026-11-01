#ifndef SL_LOG_H
#define SL_LOG_H

#include <stdio.h>

#define SL_LOG(tag, fmt, args...) printf("[SL][" tag "] " fmt "\r\n", ##args)
#define SL_DBG(fmt, args...) printf("[SL][DBG]%s:%d " fmt "\r\n", __FUNCTION__, __LINE__, ##args)

#endif /* SL_LOG_H */
