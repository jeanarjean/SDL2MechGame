#include "MovementSystem.h"
#include "../Component/Player.h"
#include <Box2D\Dynamics\b2Body.h>
#include "../Enums/MovementEnum.h"
#include "../Utils/BitMaskUtil.h"
#include "../Utils/CoordTranslator.h"

namespace MovementSystem
{
	MovementSystem::~MovementSystem()
	{
	}

	void MovementSystem::MovePlayer(int currentTick, entt::registry& registry)
	{
		auto view = registry.view<Player, b2Body*>();

		for (auto entity : view) {
			auto& player = view.get<Player>(entity);
			auto& body = view.get<b2Body*>(entity);
			b2Vec2 position = body->GetPosition();
			//TODO: MOVE THIS TO A CONST FILE
			const float topHorizontalVel = 40;
			const float topVerticalSpeed = 20;
			float accelerationVerticalSpeed = 0.2f;
			float accelerationHorizontalSpeed = 1.f;
			float decelerationHorizontalSpeed = 0.8f;
			b2Vec2 vel = body->GetLinearVelocity();
			int controlState = player.m_controlState;
			if (BitMaskUtil::IsBitActive(controlState, MECH_RIGHT_BIT))
			{
				vel.x = b2Min(vel.x + accelerationHorizontalSpeed, topHorizontalVel);
				SDL_Log("right: current frame %d", currentTick);
			}
			if (BitMaskUtil::IsBitActive(controlState, MECH_LEFT_BIT))
			{
				vel.x = b2Max(vel.x - accelerationHorizontalSpeed, -topHorizontalVel);
				SDL_Log("left: current frame %d", currentTick);
			}
			if (BitMaskUtil::IsBitInactive(controlState, MECH_LEFT_BIT) && BitMaskUtil::IsBitInactive(controlState, MECH_RIGHT_BIT))
			{
				if (vel.x > 0)
				{
					vel.x = b2Max(vel.x - decelerationHorizontalSpeed, 0.f);
				}
				else if (vel.x < 0)
				{
					vel.x = b2Min(vel.x + decelerationHorizontalSpeed, 0.f);
				}
			}

			// THIS IS UGLY NEEDS GETTER AND SETTER / THIS AIN'T THREAD SAFE AT ALL LOL
			CoordTranslator* translator = CoordTranslator::instance();
			translator->m_viewCenter = body->GetPosition();

			body->SetLinearVelocity(vel);

			if (BitMaskUtil::IsBitActive(controlState, MECH_UP_BIT))
			{
				if (currentTick - lastJumpTick > 120)
				{
					lastJumpTick = currentTick;
					body->ApplyLinearImpulse(b2Vec2(0, 5), position, true);
				}
			}
			if (BitMaskUtil::IsBitActive(controlState, MECH_DOWN_BIT))
			{
				body->ApplyLinearImpulse(b2Vec2(0, -1), position, true);
			}
		}
	}
}
