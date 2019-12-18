#include "enemy.h"
#include "type_name.h"

using namespace std;

Enemy::Enemy() : Entity()
{
  this->addSprite("assets/enemy.tga");
  TGA2PixelSprite();
}

Enemy::~Enemy()
{

}

void Enemy::update(float deltaTime)
{

}

void Enemy::UseSprite(string toGet)
{
  this->addSprite(toGet);
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

  char playerSprite[spritesize] = {0};

	for (int i = 0; i < spritesize; i++) {
		unsigned char tint = buffer->data[counter+3]; // alpha pixel

    if (tint == 0) { playerSprite[i] = 0; } // empty
    if (tint == 255) { playerSprite[i] = 1; } // solid

    counter += buffer->bitdepth;
		tcounter++;
	}
  mainsprite.init(playerSprite, w, h);
  Entity* thisparententity;
  Layer* thisparent;
  thisparententity = this->parent();
  thisparent = (Layer*)thisparententity;
  std::cout << "decltype(thisparententity) is " << type_name<decltype(thisparententity)>() << std::endl;
  std::cout << "decltype(thisparent) is " << type_name<decltype(thisparent)>() << std::endl;

  //thisparent->canvas->drawSprite(mainsprite);

  mainsprite.position = Point2i(100,100);
  Scenemanager::getInstance()->getCurrentScene()->layers[2]->canvas->drawSprite(mainsprite);

}
