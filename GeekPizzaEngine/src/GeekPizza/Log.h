#pragma once
#include "Core.h"

#include "spdlog/spdlog.h"
namespace GeekPizza
{
	class GEEKPIZZA_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return m_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return m_ClientLogger; };
	private:
		Log();
		static std::shared_ptr<spdlog::logger> m_CoreLogger;
		static std::shared_ptr<spdlog::logger> m_ClientLogger;
	};
}

//<<<<<<< HEAD
////U can disable macros in distribution version (if distbuild ...)
//=======
////U can disable macros in dist version (if distbuild ...)
//>>>>>>> 1d27db077bd39b7ef898b04f6c6d5cb17e5274b8
//Core logging macro
#define GP_CORE_FATAL(...)    ::GeekPizza::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define GP_CORE_ERROR(...)    ::GeekPizza::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GP_CORE_WARN(...)     ::GeekPizza::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GP_CORE_INFO(...)     ::GeekPizza::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GP_CORE_TRACE(...)    ::GeekPizza::Log::GetCoreLogger()->trace(__VA_ARGS__)

//Client logging macro
#define GP_CLIENT_FATAL(...)  ::GeekPizza::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define GP_CLIENT_ERROR(...)  ::GeekPizza::Log::GetClientLogger()->error(__VA_ARGS__)
#define GP_CLIENT_WARN(...)   ::GeekPizza::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GP_CLIENT_INFO(...)   ::GeekPizza::Log::GetClientLogger()->info(__VA_ARGS__)
#define GP_CLIENT_TRACE(...)  ::GeekPizza::Log::GetClientLogger()->trace(__VA_ARGS__)