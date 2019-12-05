#ifndef GAME_H
#define GAME_H

#include <vector>
#include <rt2d/timer.h>
#include <rt2d/canvas.h>
#include <rt2d/vectorx.h>
#include <rt2d/texture.h>
#include <rt2d/input.h>

#include "../myscene.h"
#include "../layer.h"
#include "../ui/button.h"
#include "../ui/background.h"


class Game : public MyScene
{
public:
  Game(std::string name);

  virtual ~Game();

  virtual void update(float deltaTime);

  void MakeBackground();

  static int activescene;

  Input* input;

private:
  Background* background;

  Timer fpstimer;
};

#endif /* GAME_H */
