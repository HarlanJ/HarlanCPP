#ifndef QUATERNION
#define QUATERNION

#include "math.h"
#include "john/Vector3.hpp"

namespace Quaternion{
	struct Quaternion{
		double r, i, j, k;
	};
	
	//*
	Quaternion mult(Quaternion l, Quaternion r){
		return Quaternion{
			l.r*r.r - l.i*r.i - l.j*r.j - l.k*r.k,
			l.r*r.i + l.i*r.r + l.j*r.k - l.k*r.j,
			l.r*r.j - l.i*r.k + l.j*r.r + l.k*r.i,
			l.r*r.k + l.i*r.j - l.j*r.i + l.k*r.r
		};
	}
	// */

	struct Quaternion fromVector3(Vector3 v){
		return Quaternion{0, v.x, v.y, v.z};
	}

	Vector3 toVector3(Quaternion q){
		return Vector3(q.i, q.j, q.k);
	}
	
	//*
	Vector3 rotate(Vector3 point, Vector3 axis, double theta){
		axis.normalize();

		Quaternion r = fromVector3(axis * sin(theta/2));
		r.r = cos(theta/2);
		
		Quaternion R = fromVector3(axis * sin(theta/-2));
		R.r = cos(theta/-2);
		
		return toVector3(mult(mult(r, fromVector3(point)), R));
	}
	// */
	
	/*
	Quaternion invert(Quaternion q){
		return Quaternion(q.a, -q.b, -q.c, -q.d);
	}
	*/
}
#endif
