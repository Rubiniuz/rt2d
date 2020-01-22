#ifndef PLAYER_H
#define PLAYER_H

#include <rt2d/entity.h>
#include <rt2d/input.h>
#include <string>
#include <iostream>

#include "scenemanager.h"
#include "bullet.h"

class Player : public Entity
{
public:
  Player();

  virtual ~Player();

  virtual void update(float deltaTime);

  void UseSprite(std::string toGet);

  void updateSpaceShip(float deltaTime);

  void ShootBullets();

  Vector2 velocity;
  Polar polar;
  float rotspeed;
  float bulletSpeed;

  Timer shoottimer;

  std::vector<Bullet*> playerBullets;

  int playerLives;

private:

};

#endif /* PLAYER_H */
