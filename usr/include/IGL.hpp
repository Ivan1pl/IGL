#ifndef IGL_HPP
#define IGL_HPP

#include <igl/glheaders.hpp>
#include <igl/Exception.hpp>
#include <igl/Window.hpp>
#include <igl/Key.hpp>
#include <igl/Point.hpp>
#include <igl/Color.hpp>
#include <igl/Drawable.hpp>
#include <igl/Triangle.hpp>
#include <igl/TriangleFan.hpp>
#include <igl/TriangleStrip.hpp>
#include <igl/Line.hpp>
#include <igl/Shader.hpp>
#include <igl/Font.hpp>
#include <igl/Text.hpp>

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
