#pragma once
#include <SDL.h>
#include <entt/entt.hpp>
#include <Box2D\Dynamics\b2Body.h>
#include <SDL_ttf.h>
#include <string>
#include "../Component/Renderable.h"
#include "../Component/Animation.h"
#include "../Utils/CoordTranslator.h"
#include "../Component/Animation.h"

using namespace std;

namespace RenderLayer
{
	void RenderGameObject(SDL_Renderer* gRenderer, Renderable& renderable, b2Vec2 positionWorld, const SDL_Rect& dest, float angle = 0.f);
	void RenderGameObject(SDL_Renderer* gRenderer, Renderable& renderable, b2Vec2 positionWorld, int dest = NULL, float angle = 0.f);
	void RenderText(SDL_Renderer* gRenderer, SDL_Rect dest, TTF_Font* font, string text);
	SDL_Rect AdvanceFrame(Animation& animation);
}
