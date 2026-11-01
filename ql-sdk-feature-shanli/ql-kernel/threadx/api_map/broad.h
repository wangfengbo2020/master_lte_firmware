#ifndef __BROAD_OPEN_H__
#define __BROAD_OPEN_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "type.h"

typedef enum AUDIO_STATE{
    AUDIO_IDLE,
    BND_SPEAK_START,
    BND_SPEAKING,
    BND_SPEAK_STOP,
    BND_LISTEN_START,
    BND_LISTENING,
    BND_LISTEN_STOP,
    BND_TTS_START,
    BND_TTS_STOP,
    BND_TONE_START,
    BND_TONE_STOP,
    BND_REC_PLAY_START,
    BND_REC_PLAY_STOP,
}AUDIO_STATE;

typedef enum VOL_TYPE{
    BND_VOICE,
    BND_TTS,
    BND_TONE
}VOL_TYPE;

typedef enum BND_RECORD_FILE_TYPE {
    BND_RECORD_FILE_REQUEST_LIST = 1,
    BND_RECORD_FILE_PLAY_INDEX = 2,
} BND_RECORD_FILE_TYPE;

typedef enum BND_RECORD_FILE_ERR {
    BND_RECORD_FILE_ERR_NET_DISCONNECT 	= -1,
	BND_RECORD_FILE_ERR_GET_TIMEOUT 	= -2,
    BND_RECORD_FILE_ERR_REQUEST_LIST_FAIL 	= -3,
	BND_RECORD_FILE_ERR_DOWN_FILE_FAIL  = -4,
	BND_RECORD_FILE_ERR_PLAY_FILE_FAIL  = -5,
	BND_RECORD_FILE_ERR_IS_RUNDING = -6,
	BND_RECORD_FILE_ERR_NO_URL = -7,
	BND_RECORD_FILE_ERR_NO_PARAM		= -8,
	BND_RECORD_FILE_ERR_NO_GID = -9,
	BND_RECORD_FILE_ERR_NO_PLAY_INDEX = -10,
} BND_RECORD_FILE_ERR;

/*
    FUN:init_cb 库初始化结果回调
    PARAM:
        ret: 0:失败； 1:成功
*/
typedef void(*init_cb)(int ret);

/*
    FUN:login_state_cb 登录状态回调
    PARAM:
        online:USER_OFFLINE/USER_ONLINE
*/
typedef void(*login_state_cb)(int online);

/*
    FUN:join_group_cb 进组回调,触发源包括主动进组和被动进组
    PARAM:
        groupname:当前群组的名字
        gid：当前群组gid
*/
typedef void(*join_group_cb)(const char* groupname, bnd_gid_t gid);

/*
    FUN:audio_cb 音频的回调
    PARAM:
        state:当前语音状态:收听/讲话/TTS/TONE
        uid：当前操作用户uid，讲话/TTS/TONE时为0
        name:当前操作用户名字，讲话/TTS/TONE时为NULL
        flag:如果state为BND_LISTEN_START,flag==1表示本机可以打断对方讲话,flag==0表示本机不能打断对方讲话
        gid: 收听 群组的ID
        g_name: 收听   群组名称
*/
typedef void(*audio_cb)(AUDIO_STATE state, bnd_uid_t uid, const char* name, int flag, bnd_gid_t gid, const char* g_name);

/*
    FUN:callmember_cb 单呼的回调
    PARAM:
        ret:1->成功，0->失败
*/
typedef void(*callmember_cb)(int ret);

/*
    FUN:listupdate_cb 数据变化的回调
    PARAM:
        flag:1：群组列表变化， 2：成员列表变化
*/
typedef void(*listupdate_cb)(int flag);

/*
    FUN:member_change_cb 数据变化的回调
    PARAM:
        flag:1 离组
        num:个数
        uids:uid集合
*/
typedef void(*member_change_cb)(int flag, int nun, bnd_uid_t* uids);

/*
    FUN:error_cb 异常错误信息的回调
    PARAM:
        info: 异常信息
*/
typedef void(*error_cb)(const char* info);

