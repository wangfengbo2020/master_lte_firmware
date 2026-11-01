/**
 * @file fota_test.c
 * @brief FOTA升级测试模块
 *
 * 使用方法：
 * 1. 取消注释下面的 #define ENABLE_FOTA_TEST 启用FOTA测试
 * 2. 选择测试方式（MINIFOTA / FULLFOTA / DFOTA）
 * 3. 配置升级包URL
 * 4. 编译烧录后，设备联网后会自动触发升级
 */

#include <stdint.h>
#include "ql_application.h"
#include "ql_fota.h"
#include "ql_rtos.h"
#include "ql_power.h"
#include "ql_data_call.h"
#include "tts_gbk.h"
#include "sl_log.h"

// =========================================================================
// 【FOTA测试开关】取消注释以启用FOTA测试
// =========================================================================
 // #define ENABLE_FOTA_TEST

// =========================================================================
// 【测试方式选择】只能选择一种
// =========================================================================
//#define TEST_MINIFOTA    // MiniFOTA方式（推荐，不占用FS空间，重启4次）
// #define TEST_FULLFOTA    // FullFOTA方式（APP全量升级，占用FS空间，重启2次）
// #define TEST_DFOTA       // DFOTA方式（差分升级，占用FS空间，重启2次）

// =========================================================================
// 【MiniFOTA配置】需要两个URL
// =========================================================================
#ifdef TEST_MINIFOTA
#define FOTA_URL1 "http://118.145.104.75:2323/system_patch.bin_1"
#define FOTA_URL2 "http://118.145.104.75:2323/system_patch.bin_2"
#endif

// =========================================================================
// 【FullFOTA配置】APP全量包URL
// =========================================================================
#ifdef TEST_FULLFOTA
#define FOTA_URL "http://192.168.1.100:8000/customer_app.bin"
#endif

// =========================================================================
// 【DFOTA配置】差分包URL
// =========================================================================
#ifdef TEST_DFOTA
#define FOTA_URL "http://192.168.1.100:8000/fbf_dfota.bin"
#endif

// 外部变量（来自example_poc.c）
extern uint8_t data_call_success;
extern volatile int g_login_ok;

#ifdef ENABLE_FOTA_TEST

// =========================================================================
// MiniFOTA测试（不占用FS空间，推荐）
// =========================================================================
#ifdef TEST_MINIFOTA
static int test_minifota_upgrade(void)
{
    int ret = 0;

    SL_LOG("FOTA_TEST", "===========================================");
    SL_LOG("FOTA_TEST", "Starting MiniFOTA Test");
    SL_LOG("FOTA_TEST", "URL1: %s", FOTA_URL1);
    SL_LOG("FOTA_TEST", "URL2: %s", FOTA_URL2);
    SL_LOG("FOTA_TEST", "===========================================");

    // 播放TTS提示
    tts_play_cn("开始MiniFOTA升级测试");
    ql_rtos_task_sleep_ms(3000);

    // 执行MiniFOTA升级
    ret = ql_fota_mini_system(
        1,                          // profile_idx (PDP context索引)
        QL_FOTA_DWNLD_MOD_HTTP,    // HTTP下载模式
        FOTA_URL1,                  // 第一个补丁包
        FOTA_URL2,                  // 第二个补丁包
        NULL,                       // 用户名（HTTP可为NULL）
        NULL                        // 密码（HTTP可为NULL）
    );

    if (ret == 0) {
        SL_LOG("FOTA_TEST", "MiniFOTA started successfully");
        SL_LOG("FOTA_TEST", "System will reboot 4 times to complete upgrade");
        tts_play_cn("升级包下载中，系统将重启四次");
        return 0;
    } else {
        SL_LOG("FOTA_TEST", "MiniFOTA failed with error: %d", ret);
        tts_play_cn("升级失败");
        return -1;
    }
}
#endif

