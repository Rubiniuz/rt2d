#include "layer.h"

Layer::Layer() : Entity()
{

}

Layer::~Layer()
{

}

void Layer::update(float deltaTime)
{

}

void Layer::Init(int bitsize)
{
  canvas = new Canvas(bitsize);
  this->addChild(canvas);
}
