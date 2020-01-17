#include "enemy.h"
#include "type_name.h"

using namespace std;

Enemy::Enemy() : Entity()
{
  int pixelsize = 4;
  makesprite();
  //mainsprite = new DynamicSprite("assets/error.tga", 1, 1, 16, 16, pixelsize);
  mainsprite = new DynamicSprite();
<<<<<<< HEAD
  mainsprite->FromSpriteSheet(spritedata, "assets/error.tga", 3, 3, 16, 16, pixelsize);
=======
  mainsprite->FromSpriteSheet(spritedata, "assets/error.tga", 1, 1, 16, 16, pixelsize);
>>>>>>> e377159369763d6a87b0b477aaa44a3992c104de
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

void Enemy::makesprite()
{
  spritedata =
  {
    1, 0, 0,
    0, 1, 0,
    0, 0, 0
  };
}
