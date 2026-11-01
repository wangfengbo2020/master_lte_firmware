/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/

#ifndef _PRODUCTION_TEST_H_
#define _PRODUCTION_TEST_H_

#include "ql_type.h"

typedef enum {
    PROD_MODE_DISABLED = 0,
    PROD_MODE_ENABLED = 1,
} prod_mode_t;

typedef struct {
    char imei[32];
    char iccid[32];
    char imsi[32];
    char fw_version[64];
    int signal_rssi;
    int signal_rsrp;
    int signal_rsrq;
    int signal_sinr;
} module_info_t;

void production_test_init(void);
void production_test_task(void *argv);
void production_enter_mode(void);
void production_exit_mode(void);
int production_is_enabled(void);

#endif
