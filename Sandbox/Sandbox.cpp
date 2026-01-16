#include "../Hyperion/src/Hyperion.h"

class ExampleLayer : public Hyperion::Layer
{
public:
    ExampleLayer() : Layer("Example") {}

    void OnUpdate() override
    {
        HYPERION_INFO("ExampleLayer::Update");
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
        PushOverlay(new Hyperion::ImGuiLayer);
    }
    ~Sandbox(){
    }
};

Hyperion::Application* CreateApplication()
{
    return new Sandbox();
}