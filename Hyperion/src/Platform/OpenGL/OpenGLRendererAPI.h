//
// Created by 13191 on 2026/3/17.
//

#ifndef HYPERIONENGINE_OPENGLRENDERERAPI_H
#define HYPERIONENGINE_OPENGLRENDERERAPI_H

#include "Hyperion/Renderer/RendererAPI.h"

namespace Hyperion
{
    class OpenGLRendererAPI : public RendererAPI
    {
    public:
        virtual void SetClearColor(const glm::vec4& color) override;
        virtual void Clear() override;

        virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) override;
    };
} // Hyperion

#endif //HYPERIONENGINE_OPENGLRENDERERAPI_H