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

bool Button::CheckPressed()
{
  int xpos = Singleton<Input>::instance()->getMouseX();
  int ypos = Singleton<Input>::instance()->getMouseY();
  if (ypos >= (this->position.y - ((this->sprite()->height() * this->scale.y) / 2)) && ypos <= (this->position.y + ((this->sprite()->height() * this->scale.y) / 2)) && xpos >= (this->position.x - ((this->sprite()->width() * this->scale.x) / 2)) && xpos <= (this->position.x + ((this->sprite()->width() * this->scale.x) / 2)))
  {
    if (Singleton<Input>::instance()->getMouseDown(0) == true) { return true; }
    else { return false; }
  }
  else { return false; }
}
