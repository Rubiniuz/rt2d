#include "enemy.h"
#include "type_name.h"

using namespace std;

Enemy::Enemy() : Entity()
{
  this->addSprite("assets/enemy.tga");
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

void Enemy::TGA2Grid(std::string tiles, std::string tga)
{
  std::cout << "TGA to grid" << std::endl;
  gridwidth = 3;
	gridheight = 3;
	cellwidth = 8;
	cellheight = 8;

	RGBAColor White       =		RGBAColor(255, 255, 255);

	// fill field of tiles
	field = new Field();
	//field->addGrid(AUTOGENWHITE, 1, 1, gridwidth, gridheight, cellwidth, cellheight);
	field->addGrid("assets/enemytiles.tga", 4, 4, gridwidth, gridheight, cellwidth, cellheight);

	heightmapsprite = new Sprite();
	heightmapsprite->setupSpriteTGAPixelBuffer("assets/enemycolormap.tga", 0, 2);
  std::cout << "sprite set up" << std::endl;
	PixelBuffer* heightmap = heightmapsprite->texture()->pixels();
  std::cout << "pixelbuffer set up" << std::endl;
	int w = heightmap->width;
	int h = heightmap->height;
  int counter = 0;
  int tcounter = 0;

  std::cout << "start colormap checking" << std::endl;
	for (int x = 0; x < w; x++) {
		for (int y = 0; y < h; y++) {
			Sprite* tile = field->spritebatch()[tcounter];
			char tintA = 0; // alpha pixel
      char tintR = 0; // red pixel
      char tintG = 0; // green pixel
      char tintB = 0; // blue pixel

      std::cout << "finished setting up RGBA Values" << std::endl;

      tintA = heightmap->data[counter+3]; // alpha pixel
      tintR = heightmap->data[counter]; // red pixel
      tintG = heightmap->data[counter+1]; // green pixel
      tintB = heightmap->data[counter+2]; // blue pixel

      std::cout << "gave RGBA a value" << std::endl;

      cv = std::vector<char>{ 0, 0, 0, 0 };

      std::cout << "made empty vector array" << std::endl;

      cv[0] = tintA;
      cv[1] = tintR;
      cv[2] = tintG;
      cv[3] = tintB;

      std::cout << "RGBA values put into a vector array" << std::endl;
      std::cout << "ARGB values: " << cv[0] << " , " << cv[1] << " , "  << cv[2] << " , "  << cv[3] << std::endl;
      /*
      if (cv[1] != 0)
      {
        if (cv[0] == 0) { tile->color = White; } // empty
        if (cv[0] == 0) { tile->frame(0); } // empty
        if (cv[0] == 51) { tile->color = White; } // body
        if (cv[0] == 51) { tile->frame(0); } // body
        if (cv[0] == 102) { tile->color = White; } // thruster
        if (cv[0] == 102) { tile->frame(0); } // thruster
        if (cv[0] == 153) { tile->color = White; } // leftwing
        if (cv[0] == 153) { tile->frame(0); } // border
        if (cv[0] == 153) { tile->color = White; } // leftwing
        if (cv[0] == 153) { tile->frame(10); } // border
        if (cv[0] == 255) { tile->color = White; } // leftwing
        if (cv[0] == 255) { tile->frame(9); } // border
        std::cout << "Checked red value" << std::endl;
      }
      else if (cv[2] != 0)
      {
        if (cv[2] == 0) { tile->color = White; } // empty
        if (cv[2] == 0) { tile->frame(0); } // empty
        if (cv[2] == 51) { tile->color = White; } // body
        if (cv[2] == 51) { tile->frame(0); } // body
        if (cv[2] == 102) { tile->color = White; } // thruster
        if (cv[2] == 102) { tile->frame(0); } // thruster
        if (cv[2] == 153) { tile->color = White; } // leftwing
        if (cv[2] == 153) { tile->frame(0); } // border
        if (cv[2] == 204) { tile->color = White; } // leftwing
        if (cv[2] == 204) { tile->frame(3); } // border
        if (cv[2] == 255) { tile->color = White; } // leftwing
        if (cv[2] == 255) { tile->frame(2); } // border
        std::cout << "Checked green value" << std::endl;
      }
      else if (cv[3] != 0)
      {
        if (cv[3] == 0) { tile->color = White; } // empty
        if (cv[3] == 0) { tile->frame(0); } // empty
        if (cv[3] == 51) { tile->color = White; } // body
        if (cv[3] == 51) { tile->frame(1); } // body
        if (cv[3] == 102) { tile->color = White; } // thruster
        if (cv[3] == 102) { tile->frame(2); } // thruster
        if (cv[3] == 153) { tile->color = White; } // leftwing
        if (cv[3] == 153) { tile->frame(3); } // border
        if (cv[3] == 204) { tile->color = White; } // leftwing
        if (cv[3] == 204) { tile->frame(4); } // border
        if (cv[3] == 255) { tile->color = White; } // leftwing
        if (cv[3] == 255) { tile->frame(5); } // border
        std::cout << "Checked blue value" << std::endl;
      }*/
      //else
      //{
        if (cv[0] == 0) { tile->color = White; } // empty
        if (cv[0] == 0) { tile->frame(0); } // empty
        if (cv[0] == 51) { tile->color = White; } // body
        if (cv[0] == 51) { tile->frame(0); } // body
        if (cv[0] == 102) { tile->color = White; } // thruster
        if (cv[0] == 102) { tile->frame(0); } // thruster
        if (cv[0] == 153) { tile->color = White; } // leftwing
        if (cv[0] == 153) { tile->frame(6); } // border
        if (cv[0] == 204) { tile->color = White; } // leftwing
        if (cv[0] == 204) { tile->frame(4); } // border
        if (cv[0] == 255) { tile->color = White; } // leftwing
        if (cv[0] == 255) { tile->frame(5); } // border
        std::cout << "Checked alpha value" << std::endl;
      //}

      counter += heightmap->bitdepth;
			tcounter++;

      std::cout << "increase counters" << std::endl;
		}
	}
	// add field_container to Enemy
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
