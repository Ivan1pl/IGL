#include <igl/Axis.hpp>
#include <cmath>

igl::Axis::Axis(float x, float y, float z) throw(igl::Exception) {
    this->x = x;
    this->y = y;
    this->z = z;
    normalize();
}

void igl::Axis::normalize() throw(igl::Exception) {
    float div = sqrt(x*x+y*y+z*z);
    if(div == 0.0f) throw Exception("igl::Axis can't be normalized -- vector length = 0");
    x /= div;
    y /= div;
    z /= div;
}
