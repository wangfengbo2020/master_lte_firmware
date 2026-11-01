#include "mqtt_remote_control.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MQTTClient.h"
#include "base64.h"
#include "cJSON.h"
#include "ql_audio.h"
#include "ql_audio_denoise.h"
#include "ql_data_call.h"
#include "ql_dev.h"
#include "ql_nw.h"
#include "ql_rtos.h"
#include "ql_sim.h"
#include "sl_log.h"
#include "version.h"

// =========================================================================
// MQTT 配置
// =========================================================================
#define MQTT_BROKER_HOST "broker.emqx.io"
#define MQTT_BROKER_PORT 1883

#define MQTT_USERNAME ""
#define MQTT_PASSWORD ""

#define MQTT_QOS_CMD 1
#define MQTT_QOS_EVENT_CRITICAL 1
#define MQTT_QOS_EVENT_PROGRESS 0

#define MQTT_KEEPALIVE_S 60
#define MQTT_YIELD_TIMEOUT_MS 200
#define MQTT_RECONNECT_DELAY_S 5

// =========================================================================
// 系统配置
// =========================================================================
#define MQTT_CMD_MAX_SIZE 256
#define MQTT_CMD_RING_SIZE 4

// =========================================================================
// 数据结构
// =========================================================================

typedef struct
{
    char json[MQTT_CMD_MAX_SIZE];
} mqtt_cmd_msg_t;

typedef struct {
    MQTTClient mqtt_client;
    Network mqtt_network;
    unsigned char sendbuf[512];
    unsigned char readbuf[512];

    char device_imei[32];

    char topic_cmd_down[128];
    char topic_cmd_up[128];
    char topic_event[128];

    bool initialized;
    bool connected;

    ql_task_t mqtt_task;
} mqtt_remote_ctx_t;

static mqtt_remote_ctx_t g_ctx = {0};

static mqtt_cmd_msg_t g_mqtt_cmd_ring[MQTT_CMD_RING_SIZE];
static volatile uint8_t g_mqtt_cmd_head = 0; // 回调写入位置
static volatile uint8_t g_mqtt_cmd_tail = 0; // 主循环读取位置

// =========================================================================
// 前向声明
// =========================================================================
static void mqtt_main_task_entry(void* arg);
static void mqtt_message_arrived(MessageData* data);
static void process_mqtt_cmd(const char* json_buf);
static void publish_cmd_response(const char* msg_id, const char* result, int error_code,
                                  const char* error_msg, const uint8_t* data, int data_len,
                                  cJSON* properties);
static void publish_event_notify(const char* msg_id, const char* message_type, const char* target,
                                  cJSON* properties, int qos);
static void handle_4g_command(const char* action, cJSON* properties, const char* msg_id);

// =========================================================================
// MQTT 发布辅助
// =========================================================================

static void publish_cmd_response(const char* msg_id, const char* result, int error_code,
                                  const char* error_msg, const uint8_t* data, int data_len,
                                  cJSON* properties) {
    if (!g_ctx.connected) return;

    cJSON* root = cJSON_CreateObject();
    if (!root) return;

    cJSON_AddStringToObject(root, "msg_id", msg_id);
    cJSON_AddStringToObject(root, "result", result);
    cJSON_AddNumberToObject(root, "error_code", error_code);

    if (error_code != 0 && error_msg) {
        cJSON_AddStringToObject(root, "error_msg", error_msg);
    }

    if (data && data_len > 0) {
        char* b64 = base64_encode(data, data_len);
        if (b64) {
            cJSON_AddStringToObject(root, "data", b64);
            free(b64);
        }
    }

    if (properties) {
        cJSON_AddItemToObject(root, "properties", cJSON_Duplicate(properties, 1));
    }

    char* json_str = cJSON_PrintUnformatted(root);
    if (json_str) {
        MQTTMessage message = {0};
        message.qos = MQTT_QOS_CMD;
        message.retained = 0;
        message.payload = json_str;
        message.payloadlen = strlen(json_str);

        int rc = MQTTPublish(&g_ctx.mqtt_client, g_ctx.topic_cmd_up, &message);
        if (rc != 0) {
            SL_LOG("MQTT", "Publish cmd/up failed: rc=%d", rc);
        }
        free(json_str);
    }

    cJSON_Delete(root);
}

