#ifndef E02T_CONFIG_H
#define E02T_CONFIG_H

#define CONFIG_FILE_PATH "U:/config.ini"
#define CONFIG_LINE_MAX 128
#define CONFIG_KEY_MAX 32
#define CONFIG_VAL_MAX 64

typedef struct {
    int gps_enable;
} e02t_config_t;

/**
 * @brief 从 U:/config.ini 读取配置，缺失字段使用默认值
 *        文件不存在时全部使用默认值，不报错
 */
void e02t_config_load(void);

/**
 * @brief 获取当前已加载的配置（只读）
 */
const e02t_config_t *e02t_config_get(void);

/**
 * @brief 从已加载的配置文件中查找 key 对应的整数值
 * @return 找到则返回对应值，未找到返回 default_val
 */
int e02t_config_get_int(const char *key, int default_val);

#endif /* E02T_CONFIG_H */
