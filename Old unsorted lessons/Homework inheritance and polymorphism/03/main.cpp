#include <iostream>
#include <string>

class Figure {
protected:
    int numOfSides;
    std::string status;
    int a, b, c, d;
    int A, B, C, D;
    std::string name;
public:
    Figure(){name = "Фигура: "; numOfSides=0; status = "Правельный";}
    Figure(int a, int b, int c, int d, int A, int B, int C, int D) : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D){}
    Figure(int a, int b, int c, int A, int B, int C) : a(a), b(b), c(c), A(A), B(B), C(C){}

    //    virtual void print_info() = 0;
    virtual void print_info(){
        std::cout << name << '\n' << status << '\n' << "Количество сторон: " << numOfSides<< "\n\n";
    };
    virtual bool chec_status(){
        return false;
    }
};

class Triangle : public Figure {
public:
    Triangle(int side_a, int side_b, int side_c, int angle_A, int angle_B, int angle_C)
        : Figure(side_a, side_b, side_c, angle_A, angle_B, angle_C){name = "Треугольник: "; numOfSides = 3; status = "";}

    void print_info() override {
        if(chec_status())
            status = "Правельный";
        else
            status = "Неправельный";
        std::cout << name << '\n' << status << '\n' << "Количество сторон: "<< numOfSides << '\n' << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n" << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
    }
    bool chec_status()  override{
        return (a + b > c && a + c > b && b + c > a && A + B + C == 180 && numOfSides == 3);
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(int side_a, int side_b, int side_c, int angle_a, int angle_b, int angle_c)
        : Triangle(side_a, side_b, side_c, angle_a, angle_b, angle_c) { name = "Прямоугольный треугольник: ";}
    bool chec_status()  override{
        return (C == 90 && Triangle::chec_status());
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int side_a, int side_b, int side_c, int angle_a, int angle_b, int angle_c)
        : Triangle(side_a, side_b, side_c, angle_a, angle_b, angle_c) {name = "Равнобедренный треугольник: ";}
    bool chec_status()  override{
        return (a == c && A == C && Triangle::chec_status());
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int side_a, int side_b, int side_c, int angle_a, int angle_b, int angle_c)
        : Triangle(side_a, side_b, side_c, angle_a, angle_b, angle_c) {name = "Равносторонний треугольник: ";}
    bool chec_status()  override{
        return (a == b && b == c && A == B && B == C && Triangle::chec_status());
    }
};

class Quadrilateral : public Figure {
public:
    Quadrilateral(int side_a, int side_b, int side_c, int side_d,
                  int angle_A, int angle_B, int angle_C, int angle_D)
        : Figure(side_a, side_b, side_c, side_d, angle_A, angle_B, angle_C, angle_D) {name = "Четырёхугольник: "; numOfSides = 4; status = "";}

    void print_info() override {
        if(chec_status())
            status = "Правельный";
        else
            status = "Неправельный";
        std::cout << name << '\n'<< status << '\n' << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n" << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
    bool chec_status()  override{
        return ( A + B + C + D == 360);
    }
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(int side_a, int side_b, int side_c, int side_d,
              int angle_A, int angle_B, int angle_C, int angle_D)
        : Quadrilateral(side_a, side_b, side_c, side_d, angle_A, angle_B, angle_C, angle_D) {name = "Прямоугольник: ";}
    bool chec_status()  override{
        return (a == c && b == d && (A == B && B == C && C == D) && A == 90 && Quadrilateral::chec_status());
    }
};


class Square : public Quadrilateral {
public:
    Square(int side_a, int side_b, int side_c, int side_d,
           int angle_A, int angle_B, int angle_C, int angle_D)
        : Quadrilateral(side_a, side_b, side_c, side_d, angle_A, angle_B, angle_C, angle_D) {name = "Квадрат: ";}
    bool chec_status()  override{
        return (a==b && b==c && c==d && (A == B && B == C && C == D) && A == 90 && Quadrilateral::chec_status());
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(int side_a, int side_b, int side_c, int side_d,
                  int angle_A, int angle_B, int angle_C, int angle_D)
        : Quadrilateral(side_a, side_b, side_c, side_d, angle_A, angle_B, angle_C, angle_D) {name = "Параллелограмм: ";}
    bool chec_status()  override{
        return (a==c && b==d && A==C && B==D && Quadrilateral::chec_status());
    }
};

class Rhombus : public Quadrilateral {
public:
    Rhombus(int side_a, int side_b, int side_c, int side_d,
            int angle_A, int angle_B, int angle_C, int angle_D)
        : Quadrilateral(side_a, side_b, side_c, side_d, angle_A, angle_B, angle_C, angle_D) {name = "Ромб: ";}
    bool chec_status()  override{
        return (a==b && b==c && c==d && A==C && B==D &&Quadrilateral::chec_status());
    }
};

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
