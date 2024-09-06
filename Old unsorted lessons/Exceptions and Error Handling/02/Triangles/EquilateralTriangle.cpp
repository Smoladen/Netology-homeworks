#include "EquilateralTriangle.h"

bool EquilateralTriangle::chec_status() {
	return (a == b && b == c && A == B && B == C && Triangle::chec_status());
}