//
// Created by 13191 on 2026/3/15.
//

#ifndef HYPERIONENGINE_RENDERER_H
#define HYPERIONENGINE_RENDERER_H

#include "Hyperion\Renderer\RenderCommand.h"

namespace Hyperion
{
    class Renderer
    {
        public:
        static void BeginScene();
        static void EndScene();

        static void Submit(const std::shared_ptr<VertexArray>& vertexArray);

        inline static RendererAPI::API GetAPI()
        {
            return RendererAPI::GetAPI();
        }
    };
} // Hyperion

#endif //HYPERIONENGINE_RENDERER_H