/*
    FUN:poc_at_cb AT透传回调，用于接收POC处理后的返回AT数据
    PARAM:
        at: POC处理后的返回AT数据
*/
typedef void(*poc_at_cb)(char* at);
typedef void(*upgrade_cb)(int ret);
typedef void(*write_account_cb)(int ret);
typedef void(*member_audio_enable)(int enable);
typedef void(*reminder_cb)(char* reminder, int day);
typedef void(*pa_cb)(int on_off);
typedef void(*request_lbs_info_cb)(char *z8filename,char *z12filename, char *z16filename, char *lbs_tts,char is_lbs_tts, char is_static_map);
typedef void(*location_change_cb)(int location_switch, int report_rate);
typedef void(*weather_info_cb)(char *lbs_tts,char is_lbs_tts);
/*
    reason  拒绝的原因//0-正常拒绝 1-接电话 2-免打扰
    result -2 对方不支持 -1 对方正在讲话，或者对方不允许被呼叫等错误  服务器拒绝
*/ 
typedef void(*request_invite_ack_cb)(uint64_t invite_id, int32_t result, uint32_t *invites, int invites_count, int reason);
/*
    result -1 当前用户被禁言，或者其他异常
*/
typedef void(*response_invite_ack_cb)(int32_t result, uint32_t is_timeout);
typedef void(*push_invite_cb)(uint64_t invite_id, uint32_t inviter);
/* 
    reason  拒绝的原因//0-拒绝 1-不在线 2-会话中 3-免打扰 4-对方响应超时 5 平台开关关闭   被呼终端拒绝
*/ 
typedef void(*push_response_invite_cb)(uint64_t invite_id, uint32_t invitee, uint32_t accept, int reason);
typedef void(*sos_status_cb)(char send_sos_status);//0 success 1 error 2 timeout 3 not enable send sos
typedef void(*sos_map_cb)(char *z8filename,char *z12filename, char *z16filename,char is_sos_map);
typedef void(*recv_sos_info_cb)(char *sendname, char *timestamp, double lon, double lat);
typedef void(*recv_enclosure_alarm_cb)(int alarm, char *tips);//1 越界 0消除
typedef void(*recv_broadcast_info_cb)(int flags, char *tts);//1 开始播放广播 0停止播放广播
typedef void(*recv_http_request_status_cb)(int status);//0成功 1失败
typedef void(*recv_http_request_add_group_status_cb)(int status, int gid, char *group_name, char *invite_code);//0成功 1失败
typedef void(*recv_http_get_invitation_code_cb)(int status, char *invitation_code);//0成功 1失败
typedef void(*recv_http_request_timeout_cb)();
typedef void(*create_group_cb)(int create_group_switch);//0 关闭 1 成功

/*
	reporter  上报者uid
	uuid  sos 唯一标示
	longitude 经度
	latitude 纬度
	gid  群组id
*/
typedef void(*recv_sos_alarm_cb)(uint32_t reporter, uint64_t uuid, double lon , double lat, uint32_t gid);

typedef void(*recv_report_sos_ack_cb)(int result);//result 0 成功 其他失败
typedef void(*recv_report_sos_ack_timeout_cb)();//发送sos超时

typedef void(*recv_close_sos_cb)(int uid, uint64_t uuid);//uid 发送者 uuid 此sos唯一标示
typedef void(*sos_switch_cb)(int sos_switch);//0 关闭 1 打开 2 请求开关超时
typedef void(*ai_switch_cb)(int ai_switch);//0 关闭 1 打开 

typedef void(*recv_reportType_msg_cb)(char* msg);//透传文字播报信息

/*
    PARAM: robot_status AI处理状态
        0 request error
        1 request timeout
        2 request success
    PARAM: ai_msg       错误提示语
    */
typedef void (*recv_ai_audio_info_cb)(int robot_status, char *ai_msg);

typedef void(*recv_record_file_err_cb)(BND_RECORD_FILE_ERR err);//录音文件错误码
/*
*size:有多少条录音记录
*list_struct_array:结构体数组指针 包含size个 bnd_record_file_info_t结构体内容
*注：如果size=0 list_struct_array为NULL
*list_struct_array 结构体数组指针，请按照size大小拷贝，POC通知完成后就会free释放掉
*/
typedef void(*recv_record_file_list_cb)(int size,bnd_record_file_info_t* list_struct_array);//录音文件列表

void broad_init(init_cb cb);
void broad_free(void);
void broad_log(boolean enable);
int broad_login(login_state_cb cb);
int broad_logout(void);
int broad_joingroup(bnd_gid_t gid);
int broad_leavegroup(void);
//1:start 0:stop
int broad_speak(boolean start);
int broad_calluser(const bnd_uid_t uid ,callmember_cb cb);
int broad_callusers( const bnd_uid_t* uids, int num, callmember_cb cb );
//按索引查询群组信息
int broad_group_getbyindex(int index,bnd_group_t* dst);

