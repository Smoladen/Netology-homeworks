#include "broom.h"
broom::broom(){

}

double broom::calculateTime(double distance){
    int counter = 0;
    double temp_distance = distance;
    while(temp_distance >= 1000){
        counter++;
        temp_distance -= 1000;
    }
    Coefficient = (distance / 100) * counter;
    distance -= Coefficient;
    double time = distance / speed;
    return time;
}
