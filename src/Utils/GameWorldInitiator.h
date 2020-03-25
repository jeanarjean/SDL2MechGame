#ifndef GAME_WORLD_INITIATOR_H
#define GAME_WORLD_INITIATOR_H

#include <SDL.h>
#include <Box2D/Box2D.h>
#include <entt/entt.hpp>

namespace GameWorldInitiator {
	bool InitiateGameWorld(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 gameWorldSize);
	void CreateGameWorldBoundaries(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 gameWorldSize);
}

#endif
