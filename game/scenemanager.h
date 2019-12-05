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
	int s;
	int scenecounter;

	MyScene* ToRun();

	void Init();

	void AddScene(MyScene* toAdd);
	//void RemoveScene(int toRemove);
	//int getVectorPosition(MyScene* toFind);

	static Scenemanager* getInstance();


private:

	static Scenemanager* instance;

};

#endif /* SCENEMANAGER_H */