// =========================================================================
// FullFOTA测试（APP全量升级）
// =========================================================================
#ifdef TEST_FULLFOTA
static int test_fullfota_upgrade(void)
{
    int ret = 0;

    SL_LOG("FOTA_TEST", "===========================================");
    SL_LOG("FOTA_TEST", "Starting FullFOTA Test");
    SL_LOG("FOTA_TEST", "URL: %s", FOTA_URL);
    SL_LOG("FOTA_TEST", "===========================================");

    tts_play_cn("开始全量升级测试");
    ql_rtos_task_sleep_ms(3000);

    // 执行FullFOTA升级
    ret = ql_fullfota_app_start(FOTA_URL);

    if (ret == 0) {
        SL_LOG("FOTA_TEST", "FullFOTA started successfully");
        SL_LOG("FOTA_TEST", "System will reboot 2 times to complete upgrade");
        tts_play_cn("全量升级包下载中");
        return 0;
    } else {
        SL_LOG("FOTA_TEST", "FullFOTA failed with error: %d", ret);
        tts_play_cn("升级失败");
        return -1;
    }
}
#endif

// =========================================================================
// DFOTA测试（差分升级）
// =========================================================================
#ifdef TEST_DFOTA
static int test_dfota_upgrade(void)
{
    int ret = 0;

    SL_LOG("FOTA_TEST", "===========================================");
    SL_LOG("FOTA_TEST", "Starting DFOTA Test");
    SL_LOG("FOTA_TEST", "URL: %s", FOTA_URL);
    SL_LOG("FOTA_TEST", "===========================================");

    tts_play_cn("开始差分升级测试");
    ql_rtos_task_sleep_ms(3000);

    // 执行DFOTA升级（使用firmware_download接口）
    ret = ql_fota_firmware_download(
        1,                          // profile_idx
        QL_FOTA_DWNLD_MOD_HTTP,    // HTTP模式
        FOTA_URL,                   // 差分包URL
        NULL,                       // 用户名
        NULL,                       // 密码
        NULL                        // 进度回调（可为NULL）
    );

    if (ret == 0) {
        SL_LOG("FOTA_TEST", "DFOTA download completed");
        SL_LOG("FOTA_TEST", "System will reboot to apply upgrade");
        tts_play_cn("差分包下载完成，准备重启");

        // 等待一段时间后重启
        ql_rtos_task_sleep_ms(3000);
        ql_power_reset();
        return 0;
    } else {
        SL_LOG("FOTA_TEST", "DFOTA failed with error: %d", ret);
        tts_play_cn("升级失败");
        return -1;
    }
}
#endif

// =========================================================================
// FOTA测试主任务
// =========================================================================
static void fota_test_task(void *arg)
{
    int retry_count = 0;
    int ret = 0;

    SL_LOG("FOTA_TEST", "FOTA Test Module Started");
    SL_LOG("FOTA_TEST", "Waiting for network connection...");

    // 等待网络连接成功（最多等待60秒）
    while (!data_call_success && retry_count < 60) {
        ql_rtos_task_sleep_s(1);
        retry_count++;
    }

    if (!data_call_success) {
        SL_LOG("FOTA_TEST", "Network connection timeout, FOTA test aborted");
        tts_play_cn("网络连接超时，升级测试取消");
        return;
    }

    SL_LOG("FOTA_TEST", "Network connected, starting FOTA test in 5 seconds...");
    tts_play_cn("网络已连接，五秒后开始升级测试");
    ql_rtos_task_sleep_s(5);

    // 根据选择的测试方式执行升级
#ifdef TEST_MINIFOTA
    ret = test_minifota_upgrade();
#elif defined(TEST_FULLFOTA)
    ret = test_fullfota_upgrade();
#elif defined(TEST_DFOTA)
    ret = test_dfota_upgrade();
#else
    SL_LOG("FOTA_TEST", "No FOTA test method selected!");
    tts_play_cn("未选择升级测试方式");
    return;
#endif

    if (ret == 0) {
        SL_LOG("FOTA_TEST", "FOTA test initiated successfully");
        SL_LOG("FOTA_TEST", "Waiting for automatic reboot...");
        // 升级过程中系统会自动重启，任务结束
    } else {
        SL_LOG("FOTA_TEST", "FOTA test failed");
    }
}

// 注册FOTA测试任务
application_init(fota_test_task, "fota_test", 4, 15);

#endif // ENABLE_FOTA_TEST
