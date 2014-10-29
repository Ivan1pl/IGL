#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <igl/glheaders.hpp>
#include <igl/Drawable.hpp>
#include <igl/Point.hpp>
#include <igl/Color.hpp>
#include <vector>

namespace igl {
    /// Drawable triangle.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class Triangle : public Drawable {
        public:
            /// Constructor.
            /**
             * @param p1 first point
             * @param p2 second point
             * @param p3 third point
             */
            Triangle(Point p1, Point p2, Point p3) throw(Exception);
            /// Copy constructor.
            /**
             * @param t Triangle to copy
             */
            Triangle(const Triangle& t) throw();
            /// Draw triangle.
            /**
             * @param window window
             */
            virtual void draw(Window * window) throw(Exception);
            /// Destructor.
            virtual ~Triangle();
    };
}

#endif /* TRIANGLE_HPP */