//如果gid传入0,可查询当前群组信息
int broad_group_getbyid(bnd_gid_t gid,bnd_group_t* dst);

//如果uid传入0,可查询当前登录用户信息
int broad_member_getbyid(bnd_uid_t uid,bnd_member_t* dst);
int broad_get_loginstate(void);
int broad_get_groupcount(void);

/*
    FUN：broad_get_grouplist
    PARAM：
        dst和dst_size为调用者的数组空间及数组大小
        index_begin为查询的索引起始值
        count为计划查询的个数
    RETURN：
        实际查询到的个数
*/
int broad_get_grouplist(bnd_group_t* dst, int dst_size, int index_begin, int count);

/*
    FUN：broad_get_default_group_id
    RETURN：
        返回默认群组ID
*/
uint32_t broad_get_default_group_id(void);

const int broad_get_membercount(bnd_gid_t gid );
/*
    FUN：broad_get_memberlist
    PARAM：
        gid为群组id
        dst和dst_size为调用者的数组空间及数组大小
        index_begin为查询的索引起始值
        count为计划查询的个数
    RETURN：
        实际查询到的个数
*/
const int broad_get_memberlist(bnd_gid_t gid, bnd_member_t* dst, int dst_size, int index_begin, int count);

AUDIO_STATE broad_get_audiostate(void);

//boolean interrupt : true--interrupt current tts playing
int broad_play_tts(const char* tts, boolean interrupt);

int broad_send_ping(void);

//lat：纬度， lon： 经度， time： 定位时间
int broad_send_gpsinfo(double lon,double lat,bnd_time_t time, double alt, double speed, double dirang);
void broad_get_version(char* ver);
int broad_current_zone_time(bnd_time_t* now, float zone);

//success return 0, failed return -1
int broad_set_tts_enable(boolean enable);
int broad_set_vol(VOL_TYPE type, int vol);
int broad_get_vol(VOL_TYPE type);
//获取帐号可用天数
int broad_get_account_day(void);

//mode:1->open; 0->close; 2->clear all history
int broad_set_rec_audio_mode(unsigned char mode);

int broad_get_rec_audio_count(void);

//index:录音列表索引, name:讲话的用户名utf8格式, delay:语音时长(单位秒), time:录制时间
int broad_get_rec_audio_info(int index, char* name, unsigned char* delay, bnd_time_t* time);

//index:录音列表索引
int broad_play_rec_audio(int index);

int broad_stop_play_rec_audio(void);
//
void broad_register_audio_cb(audio_cb cb);
void broad_register_join_group_cb(join_group_cb cb);
void broad_register_listupdate_cb(listupdate_cb cb);
void broad_register_member_change_cb(member_change_cb cb);
void broad_register_error_cb(error_cb cb);
void broad_register_upgrade_cb(upgrade_cb cb);
void broad_register_member_audio_enable_cb(member_audio_enable cb);
void broad_register_reminder_cb(reminder_cb cb);
void broad_register_pa_cb(pa_cb cb);
void broad_register_request_lbs_info_cb(request_lbs_info_cb cb);
void broad_register_location_change_cb(location_change_cb cb);
void broad_register_weather_info_cb(weather_info_cb cb);
void broad_register_cell_location_change_cb(location_change_cb cb);
void broad_register_request_invite_ack_cb(request_invite_ack_cb cb);
void broad_register_response_invite_ack_cb(response_invite_ack_cb cb);
void broad_register_push_invite_cb(push_invite_cb cb);
void broad_register_push_response_invite_cb(push_response_invite_cb cb);
void broad_register_sos_status_cb(sos_status_cb cb);
void broad_register_sos_map_cb(sos_map_cb cb);
void broad_register_recv_sos_info_cb(recv_sos_info_cb cb);
void broad_register_recv_enclosure_alarm_cb(recv_enclosure_alarm_cb cb);
void broad_register_recv_broadcast_info_cb(recv_broadcast_info_cb cb);
void broad_register_recv_http_add_group_cb(recv_http_request_add_group_status_cb cb);
void broad_register_recv_http_add_members_cb(recv_http_request_status_cb cb);
void broad_register_recv_http_remove_members_cb(recv_http_request_status_cb cb);
void broad_register_recv_http_delete_group_cb(recv_http_request_status_cb cb);
void broad_register_recv_http_update_group_owner_cb(recv_http_request_status_cb cb);
void broad_register_recv_http_get_invitation_code_cb(recv_http_get_invitation_code_cb cb);
void broad_register_recv_http_join_group_cb(recv_http_request_status_cb cb);
void broad_register_recv_http_exit_group_cb(recv_http_request_status_cb cb);
void broad_register_recv_http_request_timeout_cb(recv_http_request_timeout_cb cb);
void broad_register_create_group_switch_cb(create_group_cb cb);
void broad_register_recv_ai_audio_info_cb(recv_ai_audio_info_cb cb);
/**
 * @brief 透传文字播报信息注册回调
 */
