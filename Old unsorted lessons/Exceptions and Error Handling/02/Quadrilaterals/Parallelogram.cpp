#include "Parallelogram.h"

bool Parallelogram::chec_status() {
	return (a == c && b == d && A == C && B == D && Quadrilateral::chec_status());
}