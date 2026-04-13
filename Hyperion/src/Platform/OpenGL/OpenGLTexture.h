//
// Created by 13191 on 2026/4/12.
//

#ifndef HYPERIONENGINE_OPENGLTEXTURE_H
#define HYPERIONENGINE_OPENGLTEXTURE_H

#include "Hyperion/Renderer/Texture.h"

namespace Hyperion
{
    class OpenGLTexture2D : public Texture2D
    {
        public:
        OpenGLTexture2D(const std::string& path);
        virtual ~OpenGLTexture2D();

        virtual uint32_t GetWidth() const override {
            return m_Width;
        };
        virtual uint32_t GetHeight() const override
        {
            return m_Height;
        };

        virtual void Bind(uint32_t slot = 0) const override;

        private:
        std::string m_FilePath;
        uint32_t m_Width = 0;
        uint32_t m_Height = 0;
        uint32_t m_RendererID = 0;

    };
} // Hyperion

#endif //HYPERIONENGINE_OPENGLTEXTURE_H
