#include "Helix.h"
#include <stdexcept>

Helix::Helix() : Helix(Point(), 0, 0)
{
}

Helix::Helix(Point center, float radius, float step)
{
	this->step = step;
}

Point Helix::GetPoint(float t)
{
	return Point(radius * t * cos(t),
				 radius * t * sin(t),
				 (step * t) / (2 * M_PI));
}

Vector Helix::FirstDerivative(float t)
{
	return Vector(Point(radius * cos(t) - radius * t * sin(t),
						radius * sin(t) + radius * t * cos(t),
						step / (2 * M_PI)));
}

Curve* Helix::CreateRandom()
{
	center = center.CreateRandomPoint();
	radius = abs(rand());
	step = rand();
	return this;
}

void Helix::Print()
{
	cout << "Helix: ";
	Curve::Print();
	cout << ", radius: " << radius << ", step: " << step;
}
