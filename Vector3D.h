#pragma once
#include <iostream>
class Vector3D{
    private: 
      double _x;
      double _y;
      double _z;
    public:
      Vector3D(double x=0, double y=0, double z=0);
      Vector3D operator+(const Vector3D &m) const;
      Vector3D operator*(double d) const;
      double getX() const;
      double getY() const;
      double getZ() const;
};
std::ostream &operator<<(std::ostream &out, const Vector3D& other);