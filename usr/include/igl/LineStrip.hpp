#ifndef LINESTRIP_HPP
#define LINESTRIP_HPP

#include <igl/Lines.hpp>

namespace igl {
    /// Drawable line strip.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class LineStrip : public Lines {
        public:
            /// Line strip constructor.
            /**
             * @param first first point
             */
            LineStrip(Point first) throw();
            /// Copy constructor.
            /**
             * @param l lines to copy
             */
            LineStrip(const LineStrip& l) throw();
            /// Draw line strip.
            /**
             * @param window window
             */
            virtual void draw(Window * window) throw(Exception);
            /// Lines destructor.
            virtual ~LineStrip();
    };
}

#endif /* LINESTRIP_HPP */
