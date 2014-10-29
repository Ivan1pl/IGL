#ifndef FONT_HPP
#define FONT_HPP

#include <igl/glheaders.hpp>
#include <string>

namespace igl {
    /// Class representing font.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class Font {
        private:
            GLuint textureID;
        public:
            /// Default constructor.
            Font() throw();
            /// Copy constructor.
            /**
             * @param f Font to copy
             */
            Font(const Font& f) throw();
            /// Assignment operator.
            /**
             * @param f Font to assign
             */
            Font& operator=(const Font& f) throw();
            /// Load font from DDS file.
            /**
             * @param path path to DDS file
             * @returns Font created from DDS file
             */
            static Font loadFromDDS(std::string path) throw();
            /// Get font texture identifier used by OpenGL.
            /**
             * @returns font texture identifier
             */
            GLuint getFontTexture() throw();
    };
}

#endif /* FONT_HPP */
