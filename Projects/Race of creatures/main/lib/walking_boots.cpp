#include "walking_boots.h"

walking_boots::walking_boots(){

}

double walking_boots::calculateTime(double distance){
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
