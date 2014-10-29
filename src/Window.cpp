#include <igl/Window.hpp>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <chrono>

glm::mat4 MVP;
GLuint MatrixID;

typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::milliseconds milliseconds;

igl::Window::Window() throw() {
    open = false;
}

igl::Window::Window(int width, int height, std::string name) throw(igl::Exception) {
    create(width,height,name);
}

void igl::Window::create(int width, int height, std::string name) throw(igl::Exception) {
    window = glfwCreateWindow( width, height, name.c_str(), NULL, NULL);
    if( window == NULL ){
        glfwTerminate();
        throw Exception("Failed to open GLFW window. Check if your GPU is OpenGL 3.3 compatible.");
    }
    glfwMakeContextCurrent(window); // Initialize GLEW 
    glewExperimental=true; // Needed in core profile 
    if (glewInit() != GLEW_OK) {
        throw Exception("Failed to initialize GLEW.");
    }
    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    open = true;
}

void igl::Window::setDefaultShader(igl::Shader shader) throw() {
    this->shader = shader;
}

void igl::Window::loop() throw(igl::Exception) {
    glm::mat4 identityMatrix = glm::mat4(1.0f);
    MVP = identityMatrix;
    MatrixID = glGetUniformLocation(shader, "MVP");
    Clock::time_point t = Clock::now();
    int delta = 5;
    int tim = 0;
    do{
        Clock::time_point n = Clock::now();
        milliseconds ms = std::chrono::duration_cast<milliseconds>(n - t);
        tim += ms.count();
        t = n;
        while(tim > delta) {
            tim -= delta;
            for(int i = 0; i < realtime_handlers.size(); ++i) {
                realtime_handlers[i]->exec();
            }
        }
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(shader);
        for(int i = 0; i < objects.size(); ++i) {
            glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
            objects[i]->draw(this);
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
        for(int i = 0; i < handlers.size(); ++i) {
            handlers[i]->exec();
        }
        if (glfwWindowShouldClose(window)) {
            close();
        }
    } while(open);
}

void igl::Window::close() throw() {
    open = false;
}

bool igl::Window::isKeyPressed(igl::Key::KeyType key) throw() {
    return (glfwGetKey(window, (int) key) == GLFW_PRESS);
}

void igl::Window::addLoopHandler(igl::LoopHandler& handler) throw() {
    handlers.push_back(&handler);
}

void igl::Window::addRealTimeHandler(igl::LoopHandler& handler) throw() {
    realtime_handlers.push_back(&handler);
}

void igl::Window::addObject(igl::Drawable& drawable) throw() {
    objects.push_back(&drawable);
}

void igl::Window::useShader(const igl::Shader& s) throw() {
    glUseProgram(s);
}

void igl::Window::useDefaultShader() throw() {
    glUseProgram(shader);
}

void igl::Window::useMatrix(glm::mat4& matrix) throw() {
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &matrix[0][0]);
}

void igl::Window::useDefaultMatrix() throw() {
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

