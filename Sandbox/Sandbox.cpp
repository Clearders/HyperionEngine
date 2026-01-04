#include "../Hyperion/src/Hyperion.h"

class ExampleLayer : public Hyperion::Layer
{
public:
    ExampleLayer() : Layer("Example") {}
    void OnUpdate() override
    {
        HYPERION_TRACE("ExampleLayer::Update");
    }
    void OnEvent(Hyperion::Event& event) override
    {
        HYPERION_INFO("{}", event.ToString());
    }
};

class Sandbox : public Hyperion::Application
{
public:
    Sandbox(){
        PushLayer(new ExampleLayer);;
    }
    ~Sandbox(){
    }
};

Hyperion::Application* CreateApplication()
{
    return new Sandbox();
}