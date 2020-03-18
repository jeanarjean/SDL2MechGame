#include "MouseUtil.h"
#include "CoordTranslator.h"
#include <SDL2\SDL_mouse.h>

b2Vec2 MouseUtil::GetVectorBetweenPositionAndMouse(b2Vec2 position)
{
	CoordTranslator* translator = CoordTranslator::instance();
	// SET FORCE TO THE BULLET
	int x, y;
	SDL_GetMouseState(&x, &y);
	b2Vec2 mousePositionInGameWorldCoordinates = translator->coordPixelsToWorld(b2Vec2((float32)x, (float32)y));
	return mousePositionInGameWorldCoordinates - position;
}
