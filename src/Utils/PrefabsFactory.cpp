#include "PrefabsFactory.h"
#include "../Component/Renderable.h"
#include "../Component/Player.h"
#include "../Component/Platform.h"
#include "../Component/BoundingBox.h"
#include "../Component/Dynamic.h"
#include "TextureUtils.h"
#include "CoordTranslator.h"

entt::entity CreatePlayerPrefab(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer)
{
	CoordTranslator* translator = CoordTranslator::instance();
	b2Vec2 size{ 50.f, 50.0f };
	size = translator->scalarPixelsVectorToWorld(size);

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
	fixtureDef.friction = 0.3f;

	// Add the shape to the body.
	body->CreateFixture(&fixtureDef);
	auto entity = registry.create();
	registry.assign<Player>(entity, Player{ 0 });
	registry.assign<DynamicBody>(entity);
	Renderable renderable{ NULL, 0, 0 };
	if (!LoadFromFile("../resources/Sprite-Mech-0002.png", gRenderer, renderable))
		printf("Failed to load dot texture!\n");
	registry.assign<Renderable>(entity, Renderable{ renderable.mTexture, (int)size.x, (int)size.y });
	registry.assign<b2Body*>(entity, body);
	return entity;
}

entt::entity CreateStaticRectangleObstacle(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 position, b2Vec2 size)
{
	// Define the ground body.
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(position.x + size.x / 2, position.y + size.y / 2);
	b2Body* groundBody = world.CreateBody(&groundBodyDef);

	// Define the ground box shape.
	b2PolygonShape groundBox;

	// The extents are the half-widths of the box.
	groundBox.SetAsBox(size.x / 2, size.y / 2);

	// Add the ground fixture to the ground body.
	groundBody->CreateFixture(&groundBox, 0.0f);

	auto entity = registry.create();
	Renderable renderable2{ NULL, 0, 0 };
	if (!LoadFromFile("../resources/blue.bmp", gRenderer, renderable2))
		printf("Failed to load dot texture!\n");
	registry.assign<Renderable>(entity, Renderable{ renderable2.mTexture, (int)size.x, (int)size.y });
	registry.assign<Platform>(entity);
	registry.assign<b2Body*>(entity, groundBody);

	return entity;
}

entt::entity CreateBoundingRectangle(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, b2Vec2 position, b2Vec2 size)
{
	// Define the ground body.
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(position.x + size.x / 2, position.y + size.y / 2);
	b2Body* groundBody = world.CreateBody(&groundBodyDef);

	// Define the ground box shape.
	b2PolygonShape groundBox;

	// The extents are the half-widths of the box.
	groundBox.SetAsBox(size.x / 2, size.y / 2);

	// Add the ground fixture to the ground body.
	groundBody->CreateFixture(&groundBox, 0.0f);

	auto entity = registry.create();
	Renderable renderable2{ NULL, 0, 0 };
	if (!LoadFromFile("../resources/blue.bmp", gRenderer, renderable2))
		printf("Failed to load dot texture!\n");
	registry.assign<Renderable>(entity, Renderable{ renderable2.mTexture, (int)size.x, (int)size.y });
	registry.assign<BoundingBox>(entity);
	registry.assign<b2Body*>(entity, groundBody);

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
	registry.assign<DynamicBody>(entity);
	Renderable renderable{ NULL, 0, 0 };
	if (!LoadFromFile("../resources/Sprite-Mech-0002.png", gRenderer, renderable))
		printf("Failed to load dot texture!\n");

	registry.assign<Renderable>(entity, Renderable{ renderable.mTexture, (int)translator->scalarWorldToPixels(radius), (int)translator->scalarWorldToPixels(radius) });
	registry.assign<b2Body*>(entity, body);
	return entity;
}
