#include "AttackSystem.h"
#include "../Component/Position.h"
#include "../Component/Player.h"
#include <Box2D\Dynamics\b2Body.h>
#include  "../Enums/MovementEnum.h"
#include  "../Utils/PrefabsFactory.h"

namespace AttackSystem {
	void AttackSystem::PlayerAttack(int currentTick, entt::registry& registry, b2World& world, SDL_Renderer* gRenderer)
	{
		auto view = registry.view<Player, b2Body*>();

		for (auto entity : view) {
			auto& player = view.get<Player>(entity);
			auto& body = view.get<b2Body*>(entity);
			if (((player.m_controlState) >> (MECH_SHOOT_BIT)) & 1)
			{
				if (currentTick - lastShotBulletTick > 10)
				{
					lastShotBulletTick = currentTick;
					PrefabsFactory::SpawnBullet(registry, world, gRenderer, body->GetPosition());
				}
			}
		}
	}

}
