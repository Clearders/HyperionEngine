//
// Created by 13191 on 2026/4/12.
//

#ifndef HYPERIONENGINE_TEXTURE_H
#define HYPERIONENGINE_TEXTURE_H
#include <string>

#include "Hyperion/Core/Core.h"

namespace Hyperion
{
    class HYPERION_API Texture
    {
        public:
        virtual ~Texture() = default;

        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;

        virtual void Bind(uint32_t slot = 0) const = 0;
    };

    class HYPERION_API Texture2D : public Texture
    {
        public:
        static Ref<Texture2D> Create(const std::string& path);
    };
} // Hyperion

#endif //HYPERIONENGINE_TEXTURE_H
