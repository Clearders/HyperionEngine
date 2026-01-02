#pragma once

#include "Core.h"

namespace Hyperion
{
    class HYPERION_API Application
    {
        public:
        Application();
        virtual ~Application();

        static void Run();
        
        
    };
    Application* CreateApplication();
}
