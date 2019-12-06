#ifndef ENEMY_H
#define ENEMY_H

using namespace std;

#include <rt2d/entity.h>
#include <rt2d/input.h>
#include <string>
#include <iostream>

class Enemy : public Entity
{
public:
  Enemy();

  virtual ~Enemy();

  virtual void update(float deltaTime);

  void UseSprite(string toGet);

private:

};

#endif /* ENEMY_H */
