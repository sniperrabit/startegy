#include "Entity.h"

std::vector<EntityCol> EntityCol::EntityColList;

class EntityCol
{
public:
	EntityCol();
	~EntityCol();
};

EntityCol::EntityCol() {
	this->EntityA = NULL;
	this->EntityB = NULL;
}



