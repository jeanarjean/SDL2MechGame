#include "InputHandler.h"
#include "../Component/Position.h"
#include "../Component/Player.h"
#include <Eigen/Dense>
#include "../Utils//CoordTranslator.h"
#include "../Enums/MovementEnum.h"

namespace InputHandler {

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
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				player.m_controlState |= MECH_SHOOT;

			}
			if (event.type == SDL_MOUSEBUTTONUP)
			{
				player.m_controlState &= ~MECH_SHOOT;

			}
		});
	}
}
