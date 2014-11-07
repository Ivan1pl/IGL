#ifndef LINES_HPP
#define LINES_HPP

#include <igl/Drawable.hpp>

namespace igl {
    /// Drawable lines.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class Lines : public Drawable {
        public:
            /// Lines constructor.
            /**
             * @param first first point
             */
            Lines(Point first) throw();
            /// Copy constructor.
            /**
             * @param l lines to copy
             */
            Lines(const Lines& l) throw();
            /// Add point.
            /**
             * @param p point
             */
            void addPoint(Point p) throw();
            /// Create object.
            virtual void create() throw(Exception);
            /// Draw lines.
            /**
             * @param window window
             */
            virtual void draw(Window * window) throw(Exception);
            /// Lines destructor.
            virtual ~Lines();
    };
}

#endif /* LINES_HPP */
