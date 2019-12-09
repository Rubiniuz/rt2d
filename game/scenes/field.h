#include <rt2d/entity.h>

class Field: public Entity
{
public:
	Field();
	virtual ~Field();

	virtual void update(float deltaTime);

};
