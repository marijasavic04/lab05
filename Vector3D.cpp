#include "Vector3D.h"

Vector3D::Vector3D(double x, double y, double z): _x(x), _y(y), _z(z){};

Vector3D Vector3D::operator+(const Vector3D &other) const{
    Vector3D result;
    result._x=this->_x + other._x;
    result._y=this->_y + other._y;
    result._z=this->_z + other._z;

    return result;
};
Vector3D Vector3D::operator*(double d) const{
    Vector3D result;
    result._x= this->_x*d;
    result._y= this->_y*d;
    result._z= this->_z*d;

    return result;
};
double Vector3D::getX() const{
    return this->_x;
}
double Vector3D::getY() const{
    return this->_y;
}
double Vector3D::getZ() const{
    return this->_z;
}
std::ostream &operator<<(std::ostream &out, const Vector3D& other){
    double x,y,z;
    x=other.getX();
    y=other.getY();
    z=other.getZ();
    out << x << y << z;
    return out;
}