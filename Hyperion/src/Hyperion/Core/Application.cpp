#include "Application.h"

#include <GL/gl.h>

#include "../Events/ApplicationEvent.h"
#include "Log.h"
#include "../Events/Event.h"
#include "../hyperionpch.h"


namespace Hyperion
{
    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application(){}
    
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
        while (m_Running)
        {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
        }
    }



}