static void publish_event_notify(const char* msg_id, const char* message_type, const char* target,
                                  cJSON* properties, int qos) {
    if (!g_ctx.connected) return;

    cJSON* root = cJSON_CreateObject();
    if (!root) return;

    cJSON_AddStringToObject(root, "msg_id", msg_id);
    cJSON_AddStringToObject(root, "messageType", message_type);
    if (target) {
        cJSON_AddStringToObject(root, "target", target);
    }
    if (properties) {
        cJSON_AddItemToObject(root, "properties", cJSON_Duplicate(properties, 1));
    }

    char* json_str = cJSON_PrintUnformatted(root);
    if (json_str) {
        MQTTMessage message = {0};
        message.qos = qos;
        message.retained = 0;
        message.payload = json_str;
        message.payloadlen = strlen(json_str);

        int rc = MQTTPublish(&g_ctx.mqtt_client, g_ctx.topic_event, &message);
        if (rc != 0) {
            SL_LOG("MQTT", "Publish event/notify failed: rc=%d", rc);
        }
        free(json_str);
    }

    cJSON_Delete(root);
}

// =========================================================================
// 4G 本地命令处理
// =========================================================================

extern volatile int g_login_ok;
extern volatile int g_in_group;
extern char ip_addr_str[64];

static void handle_4g_command(const char* action, cJSON* properties, const char* msg_id) {
    if (!action) {
        publish_cmd_response(msg_id, "failed", MQTT_ERR_PARAM, "missing action", NULL, 0, NULL);
        return;
    }

    SL_LOG("MQTT", "4G cmd: action=%s, msg_id=%s", action, msg_id);

    if (strcmp(action, "intercom_on") == 0) {
        publish_cmd_response(msg_id, "success", 0, NULL, NULL, 0, NULL);
    } else if (strcmp(action, "intercom_off") == 0) {
        publish_cmd_response(msg_id, "success", 0, NULL, NULL, 0, NULL);
    } else if (strcmp(action, "volume_set") == 0) {
        if (!properties) {
            publish_cmd_response(msg_id, "failed", MQTT_ERR_PARAM, "missing properties", NULL, 0,
                                 NULL);
            return;
        }
        cJSON* level_item = cJSON_GetObjectItem(properties, "level");
        if (!level_item || !cJSON_IsNumber(level_item)) {
            publish_cmd_response(msg_id, "failed", MQTT_ERR_PARAM, "missing level", NULL, 0, NULL);
            return;
        }
        int level = level_item->valueint;
        if (level < 0) level = 0;
        if (level > 11) level = 11;
        ql_set_volume(level);
        SL_LOG("MQTT", "Volume set to %d", level);
        publish_cmd_response(msg_id, "success", 0, NULL, NULL, 0, NULL);
    } else if (strcmp(action, "volume_up") == 0) {
        int vol = ql_get_volume();
        if (vol < 11) vol++;
        ql_set_volume(vol);
        SL_LOG("MQTT", "Volume up to %d", vol);
        publish_cmd_response(msg_id, "success", 0, NULL, NULL, 0, NULL);
    } else if (strcmp(action, "volume_down") == 0) {
        int vol = ql_get_volume();
        if (vol > 0) vol--;
        ql_set_volume(vol);
        SL_LOG("MQTT", "Volume down to %d", vol);
        publish_cmd_response(msg_id, "success", 0, NULL, NULL, 0, NULL);
    } else if (strcmp(action, "denoise_on") == 0) {
        ql_set_denoise_flag(true);
        SL_LOG("MQTT", "Denoise ON");
        publish_cmd_response(msg_id, "success", 0, NULL, NULL, 0, NULL);
    } else if (strcmp(action, "denoise_off") == 0) {
        ql_set_denoise_flag(false);
        SL_LOG("MQTT", "Denoise OFF");
        publish_cmd_response(msg_id, "success", 0, NULL, NULL, 0, NULL);
    } else if (strcmp(action, "query_status") == 0) {
        cJSON* props = cJSON_CreateObject();
        if (props) {
            cJSON_AddStringToObject(props, "imei", g_ctx.device_imei);
            cJSON_AddStringToObject(props, "fw_version", GIT_VERSION);
            cJSON_AddBoolToObject(props, "mqtt_connected", g_ctx.connected);

            QL_NW_REG_STATUS_INFO_T reg_status = {0};
            bool nw_registered = false;
            if (ql_nw_get_reg_status(&reg_status) == 0) {
                nw_registered = (reg_status.data_reg.state == QL_NW_REG_STATE_HOME_NETWORK ||
                                 reg_status.data_reg.state == QL_NW_REG_STATE_ROAMING);
            }
            cJSON_AddBoolToObject(props, "network_registered", nw_registered);

            struct ql_data_call_info call_info = {0};
            bool data_active = false;
            if (ql_get_data_call_info(1, 0, &call_info) == 0) {
                data_active = (call_info.v4.state > 0);
            }
            cJSON_AddBoolToObject(props, "data_call_active", data_active);

            int sim_status = 0;
            ql_sim_get_card_status(&sim_status);
            cJSON_AddBoolToObject(props, "sim_ready", sim_status == QL_SIM_STATUS_READY);
            cJSON_AddBoolToObject(props, "sim_inserted",
                                  sim_status != QL_SIM_STATUS_NOT_INSERTED);

            char phone_number[32] = {0};
            if (ql_sim_get_phonenumber(phone_number, sizeof(phone_number)) == 0 &&
                phone_number[0] != '\0') {
                cJSON_AddStringToObject(props, "phone_number", phone_number);
            } else {
                cJSON_AddStringToObject(props, "phone_number", "");
            }

            QL_NW_OPERATOR_INFO_T oper_info = {0};
            if (ql_nw_get_operator_name(&oper_info) == 0 && oper_info.short_eons[0] != '\0') {
                cJSON_AddStringToObject(props, "operator", oper_info.short_eons);
            } else {
                cJSON_AddStringToObject(props, "operator", "");
            }

            if (ip_addr_str[0] != '\0') {
                cJSON_AddStringToObject(props, "ip_address", ip_addr_str);
            } else {
                cJSON_AddStringToObject(props, "ip_address", "");
            }

            QL_NW_SIGNAL_STRENGTH_INFO_T sig = {0};
            if (ql_nw_get_signal_strength(&sig) == 0) {
                cJSON_AddNumberToObject(props, "rssi", sig.LTE_SignalStrength.rssi);
            } else {
                cJSON_AddNumberToObject(props, "rssi", 0);
            }

            cJSON_AddBoolToObject(props, "intercom_enabled", false);
            cJSON_AddBoolToObject(props, "poc_logged_in", g_login_ok ? true : false);
            cJSON_AddBoolToObject(props, "in_group", g_in_group ? true : false);
            cJSON_AddNumberToObject(props, "volume_level", ql_get_volume());
            cJSON_AddBoolToObject(props, "denoise_enabled", ql_get_denoise_flag());
            cJSON_AddStringToObject(props, "last_error", "");

            publish_cmd_response(msg_id, "success", 0, NULL, NULL, 0, props);
            cJSON_Delete(props);
        } else {
            publish_cmd_response(msg_id, "success", 0, NULL, NULL, 0, NULL);
        }
    } else {
        SL_LOG("MQTT", "4G unknown action: %s", action);
        publish_cmd_response(msg_id, "failed", MQTT_ERR_PARAM, "unknown action", NULL, 0, NULL);
    }
}

