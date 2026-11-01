#pragma once

/**
* @file audio_api_cfg.h
* @brief ASR audio macros that define the audio capabilities which can be customized.
*/

#ifndef CONFIG_AUDIO_VOICE_OFF
#define CONFIG_AUDIO_VOICE_OFF          0
#endif

#ifndef CONFIG_AUDIO_PLATFORM_SSPX
#define CONFIG_AUDIO_PLATFORM_SSPX      0x0
#endif

#ifndef FEATURE_AUDIO_TRACK
#define FEATURE_AUDIO_TRACK             1
#endif

#ifndef FEATURE_AUDIO_RECORD
#define FEATURE_AUDIO_RECORD            1
#endif

#ifndef FEATURE_AUDIO_TONE_STREAM
#define FEATURE_AUDIO_TONE_STREAM       1
#endif

#ifndef FEATURE_AUDIO_VOCODER_STREAM
#define FEATURE_AUDIO_VOCODER_STREAM    1
#endif

#ifndef FEATURE_AUDIO_HAL_STREAM
#define FEATURE_AUDIO_HAL_STREAM        1
#endif

#ifndef FEATURE_AUDIO_POC_STREAM
#define FEATURE_AUDIO_POC_STREAM        1
#endif

#ifndef FEATURE_AUDIO_DEVICE_OPT
#ifdef QUECTEL_OPEN_CPU
// bit0置为1: 单独录音时不打开内置codec的DAC以及PA
// bit1置为1: 单独播放时不打开内置codec的ADC
// bit2置为1: 可以兼容使用AC profile 
#define FEATURE_AUDIO_DEVICE_OPT        0x5 //open use 0x5
#else 
#define FEATURE_AUDIO_DEVICE_OPT        0x0 
#endif
#endif

#ifndef FEATURE_AUDIO_DRC_ENHANCE
#define FEATURE_AUDIO_DRC_ENHANCE       1
#endif

#ifndef FEATURE_AUDIO_PWM_TRANSFORM
#define FEATURE_AUDIO_PWM_TRANSFORM     0
#endif
