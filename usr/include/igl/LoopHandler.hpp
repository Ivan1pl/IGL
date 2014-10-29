#ifndef LOOPHANDLER_HPP
#define LOOPHANDLER_HPP

#include <igl/Exception.hpp>

namespace igl {
    class Window;
    /// Base class for loop handlers.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class LoopHandler {
        protected:
            /// Window.
            Window * window;
        public:
            /// Constructor.
            /**
             * @param w window
             */
            LoopHandler(Window * w) throw();
            /// Execute action.
            /**
             * This method is run once each frame for loop handlers, or at
             * constant intervals for real time handlers.
             */
            virtual void exec() throw(Exception) = 0;
    };
}

#endif /* LOOPHANDLER_HPP */
