#ifndef C_I_AGORA_RTM_HISTORY_H
#define C_I_AGORA_RTM_HISTORY_H

#include "agora_rtm_api.h"

#include "C_AgoraRtmBase.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

// Get History Messages Options
typedef struct _get_history_messages_options {
    int64_t start;
    int64_t end;
    int count;
} get_history_messages_options;

#pragma region agora

#pragma region agora::rtm

#pragma region agora_rtm_history

/**
 * Gets history messages in the channel.
 *
 * @param [in] channelName The name of the channel.
 * @param [in] channelType The type of the channel.
 * @param [in] options The query options.
 * @param [out] requestId The related request id of this operation.
 * @return
 * - 0: Success.
 * - < 0: Failure.
 */
AGORA_RTM_API_C_INT agora_rtm_history_get_messages(AGORA_RTM_HANDLE agora_rtm_history, const char* channelName, C_RTM_CHANNEL_TYPE channelType, const get_history_messages_options* options, uint64_t* requestId);

#pragma endregion agora_rtm_history

#pragma endregion agora::rtm

#pragma endregion agora

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_I_AGORA_RTM_HISTORY_H 