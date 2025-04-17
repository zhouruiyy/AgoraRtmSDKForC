# CMakeLists.txt
cmake_minimum_required (VERSION 2.8)
project(RTMProjectC)
set(TARGET_NAME RTMQuickStartC)
set(SOURCES RTMQuickStartC.c)
set(HEADERS)
set(TARGET_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "-fPIC -O2 -g -std=c++11 -msse2")
include_directories(${CMAKE_SOURCE_DIR}/../../include)

# 添加SDK库目录（首先使用下载的SDK库路径）
link_directories(${CMAKE_SOURCE_DIR}/../../sdk_new/Agora_RTM_SDK_for_Linux_MINI_RTM/rtm/sdk)
link_directories(${CMAKE_SOURCE_DIR}/../../build)

set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib:/home/zhourui/rtm/agora_rtm_sdk_c/sdk_new/Agora_RTM_SDK_for_Linux_MINI_RTM/rtm/sdk")
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

add_executable(${TARGET_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${TARGET_NAME} agora_rtm_sdk_c stdc++ agora_rtm_sdk pthread aosl)