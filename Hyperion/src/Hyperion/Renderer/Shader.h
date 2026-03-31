//
// Created by 13191 on 2026/3/14.
//

#ifndef HYPERIONENGINE_SHADER_H
#define HYPERIONENGINE_SHADER_H

#include <string>

#include "Hyperion/Core/Core.h"

namespace Hyperion
{
    class HYPERION_API Shader
    {
    public:
        virtual ~Shader() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        static Shader* Create(const std::string& vertexSrc, const std::string& fragmentSrc);
    };
} // Hyperion

#endif //HYPERIONENGINE_SHADER_H
