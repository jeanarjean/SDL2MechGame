#include "RenderLayer.h"

#ifdef DRAWING_DEBUG 
#define D(x) (x)
#else 
#define D(x) do{}while(0)
#endif


namespace RenderLayer {
	void RenderGameObject(SDL_Renderer* gRenderer, Renderable& renderable, b2Vec2 positionWorld, const SDL_Rect& dest, float angle) {
		CoordTranslator* translator = CoordTranslator::instance();

		b2Vec2 pixelPosition = translator->coordWorldToPixels(positionWorld);
		//SDL_Rect resize = { (int)(pixelPosition.x) , (int)(pixelPosition.y), translator->scalarWorldToPixels(renderable.mWidth), translator->scalarWorldToPixels(renderable.mHeight) };
		SDL_Rect resize = { (int)(pixelPosition.x) - translator->scalarWorldToPixels(renderable.mWidth) / 2, (int)(pixelPosition.y) - translator->scalarWorldToPixels(renderable.mHeight) / 2, translator->scalarWorldToPixels(renderable.mWidth), translator->scalarWorldToPixels(renderable.mHeight) };

		SDL_RenderCopyEx(gRenderer, renderable.mTexture, &dest, &resize, 0.f, NULL, SDL_FLIP_NONE);
#ifdef DRAWING_DEBUG 
		SDL_RenderDrawRect(gRenderer, &resize);
#endif
	}

	void RenderBackground(SDL_Renderer* gRenderer, Renderable& renderable)
	{
		SDL_Rect resize = { 0, -800, 1600, 3200 };
		SDL_RenderCopyEx(gRenderer, renderable.mTexture, NULL, &resize, 0.f, NULL, SDL_FLIP_NONE);
	}

	void RenderGameObject(SDL_Renderer* gRenderer, Renderable& renderable, b2Vec2 positionWorld, int dest, float angle)
	{
		CoordTranslator* translator = CoordTranslator::instance();

		b2Vec2 pixelPosition = translator->coordWorldToPixels(positionWorld);
		//SDL_Rect resize = { (int)(pixelPosition.x), (int)(pixelPosition.y), translator->scalarWorldToPixels(renderable.mWidth), translator->scalarWorldToPixels(renderable.mHeight) };
		SDL_Rect resize = { (int)(pixelPosition.x) - translator->scalarWorldToPixels(renderable.mWidth) / 2, (int)(pixelPosition.y) - translator->scalarWorldToPixels(renderable.mHeight) / 2, translator->scalarWorldToPixels(renderable.mWidth), translator->scalarWorldToPixels(renderable.mHeight) };

		SDL_RenderCopyEx(gRenderer, renderable.mTexture, NULL, &resize, 0.f, NULL, SDL_FLIP_NONE);
#ifdef DRAWING_DEBUG 
		SDL_RenderDrawRect(gRenderer, &resize);
#endif
	}

	void DebugRenderCollisionObject(SDL_Renderer* gRenderer, b2Vec2 higherBound, b2Vec2 lowerBound)
	{
		CoordTranslator* translator = CoordTranslator::instance();

		b2Vec2 higherBoundPix = translator->coordWorldToPixels(higherBound);
		b2Vec2 lowerBoundPix = translator->coordWorldToPixels(lowerBound);
		SDL_Rect resize = { lowerBoundPix.x, lowerBoundPix.y, higherBoundPix.x - lowerBoundPix.x, higherBoundPix.y - lowerBoundPix.y };

		SDL_RenderDrawRect(gRenderer, &resize);
	}

	void RenderText(SDL_Renderer* gRenderer, SDL_Rect dest, TTF_Font* font, string text)
	{
		SDL_Color fg = { 255, 255, 255 };
		SDL_Surface* surf = TTF_RenderText_Solid(font, text.c_str(), fg);

		dest.w = surf->w;
		dest.h = surf->h;

		SDL_Texture* tex = SDL_CreateTextureFromSurface(gRenderer, surf);

		SDL_RenderCopy(gRenderer, tex, NULL, &dest);
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
