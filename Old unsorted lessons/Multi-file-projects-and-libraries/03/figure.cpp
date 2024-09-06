#include "figure.h"
#include <iostream>

void Figure::print_info(){
    std::cout << name << '\n' << '\n' << "Количество сторон: " << numOfSides<< "\n\n";
};

bool Figure::chec_status(){
    return false;
}
