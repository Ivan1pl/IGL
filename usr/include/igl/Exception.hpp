#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <string>

namespace igl {
    /// IGL exception.
    /**
     * @author Mikołaj Nowak (Ivan1pl)
     */
    class Exception : public std::exception {
        private:
            std::string wh;
        public:
            /// Default constructor.
            Exception () throw();
            /// Create exception with message.
            /**
             * @param s message
             */
            Exception (std::string s) throw();
            /// Copy constructor.
            /**
             * @param e Exception to copy
             */
            Exception (const Exception& e) throw();
            /// Assignment operator.
            /**
             * @param e Exception to assign
             */
            Exception& operator= (const Exception& e) throw();
            /// Exception destructor.
            virtual ~Exception() throw();
            /// Get exception message.
            /**
             * @returns Exception message
             */
            const char* what() const throw();
    };
}

#endif /* EXCEPTION_HPP */
