#pragma once
#include "syscontrol.h"
#include "Graphics.h"
#include "Controls.h"
class GameSystem
{
protected:
	//frame buffer
	u32* fb;
	u32 fb_width;
	u32 fb_height;

	Graphics graphics;


	bool quit = false;
public:
	GameSystem();
	~GameSystem();
	virtual void PreFrame() = 0;
	virtual void Render() = 0;
	virtual void HandleControls() = 0;
	bool GetQuit() { return quit; }
};

