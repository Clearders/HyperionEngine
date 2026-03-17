//
// Created by 13191 on 2026/3/17.
//

#include "Hyperion/hyperionpch.h"
#include "OpenGLRendererAPI.h"
#include <glad/glad.h>

namespace Hyperion
{
        void OpenGLRendererAPI::SetClearColor(const glm::vec4& color)
        {
            glClearColor(color.r, color.g, color.b, color.a);
        }

        void OpenGLRendererAPI::Clear()
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void OpenGLRendererAPI::DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)
        {
            uint32_t indexCount = vertexArray->GetIndexBuffer()->GetCount();
            glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
        }
} // Hyperion