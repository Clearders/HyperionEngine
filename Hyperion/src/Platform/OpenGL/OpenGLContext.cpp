//
// Created by 13191 on 2026/3/10.
//


#include "glad/glad.h"

#ifndef GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_NONE
#endif
#include "GLFW/glfw3.h"


#include "OpenGLContext.h"
#include "../../Hyperion/hyperionpch.h"
#include "../../Hyperion/Core/Log.h"


#include "Hyperion/Core/Core.h"


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
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        HYPERION_CORE_ASSERT(status, "Failed to initialize GLAD");

        HYPERION_CORE_INFO("OpenGL Info:");
        HYPERION_CORE_INFO("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
        HYPERION_CORE_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
        HYPERION_CORE_INFO("  Version: {0}", (const char*)glGetString(GL_VERSION));
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_windowHandle);
    }
}
