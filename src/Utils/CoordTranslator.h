#ifndef COORD_TRANSLATOR_H
#define COORD_TRANSLATOR_H
#include <Box2D\Common\b2Math.h>

class CoordTranslator
{
	b2Vec2 resolution;
	static CoordTranslator* _instance;

public:
	b2Vec2 getResolution();
	void setResolution(b2Vec2 newResolution);
	static CoordTranslator* instance()
	{
		if (!_instance)
		{
			_instance = new CoordTranslator;
		}
		return _instance;
	}

	b2Vec2 coordWorldToPixels(b2Vec2 world);
	b2Vec2 coordWorldToPixels(float worldX, float worldY);
	float scalarWorldToPixels(float val);
	b2Vec2 coordPixelsToWorld(b2Vec2 screen);
	b2Vec2 coordPixelsToWorld(float pixelX, float pixelY);
	float scalarPixelsToWorld(float val);
	b2Vec2 scalarPixelsToWorld(b2Vec2 vector);
};

#endif
