#ifndef RHOMBUS_CLASS_H
#define RHOMBUS_CLASS_H
#include "Quadrilateral.h"

class Rhombus : public Quadrilateral {
public:
    Rhombus(int side_a, int side_b, int side_c, int side_d,
        int angle_A, int angle_B, int angle_C, int angle_D)
        : Quadrilateral(side_a, side_b, side_c, side_d, angle_A, angle_B, angle_C, angle_D) {
        name = "Ромб: "; if (side_a != side_b || side_b != side_c || side_c != side_d)throw GeometryException("Не все стороны равны"); else if (angle_A != angle_C)throw GeometryException("Углы А и С не равны"); else if (angle_B != angle_D)throw GeometryException("Углы B и D не равны");
    }
    bool chec_status() override;
};
#endif