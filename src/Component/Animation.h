#pragma once
#include <SDL_video.h>
#include <SDL_image.h>
#include "./Frame.h"
#include "./Renderable.h"
#include <vector>
struct Animation {
	std::vector<Frame> frames;
	Renderable mTexture;
	Uint16 currentFrame = 0;
};
