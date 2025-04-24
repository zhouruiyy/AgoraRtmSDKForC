#include "IAgoraRtmHistory.h"

using namespace agora;
using namespace agora::rtm;

#include "C_IAgoraRtmHistory.h"

#pragma region agora

#pragma region agora::rtm

extern "C" {

AGORA_RTM_API_C_INT agora_rtm_history_get_messages(AGORA_RTM_HANDLE agora_rtm_history,
                                const char* channelName,
                                C_RTM_CHANNEL_TYPE channelType,
                                const get_history_messages_options* options,
                                uint64_t* requestId) {
    if (!agora_rtm_history || !channelName || !options || !requestId) {
        return -1;
    }
    
    GetHistoryMessagesOptions sdkOptions;
    sdkOptions.start = options->start;
    sdkOptions.end = options->end;
    sdkOptions.messageCount = options->count;
    
    ((IRtmHistory *)agora_rtm_history)->getMessages(channelName, 
                               static_cast<RTM_CHANNEL_TYPE>(channelType),
                               sdkOptions,
                               *requestId);
    return 0;
}

} // extern "C" 