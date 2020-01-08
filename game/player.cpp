#include "player.h"

using namespace std;

Player::Player() : Entity()
{
  this->addSprite("assets/spaceship.tga");
  velocity = Vector2(0,0);
	polar = Polar((rand()%360) * DEG_TO_RAD, 400.0f);
  rotspeed = 3.14f;
  bulletSpeed = 500.0f;
}

Player::~Player()
{

}

void Player::update(float deltaTime)
{
  updateSpaceShip(deltaTime);
  ShootBullets();
  CheckBullets();
}

void Player::UseSprite(string toGet)
{
  this->addSprite(toGet);
}

void Player::updateSpaceShip(float deltaTime)
{
	this->UseSprite("assets/spaceship.tga");

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

  velocity.limit(400);

	this->rotation.z = polar.angle;
	this->position += velocity * deltaTime;
  Scenemanager::getInstance()->getCamera()->position += velocity * deltaTime;
}

void Player::ShootBullets()
{
  if (input()->getKeyDown( KeyCode::Space ))
  {
    Bullet* tempBullet = new Bullet();
    tempBullet->position = this->position;
    tempBullet->rotation = this->rotation;
    tempBullet->velocity = Vector2(cos(this->rotation.z),sin(this->rotation.z));
    tempBullet->velocity *= bulletSpeed * 2;
    this->playerBullets.push_back(tempBullet);
    Scenemanager::getInstance()->getCurrentScene()->layers[1]->addChild(tempBullet);
  }
}

void Player::CheckBullets()
{
  for (int i = this->playerBullets.size() - 1; i > 0; i--)
  {
    Bullet* tmp = this->playerBullets[i];
    if ( tmp->life.seconds() > 5.0f) { playerBullets.erase(playerBullets.begin()+i); Scenemanager::getInstance()->getCurrentScene()->layers[1]->removeChild(tmp); }
  }
}
