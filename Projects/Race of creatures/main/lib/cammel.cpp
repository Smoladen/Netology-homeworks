#include "cammel.h"

cammel::cammel(){

}

double cammel::calculateTime(double distance){
    double time = distance / speed;
    int restCount = static_cast<int>(time / restTime);
    if((static_cast<int>(time) % static_cast<int>(restTime) == 0)){
        restCount--;}
    if(restCount > 1){
        restCount--;
        return time + restCount * restDurationOthers + restDurationFirst;
    } else if (static_cast<int>(time) % static_cast<int>(restTime) != 0) {
        return time + restDurationFirst;
    }
    return time;
}
