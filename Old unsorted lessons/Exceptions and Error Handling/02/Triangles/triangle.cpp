#include "triangle.h"
#include <iostream>

void Triangle::print_info() {
    if (Triangle::chec_status())
        status = "����������";
    else
        status = "������������";
    std::cout << name << '\n' << status << '\n' << "���������� ������: " << numOfSides << '\n' << "�������: a=" << a << " b=" << b << " c=" << c << "\n" << "����: A=" << A << " B=" << B << " C=" << C << "\n\n";
}

bool Triangle::chec_status() {
    return (a + b > c && a + c > b && b + c > a && A + B + C == 180 && numOfSides == 3);
}