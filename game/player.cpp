#include "player.h"

using namespace std;

Player::Player() : Entity()
{
  playerLives = 10;
  this->addSprite("assets/spaceship.tga");
  this->scale = Point2(2,2);
  velocity = Vector2(0,0);
	polar = Polar((rand()%360) * DEG_TO_RAD, 400.0f);
  rotspeed = 3.0f;
  bulletSpeed = 500.0f;
  shoottimer.start();
  boosttimer.start();
}

Player::~Player()
{

}

void Player::update(float deltaTime)
{
  updateSpaceShip(deltaTime);
  ShootBullets();
}

void Player::UseSprite(string toGet)
{
  this->addSprite(toGet);
}

void Player::updateSpaceShip(float deltaTime)
{
	this->UseSprite("assets/spaceship.tga");

	if (input()->getKey( KeyCode::W )) {
		velocity += (polar.cartesian() * deltaTime) * 2.5; // thrust
    this->UseSprite("assets/spaceship-thrusting.tga");
	}
  if (input()->getKey( KeyCode::S )) {
		velocity -= (polar.cartesian() * deltaTime) * 2.5; // thrust backwards
    this->UseSprite("assets/spaceship-braking.tga");
	}
  if (input()->getKey( KeyCode::LeftShift )) {
    this->UseSprite("assets/spaceship-boosting.tga");
    if (shoottimer.seconds() >= 1)
    {
	    velocity += polar.cartesian() * 2.5; // boost
      shoottimer.start();
    }
	}
	if (input()->getKey( KeyCode::D )) {
		polar.angle += rotspeed * deltaTime; // rotate right
    this->UseSprite("assets/spaceship-right.tga");
	}
	if (input()->getKey( KeyCode::A )) {
		polar.angle -= rotspeed * deltaTime; // rotate left
    this->UseSprite("assets/spaceship-left.tga");
	}

  float coefficient = 0.5;
  Vector2 friction = velocity;
  friction /= -1;
  friction.normalize();
  friction *= coefficient;

  if (velocity >= Vector2(10,10))  { velocity += friction; }

  if (this->position.x < 128){ this->position.x = 130; }
  if (this->position.x > 3904){ this->position.x = 3902; }
  if (this->position.y < 128){ this->position.y = 130; }
  if (this->position.y > 3904){ this->position.y = 3902; }

  if (Scenemanager::getInstance()->getCamera()->position.x < 128){ Scenemanager::getInstance()->getCamera()->position.x = 130; }
  if (Scenemanager::getInstance()->getCamera()->position.x > 3904){ Scenemanager::getInstance()->getCamera()->position.x = 3902; }
  if (Scenemanager::getInstance()->getCamera()->position.y < 128){ Scenemanager::getInstance()->getCamera()->position.y = 130; }
  if (Scenemanager::getInstance()->getCamera()->position.y > 3904){ Scenemanager::getInstance()->getCamera()->position.y = 3902; }

  velocity.limit(1000);

	this->rotation.z = polar.angle;
	this->position += velocity * deltaTime;
  Scenemanager::getInstance()->getCamera()->position += velocity * deltaTime;
}

void Player::ShootBullets()
{
  if (input()->getKey( KeyCode::Space ))
  {
    if (this->shoottimer.seconds() >= 0.125)
    {
      Bullet* tempBullet = new Bullet();
      tempBullet->position = this->position;
      tempBullet->rotation = this->rotation;
      tempBullet->velocity = Vector2(cos(this->rotation.z),sin(this->rotation.z));
      tempBullet->velocity *= bulletSpeed * 2;
      this->playerBullets.push_back(tempBullet);
      Scenemanager::getInstance()->getCurrentScene()->layers[1]->addChild(tempBullet);
      this->shoottimer.start();
    }
  }
}
