#ifndef MQTT_REMOTE_CONTROL_H
#define MQTT_REMOTE_CONTROL_H

#include <stdbool.h>
#include <stdint.h>

#include "ql_type.h"

// =========================================================================
// 错误码
// =========================================================================
#define MQTT_ERR_SUCCESS 0
#define MQTT_ERR_PARAM (-2)
#define MQTT_ERR_BUSY (-4)

// =========================================================================
// 公开接口
// =========================================================================

int mqtt_remote_control_init(const char* imei);
void mqtt_remote_control_stop(void);
int mqtt_remote_control_is_connected(void);
void drain_cmd_ring(void);

#endif /* MQTT_REMOTE_CONTROL_H */
