#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <igl/glheaders.hpp>
#include <igl/Drawable.hpp>
#include <igl/Vertex.hpp>
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
            Triangle(Vertex p1, Vertex p2, Vertex p3) throw(Exception);
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
