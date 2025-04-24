#pragma once

#if defined(_WIN32)

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif  // !WIN32_LEAN_AND_MEAN
#if defined(__aarch64__)
#include <arm64intr.h>
#endif
#include <Windows.h>

#ifdef AGORARTM_EXPORT
#define AGORA_RTM_API_C __declspec(dllexport)
#else
#define AGORA_RTM_API_C __declspec(dllimport)
#endif  // AGORARTM_EXPORT

#define AGORA_RTM_CALL_C __cdecl

#elif defined(__APPLE__)

#include <TargetConditionals.h>

#define AGORA_RTM_API_C __attribute__((visibility("default")))
#define AGORA_RTM_CALL_C

#elif defined(__ANDROID__) || defined(__linux__)

#define AGORA_RTM_API_C __attribute__((visibility("default")))
#define AGORA_RTM_CALL_C

#else  // !_WIN32 && !__APPLE__ && !(__ANDROID__ || __linux__)

#define AGORA_RTM_API_C
#define AGORA_RTM_CALL_C

#endif  // _WIN32

#ifndef AGORA_RTM_HANDLE
#define AGORA_RTM_HANDLE void *
#endif  // AGORA_RTM_HANDLE

#define AGORA_RTM_API_C_VOID AGORA_RTM_API_C void AGORA_RTM_CALL_C
#define AGORA_RTM_API_C_INT AGORA_RTM_API_C int AGORA_RTM_CALL_C
#define AGORA_RTM_API_C_SIZE_T AGORA_RTM_API_C uint32_t AGORA_RTM_CALL_C
#define AGORA_RTM_API_C_HDL AGORA_RTM_API_C AGORA_RTM_HANDLE AGORA_RTM_CALL_C
#define AGORA_RTM_API_C_LITERAL AGORA_RTM_API_C const char* AGORA_RTM_CALL_C
