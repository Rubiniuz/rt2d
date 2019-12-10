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
	Cameramove(deltaTime);
}

void MyScene::Cameramove(float deltaTime)
{
	// ###############################################################
	// Move Camera (Arrow up, down, left, right)
	// ###############################################################
	float speed = 600.0f; // 600 units / second

	// Right and Down vector
	Point2 right = Point2(1, 0);
	Point2 up = Point2(0, 1);
	// Direction
	Vector2 direction = Vector2(0,0);

	if (input()->getKey(KeyCode::Up)) {
		direction -= up;
	}
	if (input()->getKey(KeyCode::Down)) {
		direction += up;
	}
	if (input()->getKey(KeyCode::Right)) {
		direction += right;
	}
	if (input()->getKey(KeyCode::Left)) {
		direction -= right;
	}
	direction.normalize();
	direction *= deltaTime * speed;
	camera()->position += direction;
}
