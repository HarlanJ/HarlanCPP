#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <math.h>

class Vector3{
	public:
		double x, y, z;

		Vector3(){
			this->x = this->y = this->z = 0;
		}

		Vector3(int x, int y, int z){
			this->x = (double)x;
			this->y = (double)y;
			this->z = (double)z;
		}

		Vector3(double x, double y, double z){
			this->x = x;
			this->y = y;
			this->z = z;
		}

		Vector3 normalize(){
			double mag = this->mag();
			this->x /= mag;
			this->y /= mag;
			this->z /= mag;
			return *this;
		}

		Vector3 normalize(Vector3 v){
			double m = v.mag();
			return Vector3(v.x/m, v.y/m, v.z/m);
		}

		Vector3 setMag(double m){
			double s = m / this->mag();
			this->x *= s;
			this->y *= s;
			this->z *= s;
			return *this;
		}

		double mag(){
			return sqrt( x*x + y*y + z*z);
		}

		Vector3 copy(){
			return Vector3(x, y, z);
		}

		Vector3 set(double x, double y, double z){
			this->x = x;
			this->y = y;
			this->z = z;
			return *this;
		}

		double dot(Vector3 b){
			return x*b.x + y*b.y + z*b.z;
		}

		Vector3 cross(Vector3 b){
			return Vector3(y*b.z - z*b.y, z*b.x - x*b.z, x*b.y - y*b.x);
		}

		static Vector3 cross(Vector3 a, Vector3 b){
			return Vector3(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
		}

		static Vector3 random(){
			int precision = 2000000000; //	should be divisable by 2, to remove pos/neg bias
			int adjust = precision/2;
			return Vector3(rand() % precision + adjust, rand() % precision + adjust, rand() % precision + adjust).normalize();
		}

		static Vector3 X(){
			return Vector3(1, 0, 0);
		}

		static Vector3 Y(){
			return Vector3(0, 1, 0);
		}

		static Vector3 Z(){
			return Vector3(0, 0, 1);
		}

		// Add/Sub vector
		class Vector3 operator+=(const Vector3& rhs){x += rhs.x; y += rhs.y, z += rhs.z; return *this;}
		class Vector3 operator-=(const Vector3& rhs){x -= rhs.x; y -= rhs.y, z -= rhs.z; return *this;}
		class Vector3 operator+(const Vector3& rhs){return Vector3(x+rhs.x, y+rhs.y, z+rhs.z);}
		class Vector3 operator-(const Vector3& rhs){return Vector3(x-rhs.x, y-rhs.y, z-rhs.z);}


		// Add/Sub/Mult/Div double
		class Vector3 operator+=(const double rhs){x += rhs; y += rhs, z += rhs; return *this;}
		class Vector3 operator-=(const double rhs){x -= rhs; y -= rhs, z -= rhs; return *this;}
		class Vector3 operator*=(const double rhs){x *= rhs; y *= rhs, z *= rhs; return *this;}
		class Vector3 operator/=(const double rhs){x /= rhs; y /= rhs, z /= rhs; return *this;}

		class Vector3 operator+(const double rhs){return Vector3(x+rhs, y+rhs, z+rhs);}
		class Vector3 operator-(const double rhs){return Vector3(x-rhs, y-rhs, z-rhs);}
		class Vector3 operator*(const double rhs){return Vector3(x*rhs, y*rhs, z*rhs);}
		class Vector3 operator/(const double rhs){return Vector3(x/rhs, y/rhs, z/rhs);}

		bool operator==(Vector3 *rhs){return x==rhs->x && y==rhs->y && z==rhs->z;}
};

#endif
