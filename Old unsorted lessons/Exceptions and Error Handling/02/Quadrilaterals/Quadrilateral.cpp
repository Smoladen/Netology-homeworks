#include "Quadrilateral.h"
#include <iostream>

void Quadrilateral::print_info() {
    if (Quadrilateral::chec_status())
        status = "����������";
    else
        status = "������������";
    std::cout << name << '\n' << status << '\n' << "���������� ������: " << numOfSides << '\n' << "�������: a=" << a << " b=" << b << " c=" << c << "\n" << "����: A=" << A << " B=" << B << " C=" << C << "\n\n";
}
bool Quadrilateral::chec_status() {
    return (A + B + C + D == 360);
}