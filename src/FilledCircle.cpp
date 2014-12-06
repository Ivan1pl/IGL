#include <igl/FilledCircle.hpp>
#include <igl/Window.hpp>
#include <algorithm>

#define _USE_MATH_DEFINES

#include <cmath>

igl::FilledCircle::FilledCircle(igl::Vertex center, float radius) throw(igl::Exception) : fan(center) {
    if(radius <= 0.0f) {
        throw igl::Exception("igl::FilledCircle requires positive radius.");
    }
    this->radius = radius;
    float angle = 3.6f/(2.0f*M_PI*radius);
    int parts = std::max(10,(int)(360.0f/angle));
    float step = 2.0f*M_PI/(float)parts;
    fan.addPoint(Vertex(Location(center.getLocation().x+radius,center.getLocation().y,center.getLocation().z),center.getColor()));
    float currangle = step;
    while(currangle < 2.0f*M_PI) {
        fan.addPoint(Vertex(Location(center.getLocation().x+cos(currangle)*radius,center.getLocation().y+sin(currangle)*radius,center.getLocation().z),center.getColor()));
        currangle += step;
    }
    fan.addPoint(Vertex(Location(center.getLocation().x+radius,center.getLocation().y,center.getLocation().z),center.getColor()));
}

igl::FilledCircle::FilledCircle(const igl::FilledCircle& fc) throw() : Drawable(), fan(fc.fan) {
    radius = fc.radius;
}

void igl::FilledCircle::draw(igl::Window * window) throw(igl::Exception) {
    fan.draw(window);
}

void igl::FilledCircle::create() throw() {
    fan.create();
}

void igl::FilledCircle::setColor(igl::Color c) throw() {
    fan.setColor(c);
}

igl::FilledCircle::~FilledCircle() { }

