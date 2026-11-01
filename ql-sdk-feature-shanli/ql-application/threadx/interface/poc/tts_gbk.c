#include "tts_gbk.h"

#include "ql_tts.h"
#include "sl_log.h"

// =========================================================================
// UTF-8 → UCS2(大端) hex 字符串，供 ql_tts_play(mode=1) 使用
// 纯算法转换，无需映射表，任意 BMP 内字符都能播。
//
// mode=1 传参格式见 SDK 示例 example_tts.c:
//   ql_tts_play(1, "6B228FCE4F7F752879FB8FDC6A215757");  // "欢迎使用移远模块"
// 每个字符 4 个大写 hex（UCS2 大端），例如 '欢' U+6B22 -> "6B22"
// =========================================================================

// 把单个 Unicode 码点写成 4 个大写 hex 字符（UCS2 大端）
static void put_ucs2_hex(unsigned int cp, char *dst) {
    static const char hex_chars[] = "0123456789ABCDEF";
    dst[0] = hex_chars[(cp >> 12) & 0xF];
    dst[1] = hex_chars[(cp >> 8) & 0xF];
    dst[2] = hex_chars[(cp >> 4) & 0xF];
    dst[3] = hex_chars[cp & 0xF];
}

// UTF-8 → UCS2(大端) hex 字符串，返回 hex 长度（不含末尾 \0）
static int tts_utf8_to_ucs2_hex(const char *utf8, char *hex_out, int hex_size) {
    const unsigned char *s = (const unsigned char *)utf8;
    int out = 0;

    while (*s && out + 4 < hex_size) {
        unsigned int cp = 0;
        if (*s < 0x80) {
            // 1 字节 UTF-8 (ASCII)
            cp = *s++;
        } else if ((*s & 0xE0) == 0xC0) {
            // 2 字节 UTF-8
            cp = ((*s & 0x1F) << 6) | (s[1] & 0x3F);
            s += 2;
        } else if ((*s & 0xF0) == 0xE0) {
            // 3 字节 UTF-8（中文在这个范围）
            cp = ((*s & 0x0F) << 12) | ((s[1] & 0x3F) << 6) | (s[2] & 0x3F);
            s += 3;
        } else if ((*s & 0xF8) == 0xF0) {
            // 4 字节 UTF-8（emoji 等）
            cp = ((*s & 0x07) << 18) | ((s[1] & 0x3F) << 12) | ((s[2] & 0x3F) << 6) | (s[3] & 0x3F);
            s += 4;
        } else {
            s++;  // 非法 UTF-8 字节，跳过
            continue;
        }

        if (cp > 0xFFFF) {
            SL_LOG("TTS", "Warning: char U+%X beyond BMP, replaced with '?'", cp);
            cp = '?';
        }
        put_ucs2_hex(cp, hex_out + out);
        out += 4;
    }

    hex_out[out] = '\0';
    return out;
}

void tts_play_cn(const char *utf8_text) {
    char hex_buf[512];
    int len = tts_utf8_to_ucs2_hex(utf8_text, hex_buf, sizeof(hex_buf));
    if (len > 0) {
        ql_tts_play(1, hex_buf);
    }
}
