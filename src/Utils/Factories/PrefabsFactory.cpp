#include "PrefabsFactory.h"
#include "../../Component/Renderable.h"
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
	entt::entity CreatePlayerPrefab(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer)
	{
		auto entity = registry.create();

		b2Vec2 size(50.f, 50.f);
		b2Vec2 position(50.f, 50.f);
		b2Body* body = BodiesFactory::CreateDynamicBody(world, entity, position, size);
		CoordTranslator* translator = CoordTranslator::instance();

		//TODO: this is shit
		size = translator->scalarPixelsToWorld(size);

		registry.assign<Player>(entity, Player{ 0 });
		Animation animation = AnimationLoader::LoadAnimation("SamuraiShowdownSamurai", gRenderer);
		registry.assign<Animation>(entity, animation);


		animation.mTexture.mHeight = size.x;
		animation.mTexture.mWidth = size.y;
		registry.assign<Renderable>(entity, animation.mTexture);
		registry.assign<b2Body*>(entity, body);
		return entity;
	}

	entt::entity CreateStaticRectangleObstacle(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 position, b2Vec2 size)
	{
		auto entity = registry.create();
		b2Body* body = BodiesFactory::CreateStaticBody(world, entity, position, size);
		Renderable renderable2{ NULL, 0, 0 };
		if (!LoadFromFile("../resources/blue.bmp", gRenderer, renderable2))
			printf("Failed to load dot texture!\n");
		registry.assign<Renderable>(entity, Renderable{ renderable2.mTexture, (int)size.x, (int)size.y });
		registry.assign<Platform>(entity);
		registry.assign<b2Body*>(entity, body);

		return entity;
	}

	entt::entity CreateBoundingRectangle(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 position, b2Vec2 size)
	{
		auto entity = registry.create();
		b2Body* body = BodiesFactory::CreateStaticBody(world, entity, position, size);
		Renderable renderable2{ NULL, 0, 0 };
		if (!LoadFromFile("../resources/blue.bmp", gRenderer, renderable2))
			printf("Failed to load dot texture!\n");
		registry.assign<Renderable>(entity, Renderable{ renderable2.mTexture, (int)size.x, (int)size.y });
		registry.assign<BoundingBox>(entity);
		registry.assign<b2Body*>(entity, body);

		return entity;
	}

	entt::entity CreateBasicEnemy(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 position, float radius)
	{
		CoordTranslator* translator = CoordTranslator::instance();
		auto entity = registry.create();
		b2Body* body = BodiesFactory::CreateDynamicSphere(world, entity, position, radius);
		registry.assign<DynamicBody>(entity);
		Renderable renderable{ NULL, 0, 0 };
		if (!LoadFromFile("../resources/Sprite-Mech-0002.png", gRenderer, renderable))
			printf("Failed to load dot texture!\n");

		registry.assign<Renderable>(entity, Renderable{ renderable.mTexture, (int)translator->scalarWorldToPixels(radius), (int)translator->scalarWorldToPixels(radius) });
		registry.assign<b2Body*>(entity, body);
		registry.assign<Enemy>(entity);
		Health health{ 5 };
		registry.assign<Health>(entity, health);
		return entity;
	}

	entt::entity SpawnBullet(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 position)
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
