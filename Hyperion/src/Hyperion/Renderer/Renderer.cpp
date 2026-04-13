//
// Created by 13191 on 2026/3/15.
//

#include "Hyperion/hyperionpch.h"
#include "Renderer.h"
#include "Hyperion/Core/Log.h"
#include "Hyperion/Core/Core.h"

#include "Platform/OpenGL/OpenGLShader.h"

namespace Hyperion
{
    Renderer::SceneData* Renderer::m_SceneData = new Renderer::SceneData;

    void Renderer::BeginScene(OrthographicCamera& camera)
    {
        m_SceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
    }

    void Renderer::EndScene()
    {
    }

    void Renderer::Submit(const Hyperion::Ref<Shader>& shader, const Hyperion::Ref<VertexArray>& vertexArray, const glm::mat4& transform)
    {
        if (!shader)
        {
            HYPERION_CORE_ERROR("Renderer::Submit received null shader");
            return;
        }

        shader->Bind();
        auto glShader = std::dynamic_pointer_cast<OpenGLShader>(shader);
        if (!glShader)
        {
            HYPERION_CORE_ERROR("Renderer::Submit failed to cast Shader to OpenGLShader. Renderer API: {}", static_cast<int>(Renderer::GetAPI()));
            return;
        }

        glShader->UploadUniformMat4("u_ViewProjection", m_SceneData->ViewProjectionMatrix);
        glShader->UploadUniformMat4("u_Transform", transform);

        vertexArray->Bind();
        RenderCommand::DrawIndexed(vertexArray);
    }
} // Hyperion
