#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Rogue/Events/ApplicationEvent.h"
#include "Window.h"

namespace Rogue
{
	class ROGUE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& event);

	private:
		bool OnWindowClose(WindowCloseEvent e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in client
	Application* CreateApplication();
}

