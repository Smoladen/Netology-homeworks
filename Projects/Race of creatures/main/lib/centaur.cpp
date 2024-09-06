#include "centaur.h"
centaur::centaur(){

}
double centaur::calculateTime(double distance){
    double time = distance / speed;
    int restCount = static_cast<int>(time / restTime);
    if((static_cast<int>(time) % static_cast<int>(restTime) == 0)){
        restCount--;}
    if(restCount > 1){
        return time + restCount * restDurationFirst;
    }
    return time;
}
