#include "InputHandler.h"
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
				switch (event.button.button)
				{
				case SDL_BUTTON_LEFT:
					player.m_controlState |= MECH_SHOOT;
					break;
				case SDL_BUTTON_RIGHT:
					player.m_controlState |= MECH_SWORD;
					break;
				}
			}
			if (event.type == SDL_MOUSEBUTTONUP)
			{
				switch (event.button.button)
				{
				case SDL_BUTTON_LEFT:
					player.m_controlState &= ~MECH_SHOOT;
					break;
				case SDL_BUTTON_RIGHT:
					player.m_controlState &= ~MECH_SWORD;
					break;
				}

			}
		});
	}
}
