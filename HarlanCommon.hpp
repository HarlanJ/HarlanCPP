#ifndef HARLANCOMMON
#define HARLANCOMMON

#include <stdlib.h>

namespace Harlan{
	const double PI 		= 3.14159265358979323846;
	const double TWO_PI = 6.28318530717958647692;

	double deg(double r){
		return (180*r)/PI;
	}

	double rad(double d){
		return (d*PI)/180;
	}

	bool inTolerance(double a, double b, double tol){
		if(a > b){
			return (a-b) <= tol;
		} else {
			return (b-a) <= tol;
		}
	}

	struct Range{
		double bottom;
		double top;
	};

	bool inRange(double val, Range r){
		return (val > r.bottom && val < r.top);
	}

	double getRandInRange(Range r){
		return std::rand() / (RAND_MAX / (r.top-r.bottom));
	}
}

#endif