// =========================================================================
// MQTT 消息到达回调（只写 ring buffer，不 publish——规避 Paho 死锁）
// =========================================================================

static void mqtt_message_arrived(MessageData* data) {
    int json_len = data->message->payloadlen;
    if (json_len <= 0 || json_len >= MQTT_CMD_MAX_SIZE) {
        SL_LOG("MQTT", "RX msg too large: %d", json_len);
        return;
    }

    uint8_t next = (g_mqtt_cmd_head + 1) % MQTT_CMD_RING_SIZE;
    if (next == g_mqtt_cmd_tail)
    {
        SL_LOG("MQTT", "RX dropped (ring full)");
        return;
    }

    memcpy(g_mqtt_cmd_ring[g_mqtt_cmd_head].json, data->message->payload, json_len);
    g_mqtt_cmd_ring[g_mqtt_cmd_head].json[json_len] = '\0';
    g_mqtt_cmd_head = next;
}

// =========================================================================
// 命令分发
// =========================================================================

static void process_mqtt_cmd(const char* json_buf) {
    cJSON* root = cJSON_Parse(json_buf);
    if (!root) {
        SL_LOG("MQTT", "JSON parse failed");
        return;
    }

    cJSON* msg_id_item = cJSON_GetObjectItem(root, "msg_id");
    if (!msg_id_item || !cJSON_IsString(msg_id_item)) {
        SL_LOG("MQTT", "Missing msg_id");
        cJSON_Delete(root);
        return;
    }
    const char* msg_id = msg_id_item->valuestring;

    cJSON* type_item = cJSON_GetObjectItem(root, "type");
    if (!type_item || !cJSON_IsString(type_item)) {
        publish_cmd_response(msg_id, "failed", MQTT_ERR_PARAM, "missing type field", NULL, 0, NULL);
        cJSON_Delete(root);
        return;
    }
    const char* type = type_item->valuestring;

    cJSON* action_item = cJSON_GetObjectItem(root, "action");
    const char* action = (action_item && cJSON_IsString(action_item)) ? action_item->valuestring : NULL;
    cJSON* properties = cJSON_GetObjectItem(root, "properties");

    if (strcmp(type, "4g") == 0) {
        handle_4g_command(action, properties, msg_id);
    } else {
        // shanli 分支无 T32 SoC，仅支持 4g 类型命令
        publish_cmd_response(msg_id, "failed", MQTT_ERR_PARAM, "unsupported type, only '4g' is supported", NULL, 0, NULL);
    }

    cJSON_Delete(root);
}

