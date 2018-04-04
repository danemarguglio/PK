#include "GameSystemSwitch.h"
#ifndef PC


GameSystemSwitch::GameSystemSwitch(u32 fb_height, u32 fb_width)
{
	//These are overwritten every frame, but init them anyway
	this->fb_height = fb_height;
	this->fb_width = fb_width;

	//Initialize graphics
	gfxInitDefault();
	fb = (u32*)gfxGetFramebuffer((u32*)&(this->fb_width), (u32*)&(this->fb_height));
	graphics = Graphics(fb_height, fb_width, fb);
}

void GameSystemSwitch::PreFrame()
{
	hidScanInput();
	fb = (u32*)gfxGetFramebuffer((u32*)&fb_width, (u32*)&fb_height);
	graphics.Test();
}

void GameSystemSwitch::Render()
{
	gfxFlushBuffers();
	gfxSwapBuffers();
	gfxWaitForVsync();
}

void GameSystemSwitch::HandleControls()
{
	u32 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
	if (kDown & KEY_PLUS)
	{
		quit = true;
	}
}

GameSystemSwitch::~GameSystemSwitch()
{
	gfxExit();
}

#endif