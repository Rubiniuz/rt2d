#include "enemy.h"
#include "type_name.h"

using namespace std;

Enemy::Enemy() : Entity()
{
  finder.start();
  shoottimer.start();
  timetofindplayer = 0;
  speed = 0;
  int pixelsize = 2;
  makesprite();
  //mainsprite = new DynamicSprite("assets/error.tga", 1, 1, 16, 16, pixelsize);
  mainsprite = new DynamicSprite();
  mainsprite->FromSpriteSheet(spritedata, "assets/enemytest.tga", 3, 3, 16, 16, pixelsize);
  mainsprite->position = this->position;
  this->addChild(mainsprite);
  this->_width = mainsprite->width() * pixelsize;
  this->_height = mainsprite->height() * pixelsize;

  target = this->position;

  health = 5;
  pixelsdestroyed = 0;
  pixelstobedestroyed = mainsprite->width() * mainsprite->height() / 128 * pixelsize;
}

Enemy::Enemy(std::string tgafile, int width, int height, int tilewidth, int tileheight, int pixelsize) : Entity()
{
    finder.start();
    shoottimer.start();
    timetofindplayer = 0;
    speed = 0;
    makesprite();
    //mainsprite = new DynamicSprite("assets/error.tga", 1, 1, 16, 16, pixelsize);
    mainsprite = new DynamicSprite();
    mainsprite->FromSpriteSheet(spritedata, tgafile, width, height, tilewidth, tileheight, pixelsize);
    mainsprite->position = this->position;
    this->addChild(mainsprite);
    this->_width = mainsprite->width() * pixelsize;
    this->_height = mainsprite->height() * pixelsize;

    target = this->position;

    health = 5;
    pixelsdestroyed = 0;
    pixelstobedestroyed = mainsprite->width() * mainsprite->height() / 64 * pixelsize;
}

Enemy::~Enemy()
{
  delete mainsprite;
  this->removeChild(mainsprite);
}

void Enemy::update(float deltaTime)
{
   Point2 velocity = Point2(0,0);
   dir = Point2(target.x - this->position.x , target.y - this->position.y);

   float mag = sqrt(dir.x*dir.x + dir.y*dir.y);

   dir = Point2(dir.x / mag, dir.y / mag);

   dir = Point2(dir.x * 0.5, dir.y * 0.5);

   Point2 acceleration = Point2(dir.x / (speed * (pixelsdestroyed / 100 + 1)) , dir.y / (pixelsdestroyed / 100 + 1));

   velocity = Point2(velocity.x + acceleration.x , velocity.y + acceleration.y);

   if (velocity.x > 15) { velocity.x = 15; }
   if (velocity.y > 15) { velocity.y = 15; }

   this->position = Point2(this->position.x + velocity.x , this->position.y + velocity.y);
 }

 void Enemy::shootBullet(Point2 player)
 {
   this->distance = sqrt( ( (player.x - this->position.x) * (player.x - this->position.x) ) + ( (player.y - this->position.y) * (player.y - this->position.y) ) );

   if (this->shoottimer.seconds() >= timetofindplayer)
   {
     if (this->distance < 450)
     {
       Bullet* tempBullet = new Bullet();
       tempBullet->position = this->position;
       tempBullet->rotation.z = this->rotation.z;
       tempBullet->velocity = Vector2(cos(tempBullet->rotation.z),sin(tempBullet->rotation.z));
       tempBullet->velocity *= 75;
       this->bullets.push_back(tempBullet);
       Scenemanager::getInstance()->getCurrentScene()->layers[1]->addChild(tempBullet);
       this->shoottimer.start();
     }
   }
 }

 void Enemy::changeAngle(Point2 player)
 {
   dir = Point2(player.x - this->position.x , player.y - this->position.y);
   float mag = sqrt(dir.x*dir.x + dir.y*dir.y);
   dir = Point2(dir.x / mag, dir.y / mag);
   double angle = std::atan2( dir.y, dir.x );
   this->rotation.z = angle;
 }

void Enemy::makesprite()
{
  spritedata =
  {
    0, 1, 0,
    1, 3, 1,
    0, 1, 0
  };
}
