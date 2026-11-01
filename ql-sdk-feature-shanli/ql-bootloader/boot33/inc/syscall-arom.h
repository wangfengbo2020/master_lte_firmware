#ifndef _SYSCALL_AROM_H_
#define _SYSCALL_AROM_H_

typedef enum {
    /* cpu */
    SYSCALL_07_HW_PLATFORM_TYPE                 = 7,
    /* secureboot */
    SYSCALL_25_SB_FIP_IMAGE_SETUP               = 25,
    SYSCALL_26_SB_VOLUME_READ                   = 26,
    SYSCALL_27_SB_AUTH_IMAGE                    = 27,
    SYSCALL_28_SB_FLASH_READ                    = 28,
    SYSCALL_73_ABOOT_SYS_GETVERSION             = 73,
    /* syscall */
    SYSCALL_74_GET_SYSCALL_TABLE                = 74,
    /* secureboot */
    SYSCALL_75_TRANSFER_CONTROL                 = 75,
    /* secureboot */
    SYSCALL_97_SB_TLS_INIT                      = 97,
    SYSCALL_98_SB_TLS_DEINIT                    = 98,
    SYSCALL_99_SB_TLS_VERIFY_SIGNATURE          = 99,
    SYSCALL_100_SB_TLS_VERIFY_HASH              = 100,
    SYSCALL_101_SB_TLS_X509_CHECK_INTERGRITY    = 101,
    SYSCALL_102_SB_TLS_X509_GET_AUTH_PARAM      = 102,
    SYSCALL_103_PROCESS_POLL                    = 103,
    SYSCALL_104_PROCESS_POST_SYNCH              = 104,

    SYSCALL_MAX                                 = 128,
} syscall_t;
/*---------------------------------------------------------------------------*/
void syscall_init(void);
void *syscall_get_handler(syscall_t index);
void **syscall_get_table(void);

#endif
