#ifndef CAMMEL_SPEEDBOAT_H
#define CAMMEL_SPEEDBOAT_H
#include "ground_vehicle.h"
class cammel_speedboat : public GroundVehicle{
public:
    cammel_speedboat();
    double calculateTime(double distance) override;
private:
    double speed = 40; // Скорость верблюда
    double restTime = 10; // Время движения до отдыха
    double restDurationFirst = 5; // Длительность отдыха первый раз
    double restDurationSecond = 6.5;
    double restDurationOthers = 8;
};

#endif
