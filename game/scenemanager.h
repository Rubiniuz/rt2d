#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <vector>
#include "myscene.h"

/// @brief The Scenemanager class is the Scene implementation.
class Scenemanager
{
public:

	Scenemanager();

	~Scenemanager();

	std::vector<MyScene*> scenes;
	MyScene* currentScene;
	std::string currenSceneName;

	MyScene* ToRun();

	void Init();

	void AddScene(MyScene* toAdd);
	//void RemoveScene(std::string toRemove);
	//int getVectorPosition(MyScene* toFind);

	std::vector<MyScene*> getScenes();

	void setSceneToGo(MyScene* scene);

	static Scenemanager* getInstance();

	Camera* getCamera();

	MyScene* getCurrentScene();

	std::vector<std::string> scenenames;
	std::vector<std::string> getSceneNames();
	void GoToScene(std::string name);

	MyScene* scenetogo;

private:

	static Scenemanager* instance;

};

#endif /* SCENEMANAGER_H */
