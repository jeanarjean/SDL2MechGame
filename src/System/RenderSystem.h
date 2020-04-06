#pragma once
#include <SDL.h>
#include <entt/entt.hpp>
#include <Box2D\Dynamics\b2Body.h>

namespace Renderer {
	void Render(entt::registry& registry, SDL_Renderer* gRenderer);
	void RenderBackground(entt::registry& registry, SDL_Renderer* gRenderer);
	void RenderPlatforms(entt::registry& registry, SDL_Renderer* gRenderer);
	void RenderBoundingBox(entt::registry& registry, SDL_Renderer* gRenderer);
	void RenderPlayer(entt::registry& registry, SDL_Renderer* gRenderer);
	void DebugRender(entt::registry& registry, SDL_Renderer* gRenderer);
}
