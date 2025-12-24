#include "../Hyperion/src/Hyperion.h"

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