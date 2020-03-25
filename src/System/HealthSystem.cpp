#include "HealthSystem.h"
#include "../Component/Health.h"
namespace HealthSystem
{
	void ProcessHealth(entt::registry& registry, b2World& world, SDL_Renderer* gRenderer)
	{
		auto view = registry.view<Health, b2Body*>();

		for (auto entity : view) {
			auto& health = view.get<Health>(entity);
			auto& body = view.get<b2Body*>(entity);
			if (health.hitpoints < 1)
			{
				world.DestroyBody(body);
				if (registry.valid(entity))
				{
					registry.destroy(entity);
				}
			}
		}
	}

}