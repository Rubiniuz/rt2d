/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>
#include <rt2d/canvas.h>
#include <rt2d/vectorx.h>
#include "layer.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	static int activescene;

protected:
	unsigned int top_layer;
	std::vector<Entity*> layers;
	void moveCamera(float deltaTime);

private:
	Timer fpstimer;
};

#endif /* SCENE00_H */