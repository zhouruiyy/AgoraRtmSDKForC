#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdarg.h>

// 包含API头文件
#include "C_AgoraRtmBase.h"
#include "C_IAgoraRtmClient.h"
#include "bridge/C_RtmEventHandlerBridge.h"

// Pass in your App ID here
const char *APP_ID = "15e6752675d244bfb048bf17b86d8f6a";
// 将TOKEN声明为非常量，以便后续可以修改
char TOKEN[1024] = "";
const char *USER_ID = "test_user";

// Terminal color codes for UBUNTU/LINUX
#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

// using namespace agora::rtm;

void signal_handler(int sig) {
    printf("\nExiting...\n");
    exit(0);
}

void C_DemoRtmEventHandler_cbPrint(const char *fmt, ...)
{
    printf(CYAN);
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    printf(RESET);
    fflush(stdout);
    va_end(args);
}

void C_DemoRtmEventHandler_onLoginResult(C_RtmEventHandlerBridge *this_, void *userData, const uint64_t requestId, enum C_RTM_ERROR_CODE errorCode)
{
    C_DemoRtmEventHandler_cbPrint("onLoginResult callback: requestId=%llu, errorCode=%d\n", requestId, errorCode);
}

void C_DemoRtmEventHandler_onConnectionStateChanged(C_RtmEventHandlerBridge *this_, void *userData, const char *channelName, enum C_RTM_CONNECTION_STATE state, enum C_RTM_CONNECTION_CHANGE_REASON reason)
{
    C_DemoRtmEventHandler_cbPrint("onConnectionStateChanged callback: channel=%s, state=%d, reason=%d\n", channelName ? channelName : "None", state, reason);
}

void C_DemoRtmEventHandler_onPublishResult(C_RtmEventHandlerBridge *this_, void *userData, const uint64_t requestId, enum C_RTM_ERROR_CODE errorCode)
{
    C_DemoRtmEventHandler_cbPrint("onPublishResult callback: requestId=%llu, errorCode=%d\n", requestId, errorCode);
}

void C_DemoRtmEventHandler_onMessageEvent(C_RtmEventHandlerBridge *this_, void *userData, const struct C_MessageEvent *event)
{
    C_DemoRtmEventHandler_cbPrint("onMessageEvent callback: channel=%s, message=%.*s, from=%s\n", event->channelName, (int)event->messageLength, event->message, event->publisher);
}

void C_DemoRtmEventHandler_onSubscribeResult(C_RtmEventHandlerBridge *this_, void *userData, const uint64_t requestId, const char *channelName, enum C_RTM_ERROR_CODE errorCode)
{
    C_DemoRtmEventHandler_cbPrint("onSubscribeResult callback: requestId=%llu, channel=%s, errorCode=%d\n", requestId, channelName, errorCode);
}

// Add the event listener
C_RtmEventHandlerBridge_Callbacks C_DemoRtmEventHandler = {
    .onLoginResult = C_DemoRtmEventHandler_onLoginResult,
    .onConnectionStateChanged = C_DemoRtmEventHandler_onConnectionStateChanged,
    .onPublishResult = C_DemoRtmEventHandler_onPublishResult,
    .onMessageEvent = C_DemoRtmEventHandler_onMessageEvent,
    .onSubscribeResult = C_DemoRtmEventHandler_onSubscribeResult,
};

typedef struct C_DemoMessaging
{
    C_RtmEventHandlerBridge *eventHandler_;
    C_IRtmClient *rtmClient_;
} C_DemoMessaging;

// 前置声明函数，以避免未声明的隐式函数调用
int agora_rtm_client_login(C_IRtmClient *this_, const char *token, uint64_t *requestId);
int agora_rtm_client_logout(C_IRtmClient *this_, uint64_t *requestId);
int agora_rtm_client_subscribe(C_IRtmClient *this_, const char *channelName, const struct C_SubscribeOptions *options, uint64_t *requestId);
int agora_rtm_client_unsubscribe(C_IRtmClient *this_, const char *channelName, uint64_t *requestId);
int agora_rtm_client_publish(C_IRtmClient *this_, const char *channelName, const char *message, const size_t length, const struct C_PublishOptions *option, uint64_t *requestId);
int agora_rtm_client_release(C_IRtmClient *this_);

