#include <igl/Camera.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

igl::Camera::Projection::Projection() throw() {
    ProjectionMatrix = glm::mat4(1.0f);
}

glm::mat4& igl::Camera::Projection::getProjectionMatrix() throw() {
    return ProjectionMatrix;
}

igl::Camera::Projection::Projection(const igl::Camera::Projection& p) throw() {
    ProjectionMatrix = p.ProjectionMatrix;
}

igl::Camera::Projection::~Projection() { }

igl::Camera::Projection& igl::Camera::Projection::operator=(const igl::Camera::Projection& p) throw() {
    ProjectionMatrix = p.ProjectionMatrix;
    return *this;
}

igl::Camera::Projection igl::Camera::Projection::perspective(float FoV, float aspectRatio, float near, float far) throw() {
    Projection p;
    p.ProjectionMatrix = glm::perspective(FoV,aspectRatio,near,far);
    return p;
}

glm::mat4& igl::Camera::getView() throw() {
    return View;
}

glm::mat4& igl::Camera::getProjection() throw() {
    return projection.getProjectionMatrix();
}

igl::Camera::Camera() throw() {
    up = Axis(0.0f,1.0f,0.0f);
    View = glm::mat4(1.0f);
}

igl::Camera::Camera(igl::Camera::Projection p, igl::Location position, igl::Location target, igl::Axis up) throw(igl::Exception) : projection(p) {
    this->position = position;
    this->target = target;
    this->up = up;
    this->up.normalize();
    View = glm::lookAt(
        glm::vec3(position.x,position.y,position.z),
        glm::vec3(target.x,target.y,target.z),
        glm::vec3(this->up.x,this->up.y,this->up.z)
    );
}

igl::Camera::Camera(const igl::Camera& c) throw() : projection(c.projection) {
    position = c.position;
    target = c.target;
    up = c.up;
    View = c.View;
}

igl::Camera::~Camera() { }

igl::Camera& igl::Camera::operator=(const igl::Camera& c) throw() {
    projection = c.projection;
    position = c.position;
    target = c.target;
    up = c.up;
    View = c.View;
    return *this;
}

void igl::Camera::setPosition(igl::Location l) throw() {
    position = l;
    View = glm::lookAt(
        glm::vec3(position.x,position.y,position.z),
        glm::vec3(target.x,target.y,target.z),
        glm::vec3(this->up.x,this->up.y,this->up.z)
    );
}

void igl::Camera::setTarget(igl::Location l) throw() {
    target = l;
    View = glm::lookAt(
        glm::vec3(position.x,position.y,position.z),
        glm::vec3(target.x,target.y,target.z),
        glm::vec3(this->up.x,this->up.y,this->up.z)
    );
}

void igl::Camera::setUpVector(igl::Axis a) throw(igl::Exception) {
    up = a;
    up.normalize();
    View = glm::lookAt(
        glm::vec3(position.x,position.y,position.z),
        glm::vec3(target.x,target.y,target.z),
        glm::vec3(this->up.x,this->up.y,this->up.z)
    );
}

void igl::Camera::setProjection(igl::Camera::Projection p) throw() {
    projection = p;
}

