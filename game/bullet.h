#ifndef BULLET_H
#define BULLET_H

#include <rt2d/entity.h>

class Bullet : public Entity
{
public:
  Bullet();
  ~Bullet();

  virtual void update(float deltaTime);

  Timer t;
  Timer life;

  Vector2 velocity;
  Polar polar;
  /// @brief get the width of the canvas
  /// @return _width of canvas
  int width() { return _width; };
  /// @brief get the height of the canvas
  /// @return _height of canvas
  int height() { return _height; };
private:
  /// @brief width of the canvas
  int _width;
  /// @brief height of the canvas
  int _height;
};

#endif /* BULLET_H */
