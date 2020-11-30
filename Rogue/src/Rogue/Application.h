#pragma once

#include "Core.h"

#include "Rogue/Window.h"
#include "Rogue/LayerStack.h"
#include "Rogue/Events/Event.h"
#include "Rogue/Events/ApplicationEvent.h"

namespace Rogue
{
	class ROGUE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& event);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

	private:
		bool OnWindowClose(WindowCloseEvent e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in client
	Application* CreateApplication();
}