// =========================================================================
// drain_cmd_ring: 处理环形缓冲中所有待处理命令
// =========================================================================

void drain_cmd_ring(void)
{
    while (g_mqtt_cmd_tail != g_mqtt_cmd_head)
    {
        process_mqtt_cmd(g_mqtt_cmd_ring[g_mqtt_cmd_tail].json);
        g_mqtt_cmd_tail = (g_mqtt_cmd_tail + 1) % MQTT_CMD_RING_SIZE;
    }
}

// =========================================================================
// MQTT 主任务
// =========================================================================

static void mqtt_main_task_entry(void* arg) {
    int rc;
    MQTTPacket_connectData connectData = MQTTPacket_connectData_initializer;

    SL_LOG("MQTT", "MQTT task started");
    ql_rtos_task_sleep_s(5);

reconnect:
    NetworkInit(&g_ctx.mqtt_network, NULL, 1);
    MQTTClientInit(&g_ctx.mqtt_client, &g_ctx.mqtt_network, 30000, g_ctx.sendbuf,
                   sizeof(g_ctx.sendbuf), g_ctx.readbuf, sizeof(g_ctx.readbuf));

    SL_LOG("MQTT", "Connecting to %s:%d", MQTT_BROKER_HOST, MQTT_BROKER_PORT);
    rc = NetworkConnect(&g_ctx.mqtt_network, MQTT_BROKER_HOST, MQTT_BROKER_PORT);
    if (rc != 0) {
        SL_LOG("MQTT", "Network connect failed: rc=%d", rc);
        ql_rtos_task_sleep_s(MQTT_RECONNECT_DELAY_S);
        goto reconnect;
    }

    connectData.MQTTVersion = 3;
    connectData.clientID.cstring = g_ctx.device_imei;
    connectData.username.cstring = MQTT_USERNAME;
    connectData.password.cstring = MQTT_PASSWORD;
    connectData.keepAliveInterval = MQTT_KEEPALIVE_S;
    connectData.cleansession = 1;

    rc = MQTTConnect(&g_ctx.mqtt_client, &connectData);
    if (rc != 0) {
        SL_LOG("MQTT", "MQTT connect failed: rc=%d", rc);
        NetworkDisconnect(&g_ctx.mqtt_network);
        ql_rtos_task_sleep_s(MQTT_RECONNECT_DELAY_S);
        goto reconnect;
    }

    SL_LOG("MQTT", "Connected");
    g_ctx.connected = true;

    rc = MQTTSubscribe(&g_ctx.mqtt_client, g_ctx.topic_cmd_down, MQTT_QOS_CMD,
                       mqtt_message_arrived);
    if (rc != 0) {
        SL_LOG("MQTT", "Subscribe failed: rc=%d", rc);
        MQTTDisconnect(&g_ctx.mqtt_client);
        NetworkDisconnect(&g_ctx.mqtt_network);
        g_ctx.connected = false;
        ql_rtos_task_sleep_s(MQTT_RECONNECT_DELAY_S);
        goto reconnect;
    }

    SL_LOG("MQTT", "Subscribed: %s", g_ctx.topic_cmd_down);

    // 主循环
    while (1) {
        rc = MQTTYield(&g_ctx.mqtt_client, MQTT_YIELD_TIMEOUT_MS);
        if (rc != 0) {
            SL_LOG("MQTT", "Yield failed: rc=%d, reconnecting...", rc);
            break;
        }

        drain_cmd_ring();
    }

    MQTTDisconnect(&g_ctx.mqtt_client);
    NetworkDisconnect(&g_ctx.mqtt_network);
    g_ctx.connected = false;

    ql_rtos_task_sleep_s(MQTT_RECONNECT_DELAY_S);
    goto reconnect;
}

