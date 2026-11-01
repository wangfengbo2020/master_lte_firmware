#pragma once

/**
* @file audio_def.h
* @brief ASR audio macros that define the audio configurations.
*/

#include "audio_def_crane.h"

#if CONFIG_AUDIO_HAS_AP == 0
#include "audio_api_cfg.h"
#endif

#if FEATURE_AUDIO_PWM_TRANSFORM != 0
extern int _AUDIO_PROCESS_PERIOD;
#define AUDIO_PROCESS_PERIOD    _AUDIO_PROCESS_PERIOD
#endif
