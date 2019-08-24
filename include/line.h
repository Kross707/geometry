#pragma once
#include"point.h"
#include<limits>

void bringAngleToRange(double& angle, double range);

class line
{
public:
	point P;
	double angle, slope, constant;

	line();
	line(point P, double m, bool isAngle = false);
	line(point P, point Q);

	bool isPerpendicularTo(const line& L);
	bool isParallelTo(const line& L);
	bool isEqual(const line& L);
	bool hasPoint(const point& P);

	point pointOfIntersection(const line& L);

	double angleWith(const line& L);
	double angleBetween(const line& L);
	double angleWithX();
	double angleWithY();

	line angleBisector(const line& L);
	line PerpendicularFrom(point P);
};

