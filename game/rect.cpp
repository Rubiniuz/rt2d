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
