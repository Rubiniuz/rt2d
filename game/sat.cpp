#include "sat.h"

Sat::Sat()
{

}

Sat::~Sat()
{

}

Point2 Sat::GetPointRotated(float Xpos, float Ypos, float Rot, float Xos, float Yos)
{
  float rotatedX = Xpos + (Xos  * cos(Rot * 57.30)) - (Yos * sin(Rot * 57.30));
  float rotatedY = Ypos + (Xos  * sin(Rot * 57.30)) + (Yos * cos(Rot * 57.30));

  return Point2(rotatedX,rotatedY);
}

float Sat::GetAngle(Point2 a, Point2 b)
{
  return a.x * b.x + a.y * b.y;
}

float Sat::GetMagnitude(Point2 a)
{
  return sqrt( ((a.x - 1)*(a.x - 1)) + ((a.y - 1)*(a.y - 1)) );
}

float Sat::GetProjection(Point2 a)
{
  return GetMagnitude(a) * cos(0);
}

float Sat::DotProduct(Point2 a, Point2 b)
{
  return GetMagnitude(a) * GetMagnitude(b) * cos(GetAngle(a, b));
}

float Sat::GetHighest(float one, float two, float three, float four)
{
  float temp = one;
  if ( two > temp ){ temp = two; }
  if ( three > temp ){ temp = three; }
  if ( four > temp ){ temp = four; }
  if ( one > temp ){ temp = one; }
  return temp;
}

float Sat::GetLowest(float one, float two, float three, float four)
{
  float temp = one;
  if ( two < temp ){ temp = two; }
  if ( three < temp ){ temp = three; }
  if ( four < temp ){ temp = four; }
  if ( one < temp ){ temp = one; }
  return temp;
}

void Sat::GetMinAndMaxCorners()
{
  a_max.x = GetHighest(a_1.x, a_2.x, a_3.x, a_4.x);
  a_max.y = GetHighest(a_1.y, a_2.y, a_3.y, a_4.y);

  a_min.x = GetLowest(a_1.x, a_2.x, a_3.x, a_4.x);
  a_min.y = GetLowest(a_1.y, a_2.y, a_3.y, a_4.y);

  b_max.x = GetHighest(b_1.x, b_2.x, b_3.x, b_4.x);
  b_max.y = GetHighest(b_1.y, b_2.y, b_3.y, b_4.y);

  b_min.x = GetLowest(b_1.x, b_2.x, b_3.x, b_4.x);
  b_min.y = GetLowest(b_1.y, b_2.y, b_3.y, b_4.y);
}

void Sat::FillAllCorners(Entity* a, Entity* b)
{
  a_1 = GetPointRotated(a->position.x, a->position.y, a->rotation.z, -a->sprite()->width()/2, a->sprite()->height()/2);  // Dot1
  a_2 = GetPointRotated(a->position.x, a->position.y, a->rotation.z, a->sprite()->width()/2, a->sprite()->height()/2);  // Dot2
  a_3 = GetPointRotated(a->position.x, a->position.y, a->rotation.z, -a->sprite()->width()/2, -a->sprite()->height()/2); // Dot3
  a_4 = GetPointRotated(a->position.x, a->position.y, a->rotation.z, a->sprite()->width()/2, -a->sprite()->height()/2); // Dot4

  b_1 = GetPointRotated(b->position.x, b->position.y, b->rotation.z, -b->sprite()->width()/2, b->sprite()->height()/2);  // Dot1
  b_2 = GetPointRotated(b->position.x, b->position.y, b->rotation.z, b->sprite()->width()/2, b->sprite()->height()/2);  // Dot2
  b_3 = GetPointRotated(b->position.x, b->position.y, b->rotation.z, -b->sprite()->width()/2, -b->sprite()->height()/2); // Dot3
  b_4 = GetPointRotated(b->position.x, b->position.y, b->rotation.z, b->sprite()->width()/2, -b->sprite()->height()/2); // Dot4
}

float Sat::Getdot(Point2 a, Point2 b)
{
  return a.x * b.x + a.y * b.y;
}

