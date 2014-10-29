#include <igl/Point.hpp>

igl::Point::Point(float x, float y, float z, igl::Color c) throw() {
    this->x = x;
    this->y = y;
    this->z = z;
    this->c = c;
}

igl::Point::Point(const igl::Point& p) throw() {
    x = p.x;
    y = p.y;
    z = p.z;
    c = p.c;
}

igl::Point& igl::Point::operator=(const igl::Point& p) throw() {
    x = p.x;
    y = p.y;
    z = p.z;
    c = p.c;
    return (*this);
}

bool igl::Point::operator==(const igl::Point& p) const throw() {
    return (x == p.x && y == p.y && z == p.z);
}

