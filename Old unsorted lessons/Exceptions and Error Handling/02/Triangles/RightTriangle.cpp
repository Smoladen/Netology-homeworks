#include "RightTriangle.h"

bool RightTriangle::chec_status() {
	return (C == 90 && Triangle::chec_status());
}