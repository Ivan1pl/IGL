#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <igl/Location.hpp>
#include <igl/Axis.hpp>
#include <igl/glheaders.hpp>
#include <igl/Exception.hpp>

namespace igl {
    class Window;

    /// Camera.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class Camera {
        public:
            /// Projection.
            /**
             * @author Mikołaj Nowak (Ivan1pl)
             */
            class Projection {
                private:
                    glm::mat4 ProjectionMatrix;
                    Projection() throw();
                    glm::mat4& getProjectionMatrix() throw();
                public:
                    /// Copy constructor.
                    /**
                     * @param p projection to copy
                     */
                    Projection(const Projection& p) throw();
                    /// Destructor.
                    virtual ~Projection();
                    /// Assignment operator.
                    /**
                     * @param p projection to assign
                     * @returns reference to modified projection
                     */
                    Projection& operator=(const Projection& p) throw();
                    /// Create perspective projection.
                    /**
                     * @param FoV horizontal field of view (in degrees)
                     * @param aspectRatio window aspect ratio
                     * @param near near clipping plane
                     * @param far far clipping plane
                     * @returns perspective projection to apply on a camera
                     */
                    static Projection perspective(float FoV, float aspectRatio, float near, float far) throw();
                friend class Camera;
            };
        private:
            Location position;
            Location target;
            Axis up;
            glm::mat4 View;
            Projection projection;
            glm::mat4& getView() throw();
            glm::mat4& getProjection() throw();
            Camera() throw();
        public:
            /// Constructor.
            /**
             * @param p projection
             * @param position camera position
             * @param target camera target
             * @param up up vector
             */
            Camera(Projection p, Location position, Location target, Axis up = Axis(0.0f,1.0f,0.0f)) throw(Exception);
            /// Copy constructor.
            /**
             * @param c camera to copy
             */
            Camera(const Camera& c) throw();
            /// Destructor.
            virtual ~Camera();
            /// Assignment operator.
            /**
             * @param c camera to assign
             * @returns reference to modified camera
             */
            Camera& operator=(const Camera& c) throw();
            /// Set camera position.
            /**
             * @param l new position
             */
            void setPosition(Location l) throw();
            /// Set camera target.
            /**
             * @param l new target
             */
            void setTarget(Location l) throw();
            /// Set up vector.
            /**
             * @param a new up vector
             */
            void setUpVector(Axis a) throw(Exception);
            /// Set projection.
            /**
             * @param p new projection
             */
            void setProjection(Projection p) throw();
        friend class Window;
    };
}

#endif /* CAMERA_HPP */
