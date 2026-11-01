#ifndef __QL_CORGET_POC_API_H__
#define __QL_CORGET_POC_API_H__

#include <stdint.h>

typedef void (*ql_corget_tone_play_cb_t)(int type);

typedef void (*ql_corget_poc_audio_pa_contrl_cb_t)(uint8_t on_off);

typedef int (*ql_corget_poc_cmd_notify_cb_t)(char *data, int len);

typedef struct
{
    int network_pcid;
    uint8_t ip_version;
#if 0
    char *local_ip_addr;
#endif
}ql_corget_poc_network_config_t;

typedef struct
{
    int f1;
    int f2;
    int play_time;
} ql_corget_poc_tone_item_t;

typedef struct
{
    ql_corget_poc_tone_item_t tone[5];
} ql_corget_poc_tone_config_t;

typedef struct ql_corget_poc_config_st
{
    ql_corget_poc_audio_pa_contrl_cb_t pa_contrl_cb;
    ql_corget_poc_cmd_notify_cb_t poc_cmd_notify_cb;
    ql_corget_poc_network_config_t network_cfg;
    ql_corget_poc_tone_config_t *tone_cfg;
    char *customer_app_version;
    uint8_t is_disable_tts;
}ql_corget_poc_config_t;

int ql_corget_poc_init(ql_corget_poc_config_t *config);

void ql_corget_poc_network_status_change(int is_connected);

int ql_corget_poc_cmd_write(char *data, int len);

void ql_corget_poc_diag_printf(const char *data);

char *ql_corget_poc_get_version(void);

int ql_corget_poc_update_network_cfg(ql_corget_poc_network_config_t *cfg);

int ql_corget_poc_set_tone_volume(uint8_t v);

int ql_corget_poc_register_tone_play_cb(ql_corget_tone_play_cb_t cb);


#endif // __QL_CORGET_POC_API_H__
