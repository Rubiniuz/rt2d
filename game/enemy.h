#ifndef ENEMY_H
#define ENEMY_H

#include <rt2d/entity.h>
#include <rt2d/input.h>
#include <rt2d/canvas.h>
#include <rt2d/sprite.h>
#include <string>
#include <iostream>

#include "scenemanager.h"

class Enemy : public Entity
{
public:
  Enemy();

  virtual ~Enemy();

  virtual void update(float deltaTime);

  void UseSprite(std::string toGet);

  void TGA2PixelSprite();

  char playerSprite;

  PixelSprite mainsprite;

  Canvas* can;

private:

};

#endif /* ENEMY_H */
