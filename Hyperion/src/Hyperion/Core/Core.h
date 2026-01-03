#pragma once

#ifdef HYPERION_PLATFORM_WINDOWS
    #ifdef HYPERION_STATIC
        #define HYPERION_API
    #elif defined(HYPERION_BUILD_DLL)
        #define HYPERION_API __declspec(dllexport)
    #else
        #define HYPERION_API __declspec(dllimport)
    #endif
#else
    #error Hyperion only supports Windows!
#endif

#ifdef HYPERION_ENABLE_ASSERTS
#define HYPERION_CORE_ASSERT(x, ...) { if(!(x)) { HYPERION_CORE_ERROR("Assertion Failed: {}", __VA_ARGS__); __debugbreak(); } }
#define HYPERION_ASSERT(x, ...) { if(!(x)) { HYPERION_ERROR("Assertion Failed: {}", __VA_ARGS__); __debugbreak(); } }
#else
#define HYPERION_CORE_ASSERT(x, ...)
#define HYPERION_ASSERT(x, ...)
#endif

#define BIT(x) (1 << (x))