#pragma once
#include <SDL.h>
#include <entt/entt.hpp>
#include <Box2D/Box2D.h>

namespace AttackSystem
{
	class AttackSystem
	{
	public:
		AttackSystem() { lastShotBulletTick = 0; lastSwordSlashTick = 0; }
		void PlayerAttack(int currentTick, entt::registry& registry, b2World& world, SDL_Renderer* gRenderer);
	private:
		int lastShotBulletTick;
		int lastSwordSlashTick;
	};
}
