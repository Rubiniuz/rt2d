#include "background.h"

using namespace std;

Background::Background() : Entity()
{
  this->addSprite("assets/background.tga");
}

Background::~Background()
{

}

void Background::update(float deltaTime)
{

}

void Background::UseSprite(string toGet)
{
  this->addSprite(toGet);
}
