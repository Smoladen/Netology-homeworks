#include <iostream>
#include "figure.h"
#include "triangles/triangle.h"
#include "triangles/RightTriangle.h"
#include "triangles/IsoTriangle.h"
#include "triangles/EquilateralTriangle.h"
#include "quadrilaterals/Quadrilateral.h"
#include "quadrilaterals/Rectangle.h"
#include "quadrilaterals/Square.h"
#include "quadrilaterals/Parallelogram.h"
#include "quadrilaterals/Rhombus.h"

void print_info(Figure* figure) {
    figure->print_info();
}
int main() {

    Figure figure;
    print_info(&figure);

    Triangle triangle(10, 21, 30, 50, 60, 70);
    print_info(&triangle);

    RightTriangle right_triangle(10, 22, 30, 45, 45, 90);
    print_info(&right_triangle);

    IsoscelesTriangle isosceles_triangle(10, 15, 10, 50, 80, 50);
    print_info(&isosceles_triangle);

    EquilateralTriangle equilateral_triangle(10, 10, 10, 60, 60, 60);
    print_info(&equilateral_triangle);

    Quadrilateral quadrilateral(10, 20, 30, 40, 95, 95, 85, 85);
    print_info(&quadrilateral);

    Rectangle rectangle(10, 20, 10, 20, 90, 90, 90, 90);
    print_info(&rectangle);

    Square square(20, 20, 20, 20, 90, 90, 90, 90);
    print_info(&square);

    Parallelogram parallelogram(10, 20, 10, 20, 70, 110, 70, 110);
    print_info(&parallelogram);

    Rhombus rhombus(30, 30, 30, 30, 110, 70, 110, 70);
    print_info(&rhombus);

    return 0;
}
