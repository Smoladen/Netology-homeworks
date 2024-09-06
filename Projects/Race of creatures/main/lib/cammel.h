#ifndef CAMMEL_H
#define CAMMEL_H
#include "ground_vehicle.h"
class cammel : public GroundVehicle{
public:
    cammel();
    double calculateTime(double distance) override;
private:
    double speed = 10; // Скорость верблюда
    double restTime = 30; // Время движения до отдыха
    double restDurationFirst = 5; // Длительность отдыха первый раз
    double restDurationOthers = 8;
};

#endif
