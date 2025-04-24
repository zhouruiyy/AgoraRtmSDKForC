// 引入AgoraRTM SDK
#include "IAgoraRtmLock.h"

using namespace agora;
using namespace agora::rtm;

// Agora C封装
#include "C_IAgoraRtmLock.h"

#pragma region agora

#pragma region agora::rtm

#pragma region agora_rtm_lock

AGORA_RTM_API_C_VOID agora_rtm_lock_set_lock(AGORA_RTM_HANDLE agora_rtm_lock, const char *channelName, RTM_CHANNEL_TYPE channelType, const char *lockName, uint32_t ttl, uint64_t *requestId)
{
    if (!agora_rtm_lock || !channelName || !lockName || !requestId) {
        return;
    }
    ((IRtmLock *)agora_rtm_lock)->setLock(channelName, (RTM_CHANNEL_TYPE)channelType, lockName, ttl, *requestId);
}

AGORA_RTM_API_C_VOID agora_rtm_lock_get_locks(AGORA_RTM_HANDLE agora_rtm_lock, const char *channelName, RTM_CHANNEL_TYPE channelType, uint64_t *requestId)
{
    if (!agora_rtm_lock || !channelName || !requestId) {
        return;
    }
    ((IRtmLock *)agora_rtm_lock)->getLocks(channelName, (RTM_CHANNEL_TYPE)channelType, *requestId);
}

AGORA_RTM_API_C_VOID agora_rtm_lock_remove_lock(AGORA_RTM_HANDLE agora_rtm_lock, const char *channelName, RTM_CHANNEL_TYPE channelType, const char *lockName, uint64_t *requestId)
{
    if (!agora_rtm_lock || !channelName || !lockName || !requestId) {
        return;
    }
    ((IRtmLock *)agora_rtm_lock)->removeLock(channelName, (RTM_CHANNEL_TYPE)channelType, lockName, *requestId);
}

AGORA_RTM_API_C_VOID agora_rtm_lock_acquire_lock(AGORA_RTM_HANDLE agora_rtm_lock, const char *channelName, RTM_CHANNEL_TYPE channelType, const char *lockName, bool retry, uint64_t *requestId)
{
    if (!agora_rtm_lock || !channelName || !lockName || !requestId) {
        return;
    }
    ((IRtmLock *)agora_rtm_lock)->acquireLock(channelName, (RTM_CHANNEL_TYPE)channelType, lockName, retry, *requestId);
}

AGORA_RTM_API_C_VOID agora_rtm_lock_release_lock(AGORA_RTM_HANDLE agora_rtm_lock, const char *channelName, RTM_CHANNEL_TYPE channelType, const char *lockName, uint64_t *requestId)
{
    if (!agora_rtm_lock || !channelName || !lockName || !requestId) {
        return;
    }
    ((IRtmLock *)agora_rtm_lock)->releaseLock(channelName, (RTM_CHANNEL_TYPE)channelType, lockName, *requestId);
}

AGORA_RTM_API_C_VOID agora_rtm_lock_revoke_lock(AGORA_RTM_HANDLE agora_rtm_lock, const char *channelName, RTM_CHANNEL_TYPE channelType, const char *lockName, const char *owner, uint64_t *requestId)
{
    if (!agora_rtm_lock || !channelName || !lockName || !owner || !requestId) {
        return;
    }
    ((IRtmLock *)agora_rtm_lock)->revokeLock(channelName, (RTM_CHANNEL_TYPE)channelType, lockName, owner, *requestId);
}

#pragma endregion agora_rtm_lock

#pragma endregion agora::rtm

#pragma endregion agora
