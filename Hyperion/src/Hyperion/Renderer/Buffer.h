//
// Created by 13191 on 2026/3/15.
//

#ifndef HYPERIONENGINE_BUFFER_H
#define HYPERIONENGINE_BUFFER_H

namespace Hyperion
{
    class VertexBuffer
    {
    public:
        virtual ~VertexBuffer() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        static VertexBuffer* Create(float* vertices, uint32_t size);
    };

    class IndexBuffer
    {
    public:
        virtual ~IndexBuffer() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual uint32_t GetCount() const = 0;

        static IndexBuffer* Create(uint32_t* indices, uint32_t count);
    };

}

#endif //HYPERIONENGINE_BUFFER_H