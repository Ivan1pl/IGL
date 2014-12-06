#include <igl/Drawable.hpp>

igl::Drawable::Drawable() throw(igl::Exception) { }

igl::Drawable::Drawable(const igl::Drawable& d) throw() {
    p = d.p;
    texture = d.texture;
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
        normalBufferData.push_back(p[i].getNormal().x);
        normalBufferData.push_back(p[i].getNormal().y);
        normalBufferData.push_back(p[i].getNormal().z);
        UVBufferData.push_back(p[i].getUVs().x);
        UVBufferData.push_back(p[i].getUVs().y);
    }
    
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, vertexBufferData.size()*sizeof(GLfloat), vertexBufferData.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &colorbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glBufferData(GL_ARRAY_BUFFER, colorBufferData.size()*sizeof(GLfloat), colorBufferData.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &normalbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
    glBufferData(GL_ARRAY_BUFFER, normalBufferData.size()*sizeof(GLfloat), normalBufferData.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &UVbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, UVbuffer);
    glBufferData(GL_ARRAY_BUFFER, UVBufferData.size()*sizeof(GLfloat), UVBufferData.data(), GL_STATIC_DRAW);
}

void igl::Drawable::setColor(igl::Color c) throw() {
    for(int i=0; i<p.size(); ++i) {
        p[i].setColor(c);
    }
}
