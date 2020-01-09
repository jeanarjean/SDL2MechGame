#include "EntityManager.h"
#include <assert.h>

Entity EntityManager::create() {
	unsigned idx;
	if (_free_indices.size() > MINIMUM_FREE_INDICES) {
		idx = _free_indices.front();
	}
	else {
		_generation.push_back(0);
		idx = _generation.size() - 1;
		assert(idx < (1 << ENTITY_INDEX_BITS));
	}
	return Entity{ (_generation[idx] << ENTITY_INDEX_BITS) | idx };
}

bool EntityManager::alive(Entity e) const
{
	if (e.index() > (uint8_t) _generation.size() - 1)
	{
		return false;
	}
	return _generation[e.index()] == e.generation();
}

void EntityManager::destroy(Entity e)
{
	const unsigned idx = e.index();
	++_generation[idx];
	_free_indices.push_back(idx);
}
