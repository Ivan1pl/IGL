#ifndef SHADER_HPP
#define SHADER_HPP

#include <igl/Exception.hpp>
#include <igl/glheaders.hpp>
#include <string>

namespace igl {
    /// Class representing shader.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class Shader {
        private:
            GLuint programID;
        public:
            /// Shader constructor.
            Shader() throw();
            /// Copy constructor.
            /**
             * @param s Shader to copy.
             */
            Shader(const Shader& s) throw();
            /// Assignment operator.
            /**
             * @param s Shader to assign.
             */
            Shader& operator=(const Shader& s) throw();
            /// Cast operator.
            /**
             * @returns shader identifier used by OpenGL
             */
            operator GLuint() const throw();
            /// Load shader from file.
            /**
             * Shader should use OpenGL Shading Language version 3.30.
             * @param vertexPath path to vertex shader
             * @param fragmentPath path to fragment shader
             * @returns compiled shader
             */
            static Shader loadFromFile(std::string vertexPath, std::string fragmentPath) throw(Exception);
            /// Load shader from string.
            /**
             * Shader should use OpenGL Shading Language version 3.30.
             * @param vertexShader vertex shader code
             * @param fragmentShader fragment shader code
             * @returns compiled shader
             */
            static Shader loadFromString(std::string vertexShader, std::string fragmentShader) throw();
    };
}

#endif /* SHADER_HPP */
