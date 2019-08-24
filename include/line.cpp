#include "line.h"

line::line()
{
	P = point(0, 0);
	slope = angle = 0;
	this->constant = 0;
}

line::line(point P, double m, bool isAngle)
{
	this->P = P;
	if (isAngle)
	{
		this->angle = m;
		bringAngleToRange(this->angle, 2 * PI);
		if (this->angle == PI/2 || this->angle == 3*PI/2)
			slope = std::numeric_limits<double>::infinity();
		else slope = tan(this->angle);
	}
	else
	{
		this->slope = m;
		this->angle = atan(m);
	}
	this->constant = this->P.y - this->slope * this->P.x;
}

line::line(point P, point Q)
{
	this->P = P;
	point temp = P - Q;
	this->slope = temp.slopeWithX();
	this->angle = temp.angleWithXRAD();
	bringAngleToRange(this->angle, 2 * PI);
	this->constant = this->P.y - this->slope * this->P.x;
}

bool line::isPerpendicularTo(const line& L)
{
	if (this->slope * L.slope == -1)
		return true;
	else if ( ( this->slope == 0 && L.slope == std::numeric_limits<double>::infinity() ) || ( L.slope == 0 && this->slope == std::numeric_limits<double>::infinity() ) )
		return true;
	else return false;
}

bool line::isParallelTo(const line& L)
{
	if (this->slope == L.slope)
		return true;
	else return false;
}

bool line::isEqual(const line& L)
{
	if (this->slope == L.slope && this->constant == L.constant)
		return true;
	else return false;
}

bool line::hasPoint(const point& P)
{
	if (P.y == this->slope * P.x + constant)
		return true;
	else return false;
}

point line::pointOfIntersection(const line& L)
{
	if (!this->isParallelTo(L))
	{
		double tmp = (L.constant - this->constant) / (this->slope - L.slope);
		return point(tmp, tmp * this->slope + this->constant);
	}
	else if (this->isEqual(L))
		return this->P;
	else return point::infinite();
}

double line::angleWith(const line& L)
{
	return this->angle - L.angle;
}

double line::angleBetween(const line& L)
{
	return fabs(this->angle - L.angle);
}

double line::angleWithX()
{
	return this->angle;
}

double line::angleWithY()
{
	return this->angle - PI/2;
}

line line::angleBisector(const line& L)
{
	double resultAngle;
	if (this->angle <= L.angle)
		resultAngle = this->angle + angleBetween(L)/2;
	else resultAngle = L.angle + angleBetween(L)/2;
	return line(pointOfIntersection(L),resultAngle,true);
}

line line::PerpendicularFrom(point P)
{
	return line(P, -1/this->slope);
}

void bringAngleToRange(double& angle, double range)
{
	if (angle >= 0)
		angle = fmod(angle, range);
	else angle = range + fmod(angle, range);
}
