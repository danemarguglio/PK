#include "GameSystemSwitch.h"
#ifndef PC


GameSystemSwitch::GameSystemSwitch(u32 fb_height, u32 fb_width)
{
	this->fb_height = fb_height;
	this->fb_width = fb_width;
	gfxInitDefault();
	consoleInit(NULL);
}

void GameSystemSwitch::PreFrame()
{
	hidScanInput();
	//u32 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
	fb = (u32*)gfxGetFramebuffer((u32*)&fb_width, (u32*)&fb_height);
}

void GameSystemSwitch::Render()
{
	gfxFlushBuffers();
	gfxSwapBuffers();
	gfxWaitForVsync();
}

GameSystemSwitch::~GameSystemSwitch()
{
	gfxExit();
}

#endif