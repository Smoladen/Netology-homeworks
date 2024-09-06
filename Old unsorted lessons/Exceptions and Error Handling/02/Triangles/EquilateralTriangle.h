#ifndef  EQU_TRIANGLE_H
#define  EQU_TRIANGLE_H
#include "triangle.h"

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int side_a, int side_b, int side_c, int angle_a, int angle_b, int angle_c)
        : Triangle(side_a, side_b, side_c, angle_a, angle_b, angle_c) {
        name = "Равносторонний треугольник: "; if (side_a != side_b || side_b != side_c)throw GeometryException("Стороны не равны\n"); else if (angle_a != angle_b || angle_b != angle_c)throw GeometryException("Углы не равны\n");
    }
    bool chec_status() override;
};
#endif