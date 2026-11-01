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

typedef enum BND_PATROL_ERR {
    BND_PATROL_ERR_NET_DISCONNECT 	= -1,
	BND_PATROL_ERR_GET_TIMEOUT 	    = -2,
	BND_PATROL_ERR_IS_RUNDING 		= -3,
    BND_PATROL_ERR_NO_URL           = -4,
    BND_PATROL_ERR_PARSE_JOB_TODAY  = -5,
    BND_PATROL_ERR_PARSE_JOB_DETAIL  = -6,
    BND_PATROL_ERR_PARSE_SEND_CLOCKIN  = -7,
} BND_PATROL_ERR;

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
        flag:1：群组列表变化， 2：成员列表变化 3.监听群组列表变化
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
typedef void(*member_audio_enable)(int enable);
typedef void(*reminder_cb)(char* reminder, int day);
typedef void(*pa_cb)(int on_off);
typedef void(*request_lbs_info_cb)(char *z8filename,char *z12filename, char *z16filename, char *lbs_tts,char is_lbs_tts, char is_static_map);
typedef void(*location_change_cb)(int location_switch, int report_rate);
typedef void(*weather_info_cb)(char *lbs_tts,char is_lbs_tts);
/*
    reason  拒绝的原因//0-正常拒绝 1-接电话 2-免打扰
    result -2 对方不支持 -1 对方正在讲话，或者对方不允许被呼叫等错误
*/ 
typedef void(*request_invite_ack_cb)(uint64_t invite_id, int32_t result, uint32_t *invites, int invites_count, int reason);
/*
    result -1 当前用户被禁言，或者其他异常
*/
typedef void(*response_invite_ack_cb)(int32_t result, uint32_t is_timeout);
typedef void(*push_invite_cb)(uint64_t invite_id, uint32_t inviter);
/*
    reason  拒绝的原因//0-正常拒绝 1-接电话 2-免打扰
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
typedef void(*create_group_cb)(int create_group_switch);
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


/**
 * @brief 巡更开关状态回调函数
 * @param patrol_switch 开关状态（0-关闭，1-开启）
 */
typedef void(*patrol_switch_cb)(int patrol_switch);

/**
 * @brief 只支持善理平台-巡更功能 - 通用错误回调函数类型
 * 该回调函数在巡更功能发生错误时触发（如网络异常、协议解析失败、超时等），
 * 用于向上层返回错误码，便于统一处理错误或记录日志。
 * 
 * @param err   错误码（详见 BND_PATROL_ERR 枚举定义）
 * 
 * @note 该回调通常用于处理异步请求过程中的非业务错误
 * @note 业务逻辑的错误（如打卡失败）应通过对应的业务回调返回（如 recv_patrol_send_clockin_cb）
 * 
 * @warning 不要在回调函数内部执行阻塞操作
 */
typedef void(*recv_patrol_err_cb)(BND_PATROL_ERR err);

/**
 * @brief 只支持善理平台-巡更功能 - 获取今日任务列表回调函数类型
 * @param job_array   指向巡更任务信息结构体数组的指针，包含今日所有的任务
 * job_array 按照进行中、待执行、漏检、完成排序
 * @param job_size    任务数组中的元素个数（即今日任务总数）
 * 
 * @note 当 job_size == 0 时，job_array 为 NULL
 * @note 回调函数内部应自行处理 job_array 的内存复制（如需在回调外使用）
 * @note 任务数组 job_array 的生命周期仅在该回调函数执行期间有效
 * 
 * @warning 不要在回调函数内部执行阻塞操作
 * @warning 不要直接保存 job_array 指针，应在回调内完成数据拷贝
 */
typedef void(*recv_patrol_job_today_array_cb)(broad_job_info_t* job_array, int job_size);

/**
 * @brief 只支持善理平台-巡更功能 - 获取任务详情回调函数类型
 * 
 * 该回调函数在调用获取指定巡更任务详情的接口后触发，
 * 用于返回任务的完整信息，包括任务中包含的所有巡更点位置列表。
 * 
 * @param job_detail   指向巡更任务详情结构体的指针，包含任务信息及位置点数组
 * 
 * @note job_detail 的生命周期仅在该回调函数执行期间有效
 * @note 如需在回调外使用数据，应深拷贝 jobid、planname 及 locations 数组中的 locationname
 * @note 使用完毕后需调用相应的释放函数释放动态分配的内存
 * 
 * @warning 不要在回调函数内部执行阻塞操作
 * @warning 不要直接保存 job_detail 指针，应在回调内完成数据拷贝
 */
typedef void(*recv_patrol_job_detail_cb)(broad_job_detail_t* job_detail);

