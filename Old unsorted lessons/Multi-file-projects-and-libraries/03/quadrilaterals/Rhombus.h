#ifndef RHOMBUS_CLASS_H
#define RHOMBUS_CLASS_H
#include "Quadrilateral.h"

class Rhombus : public Quadrilateral {
public:
    Rhombus(int side_a, int side_b, int side_c, int side_d,
            int angle_A, int angle_B, int angle_C, int angle_D)
        : Quadrilateral(side_a, side_b, side_c, side_d, angle_A, angle_B, angle_C, angle_D) {name = "Ромб: ";}
    bool chec_status() override;
};
#endif
