#pragma once

#include <SDL.h>
#include <entt/entt.hpp>
#include <Box2D\Dynamics\b2Body.h>
#include "../Component/Renderable.h"
#include "../Component/Animation.h"

namespace RenderLayer
{
	void RenderGameObject(SDL_Renderer* gRenderer, Renderable& renderable, b2Vec2 positionWorld, const SDL_Rect& dest, float angle = 0.f);
	void RenderGameObject(SDL_Renderer* gRenderer, Renderable& renderable, b2Vec2 positionWorld, int dest = NULL, float angle = 0.f);
	SDL_Rect AdvanceFrame(Animation& animation);
}
