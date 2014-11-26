#ifndef FILLEDCIRCLE_HPP
#define FILLEDCIRCLE_HPP

#include <igl/Drawable.hpp>
#include <igl/TriangleFan.hpp>

namespace igl {
    /// Filled 2D circle.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class FilledCircle : public Drawable {
        private:
            TriangleFan fan;
            float radius;
        public:
            /// Constructor.
            /**
             * @param center center
             * @param radius radius
             */
            FilledCircle(Vertex center, float radius) throw(Exception);
            /// Copy constructor.
            /**
             * @param fc circle to copy
             */
            FilledCircle(const FilledCircle& fc) throw();
            /// Draw circle.
            /**
             * @param window window
             */
            virtual void draw(Window * window) throw(Exception);
            /// Destructor.
            virtual ~FilledCircle();
            /// Create object.
            void create() throw();
            /// Set color.
            /**
             * @param c color
             */
            void setColor(Color c) throw();
    };
}

#endif /* FILLEDCIRCLE_HPP */
