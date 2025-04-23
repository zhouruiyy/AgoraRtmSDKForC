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

struct C_RtmConfig *C_RtmConfig_New()
{
    return (C_RtmConfig *)(new RtmConfig());
}
void C_RtmConfig_Delete(struct C_RtmConfig *this_)
{
    delete (RtmConfig *)(this_);
}

#pragma region C_IRtmEventHandler

struct C_MessageEvent *C_MessageEvent_New()
{
    return (C_MessageEvent *)(new agora::rtm::IRtmEventHandler::MessageEvent());
}
void C_MessageEvent_Delete(struct C_MessageEvent *this_)
{
    delete (agora::rtm::IRtmEventHandler::MessageEvent *)(this_);
}

struct C_IntervalInfo *C_IntervalInfo_New()
{
    return (C_IntervalInfo *)(new agora::rtm::IRtmEventHandler::PresenceEvent::IntervalInfo());
}
void C_IntervalInfo_Delete(struct C_IntervalInfo *this_)
{
    delete (agora::rtm::IRtmEventHandler::PresenceEvent::IntervalInfo *)(this_);
}

struct C_SnapshotInfo *C_SnapshotInfo_New()
{
    return (C_SnapshotInfo *)(new agora::rtm::IRtmEventHandler::PresenceEvent::SnapshotInfo());
}
void C_SnapshotInfo_Delete(struct C_SnapshotInfo *this_)
{
    delete (agora::rtm::IRtmEventHandler::PresenceEvent::SnapshotInfo *)(this_);
}

struct C_PresenceEvent *C_PresenceEvent_New()
{
    return (C_PresenceEvent *)(new agora::rtm::IRtmEventHandler::PresenceEvent());
}
void C_PresenceEvent_Delete(struct C_PresenceEvent *this_)
{
    delete (agora::rtm::IRtmEventHandler::PresenceEvent *)(this_);
}

struct C_TopicEvent *C_TopicEvent_New()
{
    return (C_TopicEvent *)(new agora::rtm::IRtmEventHandler::TopicEvent());
}
void C_TopicEvent_Delete(struct C_TopicEvent *this_)
{
    delete (agora::rtm::IRtmEventHandler::TopicEvent *)(this_);
}

struct C_LockEvent *C_LockEvent_New()
{
    return (C_LockEvent *)(new agora::rtm::IRtmEventHandler::LockEvent());
}
void C_LockEvent_Delete(struct C_LockEvent *this_)
{
    delete (agora::rtm::IRtmEventHandler::LockEvent *)(this_);
}

struct C_StorageEvent *C_StorageEvent_New()
{
    return (C_StorageEvent *)(new agora::rtm::IRtmEventHandler::StorageEvent());
}
void C_StorageEvent_Delete(struct C_StorageEvent *this_)
{
    delete (agora::rtm::IRtmEventHandler::StorageEvent *)(this_);
}

void C_IRtmEventHandler_onMessageEvent(C_IRtmEventHandler *this_, const C_MessageEvent *event)
{
    ((IRtmEventHandler *)this_)->onMessageEvent(*(const IRtmEventHandler::MessageEvent *)event);
}

void C_IRtmEventHandler_onPresenceEvent(C_IRtmEventHandler *this_, const C_PresenceEvent *event)
{
    ((IRtmEventHandler *)this_)->onPresenceEvent(*(const IRtmEventHandler::PresenceEvent *)event);
}

void C_IRtmEventHandler_onTopicEvent(C_IRtmEventHandler *this_, const C_TopicEvent *event)
{
    ((IRtmEventHandler *)this_)->onTopicEvent(*(const IRtmEventHandler::TopicEvent *)event);
}

void C_IRtmEventHandler_onLockEvent(C_IRtmEventHandler *this_, const C_LockEvent *event)
{
    ((IRtmEventHandler *)this_)->onLockEvent(*(const IRtmEventHandler::LockEvent *)event);
}

void C_IRtmEventHandler_onStorageEvent(C_IRtmEventHandler *this_, const C_StorageEvent *event)
{
    ((IRtmEventHandler *)this_)->onStorageEvent(*(const IRtmEventHandler::StorageEvent *)event);
}

