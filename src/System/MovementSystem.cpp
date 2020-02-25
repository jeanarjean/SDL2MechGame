#include "MovementSystem.h"
#include "../Component/Player.h"
#include <Box2D\Dynamics\b2Body.h>
#include "../Enums/MovementEnum.h"

namespace MovementSystem
{
	void MovePlayer(entt::registry& registry)
	{
		registry.view<Player, b2Body*>().each([](auto& player, auto* body) {
			b2Vec2 position = body->GetPosition();
			int asd = MECH_DOWN;
			float desiredVelX = 0;
			float topHorizontalVel = 20;
			float topVerticalSpeed = 20;
			float accelerationVerticalSpeed = 2.2f;
			float accelerationHorizontalSpeed = 4.f;
			b2Vec2 vel = body->GetLinearVelocity();
			int controlState = player.m_controlState;
			if (((controlState) >> (MECH_UP_BIT)) & 1)
			{
				vel.y = b2Min(vel.y + accelerationVerticalSpeed, topVerticalSpeed);
			}
			if (((controlState) >> (MECH_DOWN_BIT)) & 1)
			{
				vel.y = b2Max(vel.y - accelerationVerticalSpeed, -topVerticalSpeed);
			}
			if (((controlState) >> (MECH_RIGHT_BIT)) & 1)
			{
				vel.x = b2Min(vel.x + accelerationHorizontalSpeed, topHorizontalVel);
			}
			if (((controlState) >> (MECH_LEFT_BIT)) & 1)
			{
				vel.x = b2Max(vel.x - accelerationHorizontalSpeed, -topHorizontalVel);
			}

			body->SetLinearVelocity(vel);
			});
	}
}
