#ifndef GROUND_VEHICLE_H
#define GROUND_VEHICLE_H
#include "vehicle.h"
class GroundVehicle : public vehicle{
protected:
    double timeBeforeRest;
    double restDurationFirst;
    double restDurationOthers;
public:
    GroundVehicle() = default;
    GroundVehicle(double distance) : vehicle(distance){}
    virtual double calculateTime(double distance);
};
#endif
