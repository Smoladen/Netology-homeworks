#include "eagle.h"
eagle::eagle(){

}

double eagle::calculateTime(double distance){
    Coefficient = (distance / 100) * 6;
    distance -= Coefficient;
    double time = distance / speed;
    return time;
}
