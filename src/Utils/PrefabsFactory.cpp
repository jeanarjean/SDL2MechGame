#include "PrefabsFactory.h"
#include "../Component/Renderable.h"
#include "../Component/Player.h"
#include "../Component/Platform.h"
#include "../Component/BoundingBox.h"
#include "../Component/Dynamic.h"
#include "../Component/Sprite.h"
#include "../Component/Animation.h"
#include "TextureUtils.h"
#include "CoordTranslator.h"
#include "../Component/Bullet.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include "../Component/Frame.h"

using json = nlohmann::json;


namespace PrefabsFactory
{
	entt::entity CreatePlayerPrefab(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer)
	{
		CoordTranslator* translator = CoordTranslator::instance();
		b2Vec2 size{ 50.f, 50.0f };
		size = translator->scalarPixelsToWorld(size);

		// Define the dynamic body. We set its position and call the body factory.
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(20.0f + size.x / 2, 20.0f + size.y / 2);
		b2Body* body = world.CreateBody(&bodyDef);

		// Define another box shape for our dynamic body.
		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox(size.x / 2, size.y / 2);

		// Define the dynamic body fixture.
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;

		// Set the box density to be non-zero, so it will be dynamic.
		fixtureDef.density = 1.0f;

		// Override the default friction.
		fixtureDef.friction = .3f;

		// Add the shape to the body.
		body->CreateFixture(&fixtureDef);
		auto entity = registry.create();
		body->SetUserData(reinterpret_cast<void*>(entity));

		registry.assign<Player>(entity, Player{ 0 });
		// this should be fixed at some point
		//registry.assign<DynamicBody>(entity);



		json ja;

		std::ifstream iaasda("../resources/Sprite-0004.json");
		json j = json::parse(iaasda);
		json jframes = j["frames"];
		int x = jframes["Sprite-0003 0.aseprite"]["frame"]["x"];
		int y = jframes["Sprite-0003 0.aseprite"]["frame"]["y"];
		int w = jframes["Sprite-0003 0.aseprite"]["frame"]["w"];
		int h = jframes["Sprite-0003 0.aseprite"]["frame"]["h"];
		Uint8 duration = jframes["Sprite-0003 0.aseprite"]["duration"];

		Frame frame1{ x , y , h , w, duration, 0 };

		x = jframes["Sprite-0003 1.aseprite"]["frame"]["x"];
		y = jframes["Sprite-0003 1.aseprite"]["frame"]["y"];
		w = jframes["Sprite-0003 1.aseprite"]["frame"]["w"];
		h = jframes["Sprite-0003 1.aseprite"]["frame"]["h"];
		h = jframes["Sprite-0003 1.aseprite"]["frame"]["h"];
		duration = jframes["Sprite-0003 1.aseprite"]["duration"];



		Frame frame2{ x , y , h , w, duration, 0 };

		std::vector<Frame> frames{ frame1, frame2 };
		Renderable renderable{ NULL, 0, 0 };
		if (!LoadFromFile("../resources/Sprite-0004.png", gRenderer, renderable))
			printf("Failed to load dot texture!\n");
		Animation animation{ frames, renderable };

		registry.assign<Animation>(entity, animation);


		registry.assign<Renderable>(entity, Renderable{ renderable.mTexture, (int)size.x, (int)size.y });
		registry.assign<b2Body*>(entity, body);
		return entity;
	}

