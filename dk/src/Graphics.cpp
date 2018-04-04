#include "Graphics.h"


Graphics::Graphics(u32 fb_width, u32 fb_height, u32*& fb)
	: fb_width(fb_width), fb_height(fb_height), fb(fb)
{

}

void Graphics::Test()
{
	for (u32 i = 0; i < fb_width; ++i)
	{
		for (u32 j = 0; j < fb_height; ++j)
		{
			fb[j*fb_width + i] = 0xFF00FFFF;
		}
	}
}


Graphics::~Graphics()
{
}
