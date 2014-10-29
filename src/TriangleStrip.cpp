#include <igl/TriangleStrip.hpp>
#include <igl/Window.hpp>

igl::TriangleStrip::TriangleStrip(igl::Point p) throw() {
    (this->p).push_back(p);
}

igl::TriangleStrip::TriangleStrip(const igl::TriangleStrip& s) throw() {
    p = s.p;
}

void igl::TriangleStrip::addPoint(igl::Point p) throw() {
    (this->p).push_back(p);
}

void igl::TriangleStrip::create() throw(igl::Exception) {
    if(p.size() < 3) {
        throw Exception("igl::TriangleStrip requires at least 3 points.");
    }

    Drawable::create();
}

void igl::TriangleStrip::draw(igl::Window * window) throw(igl::Exception) {
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
    glDrawArrays(GL_TRIANGLE_STRIP, 0, vertexBufferData.size()/3); // Starting from vertex 0; 3 vertices total -> 1 triangle

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

igl::TriangleStrip::~TriangleStrip() { }