/**
 * @brief 只支持善理平台-巡更功能 - 发送打卡请求回调函数类型
 * 
 * 该回调函数在调用打卡接口后触发，用于返回打卡操作的结果。
 * 
 * @param clockin_result      打卡结果码（1打卡成功2任务不包含此巡更点3任务非可打卡状态4其它错误5巡更卡已过期6未指定任务ID，无法找到合适的任务7未指定任务ID，找到多于一个任务）
 * @param clockin_result_str
 * 
 * @note clockin_result_str 的生命周期仅在该回调函数执行期间有效
 * @note 如需在回调外使用 clockin_result_str，应自行拷贝字符串内容
 * 
 * @warning 不要在回调函数内部执行阻塞操作
 * @warning 不要直接保存 clockin_result_str 指针，应在回调内完成数据拷贝
 */
typedef void(*recv_patrol_send_clockin_cb)(int clockin_result,char* clockin_result_str);
/**
 * @brief 善理巡更功能 - 任务提醒回调函数类型
 * 
 * 当有即将开始的巡更任务时触发该回调，用于提醒用户。
 * 
 * @param jobid             任务ID字符串
 * @param planname          任务计划名称
 * @param starttime         任务开始时间（Unix秒时间戳）
 * @param countdownminutes  距离任务开始的倒计时分钟数
 * 
 * @note 该回调在任务开始前指定时间触发（如提前5分钟、10分钟等）
 * @note countdownminutes 表示距离 starttime 还有多少分钟
 * 
 * @warning 不要在回调函数内部执行阻塞操作
 */
typedef void(*recv_patrol_job_remind)(char* jobid,char* planname,unsigned int starttime,unsigned int countdownminutes);


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

void broad_register_recv_ai_audio_info_cb(recv_ai_audio_info_cb cb);

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


/**仅善理使用-巡更功能
 * @brief 注册巡更功能开关通知
 * @param cb 参照patrol_switch_cb描述
 */
void broad_register_patrol_switch_cb(patrol_switch_cb cb);

/**仅善理使用-巡更功能 
 * @brief 注册执行错误码通知
 * @param cb 参照recv_patrol_err_cb描述
 */
void broad_register_patrol_err_cb(recv_patrol_err_cb cb);

/**仅善理使用-巡更功能 
 * @brief 注册今日任务列表回复-回调通知
 * @param cb 参照recv_patrol_job_today_array_cb描述
 */
void broad_register_patrol_job_today_cb(recv_patrol_job_today_array_cb cb);

/**仅善理使用-巡更功能 
 * @brief 注册任务详细信息回复-回调通知
 * @param cb recv_patrol_job_detail_cb描述
 */
void broad_register_patrol_job_detail_cb(recv_patrol_job_detail_cb cb);

/**仅善理使用-巡更功能 
 * @brief 注册打卡回复-回调通知
 * @param cb recv_patrol_send_clockin_cb
 */
void broad_register_patrol_send_clockin_cb(recv_patrol_send_clockin_cb cb);

/**仅善理使用-巡更功能 
 * @brief 注册临期任务提醒-回调通知
 * @param cb recv_patrol_job_remind
 */
void broad_register_patrol_job_remind_cb(recv_patrol_job_remind cb);


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
int broad_http_add_group(int *members, int member_count);
int broad_http_add_members(int gid, int *members, int member_count);
int broad_http_remove_members(int gid, int *members, int member_count);
int broad_http_delete_group(int gid);
int broad_http_update_group_owner(int gid, int new_owner_uid);
int broad_http_get_invitation_code_group(int uid, int gid);
int broad_http_join_group(int uid, char *invitation_code);
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
/** 只支持善理平台
 * @brief broad_set_watch_group 设置某一个群组为监听群组
 * @param gid  要设置群组的ID
 * @param is_watch 0取消监听群组 非0设置监听群组
 * @return int 0 成功 
 	-1：群组已经设置过监听群组\已经取消了监听
 	-2：此群组并未监听 无需取消监听
 	-3: 已达到设置监听群组上限
 */
int broad_set_watch_group(unsigned int gid,int is_watch);

/**
 * @brief 请求今日巡更任务列表（仅支持善理平台）
 * @param zone 时区
 * @return 0-成功，小于0-失败
 */
int broad_patrol_request_job_today(int zone);
/**
 * @brief 请求巡更任务详情（仅支持善理平台）
 * @param jobid_str 任务ID字符串
 * @return 0-成功，小于0-失败
 */
int broad_patrol_request_job_detail(char* jobid_str);
/**
 * @brief 发送巡更打卡请求（仅支持善理平台）
 * @param jobid_str 任务ID字符串
 * @param nfccode   NFC刷卡码 小于等于128字节长度
 * @return 0-成功，小于0-失败
 */
int broad_patrol_send_clockin(char* jobid_str, char* nfccode);
/*
 * @param imei_data     IMEI字符串（15位，前面补0占位）
 * @param terminal_name 终端型号，例如 "BINQI-50"
 * @param type          功能字：0x01绑定，0x02加组
 * @param type_data     功能参数：加组不为空时为 group token
 * @param ble_data      输出缓冲区（调用者保证足够空间）
 * @return              实际生成的数据长度（数据长度字节+有效数据），失败返回-1
 */
int broad_make_ble_internal_protocol(char *imei_data, char *terminal_name, int type, char *type_data, char *ble_data);
#ifdef __cplusplus
}
#endif

#endif

