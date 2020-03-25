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
	HandleEnemyCollisionWithBullet(entity1, entity2);
	HandleEnemyCollisionWithBullet(entity2, entity1);
	HandlePlayerCollisionWithEnemy(entity1, entity2);
	HandlePlayerCollisionWithEnemy(entity2, entity1);
}

void ContactListener::HandlePlayerCollisionWithEnemy(entt::entity entity1, entt::entity entity2)
{
	if (registry.valid(entity1) && registry.has<Player>(entity1) && registry.has<Health>(entity1))
	{
		if (registry.valid(entity2) && registry.has<Enemy>(entity2))
		{
			Player player = registry.get<Player>(entity1);
			if (!player.invincible)
			{
				Health health = registry.get<Health>(entity1);
				health.hitpoints--;
				registry.assign_or_replace<Health>(entity1, health);
			}
			else
			{
				Health health = registry.get<Health>(entity2);
				health.hitpoints--;
				registry.assign_or_replace<Health>(entity2, health);
			}
		}
	}
}

void ContactListener::HandleEnemyCollisionWithBullet(entt::entity entity1, entt::entity entity2)
{
	if (registry.valid(entity1) && registry.has<Bullet>(entity1))
	{
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
}
