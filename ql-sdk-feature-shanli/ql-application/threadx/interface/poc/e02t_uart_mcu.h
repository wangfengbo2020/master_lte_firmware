#ifndef E02T_UART_MCU_H
#define E02T_UART_MCU_H

#include "ql_type.h"
#include "e02t_board_cfg.h"

#define E02T_BLE_GROUP_ENABLE 1

typedef int (*e02t_uart_line_handler_t)(const char* line);

// =========================================================
// PTT 相关的事件标志位定义 (供 GPIO 中断和串口解析共用)
// =========================================================
#define QL_PTTKEY_PRESS_FLAG (0x01 << 0)
#define QL_PTTKEY_RELEASE_FLAG (0x01 << 1)
#define QL_PTTKEY_CHANGE_FLAG (0x01 << 2)
#define QL_PTTKEY_MASK_FLAG (QL_PTTKEY_PRESS_FLAG | QL_PTTKEY_RELEASE_FLAG | QL_PTTKEY_CHANGE_FLAG)

/**
 * @brief 初始化MCU-4G串口通信模块
 * @return 0 成功, 其他 失败
 */
int e02t_uart_mcu_init(void);

/**
 * @brief 通过串口发送字符串给MCU (例如应答OK或者上报状态)
 * @param str 要发送的字符串, 需以 \0 结尾
 */
void e02t_uart_send_to_mcu(const char* str);

/**
 * @brief 注册一条 MCU 上行文本处理回调
 * @param handler 返回1表示已消费该行，返回0表示继续走原有 PTT/VOL 解析
 */
void e02t_uart_register_line_handler(e02t_uart_line_handler_t handler);

/**
 * @brief 查询 MCU UART 是否已初始化就绪
 * @return 1 就绪, 0 未就绪
 */
int e02t_uart_mcu_is_ready(void);

/**
 * @brief 同步查询 MCU：发送命令并等待响应
 * @param cmd       发送给 MCU 的 AT 命令（需含 \r\n）
 * @param response  接收缓冲区
 * @param resp_len  缓冲区大小
 * @param timeout_ms 超时毫秒数
 * @return >0 响应长度, -1 UART未就绪, -2 超时
 */
int e02t_uart_query_mcu(const char *cmd, char *response, int resp_len, int timeout_ms);

/**
 * @brief 异步发起一次电量查询（非阻塞，立即返回）
 *        结果由解析线程匹配 +SOC 回复后缓存，通过 e02t_uart_get_battery() 读取。
 * @return 0 已发起, -1 UART 未就绪
 */
int e02t_uart_query_battery_async(void);

/**
 * @brief 读取最近一次电量查询结果（缓存值，不发起查询）
 * @return 1~100 电量百分比, -1 尚未查询到有效值
 */
int e02t_uart_get_battery(void);

#if E02T_BLE_GROUP_ENABLE
/**
 * @brief 初始化 BLE 群组功能（创建超时定时器）
 *        必须在 e02t_uart_mcu_init() 之后调用
 */
void e02t_ble_group_init(void);

/**
 * @brief HTTP 建群回调（由 broad SDK 异步调用）
 */
void e02t_addgroup_cb(int status, int gid, char *group_name, char *invite_code);

/**
 * @brief HTTP 获取邀请码回调（建群后 invite_code 为空时的二次获取）
 */
void e02t_get_invite_code_cb(int status, char *invitation_code);

/**
 * @brief HTTP 加群回调
 */
void e02t_joingroup_cb(int status);

// =========================================================
// 自动切组：加组成功后自动切换到新群组
// 覆盖两类来源：本机发起（AT+JOINGROUP/AT+ADDGROUP，快照+diff）与
// 平台侧拉入（手机端建群拉入，listupdate 新旧列表 diff）。
// 平台推送 listupdate 与 HTTP 进组回调的先后顺序不确定，因此在发起
// 请求前先快照群组列表，回调到达或列表刷新时都做一次 diff，谁先发现
// 新 gid 谁触发进组（两种时序都能切换成功）。
// =========================================================

/**
 * @brief 快照当前群组列表并标记待自动进组（发起进组/建组请求前调用）
 * @return 0 成功, -1 群组数超出快照容量（放弃自动切组，不影响手动切组）
 */
int e02t_auto_join_arm(void);

/**
 * @brief 取消自动进组（请求失败/超时后调用）
 */
void e02t_auto_join_disarm(void);

/**
 * @brief 是否有待自动进组请求
 * @return 1 有, 0 无
 */
int e02t_auto_join_armed(void);

/**
 * @brief 在当前群组列表中查找快照里没有的新 gid，找到即进组并取消标记
 *        （HTTP 成功回调与 listupdate 回调都会调用，可重复调用）
 * @return 0 已切到新组, -1 尚未发现新组（保持标记，等待下次检查）
 */
int e02t_auto_join_check(void);

/**
 * @brief 通知平台侧出现了新群组（本机未发起请求的场景，如手机端建群拉入），
 *        内部自动切入。由 listupdate 回调的新旧列表 diff 调用。
 * @return 0 已触发进组或已处理, -1 无效 gid 或已在该组
 */
int e02t_auto_join_notify_new(unsigned int gid);
#endif /* E02T_BLE_GROUP_ENABLE */

#endif /* E02T_UART_MCU_H */
