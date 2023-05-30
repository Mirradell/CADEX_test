#include "Curve.h"
#include "Point.h"

Curve::Curve() : Curve(Point())
{
}

Curve::Curve(Point p) : center{p}
{
}

Point Curve::GetPoint(float t)
{
	return Point();
}

Vector Curve::FirstDerivative(float t)
{
	return Vector();
}

Curve* Curve::CreateRandom()
{
	center = Point(rand(), rand());
	return this;
}

void Curve::Print()
{
	cout << "Center: ";
	center.print();
}

Curve::~Curve()
{
}
