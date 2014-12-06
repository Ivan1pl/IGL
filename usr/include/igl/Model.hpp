#ifndef MODEL_HPP
#define MODEL_HPP

#include <igl/Drawable.hpp>
#include <igl/glheaders.hpp>
#include <igl/Shader.hpp>
#include <vector>

namespace igl {
    class Window;

    /// 3D model.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class Model : public Drawable {
        public:
            /// Parse OBJ file format (beta).
            /**
             * @param path path to OBJ file
             * @retval true if parsed succesfully
             * @retval false otherwise
             */
            bool loadFromOBJ(std::string path) throw();
            /// Set texture.
            /**
             * @param t texture
             */
            void setTexture(Texture t) throw();
            /// Draw object.
            /**
             * @param window window
             */
            void draw(Window * window) throw(Exception);
    };
}

#endif /* MODEL_HPP */
