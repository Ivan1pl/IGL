#include <igl/Exception.hpp>

igl::Exception::Exception() throw() {
    wh = "Undefined IGL exception";
}

igl::Exception::Exception(std::string s) throw() {
    wh = s;
}

igl::Exception::Exception(const igl::Exception& e) throw() {
    wh = e.wh;
}

igl::Exception& igl::Exception::operator=(const igl::Exception& e) throw() {
    wh = e.wh;
    return (*this);
}

igl::Exception::~Exception() throw() { }

const char* igl::Exception::what() const throw() {
    return wh.c_str();
}
