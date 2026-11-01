/*
 * Copyright (c) 2015, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __MBTLIB_H__
#define __MBTLIB_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

enum tls_ret_value {
    AROM_TLS_CRYPTO_SUCCESS = 0,
    AROM_TLS_IMG_PARSER_OK  = 0,
    AROM_TLS_CRYPTO_ERR_INIT,
    AROM_TLS_CRYPTO_ERR_HASH,
    AROM_TLS_CRYPTO_ERR_SIGNATURE,
    AROM_TLS_CRYPTO_ERR_UNKNOWN,
    AROM_TLS_IMG_PARSER_ERR_START,
    AROM_TLS_IMG_PARSER_ERR,                /* Parser internal error */
    AROM_TLS_IMG_PARSER_ERR_FORMAT,         /* Malformed image */
    AROM_TLS_IMG_PARSER_ERR_NOT_FOUND       /* Authentication data not found */
};

/*
 * Type of parameters that can be extracted from an image and
 * used for authentication
 */
typedef enum {
    AROM_TLS_AUTH_PARAM_NONE,
    AROM_TLS_AUTH_PARAM_RAW_DATA,       /* Raw image data */
    AROM_TLS_AUTH_PARAM_SIG,            /* The image signature */
    AROM_TLS_AUTH_PARAM_SIG_ALG,        /* The image signature algorithm */
    AROM_TLS_AUTH_PARAM_HASH,           /* A hash (including the algorithm) */
    AROM_TLS_AUTH_PARAM_PUB_KEY,        /* A public key */
    AROM_TLS_AUTH_PARAM_NV_CTR,         /* A non-volatile counter */
} tls_auth_param_type_t;

/*
 * Defines an authentication parameter. The cookie will be interpreted by the
 * image parser module.
 */
typedef struct {
    tls_auth_param_type_t type;
    void *cookie;
} tls_auth_param_type_desc_t;

typedef enum {
    AROM_TLS_MD_NONE = 0,
    AROM_TLS_MD_MD2,
    AROM_TLS_MD_MD4,
    AROM_TLS_MD_MD5,
    AROM_TLS_MD_SHA1,
    AROM_TLS_MD_SHA224,
    AROM_TLS_MD_SHA256,
    AROM_TLS_MD_SHA384,
    AROM_TLS_MD_SHA512,
    AROM_TLS_MD_RIPEMD160,
} tls_md_type_t;

typedef enum {
    AROM_TLS_PK_NONE = 0,
    AROM_TLS_PK_RSA,
    AROM_TLS_PK_ECKEY,
    AROM_TLS_PK_ECKEY_DH,
    AROM_TLS_PK_ECDSA,
    AROM_TLS_PK_RSA_ALT,
    AROM_TLS_PK_RSASSA_PSS,
} tls_pk_type_t;

typedef void *(*tls_calloc_func)(size_t n, size_t size);
typedef void (*tls_free_func)(void *ptr);
typedef void *tls_handle;

typedef int (*mbedtls_io_read_t)(uint64_t addr, void **data, size_t *size);

tls_handle tls_init(tls_calloc_func c, tls_free_func f);

int tls_get_hash_sig_alg(tls_handle h, void *sig_alg, unsigned int sig_alg_len,
                         tls_md_type_t *pmd_alg, tls_pk_type_t *ppk_alg);
int tls_verify_signature(tls_handle h, void *data_ptr, unsigned int data_len,
                         void *sig_ptr, unsigned int sig_len,
                         void *sig_alg, unsigned int sig_alg_len,
                         void *pk_ptr, unsigned int pk_len);
int tls_verify_hash(tls_handle h, void *data_ptr, unsigned int data_len,
                    void *digest_info_ptr, unsigned int digest_info_len);
int tls_verify_hash_from_io_dev(tls_handle h, void *data_ptr, unsigned int data_len,
                                void *digest_info_ptr, unsigned int digest_info_len, mbedtls_io_read_t io_dev_read);
int tls_x509_check_integrity(tls_handle h, void *img, unsigned int img_len);
int tls_x509_get_auth_param(tls_handle h, const tls_auth_param_type_desc_t *type_desc,
                            void *img, unsigned int img_len,
                            void **param, unsigned int *param_len);
int tls_deinit(tls_handle h);

#ifdef __cplusplus
}
#endif

#endif /* __MBTLIB_H__ */
