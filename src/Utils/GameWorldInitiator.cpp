#include "GameWorldInitiator.h"
#include "CoordTranslator.h"
#include "TextureUtils.h"
#include "../Component/Renderable.h"
#include "../Component/Floor.h"

bool InitiateGameWorld(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 gameWorldSize)
{

	CreateGameWorldBoundaries(registry, world, gRenderer, b2Vec2{ 1600,900 });

	// Init Player
	CreatePlayerPrefab(registry, world, gRenderer);
	CreateStaticRectangleObstacle(registry, world, gRenderer, coordPixelsToWorld(b2Vec2(250, 250)), coordPixelsToWorld(b2Vec2(100, 50)));
	float32 initialX = 250.f;
	//for (initialX; initialX < 600.f; initialX++)
	//{
		CreateDynamicBallObject(registry, world, gRenderer, coordPixelsToWorld(b2Vec2(initialX, 250)), 1.f);
		CreateDynamicBallObject(registry, world, gRenderer, coordPixelsToWorld(b2Vec2(initialX, 250)), 1.f);
		CreateDynamicBallObject(registry, world, gRenderer, coordPixelsToWorld(b2Vec2(initialX, 250)), 1.f);
	//}
	//TODO return 0 if error
	return true;
}

void CreateGameWorldBoundaries(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 gameWorldSize)
{
	CreateStaticRectangleObstacle(registry, world, gRenderer, coordPixelsToWorld(b2Vec2(0, gameWorldSize.y - 20)), coordPixelsToWorld(b2Vec2(gameWorldSize.x, 50)));
	CreateStaticRectangleObstacle(registry, world, gRenderer, coordPixelsToWorld(b2Vec2(0, 0)), coordPixelsToWorld(b2Vec2(20, gameWorldSize.y)));
	CreateStaticRectangleObstacle(registry, world, gRenderer, coordPixelsToWorld(b2Vec2(gameWorldSize.x - 20, 0)), coordPixelsToWorld(b2Vec2(20, gameWorldSize.y)));
	CreateStaticRectangleObstacle(registry, world, gRenderer, coordPixelsToWorld(b2Vec2(0, 0)), coordPixelsToWorld(b2Vec2(gameWorldSize.x, 20)));
}
