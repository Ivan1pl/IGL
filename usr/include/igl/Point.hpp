#ifndef POINT_HPP
#define POINT_HPP

#include <igl/Color.hpp>

namespace igl {
    /// Class representing point.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class Point {
        public:
            /// X coordinate.
            float x;
            /// Y coordinate.
            float y;
            /// Z coordinate.
            float z;
            /// Color.
            Color c;
            /// Default constructor.
            /**
             * @param x x coordinate
             * @param y y coordinate
             * @param z z coordinate
             * @param c color
             */
            Point(float x=.0f, float y=.0f, float z=.0f, Color c=Color()) throw();
            /// Copy constructor.
            /**
             * @param p Point to copy
             */
            Point(const Point& p) throw();
            /// Assignment operator.
            /**
             * @param p Point to assign
             */
            Point& operator=(const Point& p) throw();
            /// Check if points are equal.
            /**
             * @param p second point
             * @retval true if points are equal
             * @retval false otherwise
             */
            bool operator==(const Point& p) const throw();
    };
}

#endif /* POINT_HPP */
