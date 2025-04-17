// 引入AgoraRTM SDK
#include "IAgoraRtmLock.h"

using namespace agora;
using namespace agora::rtm;

// Agora C封装
#include "C_IAgoraRtmLock.h"

#pragma region agora

#pragma region agora::rtm

#pragma region C_IRtmLock

void agora_rtm_lock_set_lock(C_IRtmLock *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, uint32_t ttl, uint64_t *requestId)
{
    if (!this_ || !channelName || !lockName || !requestId) {
        return;
    }
    ((IRtmLock *)this_)->setLock(channelName, (RTM_CHANNEL_TYPE)channelType, lockName, ttl, *requestId);
}

void agora_rtm_lock_get_locks(C_IRtmLock *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, uint64_t *requestId)
{
    if (!this_ || !channelName || !requestId) {
        return;
    }
    ((IRtmLock *)this_)->getLocks(channelName, (RTM_CHANNEL_TYPE)channelType, *requestId);
}

void agora_rtm_lock_remove_lock(C_IRtmLock *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, uint64_t *requestId)
{
    if (!this_ || !channelName || !lockName || !requestId) {
        return;
    }
    ((IRtmLock *)this_)->removeLock(channelName, (RTM_CHANNEL_TYPE)channelType, lockName, *requestId);
}

void agora_rtm_lock_acquire_lock(C_IRtmLock *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, bool retry, uint64_t *requestId)
{
    if (!this_ || !channelName || !lockName || !requestId) {
        return;
    }
    ((IRtmLock *)this_)->acquireLock(channelName, (RTM_CHANNEL_TYPE)channelType, lockName, retry, *requestId);
}

void agora_rtm_lock_release_lock(C_IRtmLock *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, uint64_t *requestId)
{
    if (!this_ || !channelName || !lockName || !requestId) {
        return;
    }
    ((IRtmLock *)this_)->releaseLock(channelName, (RTM_CHANNEL_TYPE)channelType, lockName, *requestId);
}

void agora_rtm_lock_revoke_lock(C_IRtmLock *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, const char *owner, uint64_t *requestId)
{
    if (!this_ || !channelName || !lockName || !owner || !requestId) {
        return;
    }
    ((IRtmLock *)this_)->revokeLock(channelName, (RTM_CHANNEL_TYPE)channelType, lockName, owner, *requestId);
}

#pragma endregion C_IRtmLock

#pragma endregion agora::rtm

#pragma endregion agora
