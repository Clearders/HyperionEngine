//
// Created by 13191 on 2026/3/15.
//

#ifndef HYPERIONENGINE_OPENGLBUFFER_H
#define HYPERIONENGINE_OPENGLBUFFER_H

#include "Hyperion\Renderer\Buffer.h"

namespace Hyperion
{
    class OpenGLVertexBuffer : public VertexBuffer
    {
    public:
        OpenGLVertexBuffer(float* vertices, uint32_t size);
        virtual ~OpenGLVertexBuffer();

        virtual void Bind() const;
        virtual void Unbind() const;

    private:
        uint32_t m_RendererID;
    };

    class OpenGLIndexBuffer : public IndexBuffer
    {
    public:
        OpenGLIndexBuffer(uint32_t* vertices, uint32_t count);
        virtual ~OpenGLIndexBuffer();


        virtual void Bind() const;
        virtual void Unbind() const;
        virtual uint32_t GetCount() const { return m_Count ;};
    private:
        uint32_t m_RendererID;
        uint32_t m_Count;
    };
}


#endif //HYPERIONENGINE_OPENGLBUFFER_H