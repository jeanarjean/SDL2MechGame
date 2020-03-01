#include "RenderSystem.h"
#include "../Component/BoundingBox.h"
#include "../Component/Renderable.h"
#include "../Component/Player.h"
#include "../Component/Platform.h"
#include "../Component/Dynamic.h"
#include "../Component/Background.h"
#include "../Component/Frame.h"
#include "../Component/Animation.h"
#include "../Utils/TextureUtils.h"
#include "../Utils//CoordTranslator.h"
#include <Eigen/Dense>

using namespace Eigen;

namespace Renderer
{
	void Render(entt::registry& registry, SDL_Renderer* gRenderer)
	{
		RenderBackground(registry, gRenderer);
		RenderBoundingBox(registry, gRenderer);
		RenderDynamicEntities(registry, gRenderer);
		RenderPlayer(registry, gRenderer);

		registry.view<Renderable, Platform, b2Body*>().each([gRenderer](auto& renderable, auto& floor, auto* body) {
			CoordTranslator* translator = CoordTranslator::instance();
			b2Vec2 pixelPosition = translator->coordWorldToPixels(body->GetPosition());
			SDL_Rect resize = { (int)(pixelPosition.x) - translator->scalarWorldToPixels(renderable.mWidth) / 2, (int)(pixelPosition.y) - translator->scalarWorldToPixels(renderable.mHeight) / 2, translator->scalarWorldToPixels(renderable.mWidth), translator->scalarWorldToPixels(renderable.mHeight) };

			SDL_RenderCopyEx(gRenderer, renderable.mTexture, NULL, &resize, 0.f, NULL, SDL_FLIP_NONE);
			});
	}

	void RenderPlayer(entt::registry& registry, SDL_Renderer* gRenderer)
	{
		registry.view<Animation, Renderable, b2Body*, Player>().each([gRenderer](auto& animation, auto& renderable, auto* body, auto& player) {
			CoordTranslator* translator = CoordTranslator::instance();

			Frame frame = animation.frames[animation.currentFrame];

			Uint64 newTime = SDL_GetPerformanceCounter();
			if (frame.startTime == 0)
			{
				frame.startTime = newTime;
				animation.frames[animation.currentFrame] = frame;

			}
			else {
				Uint64 currentDuration = ((newTime - frame.startTime) * 1000) / SDL_GetPerformanceFrequency();
				if (frame.duration < currentDuration)
				{
					frame.startTime = 0;
					animation.frames[animation.currentFrame] = frame;
					animation.currentFrame++;
					animation.currentFrame = (animation.currentFrame) % animation.frames.size();
					frame = animation.frames[animation.currentFrame];
				}
			}
			int w = frame.width;
			int h = frame.height;
			int x = frame.x;
			int y = frame.y;


			const SDL_Rect dest = { x, y, w, h };
			b2Vec2 pixelPosition = translator->coordWorldToPixels(body->GetPosition());
			SDL_Rect resize = { (int)(pixelPosition.x) - translator->scalarWorldToPixels(renderable.mWidth) / 2, (int)(pixelPosition.y) - translator->scalarWorldToPixels(renderable.mHeight) / 2, translator->scalarWorldToPixels(renderable.mWidth), translator->scalarWorldToPixels(renderable.mHeight) };
			float angle = CalculateAngleToMouse(body->GetPosition());


			SDL_RenderCopyEx(gRenderer, renderable.mTexture, &dest, &resize, angle, NULL, SDL_FLIP_NONE);
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

			SDL_Rect resize = { (int)(pixelPosition.x) - translator->scalarWorldToPixels(renderable.mWidth) / 2, (int)(pixelPosition.y) - translator->scalarWorldToPixels(renderable.mHeight) / 2, translator->scalarWorldToPixels(renderable.mWidth), translator->scalarWorldToPixels(renderable.mHeight) };
			SDL_RenderCopyEx(gRenderer, renderable.mTexture, NULL, &resize, 0.f, NULL, SDL_FLIP_NONE);
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

	float CalculateAngleToMouse(b2Vec2 bodyPositionPhysicSystem)
	{
		CoordTranslator* translator = CoordTranslator::instance();

		b2Vec2 pixelPosition = translator->coordWorldToPixels(bodyPositionPhysicSystem);
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
		return angle;
	}
}
