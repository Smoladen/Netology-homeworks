#ifndef FUNCTION_HEADER
#define FUNCTION_HEADER
#include <iostream>
#include <string>
#include <vector>
template <class T>
T square(T a){
    return a * a;
}
template <>
std::vector<int> square<std::vector<int>>(std::vector<int> v) {
    for (size_t i = 0; i < v.size(); i++) {
        v[i] = v[i] * v[i];
    }
    return v;
}

#endif
