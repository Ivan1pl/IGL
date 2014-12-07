#include <igl/Axis.hpp>
#include <cmath>

igl::Axis::Axis(float x, float y, float z) throw(igl::Exception) {
    this->x = x;
    this->y = y;
    this->z = z;
    normalize();
}

igl::Axis::Axis(const igl::Axis& a) throw() {
    x = a.x;
    y = a.y;
    z = a.z;
}

igl::Axis::~Axis() { }

igl::Axis& igl::Axis::operator=(const igl::Axis& a) throw() {
    x = a.x;
    y = a.y;
    z = a.z;
    return *this;
}

void igl::Axis::normalize() throw(igl::Exception) {
    float div = sqrt(x*x+y*y+z*z);
    if(div == 0.0f) throw Exception("igl::Axis can't be normalized -- vector length = 0");
    x /= div;
    y /= div;
    z /= div;
}

