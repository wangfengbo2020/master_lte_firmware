#ifndef GPS_TEST_H
#define GPS_TEST_H

#include "type.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * 产测 GPS 接口。
 *
 * GPS 芯片挂在 QL_U4_UART_PORT 上，由 driver 的 quec_uart_gps 任务独占。
 * 产测不自己开 UART，而是通过这些接口驱动该任务：进入产测模式后 GPS 常开、
 * 持续刷新 g_nmea_data，不上传平台、不走 LBS、不因超时断电。
 */

#define GPS_MAX_SATS 32

typedef struct {
    int prn;
    int snr;
} gps_sat_snr_t;

typedef struct {
    int             is_valid;
    char            rmc_status;
    char            lati_dir;
    char            longi_dir;
    double          latitude;
    double          longitude;
    float           speed_knot;
    float           speed_kmh;
    float           course;
    char            rmc_date[8];
    char            rmc_mode[4];
    char            gga_time[16];
    int             fix_quality;
    int             sat_count;
    float           hdop;
    double          altitude;
    double          geo_sep;
    int             raw_sat_count;
    gps_sat_snr_t   raw_sats[GPS_MAX_SATS];
} NMEA_Data;

typedef struct {
    int             fix;                    /* 是否已定位 (is_valid) */
    int             used;                   /* 参与定位的卫星数（GGA sat_count） */
    float           hdop;                   /* 水平精度因子 */
    double          lat;                    /* 纬度（FIX 后有效） */
    double          lon;                    /* 经度（FIX 后有效） */
    int             sat_count;              /* 本次上报信噪比的卫星数 */
    gps_sat_snr_t   sats[GPS_MAX_SATS];    /* 逐星 PRN+SNR */
} gps_test_snapshot_t;

/* 进入产测 GPS 模式：唤醒 GPS 任务上电并常开采集。返回 0 成功。 */
int gps_test_start(void);

/* 退出产测 GPS 模式：GPS 断电，任务回待机。返回 0 成功。 */
int gps_test_stop(void);

/* 读取当前 GPS 状态快照（瞬时返回，不阻塞）。 */
void gps_test_get(gps_test_snapshot_t *out);

#ifdef __cplusplus
}
#endif

#endif /* GPS_TEST_H */
