#include "GameProgressSystem.h"

namespace GameProgressSystem
{
	void ProcessGameState(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, TTF_Font* font)
	{
		auto view = registry.view<Enemy>();
		if (view.size() < 1)
		{
			string youWinText = "YOU WIN";
			SDL_Rect dest = { 50, 50, 0, 0 };

			RenderLayer::RenderText(gRenderer, dest, font, youWinText);
		}
		auto view2 = registry.view<Player>();
		if (view2.size() < 1)
		{
			string youWinText = "YOU LOST";
			SDL_Rect dest = { 50, 50, 0, 0 };

			RenderLayer::RenderText(gRenderer, dest, font, youWinText);
		}
	}


}