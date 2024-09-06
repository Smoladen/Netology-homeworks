#include <iostream>
#include "figure.h"
#include "Triangles/triangle.h"
#include "Triangles/RightTriangle.h"
#include "Triangles/IsoTriangle.h"
#include "Triangles/EquilateralTriangle.h"
#include "Quadrilaterals/Quadrilateral.h"
#include "Quadrilaterals/Rectangle.h"
#include "Quadrilaterals/Square.h"
#include "Quadrilaterals/Parallelogram.h"
#include "Quadrilaterals/Rhombus.h"
#include "GeometryException.h"

void print_info(Figure* figure) {
    figure->print_info();
}
int main() {
    setlocale(LC_ALL, "Russian");
    Figure figure;
    print_info(&figure);

    try {
        Triangle triangle(10, 21, 30, 50, 60, 80);
        print_info(&triangle);
    }
    catch (const GeometryException& error) {
        std::cout << "Ошибка создания фигуры. Причина: " << error.what() << std::endl;
    }

    try {
        RightTriangle right_triangle(10, 22, 30, 45, 45, 90);
        print_info(&right_triangle);
    }
    catch (const GeometryException& error) {
        std::cout << "Ошибка создания фигуры. Причина: " << error.what() << std::endl;
    }

    try {
        IsoscelesTriangle isosceles_triangle(10, 15, 10, 51, 80, 49);
        print_info(&isosceles_triangle);
    }
    catch (const GeometryException& error) {
        std::cout << "Ошибка создания фигуры. Причина: " << error.what() << std::endl;
    }

    try {
        EquilateralTriangle equilateral_triangle(10, 10, 10, 60, 60, 60);
        print_info(&equilateral_triangle);
    }
    catch (const GeometryException& error) {
        std::cout << "Ошибка создания фигуры. Причина: " << error.what() << std::endl;
    }

    try {
        Quadrilateral quadrilateral(10, 20, 30, 40, 95, 95, 89, 85);
        print_info(&quadrilateral);
    }
    catch (const GeometryException& error) {
        std::cout << "Ошибка создания фигуры. Причина: " << error.what() << std::endl;
    }

    try {
        Rectangle rectangle(10, 20, 10, 20, 90, 90, 90, 90);
        print_info(&rectangle);
    }
    catch (const GeometryException& error) {
        std::cout << "Ошибка создания фигуры. Причина: " << error.what() << std::endl;
    }

    try {
        Square square(20, 20, 30, 20, 90, 90, 90, 90);
        print_info(&square);
    }
    catch (const GeometryException& error) {
        std::cout << "Ошибка создания фигуры. Причина: " << error.what() << std::endl;
    }

    try {
        Parallelogram parallelogram(10, 20, 10, 20, 70, 115, 70, 105);
        print_info(&parallelogram);
    }
    catch (const GeometryException& error) {
        std::cout << "Ошибка создания фигуры. Причина: " << error.what() << std::endl;
    }

    try {
        Rhombus rhombus(30, 30, 30, 30, 110, 70, 110, 70);
        print_info(&rhombus);
    }
    catch (const GeometryException& error) {
        std::cout << "Ошибка создания фигуры. Причина: " << error.what() << std::endl;
    }

    return 0;
}
