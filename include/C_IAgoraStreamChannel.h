#ifndef C_I_AGORA_STREAM_CHANNEL_H
#define C_I_AGORA_STREAM_CHANNEL_H

#include "agora_rtm_api.h"

#include "C_AgoraRtmBase.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#pragma region agora

#pragma region agora::rtm

  /**
   * The qos of rtm message.
   */
  typedef enum _C_RTM_MESSAGE_QOS
  {
    /**
     * Will not ensure that messages arrive in order.
     */
    C_RTM_MESSAGE_QOS_UNORDERED = 0,
    /**
     * Will ensure that messages arrive in order.
     */
    C_RTM_MESSAGE_QOS_ORDERED = 1,
  } C_RTM_MESSAGE_QOS;

  /**
   * The priority of rtm message.
   */
  typedef enum _C_RTM_MESSAGE_PRIORITY
  {
    /**
     * The highest priority
     */
    C_RTM_MESSAGE_PRIORITY_HIGHEST = 0,
    /**
     * The high priority
     */
    C_RTM_MESSAGE_PRIORITY_HIGH = 1,
    /**
     * The normal priority (Default)
     */
    C_RTM_MESSAGE_PRIORITY_NORMAL = 4,
    /**
     * The low priority
     */
    C_RTM_MESSAGE_PRIORITY_LOW = 8,
  } C_RTM_MESSAGE_PRIORITY;

  /**
   * Join channel options.
   */
  typedef struct _join_channel_options
  {
    /**
     * Token used to join channel.
     */
    const char *token;
    /**
     * Whether to subscribe channel metadata information
     */
    bool withMetadata;
    /**
     * Whether to subscribe channel with user presence
     */
    bool withPresence;
    /**
     * Whether to subscribe channel with lock
     */
    bool withLock;
    /**
     * Whether to join channel in quiet mode
     */
    bool beQuiet;
  } join_channel_options;
  join_channel_options *join_channel_options_new();
  void join_channel_options_delete(join_channel_options *this_);

  /**
   * Join topic options.
   */
  typedef struct _join_topic_options
  {
    /**
     * The qos of rtm message.
     */
    C_RTM_MESSAGE_QOS qos;

    /**
     * The priority of rtm message.
     */
    C_RTM_MESSAGE_PRIORITY priority;

    /**
     * The metaData of topic.
     */
    const char *meta;

    /**
     * The rtm data will sync with media
     */
    bool syncWithMedia;
  } join_topic_options;
  join_topic_options *join_topic_options_new();
  void join_topic_options_delete(join_topic_options *this_);

  /**
   * Topic options.
   */
  typedef struct _topic_options
  {
    /**
     * The list of users to subscribe.
     */
    const char **users;
    /**
     * The number of users.
     */
    size_t userCount;
  } topic_options;
  topic_options *topic_options_new();
  void topic_options_delete(topic_options *this_);

  /**
   * The IStreamChannel class.
   *
   * This class provides the stream channel methods that can be invoked by your app.
   */
#pragma region agora_rtm_stream_channel
  /**
   * Join the channel.
   *
   * @param [in] options join channel options.
   * @param [out] requestId The unique ID of this request.
   */
  AGORA_RTM_API_C_VOID agora_rtm_stream_channel_join(AGORA_RTM_HANDLE agora_rtm_stream_channel, const join_channel_options *options, uint64_t *requestId);

  /**
   * Renews the token. Once a token is enabled and used, it expires after a certain period of time.
   * You should generate a new token on your server, call this method to renew it.
   *
   * @param [in] token Token used renew.
   * @param [out] requestId The unique ID of this request.
   */
  AGORA_RTM_API_C_VOID agora_rtm_stream_channel_renew_token(AGORA_RTM_HANDLE agora_rtm_stream_channel, const char *token, uint64_t *requestId);

  /**
   * Leave the channel.
   *
   * @param [out] requestId The unique ID of this request.
   */
  AGORA_RTM_API_C_VOID agora_rtm_stream_channel_leave(AGORA_RTM_HANDLE agora_rtm_stream_channel, uint64_t *requestId);

  /**
   * Return the channel name of this stream channel.
   *
   * @return The channel name.
   */
  AGORA_RTM_API_C_LITERAL agora_rtm_stream_channel_get_channel_name(AGORA_RTM_HANDLE agora_rtm_stream_channel);

  /**
   * Join a topic.
   *
   * @param [in] topic The name of the topic.
   * @param [in] options The options of the topic.
   * @param [out] requestId The unique ID of this request.
   */
  AGORA_RTM_API_C_VOID agora_rtm_stream_channel_join_topic(AGORA_RTM_HANDLE agora_rtm_stream_channel, const char *topic, const join_topic_options *options, uint64_t *requestId);

  /**
   * Publish a message in the topic.
   *
   * @param [in] topic The name of the topic.
   * @param [in] message The content of the message.
   * @param [in] length The length of the message.
   * @param [in] option The option of the message.
   * @param [out] requestId The unique ID of this request.
   */
  AGORA_RTM_API_C_VOID agora_rtm_stream_channel_publish_topic_message(AGORA_RTM_HANDLE agora_rtm_stream_channel, const char *topic, const char *message, size_t length, const topic_message_options *option, uint64_t *requestId);

  /**
   * Leave the topic.
   *
   * @param [in] topic The name of the topic.
   * @param [out] requestId The unique ID of this request.
   */
  AGORA_RTM_API_C_VOID agora_rtm_stream_channel_leave_topic(AGORA_RTM_HANDLE agora_rtm_stream_channel, const char *topic, uint64_t *requestId);

  /**
   * Subscribe a topic.
   *
   * @param [in] topic The name of the topic.
   * @param [in] options The options of subscribe the topic.
   * @param [out] requestId The unique ID of this request.
   */
  AGORA_RTM_API_C_VOID agora_rtm_stream_channel_subscribe_topic(AGORA_RTM_HANDLE agora_rtm_stream_channel, const char *topic, const topic_options *options, uint64_t *requestId);

  /**
   * Unsubscribe a topic.
   *
   * @param [in] topic The name of the topic.
   * @param [in] options The options of unsubscribe the topic.
   * @param [out] requestId The unique ID of this request.
   */
  AGORA_RTM_API_C_VOID agora_rtm_stream_channel_unsubscribe_topic(AGORA_RTM_HANDLE agora_rtm_stream_channel, const char *topic, const topic_options *options, uint64_t *requestId);

  /**
   * Get subscribed user list
   *
   * @param [in] topic The name of the topic.
   * @param [out] requestId The unique ID of this request.
   */
  AGORA_RTM_API_C_VOID agora_rtm_stream_channel_get_subscribed_user_list(AGORA_RTM_HANDLE agora_rtm_stream_channel, const char *topic, uint64_t *requestId);

  /**
   * Release the stream channel instance.
   *
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  AGORA_RTM_API_C_INT agora_rtm_stream_channel_release(AGORA_RTM_HANDLE agora_rtm_stream_channel);

#pragma endregion C_IStreamChannel

#pragma endregion agora::rtm

#pragma endregion agora

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_I_AGORA_STREAM_CHANNEL_H
