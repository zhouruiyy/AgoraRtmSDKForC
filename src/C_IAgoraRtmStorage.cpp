// 引入AgoraRTM SDK
#include "IAgoraRtmStorage.h"

using namespace agora;
using namespace agora::rtm;

// Agora C封装
#include "C_IAgoraRtmStorage.h"

#pragma region agora

#pragma region agora::rtm

struct C_MetadataOptions *C_MetadataOptions_New()
{
  return (C_MetadataOptions *)new MetadataOptions();
}
void C_MetadataOptions_Delete(struct C_MetadataOptions *this_)
{
  delete (MetadataOptions *)this_;
}

struct C_MetadataItem *C_MetadataItem_New()
{
  return (C_MetadataItem *)new MetadataItem();
}
void C_MetadataItem_Delete(struct C_MetadataItem *this_)
{
  delete (MetadataItem *)this_;
}

struct C_Metadata *C_Metadata_New()
{
  return (C_Metadata *)new Metadata();
}
void C_Metadata_Delete(struct C_Metadata *this_)
{
  delete (Metadata *)this_;
}

#pragma region C_IRtmStorage

void agora_rtm_storage_set_channel_metadata(C_IRtmStorage *this_,
                                     const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const struct C_Metadata *data, const struct C_MetadataOptions *options, const char *lockName, uint64_t *requestId)
{
  if (!this_ || !channelName || !data || !options || !requestId) {
    return;
  }
  ((IRtmStorage *)this_)->setChannelMetadata(channelName, (RTM_CHANNEL_TYPE)channelType, *(const Metadata *)data, *(const MetadataOptions *)options, lockName, *requestId);
}

void agora_rtm_storage_update_channel_metadata(C_IRtmStorage *this_,
                                        const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const struct C_Metadata *data, const struct C_MetadataOptions *options, const char *lockName, uint64_t *requestId)
{
  if (!this_ || !channelName || !data || !options || !requestId) {
    return;
  }
  ((IRtmStorage *)this_)->updateChannelMetadata(channelName, (RTM_CHANNEL_TYPE)channelType, *(const Metadata *)data, *(const MetadataOptions *)options, lockName, *requestId);
}

void agora_rtm_storage_remove_channel_metadata(C_IRtmStorage *this_,
                                        const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, const struct C_Metadata *data, const struct C_MetadataOptions *options, const char *lockName, uint64_t *requestId)
{
  if (!this_ || !channelName || !data || !options || !requestId) {
    return;
  }
  ((IRtmStorage *)this_)->removeChannelMetadata(channelName, (RTM_CHANNEL_TYPE)channelType, *(const Metadata *)data, *(const MetadataOptions *)options, lockName, *requestId);
}

void agora_rtm_storage_get_channel_metadata(C_IRtmStorage *this_,
                                     const char *channelName, enum C_RTM_CHANNEL_TYPE channelType, uint64_t *requestId)
{
  if (!this_ || !channelName || !requestId) {
    return;
  }
  ((IRtmStorage *)this_)->getChannelMetadata(channelName, (RTM_CHANNEL_TYPE)channelType, *requestId);
}

void agora_rtm_storage_set_user_metadata(C_IRtmStorage *this_,
                                  const char *userId, const struct C_Metadata *data, const struct C_MetadataOptions *options, uint64_t *requestId)
{
  if (!this_ || !userId || !data || !options || !requestId) {
    return;
  }
  ((IRtmStorage *)this_)->setUserMetadata(userId, *(const Metadata *)data, *(const MetadataOptions *)options, *requestId);
}

void agora_rtm_storage_update_user_metadata(C_IRtmStorage *this_,
                                     const char *userId, const struct C_Metadata *data, const struct C_MetadataOptions *options, uint64_t *requestId)
{
  if (!this_ || !userId || !data || !options || !requestId) {
    return;
  }
  ((IRtmStorage *)this_)->updateUserMetadata(userId, *(const Metadata *)data, *(const MetadataOptions *)options, *requestId);
}

void agora_rtm_storage_remove_user_metadata(C_IRtmStorage *this_,
                                     const char *userId, const struct C_Metadata *data, const struct C_MetadataOptions *options, uint64_t *requestId)
{
  if (!this_ || !userId || !data || !options || !requestId) {
    return;
  }
  ((IRtmStorage *)this_)->removeUserMetadata(userId, *(const Metadata *)data, *(const MetadataOptions *)options, *requestId);
}

void agora_rtm_storage_get_user_metadata(C_IRtmStorage *this_, const char *userId, uint64_t *requestId)
{
  if (!this_ || !userId || !requestId) {
    return;
  }
  ((IRtmStorage *)this_)->getUserMetadata(userId, *requestId);
}

void agora_rtm_storage_subscribe_user_metadata(C_IRtmStorage *this_, const char *userId, uint64_t *requestId)
{
  if (!this_ || !userId || !requestId) {
    return;
  }
  ((IRtmStorage *)this_)->subscribeUserMetadata(userId, *requestId);
}

void agora_rtm_storage_unsubscribe_user_metadata(C_IRtmStorage *this_, const char *userId, uint64_t *requestId)
{
  if (!this_ || !userId || !requestId) {
    return;
  }
  ((IRtmStorage *)this_)->unsubscribeUserMetadata(userId, *requestId);
}

#pragma endregion C_IRtmStorage

#pragma endregion agora::rtm

#pragma endregion agora
