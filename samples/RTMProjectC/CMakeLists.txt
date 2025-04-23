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
  link_directories(${CMAKE_SOURCE_DIR}/../../build)

  set(CMAKE_INSTALL_RPATH "@executable_path/../../../build")
  set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
else()
  link_directories(${CMAKE_SOURCE_DIR}/../../build/agora_rtm_sdk_download-prefix/src/agora_rtm_sdk_download/rtm/sdk)
  link_directories(${CMAKE_SOURCE_DIR}/../../build)

  set(CMAKE_CXX_FLAGS "-fPIC -O2 -g -std=c++11 -msse2")
  set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
endif()

add_executable(${TARGET_NAME} ${SOURCES} ${HEADERS})

if(APPLE)
  target_link_libraries(${TARGET_NAME} "${CMAKE_SOURCE_DIR}/../../build/libagora_rtm_sdk_c.dylib")

  set(LIBS_SOURCE_DIR "${CMAKE_SOURCE_DIR}/../../build/agora_rtm_sdk_download-prefix/src/agora_rtm_sdk_download/libs")
  set(LIBS_DEST_DIR "${CMAKE_SOURCE_DIR}/../../build")
  
  # 构建后复制依赖的 dylib 到主构建目录
  add_custom_command(
    TARGET ${TARGET_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Copying required dylibs to ${LIBS_DEST_DIR}"
    # 复制 libAgoraRtmKit.dylib
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${LIBS_SOURCE_DIR}/libAgoraRtmKit.dylib"
            "${LIBS_DEST_DIR}/libAgoraRtmKit.dylib"
    # 复制 libaosl.dylib (假设它在源目录中)
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${LIBS_SOURCE_DIR}/libaosl.dylib"
            "${LIBS_DEST_DIR}/libaosl.dylib"
    COMMENT "Copying dependencies for ${TARGET_NAME}"
    VERBATIM
  )

else()
  set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
  set(CMAKE_INSTALL_RPATH "$ORIGIN")

  target_link_libraries(${TARGET_NAME} agora_rtm_sdk_c stdc++ agora_rtm_sdk aosl pthread)

  # 设置源和目标目录变量
  set(LIBS_SOURCE_DIR "${CMAKE_SOURCE_DIR}/../../build/agora_rtm_sdk_download-prefix/src/agora_rtm_sdk_download/rtm/sdk")
  set(SO_SOURCE_DIR "${CMAKE_SOURCE_DIR}/../../build")
  set(LIBS_DEST_DIR "${CMAKE_SOURCE_DIR}/build")

  # 构建后复制依赖的 .so 到主构建目录
  add_custom_command(
    TARGET ${TARGET_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Copying required shared objects to ${LIBS_DEST_DIR}"
    # 复制 libagora_rtm_sdk.so
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${LIBS_SOURCE_DIR}/libagora_rtm_sdk.so"
            "${LIBS_DEST_DIR}/libagora_rtm_sdk.so"
    # 复制 libaosl.so (假设它在源目录中)
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${LIBS_SOURCE_DIR}/libaosl.so"
            "${LIBS_DEST_DIR}/libaosl.so"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${SO_SOURCE_DIR}/libagora_rtm_sdk_c.so"
            "${LIBS_DEST_DIR}/libagora_rtm_sdk_c.so"
    COMMENT "Copying dependencies for ${TARGET_NAME}"
    VERBATIM
  )
endif()