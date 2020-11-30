#pragma once

#ifdef ROGUE_PLATFORM_WINDOWS

extern Rogue::Application* Rogue::CreateApplication();

int main(int argc, char** argv)
{
	Rogue::Log::Init();
	Rogue::Log::my_own_log->Log("MessageLog initialized!");
	ROGUE_CORE_WARN("Initialized Log!");
	int a = 5;
	ROGUE_INFO("Hello var={0}", a);

	auto app = Rogue::CreateApplication();
	app->Run();
	delete app;
}
#endif
