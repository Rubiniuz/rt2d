#include "enemy.h"
#include "type_name.h"

using namespace std;

Enemy::Enemy() : Entity()
{
  //this->addSprite("assets/enemy.tga");
  //TGA2Grid("assets/enemytiles.tga","assets/enemycolormap.tga");
  Master2Grid();
}

Enemy::~Enemy()
{
  this->removeChild(field);
	delete field;
	delete heightmapsprite;
}

void Enemy::update(float deltaTime)
{

}

void Enemy::UseSprite(string toGet)
{
  this->addSprite(toGet);
}

void Enemy::Master2Grid()
{
  std::cout << "master to grid" << std::endl;
  gridwidth = 6;
	gridheight = 3;
	cellwidth = 16;
	cellheight = 16;

	RGBAColor wall       =		RGBAColor(255, 255, 255);

  // fill field of tiles
  field = new Field();
  //field->addGrid(AUTOGENWHITE, 1, 1, gridwidth, gridheight, cellwidth, cellheight);
  field->addGrid("assets/testtiles.tga", 4, 4, gridwidth, gridheight, cellwidth, cellheight);

  heightmapsprite = new Sprite();
  heightmapsprite->setupSpriteTGAPixelBuffer("assets/maptotiles.tga", 0, 2);
  PixelBuffer* heightmap = heightmapsprite->texture()->pixels();
  int w = heightmap->width;
  int h = heightmap->height;
  int counter = 0;
  int tcounter = 0;

  for (int x = 0; x < w; x++) {
    for (int y = 0; y < h; y++) {
      Sprite* tile = field->spritebatch()[tcounter];
      unsigned char tint = heightmap->data[counter+3]; // alpha pixel
      unsigned char tintR = heightmap->data[counter]; // alpha pixel
      unsigned char tintG = heightmap->data[counter+1]; // alpha pixel
      unsigned char tintB = heightmap->data[counter+2]; // alpha pixel

      std::cout << "X=========================================X" << std::endl;
      std::cout << "| * " << "Tile Number: " << tcounter << std::endl;
      std::cout << "| * " << "Alpha: " << (int)tint << std::endl;
      std::cout << "| * " <<  "Red: " << (int)tintR << std::endl;
      std::cout << "| * " <<  "Green: " << (int)tintG << std::endl;
      std::cout << "| * " <<  "Blue: " << (int)tintB << std::endl;
      std::cout << "X=========================================X" << std::endl;
      std::cout << " " << std::endl;

      tile->color = wall;

      if (tint == 0) { tile->frame(0); } // empty
      if (tint == 255 && tintR == 255 && tintG == 255 && tintB == 255) { tile->frame(0); }

      if (tint == 255 && tintR == 255 && tintG == 230 && tintB == 230) { tile->frame(2); }
      if (tint == 255 && tintR == 255 && tintG == 204 && tintB == 204) { tile->frame(3); }
      if (tint == 255 && tintR == 255 && tintG == 180 && tintB == 180) { tile->frame(4); }
      if (tint == 255 && tintR == 255 && tintG == 153 && tintB == 153) { tile->frame(5); }
      if (tint == 255 && tintR == 255 && tintG == 130 && tintB == 130) { tile->frame(6); }
      if (tint == 255 && tintR == 255 && tintG == 102 && tintB == 102) { tile->frame(7); }
      if (tint == 255 && tintR == 255 && tintG == 80 && tintB == 80)   { tile->frame(8); }
      if (tint == 255 && tintR == 255 && tintG == 51 && tintB == 51)   { tile->frame(9); }
      if (tint == 255 && tintR == 255 && tintG == 30 && tintB == 30)   { tile->frame(10); }

      if (tint == 255 && tintR == 255 && tintG == 0 && tintB == 0)   { tile->frame(1); }
      if (tintR == 255 && tint == 225) { tile->frame(2); }
      if (tintR == 255 && tint == 204) { tile->frame(3); }
      if (tintR == 255 && tint == 175) { tile->frame(4); }
      if (tintR == 255 && tint == 153) { tile->frame(5); }
      if (tintR == 255 && tint == 125) { tile->frame(6); }
      if (tintR == 255 && tint == 102) { tile->frame(7); }
      if (tintR == 255 && tint == 75) { tile->frame(8); }
      if (tintR == 255 && tint == 51) { tile->frame(9); }
      if (tintR == 255 && tint == 25) { tile->frame(10); }

      if (tint == 255 && tintR == 230 && tintG == 255 && tintB == 230) { tile->frame(0); }
      if (tint == 255 && tintR == 204 && tintG == 255 && tintB == 204) { tile->frame(0); }
      if (tint == 255 && tintR == 180 && tintG == 255 && tintB == 180) { tile->frame(0); }
      if (tint == 255 && tintR == 153 && tintG == 255 && tintB == 153) { tile->frame(0); }
      if (tint == 255 && tintR == 130 && tintG == 255 && tintB == 130) { tile->frame(0); }
      if (tint == 255 && tintR == 102 && tintG == 255 && tintB == 102) { tile->frame(0); }
      if (tint == 255 && tintR == 80 && tintG == 255 && tintB == 80)   { tile->frame(13); }
      if (tint == 255 && tintR == 51 && tintG == 255 && tintB == 51)   { tile->frame(11); }
      if (tint == 255 && tintR == 30 && tintG == 255 && tintB == 30)   { tile->frame(12); }

      if (tint == 255 && tintR == 0 && tintG == 255 && tintB == 0)   { tile->frame(12); }
      if (tintG == 255 && tint == 225) { tile->frame(11); }
      if (tintG == 255 && tint == 204) { tile->frame(13); }
      if (tintG == 255 && tint == 175) { tile->frame(0); }
      if (tintG == 255 && tint == 153) { tile->frame(0); }
      if (tintG == 255 && tint == 125) { tile->frame(0); }
      if (tintG == 255 && tint == 102) { tile->frame(0); }
      if (tintG == 255 && tint == 75) { tile->frame(0); }
      if (tintG == 255 && tint == 51) { tile->frame(0); }
      if (tintG == 255 && tint == 25) { tile->frame(0); }

      if (tint == 255 && tintR == 230 && tintG == 230 && tintB == 255) { tile->frame(0); }
      if (tint == 255 && tintR == 204 && tintG == 204 && tintB == 255) { tile->frame(0); }
      if (tint == 255 && tintR == 180 && tintG == 180 && tintB == 255) { tile->frame(0); }
      if (tint == 255 && tintR == 153 && tintG == 153 && tintB == 255) { tile->frame(0); }
      if (tint == 255 && tintR == 130 && tintG == 130 && tintB == 255) { tile->frame(0); }
      if (tint == 255 && tintR == 102 && tintG == 102 && tintB == 255) { tile->frame(0); }
      if (tint == 255 && tintR == 80 && tintG == 80 && tintB == 255)   { tile->frame(21); }
      if (tint == 255 && tintR == 51 && tintG == 51 && tintB == 255)   { tile->frame(19); }
      if (tint == 255 && tintR == 30 && tintG == 30 && tintB == 255)   { tile->frame(20); }

      if (tint == 255 && tintR == 0 && tintG == 0 && tintB == 255)   { tile->frame(20); }
      if (tintB == 255 && tint == 225) { tile->frame(19); }
      if (tintB == 255 && tint == 204) { tile->frame(21); }
      if (tintB == 255 && tint == 175) { tile->frame(0); }
      if (tintB == 255 && tint == 153) { tile->frame(0); }
      if (tintB == 255 && tint == 125) { tile->frame(0); }
      if (tintB == 255 && tint == 102) { tile->frame(0); }
      if (tintB == 255 && tint == 75) { tile->frame(0); }
      if (tintB == 255 && tint == 51) { tile->frame(0); }
      if (tintB == 255 && tint == 25) { tile->frame(0); }

      counter += heightmap->bitdepth;
      tcounter++;
    }
  }
	// add field_container to Enemy
  field->position = this->position;
	this->addChild(field);
  this->scale = Point2(2,2);
  std::cout << "added field as child of this enemy" << std::endl;
}

