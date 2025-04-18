# AgoraRTM SDK
include(ExternalProject)
ExternalProject_Add(agora_rtm_sdk_download
  URL               file://${CMAKE_CURRENT_LIST_DIR}/../Agora_RTM_C++_SDK_for_Linux_v2.2.4.zip
  URL_HASH          MD5=40544932746f16945fbb31128eb0816f
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  UPDATE_COMMAND    ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
  )
ExternalProject_Get_Property(agora_rtm_sdk_download SOURCE_DIR)
set(AGORA_RTM_SDK_LIB_DIR ${SOURCE_DIR}/rtm/sdk)
set(AGORA_RTM_SDK_INCLUDE_DIR ${SOURCE_DIR}/rtm/sdk/high_level_api/include)
unset(SOURCE_DIR)

add_library(agora_rtm_sdk SHARED IMPORTED)
add_dependencies(agora_rtm_sdk agora_rtm_sdk_download)
file(MAKE_DIRECTORY ${AGORA_RTM_SDK_INCLUDE_DIR})
set_property(TARGET agora_rtm_sdk PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${AGORA_RTM_SDK_INCLUDE_DIR})
set_property(TARGET agora_rtm_sdk PROPERTY IMPORTED_LOCATION ${AGORA_RTM_SDK_LIB_DIR}/libagora_rtm_sdk.so)
set_property(TARGET agora_rtm_sdk PROPERTY IMPORTED_NO_SONAME TRUE)