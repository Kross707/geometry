#include "point.h"

point::point()
{
	x = y = 0;
}

point::point(double x, double y)
{
	this->x = x;
	this->y = y;
}

point point::origin()
{
	return point(0, 0);
}

point point::basisX()
{
	return point(1, 0);
}

point point::basisY()
{
	return point(0, 1);
}

point point::operator+(const point& p)
{
	return point(this->x + p.x, this->y + p.y);
}

point point::operator-(const point& p)
{
	return point(this->x - p.x, this->y - p.y);
}

point point::operator+=(const point& p)
{
	return *this + p;
}

point point::operator-=(const point& p)
{
	return *this - p;
}

double point::angleWithOrigin()
{
	return RAD2DEG*atan(this->y / this->x);
}

double point::slopeWithOrigin()
{
	return this->y / this->x;
}

double point::distanceFromOrigin()
{
	return sqrt(this->x*this->x + this->y*this->y);
}

const point operator*(double d, const point& p)
{
	return point(p.x * d, p.y * d);
}

const point operator*(const point& p, double d)
{
	return d * p;
}

const point operator/(const point& p, double d)
{
	return point(p.x / d, p.y / d);
}

const point operator*=(const point& p, double d)
{
	return d * p;
}

const point operator/=(const point& p, double d)
{
	return p / d;
}

std::ostream& operator<<(std::ostream& out, const point& p)
{
	out << "(" << p.x << ", " << p.y << ")";
	return out;
}

point pointsAverage(const std::initializer_list<point>& il)
{
	point result;
	for (auto a : il)
		result += a;

	return result/il.size();
}