C_DemoMessaging *C_DemoMessaging_New(const char *userId)
{
    C_DemoMessaging *this_ = (C_DemoMessaging *)calloc(1, sizeof(C_DemoMessaging));
    if (!this_) {
        printf(RED "Failed to allocate memory for C_DemoMessaging\n" RESET);
        return NULL;
    }
    
    // 初始化为NULL
    this_->eventHandler_ = NULL;
    this_->rtmClient_ = NULL;
    
    // 创建事件处理程序桥接器
    this_->eventHandler_ = C_RtmEventHandlerBridge_New(C_DemoRtmEventHandler, NULL);
    if (this_->eventHandler_ == NULL) {
        printf(RED "Failed to create event handler bridge\n" RESET);
        free(this_);
        return NULL;
    }
    
    // 创建配置
    struct C_RtmConfig *config = C_RtmConfig_New();
    if (config == NULL) {
        printf(RED "Failed to create RTM config\n" RESET);
        C_RtmEventHandlerBridge_Delete(this_->eventHandler_);
        free(this_);
        return NULL;
    }
    
    // 设置配置
    config->appId = APP_ID;
    config->userId = userId;
    config->eventHandler = this_->eventHandler_;
    
    // 创建RTM客户端
    int errorCode = 0;
    this_->rtmClient_ = agora_rtm_client_create(config, &errorCode);
    if (this_->rtmClient_ == NULL || errorCode != 0) {
        printf(RED "Error creating RTM client: %d\n" RESET, errorCode);
        C_RtmConfig_Delete(config);
        C_RtmEventHandlerBridge_Delete(this_->eventHandler_);
        free(this_);
        return NULL;
    }
    
    C_RtmConfig_Delete(config);
    return this_;
}

void C_DemoMessaging_Delete(C_DemoMessaging *this_)
{
    if (this_ == NULL) {
        return;
    }
    
    if (this_->rtmClient_ != NULL) {
        agora_rtm_client_release(this_->rtmClient_);
        this_->rtmClient_ = NULL;
    }
    
    if (this_->eventHandler_ != NULL) {
        C_RtmEventHandlerBridge_Delete(this_->eventHandler_);
        this_->eventHandler_ = NULL;
    }
    
    free(this_);
}

// Log out from the RTM server
void C_DemoMessaging_logout(C_DemoMessaging *this_)
{
    if (this_ == NULL || this_->rtmClient_ == NULL) {
        printf(RED "Invalid client state\n" RESET);
        return;
    }
    
    uint64_t requestId;
    int ret = agora_rtm_client_logout(this_->rtmClient_, &requestId);
    printf(BOLDBLUE "logout ret: %d, requestId: %llu\n" RESET, ret, requestId);
}

// Subscribe to a channel
void C_DemoMessaging_subscribeChannel(C_DemoMessaging *this_, char *chnId)
{
    if (this_ == NULL || this_->rtmClient_ == NULL || chnId == NULL) {
        printf(RED "Invalid parameters for subscribe\n" RESET);
        return;
    }
    
    struct C_SubscribeOptions *opt = C_SubscribeOptions_New();
    if (opt == NULL) {
        printf(RED "Failed to create subscribe options\n" RESET);
        return;
    }
    
    // 设置默认订阅选项
    opt->withMessage = true;
    opt->withPresence = true;
    
    uint64_t requestId;
    int ret = agora_rtm_client_subscribe(this_->rtmClient_, chnId, opt, &requestId);
    printf(BOLDBLUE "subscribe ret: %d, requestId: %llu\n" RESET, ret, requestId);
    
    C_SubscribeOptions_Delete(opt);
}

// Unsubscribe from a channel
void C_DemoMessaging_unsubscribeChannel(C_DemoMessaging *this_, char *chnId)
{
    if (this_ == NULL || this_->rtmClient_ == NULL || chnId == NULL) {
        printf(RED "Invalid parameters for unsubscribe\n" RESET);
        return;
    }
    
    uint64_t requestId;
    int ret = agora_rtm_client_unsubscribe(this_->rtmClient_, chnId, &requestId);
    printf(BOLDBLUE "unsubscribe ret: %d, requestId: %llu\n" RESET, ret, requestId);
}

// Publish a message
void C_DemoMessaging_publishMessage(C_DemoMessaging *this_, char *chn, char *msg)
{
    if (this_ == NULL || this_->rtmClient_ == NULL || chn == NULL || msg == NULL) {
        printf(RED "Invalid parameters for publish\n" RESET);
        return;
    }
    
    struct C_PublishOptions *opt = C_PublishOptions_New();
    if (opt == NULL) {
        printf(RED "Failed to create publish options\n" RESET);
        return;
    }
    
    // 设置消息类型为字符串
    opt->messageType = RTM_MESSAGE_TYPE_STRING;
    
    uint64_t requestId;
    int ret = agora_rtm_client_publish(this_->rtmClient_, chn, msg, strlen(msg), opt, &requestId);
    printf(BOLDBLUE "publish ret: %d, requestId: %llu\n" RESET, ret, requestId);
    
    C_PublishOptions_Delete(opt);
}

void C_DemoMessaging_Chat(C_DemoMessaging *this_, char *channel)
{
    if (this_ == NULL || channel == NULL) {
        printf(RED "Invalid parameters for chat\n" RESET);
        return;
    }
    
    // 订阅指定通道
    C_DemoMessaging_subscribeChannel(this_, channel);

    printf(YELLOW "\nEntering chat mode for channel %s. Type 'exit' to leave the chat.\n" RESET, channel);
    
    char buffer[1024];
    while (1) {
        printf(GREEN "Enter message: " RESET);
        fgets(buffer, sizeof(buffer), stdin);
        
        // 删除换行符
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
        
        if (strcmp(buffer, "exit") == 0) {
            break;
        }
        
        C_DemoMessaging_publishMessage(this_, channel, buffer);
    }
    
    // 离开时取消订阅
    C_DemoMessaging_unsubscribeChannel(this_, channel);
}

