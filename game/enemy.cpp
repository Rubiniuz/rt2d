#include "enemy.h"

using namespace std;

Enemy::Enemy() : Entity()
{
  this->addSprite("assets/enemy.tga");
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
