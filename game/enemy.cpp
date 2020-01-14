#include "enemy.h"
#include "type_name.h"

using namespace std;

Enemy::Enemy() : Entity()
{
  mainsprite = new DynamicSprite();
  mainsprite->position = this->position;
  mainsprite->FromTGA("assets/error.tga", 4, 4, 4, 4, 16);
  this->addChild(mainsprite);
}

Enemy::~Enemy()
{
  delete mainsprite;
  this->removeChild(mainsprite);
}

void Enemy::update(float deltaTime)
{

}
