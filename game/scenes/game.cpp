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
  MakeBackground();
  AddEntities();
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
    enemy->position = Point3((350 * (i + 1)), 250 * (i + 1), 0);
    enemy->target = Point2((425 * (i + 1)), 350);
    enemy->timetofindplayer = 1.6 * (i + 1);
    enemy->speed = 15;
    enemies.push_back(enemy);
    layers[1]->addChild(enemy);
  }

  Enemy* speeder = new Enemy("assets/speeder.tga", 3, 3, 16, 16, 2);
  speeder->position = Point3((125 * 3.2), 650, 0);
  speeder->target = Point2((45 + 150), 870);
  speeder->timetofindplayer = 1.6 * 3;
  speeder->speed = 15;
  enemies.push_back(speeder);
  layers[1]->addChild(speeder);

  Enemy* carier = new Enemy("assets/carier.tga", 4, 4, 16, 16, 2);
  carier->position = Point3((270 + 170), 150, 0);
  carier->target = Point2((210 * 3.2), 287);
  carier->timetofindplayer = 1.6 * 2;
  carier->speed = 15;
  enemies.push_back(carier);
  layers[1]->addChild(carier);

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
  CheckPlayerForEnemyBullets();
  CheckBullets();
}
void Game::CheckBullets()
{
  for (int j = player->playerBullets.size() - 1; j >= 0; j--)
  {
    if (player->playerBullets[j]->life.seconds() > 5)
    {
      Scenemanager::getInstance()->getCurrentScene()->layers[1]->removeChild(player->playerBullets[j]);
      player->playerBullets.erase(player->playerBullets.begin()+j);
    }
  }
  for (int k = this->enemies.size() - 1; k >= 0; k--)
  {
    for (int l = enemies[k]->bullets.size() - 1; l >= 0; l--)
    {
      if (enemies[k]->bullets[l]->life.seconds() > 5)
      {
        Scenemanager::getInstance()->getCurrentScene()->layers[1]->removeChild(enemies[k]->bullets[l]);
        enemies[k]->bullets.erase(enemies[k]->bullets.begin()+l);
      }
    }
  }

}

void Game::CheckPlayerForEnemyBullets()
{
  for (int k = this->enemies.size() - 1; k >= 0; k--)
  {
    for (int l = enemies[k]->bullets.size() - 1; l >= 0; l--)
    {
      int xpos = enemies[k]->bullets[l]->position.x;
      int ypos = enemies[k]->bullets[l]->position.y;

      int left = player->position.x - player->sprite()->width()/2;
      int right = player->position.x + player->sprite()->width()/2;
      int top = player->position.y - player->sprite()->height()/2;
      int bottom = player->position.y + player->sprite()->height()/2;

      if (xpos > left && xpos < right && ypos > top && ypos < bottom)
      {
        Scenemanager::getInstance()->getCurrentScene()->layers[1]->removeChild(enemies[k]->bullets[l]);
        enemies[k]->bullets.erase(enemies[k]->bullets.begin()+l);
        player->playerLives--;
        if (player->playerLives <= 0) { Scenemanager::getInstance()->GoToScene("titlescreen"); }
      }

    }
  }
}

void Game::CheckEnemiesForPlayerBullets(float deltaTime)
{
  if (!this->enemies.empty())
  {
    for (int i = this->enemies.size() - 1; i >= 0; i--)
    {
      if (enemies[i]->rotation.z > 6.3) {enemies[i]->rotation.z = 0 + (enemies[i]->rotation.z - 6.29);}

      if (enemies[i]->finder.seconds() > enemies[i]->timetofindplayer * (1 + (enemies[i]->pixelsdestroyed / 100)))
      {
        enemies[i]->target = Point2(player->position.x, player->position.y);
        enemies[i]->finder.start();
        enemies[i]->changeAngle(player->position);
      }
      else{enemies[i]->changeAngle(player->position);}
      enemies[i]->shootBullet(player->position);

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

            int _x = rand() % enemies[i]->mainsprite->width();
            int _y = rand() % enemies[i]->mainsprite->height();

            if (enemies[i]->mainsprite->getPixel(_x,_y) != none) { enemies[i]->mainsprite->setPixel(_x,_y, none); enemies[i]->pixelsdestroyed ++; }
            if (enemies[i]->mainsprite->getPixel(_x +1,_y +1) != none) { enemies[i]->mainsprite->setPixel(_x +1,_y +1, none); enemies[i]->pixelsdestroyed ++; }
            if (enemies[i]->mainsprite->getPixel(_x,_y +1) != none) { enemies[i]->mainsprite->setPixel(_x,_y +1, none); enemies[i]->pixelsdestroyed ++; }
            if (enemies[i]->mainsprite->getPixel(_x +1,_y) != none) { enemies[i]->mainsprite->setPixel(_x +1,_y, none); enemies[i]->pixelsdestroyed ++; }

            if (enemies[i]->pixelsdestroyed > enemies[i]->pixelstobedestroyed)
            {
              Scenemanager::getInstance()->getCurrentScene()->layers[1]->removeChild(enemies[i]);
              enemies.erase(enemies.begin()+i);
            }
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
