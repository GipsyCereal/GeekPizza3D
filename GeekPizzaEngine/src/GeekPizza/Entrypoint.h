#pragma once
#ifdef GP_PLATFORM_WINDOWS
extern GeekPizza::App* GeekPizza::CreateApp(); //check for a function in GeekpizzaEngine "CreateApp" (which returns pointer to created App)
int main(int argc, char** argv)
{
	GeekPizza::Log::Init();
	GP_CORE_WARN("Wow Im a macro!");
	int a{ 10 };
	int b{ 8 };

	GP_CLIENT_TRACE("Hi there #{0}, {1} tests done", a,b);
	auto app = GeekPizza::CreateApp();
	app->Run();
	delete app;
}


#endif