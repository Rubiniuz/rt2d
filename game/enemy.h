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

  void CheckSprite(Point2 b);

  DynamicSprite* mainsprite;

  int width() { return _width; };
  int height() { return _height; };

  std::vector<int> spritedata;

  void makesprite();

  int health;
  int pixelsdestroyed;
  int pixelstobedestroyed;

  Point2 target;

  Timer finder;

  float timetofindplayer;

  float speed;

private:

  int gridwidth;
  int gridheight;
  int cellwidth;
  int cellheight;

  int _width;
  int _height;

};

#endif /* ENEMY_H */
