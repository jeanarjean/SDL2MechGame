#ifndef COORD_TRANSLATOR_H
#define COORD_TRANSLATOR_H
#include <Box2D\Common\b2Math.h>

class CoordTranslator
{
	b2Vec2 resolution;
	static CoordTranslator* _instance;

public:
	b2Vec2 m_viewCenter;
	b2Vec2 getResolution();
	void setResolution(b2Vec2 newResolution);
	CoordTranslator() { m_viewCenter = b2Vec2{ 0.f, 0.f }; };
	static CoordTranslator* instance()
	{
		if (!_instance)
		{
			_instance = new CoordTranslator;
		}
		return _instance;
	}

	b2Vec2 coordWorldToPixels(b2Vec2 world);
	float scalarWorldToPixels(float val);
	b2Vec2 scalarWorldToPixels(b2Vec2 vector);
	b2Vec2 coordPixelsToWorld(b2Vec2 screen);
	float scalarPixelsToWorld(float val);
	b2Vec2 scalarPixelsToWorld(b2Vec2 vector);

};

#endif
