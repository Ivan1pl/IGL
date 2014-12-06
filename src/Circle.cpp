#include <igl/Circle.hpp>
#include <igl/Window.hpp>
#include <algorithm>

#define _USE_MATH_DEFINES

#include <cmath>

igl::Circle::Circle(igl::Vertex center, float radius) throw(igl::Exception) : lines(igl::Vertex(igl::Location(center.getLocation().x+radius,center.getLocation().y,center.getLocation().z),center.getColor())) {
    if(radius <= 0.0f) {
        throw igl::Exception("igl::Circle requires positive radius.");
    }
    this->radius = radius;
    float angle = 3.6f/(2.0f*M_PI*radius);
    int parts = std::max(10,(int)(360.0f/angle));
    float step = 2.0f*M_PI/(float)parts;
    float currangle = step;
    while(currangle < 2.0f*M_PI) {
        lines.addPoint(Vertex(Location(center.getLocation().x+cos(currangle)*radius,center.getLocation().y+sin(currangle)*radius,center.getLocation().z),center.getColor()));
        currangle += step;
    }
    lines.addPoint(Vertex(Location(center.getLocation().x+radius,center.getLocation().y,center.getLocation().z),center.getColor()));
}

igl::Circle::Circle(const igl::Circle& c) throw() : Drawable(), lines(c.lines) {
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

