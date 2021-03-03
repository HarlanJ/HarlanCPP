#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <math.h>

class Vector2{
  public:
    double x, y;
    Vector2(){
      x = 0;
      y = 0;
    }

    Vector2(double x, double y){
      this->x = x;
      this->y = y;
    }

    double mag(){
      return sqrt(x*x + y*y);
    }

    // Radians
    void rotate(double theta){
      double oldX = x;
      x = x*cos(theta) - y*sin(theta);
      y = y*cos(theta) + oldX*sin(theta);
    }

    static Vector2 rotate(Vector2 v, double theta){
      return Vector2(
        v.x*cos(theta) - v.y*sin(theta),
        v.y*cos(theta) + v.x*sin(theta)
      );
    }
};

#endif