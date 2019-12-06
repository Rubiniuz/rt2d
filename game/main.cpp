/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @brief Description of My Awesome Game.
 *
 * @file main.cpp
 *
 * @mainpage My Awesome Game
 *
 * @section intro Introduction
 *
 * Detailed description of My Awesome Game.
 *
 * There's even a second paragraph.
 */
#include <rt2d/core.h>
#include "scenemanager.h"
#include "scenes/titlescreen.h"

using namespace std;

/// @brief main entry point
int main( void )
{
	// Core instance
	Core core;
	
	Scenemanager::getInstance()->AddScene(new TitleScreen("titlescreen"));
	Scenemanager::getInstance()->Init();

	int running = 1;
	while (running)
	{
		MyScene* scene = Scenemanager::getInstance()->ToRun();
		core.run(scene); // update and render the current scene
		core.showFrameRate(5); // show framerate in output every n seconds
		if (!scene->isRunning()) { running = 0; } // check status of Scene every frame
	}

	return 0;
}
