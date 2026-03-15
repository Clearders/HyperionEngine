//
// Created by 13191 on 2026/3/15.
//

#ifndef HYPERIONENGINE_RENDERER_H
#define HYPERIONENGINE_RENDERER_H

namespace Hyperion
{
    enum class RendererAPI
    {
        None = 0,OpenGL = 1
    };
    class Renderer
    {
        public:
        inline static RendererAPI GetRendererAPI()
        {
            return RendererAPI::OpenGL;
        }
        private:
        static RendererAPI s_RendererAPI;
    };
} // Hyperion

#endif //HYPERIONENGINE_RENDERER_H