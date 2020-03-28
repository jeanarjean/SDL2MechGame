#include "GameWorldInitiator.h"
#include "CoordTranslator.h"
#include "TextureUtils.h"
#include "../Utils/BackgroundLoader.h"
#include "../Physic/ContactListener.h"
#include "../Component/Renderable.h"
#include "../Component/BoundingBox.h"
#include <SDL_mixer.h>

namespace GameWorldInitiator {
	bool GameWorldInitiator::InitiateGameWorld(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 gameWorldSize)
	{
		ContactListener* contactListener = new ContactListener(registry);
		world.SetContactListener(contactListener);
		BackgroundLoader::LoadBackground(registry, gRenderer);

		Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
		Mix_Music* music = Mix_LoadMUS("../resources/untitled.ogg");
		Mix_PlayMusic(music, 2);


		CoordTranslator* translator = CoordTranslator::instance();
		CreateGameWorldBoundaries(registry, world, gRenderer, b2Vec2{ 1600,900 });

		// Init Player
		prefabsFactory->CreatePlayerPrefab(registry, world, gRenderer);
		prefabsFactory->CreateStaticRectangleObstacle(registry, world, gRenderer, b2Vec2(25, 25), b2Vec2(2, 2));
		float32 initialX = 250.f;
		prefabsFactory->CreateBasicEnemy(registry, world, gRenderer, b2Vec2(82, 82), 1.f);
		prefabsFactory->CreateBasicEnemy(registry, world, gRenderer, b2Vec2(80, 80), 1.f);
		prefabsFactory->CreateBasicEnemy(registry, world, gRenderer, b2Vec2(90, 80), 1.f);
		prefabsFactory->CreateBasicEnemy(registry, world, gRenderer, b2Vec2(20, 80), 1.f);
		prefabsFactory->CreateBasicEnemy(registry, world, gRenderer, b2Vec2(30, 5), 1.f);
		prefabsFactory->CreateBasicEnemy(registry, world, gRenderer, b2Vec2(40, 80), 1.f);
		prefabsFactory->CreateBasicEnemy(registry, world, gRenderer, b2Vec2(50, 80), 1.f);

		return true;
	}

	void GameWorldInitiator::CreateGameWorldBoundaries(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 gameWorldSize)
	{
		CoordTranslator* translator = CoordTranslator::instance();
		prefabsFactory->CreateBoundingRectangle(registry, world, gRenderer, b2Vec2(0, 2), b2Vec2(160, 1));
		prefabsFactory->CreateBoundingRectangle(registry, world, gRenderer, b2Vec2(0, 0), b2Vec2(1, 90));
		prefabsFactory->CreateBoundingRectangle(registry, world, gRenderer, b2Vec2(159, 0), b2Vec2(1, 90));
		prefabsFactory->CreateBoundingRectangle(registry, world, gRenderer, b2Vec2(0, 90 - .5), b2Vec2(160, 1));
	}

	GameWorldInitiator::~GameWorldInitiator()
	{
		prefabsFactory = NULL;
	}
}
