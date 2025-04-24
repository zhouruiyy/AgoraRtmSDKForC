#ifndef C_I_AGORA_RTM_LOCK_H
#define C_I_AGORA_RTM_LOCK_H

#include "agora_rtm_api.h"

#include "C_AgoraRtmBase.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#pragma region agora

#pragma region agora::rtm

  /**
   * The IRtmLock class.
   *
   * This class provides the rtm lock methods that can be invoked by your app.
   */
#pragma region agora_rtm_lock
  /**
   * sets a lock
   *
   * @param [in] channelName The name of the channel.
   * @param [in] channelType The type of the channel.
   * @param [in] lockName The name of the lock.
   * @param [in] ttl The lock ttl.
   * @param [out] requestId The related request id of this operation.
   */
  AGORA_RTM_API_C_VOID agora_rtm_lock_set_lock(AGORA_RTM_HANDLE agora_rtm_lock, const char *channelName, C_RTM_CHANNEL_TYPE channelType, const char *lockName, uint32_t ttl, uint64_t *requestId);

  /**
   * gets locks in the channel
   *
   * @param [in] channelName The name of the channel.
   * @param [in] channelType The type of the channel.
   * @param [out] requestId The related request id of this operation.
   */
  AGORA_RTM_API_C_VOID agora_rtm_lock_get_locks(AGORA_RTM_HANDLE agora_rtm_lock, const char *channelName, C_RTM_CHANNEL_TYPE channelType, uint64_t *requestId);

  /**
   * removes a lock
   *
   * @param [in] channelName The name of the channel.
   * @param [in] channelType The type of the channel.
   * @param [in] lockName The name of the lock.
   * @param [out] requestId The related request id of this operation.
   */
  AGORA_RTM_API_C_VOID agora_rtm_lock_remove_lock(AGORA_RTM_HANDLE agora_rtm_lock, const char *channelName, C_RTM_CHANNEL_TYPE channelType, const char *lockName, uint64_t *requestId);

  /**
   * acquires a lock
   *
   * @param [in] channelName The name of the channel.
   * @param [in] channelType The type of the channel.
   * @param [in] lockName The name of the lock.
   * @param [in] retry Whether to automatically retry when acquires lock failed
   * @param [out] requestId The related request id of this operation.
   */
  AGORA_RTM_API_C_VOID agora_rtm_lock_acquire_lock(AGORA_RTM_HANDLE agora_rtm_lock, const char *channelName, C_RTM_CHANNEL_TYPE channelType, const char *lockName, bool retry, uint64_t *requestId);

  /**
   * releases a lock
   *
   * @param [in] channelName The name of the channel.
   * @param [in] channelType The type of the channel.
   * @param [in] lockName The name of the lock.
   * @param [out] requestId The related request id of this operation.
   */
  AGORA_RTM_API_C_VOID agora_rtm_lock_release_lock(AGORA_RTM_HANDLE agora_rtm_lock, const char *channelName, C_RTM_CHANNEL_TYPE channelType, const char *lockName, uint64_t *requestId);

  /**
   * disables a lock
   *
   * @param [in] channelName The name of the channel.
   * @param [in] channelType The type of the channel.
   * @param [in] lockName The name of the lock.
   * @param [in] owner The lock owner.
   * @param [out] requestId The related request id of this operation.
   */
  AGORA_RTM_API_C_VOID agora_rtm_lock_revoke_lock(AGORA_RTM_HANDLE agora_rtm_lock, const char *channelName, C_RTM_CHANNEL_TYPE channelType, const char *lockName, const char *owner, uint64_t *requestId);

#pragma endregion agora_rtm_lock

#pragma endregion agora::rtm

#pragma endregion agora

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_I_AGORA_RTM_LOCK_H
