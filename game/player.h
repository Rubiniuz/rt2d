#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

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

  void UseSprite(string toGet);

private:

};

#endif /* PLAYER_H */
