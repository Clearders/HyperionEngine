//
// Created by 13191 on 2026/1/29.
//

#ifndef HYPERIONENGINE_WINDOWSINPUT_H
#define HYPERIONENGINE_WINDOWSINPUT_H
#include "Hyperion/Core/Input.h"


namespace Hyperion
{
    class WindowsInput : public Input
    {
    protected:
        virtual bool IsKeyPressedImpl(int keycode)override;
        virtual bool IsMouseButtonPressedImpl(int button) override;
        virtual std::pair<float, float> GetMousePositionImpl() override;

        virtual float GetMouseXImpl() override;
        virtual float GetMouseYImpl() override;

    };
}


#endif //HYPERIONENGINE_WINDOWSINPUT_H