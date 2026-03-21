//
// Created by 13191 on 2026/3/17.
//

#ifndef HYPERIONENGINE_RENDERCOMMAND_H
#define HYPERIONENGINE_RENDERCOMMAND_H

#include "RendererAPI.h"

namespace Hyperion
{
    class RenderCommand
    {
    public:
        inline static void SetClearColor(const glm::vec4& color)
        {
            s_RendererAPI->SetClearColor(color);
        };

        inline static void Clear()
        {
            s_RendererAPI->Clear();
        };

        inline static void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)
        {
            s_RendererAPI->DrawIndexed(vertexArray);
        }

    private:
        static RendererAPI* s_RendererAPI;
    };
} // Hyperion

#endif //HYPERIONENGINE_RENDERCOMMAND_H
