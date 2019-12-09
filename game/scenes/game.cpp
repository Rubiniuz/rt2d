#include "game.h"

int Game::activescene = 0;

Game::Game(std::string name) : MyScene("game")
{
  _myscenename = name;
  std::cout << "game constuctor of: " << _myscenename << std::endl;
  wtq = false;
  fpstimer.start();

  //input = new Input();

  top_layer = 3; // 3 layers (0-2)

	for (unsigned int i = 0; i <= top_layer; i++) {
		Layer* layer = new Layer();
    layer->Init(1);
		this->addChild(layer);
    layers.push_back(layer);
	}
  AddEntities();
  MakeBackground();
}

Game::~Game()
{
  int ls = layers.size();
	for (int i=0; i<ls; i++) {
		this->removeChild(layers[i]);
		delete layers[i];
		layers[i] = nullptr;
	}
	layers.clear();
}

void Game::MakeBackground()
{
  /*background = new Background();
  background->position = Point2(SWIDTH/2, SHEIGHT/2);
  background->scale = Point3(3.0f, 3.0f, 0.0f);
  layers[0]->addChild(background);
  */
  world = new World();
  layers[0]->addChild(world);
}

void Game::AddEntities()
{
  player = new Player();
  layers[1]->addChild(player);
  player->position = Point3(SWIDTH/2, SHEIGHT/2, 0);
  for (int i = 0; i < 5; i++) {
    Enemy* enemy = new Enemy();
    enemy->position = Point3((125 * i + 100), 500, 0);
    enemies.push_back(enemy);
    layers[1]->addChild(enemies[i]);
  }
}

void Game::update(float deltaTime)
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
