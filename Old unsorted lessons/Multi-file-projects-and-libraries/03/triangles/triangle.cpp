#include "triangle.h"
#include <iostream>

void Triangle::print_info() {
    std::cout << name << '\n'<< '\n' << "Количество сторон: "<< numOfSides << '\n' << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n" << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
}

bool Triangle::chec_status() {
    return (a + b > c && a + c > b && b + c > a && A + B + C == 180 && numOfSides == 3);
}
