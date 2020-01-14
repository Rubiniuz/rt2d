#include "dynamicsprite.h"
#include "basic.h"

DynamicSprite::DynamicSprite() : Entity()
{
	
}

DynamicSprite::DynamicSprite(int width, int height, int pixelsize)	: Entity()
{
	this->init(width, height, pixelsize);
}

DynamicSprite::~DynamicSprite()
{

}

void DynamicSprite::update(float deltaTime)
{

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

	// width, height, bitdepth, filter, wrap
	PixelBuffer tmp = PixelBuffer(width*tilewidth, height*tileheight, 4, 0, 0);
	this->addDynamicSprite(&tmp);

	// get the pixels from the texture and make the framebuffer point to it
	this->_framebuffer = this->sprite()->texture()->pixels();

	this->_width = width*tilewidth;
	this->_height = height*tileheight;

	for(int x = 0; x < (width * tilewidth); x++)
	{
		for(int y = 0; y < (height * tileheight); y++)
		{
			this->_framebuffer->setPixel(x, y, sprite_container->sprite()->texture()->pixels()->getPixel(x,y));
		}
	}

}

void DynamicSprite::init(int width, int height, int pixelsize)
{
	this->scale = Point2(pixelsize, pixelsize);
	// width, height, bitdepth, filter, wrap
	PixelBuffer tmp = PixelBuffer(width, height, 4, 0, 0);
	this->addDynamicSprite(&tmp);

	// get the pixels from the texture and make the framebuffer point to it
	this->_framebuffer = this->sprite()->texture()->pixels();

	this->_width = width;
	this->_height = height;

	backgroundcolor = RGBAColor(255, 255, 255, 255);
	this->fill(backgroundcolor);
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