// =========================================================================
// 初始化与停止
// =========================================================================

int mqtt_remote_control_init(const char* imei) {
    if (g_ctx.initialized) {
        return 0;
    }

    if (!imei) {
        return -1;
    }

    strncpy(g_ctx.device_imei, imei, sizeof(g_ctx.device_imei) - 1);

    snprintf(g_ctx.topic_cmd_down, sizeof(g_ctx.topic_cmd_down), "device/%s/cmd/down", imei);
    snprintf(g_ctx.topic_cmd_up, sizeof(g_ctx.topic_cmd_up), "device/%s/cmd/up", imei);
    snprintf(g_ctx.topic_event, sizeof(g_ctx.topic_event), "device/%s/event/notify", imei);

    // MQTT 主任务
    int ret = ql_rtos_task_create(&g_ctx.mqtt_task, 8192, 100, "mqtt_main", mqtt_main_task_entry, NULL);
    if (ret != 0) {
        SL_LOG("MQTT", "Create MQTT task failed: %d", ret);
        return -1;
    }

    g_ctx.initialized = true;
    SL_LOG("MQTT", "Initialized: imei=%s", imei);
    return 0;
}

void mqtt_remote_control_stop(void) {
    if (!g_ctx.initialized) return;
    g_ctx.initialized = false;
    g_ctx.connected = false;
}

int mqtt_remote_control_is_connected(void) {
    return g_ctx.connected ? 1 : 0;
}
