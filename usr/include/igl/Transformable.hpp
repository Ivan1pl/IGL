#ifndef TRANSFORMABLE_HPP
#define TRANSFORMABLE_HPP

#include <igl/DrawableContainer.hpp>
#include <igl/Axis.hpp>
#include <igl/glheaders.hpp>
#include <igl/Location.hpp>

namespace igl {
    /// Base class for all transformable objects.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class Transformable : public DrawableContainer {
        private:
            glm::mat4 Model;
            glm::mat4 translation;
            glm::mat4 scale;
            glm::mat4 rotation;
            Location origin;
        public:
            /// Default constructor.
            Transformable() throw(Exception);
            /// Copy constructor.
            /**
             * @param t object to copy
             */
            Transformable(const Transformable& t) throw();
            /// Destructor.
            virtual ~Transformable();
            /// Set container's translation.
            /**
             * @param x x offset
             * @param y y offset
             * @param z z offset
             */
            void setTranslation(float x, float y, float z) throw();
            /// Set container's rotation.
            /**
             * @param axis rotation axis
             * @param angle rotation angle
             */
            void setRotation(Axis axis, float angle) throw();
            /// Set container's rotation.
            /**
             * @param rx rotation angle (around x axis)
             * @param ry rotation angle (around y axis)
             * @param rz rotation angle (around z axis)
             */
            void setRotation(float rx, float ry, float rz) throw();
            /// Set container's scale.
            void setScale(float modifier) throw(Exception);
            /// Set container's origin.
            /**
             * @param l new origin
             */
            void setOrigin(Location l) throw();
            /// Get container's origin.
            /**
             * @returns container's origin
             */
            Location getOrigin() throw();
            /// Create object.
            void create() throw(Exception);
            /// Draw object.
            /**
             * @param window window
             */
            void draw(Window * window) throw(Exception);
    };
}

#endif /* TRANSFORMABLE_HPP */
