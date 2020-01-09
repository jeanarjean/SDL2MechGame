#include "RenderSystem.h"

void Render(entt::registry& registry, SDL_Renderer* gRenderer)
{
	registry.view<position>().each([gRenderer](auto& pos) {
		// gets all the components of the view at once ...

		//pos.x += vel.dx * dt;
		//pos.y += vel.dy * dt;
		const SDL_Rect rect = { pos.x, pos.y, 20, 20 };

		SDL_RenderDrawRect(gRenderer, &rect);

		// ...
		});
}
