//
// Created by 13191 on 2026/3/31.
//

#ifndef HYPERIONENGINE_OPENGLSHADER_H
#define HYPERIONENGINE_OPENGLSHADER_H

#include <string>

#include "glm/fwd.hpp"
#include "Hyperion/Renderer/Shader.h"

namespace Hyperion
{
    class OpenGLShader : public Shader
    {
    public:
        OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
        virtual ~OpenGLShader();

        virtual void Bind() const override;
        virtual void Unbind() const override;

        virtual void UploadUniformInt(const std::string& name, int value);

        virtual void UploadUniformFloat(const std::string& name, float value);
        virtual void UploadUniformFloat2(const std::string& name, const glm::vec2& values);
        virtual void UploadUniformFloat3(const std::string& name, const glm::vec3& values);
        virtual void UploadUniformFloat4(const std::string& name, const glm::vec4& values);

        virtual void UploadUniformMat3(const std::string& name, const glm::mat3& matrix);
        virtual void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);

    private:
        uint32_t m_RendererID;
    };
} // Hyperion

#endif //HYPERIONENGINE_OPENGLSHADER_H