void C_IRtmEventHandler_onJoinResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *userId, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onJoinResult(requestId, channelName, userId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onLeaveResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *userId, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onLeaveResult(requestId, channelName, userId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onJoinTopicResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *userId, const char *topic, const char *meta, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onJoinTopicResult(requestId, channelName, userId, topic, meta, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onLeaveTopicResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *userId, const char *topic, const char *meta, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onLeaveTopicResult(requestId, channelName, userId, topic, meta, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onSubscribeTopicResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *userId, const char *topic, struct C_UserList succeedUsers, struct C_UserList failedUsers, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onSubscribeTopicResult(requestId, channelName, userId, topic, *(UserList *)&succeedUsers, *(UserList *)&failedUsers, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onConnectionStateChanged(C_IRtmEventHandler *this_, const char *channelName, enum C_RTM_CONNECTION_STATE state, enum C_RTM_CONNECTION_CHANGE_REASON reason)
{
    ((IRtmEventHandler *)this_)->onConnectionStateChanged(channelName, (RTM_CONNECTION_STATE)state, (RTM_CONNECTION_CHANGE_REASON)reason);
}

void C_IRtmEventHandler_onTokenPrivilegeWillExpire(C_IRtmEventHandler *this_, const char *channelName)
{
    ((IRtmEventHandler *)this_)->onTokenPrivilegeWillExpire(channelName);
}

void C_IRtmEventHandler_onSubscribeResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onSubscribeResult(requestId, channelName, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onPublishResult(C_IRtmEventHandler *this_, const uint64_t requestId, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onPublishResult(requestId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onLoginResult(C_IRtmEventHandler *this_, const uint64_t requestId, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onLoginResult(requestId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onSetChannelMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onSetChannelMetadataResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onUpdateChannelMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onUpdateChannelMetadataResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onRemoveChannelMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onRemoveChannelMetadataResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onGetChannelMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const C_Metadata *data, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onGetChannelMetadataResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, *(const Metadata *)data, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onSetUserMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *userId, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onSetUserMetadataResult(requestId, userId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onUpdateUserMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *userId, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onUpdateUserMetadataResult(requestId, userId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onRemoveUserMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *userId, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onRemoveUserMetadataResult(requestId, userId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onGetUserMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *userId, const C_Metadata *data, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onGetUserMetadataResult(requestId, userId, *(const Metadata *)data, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onSubscribeUserMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *userId, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onSubscribeUserMetadataResult(requestId, userId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onSetLockResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onSetLockResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, lockName, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onRemoveLockResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onRemoveLockResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, lockName, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onReleaseLockResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onReleaseLockResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, lockName, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onAcquireLockResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, enum C_RTM_ERROR_CODE errorCode, const char *errorDetails)
{
    ((IRtmEventHandler *)this_)->onAcquireLockResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, lockName, (RTM_ERROR_CODE)errorCode, errorDetails);
}

void C_IRtmEventHandler_onRevokeLockResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const char *lockName, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onRevokeLockResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, lockName, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onGetLocksResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const struct C_LockDetail *lockDetailList, const size_t count, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onGetLocksResult(requestId, channelName, (RTM_CHANNEL_TYPE)channelType, (const LockDetail *)lockDetailList, count, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onWhoNowResult(C_IRtmEventHandler *this_, const uint64_t requestId, const struct C_UserState *userStateList, const size_t count, const char *nextPage, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onWhoNowResult(requestId, (const UserState *)userStateList, count, nextPage, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onGetOnlineUsersResult(C_IRtmEventHandler *this_, const uint64_t requestId, const struct C_UserState *userStateList, const size_t count, const char *nextPage, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onGetOnlineUsersResult(requestId, (const UserState *)userStateList, count, nextPage, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onWhereNowResult(C_IRtmEventHandler *this_, const uint64_t requestId, const struct C_ChannelInfo *channels, const size_t count, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onWhereNowResult(requestId, (const ChannelInfo *)channels, count, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onGetUserChannelsResult(C_IRtmEventHandler *this_, const uint64_t requestId, const struct C_ChannelInfo *channels, const size_t count, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onGetUserChannelsResult(requestId, (const ChannelInfo *)channels, count, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onPresenceSetStateResult(C_IRtmEventHandler *this_, const uint64_t requestId, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onPresenceSetStateResult(requestId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onPresenceRemoveStateResult(C_IRtmEventHandler *this_, const uint64_t requestId, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onPresenceRemoveStateResult(requestId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onPresenceGetStateResult(C_IRtmEventHandler *this_, const uint64_t requestId, const struct C_UserState *state, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onPresenceGetStateResult(requestId, *(const UserState *)state, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onLogoutResult(C_IRtmEventHandler *this_, const uint64_t requestId, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onLogoutResult(requestId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onRenewTokenResult(C_IRtmEventHandler *this_, const uint64_t requestId, enum C_RTM_SERVICE_TYPE serverType, const char *channelName, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onRenewTokenResult(requestId, (RTM_SERVICE_TYPE)serverType, channelName, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onPublishTopicMessageResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *topic, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onPublishTopicMessageResult(requestId, channelName, topic, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onUnsubscribeTopicResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *topic, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onUnsubscribeTopicResult(requestId, channelName, topic, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onGetSubscribedUserListResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *channelName, const char *topic, struct C_UserList users, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onGetSubscribedUserListResult(requestId, channelName, topic, *(UserList *)&users, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onUnsubscribeUserMetadataResult(C_IRtmEventHandler *this_, const uint64_t requestId, const char *userId, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onUnsubscribeUserMetadataResult(requestId, userId, (RTM_ERROR_CODE)errorCode);
}

void C_IRtmEventHandler_onGetHistoryMessagesResult(C_IRtmEventHandler *this_, const uint64_t requestId, const struct C_HistoryMessage *messageList, const size_t count, const uint64_t newStart, enum C_RTM_ERROR_CODE errorCode)
{
    ((IRtmEventHandler *)this_)->onGetHistoryMessagesResult(requestId, (const HistoryMessage *)messageList, count, newStart, (RTM_ERROR_CODE)errorCode);
}

#pragma endregion C_IRtmEventHandler

#pragma region C_IRtmClient
int agora_rtm_client_release(C_IRtmClient *this_) {
    if (!this_) {
        return -1;
    }
    return ((IRtmClient *)this_)->release();
}

int agora_rtm_client_login(C_IRtmClient *this_, const char *token, uint64_t *requestId) {
    if (!this_ || !token || !requestId) {
        return -1;
    }
    ((IRtmClient *)this_)->login(token, *requestId);
    return 0;
}

int agora_rtm_client_logout(C_IRtmClient *this_, uint64_t *requestId) {
    if (!this_ || !requestId) {
        return -1;
    }
    ((IRtmClient *)this_)->logout(*requestId);
    return 0;
}

C_IRtmStorage *agora_rtm_client_get_storage(C_IRtmClient *this_) {
    if (!this_) {
        return nullptr;
    }
    return (C_IRtmStorage *)((IRtmClient *)this_)->getStorage();
}

C_IRtmLock *agora_rtm_client_get_lock(C_IRtmClient *this_) {
    if (!this_) {
        return nullptr;
    }
    return (C_IRtmLock *)((IRtmClient *)this_)->getLock();
}

C_IRtmPresence *agora_rtm_client_get_presence(C_IRtmClient *this_) {
    if (!this_) {
        return nullptr;
    }
    return (C_IRtmPresence *)((IRtmClient *)this_)->getPresence();
}

C_IRtmHistory *agora_rtm_client_get_history(C_IRtmClient *this_) {
    if (!this_) {
        return nullptr;
    }
    return (C_IRtmHistory *)((IRtmClient *)this_)->getHistory();
}

int agora_rtm_client_renew_token(C_IRtmClient *this_, const char *token, uint64_t *requestId) {
    if (!this_ || !token || !requestId) {
        return -1;
    }
    ((IRtmClient *)this_)->renewToken(token, *requestId);
    return 0;
}

int agora_rtm_client_publish(C_IRtmClient *this_, const char *channelName, const char *message, const size_t length, const struct C_PublishOptions *option, uint64_t *requestId) {
    if (!this_ || !channelName || !message || !option || !requestId) {
        return -1;
    }
    ((IRtmClient *)this_)->publish(channelName, message, length, *(const PublishOptions *)option, *requestId);
    return 0;
}

int agora_rtm_client_subscribe(C_IRtmClient *this_, const char *channelName, const struct C_SubscribeOptions *options, uint64_t *requestId) {
    if (!this_ || !channelName || !options || !requestId) {
        return -1;
    }
    ((IRtmClient *)this_)->subscribe(channelName, *(const SubscribeOptions *)options, *requestId);
    return 0;
}

int agora_rtm_client_unsubscribe(C_IRtmClient *this_, const char *channelName, uint64_t *requestId) {
    if (!this_ || !channelName || !requestId) {
        return -1;
    }
    ((IRtmClient *)this_)->unsubscribe(channelName, *requestId);
    return 0;
}

C_IStreamChannel *agora_rtm_client_create_stream_channel(C_IRtmClient *this_, const char *channelName, int *errorCode) {
    if (!this_ || !channelName || !errorCode) {
        return nullptr;
    }
    return (C_IStreamChannel *)((IRtmClient *)this_)->createStreamChannel(channelName, *errorCode);
}

int agora_rtm_client_set_parameters(C_IRtmClient *this_, const char *parameters) {
    if (!this_ || !parameters) {
        return -1;
    }
    return ((IRtmClient *)this_)->setParameters(parameters);
}
#pragma endregion C_IRtmClient

C_IRtmClient *agora_rtm_client_create(const struct C_RtmConfig *config, int *errorCode) {
    if (!config || !errorCode) {
        return nullptr;
    }
    return (C_IRtmClient *)createAgoraRtmClient(*(const RtmConfig *)config, *errorCode);
}

const char *agora_rtm_client_get_error_reason(int errorCode) {
    return getErrorReason(errorCode);
}

const char *agora_rtm_client_get_version() {
    return getVersion();
}

#pragma endregion agora::rtm

#pragma endregion agora
