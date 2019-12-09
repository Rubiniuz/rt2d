#ifndef ENEMY_H
#define ENEMY_H

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

  void UseSprite(std::string toGet);

private:

};

#endif /* ENEMY_H */
