#include "roguepch.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Rogue
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	Rogue::MessageLog* Rogue::Log::my_own_log;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("ROGUE");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);

		my_own_log = new MessageLog();
	}
}