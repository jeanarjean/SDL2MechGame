#include "GameWorldInitiator.h"
#include "CoordTranslator.h"
#include "TextureUtils.h"
#include "../Component/Renderable.h"
#include "../Component/Floor.h"

bool InitiateGameWorld(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 gameWorldSize)
{

	CoordTranslator* translator = CoordTranslator::instance();
	CreateGameWorldBoundaries(registry, world, gRenderer, b2Vec2{ 1600,900 });

	// Init Player
	CreatePlayerPrefab(registry, world, gRenderer);
	CreateStaticRectangleObstacle(registry, world, gRenderer, b2Vec2(25, 25), b2Vec2(2, 2));
	float32 initialX = 250.f;
	//for (initialX; initialX < 600.f; initialX++)
	//{
	CreateDynamicBallObject(registry, world, gRenderer, b2Vec2(82, 82), 1.f);
	CreateDynamicBallObject(registry, world, gRenderer, b2Vec2(80, 80), 1.f);
	CreateDynamicBallObject(registry, world, gRenderer, b2Vec2(90, 80), 1.f);
	//}
	//TODO return 0 if error
	return true;
}

void CreateGameWorldBoundaries(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 gameWorldSize)
{
	CoordTranslator* translator = CoordTranslator::instance();
	CreateStaticRectangleObstacle(registry, world, gRenderer, b2Vec2(0, 0), b2Vec2(160, 1));
	CreateStaticRectangleObstacle(registry, world, gRenderer, b2Vec2(0, 0), b2Vec2(1, 90));
	CreateStaticRectangleObstacle(registry, world, gRenderer, b2Vec2(159, 0), b2Vec2(1, 90));
	CreateStaticRectangleObstacle(registry, world, gRenderer, b2Vec2(0, 90 - .5), b2Vec2(160, 1));
}
