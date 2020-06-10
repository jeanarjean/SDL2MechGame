#ifndef MOVEMENT_SYSTEM_H
#define MOVEMENT_SYSTEM_H
#include <SDL.h>
#include <entt/entt.hpp>
namespace MovementSystem {
	class MovementSystem {
	public:
		MovementSystem() { lastJumpTick = 0; }
		~MovementSystem();
		void MovePlayer(int currentTick, entt::registry& registry);
	private:
		int lastJumpTick;
	};
}
#endif
