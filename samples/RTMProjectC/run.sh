#!/bin/bash

# 设置库路径
SDK_PATH="/home/zhourui/rtm/agora_rtm_sdk_c/sdk_new/Agora_RTM_SDK_for_Linux_MINI_RTM/rtm/sdk"
export LD_LIBRARY_PATH=$SDK_PATH:$LD_LIBRARY_PATH

echo "LD_LIBRARY_PATH=$LD_LIBRARY_PATH"

# 运行程序
./build/RTMQuickStartC 