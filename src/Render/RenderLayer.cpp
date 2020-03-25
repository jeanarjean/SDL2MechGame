#include "RenderLayer.h"
#include "../Utils/CoordTranslator.h"
#include "../Component/Animation.h"

namespace RenderLayer {
	void RenderGameObject(SDL_Renderer* gRenderer, Renderable& renderable, b2Vec2 positionWorld, const SDL_Rect& dest, float angle) {
		CoordTranslator* translator = CoordTranslator::instance();

		b2Vec2 pixelPosition = translator->coordWorldToPixels(positionWorld);
		SDL_Rect resize = { (int)(pixelPosition.x) - translator->scalarWorldToPixels(renderable.mWidth) / 2, (int)(pixelPosition.y) - translator->scalarWorldToPixels(renderable.mHeight) / 2, translator->scalarWorldToPixels(renderable.mWidth), translator->scalarWorldToPixels(renderable.mHeight) };

		SDL_RenderCopyEx(gRenderer, renderable.mTexture, &dest, &resize, 0.f, NULL, SDL_FLIP_NONE);
	}

	void RenderGameObject(SDL_Renderer* gRenderer, Renderable& renderable, b2Vec2 positionWorld, int dest, float angle)
	{
		CoordTranslator* translator = CoordTranslator::instance();

		b2Vec2 pixelPosition = translator->coordWorldToPixels(positionWorld);
		SDL_Rect resize = { (int)(pixelPosition.x) - translator->scalarWorldToPixels(renderable.mWidth) / 2, (int)(pixelPosition.y) - translator->scalarWorldToPixels(renderable.mHeight) / 2, translator->scalarWorldToPixels(renderable.mWidth), translator->scalarWorldToPixels(renderable.mHeight) };

		SDL_RenderCopyEx(gRenderer, renderable.mTexture, NULL, &resize, 0.f, NULL, SDL_FLIP_NONE);
	}

	SDL_Rect AdvanceFrame(Animation& animation)
	{
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

		return SDL_Rect{ frame.x, frame.y, frame.width, frame.height };
	}
}
