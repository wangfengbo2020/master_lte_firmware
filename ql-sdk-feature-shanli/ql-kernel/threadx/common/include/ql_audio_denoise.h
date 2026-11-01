#ifndef __APP_TEST3_H__
#define __APP_TEST3_H__
#include <stdio.h>

void app3_denoise_init(void);


/***************************************************/
/* 获取算法所需的动态内存大小，已经在x86上计算过所 */
/* 需内存大小，存到了全局变量中                    */
/***************************************************/
unsigned int ql_denoise_dsp_get_memory_needed(void);


/***************************************************/
/* 把申请到的内存首地址传递给算法，算法内部有整套独*/
/* 立的与平台无关的动态内存管理策略                */
/***************************************************/
void ql_denoise_set_memory_base(void *base, unsigned int total);


/***************************************************/
/* 算法初始化                                     */
/* lvl：降噪等级，可调范围：0.2~4.0，1.0为基础，1.0以下减小降噪效果，1.0以上增大降噪效果 */
/* drc_post_gain：DRC Gain,算法内未做限制，觉得声音小就往上调整 */
/***************************************************/
void *ql_denoise_init(int sample_rate,float lvl, float drc_post_gain,int datalen);


/***************************************************/
/* 算法处理，只支持8ms一帧                          */
/***************************************************/
int ql_denoise_process(void* instance, short* mic, short* out);


/***************************************************/
/* 算法注销                                        */
/***************************************************/
void ql_denoise_cleanup(void *instance);

/***************************************************/
/*检验算法授权是否通过，检验通过返回0，不通过返回 -1                                        */
/***************************************************/


int ql_denoise_licenses_verify(void);

/***************************************************/
/*查询算法版本号                                        */
/***************************************************/
void ql_denoise_get_version(char* version);

/***************************************************/
/*默认关闭，特殊项目需要降噪开启时静音一段时间 
 （参数输入10的倍数）单位ms
*/
/***************************************************/
void ql_denoise_mute_time(unsigned int delay_ms);

void ql_denoise_set_vad_lvl(void* instance, int enable, float vad_threshold);



/***************************************************/
/*获取设备信息接口，获取的信息送到服务器获取license 
 dev_info：[in/out] 存放设备信息，malloc 1k 送入
 authcode ：授权码

 return ：0，成功，
          1，该设备已经被授权过,无需再次授权
          其他为错误值

*/
/***************************************************/
int ql_denoise_get_dev_info(unsigned char *dev_info,char *authcode);

/***************************************************/
/*保存license信息接口 ，服务器下发的数据送到这个接口校验
 license_data：需要保存的license信息
 data_len ：license 的长度

 return: 0成功，其他为错误值
*/
/***************************************************/

int ql_denoise_save_info_from_app(unsigned char *license_data,int data_len);


#endif /* __APP_TEST3_H__ */

