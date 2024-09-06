#ifndef SQUARE_CLASS_H
#define SQUARE_CLASS_H
#include "Quadrilateral.h"

class Square : public Quadrilateral {
public:
    Square(int side_a, int side_b, int side_c, int side_d,
        int angle_A, int angle_B, int angle_C, int angle_D)
        : Quadrilateral(side_a, side_b, side_c, side_d, angle_A, angle_B, angle_C, angle_D) {
        name = "Квадрат: "; if (side_a != side_b || side_b != side_c || side_c != side_d)throw GeometryException("Не все сторонны равны\n"); else if (angle_A != 90 || angle_B != 90 || angle_C != 90 || angle_D != 90)throw GeometryException("Не все углы равны 90\n");
    }
    bool chec_status() override;
};
#endif