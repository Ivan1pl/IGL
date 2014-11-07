#include <igl/Lines.hpp>
#include <igl/Window.hpp>

igl::Lines::Lines(Point first) throw() {
    (this->p).push_back(first);
}

igl::Lines::Lines(const igl::Lines& l) throw() {
    p = l.p;
}

void igl::Lines::draw(igl::Window * window) throw(igl::Exception) {
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
    glDrawArrays(GL_LINES, 0, vertexBufferData.size()/3); // Starting from vertex 0; 3 vertices total -> 1 triangle

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

igl::Lines::~Lines() { }

void igl::Lines::create() throw(igl::Exception) {
    if(p.size() < 2) {
        throw Exception("igl::Lines requires at least 2 points.");
    }
    Drawable::create();
}

void igl::Lines::addPoint(Point p) throw() {
    (this->p).push_back(p);
}

