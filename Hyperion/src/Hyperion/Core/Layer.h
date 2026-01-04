//
// Created by 13191 on 2026/1/3.
//

#pragma once

#include "Hyperion/Core/Core.h"
#include "Hyperion/Events/Event.h"

namespace Hyperion
{
    class HYPERION_API Layer
    {
    public:
        Layer(const std::string& debugname = "Layer");
        virtual ~Layer();

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event& event) {}

        inline const std::string& GetName() const { return m_DebugName; }
    protected:
        std::string m_DebugName;
    };
} // Hyperion
//HYPERIONENGINE_LAYER_H