#include "bridge/RtmEventHandlerBridge.hh"

void RtmEventHandlerBridge::onMessageEvent(const MessageEvent &event)
{
    if (cbs_.onMessageEvent != nullptr)
    {
        return cbs_.onMessageEvent(this, this->userData_, (const message_event *)&event);
    }
}

void RtmEventHandlerBridge::onPresenceEvent(const PresenceEvent &event)
{
    if (cbs_.onPresenceEvent != nullptr)
    {
        return cbs_.onPresenceEvent(this, this->userData_, (const presence_event *)&event);
    }
}

void RtmEventHandlerBridge::onTopicEvent(const TopicEvent &event)
{
    if (cbs_.onTopicEvent != nullptr)
    {
        return cbs_.onTopicEvent(this, this->userData_, (const topic_event *)&event);
    }
}

void RtmEventHandlerBridge::onLockEvent(const LockEvent &event)
{
    if (cbs_.onLockEvent != nullptr)
    {
        return cbs_.onLockEvent(this, this->userData_, (const lock_event *)&event);
    }
}

void RtmEventHandlerBridge::onStorageEvent(const StorageEvent &event)
{
    if (cbs_.onStorageEvent != nullptr)
    {
        return cbs_.onStorageEvent(this, this->userData_, (const storage_event *)&event);
    }
}

