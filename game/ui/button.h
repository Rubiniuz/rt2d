#ifndef BUTTON_H
#define BUTTON_H

#include <rt2d/entity.h>

class Button : public Entity
{
public:
  Button();
  
  virtual ~Button();

  virtual void update(float deltaTime);

private:

};

#endif /* BUTTON_H */
