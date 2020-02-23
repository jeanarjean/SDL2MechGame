#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H
#include <entt/entt.hpp>
#include <SDL.h>

namespace InputHandler {
	void HandleInputs(entt::registry& registry, SDL_Event event);
}

#endif
