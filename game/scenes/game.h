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
#include "../explosion.h"
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

  void SpawnWave();

  int score;

  std::vector<Text*> text;

  std::vector<Explosion*> explosions;

  std::vector<std::string> spritenames = { "assets/cruiser.tga" , "assets/fighter.tga" , "assets/carier.tga" };
  std::vector<Point2> spriteDimensions = { Point2(2,3) , Point2(3,3) , Point2(4,4)};
  int wavenumber;

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
