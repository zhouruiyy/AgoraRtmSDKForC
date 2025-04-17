// 引入AgoraRTM SDK
#include "IAgoraStreamChannel.h"

using namespace agora;
using namespace agora::rtm;

// Agora C封装
#include "C_IAgoraStreamChannel.h"

#pragma region agora

#pragma region agora::rtm
struct C_JoinChannelOptions *C_JoinChannelOptions_New()
{
  return (C_JoinChannelOptions *)new JoinChannelOptions();
}
void C_JoinChannelOptions_Delete(struct C_JoinChannelOptions *this_)
{
  delete (JoinChannelOptions *)this_;
}

struct C_JoinTopicOptions *C_JoinTopicOptions_New()
{
  return (C_JoinTopicOptions *)new JoinTopicOptions();
}
void C_JoinTopicOptions_Delete(struct C_JoinTopicOptions *this_)
{
  delete (JoinTopicOptions *)this_;
}

struct C_TopicOptions *C_TopicOptions_New()
{
  return (C_TopicOptions *)new TopicOptions();
}
void C_TopicOptions_Delete(struct C_TopicOptions *this_)
{
  delete (TopicOptions *)this_;
}

#pragma region C_IStreamChannel
void agora_rtm_stream_channel_join(C_IStreamChannel *this_, const struct C_JoinChannelOptions *options, uint64_t *requestId)
{
  if (!this_ || !options || !requestId) {
    return;
  }
  ((IStreamChannel *)this_)->join(*(const JoinChannelOptions *)options, *requestId);
}

void agora_rtm_stream_channel_renew_token(C_IStreamChannel *this_, const char *token, uint64_t *requestId)
{
  if (!this_ || !token || !requestId) {
    return;
  }
  ((IStreamChannel *)this_)->renewToken(token, *requestId);
}

void agora_rtm_stream_channel_leave(C_IStreamChannel *this_, uint64_t *requestId)
{
  if (!this_ || !requestId) {
    return;
  }
  ((IStreamChannel *)this_)->leave(*requestId);
}

const char *agora_rtm_stream_channel_get_channel_name(C_IStreamChannel *this_)
{
  if (!this_) {
    return NULL;
  }
  return ((IStreamChannel *)this_)->getChannelName();
}

void agora_rtm_stream_channel_join_topic(C_IStreamChannel *this_, const char *topic, const struct C_JoinTopicOptions *options, uint64_t *requestId)
{
  if (!this_ || !topic || !options || !requestId) {
    return;
  }
  ((IStreamChannel *)this_)->joinTopic(topic, *(const JoinTopicOptions *)options, *requestId);
}

void agora_rtm_stream_channel_publish_topic_message(C_IStreamChannel *this_, const char *topic, const char *message, size_t length, const struct C_TopicMessageOptions *option, uint64_t *requestId)
{
  if (!this_ || !topic || !message || !option || !requestId) {
    return;
  }
  ((IStreamChannel *)this_)->publishTopicMessage(topic, message, length, *(const TopicMessageOptions *)option, *requestId);
}

void agora_rtm_stream_channel_leave_topic(C_IStreamChannel *this_, const char *topic, uint64_t *requestId)
{
  if (!this_ || !topic || !requestId) {
    return;
  }
  ((IStreamChannel *)this_)->leaveTopic(topic, *requestId);
}

void agora_rtm_stream_channel_subscribe_topic(C_IStreamChannel *this_, const char *topic, const struct C_TopicOptions *options, uint64_t *requestId)
{
  if (!this_ || !topic || !options || !requestId) {
    return;
  }
  ((IStreamChannel *)this_)->subscribeTopic(topic, *(const TopicOptions *)options, *requestId);
}

void agora_rtm_stream_channel_unsubscribe_topic(C_IStreamChannel *this_, const char *topic, const struct C_TopicOptions *options, uint64_t *requestId)
{
  if (!this_ || !topic || !options || !requestId) {
    return;
  }
  ((IStreamChannel *)this_)->unsubscribeTopic(topic, *(const TopicOptions *)options, *requestId);
}

void agora_rtm_stream_channel_get_subscribed_user_list(C_IStreamChannel *this_, const char *topic, uint64_t *requestId)
{
  if (!this_ || !topic || !requestId) {
    return;
  }
  ((IStreamChannel *)this_)->getSubscribedUserList(topic, *requestId);
}

int agora_rtm_stream_channel_release(C_IStreamChannel *this_)
{
  if (!this_) {
    return -1;
  }
  return ((IStreamChannel *)this_)->release();
}

#pragma endregion C_IStreamChannel

#pragma endregion agora::rtm

#pragma endregion agora
