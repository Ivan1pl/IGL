#include <igl/Window.hpp>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>

std::string vs = std::string("#version 330 core\n")+
                    "layout(location = 0) in vec3 vertexPosition_modelspace;\n"+
                    "layout(location = 1) in vec3 vertexColor;\n"+
                    "layout(location = 2) in vec3 vertexNormal;\n"+
                    "layout(location = 3) in vec2 vertexUV;\n"+
                    "out vec3 fragmentColor;\n"+
                    "out vec2 UV;\n"+
                    "flat out int tex;\n"+
                    "\n"+
                    "uniform mat4 MVP;\n"+
                    "uniform int useTex = 0;\n"+
                    "\n"+
                    "void main(){\n"+
                    "    gl_Position = MVP * vec4(vertexPosition_modelspace,1);\n"+
                    "    fragmentColor = vertexColor;\n"+
                    "    UV = vertexUV;\n"+
                    "    tex = useTex;\n"+
                    "}\n";
std::string fs = std::string("#version 330 core\n")+
                    "\n"+
                    "out vec3 color;\n"+
                    "in vec3 fragmentColor;\n"+
                    "in vec2 UV;\n"+
                    "flat in int tex;\n"+
                    "\n"+
                    "uniform sampler2D myTextureSampler;\n"+
                    "\n"+
                    "void main()\n"+
                    "{\n"+
                    "\n"+
                    "    if(tex == 1) {\n"+
                    "        color = texture2D( myTextureSampler, UV ).rgb;\n"+
                    "    } else {\n"+
                    "        color = fragmentColor;\n"+
                    "    }\n"+
                    "};\n";

typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::milliseconds milliseconds;

igl::Window::Window() throw() {
    open = false;
}

igl::Window::Window(int width, int height, std::string name) throw(igl::Exception) {
    create(width,height,name);
}

igl::MatrixStack& igl::Window::getMatrixStack() throw() {
    return ms;
}

void igl::Window::updateMVP() throw() {
    MVP = camera.getProjection() * camera.getView() * ms.top();
    MatrixID = glGetUniformLocation(shader, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
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
    this->width = width;
    this->height = height;
    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);
    // Cull triangles which normal is not towards the camera
    glEnable(GL_CULL_FACE);
    shader = Shader::loadFromString(vs,fs);
}

void igl::Window::setDefaultShader(igl::Shader shader) throw() {
    this->shader = shader;
}

void igl::Window::loop() throw(igl::Exception) {
    Clock::time_point t = Clock::now();
    int delta = 5;
    int tim = 0;
    do{
        glfwGetWindowSize(window,&width,&height);
        glViewport(0,0,width,height);
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
        updateMVP();
        drawAll(this);
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

void igl::Window::useShader(const igl::Shader& s) throw() {
    glUseProgram(s);
}

void igl::Window::useDefaultShader() throw() {
    glUseProgram(shader);
}

int igl::Window::getWidth() throw() {
    return width;
}

int igl::Window::getHeight() throw() {
    return height;
}

igl::Shader igl::Window::getDefaultShader() throw() {
    return shader;
}

float igl::Window::getAspectRatio() throw() {
    return ((float) width)/((float) height);
}

igl::Camera& igl::Window::getCamera() throw() {
    return camera;
}

void igl::Window::setCamera(const igl::Camera& c) throw() {
    camera = c;
}

