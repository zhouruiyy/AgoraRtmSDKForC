// 引入AgoraRTM SDK
#include "IAgoraRtmClient.h"
#include "IAgoraRtmStorage.h"
#include "IAgoraRtmPresence.h"
#include "IAgoraRtmLock.h"
#include "IAgoraRtmHistory.h"
#include "IAgoraStreamChannel.h"

using namespace agora;
using namespace agora::rtm;

// Agora C封装
#include "C_IAgoraRtmClient.h"

#pragma region agora

#pragma region agora::rtm

rtm_config *rtm_config_create()
{
    return (rtm_config *)(new RtmConfig());
}
void rtm_config_delete(rtm_config *this_)
{
    delete (RtmConfig *)(this_);
}

#pragma region C_IRtmEventHandler

message_event *message_event_create()
{
    return (message_event *)(new agora::rtm::IRtmEventHandler::MessageEvent());
}
void message_event_delete(message_event *this_)
{
    delete (agora::rtm::IRtmEventHandler::MessageEvent *)(this_);
}

interval_info *interval_info_create()
{
    return (interval_info *)(new agora::rtm::IRtmEventHandler::PresenceEvent::IntervalInfo());
}
void interval_info_delete(interval_info *this_)
{
    delete (agora::rtm::IRtmEventHandler::PresenceEvent::IntervalInfo *)(this_);
}

snapshot_info *snapshot_info_create()
{
    return (snapshot_info *)(new agora::rtm::IRtmEventHandler::PresenceEvent::SnapshotInfo());
}
void snapshot_info_delete(snapshot_info *this_)
{
    delete (agora::rtm::IRtmEventHandler::PresenceEvent::SnapshotInfo *)(this_);
}

presence_event *presence_event_create()
{
    return (presence_event *)(new agora::rtm::IRtmEventHandler::PresenceEvent());
}
void presence_event_delete(presence_event *this_)
{
    delete (agora::rtm::IRtmEventHandler::PresenceEvent *)(this_);
}

topic_event *topic_event_create()
{
    return (topic_event *)(new agora::rtm::IRtmEventHandler::TopicEvent());
}
void topic_event_delete(topic_event *this_)
{
    delete (agora::rtm::IRtmEventHandler::TopicEvent *)(this_);
}

lock_event *lock_event_create()
{
    return (lock_event *)(new agora::rtm::IRtmEventHandler::LockEvent());
}
void lock_event_delete(lock_event *this_)
{
    delete (agora::rtm::IRtmEventHandler::LockEvent *)(this_);
}

storage_event *storage_event_create()
{
    return (storage_event *)(new agora::rtm::IRtmEventHandler::StorageEvent());
}
void storage_event_delete(storage_event *this_)
{
    delete (agora::rtm::IRtmEventHandler::StorageEvent *)(this_);
}

void C_IRtmEventHandler_onMessageEvent(C_IRtmEventHandler *this_, const message_event *event)
{
    ((IRtmEventHandler *)this_)->onMessageEvent(*(const IRtmEventHandler::MessageEvent *)event);
}

void C_IRtmEventHandler_onPresenceEvent(C_IRtmEventHandler *this_, const presence_event *event)
{
    ((IRtmEventHandler *)this_)->onPresenceEvent(*(const IRtmEventHandler::PresenceEvent *)event);
}

void C_IRtmEventHandler_onTopicEvent(C_IRtmEventHandler *this_, const topic_event *event)
{
    ((IRtmEventHandler *)this_)->onTopicEvent(*(const IRtmEventHandler::TopicEvent *)event);
}

void C_IRtmEventHandler_onLockEvent(C_IRtmEventHandler *this_, const lock_event *event)
{
    ((IRtmEventHandler *)this_)->onLockEvent(*(const IRtmEventHandler::LockEvent *)event);
}

