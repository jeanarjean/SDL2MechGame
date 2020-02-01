#include "InputHandler.h"
#include "../Component/Position.h"
#include "../Component/Renderable.h"
#include "../Component/Player.h"
#include <Eigen/Dense>
#include "../Utils//CoordTranslator.h"
#include <Box2D\Dynamics\b2Body.h>

void HandleInputs(entt::registry& registry, SDL_Event event)
{
	//SDL_Event previous_event()???
	registry.view<Player, b2Body*>().each([event](auto& player, auto* body) {
		//If a key was pressed
		b2Vec2 position = body->GetPosition();
		float desiredVelX = 0;
		float desiredVelY = 0;
		const float DOT_VEL = -1000.f;
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
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			b2Vec2 pixelPosition = coordWorldToPixels(body->GetPosition());
			int x, y;
			SDL_GetMouseState(&x, &y);
			b2Vec2 mousePositionPixel{ (float32) x, (float32) y };
			b2Vec2 forceToApply = (mousePositionPixel - pixelPosition);

			body->ApplyForceToCenter(b2Vec2(forceToApply.x * 1000.f, forceToApply.y * 1000.f), true);
		}

		body->ApplyForceToCenter(b2Vec2(desiredVelX, desiredVelY), true);
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
