#include "titlescreen.h"

int TitleScreen::activescene = 0;

TitleScreen::TitleScreen() : MyScene()
{
  std::cout << "titlescreen constuctor" << std::endl;
  fpstimer.start();

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
}
void TitleScreen::MakeButtons()
{
  startbutton = new Button();
  startbutton->position = Point2(SWIDTH/2, 400);
  startbutton->scale = Point3(3.0f, 3.0f, 0.0f);
  layers[1]->addChild(startbutton);

  creditsbutton = new Button();
  creditsbutton->position = Point2(SWIDTH/2, 460);
  creditsbutton->scale = Point3(3.0f, 3.0f, 0.0f);
  layers[1]->addChild(creditsbutton);

  exitbutton = new Button();
  exitbutton->position = Point2(SWIDTH/2, 520);
  exitbutton->scale = Point3(3.0f, 3.0f, 0.0f);
  layers[1]->addChild(exitbutton);

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
		std::stringstream fpstxt;
		fpstxt <<  "FPS: " << framecounter;
		framecounter = 0;
		fpstimer.start();
	}
	framecounter++;
}

void TitleScreen::StartGame()
{

}

void TitleScreen::Credits()
{

}

void TitleScreen::Exit()
{

}
