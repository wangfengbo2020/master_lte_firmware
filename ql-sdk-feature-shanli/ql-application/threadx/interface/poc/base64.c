#include "base64.h"

#include <stdlib.h>
#include <string.h>

static const char base64_table[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char* base64_encode(const uint8_t* data, int len) {
    int encoded_len = ((len + 2) / 3) * 4;
    char* encoded = (char*)malloc(encoded_len + 1);
    if (!encoded) return NULL;

    int i = 0, j = 0;
    uint8_t a3[3], a4[4];

    while (len--) {
        a3[i++] = *(data++);
        if (i == 3) {
            a4[0] = (a3[0] & 0xfc) >> 2;
            a4[1] = ((a3[0] & 0x03) << 4) + ((a3[1] & 0xf0) >> 4);
            a4[2] = ((a3[1] & 0x0f) << 2) + ((a3[2] & 0xc0) >> 6);
            a4[3] = a3[2] & 0x3f;

            for (i = 0; i < 4; i++) {
                encoded[j++] = base64_table[a4[i]];
            }
            i = 0;
        }
    }

    if (i) {
        for (int k = i; k < 3; k++) {
            a3[k] = '\0';
        }

        a4[0] = (a3[0] & 0xfc) >> 2;
        a4[1] = ((a3[0] & 0x03) << 4) + ((a3[1] & 0xf0) >> 4);
        a4[2] = ((a3[1] & 0x0f) << 2) + ((a3[2] & 0xc0) >> 6);

        for (int k = 0; k < i + 1; k++) {
            encoded[j++] = base64_table[a4[k]];
        }

        while (i++ < 3) {
            encoded[j++] = '=';
        }
    }

    encoded[j] = '\0';
    return encoded;
}

int base64_decode(const char* str, uint8_t* out_data, int max_len) {
    int len = strlen(str);
    int decoded_len = 0;
    uint8_t a4[4], a3[3];
    int i = 0, j = 0;

    while (len-- && str[j] != '=') {
        if (str[j] == ' ' || str[j] == '\r' || str[j] == '\n') {
            j++;
            continue;
        }

        const char* p = strchr(base64_table, str[j++]);
        if (!p) return -1;

        a4[i++] = p - base64_table;

        if (i == 4) {
            a3[0] = (a4[0] << 2) + ((a4[1] & 0x30) >> 4);
            a3[1] = ((a4[1] & 0xf) << 4) + ((a4[2] & 0x3c) >> 2);
            a3[2] = ((a4[2] & 0x3) << 6) + a4[3];

            for (i = 0; i < 3; i++) {
                if (decoded_len >= max_len) return -1;
                out_data[decoded_len++] = a3[i];
            }
            i = 0;
        }
    }

    if (i) {
        for (int k = i; k < 4; k++) {
            a4[k] = 0;
        }

        a3[0] = (a4[0] << 2) + ((a4[1] & 0x30) >> 4);
        a3[1] = ((a4[1] & 0xf) << 4) + ((a4[2] & 0x3c) >> 2);

        for (int k = 0; k < i - 1; k++) {
            if (decoded_len >= max_len) return -1;
            out_data[decoded_len++] = a3[k];
        }
    }

    return decoded_len;
}
