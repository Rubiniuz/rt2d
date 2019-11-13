/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"

MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	int entity = 0;

	do
	{ 
		this->addChild(createEntity(entity * 25, entity * 50));
		entity++;
	} while (entity <= 8);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(myentity);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myentity;
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	// ###############################################################
	// Spacebar scales myentity
	// ###############################################################
	if (input()->getKeyDown(KeyCode::Space)) {
		myentity->scale = Point(0.5f, 0.5f);
	}
	if (input()->getKeyUp(KeyCode::Space)) {
		myentity->scale = Point(1.0f, 1.0f);
	}

	// ###############################################################
	// Rotate color
	// ###############################################################
	if (t.seconds() > 0.0333f) {
		for (int i = 0; i <= 8; i++)
		{
			if (getChild(i))
			{

			}
			RGBAColor color = this->getChild(i)->sprite()->color;
			getChild(i)->sprite()->color = Color::rotate(color, 0.01f);
			t.start();
		}
	}
}

MyEntity* MyScene::createEntity(float x, float y)
{
	myentity = new MyEntity();
	myentity->position = Point2(x, y);
	if (myentity != nullptr){ return myentity; }
	else { return nullptr; }
}