float Sat::GetHighestProjectionA()
{
  float temp = DotProduct(a_1, axis);
  if ( DotProduct(a_2, axis) > temp ){ temp = DotProduct(a_2, axis); }
  if ( DotProduct(a_3, axis) > temp ){ temp = DotProduct(a_3, axis); }
  if ( DotProduct(a_4, axis) > temp ){ temp = DotProduct(a_4, axis); }
  if ( DotProduct(a_1, axis) > temp ){ temp = DotProduct(a_1, axis); }
  return temp;
}

float Sat::GetLowestProjectionA()
{
  float temp = DotProduct(a_1, axis);
  if ( DotProduct(a_2, axis) < temp ){ temp = DotProduct(a_2, axis); }
  if ( DotProduct(a_3, axis) < temp ){ temp = DotProduct(a_3, axis); }
  if ( DotProduct(a_4, axis) < temp ){ temp = DotProduct(a_4, axis); }
  if ( DotProduct(a_1, axis) < temp ){ temp = DotProduct(a_1, axis); }
  return temp;
}

float Sat::GetHighestProjectionB()
{
  float temp = DotProduct(a_1, axis);
  if ( DotProduct(a_2, axis) > temp ){ temp = DotProduct(a_2, axis); }
  if ( DotProduct(a_3, axis) > temp ){ temp = DotProduct(a_3, axis); }
  if ( DotProduct(a_4, axis) > temp ){ temp = DotProduct(a_4, axis); }
  if ( DotProduct(a_1, axis) > temp ){ temp = DotProduct(a_1, axis); }
  return temp;
}

float Sat::GetLowestProjectionB()
{
  float temp = DotProduct(a_1, axis);
  if ( DotProduct(a_2, axis) < temp ){ temp = DotProduct(a_2, axis); }
  if ( DotProduct(a_3, axis) < temp ){ temp = DotProduct(a_3, axis); }
  if ( DotProduct(a_4, axis) < temp ){ temp = DotProduct(a_4, axis); }
  if ( DotProduct(a_1, axis) < temp ){ temp = DotProduct(a_1, axis); }
  return temp;
}

bool Sat::noRotationCollision(Entity* a, Entity* b)
{
  //Pseudo code to evaluate the separation of box1 and box2
  float length = a->position.x - b->position.x;
  float hw_a = a->sprite()->width() / 2;
  float hw_b = b->sprite()->width() / 2;

  float gap = length - hw_a - hw_b;
  if (gap > 0) { std::cout << "It's a big gap between boxes" << std::endl; return false;}
  else if (gap == 0) { std::cout << "Boxes are touching each other" << std::endl; return true;}
  else if (gap < 0) { std::cout << "Boxes are penetrating each other" << std::endl; return true;}
  else { return false; }
}

bool Sat::sameRotationCollision(Entity* a, Entity* b)
{
  FillAllCorners(a, b);

  Point2 boxC = Point2(b->position.x - a->position.x , b->position.y - a->position.y);
  Point2 boxA = Point2(a_2.x - a->position.x , a_2.y - a->position.y);
  Point2 boxB = Point2(b_1.x - b->position.x , b_1.y - b->position.y);

  float projC = DotProduct(boxC, axis);
  float projA = DotProduct(boxA, axis);
  float projB = DotProduct(boxB, axis);

  float gap = projC - projA + projB;

  if (gap > 0) { std::cout << "there is a gap between both boxes" << std::endl; return false;}
  else if (gap == 0) { std::cout << "boxes are touching eachother" << std::endl; return true;}
  else if (gap < 0) { std::cout << "boxes are penetrating eachother" << std::endl; return true;}
  else { std::cout << "boxes had penetrated eachother" << std::endl; return false;}
}

bool Sat::notSameRotationCollision(Entity* a, Entity* b)
{
  FillAllCorners(a, b);

  float a_min_proj = GetLowestProjectionA();
  float a_max_proj = GetHighestProjectionA();
  float b_min_proj = GetLowestProjectionB();
  float b_max_proj = GetHighestProjectionB();

  if (b_max_proj < a_min_proj || a_max_proj < b_min_proj)
  {
    std::cout << "There's a gap between both boxes" << std::endl;
    return false;
  }
  else
  {
    std::cout << "No gap calculated." << std::endl;
    return true;
  }
}
