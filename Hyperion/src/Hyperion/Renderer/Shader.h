//
// Created by 13191 on 2026/3/14.
//

#ifndef HYPERIONENGINE_SHADER_H
#define HYPERIONENGINE_SHADER_H

#include <string>

namespace Hyperion
{
    class Shader
    {
        public:
        Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
        ~Shader();

        void Bind() const;
        void Unbind() const;

        private:
        uint32_t m_RendererID;
    };
} // Hyperion

#endif //HYPERIONENGINE_SHADER_H