#include <igl/FilledCircle.hpp>
#include <igl/Window.hpp>
#include <algorithm>

#define _USE_MATH_DEFINES

#include <cmath>

igl::FilledCircle::FilledCircle(igl::Point center, float radius) throw(igl::Exception) : fan(center) {
    if(radius <= 0.0f) {
        throw igl::Exception("igl::FilledCircle requires positive radius.");
    }
    this->radius = radius;
    float angle = 3.6f/(2.0f*M_PI*radius);
    int parts = std::max(10,(int)(360.0f/angle));
    float step = 2.0f*M_PI/(float)parts;
    fan.addPoint(Point(center.x+radius,center.y,center.z,center.c));
    float currangle = step;
    while(currangle < 2.0f*M_PI) {
        fan.addPoint(Point(center.x+cos(currangle)*radius,center.y+sin(currangle)*radius,center.z,center.c));
        currangle += step;
    }
    fan.addPoint(Point(center.x+radius,center.y,center.z,center.c));
}

igl::FilledCircle::FilledCircle(const igl::FilledCircle& fc) throw() : fan(fc.fan) {
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

