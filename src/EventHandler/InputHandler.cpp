#include "InputHandler.h"
#include "../Component/Position.h"
#include "../Component/Player.h"
#include <Eigen/Dense>
#include "../Utils//CoordTranslator.h"

enum {
	MECH_LEFT = 0x1,
	MECH_RIGHT = 0x2,
	MECH_UP = 0x4,
	MECH_DOWN = 0x8
};

void HandleInputs(entt::registry& registry, SDL_Event event)
{
	//SDL_Event previous_event()???
	registry.view<Player>().each([event](auto& player) {
		if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				player.m_controlState |= MECH_UP;
				break;
			case SDLK_s:
				player.m_controlState |= MECH_DOWN;
				break;
			case SDLK_a:
				player.m_controlState |= MECH_LEFT;
				break;
			case SDLK_d:
				player.m_controlState |= MECH_RIGHT;
				break;
			}
		}
		if (event.type == SDL_KEYUP && event.key.repeat == 0)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				player.m_controlState &= ~MECH_UP;
				break;
			case SDLK_s:
				player.m_controlState &= ~MECH_DOWN;
				break;
			case SDLK_a:
				player.m_controlState &= ~MECH_LEFT;
				break;
			case SDLK_d:
				player.m_controlState &= ~MECH_RIGHT;
				break;
			}

		}
		//fix this
		//If a key was pressed
		//if (event.type == SDL_KEYDOWN)
		//{
		//	player.

		//}
		//if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
		//{
		//const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
		//if (currentKeyStates[SDL_SCANCODE_W])
		//{
		//	vel.y = b2Min(vel.y + accelerationVerticalSpeed, topVerticalSpeed);
		//}
		//if (currentKeyStates[SDL_SCANCODE_S])
		//{
		//	vel.y = b2Max(vel.y - accelerationVerticalSpeed, -topVerticalSpeed);
		//}
		//if (currentKeyStates[SDL_SCANCODE_A])
		//{
		//	vel.x = -horizontalVel;
		//}
		//if (currentKeyStates[SDL_SCANCODE_D])
		//{
		//	vel.x = horizontalVel;
		//}

		//body->SetLinearVelocity(vel);

		//switch (event.key.keysym.sym)
		//{
		//case SDLK_w:
		//	vel.y = b2Min(vel.y + accelerationVerticalSpeed, topVerticalSpeed);
		//	break;
		//case SDLK_s:
		//	vel.y = b2Max(vel.y - accelerationVerticalSpeed, -topVerticalSpeed);
		//	break;
		//case SDLK_a:
		//	vel.x = -horizontalVel;
		//	break;
		//case SDLK_d:
		//	vel.x = horizontalVel;
		//	break;
		//}
	//}
		//if (event.type == SDL_MOUSEBUTTONDOWN)
		//{
		//	CoordTranslator* translator = CoordTranslator::instance();
		//	int x, y;
		//	SDL_GetMouseState(&x, &y);
		//	b2Vec2 mousePosition = translator->coordPixelsToWorld((float32)x, (float32)y);
		//	b2Vec2 bodyPosition = body->GetPosition();
		//	b2Vec2 forceToApply = mousePosition - body->GetPosition();
		//	forceToApply.Normalize();

		//	//body->ApplyImpulse(b2Vec2(forceToApply.x * 4000.f, forceToApply.y * 4000.f), true);
		//	b2Vec2 tes123123 = body->GetWorldCenter();
		//	//body->ApplyLinearForce(b2Vec2(3000, 3000), body->GetWorldCenter(), true);
		//}

		//body->SetLinearVelocity(vel);
		//body->ApplyLinearForce(b2Vec2(3000, 3000), body->GetWorldCenter(), true);
		//	}
		//}
		////If a key was released
		//else if (event.type == SDL_KEYUP && event.key.repeat == 0)
		//{
		//	//Adjust the velocity
		//	switch (event.key.keysym.sym)
		//	{
		//	case SDLK_a:
		//		mVelX += DOT_VEL;
		//		break;
		//	case SDLK_d:
		//		mVelX -= DOT_VEL;
		//		break;
			//}
	});

}
