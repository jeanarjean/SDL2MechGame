#pragma once
#include <SDL.h>
#include <entt/entt.hpp>
#include <Box2D/Box2D.h>

namespace HealthSystem
{
	void ProcessHealth(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer);
}

