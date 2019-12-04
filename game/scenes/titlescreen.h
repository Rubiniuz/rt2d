#ifndef TITLESCREEN_H
#define TITLESCREEN_H

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


class TitleScreen : public MyScene
{
public:
  TitleScreen();

  virtual ~TitleScreen();

  virtual void update(float deltaTime);

  void MakeBackground();
  void MakeButtons();

  static int activescene;

  Input* input;

private:
  Background* background;
  Button* startbutton;
  Button* creditsbutton;
  Button* exitbutton;

  std::vector<Button*> buttons;
  int buttonssize;

  Timer fpstimer;
};

#endif /* TITLESCREEN_H */
