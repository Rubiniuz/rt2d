#ifndef ENEMY_H
#define ENEMY_H

#include <rt2d/entity.h>
#include <rt2d/input.h>
#include <rt2d/canvas.h>
#include <rt2d/sprite.h>
#include <string>
#include <iostream>

#include "scenes/field.h"
#include "scenemanager.h"

class Enemy : public Entity
{
public:
  Enemy();

  virtual ~Enemy();

  virtual void update(float deltaTime);

  void UseSprite(std::string toGet);

  void TGA2PixelSprite();
  void TGA2Grid(std::string tiles, std::string tga);

  char enemySprite;

  PixelSprite mainsprite;

  Canvas* can;

private:
  // a field of tiles
  Field* field;
  Sprite* heightmapsprite;

  std::vector<char> cv;

  int gridwidth;
  int gridheight;
  int cellwidth;
  int cellheight;

};

#endif /* ENEMY_H */
