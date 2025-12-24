#pragma once

#ifdef HYPERION_PLATFORM_WINDOWS
    #ifdef HYPERION_BUILD_DLL
        #define HYPERION_API __declspec(dllexport)
    #else
        #define HYPERION_API __declspec(dllimport)
    #endif
#else
    #error Hyperion only supports Windows!
#endif
