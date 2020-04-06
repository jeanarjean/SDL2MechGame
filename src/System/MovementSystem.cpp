#include "MovementSystem.h"
#include "../Component/Player.h"
#include <Box2D\Dynamics\b2Body.h>
#include "../Enums/MovementEnum.h"
#include "../Utils/BitMaskUtil.h"
#include "../Utils/CoordTranslator.h"

namespace MovementSystem
{
	void MovePlayer(entt::registry& registry)
	{
		registry.view<Player, b2Body*>().each([](auto& player, auto* body) {
			b2Vec2 position = body->GetPosition();
			//TODO: MOVE THIS TO A CONST FILE
			const float topHorizontalVel = 20;
			const float topVerticalSpeed = 20;
			float accelerationVerticalSpeed = 2.2f;
			float accelerationHorizontalSpeed = 4.f;
			b2Vec2 vel = body->GetLinearVelocity();
			int controlState = player.m_controlState;
			if (BitMaskUtil::IsBitActive(controlState, MECH_UP_BIT))
			{
				vel.y = b2Min(vel.y + accelerationVerticalSpeed, topVerticalSpeed);
			}
			if (BitMaskUtil::IsBitActive(controlState, MECH_DOWN_BIT))
			{
				vel.y = b2Max(vel.y - accelerationVerticalSpeed, -topVerticalSpeed);
			}
			if (BitMaskUtil::IsBitActive(controlState, MECH_RIGHT_BIT))
			{
				vel.x = b2Min(vel.x + accelerationHorizontalSpeed, topHorizontalVel);
			}
			if (BitMaskUtil::IsBitActive(controlState, MECH_LEFT_BIT))
			{
				vel.x = b2Max(vel.x - accelerationHorizontalSpeed, -topHorizontalVel);
			}
			if (!BitMaskUtil::IsBitActive(controlState, MECH_LEFT_BIT) && !BitMaskUtil::IsBitActive(controlState, MECH_RIGHT_BIT))
			{
				//vel.x = 0;
			}
			// THIS IS UGLY NEEDS GETTER AND SETTER / THIS AIN'T THREAD SAFE AT ALL LOL
			CoordTranslator* translator = CoordTranslator::instance();
			translator->m_viewCenter = body->GetPosition();

			body->SetLinearVelocity(vel);
			});
	}
}
