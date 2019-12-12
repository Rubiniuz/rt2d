#include "world.h"

World::World() : Entity()
{
  std::cout << "World Constructor" << std::endl;
  gridwidth = 64;
	gridheight = 64;
	cellwidth = 32;
	cellheight = 32;

	RGBAColor wall       =		RGBAColor(255, 255, 255);

	// fill field of tiles
	field = new Field();
	//field->addGrid(AUTOGENWHITE, 1, 1, gridwidth, gridheight, cellwidth, cellheight);
	field->addGrid("assets/worldtiles.tga", 8, 8, gridwidth, gridheight, cellwidth, cellheight);

	heightmapsprite = new Sprite();
	heightmapsprite->setupSpriteTGAPixelBuffer("assets/colormap64.tga", 0, 2);
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
      unsigned char tintR = heightmap->data[counter]; // alpha pixel
      unsigned char tintG = heightmap->data[counter+1]; // alpha pixel
      unsigned char tintB = heightmap->data[counter+2]; // alpha pixel

      if (tint == 0) { tile->color = wall; } // empty
      if (tint == 0) { tile->frame(0); } // empty
      if (tint == 255) { tile->color = wall; } // border
      if (tint == 255) { tile->frame(1); } // border

      if (tintR == 51)   { tile->color = wall; } //
      if (tintR == 51)   { tile->frame(2); } //
      if (tintR == 102)   { tile->color = wall; } //
      if (tintR == 102)   { tile->frame(3); } //
      if (tintR == 153)   { tile->color = wall; } //
      if (tintR == 153)   { tile->frame(4); } //
      if (tintR == 204)   { tile->color = wall; } //
      if (tintR == 204)   { tile->frame(5); } //

      if (tintG == 51)   { tile->color = wall; } //
      if (tintG == 51)   { tile->frame(6); } //
      if (tintR == 102)   { tile->color = wall; } //
      if (tintG == 102)   { tile->frame(7); } //
      if (tintG == 153)   { tile->color = wall; } //
      if (tintG == 153)   { tile->frame(8); } //
      if (tintG == 204)   { tile->color = wall; } //
      if (tintG == 204)   { tile->frame(9); } //

      if (tintB == 51)   { tile->color = wall; } //
      if (tintB == 51)   { tile->frame(10); } //
      if (tintB == 102)   { tile->color = wall; } //
      if (tintB == 102)   { tile->frame(11); } //
      if (tintB == 153)   { tile->color = wall; } //
      if (tintB == 153)   { tile->frame(12); } //
      if (tintB == 204)   { tile->color = wall; } //
      if (tintB == 204)   { tile->frame(13); } //

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
