#include "IsoTriangle.h"

bool IsoscelesTriangle::chec_status(){
    return (a == c && A == C && Triangle::chec_status());
}
