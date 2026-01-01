#include "Application.h"
#include "../Events/ApplicationEvent.h"
#include "Log.h"


namespace Hyperion
{
    Application::Application()
    {
    }

    Application::~Application()
    {
    }
    
    void Application::Run()
    {
        WindowResizeEvent e(1280, 720);
        HYPERION_TRACE("WindowResizeEvent: {}, {}", e.GetWidth(), e.GetHeight());
        while (true);
    }



}
