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

        virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) = 0;
        virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) = 0;

        virtual std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() = 0;
        virtual std::shared_ptr<IndexBuffer>& GetIndexBuffer() = 0;

        static VertexArray* Create();
    };
} // Hyperion

#endif //HYPERIONENGINE_VERTEXARRAY_H