#pragma once

#include <SDL.h>
#include <Box2D/Box2D.h>
#include <entt/entt.hpp>
#include "../../Component/Renderable.h"

namespace PrefabsFactory
{
	class PrefabsFactory
	{
	public:
		PrefabsFactory(SDL_Renderer* gRenderer);
		~PrefabsFactory();
		entt::entity CreatePlayerPrefab(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer);
		entt::entity CreateStaticRectangleObstacle(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 position, b2Vec2 size);
		entt::entity CreateBoundingRectangle(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 position, b2Vec2 size);
		entt::entity PrefabsFactory::CreateBasicEnemy(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 position, b2Vec2 size);
		entt::entity SpawnBullet(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 position);
		Renderable* _tileSet;
	private:
		Renderable* _renderableBlue;
		Renderable* _renderableMech;
		Renderable* _renderableDot;
		Renderable* _renderableControl;
	};
}

