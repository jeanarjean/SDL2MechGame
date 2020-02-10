#include "BackgroundLoader.h"
#include "TextureUtils.h"
#include <Box2D\Common\b2Math.h>
#include "../Component/Background.h"
#include "CoordTranslator.h"

namespace BackgroundLoader {
	entt::entity LoadBackground(entt::registry& registry, SDL_Renderer* gRenderer)
	{
		auto entity = registry.create();
		CoordTranslator* translator = CoordTranslator::instance();
		b2Vec2 size = translator->getResolution();
		Renderable renderable{ NULL, 0, 0 };
		if (!LoadFromFile("../resources/background.png", gRenderer, renderable))
			printf("Failed to load dot texture!\n");
		registry.assign<Renderable>(entity, renderable);
		registry.assign<Background>(entity);
		return entity;
	}
}
