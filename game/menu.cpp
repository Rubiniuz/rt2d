/**
 * This class describes Menu behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "menu.h"

MyMenu::MyMenu() : Scene()
{

}


MyMenu::~MyMenu()
{

}

void MyMenu::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
}
