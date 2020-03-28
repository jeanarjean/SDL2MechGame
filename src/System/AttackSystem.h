#pragma once
#include <SDL.h>
#include <entt/entt.hpp>
#include <Box2D/Box2D.h>
#include  "../Utils/Factories/PrefabsFactory.h"

namespace AttackSystem
{
	class AttackSystem
	{
	public:
		AttackSystem(PrefabsFactory::PrefabsFactory* prefabsFactory) { lastShotBulletTick = 0; lastSwordSlashTick = 0;  AttackSystem::prefabsFactory = prefabsFactory;  }
		~AttackSystem();
		void PlayerAttack(int currentTick, entt::registry& registry, b2World& world, SDL_Renderer* gRenderer);
	private:
		int lastShotBulletTick;
		int lastSwordSlashTick;
		PrefabsFactory::PrefabsFactory* prefabsFactory;
	};
}
