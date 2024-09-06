#include "Quadrilateral.h"
#include <iostream>

void Quadrilateral::print_info(){
    std::cout << name << '\n'<< '\n' << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n" << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
}
bool Quadrilateral::chec_status(){
    return ( A + B + C + D == 360);
}
