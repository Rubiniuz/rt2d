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

	static Vector2 velocity = Vector2(0,0);
	static Polar polar = Polar((rand()%360) * DEG_TO_RAD, 400.0f);

	if (input()->getKey( KeyCode::W )) {
		this->UseSprite("assets/spaceship.tga");
		velocity += polar.cartesian() * deltaTime / 2; // thrust
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

  float coefficient = 0.5;
  Vector2 friction = velocity;
  friction /= -1;
  friction.normalize();
  friction *= coefficient;

  velocity += friction;

  if (this->position.x < 32){ this->position.x = 32; }
  if (this->position.x > 1984){ this->position.x = 1984; }
  if (this->position.y < 32){ this->position.y = 32; }
  if (this->position.y > 1984){ this->position.y = 1984; }

  if (Scenemanager::getInstance()->getCamera()->position.x < 32){ Scenemanager::getInstance()->getCamera()->position.x = 32; }
  if (Scenemanager::getInstance()->getCamera()->position.x > 1984){ Scenemanager::getInstance()->getCamera()->position.x = 1984; }
  if (Scenemanager::getInstance()->getCamera()->position.y < 32){ Scenemanager::getInstance()->getCamera()->position.y = 32; }
  if (Scenemanager::getInstance()->getCamera()->position.y > 1984){ Scenemanager::getInstance()->getCamera()->position.y = 1984; }

	this->rotation.z = polar.angle;
	this->position += velocity * deltaTime;
  Scenemanager::getInstance()->getCamera()->position += velocity * deltaTime;
}
