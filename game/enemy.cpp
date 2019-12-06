#include "enemy.h"

Enemy::Enemy() : Entity()
{
  this->addSprite("assets/startbutton.tga");
}

Enemy::~Enemy()
{

}

void Enemy::update(float deltaTime)
{

}

void Enemy::UseSprite(string toGet)
{
  this->addSprite(toGet);
}
