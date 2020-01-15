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
  for (int i = 0; i < 1; i++) {
    Enemy* enemy = new Enemy();
    enemy->position = Point3((125 * i + 10), 50, 0);
    enemies.push_back(enemy);
    layers[1]->addChild(enemy);
  }
  player = new Player();
  layers[1]->addChild(player);
  player->position = Point3(SWIDTH/2, SHEIGHT/2, 0);
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
  CheckEnemiesForPlayerBullets();
}

void Game::CheckEnemiesForPlayerBullets()
{
  for (int i = this->enemies.size() - 1; i >= 0; i--)
  {
    enemies[i]->position.x += 0.1;
    int enemywidth = enemies[i]->width();
    int enemyheight = enemies[i]->height();
    int left = enemies[i]->position.x - enemywidth/2;
    int right = enemies[i]->position.x + enemywidth/2;
    int top = enemies[i]->position.y - enemyheight/2;
    int bottom = enemies[i]->position.y + enemyheight/2;

    for (int j = player->playerBullets.size() - 1; j >= 0; j--)
    {
      if (player->playerBullets[j]->position.x > left && player->playerBullets[j]->position.x < right
        && player->playerBullets[j]->position.y > top && player->playerBullets[j]->position.y < bottom)
      {
        RGBAColor none = RGBAColor(0,0,0,0);
        enemies[i]->mainsprite->setPixel(i,j, none);
        player->playerBullets.erase(player->playerBullets.begin()+j);
        Scenemanager::getInstance()->getCurrentScene()->layers[1]->removeChild(player->playerBullets[j]);
      }
    }
  }
}
