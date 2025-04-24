// 引入AgoraRTM SDK
#include "IAgoraStreamChannel.h"

using namespace agora;
using namespace agora::rtm;

// Agora C封装
#include "C_IAgoraStreamChannel.h"

#pragma region agora

#pragma region agora::rtm
join_channel_options *join_channel_options_create()
{
  return (join_channel_options *)new JoinChannelOptions();
}
void join_channel_options_delete(join_channel_options *this_)
{
  delete (JoinChannelOptions *)this_;
}

join_topic_options *join_topic_options_create()
{
  return (join_topic_options *)new JoinTopicOptions();
}
void join_topic_options_delete(join_topic_options *this_)
{
  delete (JoinTopicOptions *)this_;
}

topic_options *topic_options_create()
{
  return (topic_options *)new TopicOptions();
}
void topic_options_delete(topic_options *this_)
{
  delete (TopicOptions *)this_;
}

#pragma region agora_rtm_stream_channel
AGORA_RTM_API_C_VOID agora_rtm_stream_channel_join(AGORA_RTM_HANDLE agora_rtm_stream_channel, const join_channel_options *options, uint64_t *requestId)
{
  if (!agora_rtm_stream_channel || !options || !requestId) {
    return;
  }
  ((IStreamChannel *)agora_rtm_stream_channel)->join(*(const JoinChannelOptions *)options, *requestId);
}

AGORA_RTM_API_C_VOID agora_rtm_stream_channel_renew_token(AGORA_RTM_HANDLE agora_rtm_stream_channel, const char *token, uint64_t *requestId)
{
  if (!agora_rtm_stream_channel || !token || !requestId) {
    return;
  }
  ((IStreamChannel *)agora_rtm_stream_channel)->renewToken(token, *requestId);
}

AGORA_RTM_API_C_VOID agora_rtm_stream_channel_leave(AGORA_RTM_HANDLE agora_rtm_stream_channel, uint64_t *requestId)
{
  if (!agora_rtm_stream_channel || !requestId) {
    return;
  }
  ((IStreamChannel *)agora_rtm_stream_channel)->leave(*requestId);
}

AGORA_RTM_API_C_LITERAL agora_rtm_stream_channel_get_channel_name(AGORA_RTM_HANDLE agora_rtm_stream_channel)
{
  if (!agora_rtm_stream_channel) {
    return NULL;
  }
  return ((IStreamChannel *)agora_rtm_stream_channel)->getChannelName();
}

AGORA_RTM_API_C_VOID agora_rtm_stream_channel_join_topic(AGORA_RTM_HANDLE agora_rtm_stream_channel, const char *topic, const join_topic_options *options, uint64_t *requestId)
{
  if (!agora_rtm_stream_channel || !topic || !options || !requestId) {
    return;
  }
  ((IStreamChannel *)agora_rtm_stream_channel)->joinTopic(topic, *(const JoinTopicOptions *)options, *requestId);
}

AGORA_RTM_API_C_VOID agora_rtm_stream_channel_publish_topic_message(AGORA_RTM_HANDLE agora_rtm_stream_channel, const char *topic, const char *message, size_t length, const topic_message_options *option, uint64_t *requestId)
{
  if (!agora_rtm_stream_channel || !topic || !message || !option || !requestId) {
    return;
  }
  ((IStreamChannel *)agora_rtm_stream_channel)->publishTopicMessage(topic, message, length, *(const TopicMessageOptions *)option, *requestId);
}

AGORA_RTM_API_C_VOID agora_rtm_stream_channel_leave_topic(AGORA_RTM_HANDLE agora_rtm_stream_channel, const char *topic, uint64_t *requestId)
{
  if (!agora_rtm_stream_channel || !topic || !requestId) {
    return;
  }
  ((IStreamChannel *)agora_rtm_stream_channel)->leaveTopic(topic, *requestId);
}

AGORA_RTM_API_C_VOID agora_rtm_stream_channel_subscribe_topic(AGORA_RTM_HANDLE agora_rtm_stream_channel, const char *topic, const topic_options *options, uint64_t *requestId)
{
  if (!agora_rtm_stream_channel || !topic || !options || !requestId) {
    return;
  }
  ((IStreamChannel *)agora_rtm_stream_channel)->subscribeTopic(topic, *(const TopicOptions *)options, *requestId);
}

AGORA_RTM_API_C_VOID agora_rtm_stream_channel_unsubscribe_topic(AGORA_RTM_HANDLE agora_rtm_stream_channel, const char *topic, const topic_options *options, uint64_t *requestId)
{
  if (!agora_rtm_stream_channel || !topic || !options || !requestId) {
    return;
  }
  ((IStreamChannel *)agora_rtm_stream_channel)->unsubscribeTopic(topic, *(const TopicOptions *)options, *requestId);
}

AGORA_RTM_API_C_VOID agora_rtm_stream_channel_get_subscribed_user_list(AGORA_RTM_HANDLE agora_rtm_stream_channel, const char *topic, uint64_t *requestId)
{
  if (!agora_rtm_stream_channel || !topic || !requestId) {
    return;
  }
  ((IStreamChannel *)agora_rtm_stream_channel)->getSubscribedUserList(topic, *requestId);
}

AGORA_RTM_API_C_INT agora_rtm_stream_channel_release(AGORA_RTM_HANDLE agora_rtm_stream_channel)
{
  if (!agora_rtm_stream_channel) {
    return -1;
  }
  return ((IStreamChannel *)agora_rtm_stream_channel)->release();
}

#pragma endregion agora_rtm_stream_channel

#pragma endregion agora::rtm

#pragma endregion agora
