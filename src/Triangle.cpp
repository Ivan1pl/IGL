#include <igl/Triangle.hpp>
#include <igl/Window.hpp>

igl::Triangle::Triangle(Point p1, Point p2, Point p3) throw(igl::Exception) {
    (this->p).push_back(p1);
    (this->p).push_back(p2);
    (this->p).push_back(p3);
    if(p1 == p2 || p1 == p3 || p2 == p3) {
        throw Exception("igl::Triangle requires 3 points.");
    }
}

igl::Triangle::Triangle(const igl::Triangle& t) throw() {
    p = t.p;
}

void igl::Triangle::draw(igl::Window * window) throw(igl::Exception) {
    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );

    // Draw the triangle !
    glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

igl::Triangle::~Triangle() { }

