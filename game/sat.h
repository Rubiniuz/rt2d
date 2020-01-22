#ifndef SAT_H
#define SAT_H

#include <rt2d/pointx.h>
#include "bullet.h"
#include "enemy.h"
#include <math.h>

class Sat
{
public:

  Sat();
  ~Sat();

  bool noRotationCollision(Entity* a, Entity* b);
  bool sameRotationCollision(Entity* a, Entity* b);
  bool notSameRotationCollision(Entity* a, Entity* b);

  float GetLowest(float one, float two, float three, float four);
  float GetHighest(float one, float two, float three, float four);

  float GetHighestProjectionA();
  float GetLowestProjectionA();

  float GetHighestProjectionB();
  float GetLowestProjectionB();

  Point2 GetPointRotated(float Xpos, float Ypos, float Rot, float Xos, float Yos);
  void FillAllCorners(Entity* a, Entity* b);

  float DotProduct(Point2 a, Point2 b);
  float GetAngle(Point2 a, Point2 b);
  float GetProjection(Point2 a);
  float GetMagnitude(Point2 a);

  void GetMinAndMaxCorners();

  float Getdot(Point2 a, Point2 b);
  // GetPointRotated(box1X, box1Y, box1R, -box1W/2, box1H/2);  // Dot1
  // GetPointRotated(box1X, box1Y, box1R, box1W/2, box1H/2);  // Dot2
  // GetPointRotated(box1X, box1Y, box1R, -box1W/2, -box1H/2); // Dot3
  // GetPointRotated(box1X, box1Y, box1R, box1W/2, -box1H/2); // Dot4

  Point2 axis = Point2(1, -1);

  Point2 a_1;
  Point2 a_2;
  Point2 a_3;
  Point2 a_4;

  Point2 b_1;
  Point2 b_2;
  Point2 b_3;
  Point2 b_4;

  Point2 a_max;
  Point2 a_min;

  Point2 b_max;
  Point2 b_min;

  float a_proj_max;
  float a_proj_min;

  float b_proj_max;
  float b_proj_min;

};

#endif /* SAT_H */
