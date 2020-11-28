#include "Application.h"

#include "Rogue/Events/ApplicationEvent.h"
#include "Rogue/Log.h"

namespace Rogue
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			ROGUE_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			ROGUE_TRACE(e);
		}

		while (true);
	}
}
