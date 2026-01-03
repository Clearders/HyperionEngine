#include "Application.h"

#include <GL/gl.h>
#include <functional>

#include "../Events/ApplicationEvent.h"
#include "Log.h"
#include "../Events/Event.h"


namespace Hyperion
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
    }

    Application::~Application(){}

    void Application::OnEvent(Event& event)
    {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

        HYPERION_CORE_TRACE("{}", event.ToString());
    }

    
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

    bool Application::OnWindowClose(WindowCloseEvent& event)
    {
        m_Running = false;
        return true;
    }



}
