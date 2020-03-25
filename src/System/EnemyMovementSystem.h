#pragma once
#include <SDL.h>
#include <entt/entt.hpp>
#include <Box2D/Box2D.h>

namespace EnemyMovementSystem
{
	class EnemyMovementSystem
	{
		const int MOVEMENT_CHANGE_TICK_INTERVAL = 100;
	public:
		EnemyMovementSystem() { lastMovementChangeTick = -MOVEMENT_CHANGE_TICK_INTERVAL-1; }
		void EnemyMovementSystem::MoveEnemies(int currentTick, entt::registry& registry, b2World& world, SDL_Renderer* gRenderer);
	private:
		int lastMovementChangeTick;
	};
}