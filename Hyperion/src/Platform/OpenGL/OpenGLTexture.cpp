//
// Created by 13191 on 2026/4/12.
//

#include "Hyperion/hyperionpch.h"
#include "OpenGLTexture.h"
#include "OpenGLError.h"

#include "stb_image.h"

#include <glad/glad.h>

namespace Hyperion
{
    OpenGLTexture2D::OpenGLTexture2D(const std::string& path)
        : m_FilePath(path)
    {
        stbi_set_flip_vertically_on_load(1);

        int width = 0, height = 0, channels = 0;
        stbi_uc* data = stbi_load(path.c_str(), &width, &height, &channels, 0);
        HYPERION_CORE_ASSERT(data, "Failed to load texture image!");
        if (!data)
        {
            return;
        }

        m_Width = static_cast<uint32_t>(width);
        m_Height = static_cast<uint32_t>(height);

        GLenum internalFormat = 0;
        GLenum dataFormat = 0;

        if (channels == 4)
        {
            internalFormat = GL_RGBA8;
            dataFormat = GL_RGBA;
        }
        else if (channels == 3)
        {
            internalFormat = GL_RGB8;
            dataFormat = GL_RGB;
        }
        else
        {
            stbi_image_free(data);
            HYPERION_CORE_ASSERT(false, "Unsupported texture channel count!");
            return;
        }

        HYPERION_GL_CALL(glCreateTextures(GL_TEXTURE_2D, 1, &m_RendererID));
        HYPERION_GL_CALL(glTextureStorage2D(m_RendererID, 1, internalFormat, static_cast<GLsizei>(m_Width), static_cast<GLsizei>(m_Height)));
        HYPERION_GL_CALL(glTextureParameteri(m_RendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
        HYPERION_GL_CALL(glTextureParameteri(m_RendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
        HYPERION_GL_CALL(glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_S, GL_REPEAT));
        HYPERION_GL_CALL(glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_T, GL_REPEAT));

        GLint previousUnpackAlignment = 4;
        HYPERION_GL_CALL(glGetIntegerv(GL_UNPACK_ALIGNMENT, &previousUnpackAlignment));
        HYPERION_GL_CALL(glPixelStorei(GL_UNPACK_ALIGNMENT, 1));

        HYPERION_GL_CALL(glTextureSubImage2D(m_RendererID, 0, 0, 0, static_cast<GLsizei>(m_Width), static_cast<GLsizei>(m_Height), dataFormat, GL_UNSIGNED_BYTE, data));

        HYPERION_GL_CALL(glPixelStorei(GL_UNPACK_ALIGNMENT, previousUnpackAlignment));
        stbi_image_free(data);
    }

    OpenGLTexture2D::~OpenGLTexture2D()
    {
        if (m_RendererID != 0)
        {
            HYPERION_GL_CALL(glDeleteTextures(1, &m_RendererID));
        }
    }

    void OpenGLTexture2D::Bind(uint32_t slot) const
    {
        HYPERION_GL_CALL(glBindTextureUnit(slot, m_RendererID));
    }
} // Hyperion