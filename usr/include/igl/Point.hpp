#ifndef POINT_HPP
#define POINT_HPP

#include <igl/Drawable.hpp>

namespace igl {
    /// Drawable point.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class Point : public Drawable {
        public:
            /// Constructor.
            /**
             * @param p first and only vertex
             */
            Point(Vertex p) throw();
            /// Copy constructor.
            /**
             * @param p Point to copy
             */
            Point(const Point& p) throw();
            /// Draw this point.
            /**
             * @param window window
             */
            virtual void draw(Window * window) throw(Exception);
            /// Point destructor.
            virtual ~Point();
    };
}

#endif /* POINT_HPP */
