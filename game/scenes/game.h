#ifndef GAME_H
#define GAME_H

#include <vector>
#include <rt2d/timer.h>
#include <rt2d/vectorx.h>
#include <rt2d/texture.h>
#include <rt2d/input.h>

#include "../myscene.h"
#include "../layer.h"
#include "../ui/button.h"
#include "../ui/background.h"
#include "../enemy.h"
#include "../player.h"
#include "world.h"

class Game : public MyScene
{
public:
  Game(std::string name);

  virtual ~Game();

  virtual void update(float deltaTime);

  void MakeBackground();
  void AddEntities();

  static int activescene;

  Input* input;

  void CheckEnemiesForPlayerBullets();
  void CheckPlayerBullets();

private:
  Background* background;
  World* world;
  std::vector<Enemy*> enemies;
  Point3 PlayerMovement();
  Point3 GetPlayerRotation();
  Player* player;
  Timer fpstimer;
};

#endif /* GAME_H */
