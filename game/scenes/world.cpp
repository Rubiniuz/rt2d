#include "world.h"

World::World() : Entity()
{
  std::cout << "World Constructor" << std::endl;
  gridwidth = 64;
	gridheight = 64;
	cellwidth = 32;
	cellheight = 32;

	RGBAColor wall       =		RGBAColor(0, 0, 0);
	RGBAColor top        =		RGBAColor(51, 51, 51);
	RGBAColor high       =	  RGBAColor(102, 102, 102);
	RGBAColor low        =		RGBAColor(153, 153, 153);
	RGBAColor bottom     =		RGBAColor(204, 204, 204);
	RGBAColor background =		RGBAColor(255, 255, 255);

	// fill field of tiles
	field = new Field();
	//field->addGrid(AUTOGENWHITE, 1, 1, gridwidth, gridheight, cellwidth, cellheight);
	field->addGrid("assets/worldtiles.tga", 8, 8, gridwidth, gridheight, cellwidth, cellheight);

	heightmapsprite = new Sprite();
	heightmapsprite->setupSpriteTGAPixelBuffer("assets/heightmap64.tga", 0, 2);
	PixelBuffer* heightmap = heightmapsprite->texture()->pixels();
	int w = heightmap->width;
	int h = heightmap->height;
  int counter = 0;
  int tcounter = 0;

	Point2 offset = Point2(-100,-100);
	for (int x = 0; x < w; x++) {
		for (int y = 0; y < h; y++) {
			Sprite* tile = field->spritebatch()[tcounter];
			unsigned char tint = heightmap->data[counter+3]; // alpha pixel

			if (tint == 255) { tile->color = background; }
      if (tint == 200) { tile->color = bottom; }
      if (tint == 150) { tile->color = low; }
      if (tint == 100) { tile->color = high; }
			if (tint == 50) { tile->color = top; }
			if (tint == 0) { tile->color = wall; }

      if (tint == 255) { tile->frame(0); }
      if (tint == 200) { tile->frame(1); }
      if (tint == 150) { tile->frame(2); }
      if (tint == 100) { tile->frame(3); }
			if (tint == 50)  { tile->frame(4); }
			if (tint == 0)   { tile->frame(5); }

      counter += heightmap->bitdepth;
			tcounter++;
		}
	}
	// add field_container to Scene
	this->addChild(field);
}


World::~World()
{
	this->removeChild(field);
	delete field;
	delete heightmapsprite;
}

void World::update(float deltaTime)
{

}
