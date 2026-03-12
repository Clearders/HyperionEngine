//
// Created by 13191 on 2026/3/10.
//


#include "glad/glad.h"


#include "OpenGLContext.h"
#include "../../Hyperion/hyperionpch.h"


#include "GLFW/glfw3.h"


#include "Hyperion/Core/Core.h"

struct GLFWWindow;

namespace Hyperion
{
    OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
        :m_windowHandle(windowHandle)
    {
        HYPERION_CORE_ASSERT(windowHandle, "Window handle is null!");
    }

    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_windowHandle);
        int ststus = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        HYPERION_CORE_ASSERT(ststus, "Failed to initialize GLAD");
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_windowHandle);
    }
}
