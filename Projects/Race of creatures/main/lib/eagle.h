#ifndef EAGLE_H
#define EAGLE_H
#include "air_vehicle.h"
class eagle : public AirVehicle{
public:
    eagle();
    double calculateTime(double distance) override;
private:
    double speed = 8;
};

#endif
