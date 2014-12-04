#ifndef IGL_HPP
#define IGL_HPP

#include <igl/glheaders.hpp>
#include <igl/Exception.hpp>
#include <igl/Window.hpp>
#include <igl/Key.hpp>
#include <igl/Location.hpp>
#include <igl/Color.hpp>
#include <igl/Axis.hpp>
#include <igl/Vertex.hpp>
#include <igl/Drawable.hpp>
#include <igl/Point.hpp>
#include <igl/Triangle.hpp>
#include <igl/TriangleFan.hpp>
#include <igl/TriangleStrip.hpp>
#include <igl/Line.hpp>
#include <igl/Shader.hpp>
#include <igl/Font.hpp>
#include <igl/MatrixStack.hpp>
#include <igl/Text.hpp>
#include <igl/Lines.hpp>
#include <igl/LineStrip.hpp>
#include <igl/FilledCircle.hpp>
#include <igl/Circle.hpp>
#include <igl/Container.hpp>
#include <igl/DrawableContainer.hpp>
#include <igl/Transformable.hpp>

/// Library namespace.
namespace igl {
    /// Initialize library.
    /**
     * It is necessary to run this function before using any other OpenGL,
     * GLEW, GLFW or IGL function or class.
     */
    void iglInit() throw(Exception);
}

#endif /* IGL_HPP */
