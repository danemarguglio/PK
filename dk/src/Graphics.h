#pragma once
#include "syscontrol.h"

class Graphics
{
	u32 fb_width;
	u32 fb_height;
	u32* fb;
	
public:
	Graphics(u32 fb_width, u32 fb_height, u32*& fb);
	~Graphics();
	void Test();
};

