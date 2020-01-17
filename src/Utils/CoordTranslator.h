#include <Box2D\Common\b2Math.h>
#ifndef COORD_TRANSLATOR_H
#define COORD_TRANSLATOR_H

b2Vec2 coordWorldToPixels(b2Vec2 world);
b2Vec2 coordWorldToPixels(float worldX, float worldY);
float scalarWorldToPixels(float val);
b2Vec2 coordPixelsToWorld(b2Vec2 screen);
b2Vec2 coordPixelsToWorld(float pixelX, float pixelY);
float scalarPixelsToWorld(float val);
#endif
