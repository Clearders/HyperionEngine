//
// Created by 13191 on 2026/3/10.
//

#ifndef HYPERIONENGINE_GRAPHICSCONTEXT_H
#define HYPERIONENGINE_GRAPHICSCONTEXT_H

namespace Hyperion
{
    class GraphicsContext
    {
    public:
        virtual ~GraphicsContext() = default;

        virtual void Init() = 0;
        virtual void SwapBuffers() = 0;
    };
}


#endif //HYPERIONENGINE_GRAPHICSCONTEXT_H