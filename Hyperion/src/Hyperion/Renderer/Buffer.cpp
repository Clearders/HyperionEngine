//
// Created by 13191 on 2026/3/15.
//
#include "Hyperion/hyperionpch.h"
#include "Buffer.h"

#include "OpenGLBuffer.h"
#include "Renderer.h"
#include "Hyperion/Core/Core.h"

namespace Hyperion
{
    VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
    {
        switch (Renderer::GetRendererAPI())
        {
            case RendererAPI::None:
                HYPERION_ASSERT(false, "RendererAPI::None is currently not supported!");
                return nullptr;
            case RendererAPI::OpenGL:
                return new OpenGLVertexBuffer(vertices, size);
        }
        HYPERION_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count)
    {
        switch (Renderer::GetRendererAPI())
        {
        case RendererAPI::None:
            HYPERION_ASSERT(false, "RendererAPI::None is currently not supported!");
            return nullptr;
        case RendererAPI::OpenGL:
            return new OpenGLIndexBuffer(indices, count);
        }
        HYPERION_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}
