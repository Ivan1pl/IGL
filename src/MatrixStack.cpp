#include <igl/MatrixStack.hpp>

igl::MatrixStack::MatrixStack() throw() {
    matrices.push(glm::mat4(1.0f));
}

void igl::MatrixStack::pushMatrix(glm::mat4 matrix) throw() {
    if(matrices.size() == 0) {
        matrices.push(glm::mat4(1.0f));
    }
    matrices.push(matrices.top() * matrix);
}

void igl::MatrixStack::popMatrix() throw() {
    if(matrices.size() > 1) {
        matrices.pop();
    }
}

glm::mat4 igl::MatrixStack::top() throw() {
    if(matrices.size() == 0) {
        matrices.push(glm::mat4(1.0f));
    }
    return matrices.top();
}
