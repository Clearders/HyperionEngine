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
        switch (Renderer::GetRendererAPI())
        {
        case RendererAPI::None:
            HYPERION_ASSERT(false, "RendererAPI::None is currently not supported!");
            return nullptr;
        case RendererAPI::OpenGL:
            return new OpenGLVertexArray();
        }
        HYPERION_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;

    };
} // Hyperion