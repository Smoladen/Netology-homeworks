#ifndef FUGIRE_CLASS_H
#include "../figure.h"
#endif
#ifndef QUADRILATERAL_CLASS_H
#define QUADRILATERAL_CLASS_H
#include "../GeometryException.h"
class Quadrilateral : public Figure {
public:
    Quadrilateral(int side_a, int side_b, int side_c, int side_d,
        int angle_A, int angle_B, int angle_C, int angle_D)
        : Figure(side_a, side_b, side_c, side_d, angle_A, angle_B, angle_C, angle_D) {
        name = "Четырёхугольник: ", numOfSides = 4; if (numOfSides != 4)throw GeometryException("Количество сторон не равно 4\n"); else if (angle_A + angle_B + angle_C + angle_D != 360)throw GeometryException("Сумма углов не равна 360\n");
    }

    void print_info()  override;
    bool chec_status() override;
};
#endif