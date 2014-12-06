#include <igl/Vertex.hpp>

igl::Vertex::Vertex(igl::Location l, igl::Color c) throw() {
    this->l = l;
    this->c = c;
}

igl::Vertex::Vertex(const igl::Vertex& v) throw() {
    l = v.l;
    c = v.c;
    n = v.n;
    UVs = v.UVs;
}

igl::Vertex& igl::Vertex::operator=(const igl::Vertex& v) throw() {
    l = v.l;
    c = v.c;
    n = v.n;
    UVs = v.UVs;
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

igl::Axis igl::Vertex::getNormal() const throw() {
    return n;
}

void igl::Vertex::setNormal(igl::Axis a) throw() {
    n = a;
    n.normalize();
}

glm::vec2 igl::Vertex::getUVs() const throw() {
    return UVs;
}

void igl::Vertex::setUVs(glm::vec2 v) throw() {
    UVs = v;
}

