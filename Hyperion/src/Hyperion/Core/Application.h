#pragma once

#include "Core.h"
#include "Window.h"
// 将事件头的包含改为相对路径，保证在此目录下可找到
#include "../Events/Event.h"
#include "Hyperion/Events/ApplicationEvent.h"

namespace Hyperion
{
    class HYPERION_API Application
    {
        public:
        Application();
        virtual ~Application();

        void OnEvent(Event& event);

        void Run();
        private:
        bool OnWindowClose(WindowCloseEvent& event);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        
        
    };
    Application* CreateApplication();
}
