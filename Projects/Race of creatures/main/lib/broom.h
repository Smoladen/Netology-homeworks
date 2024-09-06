#ifndef BROOM_H
#define BROOM_H
#include "air_vehicle.h"
class broom : public AirVehicle{
public:
    broom();
    double calculateTime(double distance) override;
private:
    double speed = 20;
};

#endif
