#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H
#include <SDL.h>
#include <entt/entt.hpp>

namespace Renderer {
	void Render(entt::registry& registry, SDL_Renderer* gRenderer);
	void RenderBackground(entt::registry& registry, SDL_Renderer* gRenderer);
	void RenderDynamicEntities(entt::registry& registry, SDL_Renderer* gRenderer);
	void RenderBoundingBox(entt::registry& registry, SDL_Renderer* gRenderer);
}
#endif
