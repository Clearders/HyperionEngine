#pragma once

#ifdef HYPERION_PLATFORM_WINDOWS
#include "Log.h"
extern Hyperion::Application* CreateApplication();

    int main(int argc, char** argv)
    {
        Hyperion::Log::Init();
        HYPERION_CORE_WARN("Initialized Log!");
        HYPERION_INFO("Hello!");
        
        printf("Hyperion Engine\n");
        auto app = CreateApplication();
        app->Run();
        delete app;
        return 0;
    }
#endif
