#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <vector>
#include <rt2d/scene.h>
#include "myscene.h"

/// @brief The Scenemanager class is the Scene implementation.
class Scenemanager : public Scene
{
public:
	Scenemanager();
	~Scenemanager();

	virtual void update(float deltaTime);

	std::vector<MyScene*> scenes;
	MyScene* currentScene;
	int s;
	int scenecounter;

	MyScene* ToRun();

	void Init();

	void AddScene(MyScene* toAdd);
	//void RemoveScene(int toRemove);
	//int getVectorPosition(MyScene* toFind);

};

#endif /* SCENEMANAGER_H */
