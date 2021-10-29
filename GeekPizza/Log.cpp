#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"
namespace GeekPizza {

	std::shared_ptr<spdlog::logger> Log::m_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::m_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%D, %X] %n: %v%$");
		m_CoreLogger = spdlog::stdout_color_mt("GeekPizza");
		m_CoreLogger->set_level(spdlog::level::trace);

		m_ClientLogger = spdlog::stdout_color_mt("Application");
		m_ClientLogger->set_level(spdlog::level::trace);
	}
	std::shared_ptr<spdlog::logger>& Log::GetCoreLogger()
	{
		return m_CoreLogger;
	}
	std::shared_ptr<spdlog::logger>& Log::GetClientLogger()
	{
		return m_ClientLogger;
	}
}
