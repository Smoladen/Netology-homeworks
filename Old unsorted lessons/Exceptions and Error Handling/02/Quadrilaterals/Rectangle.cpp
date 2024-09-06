#include "Rectangle.h"

bool Rectangle::chec_status() {
	return (a == c && b == d && (A == B && B == C && C == D) && A == 90 && Quadrilateral::chec_status());
}