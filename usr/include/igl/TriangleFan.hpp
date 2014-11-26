#ifndef TRIANGLEFAN_HPP
#define TRIANGLEFAN_HPP

#include <igl/Drawable.hpp>
#include <igl/Vertex.hpp>
#include <igl/Color.hpp>
#include <vector>

namespace igl {
    /// Drawable triangle fan.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class TriangleFan : public Drawable {
        public:
            /// Constructor.
            /**
             * @param p fan center
             */
            TriangleFan(Vertex p) throw();
            /// Copy constructor.
            /**
             * @param f TriangleFan to copy
             */
            TriangleFan(const TriangleFan& f) throw();
            /// Draw triangle fan.
            /**
             * @param window window
             */
            virtual void draw(Window * window) throw(Exception);
            /// Destructor.
            virtual ~TriangleFan();
            /// Create object.
            void create() throw(Exception);
            /// Add point to fan.
            /**
             * Two points have to be added to create first triangle, every next
             * point creates triangle with points (center, previous point, this
             * point).
             * @param p point
             */
            void addPoint(Vertex p) throw();
    };
}

#endif /* TRIANGLEFAN_HPP */
