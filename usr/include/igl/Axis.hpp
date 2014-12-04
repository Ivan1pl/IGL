#ifndef AXIS_HPP
#define AXIS_HPP

#include <igl/Exception.hpp>

namespace igl {
    /// Class representing axis.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class Axis {
        public:
            /// X component.
            float x;
            /// Y component.
            float y;
            /// Z component.
            float z;
            /// Default constructor.
            /**
             * @param x x component
             * @param y y component
             * @param z z component
             */
            Axis(float x=1.f, float y=.0f, float z=.0f) throw(Exception);
            /// Normalize axis.
            void normalize() throw(Exception);
    };
}

#endif /* AXIS_HPP */
