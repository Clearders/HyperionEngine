//
// Created by 13191 on 2026/1/2.
//
#pragma once

#include "../../Hyperion/Core/Window.h"
#include <string>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#ifndef HYPERIONENGINE_WINDOWSWINDOW_H
#define HYPERIONENGINE_WINDOWSWINDOW_H


struct GLFWwindow;


namespace Hyperion
{
    class WindowsWindow : public Window
    {
    public:
        WindowsWindow(const WindowProps& props);
        virtual ~WindowsWindow();

        void OnUpdate() override;

        inline unsigned int GetWidth() const override { return m_Data.Width;}
        inline unsigned int GetHeight() const override { return m_Data.Height;}

        // Window attributes
        inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;

        virtual void* GetNativeWindow() const { return m_Window; }

        private:
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();

    private:
        GLFWwindow* m_Window{};

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFn EventCallback;
        };

        WindowData m_Data;
    };
} // Hyperion

#endif //HYPERIONENGINE_WINDOWSWINDOW_H