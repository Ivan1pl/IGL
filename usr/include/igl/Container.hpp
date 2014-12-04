#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <vector>
#include <igl/Drawable.hpp>

namespace igl {
    class Window;

    /// Container for drawable objects.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class Container {
        protected:
            std::vector <Drawable*> objects;
        public:
            /// Default constructor.
            Container() throw();
            /// Copy contructor.
            /**
             * @param c container to copy
             */
            Container(const Container& c) throw();
            /// Add drawable object.
            /**
             * Objects will be drawn in the same order as they were added.
             * @param drawable object
             */
            void addObject(Drawable& drawable) throw();
            /// Destructor.
            virtual ~Container();
        protected:
            /// Draw all objects in this container.
            void drawAll(Window * window) throw(Exception);
    };
}

#endif /* CONTAINER_HPP */
