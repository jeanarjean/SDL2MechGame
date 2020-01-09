#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H
#include <SDL.h>
#include <entt/entt.hpp>
#include "../Component/Position.h"
#include "../Component/Velocity.h"
void Render(entt::registry& registry,SDL_Renderer* gRenderer);
#endif
