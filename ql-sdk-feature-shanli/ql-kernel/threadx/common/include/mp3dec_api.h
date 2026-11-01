/******************************************************************************
 *
 *  (C)Copyright ASRMicro. All Rights Reserved.
 *
 *  THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF ASRMicro.
 *  The copyright notice above does not evidence any actual or intended
 *  publication of such source code.
 *  This Module contains Proprietary Information of ASRMicro and should be
 *  treated as Confidential.
 *  The information in this file is provided for the exclusive use of the
 *  licensees of ASRMicro.
 *  Such users have the right to use, modify, and incorporate this code into
 *  products for purposes authorized by the license agreement provided they
 *  include this notice and the associated copyright notice with any such
 *  product.
 *  The information in this file is provided "AS IS" without warranty.
 *
 ******************************************************************************/

#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include "acm_audio_def.h"

    /**
    * @file mp3dec_api.h
    * @brief ASR mp3 API describes the process and functions used for MP3 decoder and related playback.
    * @addtogroup AUDIO_APPLICATION_MP3
    * @{
    */

    typedef enum Mp3PlayEventValue {
        /** play out all for file or stream*/
        MP3_PLAYBACK_STATUS_ENDED = 0,
        /** indicate current playback is started*/
        MP3_PLAYBACK_STATUS_STARTED,
        /** indicate output device is opened*/
        MP3_PLAYBACK_STATUS_OPENED,
        /** reach file end*/
        MP3_PLAYBACK_STATUS_FILE_READED,
        /** reach timeout setting*/
        MP3_PLAYBACK_STATUS_TIMEOUT,
        /** indicate current playback is started for pcm processing*/
        MP3_PLAYBACK_STATUS_PCM_STARTED,

        MP3_PLAYBACK_STATUS_STREAM = 100,
        /** indicate mp3 data producer should slow down to avoid overrun*/
        MP3_STREAM_STATUS_NEARLY_OVERRUN,
        MP3_STREAM_STATUS_SLOW_DOWN = MP3_STREAM_STATUS_NEARLY_OVERRUN,
        /** indicate mp3 data producer should fast up to avoid underrun*/
        MP3_STREAM_STATUS_NEARLY_UNDERRUN,
        MP3_STREAM_STATUS_FAST_UP = MP3_STREAM_STATUS_NEARLY_UNDERRUN,
        /** indicate mp3 data producer could stop since data blocks written are consumed*/
        MP3_STREAM_STATUS_UNDERRUN,
    }Mp3PlayEventValue;

    typedef enum Mp3PlayEventType {
        /** mp3 playback status, value with type @ref Mp3PlayEventValue*/
        MP3_PLAYBACK_EVENT_STATUS,
        /** id3 header size, value with type int*/
        MP3_FILE_EVENT_ID3OFFSET,
        /** sample rate, value with type int*/
        MP3_FILE_EVENT_SAMPLERATE,
        /** channel, value with type int*/
        MP3_FILE_EVENT_CHANNEL,
        /** bit rat, value with type int*/
        MP3_FILE_EVENT_BITRATE,
        /** file name request, value with type char* */
        MP3_FILE_EVENT_FILENAME,
        /** playback position, value with type int* */
        MP3_FILE_EVENT_POSITION,
    }Mp3PlayEventType;

    typedef enum Mp3PlayInfoType {
        /** pcm stream handle to correspond the current decoder*/
        MP3_PLAYBACK_INFO_PCM_HANDLE,
        /** current playback position*/
        MP3_PLAYBACK_INFO_POSITION,
        /** current playback duration*/
        MP3_PLAYBACK_INFO_DURATION,
        /** how many pcm samples per mp3 frame*/
        MP3_PLAYBACK_INFO_SAMPLE_COUNT,
        /** offset of the first valid mp3 frame*/
        MP3_PLAYBACK_INFO_FRAME_OFFSET,
        /** size of one mp3 frame*/
        MP3_PLAYBACK_INFO_FRAME_SIZE,
        /** how many mp3 frames parsed*/
        MP3_PLAYBACK_INFO_FRAME_COUNT,
        /** how many mp3 frames parsed from VBR header*/
        MP3_PLAYBACK_INFO_FRAME_COUNT_TOTAL,
        /** sample rate of decoded pcm*/
        MP3_PLAYBACK_INFO_PCM_RATE,
        /** channel of decoded pcm*/
        MP3_PLAYBACK_INFO_PCM_CHANNEL,
        /** bit rate of the current mp3 frame*/
        MP3_PLAYBACK_INFO_BIT_RATE,
    }Mp3PlayInfoType;

    /** mp3 playback handle, held and used by mp3 playback user*/
    typedef uint32_t Mp3PlaybackHandle;
    /** mp3 playback event callback prototype*/
    typedef void(*Mp3PlaybackEventCallback)(Mp3PlayEventType, int);
    /** mp3 playback event callback prototype*/
    typedef void(*Mp3PlaybackEventCallback2)(Mp3PlayEventType, int, Mp3PlaybackHandle);

    typedef struct Mp3PlayConfigInfo {
        /** mp3 playback property in bitmap format, refer @ref AUDIO_PLAY_OPTION in @ref acm_audio_def.h*/
        int64_t option;
        /** block size for file only, 0 for frame mode*/
        int block_size;
        /** how many mp3 frames will be skipped before playback*/
        int skip_frames;
        /** how many mp3 frames will be held before playback*/
        int cache_frames;
        /** user registers callback to get playback event such as file end etc */
        Mp3PlaybackEventCallback listener;
        /** user registers callback to get playback event with handle */
        Mp3PlaybackEventCallback2 listener2;
        /** how many milliseconds before trigger auto stop*/
        int timeout;
        /** @deprecated start with sync mode*/
        int sync_mode;
    }Mp3PlayConfigInfo;

    typedef Mp3PlayConfigInfo Mp3StreamConfigInfo;

    typedef struct Mp3StreamDataInfo {
        /** mp3 playback handle held by user, used to send following mp3 data to corresponding stream instance*/
        Mp3PlaybackHandle handle;
        /** user space mp3 data ptr*/
        uint8_t* buf;
        /** user space mp3 data size*/
        uint32_t size;
    }Mp3StreamDataInfo;

    /** Start mp3 file playback with default property.
    * @param [in] name                  mp3 file name
    * @returns error code in int, non-zero on failure
    */
    int mp3Start(const char* file_name);

    /** Stop all the mp3 file playbacks ongoing.
    * @returns error code in int, non-zero on failure
    */
    int mp3Stop(void);

    /** Start mp3 file playback with dedicated property.
    * @param [in] name                  mp3 file name
    * @param [in] configInfo            mp3 file playback settings
    * @param [in,out] handle            mp3 playback handle
    * @returns error code in int, non-zero on failure
    */
    int mp3PlayStart(const char* file_name, const Mp3PlayConfigInfo* configInfo, Mp3PlaybackHandle* handle);

    /** Stop mp3 file playback with handle.
    * @param [in] handle                mp3 playback handle
    * @param [in] drain                 drain or not
    * @returns error code in int, non-zero on failure
    */
    int mp3PlayStop(Mp3PlaybackHandle handle, int drain);

    /** Stop mp3 file playback with file name.
    * @param [in] file_name             mp3 file name
    * @param [in] drain                 drain or not
    * @returns error code in int, non-zero on failure
    */
    int mp3PlayStopWithName(const char* file_name, int drain);

    /** Get mp3 file playback duration.
    * @param [in] name                  mp3 file name
    * @param [in,out] duration          duration in millisecond
    * @returns error code in int, non-zero on failure
    */
    int mp3PlayGetDuration(const char* file_name, int* duration);

    /** Get specific playback information.
    * @param [in] handle                mp3 playback handle
    * @param [in] type                  mp3 playback information type
    * @param [in,out] value             mp3 playback information value
    * @returns error code in int, non-zero on failure
    */
    int mp3PlayGetInfo(Mp3PlaybackHandle handle, Mp3PlayInfoType type, int* value);

    /** Start mp3 stream playback with dedicated configuration.
    * @param [in] configInfo            mp3 stream playback configuration
    * @param [in,out] handle            mp3 playback handle
    * @returns error code in int, non-zero on failure
    */
    int mp3StreamStart(const Mp3StreamConfigInfo* configInfo, Mp3PlaybackHandle* handle);

    /** Send one mp3 data block from mp3 stream data producer.
    * @param [in] dataInfo              mp3 data block
    * @returns error code in int, non-zero on failure
    */
    int mp3StreamPlayBuffer(const Mp3StreamDataInfo* dataInfo);

    /** Stop mp3 stream playback with handle.
    * @param [in] handle                mp3 playback handle
    * @param [in] drain                 drain or not
    * @returns error code in int, non-zero on failure
    */
    int mp3StreamStop(Mp3PlaybackHandle handle, int drain);

    /** Get audio track handle, which is used to manipulate pcm stream.
    * @param [in] handle                mp3 playback handle
    * @param [in,out] pcm_handle        pcm stream out handle
    * @returns error code in int, non-zero on failure
    */
    int mp3GetPCMOutHandle(Mp3PlaybackHandle handle, uint32_t* pcm_handle);

    /** Init mp3 playback resource.
    * @note for mp3 playback user do @b not call this api!
    */
    void mp3PlayInit(void);

    /** @} AUDIO_APPLICATION_MP3*/
#ifdef __cplusplus
}
#endif
