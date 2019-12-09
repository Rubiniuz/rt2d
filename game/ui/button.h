#ifndef BUTTON_H
#define BUTTON_H

#include <rt2d/entity.h>
#include <rt2d/input.h>
#include <string>
#include <iostream>

class Button : public Entity
{
public:
  Button();

  virtual ~Button();

  virtual void update(float deltaTime);

  void UseSprite(std::string toGet);

  bool CheckPressed();

private:

};

#endif /* BUTTON_H */
