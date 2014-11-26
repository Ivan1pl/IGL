#ifndef LOCATION_HPP
#define LOCATION_HPP

namespace igl {
    /// Location.
    /*
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class Location {
        public:
            /// X coordinate.
            float x;
            /// Y coordinate.
            float y;
            /// Z coordinate.
            float z;
            /// Default constructor.
            /**
             * @param x x coordinate
             * @param y y coordinate
             * @param z z coordinate
             */
            Location(float x=.0f, float y=.0f, float z=.0f) throw();
            /// Copy constructor.
            /**
             * @param l Location to copy
             */
            Location(const Location& l) throw();
            /// Assignment operator.
            /**
             * @param l Location to assign
             */
            Location& operator=(const Location& l) throw();
            /// Check if locations are equal.
            /**
             * @param l second location
             * @retval true if locations are equal
             * @retval false otherwise
             */
            bool operator==(const Location& l) const throw();
    };
}

#endif /* LOCATION_HPP */
