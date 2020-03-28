#include "PrefabsFactory.h"
#include "../../Component/Player.h"
#include "../../Component/Platform.h"
#include "../../Component/BoundingBox.h"
#include "../../Component/Dynamic.h"
#include "../../Component/Sprite.h"
#include "../../Component/Animation.h"
#include "../../Component/Bullet.h"
#include "../../Component/Enemy.h"
#include "../../Component/Health.h"
#include "../TextureUtils.h"
#include "../CoordTranslator.h"
#include "../AnimationLoader.h"
#include "../MouseUtil.h"
#include "BodiesFactory.h"

namespace PrefabsFactory
{
	PrefabsFactory::PrefabsFactory(SDL_Renderer* gRenderer)
	{
		_renderableBlue = new Renderable{ NULL, 0, 0 };
		if (!LoadFromFile("../resources/blue.bmp", gRenderer, *_renderableBlue))
			printf("Failed to load dot texture!\n");
		_renderableMech = new Renderable{ NULL, 0, 0 };
		if (!LoadFromFile("../resources/Sprite-Mech-0002.png", gRenderer, *_renderableMech))
			printf("Failed to load dot texture!\n");
		_renderableDot = new Renderable{ NULL, 0, 0 };
		if (!LoadFromFile("../resources/dot.bmp", gRenderer, *_renderableDot))
			printf("Failed to load dot texture!\n");
	}

	PrefabsFactory::~PrefabsFactory()
	{
		free(_renderableBlue->mTexture);
		free(_renderableBlue);
		_renderableBlue = NULL;

		free(_renderableMech->mTexture);
		free(_renderableMech);
		_renderableMech = NULL;

		free(_renderableDot->mTexture);
		free(_renderableDot);
		_renderableDot = NULL;
	}

	entt::entity PrefabsFactory::CreatePlayerPrefab(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer)
	{
		auto entity = registry.create();

		b2Vec2 size(50.f, 50.f);
		b2Vec2 position(50.f, 50.f);
		b2Body* body = BodiesFactory::CreateDynamicBody(world, entity, position, size);
		CoordTranslator* translator = CoordTranslator::instance();

		//TODO: this is shit
		size = translator->scalarPixelsToWorld(size);

		registry.assign<Player>(entity, Player{ 0 , false });
		registry.assign<Health>(entity, Health{ 1 });
		Animation animationSamurai = AnimationLoader::LoadAnimation("SamuraiShowdownSamurai", gRenderer);
		registry.assign<Animation>(entity, animationSamurai);


		animationSamurai.mTexture.mHeight = size.x;
		animationSamurai.mTexture.mWidth = size.y;
		registry.assign<Renderable>(entity, animationSamurai.mTexture);
		registry.assign<b2Body*>(entity, body);
		return entity;
	}

	entt::entity PrefabsFactory::CreateStaticRectangleObstacle(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 position, b2Vec2 size)
	{
		auto entity = registry.create();
		b2Body* body = BodiesFactory::CreateStaticBody(world, entity, position, size);
		registry.assign<Renderable>(entity, Renderable{ _renderableBlue->mTexture, (int)size.x, (int)size.y });
		registry.assign<Platform>(entity);
		registry.assign<b2Body*>(entity, body);

		return entity;
	}

	entt::entity PrefabsFactory::CreateBoundingRectangle(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 position, b2Vec2 size)
	{
		auto entity = registry.create();
		b2Body* body = BodiesFactory::CreateStaticBody(world, entity, position, size);
		registry.assign<Renderable>(entity, Renderable{ _renderableBlue->mTexture, (int)size.x, (int)size.y });
		registry.assign<BoundingBox>(entity);
		registry.assign<b2Body*>(entity, body);

		return entity;
	}

	entt::entity PrefabsFactory::CreateBasicEnemy(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 position, float radius)
	{
		CoordTranslator* translator = CoordTranslator::instance();
		auto entity = registry.create();
		b2Body* body = BodiesFactory::CreateDynamicSphere(world, entity, position, radius);
		registry.assign<DynamicBody>(entity);

		registry.assign<Renderable>(entity, Renderable{ _renderableMech->mTexture, (int)translator->scalarWorldToPixels(radius), (int)translator->scalarWorldToPixels(radius) });
		registry.assign<b2Body*>(entity, body);
		registry.assign<Enemy>(entity);
		Health health{ 5 };
		registry.assign<Health>(entity, health);
		return entity;
	}

	entt::entity PrefabsFactory::SpawnBullet(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 position)
	{
		CoordTranslator* translator = CoordTranslator::instance();
		auto entity = registry.create();
		float radius = 0.1f;

		b2Vec2 forceToApply = MouseUtil::GetVectorBetweenPositionAndMouse(position);
		forceToApply.Normalize();
		position = b2Vec2{ position.x + forceToApply.x * 2, position.y + forceToApply.y * 2 };

		b2Body* body = BodiesFactory::CreateDynamicSphere(world, entity, position, radius, 20.0f, 0.3f, true);

		body->ApplyForce(b2Vec2(forceToApply.x * 4000.f * 50.f, forceToApply.y * 4000.f * 50.f), body->GetWorldCenter(), true);

		registry.assign<DynamicBody>(entity);
		registry.assign<Bullet>(entity);
		Renderable renderable{ NULL, 0, 0 };
		if (!LoadFromFile("../resources/dot.bmp", gRenderer, renderable))
			printf("Failed to load dot texture!\n");

		registry.assign<Renderable>(entity, Renderable{ renderable.mTexture, (int)translator->scalarWorldToPixels(radius), (int)translator->scalarWorldToPixels(radius) });
		registry.assign<b2Body*>(entity, body);
		return entity;
	}
}
