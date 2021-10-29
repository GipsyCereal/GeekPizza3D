#pragma once
#include "Core.h"


namespace GeekPizza
{
	class GEEKPIZZA_API App
	{
	public:
		App() = default;
		virtual ~App() = default;
		App(const App& other) = delete;
		App(App&& other) = delete;
		App& operator=(const App& other) = delete;
		App& operator=(App&& other) = delete;
		
		void Run();
	};
	App* CreateApp();
}

