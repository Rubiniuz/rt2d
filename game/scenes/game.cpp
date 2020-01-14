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
		this->addChild(layer);
    layers.push_back(layer);
	}
  AddEntities();
  MakeBackground();
  initialized = true;
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
  world = new World();
  layers[0]->addChild(world);
}

void Game::AddEntities()
{
  player = new Player();
  layers[1]->addChild(player);
  player->position = Point3(SWIDTH/2, SHEIGHT/2, 0);
  for (int i = 0; i < 1; i++) {
    Enemy* enemy = new Enemy();
    enemy->position = Point3((125 * i + 10), 50, 0);
    enemies.push_back(enemy);
    layers[1]->addChild(enemy);
    //enemy->TGA2PixelSprite();
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
  if (Singleton<Input>::instance()->getKey( KeyCode::Escape )) {
    this->stop();
  }
}
