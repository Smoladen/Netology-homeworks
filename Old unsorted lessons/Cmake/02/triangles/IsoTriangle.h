#ifndef  ISO_TRIANGLE_H
#define  ISO_TRIANGLE_H
#include "triangle.h"

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int side_a, int side_b, int side_c, int angle_a, int angle_b, int angle_c)
        : Triangle(side_a, side_b, side_c, angle_a, angle_b, angle_c) {name = "Равнобедренный треугольник: ";}

    bool chec_status()  override;
};
#endif
