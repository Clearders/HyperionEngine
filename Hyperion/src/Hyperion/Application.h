#pragma once

#include "Core.h"

namespace Hyperion
{
    class HYPERION_API Application
    {
        public:
        Application();
        virtual ~Application();
        
        void Run();
        
        
    };
    Application* CreateApplication();
}
