#ifndef WORLD_H
#define WORLD_H

#include <rt2d/entity.h>
#include "field.h"

class World: public Entity
{
public:
	World();
	virtual ~World();

	virtual void update(float deltaTime);

private:
	// a field of tiles
	Field* field;
	Sprite* heightmapsprite;

	int gridwidth;
	int gridheight;
	int cellwidth;
	int cellheight;
};

#endif /* WORLD_H */
