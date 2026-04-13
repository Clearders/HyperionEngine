//
// Created by 13191 on 2026/3/16.
//

#ifndef HYPERIONENGINE_VERTEXARRAY_H
#define HYPERIONENGINE_VERTEXARRAY_H

#include <memory>
#include "Buffer.h"
#include "Hyperion/Core/Core.h"

namespace Hyperion
{
    class HYPERION_API VertexArray
    {
    public:
        virtual ~VertexArray() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual void AddVertexBuffer(const Hyperion::Ref<VertexBuffer>& vertexBuffer) = 0;
        virtual void SetIndexBuffer(const Hyperion::Ref<IndexBuffer>& indexBuffer) = 0;

        virtual std::vector<Hyperion::Ref<VertexBuffer>>& GetVertexBuffers() = 0;
        virtual Hyperion::Ref<IndexBuffer>& GetIndexBuffer() = 0;

        static VertexArray* Create();
    };
} // Hyperion

#endif //HYPERIONENGINE_VERTEXARRAY_H