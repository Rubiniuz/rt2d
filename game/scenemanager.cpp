#include "scenemanager.h"

Scenemanager::Scenemanager() : Entity()
{
	std::cout << "Scenemanager Constructor" << std::endl;
}

Scenemanager::~Scenemanager()
{
	std::cout << "Scenemanager DeConstructor" << std::endl;
}

void Scenemanager::update(float deltaTime)
{

}

void Scenemanager::AddScene(MyScene* toAdd)
{
	scenes.push_back(toAdd);
	this->addChild(toAdd);
	s = scenes.size();
}
void Scenemanager::Init()
{
	currentScene = scenes[0];
	scenecounter = 0;
	std::cout << "Scenemanager Init()" << std::endl;
}

MyScene* Scenemanager::ToRun()
{
	scenecounter = currentScene->activescene;
	//if (scenecounter > s-1) { scenecounter = 0; currentScene->activescene = 0; }
	//if (scenecounter < 0) { scenecounter = s-1; currentScene->activescene = s-1; }
	currentScene = scenes[scenecounter];
	return currentScene;
}
