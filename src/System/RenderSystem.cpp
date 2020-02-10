#include "RenderSystem.h"
#include "../Component/Position.h"
#include "../Component/BoundingBox.h"
#include "../Component/Renderable.h"
#include "../Component/Player.h"
#include "../Component/Platform.h"
#include "../Component/Dynamic.h"
#include "../Component/Background.h"
#include "../Utils//CoordTranslator.h"
#include <Eigen/Dense>
#include <Box2D\Dynamics\b2Body.h>

using namespace Eigen;

namespace Renderer
{
	void Render(entt::registry& registry, SDL_Renderer* gRenderer)
	{
		RenderBackground(registry, gRenderer);
		RenderBoundingBox(registry, gRenderer);
		RenderDynamicEntities(registry, gRenderer);

		registry.view<Renderable, Platform, b2Body*>().each([gRenderer](auto& renderable, auto& floor, auto* body) {
			CoordTranslator* translator = CoordTranslator::instance();
			b2Vec2 pixelPosition = translator->coordWorldToPixels(body->GetPosition());
			SDL_Rect resize = { (int)(pixelPosition.x) - translator->scalarWorldToPixels(renderable.mWidth) / 2, (int)(pixelPosition.y) - translator->scalarWorldToPixels(renderable.mHeight) / 2, translator->scalarWorldToPixels(renderable.mWidth), translator->scalarWorldToPixels(renderable.mHeight) };

			SDL_RenderCopyEx(gRenderer, renderable.mTexture, NULL, &resize, 0.f, NULL, SDL_FLIP_NONE);
			});
	}

	void RenderPlatforms(entt::registry& registry, SDL_Renderer* gRenderer)
	{
		registry.view<Renderable, Platform, b2Body*>().each([gRenderer](auto& renderable, auto& floor, auto* body) {
			CoordTranslator* translator = CoordTranslator::instance();
			b2Vec2 pixelPosition = translator->coordWorldToPixels(body->GetPosition());
			SDL_Rect resize = { (int)(pixelPosition.x) - translator->scalarWorldToPixels(renderable.mWidth) / 2, (int)(pixelPosition.y) - translator->scalarWorldToPixels(renderable.mHeight) / 2, translator->scalarWorldToPixels(renderable.mWidth), translator->scalarWorldToPixels(renderable.mHeight) };

			SDL_RenderCopyEx(gRenderer, renderable.mTexture, NULL, &resize, 0.f, NULL, SDL_FLIP_NONE);
			});
	}

	void RenderDynamicEntities(entt::registry& registry, SDL_Renderer* gRenderer)
	{
		registry.view<DynamicBody, Renderable, b2Body*>().each([gRenderer](auto& player, auto& renderable, auto* body) {
			CoordTranslator* translator = CoordTranslator::instance();
			b2Vec2 pixelPosition = translator->coordWorldToPixels(body->GetPosition());
			Vector2d horizontal(0, 1);
			int x, y;
			SDL_GetMouseState(&x, &y);
			Vector2d lineToMouse(x - pixelPosition.x, y - pixelPosition.y);

			double angle = acos(horizontal.dot(lineToMouse) / (horizontal.norm() * lineToMouse.norm())) / 0.0174533;
			angle -= 90;
			if (x > pixelPosition.x)
			{
				angle = -angle;
			}

			SDL_Rect resize = { (int)(pixelPosition.x) - translator->scalarWorldToPixels(renderable.mWidth) / 2, (int)(pixelPosition.y) - translator->scalarWorldToPixels(renderable.mHeight) / 2, translator->scalarWorldToPixels(renderable.mWidth), translator->scalarWorldToPixels(renderable.mHeight) };
			SDL_RenderCopyEx(gRenderer, renderable.mTexture, NULL, &resize, angle, NULL, SDL_FLIP_NONE);

			});

	}

	void RenderBackground(entt::registry& registry, SDL_Renderer* gRenderer)
	{
		registry.view<Renderable, Background>().each([gRenderer](auto& renderable, auto Background) {
			CoordTranslator* translator = CoordTranslator::instance();
			float arbitraryScalingFactor = 1;
			SDL_Rect resize = { 0, 0, renderable.mWidth * arbitraryScalingFactor, renderable.mHeight * arbitraryScalingFactor };
			SDL_RenderCopyEx(gRenderer, renderable.mTexture, NULL, &resize, 0.f, NULL, SDL_FLIP_NONE);
			});
	}

	void RenderBoundingBox(entt::registry& registry, SDL_Renderer* gRenderer)
	{
		registry.view<Renderable, BoundingBox, b2Body*>().each([gRenderer](auto& renderable, auto& boundingBox, auto* body) {
			CoordTranslator* translator = CoordTranslator::instance();
			b2Vec2 pixelPosition = translator->coordWorldToPixels(body->GetPosition());
			SDL_Rect resize = { (int)(pixelPosition.x) - translator->scalarWorldToPixels(renderable.mWidth) / 2, (int)(pixelPosition.y) - translator->scalarWorldToPixels(renderable.mHeight) / 2, translator->scalarWorldToPixels(renderable.mWidth), translator->scalarWorldToPixels(renderable.mHeight) };

			SDL_RenderCopyEx(gRenderer, renderable.mTexture, NULL, &resize, 0.f, NULL, SDL_FLIP_NONE);
			});
	}
}
