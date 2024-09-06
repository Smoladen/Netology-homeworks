#ifndef RIGHT_TRIANGLE_H
#define RIGHT_TRIANGLE_H
#include "triangle.h"

class RightTriangle : public Triangle {
public:
    RightTriangle(int side_a, int side_b, int side_c, int angle_a, int angle_b, int angle_c)
        : Triangle(side_a, side_b, side_c, angle_a, angle_b, angle_c) {
        name = "Прямоугольный треугольник: "; if (angle_c != 90) { throw GeometryException("Угол C не равен 90 градусам\n"); }
    }

    bool chec_status() override;
};
#endif