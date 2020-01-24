#ifndef GAME_H
#define GAME_H

#include <vector>
#include <rt2d/timer.h>
#include <rt2d/vectorx.h>
#include <rt2d/texture.h>
#include <rt2d/input.h>
#include <rt2d/text.h>

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

  void CheckEnemiesForPlayerBullets(float deltaTime);
  void CheckPlayerForEnemyBullets();
  void CheckBullets();
  Point2 Rotate(Point2 point, int angle, Point2 center_of_rotation);

  int score;

  std::vector<Text*> text;

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
