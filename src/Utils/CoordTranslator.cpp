#include "CoordTranslator.h"
const float WORLD_TO_PIXEL_RATIO = 10.0f;
const float PIXEL_TO_WORLD_RATIO = 0.1;

CoordTranslator* CoordTranslator::_instance;

b2Vec2 CoordTranslator::coordWorldToPixels(b2Vec2 world)
{
	return b2Vec2(world.x * WORLD_TO_PIXEL_RATIO, resolution.y - (world.y * WORLD_TO_PIXEL_RATIO));
}

b2Vec2 CoordTranslator::coordWorldToPixels(float worldX, float worldY)
{
	return b2Vec2(worldX * WORLD_TO_PIXEL_RATIO, resolution.y - (worldY * WORLD_TO_PIXEL_RATIO));
}

float CoordTranslator::scalarWorldToPixels(float val)
{
	return val * WORLD_TO_PIXEL_RATIO;
}

b2Vec2 CoordTranslator::scalarWorldToPixels(b2Vec2 vector)
{
	return b2Vec2(vector.x * WORLD_TO_PIXEL_RATIO, vector.y * WORLD_TO_PIXEL_RATIO);
}

b2Vec2 CoordTranslator::coordPixelsToWorld(b2Vec2 pixelScreenCoordinates)
{
	return b2Vec2(pixelScreenCoordinates.x / WORLD_TO_PIXEL_RATIO, (resolution.y - pixelScreenCoordinates.y) / WORLD_TO_PIXEL_RATIO);
}
b2Vec2 CoordTranslator::coordPixelsToWorld(float pixelX, float pixelY)
{
	return b2Vec2(pixelX / WORLD_TO_PIXEL_RATIO, (resolution.y - pixelY) / WORLD_TO_PIXEL_RATIO);
}

float CoordTranslator::scalarPixelsToWorld(float val)
{
	return val / WORLD_TO_PIXEL_RATIO;
}

b2Vec2 CoordTranslator::scalarPixelsToWorld(b2Vec2 vector)
{
	return b2Vec2(vector.x / WORLD_TO_PIXEL_RATIO, vector.y / WORLD_TO_PIXEL_RATIO);
}

b2Vec2 CoordTranslator::getResolution() {
	return resolution;
}

void CoordTranslator::setResolution(b2Vec2 newResolution) {
	resolution = newResolution;
}
