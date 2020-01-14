#ifndef BASIC_H
#define BASIC_H

#include <rt2d/entity.h>

class Basic: public Entity
{
public:
  Basic();
  ~Basic();
  void update(float deltaTime);
private:

};

#endif /* BASIC_H */
