#include "scenemanager.h"

using namespace std;

Scenemanager* Scenemanager::instance = 0;

// to call scenemanager use Scenemanager::getInstance()->

Scenemanager::Scenemanager()
{}

Scenemanager::~Scenemanager()
{}

void Scenemanager::AddScene(MyScene* toAdd)
{
	scenes.push_back(toAdd);
	std::string scenename = toAdd->getMySceneName();
	scenenames.push_back(scenename);
}

void Scenemanager::Init()
{
	currentScene = scenes[0];
	currenSceneName = currentScene->getMySceneName();
	scenetogo = currentScene;
	std::cout << "Scenemanager Init()" << std::endl;
}

MyScene* Scenemanager::ToRun()
{
	if (scenetogo != nullptr)
	{
		if (currentScene->getMySceneName() != scenetogo->getMySceneName())
		{
			currentScene = scenetogo;
		}
	}
	return currentScene;
}

std::vector<MyScene*> Scenemanager::getScenes()
{
	return scenes;
}
void Scenemanager::setSceneToGo(MyScene* scene)
{
	scenetogo = scene;
}
std::vector<std::string> Scenemanager::getSceneNames()
{
	return scenenames;
}

void Scenemanager::GoToScene(std::string name)
{
	std::vector<MyScene*> list = Scenemanager::getInstance()->getScenes();
	std::vector<std::string> names = Scenemanager::getInstance()->getSceneNames();
	MyScene* togo = nullptr;
	for (int i = 0; i < names.size(); i++) {
		if (names[i] == name)
		{
			togo = list[i];
			Scenemanager::getInstance()->setSceneToGo(togo);
		}
	}
}

Scenemanager* Scenemanager::getInstance()
{
  if (Scenemanager::instance == 0)
  {
      Scenemanager::instance = new Scenemanager();
  }
  return Scenemanager::instance;
}

Camera* Scenemanager::getCamera()
{
	return currentScene->camera();
}

MyScene* Scenemanager::getCurrentScene()
{
	return currentScene;
}
