#ifndef FLYING_CARPET_H
#define FLYING_CARPET_H
#include "air_vehicle.h"
class flying_carpet : public AirVehicle{
public:
    flying_carpet();
    double calculateTime(double distance) override;
private:
    double speed = 10;
};

#endif
