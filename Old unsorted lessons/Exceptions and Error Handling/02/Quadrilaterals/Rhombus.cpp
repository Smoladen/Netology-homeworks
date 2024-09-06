#include "Rhombus.h"

bool Rhombus::chec_status() {
	return (a == b && b == c && c == d && A == C && B == D && Quadrilateral::chec_status());
}