#include "bullet.h"

Bullet::Bullet() : Entity()
{
  this->addSpriteSheet("assets/bulletsheet.tga", 4, 4);
  this->sprite()->frame(0);
  t.start();
  life.start();
}

Bullet::~Bullet()
{

}

void Bullet::update(float deltaTime)
{
  this->position += this->velocity * deltaTime;
  static int f = 0;
  if (f > 4) { f = 0; }

  this->sprite()->frame(f);
  if (t.seconds() > 0.05f) {
    f++;
    t.start();
  }
}
