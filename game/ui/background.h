#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <rt2d/entity.h>
#include <string>
#include <iostream>

class Background : public Entity
{
public:
  Background();

  virtual ~Background();

  virtual void update(float deltaTime);

  void UseSprite(std::string toGet);

private:

};

#endif /* BACKGROUND_H */
