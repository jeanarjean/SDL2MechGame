#include "CoordTranslator.h"
const int WORLD_TO_PIXEL_RATIO = 10;

b2Vec2 coordWorldToPixels(b2Vec2 world)
{
	return b2Vec2(world.x * WORLD_TO_PIXEL_RATIO, world.y * WORLD_TO_PIXEL_RATIO);
}


b2Vec2 coordWorldToPixels(float worldX, float worldY)
{
	return b2Vec2(worldX * WORLD_TO_PIXEL_RATIO, worldY * WORLD_TO_PIXEL_RATIO);
}

float scalarWorldToPixels(float val)
{
	return val * WORLD_TO_PIXEL_RATIO;
}

b2Vec2 coordPixelsToWorld(b2Vec2 screen)
{
	return b2Vec2(screen.x / WORLD_TO_PIXEL_RATIO, screen.y / WORLD_TO_PIXEL_RATIO);
}
b2Vec2 coordPixelsToWorld(float pixelX, float pixelY)
{
	return b2Vec2(pixelX / WORLD_TO_PIXEL_RATIO, pixelY / WORLD_TO_PIXEL_RATIO);
}


float scalarPixelsToWorld(float val)
{
	return val / WORLD_TO_PIXEL_RATIO;
}
