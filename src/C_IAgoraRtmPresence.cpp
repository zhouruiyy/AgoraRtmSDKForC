// 引入AgoraRTM SDK
#include "IAgoraRtmPresence.h"

using namespace agora;
using namespace agora::rtm;

// Agora C封装
#include "C_IAgoraRtmPresence.h"

#pragma region agora

#pragma region agora::rtm

#pragma region agora_rtm_presence

AGORA_RTM_API_C_INT agora_rtm_presence_who_now(AGORA_RTM_HANDLE agora_rtm_presence, const char *channelName, RTM_CHANNEL_TYPE channelType, const presence_options *options, uint64_t *requestId)
{
    if (!agora_rtm_presence || !channelName || !options || !requestId) {
        return -1;
    }
    ((IRtmPresence *)agora_rtm_presence)->whoNow(channelName, (RTM_CHANNEL_TYPE)channelType, *(const PresenceOptions *)options, *requestId);
    return 0;
}

AGORA_RTM_API_C_INT agora_rtm_presence_where_now(AGORA_RTM_HANDLE agora_rtm_presence, const char *userId, uint64_t *requestId)
{
    if (!agora_rtm_presence || !userId || !requestId) {
        return -1;
    }
    ((IRtmPresence *)agora_rtm_presence)->whereNow(userId, *requestId);
    return 0;
}

AGORA_RTM_API_C_INT agora_rtm_presence_set_state(AGORA_RTM_HANDLE agora_rtm_presence, const char *channelName, RTM_CHANNEL_TYPE channelType, const state_item *items, size_t count, uint64_t *requestId)
{
    if (!agora_rtm_presence || !channelName || !items || !requestId) {
        return -1;
    }
    ((IRtmPresence *)agora_rtm_presence)->setState(channelName, (RTM_CHANNEL_TYPE)channelType, (const StateItem *)items, count, *requestId);
    return 0;
}

AGORA_RTM_API_C_INT agora_rtm_presence_remove_state(AGORA_RTM_HANDLE agora_rtm_presence, const char *channelName, RTM_CHANNEL_TYPE channelType, const char **keys, size_t count, uint64_t *requestId)
{
    if (!agora_rtm_presence || !channelName || !keys || !requestId) {
        return -1;
    }
    ((IRtmPresence *)agora_rtm_presence)->removeState(channelName, (RTM_CHANNEL_TYPE)channelType, keys, count, *requestId);
    return 0;
}

AGORA_RTM_API_C_INT agora_rtm_presence_get_state(AGORA_RTM_HANDLE agora_rtm_presence, const char *channelName, RTM_CHANNEL_TYPE channelType, const char *userId, uint64_t *requestId)
{
    if (!agora_rtm_presence || !channelName || !userId || !requestId) {
        return -1;
    }
    ((IRtmPresence *)agora_rtm_presence)->getState(channelName, (RTM_CHANNEL_TYPE)channelType, userId, *requestId);
    return 0;
}

AGORA_RTM_API_C_INT agora_rtm_presence_get_online_users(AGORA_RTM_HANDLE agora_rtm_presence, const char *channelName, RTM_CHANNEL_TYPE channelType, const get_online_users_options *options, uint64_t *requestId)
{
    if (!agora_rtm_presence || !channelName || !options || !requestId) {
        return -1;
    }
    ((IRtmPresence *)agora_rtm_presence)->getOnlineUsers(channelName, (RTM_CHANNEL_TYPE)channelType, *(const GetOnlineUsersOptions *)options, *requestId);
    return 0;
}

AGORA_RTM_API_C_INT agora_rtm_presence_get_user_channels(AGORA_RTM_HANDLE agora_rtm_presence, const char *userId, uint64_t *requestId)
{
    if (!agora_rtm_presence || !userId || !requestId) {
        return -1;
    }
    ((IRtmPresence *)agora_rtm_presence)->getUserChannels(userId, *requestId);
    return 0;
}
#pragma endregion agora_rtm_presence

#pragma endregion agora::rtm

#pragma endregion agora
