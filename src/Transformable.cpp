#include <igl/Transformable.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <igl/Window.hpp>

igl::Transformable::Transformable() throw(igl::Exception) {
    Model = translation = scale = rotation = glm::mat4(1.0f);
}

igl::Transformable::Transformable(const igl::Transformable& t) throw() : DrawableContainer(t) {
    Model = t.Model;
    translation = t.translation;
    scale = t.scale;
    rotation = t.rotation;
}

igl::Transformable::~Transformable() { }

void igl::Transformable::setTranslation(float x, float y, float z) throw() {
    translation = glm::translate(glm::mat4(1.0f),glm::vec3(x,y,z));
}

void igl::Transformable::setRotation(igl::Axis axis, float angle) throw() {
    glm::vec3 vaxis(axis.x, axis.y, axis.z);
    rotation = glm::translate(glm::mat4(1.0f),glm::vec3(origin.x,origin.y,origin.z));
    rotation = glm::rotate(rotation,angle,vaxis);
    rotation = glm::translate(rotation,glm::vec3(-origin.x,-origin.y,-origin.z));
}

void igl::Transformable::setRotation(float rx, float ry, float rz) throw() {
    rotation = glm::translate(glm::mat4(1.0f),glm::vec3(origin.x,origin.y,origin.z));
    rotation = glm::rotate(rotation,rx,glm::vec3(1.0f,0.0f,0.0f));
    rotation = glm::rotate(rotation,ry,glm::vec3(0.0f,1.0f,0.0f));
    rotation = glm::rotate(rotation,rz,glm::vec3(0.0f,0.0f,1.0f));
    rotation = glm::translate(rotation,glm::vec3(-origin.x,-origin.y,-origin.z));
}

void igl::Transformable::setScale(float modifier) throw(igl::Exception) {
    if(modifier <= 0.0f) throw Exception("igl::Transformable: scale modifier has to be positive");
    scale = glm::scale(glm::mat4(1.0f),glm::vec3(modifier, modifier, modifier));
}

void igl::Transformable::setOrigin(igl::Location l) throw() {
    origin = l;
}

igl::Location igl::Transformable::getOrigin() throw() {
    return origin;
}

void igl::Transformable::create() throw(igl::Exception) {
    DrawableContainer::create();
    Model = translation * rotation * scale;
}

void igl::Transformable::draw(igl::Window * window) throw(igl::Exception) {
    window->getMatrixStack().pushMatrix(Model);
    window->updateMVP();
    DrawableContainer::draw(window);
    window->getMatrixStack().popMatrix();
    window->updateMVP();
}

