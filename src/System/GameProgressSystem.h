#pragma once
#include <SDL.h>
#include <entt/entt.hpp>
#include <Box2D/Box2D.h>
#include <SDL_ttf.h>
#include <string>
#include "../Render/RenderLayer.h"
#include "../Component/Enemy.h"
#include "../Component/Player.h"

using namespace std;

namespace GameProgressSystem
{
	void ProcessGameState(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer, TTF_Font* font);
}