void broad_register_recv_reportType_msg_cb(recv_reportType_msg_cb cb);

/**
 * @brief 注册接受sos 通知
 * 
 * @param cb 
 */
void broad_register_recv_sos_alarm_cb(recv_sos_alarm_cb cb);
/**
 * @brief 注册接受发送sos 回应通知
 * 
 * @param cb 
 */

void broad_register_recv_report_sos_ack_cb(recv_report_sos_ack_cb cb);
/**
 * @brief 注册sos 超时回调函数
 * 
 * @param cb 
 */
void broad_register_recv_report_sos_ack_timeout_cb(recv_report_sos_ack_timeout_cb cb);
/**
 * @brief 注册接受关闭sos通知
 * 
 * @param cb 
 */
void broad_register_recv_close_sos_cb(recv_close_sos_cb cb);

/**
 * @brief 注册sos 开关通知
 * 
 * @param cb 
 */
void broad_register_sos_switch_cb(sos_switch_cb cb);
void broad_register_ai_switch_cb(ai_switch_cb cb);

/**
 * @brief 注册录音文件 错误码通知
 * 
 * @param cb 
 */
void broad_register_record_file_err_cb(recv_record_file_err_cb cb);

/**
 * @brief 注册录音文件 当前群组文件列表通知
 * 
 * @param cb 
 */
void broad_register_record_file_list_cb(recv_record_file_list_cb cb);


//建议broad_set_poc_uart_device用于broad_init(init_cb cb)注册的回调里
/*
	void ui_init(int ret){
		broad_set_poc_uart_device(0);
	}
	broad_init(ui_init);
*/
int broad_set_poc_uart_device(int open); //默认uart设备是打开的，如需关闭请设置为0
//AT 透传接口
int broad_send_at(char* at); //发送
void broad_register_poc_at_cb(poc_at_cb cb);//注册接收回调
int broad_set_call_end_timeptr(int timeptr);
int broad_set_call_auto_leave_temp_group(int flag);
int broad_write_custom(BND_CUSTOM_TYPE type, const char* value);
int broad_read_custom(BND_CUSTOM_TYPE type, const char* value);
void broad_set_notify_mode(int flags);
int broad_set_solution(char *solution);
int broad_set_solution_version(char *version);
int broad_set_productInfo(char *productInfo);
int broad_set_manufacturer(char *manufacturer);
int broad_request_upgrade();
int broad_get_init_status();
int broad_set_tone_enable(int flags);
void broad_get_upgrade_version(char* ver);
int broad_request_lbs_info(int w, int h, double lon, double lat);
int broad_request_weather_info(double lon,double lat);
//以下三个接口试用于 善理1.0账号登陆的方式
int broad_login_by_saved(login_state_cb cb);
int broad_change_logininfo(const char* account,const char* pwd);
int broad_get_logininfo(char* account, char* pwd);
/*
    FUN：broad_request_create_full_duplex_group
    PARAM：
        invites 为成员id数组
        size 成员的个数
    RETURN：
        发送请求创建全双工临时群组
*/
int broad_request_create_full_duplex_group(uint32_t* invites, uint32_t size);
/*
    FUN：broad_response_create_full_duplex_group
    PARAM：
        invite_id 此次请求的会话id,通过poc通知拿到
        inviter 发起请求的uid，通过poc通知拿到
        accept  是否同意此次请求
        reason  拒绝的原因//0-正常拒绝 1-接电话 2-免打扰
    RETURN：
        发送请求创建全双工临时群组
*/
int broad_response_create_full_duplex_group(uint64_t invite_id, uint32_t inviter, uint32_t accept, int reason);
int broad_sos_start(double lon, double lat);
int broad_query_sos_map(int w, int h, double lon, double lat);
const int broad_get_contactlist_count();
const int broad_get_contactlist(bnd_contact_t* dst, int dst_size);

