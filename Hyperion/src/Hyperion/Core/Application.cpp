#include "Application.h"
#include "../Events/ApplicationEvent.h"
#include "Log.h"
#include "../Events/Event.h"
#include "../hyperionpch.h"


namespace Hyperion
{
    Application::Application()
    = default;

    Application::~Application()
    = default;
    
    void Application::Run()
    {
        WindowResizeEvent e(1280, 720);
        if (e.IsInCategory(EventCategoryApplication))
        {
            HYPERION_TRACE("WindowResizeEvent is in Application Category");
        }
        if (e.IsInCategory(EventCategoryInput))
        {
            HYPERION_TRACE("WindowResizeEvent is in Input Category");
        }

        HYPERION_TRACE("WindowResizeEvent: {}, {}", e.GetWidth(), e.GetHeight());
        while (true);
    }



}
