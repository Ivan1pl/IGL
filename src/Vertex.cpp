#include <igl/Vertex.hpp>

igl::Vertex::Vertex(igl::Location l, igl::Color c) throw() {
    this->l = l;
    this->c = c;
}

igl::Vertex::Vertex(const igl::Vertex& v) throw() {
    l = v.l;
    c = v.c;
}

igl::Vertex& igl::Vertex::operator=(const igl::Vertex& v) throw() {
    l = v.l;
    c = v.c;
    return (*this);
}

igl::Location igl::Vertex::getLocation() const throw() {
    return l;
}

void igl::Vertex::setLocation(igl::Location l) throw() {
    this->l = l;
}

igl::Color igl::Vertex::getColor() const throw() {
    return c;
}

void igl::Vertex::setColor(igl::Color c) throw() {
    this->c = c;
}

