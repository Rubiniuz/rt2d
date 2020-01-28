#include "explosion.h"

Explosion::Explosion() : Entity()
{

}

Explosion::Explosion(int size) : Entity()
{
  std::cout << "overloaded explosion constructor" << std::endl;
  this->addSpriteSheet("assets/explosionsheet.tga", 4, 4);
  this->sprite()->frame(0);
  this->sprite()->color = RED;
  currentframe = 0;
  t.start();
  this->scale = Point2(size,size);
}

Explosion::~Explosion()
{

}

void Explosion::update(float deltaTime)
{
  if (t.seconds() > 0.05f) {
    currentframe++;
    t.start();
  }
  this->sprite()->frame(currentframe);
}
