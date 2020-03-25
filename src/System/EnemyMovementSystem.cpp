#include "EnemyMovementSystem.h"
#include "../Component/Enemy.h"

namespace EnemyMovementSystem {

	void EnemyMovementSystem::MoveEnemies(int currentTick, entt::registry& registry, b2World& world, SDL_Renderer* gRenderer)
	{
		auto view = registry.view<Enemy, b2Body*>();

		if (lastMovementChangeTick + MOVEMENT_CHANGE_TICK_INTERVAL < currentTick)
		{
			lastMovementChangeTick = currentTick;
			for (auto entity : view) {
				auto& player = view.get<Enemy>(entity);
				auto& body = view.get<b2Body*>(entity);
				if (rand() % 2 == 0)
				{
					body->SetLinearVelocity(b2Vec2(20, 0));
				}
				else {
					body->SetLinearVelocity(b2Vec2(-20, 0));
				}
			}
		}
	}

}
