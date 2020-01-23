#ifndef ENEMY_H
#define ENEMY_H

#include <rt2d/entity.h>
#include <rt2d/input.h>
#include <string>
#include <iostream>

#include "scenemanager.h"
#include "dynamicsprite.h"
#include "bullet.h"

class Enemy : public Entity
{
public:
  Enemy();
  Enemy(std::string tgafile);

  virtual ~Enemy();

  virtual void update(float deltaTime);

  void UseSprite(std::string toGet);

  void CheckSprite(Point2 b);

  DynamicSprite* mainsprite;

  int width() { return _width; };
  int height() { return _height; };

  std::vector<int> spritedata;

  void makesprite();

  void changeAngle(Point2 player);

  void shootBullet(Point2 player);

  int health;
  int pixelsdestroyed;
  int pixelstobedestroyed;

  Point2 target;

  Timer finder;
  Timer shoottimer;

  float timetofindplayer;

  float distance;

  float speed;

  Point2 dir;

  std::vector<Bullet*> bullets;

private:

  int gridwidth;
  int gridheight;
  int cellwidth;
  int cellheight;

  int _width;
  int _height;

};

#endif /* ENEMY_H */
