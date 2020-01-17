#include "dynamicsprite.h"
#include "basic.h"

DynamicSprite::DynamicSprite() : Entity()
{

}

DynamicSprite::DynamicSprite(std::string tgafile, int width, int height, int tilewidth, int tileheight, int pixelsize)	: Entity()
{
	this->FromTGA(tgafile, width, height, tilewidth, tileheight, pixelsize);
}

DynamicSprite::~DynamicSprite()
{

}

void DynamicSprite::update(float deltaTime)
{
	worldposition((this->position + this->parent()->position));
  this->worldrotation((this->rotation + this->parent()->rotation));
}

void DynamicSprite::FromTGA(std::string tgafile, int width, int height, int tilewidth, int tileheight, int pixelsize)
{
	this->scale = Point2(pixelsize, pixelsize);
	sprite_container = new Basic();
	sprite_container->position = this->position;
	sprite_container->scale = this->scale;

	dynamic_sprite = new Sprite();
	dynamic_sprite->setupSpriteTGAPixelBuffer(tgafile, 0, 0);
	sprite_container->addSprite(dynamic_sprite);

	this->_width = width * tilewidth;
	this->_height = height * tileheight;

	// width, height, bitdepth, filter, wrap
	PixelBuffer tmp = PixelBuffer(this->width(), this->height(), 4, 0, 0);
	this->addDynamicSprite(&tmp);

	// get the pixels from the texture and make the framebuffer point to it
	this->_framebuffer = this->sprite()->texture()->pixels();

	for(int x = 0; x < this->width(); x++)
	{
		for(int y = 0; y < this->height(); y++)
		{
			this->_framebuffer->setPixel(x, y, sprite_container->sprite()->texture()->pixels()->getPixel(x,y));
		}
	}
}

void DynamicSprite::FromSpriteSheet(std::vector<int> data, std::string tgafile, int width, int height, int tilewidth, int tileheight, int pixelsize)
{
	this->scale = Point2(pixelsize, pixelsize);
	sprite_container = new Basic();
	sprite_container->position = this->position;
	sprite_container->scale = this->scale;

	dynamic_sprite = new Sprite();
	dynamic_sprite->setupSpriteTGAPixelBuffer(tgafile, 0, 0);
	sprite_container->addSprite(dynamic_sprite);

	this->_width = width * tilewidth;
	this->_height = height * tileheight;

	// width, height, bitdepth, filter, wrap
	PixelBuffer tmp = PixelBuffer(this->width(), this->height(), 4, 0, 0);
	this->addDynamicSprite(&tmp);

	// get the pixels from the texture and make the framebuffer point to it
	this->_framebuffer = this->sprite()->texture()->pixels();

	for (int i = 0; i < data.size(); i++)
	{
		for(int x = 0; x < this->width(); x++)
		{
			for(int y = 0; y < this->height(); y++)
			{
				this->_framebuffer->setPixel(x - (data[i] * tilewidth), y - (data[i] * tileheight), sprite_container->sprite()->texture()->pixels()->getPixel(x - (data[i] * tilewidth), y - (data[i] * tileheight)));
			}
		}
	}
}

void DynamicSprite::setPixel(int x, int y, RGBAColor color)
{
	this->_framebuffer->setPixel(x, y, color);
}

RGBAColor DynamicSprite::getPixel(int x, int y)
{
	return this->_framebuffer->getPixel(x, y);
}

void DynamicSprite::clearPixel(int x, int y)
{
	this->_framebuffer->setPixel(x, y, backgroundcolor);
}

void DynamicSprite::fill(RGBAColor color)
{
	// fill framebuffer with color
	for (long y=0; y<_framebuffer->height; y++) {
		for (long x=0; x<_framebuffer->width; x++) {
			this->setPixel(x, y, color);
		}
	}
}
