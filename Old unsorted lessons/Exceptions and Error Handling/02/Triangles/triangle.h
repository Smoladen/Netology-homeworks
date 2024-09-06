#ifndef TRIANGLE_CLASS_H
#define TRIANGLE_CLASS_H
#include "../figure.h"
#include "../GeometryException.h"

class Triangle : public Figure {
public:
    Triangle(int side_a, int side_b, int side_c, int angle_A, int angle_B, int angle_C)
        : Figure(side_a, side_b, side_c, angle_A, angle_B, angle_C) {
        name = "Треугольник: "; numOfSides = 3; status = "";
        if ((angle_A + angle_B + angle_C != 180)) {
            throw GeometryException("Сумма углов не равна 180 градусам\n");
        }
        else if (numOfSides != 3) {
            throw GeometryException("Количество сторон не равно 3\n");
        }
    }
    void print_info() override;
    bool chec_status() override;

};
#endif