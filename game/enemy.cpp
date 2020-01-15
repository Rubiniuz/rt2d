#include "enemy.h"
#include "type_name.h"

using namespace std;

Enemy::Enemy() : Entity()
{
  int pixelsize = 4;
  mainsprite = new DynamicSprite("assets/error.tga", 1, 1, 16, 16, pixelsize);
  mainsprite->position = this->position;
  this->addChild(mainsprite);
  this->_width = mainsprite->width() * pixelsize;
  this->_height = mainsprite->height() * pixelsize;
}

Enemy::~Enemy()
{
  delete mainsprite;
  this->removeChild(mainsprite);
}

void Enemy::update(float deltaTime)
{

}
