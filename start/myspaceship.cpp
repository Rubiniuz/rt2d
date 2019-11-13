/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "myspaceship.h"

MySpaceShip::MySpaceShip() : Entity()
{
	this->addSprite("assets/spaceship.tga");
	this->sprite()->color = BLACK;
	this->sprite()->spritescale = Point3(3,3,3);
	this->input = new Input();
	this->vel = Vector2(0, 0);
	this->maxSpeed = 0.1;
}

MySpaceShip::~MySpaceShip()
{

}

void MySpaceShip::update(float deltaTime)
{
	this->mP = Vector2(input->getMouseX(), input->getMouseX());
	this->dir = mP -= pos;
	this->dir.normalize();
	this->dir *= maxSpeed;
	this->acc = dir;
	this->vel += acc;
	this->rotation.z = (atan2(vel.y, vel.x) * (180 / PI));
	this->vel.limit(maxSpeed);
	this->pos += vel;
	this->position.x = pos.x;
	this->position.y = pos.y;
}

void MySpaceShip::CheckInputs()
{

}

void MySpaceShip::MoveSpaceShip()
{

}
