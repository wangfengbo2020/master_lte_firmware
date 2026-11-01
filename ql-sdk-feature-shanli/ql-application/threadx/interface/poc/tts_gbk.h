#ifndef TTS_GBK_H
#define TTS_GBK_H

/**
 * @brief 便捷接口：直接用 UTF-8 中文播放 TTS
 *
 * 内部把 UTF-8 转成 UCS2(大端) hex 字符串后调 ql_tts_play(mode=1)。
 * 纯算法转换、无需映射表，任意 BMP 内汉字都能播。
 *
 * 注：文件名 tts_gbk 为历史遗留，当前实现已改用 UCS2，不再依赖 GBK 映射表。
 *
 * @param utf8_text UTF-8 编码的中文字符串
 */
void tts_play_cn(const char* utf8_text);

#endif /* TTS_GBK_H */
