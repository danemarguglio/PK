#pragma once
#ifdef PC
#include <SDL.h>
#include <cstdint>
typedef uint32_t u32;
typedef uint8_t u8;
#else
#include <switch.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>





class WindowEngine
{
#ifdef PC
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Event e;
#endif

	int error = 0;
	bool quit = false;
	u32 fb_width;
	u32 fb_height;

	u32* fb;
	

public:
	WindowEngine(u32 SCREEN_WIDTH, u32 SCREEN_HEIGHT);
	~WindowEngine();

#ifdef PC
	void drawFrameBuffer();
#endif

	void runLoop();
};

