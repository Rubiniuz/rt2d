#ifndef BULLET_H
#define BULLET_H

#include <rt2d/entity.h>

class Bullet : public Entity
{
public:
  Bullet();
  ~Bullet();

  virtual void update(float deltaTime);

  Timer t;
  Timer life;

  Vector2 velocity;
  Polar polar;
};

#endif /* BULLET_H */
