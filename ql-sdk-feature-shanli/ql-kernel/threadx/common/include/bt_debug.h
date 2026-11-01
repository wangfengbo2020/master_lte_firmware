#ifndef BT_DEBUG_H
#define BT_DEBUG_H

//bt device log print
#define BTLog(fmt,args...)                                                    \
{                                                                                       \
    if (log_config.log_cfg != LOG_DISABLE)      \
    {                                                                                   \
        UARTLogPrintf_Extend(LOG_MODULE_BT, fmt, ##args);                              \
    }                                                                                   \
}

#define appbt_debug(fmt, args...) BTLog("[BTAPP]"fmt, ##args)
#define appbt_log(fmt, args...) BTLog("[BTLOG]"fmt, ##args)
#define appbt_uart_log(fmt, args...) BTLog("[BTUART]"fmt, ##args)
#define a2dp_debug(fmt, args...) BTLog("[BTA2DP]"fmt, ##args)
#define app_bt_dbg(fmt, args...) BTLog("[BT]"fmt"\r\n", ##args)
#define app_ble_dbg(fmt, args...) BTLog("[BLE]"fmt"\r\n", ##args)

#define bt_log(TAG, fmt, args...) BTLog(TAG fmt, ##args)
#endif
