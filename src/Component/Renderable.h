#ifndef RENDEREABLE_H
#define RENDEREABLE_H
#include <SDL_video.h>
#include <SDL_image.h>
struct Renderable{
	SDL_Texture* mTexture;
	int mWidth;
	int mHeight;
};
#endif
