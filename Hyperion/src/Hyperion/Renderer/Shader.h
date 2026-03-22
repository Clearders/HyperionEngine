//
// Created by 13191 on 2026/3/14.
//

#ifndef HYPERIONENGINE_SHADER_H
#define HYPERIONENGINE_SHADER_H

#include <string>

#include "glm/fwd.hpp"
#include "Hyperion/Core/Core.h"

namespace Hyperion
{
    class HYPERION_API Shader
    {
    public:
        Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
        ~Shader();

        void Bind() const;
        void Unbind() const;

        void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);

    private:
        uint32_t m_RendererID;
    };
} // Hyperion

#endif //HYPERIONENGINE_SHADER_H
