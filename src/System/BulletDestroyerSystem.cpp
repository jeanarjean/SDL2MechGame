#include "BulletDestroyerSystem.h"
#include "../Component/Bullet.h"
namespace BulletDestroyerSystem
{
	void  ProcessBullets(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer)
	{
		auto view = registry.view<Bullet, b2Body*>();

		for (auto entity : view) {
			auto& bullet = view.get<Bullet>(entity);
			auto& body = view.get<b2Body*>(entity);
			if (bullet.collisionCount > 100)
			{
				world.DestroyBody(body);
				registry.destroy(entity);
			}
		}
	}

}