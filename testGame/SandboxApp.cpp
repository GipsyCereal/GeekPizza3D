#include <GeekPizza.h>

class Sandbox : public GeekPizza::App
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	} 


};

GeekPizza::App* GeekPizza::CreateApp()
{
	return new Sandbox();
}