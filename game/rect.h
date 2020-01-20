#ifndef RECT_H
#define RECT_H

#include <rt2d/pointx.h>

class Rect
{
public:

  Rect(Point2 scale1, Point2 pos1, Point2 scale2, Point2 pos2);
  ~Rect();

  Point2 a(){return _a;};
  Point2 b(){return _b;};
  Point2 c(){return _c;};
  Point2 d(){return _d;};

  Point2 axis1(){return _axis1;};
  Point2 axis2(){return _axis2;};

  Point2 e(){return _e;};
  Point2 f(){return _f;};
  Point2 g(){return _g;};
  Point2 h(){return _h;};

  Point2 axis3(){return _axis3;};
  Point2 axis4(){return _axis4;};

private:

  Rect();

  Point2 _a;
  Point2 _b;
  Point2 _c;
  Point2 _d;

  Point2 _axis1;
  Point2 _axis2;

  Point2 _e;
  Point2 _f;
  Point2 _g;
  Point2 _h
  ;
  Point2 _axis3;
  Point2 _axis4;

};

#endif /* Rect_H */
