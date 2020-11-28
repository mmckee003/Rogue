#include "roguepch.h"
#include "Application.h"

#include "Rogue/Log.h"

#include <GLFW/glfw3.h>

namespace Rogue
{
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		ROGUE_CORE_TRACE("{0}", event);
	}

	bool Application::OnWindowClose(WindowCloseEvent e)
	{
		m_Running = false;
		return true;
	}
}
