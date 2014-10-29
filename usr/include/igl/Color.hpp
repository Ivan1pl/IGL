#ifndef COLOR_HPP
#define COLOR_HPP

#include <igl/Exception.hpp>
#include <igl/glheaders.hpp>

namespace igl {
    /// RGBA color.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class Color {
        public:
            /// Red intensity.
            int r;
            /// Green intensity.
            int g;
            /// Blue intensity.
            int b;
            /// Alpha channel.
            int a;
            /// Color constructor.
            /**
             * @param r red intensity
             * @param g green intensity
             * @param b blue intensity
             * @param a alpha channel
             */
            Color(int r=0, int g=0, int b=0, int a=0) throw(Exception);
            /// Copy constructor.
            /**
             * @param c color to copy
             */
            Color(const Color& c) throw();
            /// Assignment operator.
            /**
             * @param c color to assign
             */
            Color& operator=(const Color& c) throw();
            /// Converts intensity to float.
            /**
             * This function maps intensity from [0,255] to [0,1] required by
             * OpenGL.
             * @param v intensity value
             * @returns intensity value mapped to [0,1]
             */
            static GLfloat toFloat(int v);
    };
}

#endif /* COLOR_HPP */
