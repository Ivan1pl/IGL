#ifndef MATRIXSTACK_HPP
#define MATRIXSTACK_HPP

#include <igl/glheaders.hpp>
#include <stack>

namespace igl {
    class Window;
    class Transformable;

    /// Matrix stack.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class MatrixStack {
        private:
            std::stack<glm::mat4> matrices;
            MatrixStack() throw();
            void pushMatrix(glm::mat4 matrix) throw();
            void popMatrix() throw();
            glm::mat4 top() throw();
        friend class Window;
        friend class Transformable;
    };
}

#endif /* MATRIXSTACK_HPP */
