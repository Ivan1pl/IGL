#ifndef LINE_HPP
#define LINE_HPP

#include <igl/Drawable.hpp>

namespace igl {
    /// Drawable line.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class Line : public Drawable {
        public:
            /// Line constructor.
            /**
             * Create line connecting two points.
             * @param p1 first point
             * @param p2 second point
             */
            Line(Vertex p1, Vertex p2) throw(Exception);
            /// Copy constructor.
            /**
             * @param l line to copy
             */
            Line(const Line& l) throw();
            /// Draw this line.
            /**
             * @param window window
             */
            virtual void draw(Window * window) throw(Exception);
            /// Line destructor.
            virtual ~Line();
    };
}

#endif /* LINE_HPP */
