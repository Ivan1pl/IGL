#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <igl/glheaders.hpp>
#include <string>

namespace igl {
    class Drawable;

    /// Texture.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class Texture {
        private:
            GLuint id;
            Texture() throw();
        public:
            /// Copy constructor.
            /**
             * @param t texture to copy
             */
            Texture(const Texture& t) throw();
            /// Destructor.
            virtual ~Texture();
            /// Assignment operator.
            /**
             * @param t texture to assign
             * @returns reference to modified texture
             */
            Texture& operator=(const Texture& t) throw();
            /// Cast operator.
            operator GLuint() throw();
            /// Texture loader.
            /**
             * @param path path to image
             * @returns texture object containing specified image
             */
            static Texture loadFromDDS(std::string path) throw();
        friend class Drawable;
    };
}

#endif /* TEXTURE_HPP */
