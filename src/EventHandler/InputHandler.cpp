#include "InputHandler.h"
#include "../Component/Position.h"
#include "../Component/Renderable.h"
#include "../Component/Player.h"
#include <Box2D\Dynamics\b2Body.h>

void HandleInputs(entt::registry& registry, SDL_Event event)
{
	//SDL_Event previous_event()???
	registry.view<Player, b2Body*>().each([event](auto& player, auto* body) {
		//If a key was pressed
		b2Vec2 position = body->GetPosition();
		float desiredVelX = 0;
		float desiredVelY = 0;
		const float DOT_VEL = 100.f;
		if (event.type == SDL_KEYDOWN)
		{
			b2Vec2 position = body->GetPosition();
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				desiredVelY += DOT_VEL;
				break;
			case SDLK_s:
				desiredVelY -= DOT_VEL;
				break;
			case SDLK_a:
				desiredVelX += DOT_VEL;
				break;
			case SDLK_d:
				desiredVelX -= DOT_VEL;
				break;
			}
		}

		body->SetTransform(b2Vec2(position.x + desiredVelX, position.y + desiredVelY), body->GetAngle());
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
