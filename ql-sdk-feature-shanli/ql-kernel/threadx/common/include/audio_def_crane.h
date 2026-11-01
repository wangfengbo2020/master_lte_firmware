#pragma once

#define FEATURE_AUDIO_16K_STREAMING         1
#define FEATURE_AUDIO_48K_STREAMING         0x3
#define CONFIG_AUDIO_HAS_AP                 0
#define CONFIG_AUDIO_NVM_TYPE               3
#define CONFIG_AUDIO_IPC_TICK               0
#define CONFIG_AUDIO_TONE_DELAY             1
#define CONFIG_AUDIO_TONE_NOTIFY            1
#define CONFIG_AUDIO_PWM_LOOKUP             1
#define CONFIG_AUDIO_PWM_RAMPUP             0

#if defined(CRANELR_SUPPORT)
#define CONFIG_AUDIO_DSP_OFF                1
#define CONFIG_AUDIO_VOICE_OFF              1
#define CONFIG_AUDIO_PLATFORM_SSPA          0x0
#define CONFIG_AUDIO_PLATFORM_SSPX          0x2
#define CONFIG_AUDIO_INTERNAL_CODEC         0x0
#define CONFIG_AUDIO_INTERNAL_CODEC_REV     0x0
#define FEATURE_AUDIO_HAL_STREAM            0
#define FEATURE_AUDIO_POC_STREAM            0
#define FEATURE_AUDIO_TONE_STREAM           0
#define FEATURE_AUDIO_VOCODER_STREAM        0
#else
#define CONFIG_AUDIO_DSP_OFF                0
#define CONFIG_AUDIO_PLATFORM_SSPA          0x1
#define CONFIG_AUDIO_INTERNAL_CODEC         0x1
#define CONFIG_AUDIO_INTERNAL_CODEC_REV     0x0200
#endif

#define INTERNAL_CODEC_REV_MAIN             ((CONFIG_AUDIO_INTERNAL_CODEC_REV & 0xff00) >> 8)
#define INTERNAL_CODEC_REV_SUB              (CONFIG_AUDIO_INTERNAL_CODEC_REV & 0xff)
