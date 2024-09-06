#include "Square.h"

bool Square::chec_status() {
	return (a == b && b == c && c == d && (A == B && B == C && C == D) && A == 90 && Quadrilateral::chec_status());
}