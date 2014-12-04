#include <igl/DrawableContainer.hpp>

igl::DrawableContainer::DrawableContainer() throw() { }

igl::DrawableContainer::DrawableContainer(const igl::DrawableContainer& d) throw() : Drawable(d), Container(d) { }

igl::DrawableContainer::~DrawableContainer() { }

void igl::DrawableContainer::create() throw(igl::Exception) {
    for(int i=0; i<objects.size(); ++i) {
        objects[i]->create();
    }
}

void igl::DrawableContainer::setColor(igl::Color c) throw() {
    for(int i=0; i<objects.size(); ++i) {
        objects[i]->setColor(c);
    }
}

void igl::DrawableContainer::draw(igl::Window * window) throw(igl::Exception) {
    drawAll(window);
}
