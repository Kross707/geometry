#include "point.h"

point::point()
{
	x = y = aWO = 0;
}

point::point(double x, double y)
{
	this->x = x;
	this->y = y;
	aWO = atan2(this->y, this->x);
	if (aWO < 0)
		aWO + 360;
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

point point::infinite()
{
	return point(std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity());
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
	*this = *this + p;
	return *this;
}

point point::operator-=(const point& p)
{
	*this = *this - p;
	return *this;
}

double point::angleWithXRAD()
{
	return aWO;
}

double point::angleWithXDEG()
{
	return aWO * RAD2DEG;
}

double point::slopeWithX()
{
	if (this->x)
		return this->y / this->x;
	else return std::numeric_limits<double>::infinity();
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

const point operator*=(point& p, double d)
{
	p = d * p;
	return p;
}

const point operator/=(point& p, double d)
{
	p = p / d;
	return p;
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
