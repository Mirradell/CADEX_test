#include "Ellipse.h"
#include <stdexcept>
#include <cmath>

Ellipse::Ellipse() : Ellipse(Point(), 0, 0)
{
}

Ellipse::Ellipse(Point center) : Ellipse(center, 0, 0)
{
}

Ellipse::Ellipse(Point center, float radiusX, float radiusY)
{
	if (radiusX < 0 || radiusY < 0)
		throw invalid_argument("Radii must be positive!");

	this->radiusX = radiusX;
	this->radiusY = radiusY;
}

Point Ellipse::GetPoint(float t)
{
	return Point(radiusX * cos(t),
				 radiusY * sin(t),
				 0);
}

Vector Ellipse::FirstDerivative(float t)
{
	return Vector(Point(-1 * radiusX * sin(t),
						radiusY * cos(t),
						0));
}

Curve* Ellipse::CreateRandom()
{
	center = center.CreateRandomPoint();
	radiusX = abs(rand());
	radiusY = abs(rand());
	return this;
}

void Ellipse::Print()
{
	cout << "Ellipse: ";
	Curve::Print();
	cout << ", radius X: " << radiusX << ", radius Y: " << radiusY;
}
