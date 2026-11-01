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
}BND_CUSTOM_TYPE;

//群组结构
typedef struct bnd_group_t
{
	bnd_gid_t		gid;		//群组ID
	char		name[BRD_NAME_LEN];		//群组名
	BRD_GROUP_TYPE	type;		//群组类型
	int			index;
	unsigned int creator_uid;		///群组创建者
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

#ifdef __cplusplus
}
#endif
#endif

