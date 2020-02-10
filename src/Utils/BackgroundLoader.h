#ifndef BACKGROUND_LOADER_H
#define BACKGROUND_LOADER_H

#include <SDL.h>
#include <entt/entt.hpp>

namespace BackgroundLoader {
	entt::entity LoadBackground(entt::registry& registry, SDL_Renderer* gRenderer);
}

#endif
