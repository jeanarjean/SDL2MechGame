#ifndef CONTACT_LISTENER_H
#define CONTACT_LISTENER_H
#include <Box2D/Box2D.h>
#include <entt/entt.hpp>

class ContactListener final : public b2ContactListener
{
public:
	ContactListener(entt::registry& registry) : registry(registry) {};


	void ContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
	void HandleEnemyCollisionWithBullet(entt::entity entity2, entt::entity entity1);
	void ContactListener::HandlePlayerCollisionWithEnemy(entt::entity entity1, entt::entity entity2);
private:
	entt::registry& registry;
};


#endif

