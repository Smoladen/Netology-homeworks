#ifndef CENTAUR_H
#define CENTAUR_H
#include "ground_vehicle.h"
class centaur : public GroundVehicle{
public:
    centaur();
    double calculateTime(double distance) override;
private:
    double speed = 15; // Скорость верблюда
    double restTime = 8; // Время движения до отдыха
    double restDurationFirst = 2; // Длительность отдыха первый раз
};

#endif