void Enemy::TGA2Grid(std::string tiles, std::string tga)
{
  std::cout << "TGA to grid" << std::endl;
  gridwidth = 3;
	gridheight = 3;
	cellwidth = 16;
	cellheight = 16;

	RGBAColor wall       =		RGBAColor(255, 255, 255);

  // fill field of tiles
  field = new Field();
  //field->addGrid(AUTOGENWHITE, 1, 1, gridwidth, gridheight, cellwidth, cellheight);
  field->addGrid("assets/enemies_tiles.tga", 8, 8, gridwidth, gridheight, cellwidth, cellheight);

  heightmapsprite = new Sprite();
  heightmapsprite->setupSpriteTGAPixelBuffer("assets/newmap.tga", 0, 2);
  PixelBuffer* heightmap = heightmapsprite->texture()->pixels();
  int w = heightmap->width;
  int h = heightmap->height;
  int counter = 0;
  int tcounter = 0;

  for (int x = 0; x < w; x++) {
    for (int y = 0; y < h; y++) {
      Sprite* tile = field->spritebatch()[tcounter];
      unsigned char tint = heightmap->data[counter+3]; // alpha pixel
      unsigned char tintR = heightmap->data[counter]; // alpha pixel
      unsigned char tintG = heightmap->data[counter+1]; // alpha pixel
      unsigned char tintB = heightmap->data[counter+2]; // alpha pixel

      std::cout << "X=========================================X" << std::endl;
      std::cout << "| * " << "Tile Number: " << tcounter << std::endl;
      std::cout << "| * " << "Alpha: " << (int)tint << std::endl;
      std::cout << "| * " <<  "Red: " << (int)tintR << std::endl;
      std::cout << "| * " <<  "Green: " << (int)tintG << std::endl;
      std::cout << "| * " <<  "Blue: " << (int)tintB << std::endl;
      std::cout << "X=========================================X" << std::endl;
      std::cout << " " << std::endl;

      tile->color = wall;

      if (tint == 0) { tile->color = wall; } // empty
      if (tint == 0) { tile->frame(0); } // empty

      if (tint == 255 && tintR == 255 && tintG == 0 && tintB == 0 ) { tile->frame(4); } // pure red
      if (tint == 255 && tintR == 255 && tintG == 51 && tintB == 51 ) { tile->frame(3); } // nearly pure red
      if (tint == 255 && tintR == 255 && tintG == 102 && tintB == 102 ) { tile->frame(5); } // medium red
      if (tint == 255 && tintR == 255 && tintG == 153 && tintB == 153 ) { tile->frame(0); } // low red
      if (tint == 255 && tintR == 255 && tintG == 204 && tintB == 204 ) { tile->frame(0); } // lowest red

      if (tint == 255 && tintR == 0 && tintG == 255 && tintB == 0 ) { tile->frame(12); } // pure green
      if (tint == 255 && tintR == 51 && tintG == 255 && tintB == 51 ) { tile->frame(11); } // nearly pure green
      if (tint == 255 && tintR == 102 && tintG == 255 && tintB == 102 ) { tile->frame(13); } // medium green
      if (tint == 255 && tintR == 153 && tintG == 255 && tintB == 153 ) { tile->frame(0); } // low green
      if (tint == 255 && tintR == 204 && tintG == 255 && tintB == 204 ) { tile->frame(0); } // lowest green

      if (tint == 255 && tintR == 0 && tintG == 0 && tintB == 255 ) { tile->frame(20); } // pure blue
      if (tint == 255 && tintR == 51 && tintG == 51 && tintB == 255 ) { tile->frame(19); } // nearly pure blue
      if (tint == 255 && tintR == 102 && tintG == 102 && tintB == 255 ) { tile->frame(21); } // medium blue
      if (tint == 255 && tintR == 153 && tintG == 153 && tintB == 255 ) { tile->frame(0); } // low blue
      if (tint == 255 && tintR == 204 && tintG == 204 && tintB == 255 ) { tile->frame(0); } // lowest blue

      counter += heightmap->bitdepth;
      tcounter++;
    }
  }
	// add field_container to Enemy
  field->position = this->position;
	this->addChild(field);
  std::cout << "added field as child of this enemy" << std::endl;
}

