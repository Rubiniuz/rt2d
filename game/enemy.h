#ifndef ENEMY_H
#define ENEMY_H

#include <rt2d/entity.h>
#include <rt2d/input.h>
#include <string>
#include <iostream>

#include "scenemanager.h"
#include "dynamicsprite.h"

class Enemy : public Entity
{
public:
  Enemy();

  virtual ~Enemy();

  virtual void update(float deltaTime);

  void UseSprite(std::string toGet);

  DynamicSprite* mainsprite;

private:

  int gridwidth;
  int gridheight;
  int cellwidth;
  int cellheight;

};

#endif /* ENEMY_H */