	entt::entity CreateStaticRectangleObstacle(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 position, b2Vec2 size)
	{
		// Define the ground body.
		b2BodyDef groundBodyDef;
		groundBodyDef.position.Set(position.x + size.x / 2, position.y + size.y / 2);
		b2Body* body = world.CreateBody(&groundBodyDef);

		// Define the ground box shape.
		b2PolygonShape groundBox;

		// The extents are the half-widths of the box.
		groundBox.SetAsBox(size.x / 2, size.y / 2);

		// Add the ground fixture to the ground body.
		body->CreateFixture(&groundBox, 0.0f);

		auto entity = registry.create();
		body->SetUserData(reinterpret_cast<void*>(entity));

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
		// Define the ground body.
		b2BodyDef groundBodyDef;
		groundBodyDef.position.Set(position.x + size.x / 2, position.y + size.y / 2);
		b2Body* body = world.CreateBody(&groundBodyDef);

		// Define the ground box shape.
		b2PolygonShape groundBox;

		// The extents are the half-widths of the box.
		groundBox.SetAsBox(size.x / 2, size.y / 2);

		// Add the ground fixture to the ground body.
		body->CreateFixture(&groundBox, 0.0f);

		auto entity = registry.create();
		body->SetUserData(reinterpret_cast<void*>(entity));
		Renderable renderable2{ NULL, 0, 0 };
		if (!LoadFromFile("../resources/blue.bmp", gRenderer, renderable2))
			printf("Failed to load dot texture!\n");
		registry.assign<Renderable>(entity, Renderable{ renderable2.mTexture, (int)size.x, (int)size.y });
		registry.assign<BoundingBox>(entity);
		registry.assign<b2Body*>(entity, body);

		return entity;
	}

	entt::entity CreateDynamicBallObject(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 position, float radius)
	{
		CoordTranslator* translator = CoordTranslator::instance();
		// Define the dynamic body. We set its position and call the body factory.
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(101.0f + radius / 2, 20.0f + radius);
		b2Body* body = world.CreateBody(&bodyDef);

		// Define another box shape for our dynamic body.
		b2CircleShape dynamicBox;
		dynamicBox.m_radius = 2.f;

		// Define the dynamic body fixture.
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;

		// Set the box density to be non-zero, so it will be dynamic.
		fixtureDef.density = 1.0f;

		// Override the default friction.
		fixtureDef.friction = 0.3f;

		// Add the shape to the body.
		body->CreateFixture(&fixtureDef);
		auto entity = registry.create();
		body->SetUserData(reinterpret_cast<void*>(entity));
		registry.assign<DynamicBody>(entity);
		Renderable renderable{ NULL, 0, 0 };
		if (!LoadFromFile("../resources/Sprite-Mech-0002.png", gRenderer, renderable))
			printf("Failed to load dot texture!\n");

		registry.assign<Renderable>(entity, Renderable{ renderable.mTexture, (int)translator->scalarWorldToPixels(radius), (int)translator->scalarWorldToPixels(radius) });
		registry.assign<b2Body*>(entity, body);
		return entity;
	}

	entt::entity SpawnBullet(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 position)
	{
		CoordTranslator* translator = CoordTranslator::instance();

		// SET FORCE TO THE BULLET
		int x, y;
		SDL_GetMouseState(&x, &y);
		b2Vec2 mousePosition = translator->coordPixelsToWorld(b2Vec2((float32)x, (float32)y));
		b2Vec2 forceToApply = mousePosition - position;
		forceToApply.Normalize();


		float radius = 0.1f;
		// Define the dynamic body. We set its position and call the body factory.
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(position.x + forceToApply.x * 2, position.y + forceToApply.y * 2);
		bodyDef.bullet = true;
		bodyDef.allowSleep = true;
		b2Body* body = world.CreateBody(&bodyDef);

		// Define another box shape for our dynamic body.
		b2CircleShape dynamicBox;
		dynamicBox.m_radius = radius;

		// Define the dynamic body fixture.
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;

		// Set the box density to be non-zero, so it will be dynamic.
		fixtureDef.density = 20.0f;

		// Override the default friction.
		fixtureDef.friction = 0.3f;

		// Add the shape to the body.
		body->CreateFixture(&fixtureDef);

		body->ApplyForce(b2Vec2(forceToApply.x * 4000.f * 50.f, forceToApply.y * 4000.f * 50.f), body->GetWorldCenter(), true);


		auto entity = registry.create();
		body->SetUserData(reinterpret_cast<void*>(entity));
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
