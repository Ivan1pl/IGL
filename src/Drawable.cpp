#include <igl/Drawable.hpp>

igl::Drawable::Drawable() throw(igl::Exception) { }

igl::Drawable::Drawable(const igl::Drawable& d) throw() {
    p = d.p;
}

igl::Drawable::~Drawable() { }

void igl::Drawable::create() throw(igl::Exception) {
    vertexBufferData.clear();
    colorBufferData.clear();
    for(int i=0; i<p.size(); ++i) {
        vertexBufferData.push_back(p[i].getLocation().x);
        vertexBufferData.push_back(p[i].getLocation().y);
        vertexBufferData.push_back(p[i].getLocation().z);
        colorBufferData.push_back(Color::toFloat(p[i].getColor().r));
        colorBufferData.push_back(Color::toFloat(p[i].getColor().g));
        colorBufferData.push_back(Color::toFloat(p[i].getColor().b));
    }
    
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, vertexBufferData.size()*sizeof(GLfloat), vertexBufferData.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &colorbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glBufferData(GL_ARRAY_BUFFER, colorBufferData.size()*sizeof(GLfloat), colorBufferData.data(), GL_STATIC_DRAW);
}

void igl::Drawable::setColor(igl::Color c) throw() {
    for(int i=0; i<p.size(); ++i) {
        p[i].setColor(c);
    }
}
