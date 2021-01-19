#ifndef point3
#define point3

struct Point3D{
	double x, y, z;

	Point3D(){
		x = y = z = 0.0;
	}

	Point3D(double x, double y, double z){
		this->x = x;
		this->y = y;
		this->z = z;
	}
	
	Point3D set(double x, double y, double z){
		this->x = x;
		this->y = y;
		this->z = z;

		return *this;
	}

	struct Point3D& operator+=(const Point3D& rhs){x += rhs.x; y += rhs.y; z += rhs.z; return *this;}
	struct Point3D& operator-=(const Point3D& rhs){x -= rhs.x; y -= rhs.y; z -= rhs.z; return *this;}

	struct Point3D& operator+=(const double  rhs){x += rhs; y += rhs; z += rhs; return *this;}
	struct Point3D& operator-=(const double  rhs){x -= rhs; y -= rhs; z -= rhs; return *this;}

	struct Point3D& operator*=(const double s){x *= s; y *= s; z *= s; return *this;}
	struct Point3D& operator/=(const double s){x /= s; y /= s; z /= s; return *this;}
};

struct Point3D operator+(const Point3D l, const Point3D r){ return Point3D{l.x+r.x, l.y+r.y, l.z+r.z};};
struct Point3D operator-(const Point3D l, const Point3D r){ return Point3D{l.x-r.x, l.y-r.y, l.z-r.z};};

struct Point3D operator*(const Point3D l, const double s){ return Point3D{l.x*s, l.y*s, l.z*s};};
struct Point3D operator*(const double s, const Point3D l){ return Point3D{l.x*s, l.y*s, l.z*s};};

struct Point3D operator/(const Point3D l, const double s){ return Point3D{l.x/s, l.y/s, l.z/s};};
struct Point3D operator/(const double s, const Point3D l){ return Point3D{l.x/s, l.y/s, l.z/s};};
#endif
