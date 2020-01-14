#ifndef LAYER_H
#define LAYER_H

#include <rt2d/entity.h>

class Layer : public Entity
{
public:
  Layer();
  virtual ~Layer();

  virtual void update(float deltaTime);
private:

};

#endif /* LAYER_H */
