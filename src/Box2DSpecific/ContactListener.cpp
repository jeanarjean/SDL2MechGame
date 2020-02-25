#include "ContactListener.h"
#include <SDL_mixer.h>
#include "../Component/Player.h"
#include "../Component/Bullet.h"

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
		int asd = 2;

	}
	if (registry.valid(entity2) && registry.has<Bullet>(entity2))
	{
		Bullet bullet = registry.get<Bullet>(entity2);
		bullet.collisionCount++;
		registry.assign_or_replace<Bullet>(entity2, bullet);
	}


}
