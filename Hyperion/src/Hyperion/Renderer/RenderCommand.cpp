//
// Created by 13191 on 2026/3/17.
//

#include "Hyperion/hyperionpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Hyperion
{
    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
} // Hyperion