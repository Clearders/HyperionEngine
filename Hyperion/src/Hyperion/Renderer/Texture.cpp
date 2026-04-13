//
// Created by 13191 on 2026/4/12.
//

#include "Hyperion/hyperionpch.h"
#include "Texture.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Hyperion
{
    Ref<Texture2D> Texture2D::Create(const std::string& path)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:
            HYPERION_ASSERT(false, "RendererAPI::None is currently not supported!");
            return nullptr;
        case RendererAPI::API::OpenGL:
            return std::make_shared<OpenGLTexture2D>(path);
        }
        
        HYPERION_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
} // Hyperion