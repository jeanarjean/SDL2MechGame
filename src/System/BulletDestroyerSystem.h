#ifndef BULLET_DESTROYED_SYSTEM_H
#define BULLET_DESTROYED_SYSTEM_H
#include <SDL.h>
#include <entt/entt.hpp>
#include <Box2D/Box2D.h>

namespace BulletDestroyerSystem
{
	void ProcessBullets(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer);
}

#endif
