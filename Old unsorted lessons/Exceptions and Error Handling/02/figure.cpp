#include "figure.h"
#include <iostream>

void Figure::print_info() {
	std::cout << name << '\n' << status << '\n' << "���������� ������: " << numOfSides << "\n\n";
};

bool Figure::chec_status() {
	return false;
}