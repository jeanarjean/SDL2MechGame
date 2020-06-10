#include "CoordTranslator.h"
const float VIEW_VERTICAL_SPAN = 15.f;


CoordTranslator* CoordTranslator::_instance;

b2Vec2 CoordTranslator::coordWorldToPixels(b2Vec2 world)
{
	float aspect = resolution.x / resolution.y;
	float viewHorizontalSpan = VIEW_VERTICAL_SPAN * aspect;

	float locationX = m_viewCenter.x - 0.5f * viewHorizontalSpan;
	float locationY = m_viewCenter.y - 0.5f * VIEW_VERTICAL_SPAN;

	float xf = (world.x - locationX) / viewHorizontalSpan;
	float yf = (world.y - locationY) / VIEW_VERTICAL_SPAN;

	return b2Vec2(xf * resolution.x, resolution.y - (yf * resolution.y));
}

float CoordTranslator::scalarWorldToPixels(float val)
{
	return val * resolution.y / VIEW_VERTICAL_SPAN;
}

b2Vec2 CoordTranslator::coordPixelsToWorld(b2Vec2 pixelScreenCoordinates)
{
	float aspect = resolution.x / resolution.y;
	float viewHorizontalSpan = VIEW_VERTICAL_SPAN * aspect;

	float locationX = m_viewCenter.x - 0.5f * viewHorizontalSpan;
	float locationY = m_viewCenter.y - 0.5f * VIEW_VERTICAL_SPAN;

	float xf = pixelScreenCoordinates.x / resolution.x;
	float yf = (resolution.y - pixelScreenCoordinates.y) / resolution.y;

	return b2Vec2(locationX + xf * viewHorizontalSpan, locationY + yf * VIEW_VERTICAL_SPAN);
}

float CoordTranslator::scalarPixelsToWorld(float val)
{
	return val * VIEW_VERTICAL_SPAN / resolution.y;
}

b2Vec2 CoordTranslator::scalarPixelsToWorld(b2Vec2 vector)
{
	return b2Vec2(vector.x * VIEW_VERTICAL_SPAN / resolution.y, vector.y * VIEW_VERTICAL_SPAN / resolution.y);
}

b2Vec2 CoordTranslator::getResolution() {
	return resolution;
}

void CoordTranslator::setResolution(b2Vec2 newResolution) {
	resolution = newResolution;
}