void C_IRtmEventHandler_onStorageEvent(C_IRtmEventHandler *this_, const storage_event *event)
{
    ((IRtmEventHandler *)this_)->onStorageEvent(*(const IRtmEventHandler::StorageEvent *)event);
}

void C_IRtmEventHandler_onJoinResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *userId, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onJoinResult(requestId, channelName, userId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onLeaveResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *userId, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onLeaveResult(requestId, channelName, userId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onJoinTopicResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *userId, const char *topic, const char *meta, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onJoinTopicResult(requestId, channelName, userId, topic, meta, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onLeaveTopicResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *userId, const char *topic, const char *meta, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onLeaveTopicResult(requestId, channelName, userId, topic, meta, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onSubscribeTopicResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *userId, const char *topic, user_list succeedUsers, user_list failedUsers, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onSubscribeTopicResult(requestId, channelName, userId, topic, *(UserList *)&succeedUsers, *(UserList *)&failedUsers, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onConnectionStateChanged(C_IRtmEventHandler *this_, const char *channelName, C_RTM_CONNECTION_STATE state, C_RTM_CONNECTION_CHANGE_REASON reason)
{
    ((IRtmEventHandler *)this_)->onConnectionStateChanged(channelName, (RTM_CONNECTION_STATE)state, (RTM_CONNECTION_CHANGE_REASON)reason);
}

void C_IRtmEventHandler_onTokenPrivilegeWillExpire(C_IRtmEventHandler *this_, const char *channelName)
{
    ((IRtmEventHandler *)this_)->onTokenPrivilegeWillExpire(channelName);
}

void C_IRtmEventHandler_onSubscribeResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onSubscribeResult(requestId, channelName, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onPublishResult(C_IRtmEventHandler *this_, const uint64_t requestId, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onPublishResult(requestId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onLoginResult(C_IRtmEventHandler *this_, const uint64_t requestId, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onLoginResult(requestId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onSetChannelMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, C_RTM_CHANNEL_TYPE channelType, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onSetChannelMetadataResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onUpdateChannelMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, C_RTM_CHANNEL_TYPE channelType, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onUpdateChannelMetadataResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onRemoveChannelMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, C_RTM_CHANNEL_TYPE channelType, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onRemoveChannelMetadataResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onGetChannelMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, C_RTM_CHANNEL_TYPE channelType, const metadata *data, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onGetChannelMetadataResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, *(const Metadata *)data, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onSetUserMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *userId, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onSetUserMetadataResult(requestId, userId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onUpdateUserMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *userId, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onUpdateUserMetadataResult(requestId, userId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onRemoveUserMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *userId, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onRemoveUserMetadataResult(requestId, userId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onGetUserMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *userId, const metadata *data, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onGetUserMetadataResult(requestId, userId, *(const Metadata *)data, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onSubscribeUserMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *userId, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onSubscribeUserMetadataResult(requestId, userId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onSetLockResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, C_RTM_CHANNEL_TYPE channelType, const char *lockName, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onSetLockResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, lockName, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onRemoveLockResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, C_RTM_CHANNEL_TYPE channelType, const char *lockName, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onRemoveLockResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, lockName, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onReleaseLockResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, C_RTM_CHANNEL_TYPE channelType, const char *lockName, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onReleaseLockResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, lockName, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onAcquireLockResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, C_RTM_CHANNEL_TYPE channelType, const char *lockName, C_RTM_ERROR_CODE errorCode, const char *errorDetails)
{
    ((IRtmEventHandler *)this_)->onAcquireLockResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, lockName, (RTM_ERROR_CODE)errorCode, errorDetails);
}

void C_IRtmEventHandler_onRevokeLockResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, C_RTM_CHANNEL_TYPE channelType, const char *lockName, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onRevokeLockResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, lockName, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onGetLocksResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, C_RTM_CHANNEL_TYPE channelType, const lock_detail *lockDetailList, const size_t count, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onGetLocksResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, (const LockDetail *)lockDetailList, count, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onWhoNowResult(C_IRtmEventHandler *this_, const uint64_t requestId, const user_state *userStateList, const size_t count, const char *nextPage, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onWhoNowResult(requestId, (const UserState *)userStateList, count, nextPage, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onGetOnlineUsersResult(C_IRtmEventHandler *this_, const uint64_t requestId, const user_state *userStateList, const size_t count, const char *nextPage, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onGetOnlineUsersResult(requestId, (const UserState *)userStateList, count, nextPage, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onWhereNowResult(C_IRtmEventHandler *this_, const uint64_t requestId, const channel_info *channels, const size_t count, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onWhereNowResult(requestId, (const ChannelInfo *)channels, count, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onGetUserChannelsResult(C_IRtmEventHandler *this_, const uint64_t requestId, const channel_info *channels, const size_t count, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onGetUserChannelsResult(requestId, (const ChannelInfo *)channels, count, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onPresenceSetStateResult(C_IRtmEventHandler *this_, const uint64_t requestId, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onPresenceSetStateResult(requestId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onPresenceRemoveStateResult(C_IRtmEventHandler *this_, const uint64_t requestId, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onPresenceRemoveStateResult(requestId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onPresenceGetStateResult(C_IRtmEventHandler *this_, const uint64_t requestId, const user_state *state, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onPresenceGetStateResult(requestId, *(const UserState *)state, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onLogoutResult(C_IRtmEventHandler *this_, const uint64_t requestId, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onLogoutResult(requestId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onRenewTokenResult(C_IRtmEventHandler *this_, const uint64_t requestId, C_RTM_SERVICE_TYPE serverType, const char *channelName, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onRenewTokenResult(requestId, (RTM_SERVICE_TYPE)serverType, channelName, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onPublishTopicMessageResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *topic, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onPublishTopicMessageResult(requestId, channelName, topic, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onUnsubscribeTopicResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *topic, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onUnsubscribeTopicResult(requestId, channelName, topic, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onGetSubscribedUserListResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *topic, user_list users, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onGetSubscribedUserListResult(requestId, channelName, topic, *(UserList *)&users, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onUnsubscribeUserMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *userId, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onUnsubscribeUserMetadataResult(requestId, userId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onGetHistoryMessagesResult(C_IRtmEventHandler *this_, const uint64_t requestId, const history_message *messageList, const size_t count, const uint64_t newStart, C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onGetHistoryMessagesResult(requestId, (const HistoryMessage *)messageList, count, newStart, (RTM_ERROR_CODE)errorCode);
}

#pragma endregion C_IRtmEventHandler

#pragma region agora_rtm_client
AGORA_RTM_API_C_INT agora_rtm_client_release(AGORA_RTM_HANDLE agora_rtm_client) {
    if (!agora_rtm_client) {
        return -1;
    }
    return ((IRtmClient *)agora_rtm_client)->release();
}

AGORA_RTM_API_C_INT agora_rtm_client_login(AGORA_RTM_HANDLE agora_rtm_client, const char *token, uint64_t *requestId) {
    if (!agora_rtm_client || !token || !requestId) {
        return -1;
    }
    ((IRtmClient *)agora_rtm_client)->login(token, *requestId);
    return 0;
}

AGORA_RTM_API_C_INT agora_rtm_client_logout(AGORA_RTM_HANDLE agora_rtm_client, uint64_t *requestId) {
    if (!agora_rtm_client || !requestId) {
        return -1;
    }
    ((IRtmClient *)agora_rtm_client)->logout(*requestId);
    return 0;
}

AGORA_RTM_API_C_HDL agora_rtm_client_get_storage(AGORA_RTM_HANDLE agora_rtm_client) {
    if (!agora_rtm_client) {
        return nullptr;
    }
    return (AGORA_RTM_HANDLE)((IRtmClient *)agora_rtm_client)->getStorage();
}

AGORA_RTM_API_C_HDL agora_rtm_client_get_lock(AGORA_RTM_HANDLE agora_rtm_client) {
    if (!agora_rtm_client) {
        return nullptr;
    }
    return (AGORA_RTM_HANDLE)((IRtmClient *)agora_rtm_client)->getLock();
}

AGORA_RTM_API_C_HDL agora_rtm_client_get_presence(AGORA_RTM_HANDLE agora_rtm_client) {
    if (!agora_rtm_client) {
        return nullptr;
    }
    return (AGORA_RTM_HANDLE)((IRtmClient *)agora_rtm_client)->getPresence();
}

AGORA_RTM_API_C_HDL agora_rtm_client_get_history(AGORA_RTM_HANDLE agora_rtm_client) {
    if (!agora_rtm_client) {
        return nullptr;
    }
    return (AGORA_RTM_HANDLE)((IRtmClient *)agora_rtm_client)->getHistory();
}

AGORA_RTM_API_C_INT agora_rtm_client_renew_token(AGORA_RTM_HANDLE agora_rtm_client, const char *token, uint64_t *requestId) {
    if (!agora_rtm_client || !token || !requestId) {
        return -1;
    }
    ((IRtmClient *)agora_rtm_client)->renewToken(token, *requestId);
    return 0;
}

AGORA_RTM_API_C_INT agora_rtm_client_publish(AGORA_RTM_HANDLE agora_rtm_client, const char *channelName, const char *message, const size_t length, const publish_options *option, uint64_t *requestId) {
    if (!agora_rtm_client || !channelName || !message || !option || !requestId) {
        return -1;
    }
    ((IRtmClient *)agora_rtm_client)->publish(channelName, message, length, *(const PublishOptions *)option, *requestId);
    return 0;
}

AGORA_RTM_API_C_INT agora_rtm_client_subscribe(AGORA_RTM_HANDLE agora_rtm_client, const char *channelName, const subscribe_options *options, uint64_t *requestId) {
    if (!agora_rtm_client || !channelName || !options || !requestId) {
        return -1;
    }
    ((IRtmClient *)agora_rtm_client)->subscribe(channelName, *(const SubscribeOptions *)options, *requestId);
    return 0;
}

AGORA_RTM_API_C_INT agora_rtm_client_unsubscribe(AGORA_RTM_HANDLE agora_rtm_client, const char *channelName, uint64_t *requestId) {
    if (!agora_rtm_client || !channelName || !requestId) {
        return -1;
    }
    ((IRtmClient *)agora_rtm_client)->unsubscribe(channelName, *requestId);
    return 0;
}

AGORA_RTM_API_C_HDL agora_rtm_client_create_stream_channel(AGORA_RTM_HANDLE agora_rtm_client, const char *channelName, int *errorCode) {
    if (!agora_rtm_client || !channelName || !errorCode) {
        return nullptr;
    }
    return (AGORA_RTM_HANDLE)((IRtmClient *)agora_rtm_client)->createStreamChannel(channelName, *errorCode);
}

AGORA_RTM_API_C_INT agora_rtm_client_set_parameters(AGORA_RTM_HANDLE agora_rtm_client, const char *parameters) {
    if (!agora_rtm_client || !parameters) {
        return -1;
    }
    return ((IRtmClient *)agora_rtm_client)->setParameters(parameters);
}
#pragma endregion agora_rtm_client

AGORA_RTM_API_C_HDL agora_rtm_client_create(const rtm_config *config, int *errorCode) {
    if (!config || !errorCode) {
        return nullptr;
    }
    return (AGORA_RTM_HANDLE)createAgoraRtmClient(*(const RtmConfig *)config, *errorCode);
}

AGORA_RTM_API_C_LITERAL agora_rtm_client_get_error_reason(int errorCode) {
    return getErrorReason(errorCode);
}

AGORA_RTM_API_C_LITERAL agora_rtm_client_get_version() {
    return getVersion();
}

#pragma endregion agora::rtm

#pragma endregion agora
