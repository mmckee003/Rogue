#include <Rogue.h>

class ExampleLayer : public Rogue::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override
	{
		ROGUE_INFO("ExampleLayer::OnUpdate");
	}

	void OnEvent(Rogue::Event& e) override
	{
		ROGUE_TRACE("{0}", e);
	}
};

class Sandbox : public Rogue::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Rogue::Application* Rogue::CreateApplication()
{
	return new Sandbox;
}