#pragma once
#include "syscontrol.h"
class GameSystem
{
protected:
	u32* fb;
	u32 fb_width;
	u32 fb_height;
	bool quit = false;
public:
	GameSystem();
	~GameSystem();
	virtual void PreFrame() = 0;
	virtual void Render() = 0;
	bool GetQuit() { return quit; }
};

