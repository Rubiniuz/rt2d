/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file menu.h
 *
 * @brief description of Menu behavior.
 */

#ifndef MENU_H
#define MENU_H

#include <rt2d/scene.h>

#include "canvas.h"

#include "myentity.h"

/// @brief The MyScene class is the Scene implementation.
class MyMenu : public Scene
{
public:
	/// @brief Constructor
	MyMenu();
	/// @brief Destructor
	virtual ~MyMenu();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	Canvas* canvas;
	PixelSprite player;

	void setupPlayer();

};

#endif /* MENU_H */
