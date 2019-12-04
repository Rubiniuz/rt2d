#include "titlescreen.h"

int TitleScreen::activescene = 0;

TitleScreen::TitleScreen() : MyScene()
{
  std::cout << "titlescreen constuctor" << std::endl;
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
		std::stringstream fpstxt;
		fpstxt <<  "FPS: " << framecounter;
		framecounter = 0;
		fpstimer.start();
	}
	framecounter++;

	for (int i=0; i<buttonssize; i++) {
		Button* b = buttons[i];
    int xpos = Singleton<Input>::instance()->getMouseX();
    int ypos = Singleton<Input>::instance()->getMouseY();
    //std::cout << "Button: " << i << " pos: " << b->position.x << " , " << b->position.y << std::endl;
    //std::cout << "Mouse Position: " << xpos << " , " << ypos << std::endl;
    if (ypos >= (b->position.y - ((b->sprite()->height() * b->scale.y) / 2)) && ypos <= (b->position.y + ((b->sprite()->height() * b->scale.y) / 2)) && xpos >= (b->position.x - ((b->sprite()->width() * b->scale.x) / 2)) && xpos <= (b->position.x + ((b->sprite()->width() * b->scale.x) / 2)))
    {
      if (Singleton<Input>::instance()->getMouseDown(0) == true)
      {
        std::cout << "Button got pressed | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |" << std::endl;
        if (b == buttons[0]) { std::cout << "Going to Game" << std::endl; StartGame(); }
        if (b == buttons[1]) { std::cout << "Going to Credits" << std::endl; Credits(); }
        if (b == buttons[2]) { std::cout << "Exiting" << std::endl; Exit(); }
      }
    }
	}
}


/*bool CheckPressed()
{
  std::cout << "Mouse Position: " << Singleton<Input>::instance()->getMouseX() << " , " << Singleton<Input>::instance()->getMouseY() << std::endl;
  if (Singleton<Input>::instance()->getMouseX() >= this->position.x - (this->sprite()->width() / 2) && Singleton<Input>::instance()->getMouseX() <= this->position.x + (this->sprite()->width() / 2))
  {
    if (Singleton<Input>::instance()->getMouseY() > this->position.y - (this->sprite()->height() / 2) && Singleton<Input>::instance()->getMouseY() < this->position.y + (this->sprite()->height() / 2))
    {
      if (Singleton<Input>::instance()->getMouseDown(1) == true) {return true;}
      else{return false;}
    }
  }
  if (Singleton<Input>::instance()->getMouseY() > this->position.y - (this->sprite()->height() / 2) && Singleton<Input>::instance()->getMouseY() < this->position.y + (this->sprite()->height() / 2))
  {
    if (Singleton<Input>::instance()->getMouseX() >= this->position.x - (this->sprite()->width() / 2) && Singleton<Input>::instance()->getMouseX() <= this->position.x + (this->sprite()->width() / 2))
    {
      if (Singleton<Input>::instance()->getMouseDown(1) == true) {return true;}
      else{return false;}
    }
  }
  return false;
}*/

void TitleScreen::StartGame()
{

}

void TitleScreen::Credits()
{

}

void TitleScreen::Exit()
{

}
