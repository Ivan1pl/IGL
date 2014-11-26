#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <igl/Location.hpp>
#include <igl/Color.hpp>

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
    };
}

#endif /* VERTEX_HPP */
