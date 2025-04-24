// 引入AgoraRTM SDK
#include "AgoraRtmBase.h"

using namespace agora;
using namespace agora::rtm;

// Agora C封装
#include "C_AgoraRtmBase.h"

#pragma region agora

#pragma region agora::rtm

rtm_log_config *rtm_log_config_create()
{
    return (rtm_log_config *)(new RtmLogConfig());
}
void rtm_log_config_delete(rtm_log_config *this_)
{
    delete (RtmLogConfig *)this_;
    this_ = nullptr;
}

user_list *user_list_create()
{
    return (user_list *)(new UserList());
}
void user_list_delete(user_list *this_)
{
    delete (UserList *)this_;
    this_ = nullptr;
}

publisher_info *publisher_info_create()
{
    return (publisher_info *)(new PublisherInfo());
}
void publisher_info_delete(publisher_info *this_)
{
    delete (PublisherInfo *)this_;
    this_ = nullptr;
}

topic_info *topic_info_create()
{
    return (topic_info *)(new TopicInfo());
}
void topic_info_delete(topic_info *this_)
{
    delete (TopicInfo *)this_;
    this_ = nullptr;
}

state_item *state_item_create()
{
    return (state_item *)(new StateItem());
}
void state_item_delete(state_item *this_)
{
    delete (StateItem *)this_;
    this_ = nullptr;
}

lock_detail *lock_detail_create()
{
    return (lock_detail *)(new LockDetail());
}
void lock_detail_delete(lock_detail *this_)
{
    delete (LockDetail *)this_;
    this_ = nullptr;
}

user_state *user_state_create()
{
    return (user_state *)(new UserState());
}
void user_state_delete(user_state *this_)
{
    delete (UserState *)this_;
    this_ = nullptr;
}

subscribe_options *subscribe_options_create()
{
    return (subscribe_options *)(new SubscribeOptions());
}
void subscribe_options_delete(subscribe_options *this_)
{
    delete (SubscribeOptions *)this_;
    this_ = nullptr;
}

channel_info *channel_info_create()
{
    return (channel_info *)(new ChannelInfo());
}
void channel_info_delete(channel_info *this_)
{
    delete (ChannelInfo *)this_;
    this_ = nullptr;
}

presence_options *presence_options_create()
{
    return (presence_options *)(new PresenceOptions());
}
void presence_options_delete(presence_options *this_)
{
    delete (PresenceOptions *)this_;
    this_ = nullptr;
}

get_online_users_options *get_online_users_options_create()
{
    return (get_online_users_options *)(new GetOnlineUsersOptions());
}
void get_online_users_options_delete(get_online_users_options *this_)
{
    delete (GetOnlineUsersOptions *)this_;
    this_ = nullptr;
}

publish_options *publish_options_create()
{
    return (publish_options *)(new PublishOptions());
}
void publish_options_delete(publish_options *this_)
{
    delete (PublishOptions *)this_;
    this_ = nullptr;
}

topic_message_options *topic_message_options_create()
{
    return (topic_message_options *)(new TopicMessageOptions());
}
void topic_message_options_delete(topic_message_options *this_)
{
    delete (TopicMessageOptions *)this_;
    this_ = nullptr;
}

rtm_proxy_config *rtm_proxy_config_create()
{
    return (rtm_proxy_config *)(new RtmProxyConfig());
}
void rtm_proxy_config_delete(rtm_proxy_config *this_)
{
    delete (RtmProxyConfig *)this_;
    this_ = nullptr;
}

rtm_encryption_config *rtm_encryption_config_create()
{
    return (rtm_encryption_config *)(new RtmEncryptionConfig());
}
void rtm_encryption_config_delete(rtm_encryption_config *this_)
{
    delete (RtmEncryptionConfig *)this_;
    this_ = nullptr;
}

#pragma endregion agora::rtm

#pragma endregion agora