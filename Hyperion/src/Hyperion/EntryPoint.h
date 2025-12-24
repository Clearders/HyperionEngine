#pragma once

#ifdef HYPERION_PLATFORM_WINDOWS
extern Hyperion::Application* CreateApplication();

    int main(int argc, char** argv)
    {
        printf("Hyperion Engine\n");
        auto app = CreateApplication();
        app->Run();
        delete app;
        return 0;
    }
#endif
