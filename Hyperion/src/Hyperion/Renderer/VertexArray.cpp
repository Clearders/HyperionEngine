//
// Created by 13191 on 2026/3/16.
//

#include "Hyperion/hyperionpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"


namespace Hyperion
{
    VertexArray* VertexArray::Create()
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:
            HYPERION_ASSERT(false, "RendererAPI::None is currently not supported!");
            return nullptr;
        case RendererAPI::API::OpenGL:
            return new OpenGLVertexArray();
        }
        HYPERION_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;

    };
} // Hyperion