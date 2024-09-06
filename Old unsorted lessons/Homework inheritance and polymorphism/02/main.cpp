#include <iostream>
#include <string>

class Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;
    std::string name;
public:
    Figure(int a, int b, int c, int d, int A, int B, int C, int D) : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D){}
    Figure(int a, int b, int c, int A, int B, int C) : a(a), b(b), c(c), A(A), B(B), C(C){}

    virtual void print_info() const = 0;
};

class Triangle : public Figure {
public:
    Triangle(int side_a, int side_b, int side_c, int angle_A, int angle_B, int angle_C)
        : Figure(side_a, side_b, side_c, angle_A, angle_B, angle_C) {name = "Треугольник: ";}

    void print_info() const override {
        std::cout << name << '\n' << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n" << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(int side_a, int side_b, int side_c, int angle_a, int angle_b)
        : Triangle(side_a, side_b, side_c, angle_a, angle_b, 90) { name = "Прямоугольный треугольник: ";}
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int side_a_c, int side_b, int base_angle)
        : Triangle(side_a_c, side_b, side_a_c, base_angle, 180 - 2 * base_angle, base_angle) {name = "Равнобедренный треугольник: ";}
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int side)
        : Triangle(side, side, side, 60, 60, 60) {name = "Равносторонний треугольник: ";}
};

class Quadrilateral : public Figure {
public:
    Quadrilateral(int side_a, int side_b, int side_c, int side_d,
                  int angle_A, int angle_B, int angle_C, int angle_D)
        : Figure(side_a, side_b, side_c, side_d, angle_A, angle_B, angle_C, angle_D) {name = "Четырёхугольник: ";}

    void print_info() const override {
        std::cout << name << '\n' << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n" << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(int side_a, int side_b)
        : Quadrilateral(side_a, side_b, side_a, side_b, 90, 90, 90, 90) {name = "Прямоугольник: ";}
};

class Square : public Rectangle {
public:
    Square(int side)
        : Rectangle(side, side) {name = "Квадрат: ";}
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(int side_a, int side_b, int angle)
        : Quadrilateral(side_a, side_b, side_a, side_b, angle, 180 - angle, angle, 180 - angle) {name = "Параллелограмм: ";}
};

class Rhombus : public Parallelogram {
public:
    Rhombus(int side, int angle)
        : Parallelogram(side, side, angle) {name = "Ромб: ";}
};

void print_info(const Figure* figure) {
    figure->print_info();
}

int main() {
    Triangle triangle(10, 20, 30, 50, 60, 70);
    print_info(&triangle);

    RightTriangle right_triangle(10, 20, 30, 40, 50);
    print_info(&right_triangle);

    IsoscelesTriangle isosceles_triangle(10,20, 50);
    print_info(&isosceles_triangle);

    EquilateralTriangle equilateral_triangle(30);
    print_info(&equilateral_triangle);

    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    print_info(&quadrilateral);

    Rectangle rectangle(10, 20);
    print_info(&rectangle);

    Square square(20);
    print_info(&square);

    Parallelogram parallelogram(20, 30, 60);
    print_info(&parallelogram);

    Rhombus rhombus(30, 30);
    print_info(&rhombus);

    return 0;
}
