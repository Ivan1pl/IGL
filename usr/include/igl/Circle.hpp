#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <igl/Drawable.hpp>
#include <igl/LineStrip.hpp>

namespace igl {
    /// 2D circle.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class Circle : public Drawable {
        private:
            LineStrip lines;
            float radius;
        public:
            /// Constructor.
            /**
             * @param center center
             * @param radius radius
             */
            Circle(Vertex center, float radius) throw(Exception);
            /// Copy constructor.
            /**
             * @param c circle to copy
             */
            Circle(const Circle& c) throw();
            /// Draw circle.
            /**
             * @param window window
             */
            virtual void draw(Window * window) throw(Exception);
            /// Destructor.
            virtual ~Circle();
            /// Create object.
            void create() throw();
            /// Set color.
            /**
             * @param c color
             */
            void setColor(Color c) throw();
    };
}

#endif /* CIRCLE_HPP */
