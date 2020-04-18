#include "BodiesFactory.h"

namespace BodiesFactory
{
	b2Body* CreateDynamicBody(b2World& world, entt::entity entity, b2Vec2 position, b2Vec2 size, float density, float friction)
	{
		CoordTranslator* translator = CoordTranslator::instance();

		// Define the dynamic body. We set its position and call the body factory.
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(position.x + size.x / 2, position.y + size.y / 2);
		b2Body* body = world.CreateBody(&bodyDef);

		// Define another box shape for our dynamic body.
		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox(size.x / 2, size.y / 2);

		// Define the dynamic body fixture.
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;

		// Set the box density to be non-zero, so it will be dynamic.
		fixtureDef.density = density;

		// Override the default friction.
		fixtureDef.friction = friction;

		// Add the shape to the body.
		body->CreateFixture(&fixtureDef);
		body->SetUserData(reinterpret_cast<void*>(entity));
		auto asd = body->GetFixtureList()[0].GetAABB(0).lowerBound;

		return body;
	}

	b2Body* CreateDynamicSphere(b2World& world, entt::entity entity, b2Vec2 position, float radius, float density, float friction, bool isBullet)
	{
		// Define the dynamic body. We set its position and call the body factory.
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(position.x, position.y);
		bodyDef.bullet = isBullet;
		b2Body* body = world.CreateBody(&bodyDef);

		// Define another box shape for our dynamic body.
		b2CircleShape dynamicBox;
		dynamicBox.m_radius = radius;

		// Define the dynamic body fixture.
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;

		// Set the box density to be non-zero, so it will be dynamic.
		fixtureDef.density = 0.01;

		// Override the default friction.
		fixtureDef.friction = 0.3f;

		// Add the shape to the body.
		body->CreateFixture(&fixtureDef);
		body->SetUserData(reinterpret_cast<void*>(entity));
		return body;
	}

	b2Body* CreateStaticBody(b2World& world, entt::entity entity, b2Vec2 position, b2Vec2 size)
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

		body->SetUserData(reinterpret_cast<void*>(entity));
		return body;
	}
}
