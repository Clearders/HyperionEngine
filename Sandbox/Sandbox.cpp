#include "../Hyperion/src/Hyperion.h"

namespace Hyperion
{
    class Application;
}

class Sandbox : public Hyperion::Application
{
public:
    Sandbox(){
    }
    ~Sandbox(){
    }
};

Hyperion::Application* CreateApplication()
{
    return new Sandbox();
}