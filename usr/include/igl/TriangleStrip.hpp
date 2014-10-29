#ifndef TRIANGLESTRIP_HPP
#define TRIANGLESTRIP_HPP

#include <igl/Drawable.hpp>

namespace igl {
    /// Drawable triangle strip.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class TriangleStrip : public Drawable {
        public:
            /// Constructor.
            /**
             * @param p first point
             */
            TriangleStrip(Point p) throw();
            /// Copy constructor.
            /**
             * @param s TriangleStrip to copy
             */
            TriangleStrip(const TriangleStrip& s) throw();
            /// Draw triangle strip.
            /**
             * @param window window
             */
            virtual void draw(Window * window) throw(Exception);
            /// Destructor.
            virtual ~TriangleStrip();
            /// Create object.
            void create() throw(Exception);
            /// Add point.
            /**
             * Two points have to be added to create first triangle, every next
             * point creates triangle with points (two previous points, this
             * point).
             * @param p point
             */
            void addPoint(Point p) throw();
    };
}

#endif /* TRIANGLESTRIP_HPP */
