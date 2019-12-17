#include "titlescreen.h"

using namespace std;

int TitleScreen::activescene = 0;

TitleScreen::TitleScreen(std::string name) : MyScene("titlescreen")
{
  _myscenename = name;
  std::cout << "titlescreen constuctor of: " << _myscenename << std::endl;
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
  MakeButtons();
  initialized = true;
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
  startbutton = new Button("assets/startbutton.tga");
  startbutton->position = Point2(SWIDTH/2, 400);
  startbutton->scale = Point3(3.0f, 3.0f, 0.0f);
  buttons.push_back(startbutton);
  layers[1]->addChild(startbutton);

  creditsbutton = new Button("assets/creditsbutton.tga");
  creditsbutton->position = Point2(SWIDTH/2, 500);
  creditsbutton->scale = Point3(3.0f, 3.0f, 0.0f);
  buttons.push_back(creditsbutton);
  layers[1]->addChild(creditsbutton);

  exitbutton = new Button("assets/exitbutton.tga");
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
  gamename = new Background();
  gamename->position = Point2(SWIDTH/2, SHEIGHT/3);
  gamename->scale = Point3(1.5f, 1.5f, 0.0f);
  gamename->UseSprite("assets/titlename.tga");
  layers[0]->addChild(gamename);
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
      if (b == buttons[0]) { std::cout << "Going to Game" << std::endl; Scenemanager::getInstance()->GoToScene("game");}
      if (b == buttons[1]) { std::cout << "Going to Credits" << std::endl; Scenemanager::getInstance()->GoToScene("credits");  }
      if (b == buttons[2]) { std::cout << "Exiting" << std::endl; wtq = true;}
    }
	}
  if (Singleton<Input>::instance()->getKey( KeyCode::Escape )) {
    this->stop();
  }
}
