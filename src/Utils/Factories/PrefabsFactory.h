#pragma once

#include <SDL.h>
#include <Box2D/Box2D.h>
#include <entt/entt.hpp>

namespace PrefabsFactory
{
	entt::entity CreatePlayerPrefab(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer);
	entt::entity CreateStaticRectangleObstacle(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 position, b2Vec2 size);
	entt::entity CreateBoundingRectangle(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 position, b2Vec2 size);
	entt::entity CreateBasicEnemy(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 position, float radius);
	entt::entity SpawnBullet(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 position);
}

