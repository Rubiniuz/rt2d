#ifndef BUTTON_H
#define BUTTON_H

using namespace std;

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

  void UseSprite(string toGet);

private:

};

#endif /* BUTTON_H */
