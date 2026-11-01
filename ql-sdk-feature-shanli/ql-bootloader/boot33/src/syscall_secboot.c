#include "syscall-arom.h"
#include "stdint.h"
#include "mbtlib.h"

tls_handle
tls_init(tls_calloc_func c, tls_free_func f)
{
    tls_handle (*handler)(tls_calloc_func, tls_free_func);
    tls_handle ret = NULL;

    handler = syscall_get_handler(SYSCALL_97_SB_TLS_INIT);
    if (handler) {
        ret = handler(c, f);
    }

    return ret;
}

int
tls_deinit(tls_handle h)
{
    int (*handler)(tls_handle);
    int ret = 0;

    handler = syscall_get_handler(SYSCALL_98_SB_TLS_DEINIT);
    if (handler) {
        ret = handler(h);
    }

    return ret;
}

int
tls_verify_signature(tls_handle h, void *data_ptr, unsigned int data_len,
                     void *sig_ptr, unsigned int sig_len,
                     void *sig_alg, unsigned int sig_alg_len,
                     void *pk_ptr, unsigned int pk_len)
{
    int (*handler)(tls_handle, void *, unsigned int,
                   void *, unsigned int,
                   void *, unsigned int,
                   void *, unsigned int);
    int ret = 0;

    handler = syscall_get_handler(SYSCALL_99_SB_TLS_VERIFY_SIGNATURE);
    if (handler) {
        ret = handler(h, data_ptr, data_len, sig_ptr, sig_len,
                      sig_alg, sig_alg_len, pk_ptr, pk_len);
    }

    return ret;
}

int
tls_verify_hash_from_io_dev(tls_handle h, void *data_ptr, unsigned int data_len,
                            void *digest_info_ptr, unsigned int digest_info_len, mbedtls_io_read_t io_dev_read)
{
    int (*handler)(tls_handle, void *, unsigned int,
                   void *, unsigned int, mbedtls_io_read_t);
    int ret = 0;

    handler = syscall_get_handler(SYSCALL_100_SB_TLS_VERIFY_HASH);
    if (handler) {
        ret = handler(h, data_ptr, data_len,
                      digest_info_ptr, digest_info_len, io_dev_read);
    }

    return ret;
}

int
tls_x509_get_auth_param(tls_handle h, const tls_auth_param_type_desc_t *desc,
                        void *img, unsigned int img_len,
                        void **param, unsigned int *param_len)
{
    int (*handler)(tls_handle, const tls_auth_param_type_desc_t *,
                   void *, unsigned int,
                   void **, unsigned int *);
    int ret = 0;

    handler = syscall_get_handler(SYSCALL_102_SB_TLS_X509_GET_AUTH_PARAM);
    if (handler) {
        ret = handler(h, desc, img, img_len, param, param_len);
    }

    return ret;
}

int
tls_x509_check_integrity(tls_handle h, void *img, unsigned int img_len)
{
    int (*handler)(tls_handle, void *, unsigned int);
    int ret = 0;

    handler = syscall_get_handler(SYSCALL_101_SB_TLS_X509_CHECK_INTERGRITY);
    if (handler) {
        ret = handler(h, img, img_len);
    }

    return ret;
}
