#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <rt2d/entity.h>
#include <rt2d/sprite.h>

class Explosion: public Entity
{
public:

  Explosion(int size);
  virtual ~Explosion();

  virtual void update(float deltaTime);

  int currentframe;

private:

  Explosion();

  Timer t;

};

#endif /* EXPLOSION_H */
