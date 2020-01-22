#include "rect.h"

Rect::Rect()
{

}

Rect::Rect(Point2 scale1, Point2 pos1, Point2 scale2, Point2 pos2)
{
  _a = Point2(pos1.x - scale1.x/2 , pos1.y - scale1.y / 2);
  _b = Point2(pos1.x + scale1.x/2 , pos1.y - scale1.y / 2);
  _c = Point2(pos1.x - scale1.x/2 , pos1.y + scale1.y / 2);
  _d = Point2(pos1.x + scale1.x/2 , pos1.y + scale1.y / 2);

  _axis1 = Point2(b().x - a().x , b().y - a().y );
  _axis2 = Point2(b().x - c().x , b().y - c().y );

}

Rect::~Rect()
{

}

// GetPointRotated(box1X, box1Y, box1R, -box1W/2, box1H/2);  // Dot1
// GetPointRotated(box1X, box1Y, box1R, box1W/2, box1H/2);  // Dot2
// GetPointRotated(box1X, box1Y, box1R, -box1W/2, -box1H/2); // Dot3
// GetPointRotated(box1X, box1Y, box1R, box1W/2, -box1H/2); // Dot4

Point2 Rect::GetPointRotated(float Xpos, float Ypos, float Rot, float Xos, float Yos)
{
  // Xos, Yos // the coordinates of your center point of rect
  // R      // the angle you wish to rotate

  //The rotated position of this corner in world coordinates
  float rotatedX = Xpos + (Xos  * cos(Rot * 57.30)) - (Yos * sin(Rot * 57.30));
  float rotatedY = Ypos + (Xos  * sin(Rot * 57.30)) + (Yos * cos(Rot * 57.30));

  return Point2(rotatedX,rotatedY);
}

float Rect::Getdot(Point2 a, Point2 b)
{
  return a.x * b.x + a.y * b.y;
}

float Rect::GetHighest(float one, float two, float three, float four)
{
  int temp = one;
  if ( two > temp ){ temp = two; }
  if ( three > temp ){ temp = three; }
  if ( four > temp ){ temp = four; }
  if ( one > temp ){ temp = one; }
  return temp;
}

float Rect::GetLowest(float one, float two, float three, float four)
{
  int temp = one;
  if ( two < temp ){ temp = two; }
  if ( three < temp ){ temp = three; }
  if ( four < temp ){ temp = four; }
  if ( one < temp ){ temp = one; }
  return temp;
}

void Rect::SATEnemyToBullet(Enemy* aa, Bullet* bb)
{
  _a = GetPointRotated(aa->position.x, aa->position.y, aa->mainsprite->worldrotation().z, -aa->width()/2, aa->height()/2);
  _b = GetPointRotated(aa->position.x, aa->position.y, aa->mainsprite->worldrotation().z, aa->width()/2, aa->height()/2);
  _c = GetPointRotated(aa->position.x, aa->position.y, aa->mainsprite->worldrotation().z, -aa->width()/2, -aa->height()/2);
  _d = GetPointRotated(aa->position.x, aa->position.y, aa->mainsprite->worldrotation().z, aa->width()/2, -aa->height()/2);

  _e = GetPointRotated(bb->position.x, bb->position.y, bb->rotation.z, -bb->width()/2, bb->height()/2);
  _f = GetPointRotated(bb->position.x, bb->position.y, bb->rotation.z, bb->width()/2, bb->height()/2);
  _g = GetPointRotated(bb->position.x, bb->position.y, bb->rotation.z, -bb->width()/2, -bb->height()/2);
  _h = GetPointRotated(bb->position.x, bb->position.y, bb->rotation.z, bb->width()/2, -bb->height()/2);

  float aa_maxX = GetHighest(_a.x, _b.x, _c.x, _d.x);
  float aa_maxY = GetHighest(_a.y, _b.y, _c.y, _d.y);
  float bb_maxX = GetHighest(_e.x, _f.x, _g.x, _h.x);
  float bb_maxY = GetHighest(_e.y, _f.y, _g.y, _h.y);

  float aa_minX = GetLowest(_a.x, _b.x, _c.x, _d.x);
  float aa_minY = GetLowest(_a.y, _b.y, _c.y, _d.y);
  float bb_minX = GetLowest(_e.x, _f.x, _g.x, _h.x);
  float bb_minY = GetLowest(_e.y, _f.y, _g.y, _h.y);

  Point2 aa_max = Point2(aa_maxX, aa_maxY);
  Point2 aa_min = Point2(aa_minX, aa_minY);

  Point2 bb_max = Point2(bb_maxX, bb_maxY);
  Point2 bb_min = Point2(bb_minX, bb_minY);

  _axis1 = _b - _a;
  _axis2 = _d - _a;
  _axis3 = _f - _e;
  _axis4 = _h - _e;

  float gapX;
  float gapY;

  if (aa->position.x < bb->position.x) { gapX = bb_max.x - aa_min.x; }
  if (aa->position.x > bb->position.x) { gapX = aa_max.x - bb_min.x; }

  if (aa->position.y < bb->position.y) { gapY = bb_min.y - aa_max.y; }
  if (aa->position.y > bb->position.y) { gapY = aa_min.y - bb_max.y; }

  if (gapX > 0 && gapY > 0) { std::cout << "no collision" << std::endl;}
  if (gapX < 0 && gapY < 0) { std::cout << "full penetration collision" << std::endl;}
  if (gapX < 0 && gapY > 0) { std::cout << "x axis penetration no collision" << std::endl;}
  if (gapX > 0 && gapY < 0) { std::cout << "y axis penetration no collision" << std::endl;}
}
