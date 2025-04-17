// 引入AgoraRTM SDK
#include "IAgoraRtmPresence.h"

using namespace agora;
using namespace agora::rtm;

// Agora C封装
#include "C_IAgoraRtmPresence.h"

#pragma region agora

#pragma region agora::rtm

#pragma region C_IRtmPresence

int C_IRtmPresence_whoNow(C_IRtmPresence *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const struct C_PresenceOptions *options, uint64_t *requestId)
{
    if (!this_ || !channelName || !options || !requestId) {
        return -1;
    }
    ((IRtmPresence *)this_)->whoNow(channelName, (RTM_CHANNEL_TYPE)channelType, *(const PresenceOptions *)options, *requestId);
    return 0;
}

int C_IRtmPresence_whereNow(C_IRtmPresence *this_, const char *userId, uint64_t *requestId)
{
    if (!this_ || !userId || !requestId) {
        return -1;
    }
    ((IRtmPresence *)this_)->whereNow(userId, *requestId);
    return 0;
}

int C_IRtmPresence_setState(C_IRtmPresence *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const struct C_StateItem *items, size_t count, uint64_t *requestId)
{
    if (!this_ || !channelName || !items || !requestId) {
        return -1;
    }
    ((IRtmPresence *)this_)->setState(channelName, (RTM_CHANNEL_TYPE)channelType, (const StateItem *)items, count, *requestId);
    return 0;
}

int C_IRtmPresence_removeState(C_IRtmPresence *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char **keys, size_t count, uint64_t *requestId)
{
    if (!this_ || !channelName || !keys || !requestId) {
        return -1;
    }
    ((IRtmPresence *)this_)->removeState(channelName, (RTM_CHANNEL_TYPE)channelType, keys, count, *requestId);
    return 0;
}

int C_IRtmPresence_getState(C_IRtmPresence *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *userId, uint64_t *requestId)
{
    if (!this_ || !channelName || !userId || !requestId) {
        return -1;
    }
    ((IRtmPresence *)this_)->getState(channelName, (RTM_CHANNEL_TYPE)channelType, userId, *requestId);
    return 0;
}

int C_IRtmPresence_getOnlineUsers(C_IRtmPresence *this_, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const struct C_GetOnlineUsersOptions *options, uint64_t *requestId)
{
    if (!this_ || !channelName || !options || !requestId) {
        return -1;
    }
    ((IRtmPresence *)this_)->getOnlineUsers(channelName, (RTM_CHANNEL_TYPE)channelType, *(const GetOnlineUsersOptions *)options, *requestId);
    return 0;
}

int C_IRtmPresence_getUserChannels(C_IRtmPresence *this_, const char *userId, uint64_t *requestId)
{
    if (!this_ || !userId || !requestId) {
        return -1;
    }
    ((IRtmPresence *)this_)->getUserChannels(userId, *requestId);
    return 0;
}
#pragma endregion C_IRtmPresence

#pragma endregion agora::rtm

#pragma endregion agora
