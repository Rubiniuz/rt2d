#include "titlescreen.h"

int TitleScreen::activescene = 0;

TitleScreen::TitleScreen(std::string name) : MyScene("titlescreen")
{
  _myscenename = name;
  std::cout << "titlescreen constuctor of: " << _myscenename << std::endl;
  fpstimer.start();

  //input = new Input();

  top_layer = 3; // 3 layers (0-2)

	for (unsigned int i = 0; i <= top_layer; i++) {
		Layer* layer = new Layer();
		this->addChild(layer);
    layers.push_back(layer);
	}

  MakeBackground();
  MakeButtons();
}

TitleScreen::~TitleScreen()
{
  int ls = layers.size();
	for (int i=0; i<ls; i++) {
		this->removeChild(layers[i]);
		delete layers[i];
		layers[i] = nullptr;
	}
	layers.clear();
  delete input;
}
void TitleScreen::MakeButtons()
{
  startbutton = new Button();
  startbutton->position = Point2(SWIDTH/2, 400);
  startbutton->scale = Point3(3.0f, 3.0f, 0.0f);
  buttons.push_back(startbutton);
  layers[1]->addChild(startbutton);

  creditsbutton = new Button();
  creditsbutton->position = Point2(SWIDTH/2, 500);
  creditsbutton->scale = Point3(3.0f, 3.0f, 0.0f);
  buttons.push_back(creditsbutton);
  layers[1]->addChild(creditsbutton);

  exitbutton = new Button();
  exitbutton->position = Point2(SWIDTH/2, 600);
  exitbutton->scale = Point3(3.0f, 3.0f, 0.0f);
  buttons.push_back(exitbutton);
  layers[1]->addChild(exitbutton);

  buttonssize = buttons.size();
}

void TitleScreen::MakeBackground()
{
  background = new Background();
  background->position = Point2(SWIDTH/2, SHEIGHT/2);
  background->scale = Point3(3.0f, 3.0f, 0.0f);
  layers[0]->addChild(background);
}

void TitleScreen::update(float deltaTime)
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

	for (int i=0; i<buttonssize; i++) {
		Button* b = buttons[i];
    if (b->CheckPressed())
    {
      std::cout << "Button got pressed!" << std::endl;
      if (b == buttons[0]) { std::cout << "Going to Game" << std::endl; activescene = 1; }
      if (b == buttons[1]) { std::cout << "Going to Credits" << std::endl; activescene = 2; }
      if (b == buttons[2]) { std::cout << "Exiting" << std::endl; }
    }
	}
}
