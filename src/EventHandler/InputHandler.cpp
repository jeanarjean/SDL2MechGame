#include "InputHandler.h"
#include "../Component/Position.h"
#include "../Component/Renderable.h"
#include "../Component/Player.h"

void HandleInputs(entt::registry& registry, SDL_Event event)
{
	registry.view<Player, Renderable, Position>().each([](auto& player, auto& renderable, auto& pos) {
		////If a key was pressed
		//if (event.type == SDL_KEYDOWN)
		//{
		//	//Adjust the velocity
		//	switch (event.key.keysym.sym)
		//	{
		//	case SDLK_w:
		//		if (mVelY > MAXSPEED)
		//		{
		//			mVelY -= DOT_VEL;
		//		}
		//		break;
		//	case SDLK_s:
		//		mVelY += DOT_VEL;
		//		break;
		//	case SDLK_a:
		//		if (event.key.repeat == 0)
		//		{
		//			mVelX -= DOT_VEL;
		//		}
		//		break;
		//	case SDLK_d:
		//		if (event.key.repeat == 0)
		//		{
		//			mVelX += DOT_VEL;
		//		}
		//		break;
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
