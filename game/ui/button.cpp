#include "button.h"

using namespace std;

Button::Button() : Entity()
{
  this->addSprite("assets/startbutton.tga");
}

Button::~Button()
{

}

void Button::update(float deltaTime)
{

}

void Button::UseSprite(string toGet)
{
  this->addSprite(toGet);
}
