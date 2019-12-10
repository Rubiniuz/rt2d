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
  updateSpaceShip(deltaTime);
}

void Player::UseSprite(string toGet)
{
  this->addSprite(toGet);
}

void Player::updateSpaceShip(float deltaTime)
{
	this->UseSprite("assets/spaceship.tga");

	float rotspeed = 3.14f;

	static Vector2 velocity = Vector2((rand()%100)-50, (rand()%100)-50);
	static Polar polar = Polar((rand()%360) * DEG_TO_RAD, 400.0f);

	if (input()->getKey( KeyCode::W )) {
		this->UseSprite("assets/spaceship.tga");
		velocity += polar.cartesian() * deltaTime; // thrust
	}
  if (input()->getKey( KeyCode::S )) {
		this->UseSprite("assets/spaceship.tga");
		velocity -= polar.cartesian() * deltaTime / 2; // thrust backwards
	}
	if (input()->getKey( KeyCode::D )) {
		polar.angle += rotspeed * deltaTime; // rotate right
	}
	if (input()->getKey( KeyCode::A )) {
		polar.angle -= rotspeed * deltaTime; // rotate left
	}

	this->rotation.z = polar.angle;
	this->position += velocity * deltaTime;
}
