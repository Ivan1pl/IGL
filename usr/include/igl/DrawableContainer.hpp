#ifndef DRAWABLECONTAINER_HPP
#define DRAWABLECONTAINER_HPP

#include <igl/Drawable.hpp>
#include <igl/Container.hpp>

namespace igl {
    /// Drawable container.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class DrawableContainer : public Container, public Drawable {
        public:
            /// Default constructor.
            DrawableContainer() throw();
            /// Copy constructor.
            /**
             * @param d container to copy
             */
            DrawableContainer(const DrawableContainer& d) throw();
            /// Create object.
            /**
             * This method is used to create vertex and color buffers.
             */
            virtual void create() throw(Exception);
            /// Set color of this object.
            /**
             * Sets color of each point to @p c.
             * @param c new color
             */
            virtual void setColor(Color c) throw();
            /// Draw this object.
            /**
             * @param window window
             */
            virtual void draw(Window * window) throw(Exception);
            /// Drawable destructor.
            virtual ~DrawableContainer();
    };
}

#endif /* DRAWABLECONTAINER_HPP */
