//
// Created by 13191 on 2026/3/16.
//

#ifndef HYPERIONENGINE_OPENGLVERTEXARRAY_H
#define HYPERIONENGINE_OPENGLVERTEXARRAY_H
#include "Hyperion/Renderer/VertexArray.h"

namespace Hyperion
{
    class OpenGLVertexArray : public VertexArray
    {
    public:
        OpenGLVertexArray();
        virtual ~OpenGLVertexArray();

        virtual void Bind() const override;
        virtual void Unbind() const override;

        virtual void AddVertexBuffer(const Hyperion::Ref<VertexBuffer>& vertexBuffer) override;
        virtual void SetIndexBuffer(const Hyperion::Ref<IndexBuffer>& indexBuffer) override;

        virtual std::vector<Hyperion::Ref<VertexBuffer>>& GetVertexBuffers() { return m_VertexBuffers; };
        virtual Hyperion::Ref<IndexBuffer>& GetIndexBuffer() { return m_IndexBuffers; };

    private:
        uint32_t m_RendererID;
        std::vector<Hyperion::Ref<VertexBuffer>> m_VertexBuffers;
        Hyperion::Ref<IndexBuffer> m_IndexBuffers;
    };
} // Hyperion

#endif //HYPERIONENGINE_OPENGLVERTEXARRAY_H