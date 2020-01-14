#include "button.h"

using namespace std;

Button::Button(string sprite) : Entity()
{
  this->addSprite(sprite);
}

Button::~Button()
{

}

void Button::update(float deltaTime)
{
  Hover();
}

void Button::UseSprite(string toGet)
{
  this->addSprite(toGet);
}

void Button::Hover()
{
  int xpos = Singleton<Input>::instance()->getMouseX();
  int ypos = Singleton<Input>::instance()->getMouseY();
  if (ypos >= (this->position.y - ((this->sprite()->height() * this->scale.y) / 2)) && ypos <= (this->position.y + ((this->sprite()->height() * this->scale.y) / 2)) && xpos >= (this->position.x - ((this->sprite()->width() * this->scale.x) / 2)) && xpos <= (this->position.x + ((this->sprite()->width() * this->scale.x) / 2)))
  {
    this->sprite()->color = RGBAColor(255,255,255,204);
  }
  else{ this->sprite()->color = RGBAColor(255,255,255,255); }
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
