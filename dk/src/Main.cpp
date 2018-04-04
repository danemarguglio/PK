//#include "WindowEngine.h"
#ifdef PC
#include "GameSystemPC.h"
#else
#include "GameSystemSwitch.h"
#endif

#include <iostream>


u32 x_res = 1280;
u32 y_res = 720;

int main(int argc, char * argv[])
{
#ifdef PC
	GameSystemPC sys = GameSystemPC(x_res, y_res);
#else
	GameSystemSwitch sys = GameSystemSwitch(x_res, y_res);
#endif

	while (!sys.GetQuit() 
#ifndef PC 
		&& appletMainLoop() 
#endif
		)
	{
		sys.PreFrame();
		sys.HandleControls();
		sys.Render();
	}

	
	return 0;
}