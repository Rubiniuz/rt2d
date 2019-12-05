#include "scenemanager.h"

/* Null, because instance will be initialized on demand. */
Scenemanager* Scenemanager::instance = 0;

Scenemanager::Scenemanager()
{}

Scenemanager::~Scenemanager()
{}

void Scenemanager::AddScene(MyScene* toAdd)
{
	scenes.push_back(toAdd);
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

Scenemanager* Scenemanager::getInstance()
{
    if (Scenemanager::instance == 0)
    {
        Scenemanager::instance = new Scenemanager();
    }

    return Scenemanager::instance;
}
