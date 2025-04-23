set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
if(APPLE)
  set(CMAKE_INSTALL_RPATH "@executable_path/../lib;@loader_path")
  set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
endif()

cmake_minimum_required(VERSION 3.0.0)
project(agora_rtm_sdk_c VERSION 2.1.12)
set(CMAKE_CXX_STANDARD 11)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(AgoraRtmSdk)

add_library(${PROJECT_NAME} SHARED)
target_include_directories(${PROJECT_NAME} PUBLIC "./include")
aux_source_directory(./src SRCS)
aux_source_directory(./src/bridge BRIDGE_SRCS)
target_sources(${PROJECT_NAME} PRIVATE ${SRCS} ${BRIDGE_SRCS})

# include AgoraRTM SDK
target_include_directories(${PROJECT_NAME} PRIVATE agora_rtm_sdk)
target_link_libraries(${PROJECT_NAME} agora_rtm_sdk)
