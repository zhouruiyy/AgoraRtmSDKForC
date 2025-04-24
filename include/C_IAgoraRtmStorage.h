#ifndef C_I_AGORA_RTM_STORAGE_H
#define C_I_AGORA_RTM_STORAGE_H

#include "agora_rtm_api.h"

#include "C_AgoraRtmBase.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#pragma region agora

#pragma region agora::rtm

  /**
   * Metadata options.
   */
  typedef struct _metadata_options
  {
    /**
     * Indicates whether or not to notify server update the modify timestamp of metadata
     */
    bool recordTs;
    /**
     * Indicates whether or not to notify server update the modify user id of metadata
     */
    bool recordUserId;
  } metadata_options;
  metadata_options *metadata_options_create();
  void metadata_options_delete(metadata_options *this_);

  typedef struct _metadata_item
  {
    /**
     * The key of the metadata item.
     */
    const char *key;
    /**
     * The value of the metadata item.
     */
    const char *value;
    /**
     * The User ID of the user who makes the latest update to the metadata item.
     */
    const char *authorUserId;
    /**
     * The revision of the metadata item.
     */
    int64_t revision;
    /**
     * The Timestamp when the metadata item was last updated.
     */
    int64_t updateTs;
  } metadata_item;
  metadata_item *metadata_item_create();
  void metadata_item_delete(metadata_item *this_);

  typedef struct _metadata
  {
    /**
     * the major revision of metadata.
     */
    int64_t majorRevision;
    /**
     * The metadata item array.
     */
    metadata_item *items;
    /**
     * The items count.
     */
    size_t itemCount;
  } metadata;
  metadata *metadata_create();
  void metadata_delete(metadata *this_);

#pragma region agora_rtm_storage
  /**
   * Set the metadata of a specified channel.
   *
   * @param [in] channelName The name of the channel.
   * @param [in] channelType Which channel type, RTM_CHANNEL_TYPE_STREAM or RTM_CHANNEL_TYPE_MESSAGE.
   * @param [in] data Metadata data.
   * @param [in] options The options of operate metadata.
   * @param [in] lock lock for operate channel metadata.
   * @param [out] requestId The unique ID of this request.
   */
  AGORA_RTM_API_C_VOID agora_rtm_storage_set_channel_metadata(AGORA_RTM_HANDLE agora_rtm_storage,
                                       const char *channelName, C_RTM_CHANNEL_TYPE channelType, const metadata *data, const metadata_options *options, const char *lockName, uint64_t *requestId);
  /**
   * Update the metadata of a specified channel.
   *
   * @param [in] channelName The channel Name of the specified channel.
   * @param [in] channelType Which channel type, RTM_CHANNEL_TYPE_STREAM or RTM_CHANNEL_TYPE_MESSAGE.
   * @param [in] data Metadata data.
   * @param [in] options The options of operate metadata.
   * @param [in] lock lock for operate channel metadata.
   * @param [out] requestId The unique ID of this request.
   */
  AGORA_RTM_API_C_VOID agora_rtm_storage_update_channel_metadata(AGORA_RTM_HANDLE agora_rtm_storage,
                                          const char *channelName, C_RTM_CHANNEL_TYPE channelType, const metadata *data, const metadata_options *options, const char *lockName, uint64_t *requestId);
  /**
   * Remove the metadata of a specified channel.
   *
   * @param [in] channelName The channel Name of the specified channel.
   * @param [in] channelType Which channel type, RTM_CHANNEL_TYPE_STREAM or RTM_CHANNEL_TYPE_MESSAGE.
   * @param [in] data Metadata data.
   * @param [in] options The options of operate metadata.
   * @param [in] lock lock for operate channel metadata.
   * @param [out] requestId The unique ID of this request.
   */
  AGORA_RTM_API_C_VOID agora_rtm_storage_remove_channel_metadata(AGORA_RTM_HANDLE agora_rtm_storage,
                                          const char *channelName, C_RTM_CHANNEL_TYPE channelType, const metadata *data, const metadata_options *options, const char *lockName, uint64_t *requestId);
  /**
   * Get the metadata of a specified channel.
   *
   * @param [in] channelName The channel Name of the specified channel.
   * @param [in] channelType Which channel type, RTM_CHANNEL_TYPE_STREAM or RTM_CHANNEL_TYPE_MESSAGE.
   * @param requestId The unique ID of this request.
   */
  AGORA_RTM_API_C_VOID agora_rtm_storage_get_channel_metadata(AGORA_RTM_HANDLE agora_rtm_storage,
                                       const char *channelName, C_RTM_CHANNEL_TYPE channelType, uint64_t *requestId);

  /**
   * Set the metadata of a specified user.
   *
   * @param [in] userId The user ID of the specified user.
   * @param [in] data Metadata data.
   * @param [in] options The options of operate metadata.
   * @param [out] requestId The unique ID of this request.
   */
  AGORA_RTM_API_C_VOID agora_rtm_storage_set_user_metadata(AGORA_RTM_HANDLE agora_rtm_storage,
                                    const char *userId, const metadata *data, const metadata_options *options, uint64_t *requestId);
  /**
   * Update the metadata of a specified user.
   *
   * @param [in] userId The user ID of the specified user.
   * @param [in] data Metadata data.
   * @param [in] options The options of operate metadata.
   * @param [out] requestId The unique ID of this request.
   */
  AGORA_RTM_API_C_VOID agora_rtm_storage_update_user_metadata(AGORA_RTM_HANDLE agora_rtm_storage,
                                       const char *userId, const metadata *data, const metadata_options *options, uint64_t *requestId);
  /**
   * Remove the metadata of a specified user.
   *
   * @param [in] userId The user ID of the specified user.
   * @param [in] data Metadata data.
   * @param [in] options The options of operate metadata.
   * @param [out] requestId The unique ID of this request.
   */
  AGORA_RTM_API_C_VOID agora_rtm_storage_remove_user_metadata(AGORA_RTM_HANDLE agora_rtm_storage,
                                       const char *userId, const metadata *data, const metadata_options *options, uint64_t *requestId);
  /**
   * Get the metadata of a specified user.
   *
   * @param [in] userId The user ID of the specified user.
   * @param [out] requestId The unique ID of this request.
   */
  AGORA_RTM_API_C_VOID agora_rtm_storage_get_user_metadata(AGORA_RTM_HANDLE agora_rtm_storage, const char *userId, uint64_t *requestId);

  /**
   * Subscribe the metadata update event of a specified user.
   *
   * @param [in] userId The user ID of the specified user.
   * @param [out] requestId The unique ID of this request.
   */
  AGORA_RTM_API_C_VOID agora_rtm_storage_subscribe_user_metadata(AGORA_RTM_HANDLE agora_rtm_storage, const char *userId, uint64_t *requestId);
  /**
   * unsubscribe the metadata update event of a specified user.
   *
   * @param [in] userId The user ID of the specified user.
   * @param [out] requestId The unique ID of this request.
   */
  AGORA_RTM_API_C_VOID agora_rtm_storage_unsubscribe_user_metadata(AGORA_RTM_HANDLE agora_rtm_storage, const char *userId, uint64_t *requestId);

#pragma endregion agora_rtm_storage

#pragma endregion agora::rtm

#pragma endregion agora

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_I_AGORA_RTM_STORAGE_H
