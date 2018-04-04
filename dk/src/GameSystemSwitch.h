#pragma once
#include "GameSystem.h"



class GameSystemSwitch :
	public GameSystem
{
public:
	GameSystemSwitch(u32 fb_width, u32 fb_height);
	~GameSystemSwitch();

	virtual void PreFrame();
	virtual void Render();
	virtual void HandleControls();
};
