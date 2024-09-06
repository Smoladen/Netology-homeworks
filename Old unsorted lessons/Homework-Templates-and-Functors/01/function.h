#ifndef FUNCTION_HEADER
#define FUNCTION_HEADER
#include <iostream>
#include <string>
#include <vector>
template <class T>
T square(T a){
    return a * a;
}
template <typename T>
std::vector<T> square(std::vector<T>& v) {
     std::vector<T> result(v.size());
    for (size_t i = 0; i < v.size(); i++) {
         result[i] = square(v[i]);
    }
    return result;
}
#endif
