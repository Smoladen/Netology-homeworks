#ifndef AIR_VEHICLE_H
#define AIR_VEHICLE_H
#include "vehicle.h"
class AirVehicle : public vehicle{
protected:
    double Coefficient = 0;
public:
    AirVehicle() = default;
    AirVehicle(double distance) : vehicle(distance){}
    virtual double calculateTime(double distance);
};
#endif
