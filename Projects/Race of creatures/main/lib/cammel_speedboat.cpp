#include "cammel_speedboat.h"

cammel_speedboat::cammel_speedboat(){

}

double cammel_speedboat::calculateTime(double distance){
    double time = distance / speed;
    int restCount = static_cast<int>(time / restTime);
    if((static_cast<int>(time) % static_cast<int>(restTime) == 0)){
        restCount--;}
    if(restCount > 2){
        restCount -=2;
        return time + restCount * restDurationOthers + restDurationFirst + restDurationSecond;
    }else if(restCount == 2){
        return time + restDurationFirst + restDurationSecond;
    }else if((static_cast<int>(time) % static_cast<int>(restTime)) != 0){
        return time + restDurationFirst;
    }
    return time;
}
