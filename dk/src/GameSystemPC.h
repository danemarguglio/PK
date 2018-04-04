#pragma once
#include "GameSystem.h"
#ifdef PC

class GameSystemPC :
	public GameSystem
{
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Event e;


	bool error;
public:
	GameSystemPC(u32 fb_width, u32 fb_height);
	~GameSystemPC();

	virtual void PreFrame();
	virtual void Render();
	virtual void HandleControls();


	void DrawFrameBuffer();
};

#endif