// Sample codes for the user interface
void C_DemoMessaging_mainMenu(C_DemoMessaging *this_)
{
    if (this_ == NULL) {
        printf(RED "Invalid client state\n" RESET);
        return;
    }
    
    int choice;
    char channel[64];
    char message[1024];
    
    while (1) {
        printf(YELLOW "\n===== RTM Demo Menu =====\n" RESET);
        printf("1. 订阅频道\n");
        printf("2. 取消订阅频道\n");
        printf("3. 发送消息\n");
        printf("4. 进入聊天模式\n");
        printf("5. 退出登录\n");
        printf("0. 退出\n");
        printf(YELLOW "选择操作: \n" RESET);
        
        if (scanf("%d", &choice) != 1) {
            // 清除输入缓冲区
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            continue;
        }
        getchar(); // 消耗换行符
        
        switch (choice) {
            case 1:
                printf("输入频道名称: ");
                fgets(channel, sizeof(channel), stdin);
                channel[strcspn(channel, "\n")] = 0; // 移除换行符
                C_DemoMessaging_subscribeChannel(this_, channel);
                break;
                
            case 2:
                printf("输入频道名称: ");
                fgets(channel, sizeof(channel), stdin);
                channel[strcspn(channel, "\n")] = 0;
                C_DemoMessaging_unsubscribeChannel(this_, channel);
                break;
                
            case 3:
                printf("输入频道名称: ");
                fgets(channel, sizeof(channel), stdin);
                channel[strcspn(channel, "\n")] = 0;
                
                printf("输入消息: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0;
                
                C_DemoMessaging_publishMessage(this_, channel, message);
                break;
                
            case 4:
                printf("输入频道名称: ");
                fgets(channel, sizeof(channel), stdin);
                channel[strcspn(channel, "\n")] = 0;
                C_DemoMessaging_Chat(this_, channel);
                break;
                
            case 5:
                C_DemoMessaging_logout(this_);
                return;
                
            case 0:
                C_DemoMessaging_logout(this_);
                return;
                
            default:
                printf(RED "无效选择，请重试\n" RESET);
                break;
        }
    }
}

void C_DemoMessaging_login(C_DemoMessaging *this_)
{
    if (this_ == NULL || this_->rtmClient_ == NULL) {
        printf(RED "Invalid client state\n" RESET);
        return;
    }
    
    while (1) {
        // 询问用户是否输入TOKEN
        printf(YELLOW "输入TOKEN (直接回车使用默认): " RESET);
        char tempToken[1024];
        fgets(tempToken, sizeof(tempToken), stdin);
        tempToken[strcspn(tempToken, "\n")] = 0; // 移除换行符
        
        // 如果用户输入了非空TOKEN，则使用用户输入的TOKEN
        if (strlen(tempToken) > 0) {
            strcpy(TOKEN, tempToken);
        } else if (strlen(TOKEN) == 0) {
            // 如果用户未输入且TOKEN为空，提示必须输入TOKEN
            printf(RED "必须输入有效的TOKEN\n" RESET);
            continue;
        }
        
        // 登录到RTM服务器
        uint64_t requestId;
        int ret = agora_rtm_client_login(this_->rtmClient_, TOKEN, &requestId);
        printf(BOLDBLUE "login ret: %d, requestId: %llu\n" RESET, ret, requestId);
        
        if (ret != 0) {
            continue; // 再次尝试登录
        }
        
        // 显示主菜单
        C_DemoMessaging_mainMenu(this_);
        
        printf(YELLOW "Quit? yes/no\n" RESET);
        char input[4];
        // Use fgets for safer input, read sizeof(input)-1 chars to leave space for null terminator
        if (fgets(input, sizeof(input), stdin) != NULL) {
            // Remove trailing newline if present
            input[strcspn(input, "\n")] = 0;
        } else {
            // Handle input error or EOF
            input[0] = '\0'; // Ensure string is empty on error
        }
        if (strcmp(input, "yes") == 0) {
            return;
        }
    }
}

int main(int argc, const char *argv[])
{
    // 设置中断处理
    signal(SIGINT, signal_handler);

    // 使用默认用户ID或让用户输入
    char userID[64];
    strcpy(userID, USER_ID); // 使用strcpy代替直接初始化

    printf(YELLOW "使用默认用户ID '%s'? (yes/no): " RESET, USER_ID);
    char input[256];
    scanf("%3s", input);
    getchar(); // 消耗换行符

    if (strcmp(input, "no") == 0) {
        printf("输入用户ID: ");
        fgets(userID, sizeof(userID), stdin);
        userID[strcspn(userID, "\n")] = 0; // 移除换行符
    }
    
    // 使用用户输入的ID创建客户端
    C_DemoMessaging *messaging = C_DemoMessaging_New(userID);
    if (messaging == NULL) {
        printf(RED "Failed to create messaging client\n" RESET);
        return 1;
    }
    
    C_DemoMessaging_login(messaging);
    
    C_DemoMessaging_Delete(messaging);
    return 0;
}

