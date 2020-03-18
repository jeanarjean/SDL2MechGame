#include "ContactListener.h"
#include <SDL_mixer.h>
#include "../Component/Player.h"
#include "../Component/Bullet.h"
#include "../Component/Enemy.h"
#include "../Component/Health.h"

void ContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{
	//Mix_Music* music = Mix_LoadMUS("../resources/whilem.wav");
	//Mix_PlayMusic(music, -1);
	auto* ptrBody1 = contact->GetFixtureA()->GetBody();
	auto* ptrBody2 = contact->GetFixtureB()->GetBody();
	auto entity1 = (entt::entity) (std::uint32_t) (ptrBody1->GetUserData());
	auto entity2 = (entt::entity) (std::uint32_t) (ptrBody2->GetUserData());
	if (registry.valid(entity1) && registry.has<Bullet>(entity1))
	{
		// Handle Bullet state changes
		// TODO function this
		Bullet bullet = registry.get<Bullet>(entity1);
		bullet.collisionCount++;
		registry.assign_or_replace<Bullet>(entity1, bullet);


		if (registry.valid(entity2) && registry.has<Enemy>(entity2) && registry.has<Health>(entity2))
		{
			Health health = registry.get<Health>(entity2);
			health.hitpoints--;
			registry.assign_or_replace<Health>(entity2, health);

		}

	}
	if (registry.valid(entity2) && registry.has<Bullet>(entity2))
	{
		// Handle Bullet state changes
		// TODO function this
		Bullet bullet = registry.get<Bullet>(entity2);
		bullet.collisionCount++;
		registry.assign_or_replace<Bullet>(entity2, bullet);

		if (registry.valid(entity1) && registry.has<Enemy>(entity1) && registry.has<Health>(entity1))
		{
			Health health = registry.get<Health>(entity1);
			health.hitpoints--;
			registry.assign_or_replace<Health>(entity1, health);

		}
	}
}