void Enemy::TGA2PixelSprite()
{
  Sprite* tgaSprite = new Sprite();
	tgaSprite->setupSpriteTGAPixelBuffer("assets/test.tga", 0, 2);
	PixelBuffer* buffer = tgaSprite->texture()->pixels();
	int w = buffer->width;
	int h = buffer->height;
  int counter = 0;
  int tcounter = 0;
  int spritesize = w * h;

  char enemySprite[spritesize] = {0};

	for (int i = 0; i < spritesize; i++) {
		unsigned char tint = buffer->data[counter+3]; // alpha pixel

    if (tint == 0) { enemySprite[i] = 0; } // empty
    if (tint == 255) { enemySprite[i] = 1; } // solid

    counter += buffer->bitdepth;
		tcounter++;
	}
  mainsprite.init(enemySprite, w, h);
  Entity* thisparententity;
  Layer* thisparent;
  thisparententity = this->parent();
  thisparent = (Layer*)thisparententity;
  std::cout << "decltype(thisparententity) is " << type_name<decltype(thisparententity)>() << std::endl;
  std::cout << "decltype(thisparent) is " << type_name<decltype(thisparent)>() << std::endl;

  thisparent->canvas->drawSprite(mainsprite);

  mainsprite.position = Point2i(100,100);
  //Scenemanager::getInstance()->getCurrentScene()->layers[2]->canvas->drawSprite(mainsprite);

}
