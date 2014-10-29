#ifndef TEXT_HPP
#define TEXT_HPP

#include <igl/glheaders.hpp>
#include <igl/Drawable.hpp>
#include <igl/Shader.hpp>
#include <igl/Font.hpp>
#include <string>

namespace igl {
    /// 2D text.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class Text : public Drawable {
        private:
            GLuint Text2DVertexBufferID;
            GLuint Text2DUVBufferID;
            GLuint Text2DShaderID;
            GLuint Text2DUniformID;
            int x;
            int y;
            int size;
            Font f;
            std::string text;
            Shader shader;
            unsigned int vertices_s;
        public:
            /// Constructor.
            /**
             * @param s text to display
             * @param f font
             * @param size font size
             */
            Text(std::string s, Font f, int size) throw();
            /// Set position on screen.
            /**
             * @param x x coordinate
             * @param y y coordinate
             */
            void setPosition(int x, int y) throw();
            /// Set font size.
            /**
             * @param s new size
             */
            void setSize(int s) throw();
            /// Set font.
            /**
             * @param f new font
             */
            void setFont(Font f) throw();
            /// Create object.
            void create() throw();
            /// Set text to display.
            /**
             * @param text new text
             */
            void setText(std::string text) throw();
            /// Draw object.
            /**
             * @param window window
             */
            void draw(Window * window) throw();
    };
}

#endif /* TEXT_HPP */
