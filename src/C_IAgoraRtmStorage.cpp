// 引入AgoraRTM SDK
#include "IAgoraRtmStorage.h"

using namespace agora;
using namespace agora::rtm;

// Agora C封装
#include "C_IAgoraRtmStorage.h"

#pragma region agora

#pragma region agora::rtm

metadata_options *metadata_options_create()
{
  return (metadata_options *)new MetadataOptions();
}
void metadata_options_delete(metadata_options *this_)
{
  delete (MetadataOptions *)this_;
}

metadata_item *metadata_item_create()
{
  return (metadata_item *)new MetadataItem();
}
void metadata_item_delete(metadata_item *this_)
{
  delete (MetadataItem *)this_;
}

metadata *metadata_create()
{
  return (metadata *)new Metadata();
}
void metadata_delete(metadata *this_)
{
  delete (Metadata *)this_;
}

#pragma region agora_rtm_storage

AGORA_RTM_API_C_VOID agora_rtm_storage_set_channel_metadata(AGORA_RTM_HANDLE agora_rtm_storage,
                                     const char *channelName, RTM_CHANNEL_TYPE channelType, const metadata *data, const metadata_options *options, const char *lockName, uint64_t *requestId)
{
  if (!agora_rtm_storage || !channelName || !data || !options || !requestId) {
    return;
  }
  ((IRtmStorage *)agora_rtm_storage)->setChannelMetadata(channelName, (RTM_CHANNEL_TYPE)channelType, *(const Metadata *)data, *(const MetadataOptions *)options, lockName, *requestId);
}

AGORA_RTM_API_C_VOID agora_rtm_storage_update_channel_metadata(AGORA_RTM_HANDLE agora_rtm_storage,
                                        const char *channelName, RTM_CHANNEL_TYPE channelType, const metadata *data, const metadata_options *options, const char *lockName, uint64_t *requestId)
{
  if (!agora_rtm_storage || !channelName || !data || !options || !requestId) {
    return;
  }
  ((IRtmStorage *)agora_rtm_storage)->updateChannelMetadata(channelName, (RTM_CHANNEL_TYPE)channelType, *(const Metadata *)data, *(const MetadataOptions *)options, lockName, *requestId);
}

AGORA_RTM_API_C_VOID agora_rtm_storage_remove_channel_metadata(AGORA_RTM_HANDLE agora_rtm_storage,
                                        const char *channelName, RTM_CHANNEL_TYPE channelType, const metadata *data, const metadata_options *options, const char *lockName, uint64_t *requestId)
{
  if (!agora_rtm_storage || !channelName || !data || !options || !requestId) {
    return;
  }
  ((IRtmStorage *)agora_rtm_storage)->removeChannelMetadata(channelName, (RTM_CHANNEL_TYPE)channelType, *(const Metadata *)data, *(const MetadataOptions *)options, lockName, *requestId);
}

AGORA_RTM_API_C_VOID agora_rtm_storage_get_channel_metadata(AGORA_RTM_HANDLE agora_rtm_storage,
                                     const char *channelName, RTM_CHANNEL_TYPE channelType, uint64_t *requestId)
{
  if (!agora_rtm_storage || !channelName || !requestId) {
    return;
  }
  ((IRtmStorage *)agora_rtm_storage)->getChannelMetadata(channelName, (RTM_CHANNEL_TYPE)channelType, *requestId);
}

AGORA_RTM_API_C_VOID agora_rtm_storage_set_user_metadata(AGORA_RTM_HANDLE agora_rtm_storage,
                                  const char *userId, const metadata *data, const metadata_options *options, uint64_t *requestId)
{
  if (!agora_rtm_storage || !userId || !data || !options || !requestId) {
    return;
  }
  ((IRtmStorage *)agora_rtm_storage)->setUserMetadata(userId, *(const Metadata *)data, *(const MetadataOptions *)options, *requestId);
}

AGORA_RTM_API_C_VOID agora_rtm_storage_update_user_metadata(AGORA_RTM_HANDLE agora_rtm_storage,
                                     const char *userId, const metadata *data, const metadata_options *options, uint64_t *requestId)
{
  if (!agora_rtm_storage || !userId || !data || !options || !requestId) {
    return;
  }
  ((IRtmStorage *)agora_rtm_storage)->updateUserMetadata(userId, *(const Metadata *)data, *(const MetadataOptions *)options, *requestId);
}

AGORA_RTM_API_C_VOID agora_rtm_storage_remove_user_metadata(AGORA_RTM_HANDLE agora_rtm_storage,
                                     const char *userId, const metadata *data, const metadata_options *options, uint64_t *requestId)
{
  if (!agora_rtm_storage || !userId || !data || !options || !requestId) {
    return;
  }
  ((IRtmStorage *)agora_rtm_storage)->removeUserMetadata(userId, *(const Metadata *)data, *(const MetadataOptions *)options, *requestId);
}

AGORA_RTM_API_C_VOID agora_rtm_storage_get_user_metadata(AGORA_RTM_HANDLE agora_rtm_storage, const char *userId, uint64_t *requestId)
{
  if (!agora_rtm_storage || !userId || !requestId) {
    return;
  }
  ((IRtmStorage *)agora_rtm_storage)->getUserMetadata(userId, *requestId);
}

AGORA_RTM_API_C_VOID agora_rtm_storage_subscribe_user_metadata(AGORA_RTM_HANDLE agora_rtm_storage, const char *userId, uint64_t *requestId)
{
  if (!agora_rtm_storage || !userId || !requestId) {
    return;
  }
  ((IRtmStorage *)agora_rtm_storage)->subscribeUserMetadata(userId, *requestId);
}

AGORA_RTM_API_C_VOID agora_rtm_storage_unsubscribe_user_metadata(AGORA_RTM_HANDLE agora_rtm_storage, const char *userId, uint64_t *requestId)
{
  if (!agora_rtm_storage || !userId || !requestId) {
    return;
  }
  ((IRtmStorage *)agora_rtm_storage)->unsubscribeUserMetadata(userId, *requestId);
}

#pragma endregion agora_rtm_storage

#pragma endregion agora::rtm

#pragma endregion agora
