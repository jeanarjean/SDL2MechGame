#include "RenderSystem.h"
#include "../Component/Position.h"
#include "../Component/Renderable.h"
#include "../Component/Player.h"
#include <Eigen/Dense>

using namespace Eigen;

void Render(entt::registry& registry, SDL_Renderer* gRenderer)
{
	registry.view<Renderable, Position>().each([gRenderer](auto& renderable, auto& pos) {
		Vector2d horizontal(0, 1);
		int x, y;
		SDL_GetMouseState(&x, &y);
		Vector2d lineToMouse(x - pos.x, y - pos.y);

		double angle = acos(horizontal.dot(lineToMouse) / (horizontal.norm() * lineToMouse.norm())) / 0.0174533;
		angle -= 90;
		if (x > pos.x)
		{
			angle = -angle;
		}
		SDL_Rect resize = { (int) pos.x, (int) pos.y, 50, 50 };

		SDL_RenderCopyEx(gRenderer, renderable.mTexture, NULL, &resize, angle, NULL, SDL_FLIP_NONE);

		SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(gRenderer, pos.x, pos.y, x, y);
		});
}
