#include "titlescreen.h"

int TitleScreen::activescene = 0;

TitleScreen::TitleScreen() : MyScene()
{
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
  startbutton->UseSprite("assets/startbutton.tga");
  layers[1]->canvas->addChild(startbutton);
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

void TitleScreen::MakeBackground()
{
  for (size_t i = 0; i < SHEIGHT; i++) {
    for (size_t j = 0; j < SWIDTH; j++) {
      layers[0]->canvas->setPixel(i, j, GREEN);
      layers[1]->canvas->setPixel(i, j, RED);
      layers[2]->canvas->setPixel(i, j, BLUE);
    }
  }
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
