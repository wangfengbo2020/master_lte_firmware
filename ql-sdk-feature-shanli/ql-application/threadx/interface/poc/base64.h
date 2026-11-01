#ifndef BASE64_H
#define BASE64_H

#include <stdint.h>

/**
 * @brief Base64编码
 * @param data 输入数据
 * @param len 数据长度
 * @return 编码后的字符串（需要调用者free）
 */
char* base64_encode(const uint8_t* data, int len);

/**
 * @brief Base64解码
 * @param str Base64字符串
 * @param out_data 输出缓冲区
 * @param max_len 缓冲区最大长度
 * @return 解码后的数据长度，失败返回-1
 */
int base64_decode(const char* str, uint8_t* out_data, int max_len);

#endif
