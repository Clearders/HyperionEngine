#pragma once

#include "Core.h"
#include "Window.h"
#include "LayerStack.h"
#include "../Events/Event.h"
#include "Hyperion/Events/ApplicationEvent.h"

#include "Hyperion/ImGui/ImGuiLayer.h"

namespace Hyperion
{
    class HYPERION_API Application
    {

        public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& event);

        void PushLayer(Layer* layer);
        void PopLayer(Layer* layer);

        void PushOverlay(Layer* overlay);
        void PopOverlay(Layer* overlay);

        inline static Application& Get() { return *m_Instance; }
        inline Window& GetWindow() { return *m_Window;}
        private:
        bool OnWindowClose(WindowCloseEvent& event);

        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        LayerStack m_LayerStack;

        static Application* m_Instance;
        
        
    };
    Application* CreateApplication();
}
