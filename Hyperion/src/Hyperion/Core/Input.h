//
// Created by 13191 on 2026/1/21.
//
#pragma once

#include <utility>

#include "Core.h"

namespace Hyperion
{
    class HYPERION_API Input
    {
    public:
        inline static bool IsKeyPressed(int keycode)
        {
            return m_instance->IsKeyPressedImpl(keycode);
        };
        inline static bool IsMouseButtonPressed(int button)
        {
            return m_instance->IsMouseButtonPressedImpl(button);
        };
        inline static std::pair<float, float> GetMousePosition()
        {
            return m_instance->GetMousePositionImpl();
        }
        static float GetMouseX()
        {
            auto [x, y] = m_instance->GetMousePositionImpl();
            return x;
        };
        static float GetMouseY()
        {
            auto [x, y] = m_instance->GetMousePositionImpl();
            return y;
        };

    protected:
        virtual bool IsKeyPressedImpl(int keycode) = 0;
        virtual bool IsMouseButtonPressedImpl(int button) = 0;
        virtual std::pair<float, float> GetMousePositionImpl() = 0;

        virtual float GetMouseXImpl() = 0;
        virtual float GetMouseYImpl() = 0;

    private:
        static Input* m_instance;
    };
}