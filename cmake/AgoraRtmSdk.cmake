# AgoraRTM SDK
include(ExternalProject)
if(APPLE) 
  set(SDK_URL file://${CMAKE_CURRENT_LIST_DIR}/../Agora_RTM_OC_SDK_v2.2.4.zip)
  set(SDK_URL_HASH MD5=f2012cbf6a7f7c4b01d05a3b1123eea0)
else()
  set(SDK_URL file://${CMAKE_CURRENT_LIST_DIR}/../Agora_RTM_C++_SDK_for_Linux_v2.2.4.zip)
  set(SDK_URL_HASH MD5=40544932746f16945fbb31128eb0816f)
endif()
ExternalProject_Add(agora_rtm_sdk_download
  URL               ${SDK_URL}
  URL_HASH          ${SDK_URL_HASH}
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  UPDATE_COMMAND    ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
  )
ExternalProject_Get_Property(agora_rtm_sdk_download SOURCE_DIR)
if (APPLE)
  add_custom_command(
    TARGET agora_rtm_sdk_download POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${CMAKE_CURRENT_SOURCE_DIR}
    python3 ${CMAKE_CURRENT_SOURCE_DIR}/cmake/framework_to_dylib.py
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Converting xcframework to dylib..."
  )

  set(AGORA_RTM_SDK_LIB_DIR ${AGORA_SDK_OUTPUT_DIR})
  set(AGORA_RTM_SDK_INCLUDE_DIR ${SOURCE_DIR}/headers)
  set(CMAKE_C_COMPILER "/usr/bin/clang")
  set(CMAKE_OBJC_COMPILER "/usr/bin/clang")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fobjc-arc")
  set(CMAKE_OBJC_FLAGS "${CMAKE_OBJC_FLAGS} -fobjc-arc")

  include_directories(${AGORA_RTM_SDK_INCLUDE_DIR})
  include_directories(${SOURCE_DIR}/headers)
else()
  set(AGORA_RTM_SDK_LIB_DIR ${SOURCE_DIR}/rtm/sdk)
  set(AGORA_RTM_SDK_INCLUDE_DIR ${SOURCE_DIR}/rtm/sdk/high_level_api/include)
endif()
unset(SOURCE_DIR)

add_library(agora_rtm_sdk SHARED IMPORTED)
add_dependencies(agora_rtm_sdk agora_rtm_sdk_download)
file(MAKE_DIRECTORY ${AGORA_RTM_SDK_INCLUDE_DIR})
set_property(TARGET agora_rtm_sdk PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${AGORA_RTM_SDK_INCLUDE_DIR})
if (APPLE)
  set_property(TARGET agora_rtm_sdk PROPERTY IMPORTED_LOCATION ${AGORA_RTM_SDK_LIB_DIR}/libAgoraRtmKit.dylib)
else()
  set_property(TARGET agora_rtm_sdk PROPERTY IMPORTED_LOCATION ${AGORA_RTM_SDK_LIB_DIR}/libagora_rtm_sdk.so)
endif()
set_property(TARGET agora_rtm_sdk PROPERTY IMPORTED_NO_SONAME TRUE)