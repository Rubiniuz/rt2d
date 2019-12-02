#include "titlescreen.h"

int TitleScreen::activescene = 0;

TitleScreen::TitleScreen() : MyScene()
{
  std::cout << "titlescreen constuctor" << std::endl;
  fpstimer.start();

  top_layer = 3; // 3 layers (0-2)

	for (unsigned int i = 0; i <= top_layer; i++) {
		Layer* layer = new Layer();
    layer->Init(8);
		layers.push_back(layer);
		this->addChild(layer);
	}

  MakeBackground();

  startbutton = new Button();
  startbutton->position = Point2(SWIDTH/2, SHEIGHT/2);
  layers[1]->addChild(startbutton);
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

void TitleScreen::MakeBackground()
{
  layers[0]->addSprite("assets/background.tga");
  layers[0]->position = Point2(SWIDTH/2, SHEIGHT/2);
  layers[0]->sprite()->color = WHITE;
  layers[0]->sprite()->spritescale = Point_t<float>(10.0f,10.0f,0.0f);
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
