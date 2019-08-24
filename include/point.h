#pragma once
#include<sstream>
#include <initializer_list>
#include<cmath>

const double PI = 3.1415926535897932384626433832;
const double DEG2RAD = 0.0174532925199432957692369076;
const double RAD2DEG = 57.295779513082320876798154814;

class point
{
public:
	double x, y;
	point();
	point(double, double);

	static point origin();
	static point basisX();
	static point basisY();

	point operator +(const point& p);
	point operator -(const point& p);
	point operator +=(const point& p);
	point operator -=(const point& p);

	double angleWithOrigin();
	double slopeWithOrigin();
	double distanceFromOrigin();

};

const point operator*(double d, const point& p);
const point operator*(const point& p, double d);
const point operator/(const point& p, double d);
const point operator*=(point& p, double d);
const point operator/=(point& p, double d);
std::ostream& operator << (std::ostream& out, const point& p);



point pointsAverage(const std::initializer_list<point>& il);
