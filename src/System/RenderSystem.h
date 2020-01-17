#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H
#include <SDL.h>
#include <entt/entt.hpp>
#include "../Utils//CoordTranslator.h"
void Render(entt::registry& registry,SDL_Renderer* gRenderer);
#endif
