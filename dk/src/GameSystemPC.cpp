#include "GameSystemPC.h"
#ifdef PC

GameSystemPC::GameSystemPC(u32 fb_width, u32 fb_height)
{
	this->fb_height = fb_height;
	this->fb_width = fb_width;

	//Init SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		error = 1;

	//Create window & Renderer
	window = SDL_CreateWindow("DK", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, fb_width, fb_height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == NULL || renderer == NULL)
		error = 1;

	//Create framebuffer emulation
	fb = new u32[fb_width*fb_height];
	for (u32 i = 0; i < fb_width * fb_height; ++i)
	{
		//Starts off red, for no reason.
		fb[i] = 0xFF0000FF;
	}

	graphics = Graphics((this->fb_height), (this->fb_width), fb);

}

 void GameSystemPC::PreFrame()
{
	 graphics.Test();
}


 void GameSystemPC::HandleControls()
 {
	 while (SDL_PollEvent(&e) != 0)
	 {
		 if (e.type == SDL_QUIT)
		 {
			 quit = true;
		 }
	 }
 }






//Emulate drawing to framebuffer on switch
void GameSystemPC::DrawFrameBuffer()
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

void GameSystemPC::Render()
{
	SDL_RenderClear(renderer);
	DrawFrameBuffer();
	SDL_RenderPresent(renderer);
	SDL_Delay(100);
}


GameSystemPC::~GameSystemPC()
{
	delete[] fb;
	SDL_DestroyWindow(window);
	SDL_Quit();
}
#endif