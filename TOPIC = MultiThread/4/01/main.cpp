#include <iostream>
#include "shape.cpp"


int main() {

    Line line(0, 0, 10, 0);
    std::cout << "Line Area: " << line.getArea() << " Line Volume: " << line.getVolume() << std::endl;

    Square square(0, 0, 5, 5);
    std::cout << "Square Area: " << square.getArea() << " Square Volume: " << square.getVolume() << std::endl;

    Cube cube(0, 0, 0, 3, 3, 3);
    std::cout << "Cube Area: " << cube.getArea() << " Cube Volume: " << cube.getVolume() << std::endl;

   Circle circle(0, 0, 5);
    std::cout << "Circle created. Area: " << circle.getArea() << ", Volume: " << circle.getVolume() << std::endl;

    Cylinder cylinder(0, 0, 3, 7);
    std::cout << "Cylinder created. Area: " << cylinder.getArea() << ", Volume: " << cylinder.getVolume() << std::endl;

    return 0;
}
