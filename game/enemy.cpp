#include "enemy.h"
#include "type_name.h"

using namespace std;

Enemy::Enemy() : Entity()
{
  
}

Enemy::~Enemy()
{
  this->removeChild(field);
	delete field;
	delete heightmapsprite;
}

void Enemy::update(float deltaTime)
{

}
