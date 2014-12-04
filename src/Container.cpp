#include <igl/Container.hpp>
#include <igl/Window.hpp>

igl::Container::Container() throw() { }

igl::Container::Container(const igl::Container& c) throw() {
    objects = c.objects;
}

igl::Container::~Container() { }

void igl::Container::addObject(igl::Drawable& drawable) throw() {
    objects.push_back(&drawable);
}

void igl::Container::drawAll(igl::Window * window) throw(igl::Exception) {
    for(int i = 0; i < objects.size(); ++i) {
        objects[i]->draw(window);
    }
}
