#pragma once

#include <SDL.h>
#include <Box2D/Box2D.h>
#include <entt/entt.hpp>
#include "../CoordTranslator.h"

namespace BodiesFactory
{

	b2Body* CreateDynamicBody(b2World& world, entt::entity entity, b2Vec2 position, b2Vec2 size, float density = 1.0f, float friction = 0.3f);
	b2Body* CreateDynamicSphere(b2World& world, entt::entity entity, b2Vec2 position, float radius, float density = 1.0f, float friction = 0.3f, bool isBullet = false);
	b2Body* CreateStaticBody(b2World& world, entt::entity entity, b2Vec2 position, b2Vec2 size);
}