/**
 * @brief broad_http_add_group 添加群组
 * @brief members 添加群组并拉去成员uid 可以传NuLL
 * @param member_count	成员个数
 * @return int 0 成功  -1 内部错误
 */
int broad_http_add_group(int *members, int member_count);
/**
 * @brief broad_http_add_members 向指定群组添加添加成员
 * @brief gid 指定群组gid
 * @brief members 添加群成员uid
 * @param member_count	成员个数
 * @return int 0 成功  -1 内部错误
 */
int broad_http_add_members(int gid, int *members, int member_count);
/**
 * @brief broad_http_add_members 向指定群组删除成员
 * @brief gid 指定群组gid
 * @brief members 删除群组成员uid
 * @param member_count	成员个数
 * @return int 0 成功  -1 内部错误
 */
int broad_http_remove_members(int gid, int *members, int member_count);
/**
 * @brief broad_http_delete_group 删除指定群组
 * @brief gid 删除指定群组gid
 * @return int 0 成功  -1 内部错误
 */
int broad_http_delete_group(int gid);
/**
 * @brief broad_http_update_group_owner 向指定群组更新群组管理员
 * @brief gid 指定群组gid
 * @brief new_owner_uid 新群组管理员uid
 * @return int 0 成功  -1 内部错误
 */
int broad_http_update_group_owner(int gid, int new_owner_uid);
/**
 * @brief broad_http_get_invitation_code_group 向指定群组获取邀请码
 * @brief gid 指定群组gid
 * @brief uid 邀请者uid
 * @return int 0 成功  -1 内部错误
 */
int broad_http_get_invitation_code_group(int uid, int gid);
/**
 * @brief broad_http_join_group 通过邀请码加入群组
 * @brief invitation_code 群组邀请码
 * @brief uid 加入者uid
 * @return int 0 成功  -1 内部错误
 */
int broad_http_join_group(int uid, char *invitation_code);
/**
 * @brief broad_http_exit_group 退出群组
 * @brief gid 要退出群组gid
 * @brief uid 退出者 uid
 * @return int 0 成功  -1 内部错误
 */
int broad_http_exit_group(int uid, int gid);

/**
 * @brief broad_report_sos 发送sos
 * 
 * @param lon 经度
 * @param lat 纬度
 * @param time 时间
 * @param alt 海拔
 * @param speed 速度
 * @param dirang 方向
 * @return int 0 成功  -1 内部错误 -2 发送sos 频繁
 */
int broad_report_sos(double lon,double lat,bnd_time_t time, double alt, double speed, double dirang);

/**
 * @brief broad_set_terminal_info 设置或更新终端当前电量（1~100%）和4G信号等级（1~5个等级）信息
 * @brief 此函数设置的信息不会立即上报 跟随下一个心跳(broad_send_ping)上报到服务器
 * @param battery_level	电量（1~100%）
 * @param signal_level  4G信号等级（1~5个等级）
 * @return int 0 成功  -1 内部错误
 */
int broad_set_terminal_info(int battery_level, int signal_level);

/**
 * @brief 设置广播TTS开关
 * 默认打开 如果通过透传 获取【文字广播】需要设置为关闭 0
 */
void broad_set_broadcast_tts_enable(boolean enable);

/*
    broad_recorder_audio_run 录制音频数据，并发送
    flag:
    1 开始录制
    0 停止录制
    ret
    0   成功
    -1  录音失败
    -2  未开启ai 开关
*/
const int broad_recorder_audio_run(int flag);
/*
    broad_stop_play_ai_tts 主动停止ai tts
    ret
    0   成功
*/
int broad_stop_play_ai_tts();

/** 只支持善理平台
 * @brief broad_http_record_file 请求录音文件列表和通过列表的record_file_index播放相应的录音文件
 * @param type 1.BND_RECORD_FILE_REQUEST_LIST 请求列表 必须传gid play_file_index为0
 			   2.BND_RECORD_FILE_PLAY_INDEX	通过1步骤 请求下来的record_file_index来播放录音文件 必须传play_file_index （0~9） gid为0
 * @param gid  查询录音文件的群组ID
 * @param play_file_index 播放录音文件的INDEX
 * @return int 0 成功 其他 错误 具体见 BND_RECORD_FILE_ERR枚举
 */
int broad_http_record_file(BND_RECORD_FILE_TYPE type,unsigned int gid,unsigned int play_file_index);
/** 只支持善理平台
 * @brief 停止播放录音文件
**/
int broad_http_record_file_stop_play(void);
#ifdef __cplusplus
}
#endif

#endif

