#ifndef PLAYER_H
#define PLAYER_H

#include <rt2d/entity.h>
#include <rt2d/input.h>
#include <string>
#include <iostream>

class Player : public Entity
{
public:
  Player();

  virtual ~Player();

  virtual void update(float deltaTime);

  void UseSprite(std::string toGet);

  void updateSpaceShip(float deltaTime);

  static Vector2 velocity;
  static Polar polar;

private:

};

#endif /* PLAYER_H */
