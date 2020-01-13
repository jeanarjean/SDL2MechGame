#ifndef TEXTURE_UTILS_H
#define TEXTURE_UTILS_H

#include "string"
#include <SDL_image.h>
#include <SDL_video.h>
#include "../Component/Renderable.h"

void Free(Renderable& renderable);
bool LoadFromFile(std::string path, SDL_Renderer* gRenderer, Renderable& renderable);
#endif
