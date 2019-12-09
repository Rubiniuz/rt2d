#include "player.h"

using namespace std;

Player::Player() : Entity()
{
  this->addSprite("assets/spaceship.tga");
}

Player::~Player()
{

}

void Player::update(float deltaTime)
{

}

void Player::UseSprite(string toGet)
{
  this->addSprite(toGet);
}
