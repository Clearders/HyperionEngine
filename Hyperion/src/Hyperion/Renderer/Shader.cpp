//
// Created by 13191 on 2026/3/14.
//

#include "../hyperionpch.h"
#include "Shader.h"

#include <glad/glad.h>

#include "Renderer.h"
#include "VertexArray.h"
#include "glm/gtc/type_ptr.hpp"
#include "Hyperion/Core/Core.h"
#include "Platform/OpenGL/OpenGLShader.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Hyperion
{
    Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:
                HYPERION_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
                return nullptr;
            case RendererAPI::API::OpenGL:
                return new OpenGLShader(vertexSrc, fragmentSrc);
        }

        HYPERION_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
} // Hyperion