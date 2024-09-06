#include "Quadrilateral.h"
#include <iostream>

void Quadrilateral::print_info(){
    if(Quadrilateral::chec_status())
        status = "Правельный";
    else
        status = "Неправельный";
    std::cout << name << '\n'<< status << '\n' << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n" << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
}
bool Quadrilateral::chec_status(){
    return ( A + B + C + D == 360);
}
