/**
 * @file fota_version_check.c
 * @brief FOTA升级版本检查工具
 *
 * 用于验证FOTA升级是否成功
 * 通过对比版本号来确认升级结果
 */

#include "ql_application.h"
#include "ql_rtos.h"
#include "sl_log.h"
#include "tts_gbk.h"

// 从example_poc.c引用版本号
#define CUSTOMER_APP_VERSION "APP_V0.0.2"

// =========================================================================
// 版本信息打印
// =========================================================================
static void print_version_info(void)
{
    SL_LOG("VERSION", "========================================");
    SL_LOG("VERSION", "Firmware Version Information");
    SL_LOG("VERSION", "========================================");

    // 打印APP版本
    SL_LOG("VERSION", "APP Version: %s", CUSTOMER_APP_VERSION);

    // 打印Git版本信息（如果有）
#ifdef GIT_VERSION
    SL_LOG("VERSION", "Git Version: %s", GIT_VERSION);
#endif
#ifdef GIT_COMMIT_DATE
    SL_LOG("VERSION", "Git Date: %s", GIT_COMMIT_DATE);
#endif
#ifdef GIT_BRANCH
    SL_LOG("VERSION", "Git Branch: %s", GIT_BRANCH);
#endif

    SL_LOG("VERSION", "========================================");

    // 播放版本号TTS
    // tts_play_cn("当前版本");
    ql_rtos_task_sleep_ms(1000);
}

// =========================================================================
// 版本检查任务
// =========================================================================
static void version_check_task(void *arg)
{
    // 等待系统启动完成
    ql_rtos_task_sleep_s(3);

    SL_LOG("VERSION_CHECK", "Starting version check...");

    // 打印版本信息
    print_version_info();

    SL_LOG("VERSION_CHECK", "Version check completed");
    SL_LOG("VERSION_CHECK", "To verify FOTA upgrade:");
    SL_LOG("VERSION_CHECK", "1. Compare version number before and after upgrade");
    SL_LOG("VERSION_CHECK", "2. Check if system rebooted multiple times");
    SL_LOG("VERSION_CHECK", "3. Test all functions work correctly");

    // 任务完成，退出
}

// 注册版本检查任务（优先级较高，尽早执行）
application_init(version_check_task, "ver_check", 2, 5);
