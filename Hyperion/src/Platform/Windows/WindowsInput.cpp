//
// Created by 13191 on 2026/1/29.
//

#include "WindowsInput.h"
#ifndef GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_NONE
#endif
#include "GLFW/glfw3.h"
#include "Hyperion/Core/Application.h"

namespace Hyperion
{
    Input* Input::m_instance = new WindowsInput();

    bool WindowsInput::IsKeyPressedImpl(int keycode)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
        // Implement Windows-specific key press detection
        return false; // Placeholder implementation
    }

    bool WindowsInput::IsMouseButtonPressedImpl(int button)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;
        // Implement Windows-specific mouse button press detection
        return false; // Placeholder implementation
    }

    std::pair<float, float> WindowsInput::GetMousePositionImpl()
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        return {static_cast<float>(xpos), static_cast<float>(ypos)};
        // Implement Windows-specific mouse position retrieval
        return {0.0f, 0.0f}; // Placeholder implementation
    }

    float WindowsInput::GetMouseXImpl()
    {
        auto [x,y] = GetMousePositionImpl();
        return x;
    }

    float WindowsInput::GetMouseYImpl()
    {
        auto [x,y] = GetMousePositionImpl();
        return y;
    }
}