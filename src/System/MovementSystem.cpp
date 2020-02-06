#include "MovementSystem.h"
#include "../Component/Position.h"
#include "../Component/Player.h"
#include <Box2D\Dynamics\b2Body.h>

enum {
	MECH_LEFT = 0x1,
	MECH_RIGHT = 0x2,
	MECH_UP = 0x4,
	MECH_DOWN = 0x8
};

void MovePlayer(entt::registry& registry)
{
	registry.view<Player, b2Body*>().each([](auto& player, auto* body) {
		b2Vec2 position = body->GetPosition();
		float desiredVelX = 0;
		float horizontalVel = 20;
		float topVerticalSpeed = 20;
		float accelerationVerticalSpeed = 2.2f;
		b2Vec2 vel = body->GetLinearVelocity();
		int controlState = player.m_controlState;
		if (((controlState) >> (2)) & 1)
		{
			vel.y = b2Min(vel.y + accelerationVerticalSpeed, topVerticalSpeed);
		}
		if (((controlState) >> (3)) & 1)
		{
			vel.y = b2Max(vel.y - accelerationVerticalSpeed, -topVerticalSpeed);
		}
		if (((controlState)>> (1)) & 1)
		{
			vel.x = horizontalVel;
		}
		if (((controlState) >> (0)) & 1)
		{
			vel.x = -horizontalVel;
		}

		body->SetLinearVelocity(vel);
		});
}
