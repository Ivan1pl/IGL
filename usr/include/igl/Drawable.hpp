#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <igl/glheaders.hpp>
#include <igl/Exception.hpp>
#include <igl/Vertex.hpp>
#include <igl/Color.hpp>
#include <igl/Texture.hpp>
#include <vector>

namespace igl {
    class Window;
    /// Base class for all drawable objects.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class Drawable {
        protected:
            /// Vector of points this object contains.
            std::vector<Vertex> p;
            /// Vertex buffer used by OpenGL.
            std::vector<GLfloat> vertexBufferData;
            /// Vertex buffer identifier.
            GLuint vertexbuffer;
            /// Color buffer used by OpenGL.
            std::vector<GLfloat> colorBufferData;
            /// Color buffer identifier.
            GLuint colorbuffer;
            /// Normal buffer used by OpenGL.
            std::vector<GLfloat> normalBufferData;
            /// Normal buffer identifier.
            GLuint normalbuffer;
            /// UV buffer used by OpenGL.
            std::vector<GLfloat> UVBufferData;
            /// UV buffer identifier.
            GLuint UVbuffer;
            /// Texture.
            Texture texture;
            /// True if object has texture.
            bool textured;
        public:
            /// Default constructor.
            Drawable() throw(Exception);
            /// Copy constructor.
            /**
             * @param d object to copy
             */
            Drawable(const Drawable& d) throw();
            /// Create object.
            /**
             * This method is used to create vertex and color buffers.
             */
            virtual void create() throw(Exception);
            /// Set color of this object.
            /**
             * Sets color of each point to @p c.
             * @param c new color
             */
            virtual void setColor(Color c) throw();
            /// Draw this object.
            /**
             * @param window window
             */
            virtual void draw(Window * window) throw(Exception) = 0;
            /// Drawable destructor.
            virtual ~Drawable();
    };
}

#endif /* DRAWABLE_HPP */
