#include "flying_carpet.h"
flying_carpet::flying_carpet(){

}

double flying_carpet::calculateTime(double distance){
    if(distance > 1000 && distance < 5000){
        Coefficient = (distance / 100) * 3;
    }else if(distance < 10000){
        Coefficient = (distance / 100) * 10;
    }else if(distance >= 10000){
        Coefficient = (distance / 100) * 5;
    }
    distance -= Coefficient;
    double time = distance / speed;
    return time;
}
