#ifndef VEHICLE_H
#define VEHICLE_H
class vehicle{
protected:
    double distance;
    double speed;

public:
    vehicle() = default;
    vehicle(double distance) : distance(distance) {}

    virtual double calculateTime(double distance);
};
#endif
