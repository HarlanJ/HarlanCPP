#ifndef HARLANCOMMON
#define HARLANCOMMON

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
}

#endif
