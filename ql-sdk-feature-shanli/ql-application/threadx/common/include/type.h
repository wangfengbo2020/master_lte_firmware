#ifndef __BROAD_OPEN_TYPE_H__
#define __BROAD_OPEN_TYPE_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
typedef unsigned int			bnd_uid_t;
typedef unsigned int			bnd_gid_t;
typedef unsigned char			boolean;

#define USER_ONLINE 	1
#define USER_OFFLINE 	2
#define USER_INGROUP	3
#define BRD_NAME_LEN 64
//群组类型
typedef enum BRD_GROUP_TYPE {
	GRP_COMMON,
	GRP_SINGLECALL
} BRD_GROUP_TYPE;

typedef enum BND_CUSTOM_TYPE{
	ACCOUNT_LOGIN_ENABLE,
	WRITE_CUSTOM_ACCOUNT,
	QUERY_ALL_GROUP_MEMBER,
	CHANGE_PLATFORM_CONTEXT,
	SET_TONE_DURATION,
	SET_SYNC_RECORD_STOP_DURATION,
	CHANGE_PLATFORM_DNS,
	SET_APN,
	SET_APN_USERNAME,
	SET_APN_PASSWORD,
	SET_APN_MODEL,
	SET_CURRENT_GROUP_AHEAD,
	CLEAR_GROUP_MEMBER,
	SET_BND_IMEI_LOGIN,
	SET_IS_BROAD,
	SET_IS_ABROAD,
	SET_URL_INFO,
	SET_CREATE_GROUP_URL_INFO,//配置自建组域名
	SET_SOS_AUTO_RELEASE_TIME,//配置sos 发送的间隔限制 1~5s
	SET_ALWAYS_JOIN_LAST_GROUP,//配置进组超时，总是进入超时的群组
	SET_DROP_RECORD_FRAME,//丢弃录音桢数0~10
	SET_READ_SIM_ID,//设置读取sim id 只有芯平台有效，切换到其他平台需要重新设置为0
	SET_WIFI_NETWORK_VALID,//不配置和0：普通LET注网模式 配置1：WIFI注网
	SET_ACCOUNT_ICCID_ENABLE,//配置是否优先ICCID登录 对于WIFI方案 在无SIM卡情况 这个配置要写0
	SET_SPEAK_TONE_PCM_FILE_PATH,//配置自定义tone音(按麦、放麦2组)需要播放PCM文件的系统资源路径(文件需16位8K小于150毫秒)
	SET_JOIN_LAST_GROUP,//配置开机登录时进入(最后或默认)群组 1登录时进入关机前所在群组 0登录时进入此用户的默认群组 不设置情况默认1
	SET_TOC_PLATFROM,//配置登录为ToC平台 默认和不配置为ToB 配置1为ToC
}BND_CUSTOM_TYPE;

//群组结构
typedef struct bnd_group_t
{
	bnd_gid_t		gid;		//群组ID
	char		name[BRD_NAME_LEN];		//群组名
	BRD_GROUP_TYPE	type;		//群组类型
	int			index;
	unsigned int creator_uid;		///群组创建者
	boolean		is_watch; //是否监听
} bnd_group_t;

typedef struct _bnd_member_t {
	bnd_uid_t uid;
	char name[BRD_NAME_LEN];
	int state; //1在线，2,离线，3在线在组
	unsigned int prior;		///< 优先级
	int index;
	char role;//0普通成员 3调度员
}bnd_member_t;

typedef struct bnd_time_t {
	unsigned short	year;
	unsigned char	month;
	unsigned char	day;
	unsigned char	hour;
	unsigned char	minute;
	unsigned char	second;
	unsigned short	millisecond;
} bnd_time_t;

//好友结构
typedef struct bnd_contact_t
{
	bnd_uid_t uid;
	char name[BRD_NAME_LEN];
	int state; //1在线，2,离线，3在线在组
	unsigned int prior;		///< 优先级
	int index;
	char role;//0 普通成员 3调度员
} bnd_contact_t;

typedef struct bnd_record_file_info_t{
	unsigned int  record_start_time; //录音开始时间（UTC时间戳 单位:秒）
	unsigned int record_all_time;//录音总时长 单位:秒
	unsigned int record_file_index; //录音文件编号 0~9
	unsigned int userID;//讲话者ID
	char  speak_name[64];//讲话者名称
	char file_suffix[32];//文件后缀
	char msgUUID[32]; //录音文件ID 通过这个ID在请求下载文件的URL 最后获取的下载文件的URL 下载文件
}bnd_record_file_info_t;

/**
 * @brief 善理巡更功能 - 任务状态枚举
 */
typedef enum {
    TASK_STATUS_NOW = 0,      ///< 当前任务（正在进行中）
    TASK_STATUS_WAITING = 1,  ///< 等待任务（尚未开始）
    TASK_STATUS_MISS = 2,     ///< 错过任务（未在规定时间内完成）
    TASK_STATUS_FINISH = 3    ///< 完成任务（已完成打卡）
} broad_job_status;

/**
 * @brief 善理巡更功能 - 任务信息结构体（用于任务列表）
 * 
 * 该结构体用于描述巡更任务列表中的单个任务概要信息，
 * 相比任务详情结构体，该结构体更轻量，适用于列表展示。
 */
typedef struct {
    char* jobid;                    ///< 任务ID（动态分配字符串）
    char* planname;                 ///< 任务计划名称（动态分配字符串）
    unsigned long starttime;        ///< 任务开始时间（Unix秒时间戳）
    unsigned long endtime;          ///< 任务结束时间（Unix秒时间戳）
    int startsoon;                  ///< 即将开始标志（1-即将开始，0-正常，用于前端展示提醒）
    broad_job_status status;        ///< 任务状态（见 broad_job_status 枚举）
} broad_job_info_t;

/**
 * @brief 善理巡更功能 - 巡更位置点结构体
 * 
 * 描述巡更任务中的一个具体打卡位置点的详细信息
 */
typedef struct {
    int locationid;                 ///< 巡更点ID（唯一标识）
    int locationtype;               ///< 打卡类型，如 NFC/GPS 等
    char* locationname;             ///< 巡更点名称（动态分配字符串）
    int clockinuid;                 ///< 打卡用户ID（0表示未打卡）
    long long clockintime;          ///< 打卡时间（Unix秒时间戳，0表示未打卡）
    int locationstatus;             ///< 位置点状态（1-未开始2-未开始(已暂停已废弃)3-进行中4-已完成5-过期漏巡）
} broad_location_t;

/**
 * @brief 善理巡更功能 - 任务详情结构体
 * 
 * 描述一个完整的巡更任务，包含任务基本信息以及需要打卡的所有位置点列表。
 * 相比 broad_job_info_t，该结构体包含更详细的位置点信息。
 */
typedef struct {
    char* jobid;                    ///< 任务ID（动态分配字符串）
    char* planname;                 ///< 任务名称（动态分配字符串）
    long long starttime;            ///< 任务开始时间（Unix秒时间戳）
    long long endtime;              ///< 任务结束时间（Unix秒时间戳）
    int endcountdown;               ///< 结束倒计时（秒，距任务结束剩余时间）
    int jobstatus;                  ///< 任务状态（1-未开始2-未开始(已暂停已废弃)3-进行中4-已完成5-过期漏巡）
    broad_location_t* locations;    ///< 巡更位置点数组指针（任务中的所有打卡点）
    int locations_size;             ///< 位置点数组的元素个数
} broad_job_detail_t;

#ifdef __cplusplus
}
#endif
#endif

