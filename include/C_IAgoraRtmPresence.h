#ifndef C_I_AGORA_RTM_PRESENCE_H
#define C_I_AGORA_RTM_PRESENCE_H

#include "agora_rtm_api.h"
#include "C_AgoraRtmBase.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#pragma region agora

#pragma region agora::rtm

  /**
   * The IRtmPresence class.
   *
   * This class provides the rtm presence methods that can be invoked by your app.
   */
#pragma region agora_rtm_presence
  /**
   * To query who joined this channel
   *
   * @param [in] channelName The name of the channel.
   * @param [in] channelType The type of the channel.
   * @param [in] options The query option.
   * @param [out] requestId The related request id of this operation.
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  AGORA_RTM_API_C_INT agora_rtm_presence_who_now(AGORA_RTM_HANDLE agora_rtm_presence, const char *channelName, C_RTM_CHANNEL_TYPE channelType, const presence_options *options, uint64_t *requestId);

  /**
   * To query which channels the user joined
   *
   * @param [in] userId The id of the user.
   * @param [out] requestId The related request id of this operation.
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  AGORA_RTM_API_C_INT agora_rtm_presence_where_now(AGORA_RTM_HANDLE agora_rtm_presence, const char *userId, uint64_t *requestId);

  /**
   * Set user state
   *
   * @param [in] channelName The name of the channel.
   * @param [in] channelType The type of the channel.
   * @param [in] items The states item of user.
   * @param [in] count The count of states item.
   * @param [out] requestId The related request id of this operation.
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  AGORA_RTM_API_C_INT agora_rtm_presence_set_state(AGORA_RTM_HANDLE agora_rtm_presence, const char *channelName, C_RTM_CHANNEL_TYPE channelType, const state_item *items, size_t count, uint64_t *requestId);

  /**
   * Delete user state
   *
   * @param [in] channelName The name of the channel.
   * @param [in] channelType The type of the channel.
   * @param [in] keys The keys of state item.
   * @param [in] count The count of keys.
   * @param [out] requestId The related request id of this operation.
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  AGORA_RTM_API_C_INT agora_rtm_presence_remove_state(AGORA_RTM_HANDLE agora_rtm_presence, const char *channelName, C_RTM_CHANNEL_TYPE channelType, const char **keys, size_t count, uint64_t *requestId);

  /**
   * Get user state
   *
   * @param [in] channelName The name of the channel.
   * @param [in] channelType The type of the channel.
   * @param [in] userId The id of the user.
   * @param [out] requestId The related request id of this operation.
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  AGORA_RTM_API_C_INT agora_rtm_presence_get_state(AGORA_RTM_HANDLE agora_rtm_presence, const char *channelName, C_RTM_CHANNEL_TYPE channelType, const char *userId, uint64_t *requestId);

  /**
   * To query who joined this channel
   *
   * @param [in] channelName The name of the channel.
   * @param [in] channelType The type of the channel.
   * @param [in] options The query option.
   * @param [out] requestId The related request id of this operation.
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  AGORA_RTM_API_C_INT agora_rtm_presence_get_online_users(AGORA_RTM_HANDLE agora_rtm_presence, const char *channelName, C_RTM_CHANNEL_TYPE channelType, const get_online_users_options *options, uint64_t *requestId);

  /**
   * To query which channels the user joined
   *
   * @param [in] userId The id of the user.
   * @param [out] requestId The related request id of this operation.
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  AGORA_RTM_API_C_INT agora_rtm_presence_get_user_channels(AGORA_RTM_HANDLE agora_rtm_presence, const char *userId, uint64_t *requestId);

#pragma endregion agora_rtm_presence

#pragma endregion agora::rtm

#pragma endregion agora

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_I_AGORA_RTM_PRESENCE_H
