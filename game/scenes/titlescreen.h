#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include <vector>
#include <rt2d/timer.h>
#include <rt2d/canvas.h>
#include <rt2d/vectorx.h>
#include <rt2d/texture.h>

#include "../myscene.h"
#include "../layer.h"
#include "../ui/button.h"
#include "../ui/background.h"


class TitleScreen : public MyScene
{
public:
  TitleScreen();

  virtual ~TitleScreen();

  virtual void update(float deltaTime);

  void MakeBackground();
  void MakeButtons();

  void StartGame();
  void Credits();
  void Exit();

  static int activescene;

private:
  Background* background;
  Button* startbutton;
  Button* creditsbutton;
  Button* exitbutton;

  Timer fpstimer;
};

#endif /* TITLESCREEN_H */
