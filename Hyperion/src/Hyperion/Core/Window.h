//
// Created by 13191 on 2026/1/2.
//
#pragma once

#include "Core.h"
#include "../Events/Event.h"

#ifndef HYPERIONENGINE_WINDOW_H
#define HYPERIONENGINE_WINDOW_H

namespace Hyperion
{
    struct WindowProps
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProps(const std::string& title = "Hyperion Engine",
                    unsigned int width = 1280,
                    unsigned int height = 720)
            : Title(title), Width(width), Height(height)
        {}
    };
    class HYPERION_API Window
    {
    public:
        using EventCallback = std::function<void(Event&)>;

        virtual ~Window() = default;

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        // Window attributes
        virtual void SetEventCallback(const EventCallback& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const std::string& title, unsigned int width, unsigned int height);
    };
} // Hyperion

#endif //HYPERIONENGINE_WINDOW_H