#include "e02t_config.h"

#include <string.h>
#include <stdlib.h>

#include "fs/ql_fs.h"
#include "sl_log.h"

static e02t_config_t g_config;
static int g_config_loaded = 0;

static void trim_line(char *s)
{
    int len = strlen(s);
    while (len > 0 && (s[len - 1] == '\r' || s[len - 1] == '\n' ||
                       s[len - 1] == ' ' || s[len - 1] == '\t')) {
        s[--len] = '\0';
    }
}

static int parse_line(const char *line, char *key, int key_len, char *val, int val_len)
{
    const char *eq;
    int klen;

    if (line[0] == '#' || line[0] == ';' || line[0] == '\0') {
        return -1;
    }

    eq = strchr(line, '=');
    if (eq == NULL) {
        return -1;
    }

    klen = eq - line;
    if (klen <= 0 || klen >= key_len) {
        return -1;
    }

    memcpy(key, line, klen);
    key[klen] = '\0';

    eq++;
    strncpy(val, eq, val_len - 1);
    val[val_len - 1] = '\0';

    return 0;
}

int e02t_config_get_int(const char *key, int default_val)
{
    QFILE *fp;
    char line[CONFIG_LINE_MAX];
    char k[CONFIG_KEY_MAX];
    char v[CONFIG_VAL_MAX];

    fp = ql_fopen(CONFIG_FILE_PATH, "r");
    if (fp == NULL) {
        return default_val;
    }

    while (ql_fgets(line, sizeof(line), fp) != NULL) {
        trim_line(line);
        if (parse_line(line, k, sizeof(k), v, sizeof(v)) == 0) {
            if (strcmp(k, key) == 0) {
                ql_fclose(fp);
                return atoi(v);
            }
        }
    }

    ql_fclose(fp);
    return default_val;
}

static void set_defaults(void)
{
    g_config.gps_enable = 0;
}

void e02t_config_load(void)
{
    set_defaults();

    g_config.gps_enable = e02t_config_get_int("gps_enable", g_config.gps_enable);

    g_config_loaded = 1;

    SL_LOG("CFG", "config loaded: gps_enable=%d", g_config.gps_enable);
}

const e02t_config_t *e02t_config_get(void)
{
    if (!g_config_loaded) {
        set_defaults();
    }
    return &g_config;
}
