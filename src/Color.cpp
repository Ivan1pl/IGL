#include <igl/Color.hpp>

igl::Color::Color(int r, int g, int b, int a) throw(igl::Exception) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
    if(r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255 || a < 0 || a > 255) {
        throw Exception("Invalid RGBA value.");
    }
}

igl::Color::Color(const igl::Color& c) throw() {
    r = c.r;
    g = c.g;
    b = c.b;
    a = c.a;
}

igl::Color& igl::Color::operator=(const igl::Color& c) throw() {
    r = c.r;
    g = c.g;
    b = c.b;
    a = c.a;
    return (*this);
}

GLfloat igl::Color::toFloat(int v) {
    return ((GLfloat)v)/255.0f;
}

