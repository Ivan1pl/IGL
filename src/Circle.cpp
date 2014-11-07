#include <igl/Circle.hpp>
#include <igl/Window.hpp>
#include <algorithm>

#define _USE_MATH_DEFINES

#include <cmath>

igl::Circle::Circle(igl::Point center, float radius) throw(igl::Exception) : lines(igl::Point(center.x+radius,center.y,center.z,center.c)) {
    if(radius <= 0.0f) {
        throw igl::Exception("igl::Circle requires positive radius.");
    }
    this->radius = radius;
    float angle = 3.6f/(2.0f*M_PI*radius);
    int parts = std::max(10,(int)(360.0f/angle));
    float step = 2.0f*M_PI/(float)parts;
    float currangle = step;
    while(currangle < 2.0f*M_PI) {
        lines.addPoint(Point(center.x+cos(currangle)*radius,center.y+sin(currangle)*radius,center.z,center.c));
        currangle += step;
    }
    lines.addPoint(Point(center.x+radius,center.y,center.z,center.c));
}

igl::Circle::Circle(const igl::Circle& c) throw() : lines(c.lines) {
    radius = c.radius;
}

void igl::Circle::draw(igl::Window * window) throw(igl::Exception) {
    lines.draw(window);
}

void igl::Circle::create() throw() {
    lines.create();
}

void igl::Circle::setColor(igl::Color c) throw() {
    lines.setColor(c);
}

igl::Circle::~Circle() { }

