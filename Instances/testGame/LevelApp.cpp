#include <string>
#include <GeekPizza.h>

class LevelApp final : public GeekPizza::App
{
public:
	LevelApp() 
	{

	}
	~LevelApp() 
	{
	}
};
GeekPizza::App* GeekPizza::CreateApp()
{
	return new LevelApp();
}