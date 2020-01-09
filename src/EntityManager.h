#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H
#include <deque>
#include <vector>

const unsigned ENTITY_INDEX_BITS = 22;
const unsigned ENTITY_INDEX_MASK = (1 << ENTITY_INDEX_BITS) - 1;
const unsigned ENTITY_GENERATION_BITS = 8;
const unsigned ENTITY_GENERATION_MASK = (1 << ENTITY_GENERATION_BITS) - 1;
const unsigned MINIMUM_FREE_INDICES = 1024;

struct Entity
{
	unsigned id;

	unsigned index() const { return id & ENTITY_INDEX_MASK; }
	unsigned generation() const { return (id >> ENTITY_INDEX_BITS)& ENTITY_GENERATION_MASK; }
};


using namespace std;

class EntityManager
{
	vector<uint8_t> _generation;
	deque<unsigned> _free_indices;

public:
	Entity create();

	bool alive(Entity e) const;

	void destroy(Entity e);
};

#endif
