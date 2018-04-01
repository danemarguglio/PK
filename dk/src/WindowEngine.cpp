#include "WindowEngine.h"


WindowEngine::WindowEngine(u32 SCREEN_WIDTH, u32 SCREEN_HEIGHT)
{
	this->fb_width = SCREEN_WIDTH;
	this->fb_height = SCREEN_HEIGHT;

#ifdef PC
	//Init SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		error = 1;

	//Create window & Renderer
	window = SDL_CreateWindow("DK", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == NULL || renderer == NULL)
		error = 1;

	//Create framebuffer emulation
	fb = new u32[SCREEN_WIDTH*SCREEN_HEIGHT];
	for (u32 i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; ++i)
	{
		fb[i] = 0xFF0000FF;
	}

#else
	//Switch Init
	gfxInitDefault();
	consoleInit(NULL);
#endif

	

}

void WindowEngine::runLoop()
{
	srand(time(NULL));

#ifdef PC
	while (!quit)
#else
	while (appletMainLoop() && !quit)
#endif
	{
		//Controls & Loop Init
#ifdef PC
		while (SDL_PollEvent(&e) != 0)
		{
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
		}
#else
		//Get Inputs & Frame Buffer
		hidScanInput();
		u32 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
		fb = (u32*)gfxGetFramebuffer((u32*)&fb_width, (u32*)&fb_height);
#endif






		for (u32 i = 0; i < fb_width+10; ++i)
		{
			for (u32 j = 0; j < fb_height; ++j)
			{
#ifndef PC
				fb[gfxGetFramebufferDisplayOffset(i, j)] = 0xFF0000FF;

#endif
			}
		}









		//Rendering
#ifdef PC
		SDL_RenderClear(renderer);
		drawFrameBuffer();
		SDL_RenderPresent(renderer);
		SDL_Delay(100);
#else
		gfxFlushBuffers();
		gfxSwapBuffers();
		gfxWaitForVsync();
#endif
	}

}

#ifdef PC
void WindowEngine::drawFrameBuffer()
{
	for (u32 i = 0; i < fb_width; ++i)
	{
		for (u32 j = 0; j < fb_height; ++j)
		{
			u32 pxl = fb[j*fb_width + i];
			u8 r = (pxl & 0xFF000000) >> 24;
			u8 g = (pxl & 0x00FF0000) >> 16;
			u8 b = (pxl & 0x0000FF00) >> 8;
			u8 a = (pxl & 0x000000FF);
 
			SDL_SetRenderDrawColor(renderer, r, g, b, a);
			SDL_RenderDrawPoint(renderer, i, j);
		}
	}

}
#endif


WindowEngine::~WindowEngine()
{
#ifdef PC
	delete[] fb;
	SDL_DestroyWindow(window);
	SDL_Quit();
#else
	gfxExit();
#endif
}
