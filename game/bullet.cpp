#include "bullet.h"

Bullet::Bullet() : Entity()
{
  this->addSpriteSheet("assets/bulletsheet.tga", 2, 2);
  this->sprite()->frame(0);
  t.start();
  life.start();
  this->_width = 8;
  this->_height = 4;
  this->scale = Point2(2,2);
}

Bullet::~Bullet()
{

}

void Bullet::update(float deltaTime)
{
  this->position += this->velocity * deltaTime * 5;
  int f = 0;
  if (f > 4) { f = 0; }

  if (t.seconds() > 0.25f) {
    f++;
    t.start();
  }
  this->sprite()->frame(f);
  this->worldposition((this->position + this->parent()->position));
  this->worldrotation((this->rotation + this->parent()->rotation));
}
