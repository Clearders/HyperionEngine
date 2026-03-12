//
// Created by 13191 on 2026/3/10.
//

#ifndef HYPERIONENGINE_OPENGLCONTEXT_H
#define HYPERIONENGINE_OPENGLCONTEXT_H
#include "Hyperion/Renderer/GraphicsContext.h"
#include "../../Hyperion/Renderer/GraphicsContext.h"
#include "GLFW/glfw3.h"

struct GLFWWindow;

namespace Hyperion
{
    class OpenGLContext :public GraphicsContext
    {
    public:
        OpenGLContext(GLFWwindow* windowHandle);

        virtual ~OpenGLContext() = default;

        virtual void Init() override;
        virtual void SwapBuffers() override;

    private:
        GLFWwindow* m_windowHandle;
    };
}


#endif //HYPERIONENGINE_OPENGLCONTEXT_H