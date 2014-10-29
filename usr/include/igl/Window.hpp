#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <igl/glheaders.hpp>
#include <igl/Exception.hpp>
#include <igl/Key.hpp>
#include <igl/LoopHandler.hpp>
#include <igl/Drawable.hpp>
#include <igl/Shader.hpp>
#include <vector>

namespace igl {
    /// Window.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class Window {
        private:
            GLFWwindow* window;
            bool open;
            std::vector <LoopHandler*> handlers;
            std::vector <LoopHandler*> realtime_handlers;
            std::vector <Drawable*> objects;
            Shader shader;
        public:
            /// Default constructor.
            Window() throw();
            /// Constructor.
            /**
             * This constructor automatically creates the window, so you don't
             * have to call @a create method.
             * @param width window width
             * @param height window height
             * @param name window title
             */
            Window(int width, int height, std::string name) throw(Exception);
            /// Create window.
            /**
             * @param width window width
             * @param height window height
             * @param name window title
             */
            void create(int width, int height, std::string name) throw(Exception);
            /// Set default shader.
            /**
             * For now it is necessary to call this method, it will become
             * optional in future versions.
             * @param shader shader
             */
            void setDefaultShader(Shader shader) throw();
            /// Run window loop.
            void loop() throw(Exception);
            /// Close window.
            void close() throw();
            /// Check if key is pressed.
            /**
             * @param key key
             * @retval true if @p key is pressed
             * @retval false otherwise
             */
            bool isKeyPressed(Key::KeyType key) throw();
            /// Add loop handler.
            /**
             * @param handler loop handler
             */
            void addLoopHandler(LoopHandler& handler) throw();
            /// Add real time handler.
            /**
             * @param handler real time handler
             */
            void addRealTimeHandler(LoopHandler& handler) throw();
            /// Add drawable object.
            /**
             * Objects will be drawn in the same order as they were added.
             * @param drawable object
             */
            void addObject(Drawable& drawable) throw();
            /// Use shader.
            /**
             * Set current shader to @p s.
             * @param s shader
             */
            void useShader(const Shader& s) throw();
            /// Use default shader.
            /**
             * Set current shader to default.
             */
            void useDefaultShader() throw();
            /// Use matrix.
            /**
             * This method will be removed or made private in future versions.
             * @param matrix matrix
             */
            void useMatrix(glm::mat4& matrix) throw();
            /// Use default matrix.
            /**
             * This method will be removed or made private in future versions.
             */
            void useDefaultMatrix() throw();
    };
}

#endif /* WINDOW_HPP */
