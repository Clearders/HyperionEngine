//
// Created by 13191 on 2026/3/15.
//

#include "Hyperion/hyperionpch.h"
#include "Renderer.h"

namespace Hyperion
{
    void Renderer::BeginScene()
    {
    }

    void Renderer::EndScene()
    {
    }

    void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray)
    {
        vertexArray->Bind();
        RenderCommand::DrawIndexed(vertexArray);
    }
} // Hyperion