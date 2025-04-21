# CMakeLists.txt
cmake_minimum_required (VERSION 2.8)
project(RTMProjectC)
set(TARGET_NAME RTMQuickStartC)
set(SOURCES RTMQuickStartC.c)
set(HEADERS)
set(TARGET_BUILD_TYPE "Debug")

# Common include directory
include_directories(${CMAKE_SOURCE_DIR}/../../include)

if(APPLE)
  # macOS specific settings
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -O2 -g -std=c++11")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -O2 -g")

  include_directories(${CMAKE_SOURCE_DIR}/../../include)
  include_directories(${CMAKE_SOURCE_DIR}/../../build/agora_rtm_sdk_download-prefix/src/agora_rtm_sdk_download/headers)
  
  link_directories(${CMAKE_SOURCE_DIR}/../../build)
  link_directories(${CMAKE_SOURCE_DIR}/../../build/agora_rtm_sdk_download-prefix/src/agora_rtm_sdk_download/libs)

  set(CMAKE_INSTALL_RPATH "@executable_path/../../../build/agora_rtm_sdk_download-prefix/src/agora_rtm_sdk_download/libs")
  set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
else()
  link_directories(${CMAKE_SOURCE_DIR}/../../build/agora_rtm_sdk_download-prefix/src/agora_rtm_sdk_download/rtm/sdk)
  link_directories(${CMAKE_SOURCE_DIR}/../../build)

  set(CMAKE_CXX_FLAGS "-fPIC -O2 -g -std=c++11 -msse2")
  set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib:${CMAKE_SOURCE_DIR}/../../build/agora_rtm_sdk_download-prefix/src/agora_rtm_sdk_download/rtm/sdk")
  set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
endif()

add_executable(${TARGET_NAME} ${SOURCES} ${HEADERS})

if(APPLE)
  target_link_libraries(${TARGET_NAME} agora_rtm_sdk_c AgoraRtmKit aosl stdc++ pthread)
else()
  target_link_libraries(${TARGET_NAME} agora_rtm_sdk_c stdc++ agora_rtm_sdk pthread aosl)
endif()