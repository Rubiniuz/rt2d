#include "myscene.h"

int MyScene::activescene = 0;

MyScene::MyScene(std::string name) : Scene()
{
	_myscenename = name;
	std::cout << "myscene constructor of: " << _myscenename << std::endl;
	fpstimer.start();

	top_layer = 3; // 8 layers (0-7)

	for (unsigned int i = 0; i <= top_layer; i++) {
		Layer* layer = new Layer();
    layer->Init(8);
		layers.push_back(layer);
		this->addChild(layer);
	}
}


MyScene::~MyScene()
{
	int ls = layers.size();
	for (int i=0; i<ls; i++) {
		this->removeChild(layers[i]);
		delete layers[i];
		layers[i] = nullptr;
	}
	layers.clear();
}

std::string MyScene::getMySceneName()
{
	return _myscenename;
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// show FPS
	// ###############################################################
	static int framecounter = 0;
	if (fpstimer.seconds() > 1.0f) {
		framecounter = 0;
		fpstimer.start();
	}
	framecounter++;
}
