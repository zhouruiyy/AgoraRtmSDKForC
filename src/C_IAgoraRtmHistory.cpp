#include "IAgoraRtmHistory.h"

using namespace agora;
using namespace agora::rtm;

#include "C_IAgoraRtmHistory.h"

#pragma region agora

#pragma region agora::rtm

extern "C" {

int agora_rtm_history_get_messages(C_IRtmHistory *this_,
                                const char* channelName,
                                C_RTM_CHANNEL_TYPE channelType,
                                const C_GetHistoryMessagesOptions* options,
                                uint64_t* requestId) {
    if (!this_ || !channelName || !options || !requestId) {
        return -1;
    }
    
    GetHistoryMessagesOptions sdkOptions;
    sdkOptions.start = options->start;
    sdkOptions.end = options->end;
    sdkOptions.messageCount = options->count;
    
    ((IRtmHistory *)this_)->getMessages(channelName, 
                               static_cast<RTM_CHANNEL_TYPE>(channelType),
                               sdkOptions,
                               *requestId);
    return 0;
}

} // extern "C" 