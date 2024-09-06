#ifndef RECTANGLE_CLASS_H
#define RECTANGLE_CLASS_H
#include "Quadrilateral.h"

class Rectangle : public Quadrilateral {
public:
    Rectangle(int side_a, int side_b, int side_c, int side_d,
        int angle_A, int angle_B, int angle_C, int angle_D)
        : Quadrilateral(side_a, side_b, side_c, side_d, angle_A, angle_B, angle_C, angle_D) {
        name = "�������������: "; if (angle_A != 90 || angle_B != 90 || angle_C != 90 || angle_D != 90) { throw GeometryException("�� ��� ���� ����� 90 ��������\n"); }
        else if (side_a != side_c) { throw GeometryException("������� � � � �� �����\n"); }
        else if (side_b != side_d)throw GeometryException("������� B � D �� �����\n");
    }
    bool chec_status() override;
};
#endif