#include <igl/Location.hpp>

igl::Location::Location(float x, float y, float z) throw() {
    this->x = x;
    this->y = y;
    this->z = z;
}

igl::Location::Location(const igl::Location& l) throw() {
    x = l.x;
    y = l.y;
    z = l.z;
}

igl::Location& igl::Location::operator=(const igl::Location& l) throw() {
    x = l.x;
    y = l.y;
    z = l.z;
    return (*this);
}

bool igl::Location::operator==(const igl::Location& l) const throw() {
    return (x == l.x && y == l.y && z == l.z);
}

