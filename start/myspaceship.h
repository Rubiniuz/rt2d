/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef MYSPACESHIP_H
#define MYSPACESHIP_H

#include <C:\Users\Ruben Engelage\Desktop\School\RT2D\rt2d\rt2d\entity.h>

 /// @brief The MyEntity class is the Entity implementation.
class MySpaceShip : public Entity
{
public:
	/// @brief Constructor
	MySpaceShip();
	/// @brief Destructor
	virtual ~MySpaceShip();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	Input* input;

	Vector2 vel;
	Vector2 pos;
	Vector2 acc;
	Vector2 dir;
	Vector2 mP;
	
	double maxSpeed;

private:
	/* add your private declarations */
	void CheckInputs();
	void MoveSpaceShip();
};

#endif /* MYSPACESHIP_H */
