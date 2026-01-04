#include "Application.h"

#include <GL/gl.h>
#include <functional>

#include "../Events/ApplicationEvent.h"
#include "Log.h"
#include "../Events/Event.h"

#include "Layer.h"
#include "Window.h"
#include "GLFW/glfw3.h"


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

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
        {
            (*--it)->OnEvent(event);
            if (event.Handled)
                break;
        }
    }

    void Application::PushLayer(Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PopLayer(Layer* layer)
    {
    }

    void Application::PushOverlay(Layer* layer)
    {
        m_LayerStack.PushOverlay(layer);
        layer->OnAttach();
    }

    void Application::PopOverlay(Layer* overlay)
    {
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

            for (Layer* layer : m_LayerStack)
                layer->OnUpdate();

            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& event)
    {
        m_Running = false;
        return true;
    }



}
