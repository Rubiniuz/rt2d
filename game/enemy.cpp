#include "enemy.h"
#include "type_name.h"

using namespace std;

Enemy::Enemy() : Entity()
{
  mainsprite = new DynamicSprite("assets/error.tga", 4, 4, 4, 4, 16);
  mainsprite->position = this->position;
  this->addChild(mainsprite);
  _width = mainsprite->width();
  _height = mainsprite->height();
}

Enemy::~Enemy()
{
  delete mainsprite;
  this->removeChild(mainsprite);
}

void Enemy::update(float deltaTime)
{

}
