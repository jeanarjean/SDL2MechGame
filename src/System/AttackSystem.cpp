#include "AttackSystem.h"
#include  "../Enums/MovementEnum.h"
#include "../Component/Player.h"
#include "../Utils/BitMaskUtil.h"
#include "../Utils/MouseUtil.h"
#include <SDL_mixer.h>

namespace AttackSystem {
	void AttackSystem::PlayerAttack(int currentTick, entt::registry& registry, b2World& world, SDL_Renderer* gRenderer)
	{
		auto view = registry.view<Player, b2Body*>();

		for (auto entity : view) {
			auto& player = view.get<Player>(entity);
			auto& body = view.get<b2Body*>(entity);

			if (currentTick - lastSwordSlashTick > 20)
			{
				player.m_invincible = false;
				registry.assign_or_replace<Player>(entity, player);
			}

			if (BitMaskUtil::IsBitActive(player.m_controlState, MECH_SHOOT_BIT))
			{
				if (currentTick - lastShotBulletTick > 10)
				{
					lastShotBulletTick = currentTick;
					prefabsFactory->SpawnBullet(registry, world, gRenderer, body->GetPosition());
					Mix_Chunk* music = Mix_LoadWAV("../resources/GUN_SHOT.wav");
					Mix_PlayChannel(-1, music, 0);
				}
			}
			if (BitMaskUtil::IsBitActive(player.m_controlState, MECH_SWORD_BIT))
			{
				if (currentTick - lastSwordSlashTick > 40)
				{
					lastSwordSlashTick = currentTick;
					b2Vec2 forceToApply = MouseUtil::GetVectorBetweenPositionAndMouse(body->GetPosition());
					forceToApply.Normalize();
					body->ApplyForce(b2Vec2(forceToApply.x * 2000.f, forceToApply.y * 2000.f), body->GetWorldCenter(), true);
					player.m_invincible = true;
					registry.assign_or_replace<Player>(entity, player);
					Mix_Chunk* music = Mix_LoadWAV("../resources/swordsheet1.wav");
					Mix_PlayChannel(-1, music, 0);
				}
			}
		}
	}

	AttackSystem::~AttackSystem()
	{
		prefabsFactory = NULL;
	}
}

