#pragma once
#ifdef GP_PLATFORM_WINDOWS
	#ifdef GP_BUILD_DLL
		#define GEEKPIZZA_API __declspec(dllexport)
	#else
		#define GEEKPIZZA_API __declspec(dllimport)
	#endif
#else
	#error Run on Windows x64
#endif
