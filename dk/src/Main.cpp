//#include "WindowEngine.h"
#ifdef PC
#include "GameSystemPC.h"
#else
#include "GameSystemSwitch.h"
#endif

#include <iostream>




int main(int argc, char * argv[])
{
#ifdef PC
	GameSystemPC sys = GameSystemPC(1280, 720);
#else
	GameSystemSwitch sys = GameSystemSwitch(1280, 720);
#endif

	while (!sys.GetQuit())
	{
		sys.PreFrame();


		sys.Render();
	}

	
	return 0;
}