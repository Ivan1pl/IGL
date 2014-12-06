#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <igl/Location.hpp>
#include <igl/Color.hpp>
#include <igl/Axis.hpp>
#include <igl/glheaders.hpp>

namespace igl {
    /// Class representing vertex.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class Vertex {
        protected:
            /// Vertex location.
            Location l;
            /// Color.
            Color c;
            /// Normal.
            Axis n;
            /// UV coordinates.
            glm::vec2 UVs;
        public:
            /// Default constructor.
            /**
             * @param l location
             * @param c color
             */
            Vertex(Location l=Location(), Color c=Color()) throw();
            /// Copy constructor.
            /**
             * @param v Vertex to copy
             */
            Vertex(const Vertex& v) throw();
            /// Assignment operator.
            /**
             * @param v Vertex to assign
             */
            Vertex& operator=(const Vertex& v) throw();
            /// Get vertex's location.
            /**
             * @returns vertex's location
             */
            Location getLocation() const throw();
            /// Set vertex's location.
            /**
             * @param l new location
             */
            void setLocation(Location l) throw();
            /// Get vertex's color.
            /**
             * @returns vertex's color
             */
            Color getColor() const throw();
            /// Set vertex's color.
            /**
             * @param c new color
             */
            void setColor(Color c) throw();
            /// Get normal vector.
            /**
             * @returns normal vector
             */
            Axis getNormal() const throw();
            /// Set normal vector.
            /**
             * @param a normal vector
             */
            void setNormal(Axis a) throw();
            /// Get UV coordinates.
            /**
             * @returns UV coordinates
             */
            glm::vec2 getUVs() const throw();
            /// Set UV coordinates.
            /**
             * @param v UV coordinates
             */
            void setUVs(glm::vec2 v) throw();
    };
}

#endif /* VERTEX_HPP */
