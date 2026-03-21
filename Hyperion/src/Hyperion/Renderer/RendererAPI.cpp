//
// Created by 13191 on 2026/3/17.
//
#include "Hyperion/hyperionpch.h"
#include "RendererAPI.h"

namespace Hyperion
{
    RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;

    RendererAPI::~RendererAPI() = default;
} // Hyperion