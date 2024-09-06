#ifndef GEOMETRY_EXCEPTION_H
#define GEOMETRY_EXCEPTION_H
#include <exception>
#include <string>
class GeometryException : public std::exception {
public:
    GeometryException(const char* message) : msg(message) {}
    GeometryException(const std::string& message) : msg(message) {}
    virtual const char* what() const throw() {
        return msg.c_str();
    }
protected:
    std::string msg;
};
#endif