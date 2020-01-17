#include "RenderSystem.h"
#include "../Component/Position.h"
#include "../Component/Renderable.h"
#include "../Component/Player.h"
#include "../Component/Floor.h"
#include <Eigen/Dense>
#include <Box2D\Dynamics\b2Body.h>

using namespace Eigen;

void Render(entt::registry& registry, SDL_Renderer* gRenderer)
{
	registry.view<Player, Renderable, Position, b2Body*>().each([gRenderer](auto& player, auto& renderable, auto& pos, auto* body) {
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
		b2Vec2 pixelPosition = coordWorldToPixels(body->GetPosition());
		//need to map to screen and decide the size of the world
		SDL_Rect resize = { (int)(pixelPosition.x), (int)(pixelPosition.y), 50, 50 };

		SDL_RenderCopyEx(gRenderer, renderable.mTexture, NULL, &resize, angle, NULL, SDL_FLIP_NONE);

		SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(gRenderer, pos.x, pos.y, x, y);
		});

	registry.view<Renderable, Floor, b2Body*>().each([gRenderer](auto& renderable, auto& floor, auto* body) {
		b2Vec2 pixelPosition = coordWorldToPixels(body->GetPosition());
		SDL_Rect resize = { (int)(pixelPosition.x), (int)(pixelPosition.y), scalarWorldToPixels(renderable.mWidth), scalarWorldToPixels(renderable.mWidth) };

		SDL_RenderCopyEx(gRenderer, renderable.mTexture, NULL, &resize, 0.f, NULL, SDL_FLIP_NONE);
		});
}
