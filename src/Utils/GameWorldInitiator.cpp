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
		Mix_Music* music = Mix_LoadMUS("../resources/MUSIC.wav");
		assert(music != nullptr);
		Mix_PlayMusic(music, 2);


		CoordTranslator* translator = CoordTranslator::instance();

		return true;
	}

	GameWorldInitiator::~GameWorldInitiator()
	{
		prefabsFactory = NULL;
	}
}
