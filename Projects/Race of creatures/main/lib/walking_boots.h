#ifndef WALKING_BOOTS_H
#define WALKING_BOOTS_H
#include "ground_vehicle.h"
class walking_boots : public GroundVehicle{
public:
    walking_boots();
    double calculateTime(double distance) override;
private:
    double speed = 6; // Скорость верблюда
    double restTime = 60; // Время движения до отдыха
    double restDurationFirst = 10; // Длительность отдыха первый раз
    double restDurationOthers = 5;
};

#endif