void RtmEventHandlerBridge::onJoinResult(const uint64_t requestId, const char *channelName, const char *userId, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onJoinResult != nullptr)
    {
        return cbs_.onJoinResult(this, this->userData_, requestId, channelName, userId, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onLeaveResult(const uint64_t requestId, const char *channelName, const char *userId, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onLeaveResult != nullptr)
    {
        return cbs_.onLeaveResult(this, this->userData_, requestId, channelName, userId, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onJoinTopicResult(const uint64_t requestId, const char *channelName, const char *userId, const char *topic, const char *meta, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onJoinTopicResult != nullptr)
    {
        return cbs_.onJoinTopicResult(this, this->userData_, requestId, channelName, userId, topic, meta, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onLeaveTopicResult(const uint64_t requestId, const char *channelName, const char *userId, const char *topic, const char *meta, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onLeaveTopicResult != nullptr)
    {
        return cbs_.onLeaveTopicResult(this, this->userData_, requestId, channelName, userId, topic, meta, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onSubscribeTopicResult(const uint64_t requestId, const char *channelName, const char *userId, const char *topic, UserList succeedUsers, UserList failedUsers, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onSubscribeTopicResult != nullptr)
    {
        return cbs_.onSubscribeTopicResult(this, this->userData_, requestId, channelName, userId, topic, *(user_list *)&succeedUsers, *(user_list *)&failedUsers, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onConnectionStateChanged(const char *channelName, RTM_CONNECTION_STATE state, RTM_CONNECTION_CHANGE_REASON reason)
{
    if (cbs_.onConnectionStateChanged != nullptr)
    {
        return cbs_.onConnectionStateChanged(this, this->userData_, channelName, (C_RTM_CONNECTION_STATE)state, (C_RTM_CONNECTION_CHANGE_REASON)reason);
    }
}

void RtmEventHandlerBridge::onTokenPrivilegeWillExpire(const char *channelName)
{
    if (cbs_.onTokenPrivilegeWillExpire != nullptr)
    {
        return cbs_.onTokenPrivilegeWillExpire(this, this->userData_, channelName);
    }
}

void RtmEventHandlerBridge::onSubscribeResult(const uint64_t requestId, const char *channelName, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onSubscribeResult != nullptr)
    {
        return cbs_.onSubscribeResult(this, this->userData_, requestId, channelName, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onPublishResult(const uint64_t requestId, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onPublishResult != nullptr)
    {
        return cbs_.onPublishResult(this, this->userData_, requestId, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onLoginResult(const uint64_t requestId, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onLoginResult != nullptr)
    {
        return cbs_.onLoginResult(this, this->userData_, requestId, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onSetChannelMetadataResult(const uint64_t requestId, const char *channelName, RTM_CHANNEL_TYPE channelType, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onSetChannelMetadataResult != nullptr)
    {
        return cbs_.onSetChannelMetadataResult(this, this->userData_, requestId, channelName, (C_RTM_CHANNEL_TYPE)channelType, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onUpdateChannelMetadataResult(const uint64_t requestId, const char *channelName, RTM_CHANNEL_TYPE channelType, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onUpdateChannelMetadataResult != nullptr)
    {
        return cbs_.onUpdateChannelMetadataResult(this, this->userData_, requestId, channelName, (C_RTM_CHANNEL_TYPE)channelType, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onRemoveChannelMetadataResult(const uint64_t requestId, const char *channelName, RTM_CHANNEL_TYPE channelType, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onRemoveChannelMetadataResult != nullptr)
    {
        return cbs_.onRemoveChannelMetadataResult(this, this->userData_, requestId, channelName, (C_RTM_CHANNEL_TYPE)channelType, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onGetChannelMetadataResult(const uint64_t requestId, const char *channelName, RTM_CHANNEL_TYPE channelType, const Metadata &data, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onGetChannelMetadataResult != nullptr)
    {
        return cbs_.onGetChannelMetadataResult(this, this->userData_, requestId, channelName, (C_RTM_CHANNEL_TYPE)channelType, (const metadata *)&data, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onSetUserMetadataResult(const uint64_t requestId, const char *userId, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onSetUserMetadataResult != nullptr)
    {
        return cbs_.onSetUserMetadataResult(this, this->userData_, requestId, userId, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onUpdateUserMetadataResult(const uint64_t requestId, const char *userId, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onUpdateUserMetadataResult != nullptr)
    {
        return cbs_.onUpdateUserMetadataResult(this, this->userData_, requestId, userId, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onRemoveUserMetadataResult(const uint64_t requestId, const char *userId, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onRemoveUserMetadataResult != nullptr)
    {
        return cbs_.onRemoveUserMetadataResult(this, this->userData_, requestId, userId, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onGetUserMetadataResult(const uint64_t requestId, const char *userId, const Metadata &data, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onGetUserMetadataResult != nullptr)
    {
        return cbs_.onGetUserMetadataResult(this, this->userData_, requestId, userId, (const metadata *)&data, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onSubscribeUserMetadataResult(const uint64_t requestId, const char *userId, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onSubscribeUserMetadataResult != nullptr)
    {
        return cbs_.onSubscribeUserMetadataResult(this, this->userData_, requestId, userId, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onSetLockResult(const uint64_t requestId, const char *channelName, RTM_CHANNEL_TYPE channelType, const char *lockName, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onSetLockResult != nullptr)
    {
        return cbs_.onSetLockResult(this, this->userData_, requestId, channelName, (C_RTM_CHANNEL_TYPE)channelType, lockName, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onRemoveLockResult(const uint64_t requestId, const char *channelName, RTM_CHANNEL_TYPE channelType, const char *lockName, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onRemoveLockResult != nullptr)
    {
        return cbs_.onRemoveLockResult(this, this->userData_, requestId, channelName, (C_RTM_CHANNEL_TYPE)channelType, lockName, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onReleaseLockResult(const uint64_t requestId, const char *channelName, RTM_CHANNEL_TYPE channelType, const char *lockName, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onReleaseLockResult != nullptr)
    {
        return cbs_.onReleaseLockResult(this, this->userData_, requestId, channelName, (C_RTM_CHANNEL_TYPE)channelType, lockName, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onAcquireLockResult(const uint64_t requestId, const char *channelName, RTM_CHANNEL_TYPE channelType, const char *lockName, RTM_ERROR_CODE errorCode, const char *errorDetails)
{
    if (cbs_.onAcquireLockResult != nullptr)
    {
        return cbs_.onAcquireLockResult(this, this->userData_, requestId, channelName, (C_RTM_CHANNEL_TYPE)channelType, lockName, (C_RTM_ERROR_CODE)errorCode, errorDetails);
    }
}

void RtmEventHandlerBridge::onRevokeLockResult(const uint64_t requestId, const char *channelName, RTM_CHANNEL_TYPE channelType, const char *lockName, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onRevokeLockResult != nullptr)
    {
        return cbs_.onRevokeLockResult(this, this->userData_, requestId, channelName, (C_RTM_CHANNEL_TYPE)channelType, lockName, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onGetLocksResult(const uint64_t requestId, const char *channelName, RTM_CHANNEL_TYPE channelType, const LockDetail *lockDetailList, const size_t count, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onGetLocksResult != nullptr)
    {
        return cbs_.onGetLocksResult(this, this->userData_, requestId, channelName, (C_RTM_CHANNEL_TYPE)channelType, (const lock_detail *)lockDetailList, count, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onWhoNowResult(const uint64_t requestId, const UserState *userStateList, const size_t count, const char *nextPage, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onWhoNowResult != nullptr)
    {
        return cbs_.onWhoNowResult(this, this->userData_, requestId, (const user_state *)userStateList, count, nextPage, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onGetOnlineUsersResult(const uint64_t requestId, const UserState *userStateList, const size_t count, const char *nextPage, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onGetOnlineUsersResult != nullptr)
    {
        return cbs_.onGetOnlineUsersResult(this, this->userData_, requestId, (const user_state *)userStateList, count, nextPage, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onWhereNowResult(const uint64_t requestId, const ChannelInfo *channels, const size_t count, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onWhereNowResult != nullptr)
    {
        return cbs_.onWhereNowResult(this, this->userData_, requestId, (const channel_info *)channels, count, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onGetUserChannelsResult(const uint64_t requestId, const ChannelInfo *channels, const size_t count, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onGetUserChannelsResult != nullptr)
    {
        return cbs_.onGetUserChannelsResult(this, this->userData_, requestId, (const channel_info *)channels, count, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onPresenceSetStateResult(const uint64_t requestId, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onPresenceSetStateResult != nullptr)
    {
        return cbs_.onPresenceSetStateResult(this, this->userData_, requestId, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onPresenceRemoveStateResult(const uint64_t requestId, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onPresenceRemoveStateResult != nullptr)
    {
        return cbs_.onPresenceRemoveStateResult(this, this->userData_, requestId, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onPresenceGetStateResult(const uint64_t requestId, const UserState &state, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onPresenceGetStateResult != nullptr)
    {
        return cbs_.onPresenceGetStateResult(this, this->userData_, requestId, (const user_state *)&state, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onLinkStateEvent(const LinkStateEvent &event)
{
    if (cbs_.onLinkStateEvent != nullptr)
    {
        return cbs_.onLinkStateEvent(this, this->userData_, (const link_state_event *)&event);
    }
}

void RtmEventHandlerBridge::onLogoutResult(const uint64_t requestId, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onLogoutResult != nullptr)
    {
        return cbs_.onLogoutResult(this, this->userData_, requestId, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onRenewTokenResult(const uint64_t requestId, RTM_SERVICE_TYPE serverType, const char *channelName, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onRenewTokenResult != nullptr)
    {
        return cbs_.onRenewTokenResult(this, this->userData_, requestId, (C_RTM_SERVICE_TYPE)serverType, channelName, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onPublishTopicMessageResult(const uint64_t requestId, const char *channelName, const char *topic, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onPublishTopicMessageResult != nullptr)
    {
        return cbs_.onPublishTopicMessageResult(this, this->userData_, requestId, channelName, topic, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onUnsubscribeTopicResult(const uint64_t requestId, const char *channelName, const char *topic, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onUnsubscribeTopicResult != nullptr)
    {
        return cbs_.onUnsubscribeTopicResult(this, this->userData_, requestId, channelName, topic, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onGetSubscribedUserListResult(const uint64_t requestId, const char *channelName, const char *topic, UserList users, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onGetSubscribedUserListResult != nullptr)
    {
        return cbs_.onGetSubscribedUserListResult(this, this->userData_, requestId, channelName, topic, *(user_list *)&users, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onGetHistoryMessagesResult(const uint64_t requestId, const HistoryMessage *messageList, const size_t count, const uint64_t newStart, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onGetHistoryMessagesResult != nullptr)
    {
        return cbs_.onGetHistoryMessagesResult(this, this->userData_, requestId, (const history_message *)messageList, count, newStart, (C_RTM_ERROR_CODE)errorCode);
    }
}

void RtmEventHandlerBridge::onUnsubscribeUserMetadataResult(const uint64_t requestId, const char *userId, RTM_ERROR_CODE errorCode)
{
    if (cbs_.onUnsubscribeUserMetadataResult != nullptr)
    {
        return cbs_.onUnsubscribeUserMetadataResult(this, this->userData_, requestId, userId, (C_RTM_ERROR_CODE)errorCode);
    }
}

