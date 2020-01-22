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
  for (int i = 0; i < 3; i++) {
    Enemy* enemy = new Enemy();
    enemy->position = Point3((350 * i + 250), 150, 0);
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
  CheckEnemiesForPlayerBullets(deltaTime);
  CheckPlayerBullets();
}
void Game::CheckPlayerBullets()
{
  for (int j = player->playerBullets.size() - 1; j >= 0; j--)
  {
    if (player->playerBullets[j]->life.seconds() > 5)
    {
      Scenemanager::getInstance()->getCurrentScene()->layers[1]->removeChild(player->playerBullets[j]);
      player->playerBullets.erase(player->playerBullets.begin()+j);
    }
  }
}

void Game::CheckEnemiesForPlayerBullets(float deltaTime)
{
  if (!this->enemies.empty())
  {
    for (int i = this->enemies.size() - 1; i >= 0; i--)
    {
      //enemies[i]->position.x += 1 * deltaTime;
      enemies[i]->rotation.z += 1.5 * deltaTime;
      if (enemies[i]->rotation.z > 6.3) {enemies[i]->rotation.z = 0 + (enemies[i]->rotation.z - 6.29);}

      int enemywidth = enemies[i]->width();
      int enemyheight = enemies[i]->height();

      int left = enemies[i]->position.x - enemywidth/2;
      int right = enemies[i]->position.x + enemywidth/2;
      int top = enemies[i]->position.y - enemyheight/2;
      int bottom = enemies[i]->position.y + enemyheight/2;

      RGBAColor none = RGBAColor(0,0,0,0);

      if (!player->playerBullets.empty())
      {
        for (int j = player->playerBullets.size() - 1; j >= 0; j--)
        {
          Point2 toUse = this->Rotate(player->playerBullets[j]->position, player->playerBullets[j]->rotation.z, enemies[i]->position);

          if (toUse.x > left && toUse.x < right
            && toUse.y > top && toUse.y < bottom)
          {
            Point2 toDestroy = Point2(0,0);
            //int ppuX = enemies[i]->mainsprite->width() / enemies[i]->width();
            //int ppuY = enemies[i]->mainsprite->height() / enemies[i]->height();

            if (toUse.x < right && toUse.x > enemies[i]->position.x){ toDestroy.x = (enemies[i]->mainsprite->width() / 2) + toUse.x; }
            if (toUse.x > left && toUse.x < enemies[i]->position.x){ toDestroy.x = (enemies[i]->mainsprite->width() / 2) - toUse.x; }

            if (toUse.y < bottom && toUse.y > enemies[i]->position.y){ toDestroy.y = (enemies[i]->mainsprite->height() / 2) + toUse.y; }
            if (toUse.y > top && toUse.y < enemies[i]->position.y){ toDestroy.y = (enemies[i]->mainsprite->height() / 2) - toUse.y; }

            std::cout << "----- HIT! -----" << std::endl;

            int _x = rand() % enemies[i]->mainsprite->width();
            int _y = rand() % enemies[i]->mainsprite->height();

            enemies[i]->mainsprite->setPixel(_x,_y, none);
            std::cout << "Destroyed Pixel: " << _x << " , " << _y << std::endl;
            Scenemanager::getInstance()->getCurrentScene()->layers[1]->removeChild(player->playerBullets[j]);
            player->playerBullets.erase(player->playerBullets.begin()+j);
          }
        }
      }
    }
  }
}

Point2 Game::Rotate(Point2 point, int angle, Point2 center_of_rotation)
{
  angle *= 57.295779513082320876798154814105;
  float sinus   = sin(angle);
  float cosinus = cos(angle);
  Point2 temp;

  point.x  = point.x - center_of_rotation.x;
  point.y  = point.y - center_of_rotation.y;
  temp.x = point.x * cosinus - point.y * sinus;
  temp.y = point.x * sinus   + point.y * cosinus;
  point.x  =  temp.x + center_of_rotation.x;
  point.y  =  temp.y + center_of_rotation.y;

  return point;
}
