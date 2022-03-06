#include "Log.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace GeekPizza {

	std::shared_ptr<spdlog::logger> Log::m_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::m_ClientLogger;

	void Log::Init()
	{
		spdlog::color_mode kek = spdlog::color_mode::never;
		spdlog::set_pattern("%^[%D, %X] %n: %v%$");
		m_CoreLogger = spdlog::stdout_color_mt("GEEKPIZZA");
		m_CoreLogger->set_level(spdlog::level::trace);

		m_ClientLogger = spdlog::stdout_color_mt("APPLICATION");
		m_ClientLogger->set_level(spdlog::level::trace);
	}

	Log::Log()
	{
		if(!this)
			Init();
	}
}
